

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "read_file.h"
#include "algorithm.h"
#include "doctest.h"


TEST_CASE("Reading matrix from stream") {
    SUBCASE("Read valid matrix from string stream") {
        std::istringstream iss("0 1 2\n1 0 2\n2 1 0\n");
        Matrix matrix = ReadMatrixFromStream(iss);

        CHECK(matrix[0][0] == 0);
        CHECK(matrix[0][1] == 1);
        CHECK(matrix[0][2] == INF);
        CHECK(matrix[1][0] == 1);
        CHECK(matrix[1][1] == 0);
        CHECK(matrix[1][2] == INF);
        CHECK(matrix[2][0] == INF);
        CHECK(matrix[2][1] == 1);
        CHECK(matrix[2][2] == 0);
    }
}

TEST_CASE("ExpensiveDiGraphExactPaths computation") {
    SUBCASE("Test with predetermined matrix") {
        std::istringstream d1Input("0 1 2\n1 0 2\n2 1 0\n");
        std::istringstream d0Input("0 2 2\n2 0 2\n2 2 0\n");
        std::istringstream dminus1Input("0 2 2\n2 0 2\n2 2 0\n");

        Matrix D1 = ReadMatrixFromStream(d1Input);
        Matrix D0 = ReadMatrixFromStream(d0Input);
        Matrix Dminus1 = ReadMatrixFromStream(dminus1Input);

        ExpensiveDigraphExactPaths(D1, D0, Dminus1);

        // The D1 matrix should remain unchanged since there are no zero-weighted paths to change +1's to 0
        CHECK(D1[0][1] == 1);
        CHECK(D1[1][2] == INF);
        CHECK(D1[2][0] == INF);

        // The D0 matrix should now contain zeroes for paths that can be made with +1 and -1 combinations
        CHECK(D0[0][0] == 0);
        CHECK(D0[1][1] == 0);
        CHECK(D0[2][2] == 0);

        // Assuming that the -1 paths cannot contribute to the D0 matrix
        CHECK(D0[0][1] == INF); // Since there is no -1 path from 0 to 1 to offset the +1
        CHECK(D0[1][0] == INF); // Since there is no -1 path from 1 to 0 to offset the +1

        // The Dminus1 matrix should remain unchanged since there are no zero-weighted paths to change -1's to 0
        CHECK(Dminus1[0][0] == 0);
        CHECK(Dminus1[1][1] == 0);
        CHECK(Dminus1[2][2] == 0);
        
        // Example of an expected failure (assuming there is no path to self from self with a cost)
        //CHECK(D0[0][0] == INF); // This check is expected to fail as D0[0][0] should be 0
    }


    // You can add more SUBCASEs to test other aspects of the algorithm
}


