#include <algorithm>
#include <queue>
#include <stdexcept>
#include <library/leetcode/datatype/ListNode.h>
#include <library/leetcode/datatype/TreeNode.h>
#include <tests/leetcode/util/Parser.h>
#include <tests/util/String.h>

namespace Library::LeetCode::Datatype {
    struct TreeNode;
}

template<>
std::vector<std::string> Tests::LeetCode::Util::Parser::parse(const std::string &str) {
    if (str.size() < 2)
        throw std::invalid_argument("Not enough bytes provided: " + str);

    if (str.front() != '[' || str.back() != ']')
        throw std::invalid_argument("Invalid Input: " + str);

    return Tests::Util::String::splitWords(std::string_view(str.data() + 1, str.size() - 2), ",");
}

template<>
std::vector<int> Tests::LeetCode::Util::Parser::parse(const std::string &str) {
    const auto words = parse<std::vector<std::string> >(str);
    std::vector<int> result(words.size());
    std::ranges::transform(words, result.begin(), [](const auto &word) { return std::stoi(word); });
    return result;
}

template<>
std::vector<std::vector<std::string> > Tests::LeetCode::Util::Parser::parse(const std::string &str) {
    const auto size = str.size();
    if (size < 2)
        throw std::invalid_argument("Not enough bytes provided: " + str);

    if (str.front() != '[' || str.back() != ']')
        throw std::invalid_argument("Invalid Input: " + str);

    if (size == 2)
        return {};

    if (size < 4 || str[1] != '[' || str[size - 2] != ']')
        throw std::invalid_argument("Invalid Input: " + str);

    const auto lines = Tests::Util::String::splitWords(std::string_view(str.data() + 2, str.size() - 4), "],[");
    std::vector<std::vector<std::string> > stringMatrix(lines.size());

    std::ranges::transform(lines, stringMatrix.begin(), [](const auto &line) {
        return Tests::Util::String::splitWords(line, ",");
    });
    return stringMatrix;
}

template<>
std::vector<std::vector<int> > Tests::LeetCode::Util::Parser::parse(const std::string &str) {
    const auto stringMatrix = parse<std::vector<std::vector<std::string> > >(str);
    std::vector<std::vector<int> > intMatrix(stringMatrix.size());

    std::ranges::transform(stringMatrix, intMatrix.begin(), [](const auto &stringRow) {
        std::vector<int> intRow(stringRow.size());
        std::ranges::transform(stringRow, intRow.begin(), [](const auto &word) { return std::stoi(word); });
        return intRow;
    });

    return intMatrix;
}

template<>
std::vector<std::vector<char> > Tests::LeetCode::Util::Parser::parse(const std::string &str) {
    const auto stringMatrix = parse<std::vector<std::vector<std::string> > >(str);
    std::vector<std::vector<char> > charMatrix(stringMatrix.size());

    std::ranges::transform(stringMatrix, charMatrix.begin(), [](const auto &stringRow) {
        std::vector<char> charRow(stringRow.size());
        std::ranges::transform(stringRow, charRow.begin(), [](const auto &word) { return word[0]; });
        return charRow;
    });

    return charMatrix;
}

Library::LeetCode::Datatype::ListNode *listNodeFromIntVector(const std::vector<int> &intVector) {
    Library::LeetCode::Datatype::ListNode dummy;
    Library::LeetCode::Datatype::ListNode *tail = &dummy;
    for (const auto val: intVector) {
        tail->next = new Library::LeetCode::Datatype::ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

template<>
Library::LeetCode::Datatype::ListNode *Tests::LeetCode::Util::Parser::parse(const std::string &str) {
    const auto intVector = parse<std::vector<int> >(str);
    return listNodeFromIntVector(intVector);
}

template<>
std::vector<Library::LeetCode::Datatype::ListNode *> Tests::LeetCode::Util::Parser::parse(const std::string &str) {
    const auto intMatrix = parse<std::vector<std::vector<int> > >(str);

    std::vector<Library::LeetCode::Datatype::ListNode *> result(intMatrix.size());
    std::ranges::transform(intMatrix, result.begin(), [](const auto &intVector) {
        return listNodeFromIntVector(intVector);
    });
    return result;
}

template<>
Library::LeetCode::Datatype::TreeNode *Tests::LeetCode::Util::Parser::parse(const std::string &str) {
    const auto stringVector = parse<std::vector<std::string> >(str);
    if (stringVector.empty())
        return nullptr;

    auto *root = new Library::LeetCode::Datatype::TreeNode(std::stoi(stringVector[0]));
    std::queue<Library::LeetCode::Datatype::TreeNode *> nodes;
    nodes.push(root);

    for (int i = 1; i < stringVector.size(); i += 2) {
        Library::LeetCode::Datatype::TreeNode *node = nodes.front();
        nodes.pop();

        if (stringVector[i] != "null") {
            node->left = new Library::LeetCode::Datatype::TreeNode(std::stoi(stringVector[i]));
            nodes.push(node->left);
        }
        if (i + 1 < stringVector.size() && stringVector[i + 1] != "null") {
            node->right = new Library::LeetCode::Datatype::TreeNode(std::stoi(stringVector[i + 1]));
            nodes.push(node->right);
        }
    }

    return root;
}
