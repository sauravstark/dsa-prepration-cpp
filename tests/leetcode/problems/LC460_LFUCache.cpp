#include <common/util/String.h>
#include <gtest/gtest.h>
#include <leetcode/problems/LC460_LFUCache.h>
#include <leetcode/util/TastcaseReader.h>

TEST(LeetCode, LC460_LFUCache) {
    LeetCode::Util::TestcaseReader testcaseReader("testcases/leetcode/LC460_LFUCache.txt", 3);

    while (testcaseReader.hasNext()) {
        const auto words = testcaseReader.next();
        const auto commands = Common::Util::String::parseVectorString(words[0]);
        const auto arguments = Common::Util::String::parse2DVectorInt(words[1]);
        const auto expectedResults = Common::Util::String::parseVectorString(words[2]);

        if (commands.size() != arguments.size() || commands.size() != expectedResults.size())
            throw std::runtime_error("Mismatch number of commands, arguments, and expected");
        if (commands.empty() || commands[0] != "LFUCache")
            throw std::runtime_error("Expected first command to be 'LFUCache'");
        if (arguments[0].size() != 1)
            throw std::runtime_error("Expected argument count for LFUCache to be 1");

        LeetCode::Problems::LC460::LFUCache cache(arguments[0][0]);

        for (int i = 1; i < commands.size(); i++) {
            const auto &command = commands[i];
            const auto &argument = arguments[i];
            const auto &expectedResult = expectedResults[i];
            if (command == "put") {
                if (argument.size() != 2)
                    throw std::runtime_error("Expected argument count for put to be 2");
                cache.put(argument[0], argument[1]);
            } else if (command == "get") {
                if (argument.size() != 1)
                    throw std::runtime_error("Expected argument count for get to be 1");
                const auto result = cache.get(argument[0]);
                ASSERT_EQ(std::stoi(expectedResult), result);
            } else {
                throw std::runtime_error("Expected command to be to 'get' or 'put'");
            }
        }
    }
}
