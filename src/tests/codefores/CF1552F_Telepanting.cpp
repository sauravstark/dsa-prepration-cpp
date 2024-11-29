#include <library/codefores/CF1552F_Telepanting.h>
#include <tests/util/File.h>
#include <tests/util/String.h>
#include <gtest/gtest.h>
#include <tests/codeforces/util/TestcaseReader.h>

namespace Tests::Codeforces {
    TEST(Codeforces, CF1552F_Telepanting) {
        Util::TestcaseReader reader("testcases/codeforces/CF1552F_Telepanting.txt");
        const auto testcaseCount = reader.readInt();
        for (auto i = 0; i < testcaseCount; i++) {
            const auto N = reader.readInt();
            const auto matrix = reader.readIntVector2D(N, 3);
            const auto transposedMatrix = Util::transpose(matrix);
            const auto src = transposedMatrix[0];
            const auto dst = transposedMatrix[1];
            const auto state = transposedMatrix[2];
            const auto expected = reader.readInt();
            const auto result = Library::Codeforces::CF1552F::telepanting(src, dst, state);
            ASSERT_EQ(result, expected);
        }
    }
}
