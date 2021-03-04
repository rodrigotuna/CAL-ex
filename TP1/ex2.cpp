#include "exercises.h"

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int maxSum = A[0];
    i = 0; j = 0;

    for(int u = 0; u < n; u++){
        int localSum = 0;
        for(int v = u; v < n; v ++){
            localSum += A[v];
            if(localSum > maxSum){
                maxSum = localSum;
                i = u;
                j = v;
            }
        }
    }

    return maxSum;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}