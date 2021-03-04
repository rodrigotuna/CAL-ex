#include "exercises.h"

int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j, int l, int r) {
    if(l == r) {
        i = l, j = r;
        return A[l];
    }
    int li,lj,ri,rj;
    int m = (l+r)/2;
    int lmax = maxSubsequenceDC(A,n,li,lj,l,m);
    int rmax = maxSubsequenceDC(A,n,ri,rj,m,r);
    int dmax;

    if(lmax > rmax){
        dmax = lmax;
        i = li;
        j = lj;
    } else{
        dmax = rmax;
        i = ri;
        j = rj;
    }

    int mmax= A[m], mi = m, mj = m;
    int lm, best = -INT_MAX, tot = 0;
    for(int ii = m - 1; ii >= l; ii--){
        tot += A[ii];
        if(tot > best){
            best = tot;
            lm = ii;
        }
    }
    if(best > 0) {
        mmax += best;
        mi = lm;
    }
    best = -INT_MAX, tot = 0;
    for(int ii = m+1; i <= r; i--){
        tot += A[ii];
        if(tot > best){
            best = tot;
            lm = ii;
        }
    }
    if(best > 0) {
        mmax += best;
        mj = lm;
    }
    if(mmax > dmax){
        dmax = mmax;
        i = mi;
        j = mj;
    }
    return 0;
}

int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j) {
	return maxSubsequenceDC(A,n,i,j,0,n-1);
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP3_Ex2, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    int i, j;
    EXPECT_EQ(maxSubsequenceDC(A1,n1,i,j), 10);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
    EXPECT_EQ(maxSubsequenceDC(A2,n2,i,j), 4);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    EXPECT_EQ(maxSubsequenceDC(A3,n3,i,j), 8);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    EXPECT_EQ(maxSubsequenceDC(A4,n4,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}