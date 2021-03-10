#include "exercises.h"

int maxSubsequenceDP(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int bestSum = A[0];
    int bestLocalSum = A[0];
    unsigned locali = 0, localj = 0;
    i = 0; j= 0;
    for(unsigned w = 1; w < n; w++){
        if(bestLocalSum + A[w] < A[w]){
            locali = w;
            localj = w;
            bestLocalSum = A[w];
        } else {
            localj = w;
            bestLocalSum += A[w];
        }

        if(bestLocalSum > bestSum){
            i = locali;
            j = localj;
            bestSum = bestLocalSum;
        }
    }
    return bestSum;
}

int maxSubsequenceBF(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
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

int maxSubsequenceDC(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    // TODO
	// Copy-paste your solution for ex2 of TP3 HERE
	return 0;
}

void testPerformanceMaxSubsequence() {
	// TODO
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex6, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequenceDP(A1,n1,i,j), 10);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
    EXPECT_EQ(maxSubsequenceDP(A2,n2,i,j), 4);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    EXPECT_EQ(maxSubsequenceDP(A3,n3,i,j), 8);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    EXPECT_EQ(maxSubsequenceDP(A4,n4,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);

    testPerformanceMaxSubsequence();
}