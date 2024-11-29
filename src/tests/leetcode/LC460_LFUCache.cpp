#include <tests/util/String.h>
#include <gtest/gtest.h>
#include <library/leetcode/LC460_LFUCache.h>
#include <tests/leetcode/util/Parser.h>
#include <tests/leetcode/util/TestcaseReader.h>

namespace Tests::LeetCode {
    TEST(LeetCode, LC460_LFUCache) {
        Util::TestcaseReader testcaseReader("testcases/leetcode/LC460_LFUCache.txt", 3);

        while (testcaseReader.hasNext()) {
            const auto words = testcaseReader.next();
            const auto commands = Util::Parser::parse<std::vector<std::string> >(words[0]);
            const auto arguments = Util::Parser::parse<std::vector<std::vector<int> > >(words[1]);
            const auto expectedResults = Util::Parser::parse<std::vector<std::string> >(words[2]);

            if (commands.size() != arguments.size() || commands.size() != expectedResults.size())
                throw std::runtime_error("Mismatch number of commands, arguments, and expected");
            if (commands.empty() || commands[0] != "LFUCache")
                throw std::runtime_error("Expected first command to be 'LFUCache'");
            if (arguments[0].size() != 1)
                throw std::runtime_error("Expected argument count for LFUCache to be 1");

            const auto capacity = arguments[0][0];
            Library::LeetCode::LC460::LFUCache cache(capacity);

            for (int i = 1; i < commands.size(); i++) {
                const auto &command = commands[i];
                const auto &argument = arguments[i];
                const auto &expectedResult = expectedResults[i];
                if (command == "put") {
                    if (argument.size() != 2)
                        throw std::runtime_error("Expected argument count for put to be 2");
                    const auto key = argument[0];
                    const auto value = argument[1];
                    cache.put(key, value);
                } else if (command == "get") {
                    if (argument.size() != 1)
                        throw std::runtime_error("Expected argument count for get to be 1");
                    const auto key = argument[0];
                    const auto result = cache.get(key);
                    ASSERT_EQ(std::stoi(expectedResult), result);
                } else {
                    throw std::runtime_error("Expected command to be to 'get' or 'put'");
                }
            }
        }
    }
}
