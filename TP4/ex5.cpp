#include "exercises.h"

#include <vector>

unsigned long s_recursive(unsigned int n, unsigned int k) {
    if ( k == 1 || n == k) return 1;

    return s_recursive(n-1,k-1) + k*s_recursive(n-1,k);
}

unsigned long b_recursive(unsigned int n) {
    unsigned long result = 0;
    for(int i = 1; i <= n; i++) result += s_recursive(n,i);
    return result;
}

unsigned long s_dynamic(unsigned int n, unsigned int k) {
    std::vector<unsigned> s(k+1,1);

    for(unsigned i = 2; i <= n; i++){
        for(unsigned j = std::min(k, i-1); j > 1; j--){
            s[j] = s[j-1] + j*s[j];
        }
    }
    return s[k];
}

unsigned long b_dynamic(unsigned int n) {
    unsigned long res = 0;
    std::vector<unsigned> s(n+1,1);

    for(unsigned i = 2; i <= n; i++){
        for(unsigned j = i-1 ; j > 1; j--){
            s[j] = s[j-1] + j*s[j];
        }
    }

    for(int i = 1; i <= n; i++){
        res += s[i];
    }
    return res;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex5, testPartitioningRecursive) {
    EXPECT_EQ(1,s_recursive(3,3));
    EXPECT_EQ(3025,s_recursive(9,3));
    EXPECT_EQ(22827,s_recursive(10,6));

    EXPECT_EQ(5,b_recursive(3));
    EXPECT_EQ(203,b_recursive(6));
    EXPECT_EQ(1382958545,b_recursive(15));
}

TEST(TP4_Ex5, testPartitioningDynamic) {
    EXPECT_EQ(1,s_dynamic(3,3));
    EXPECT_EQ(3025,s_dynamic(9,3));
    EXPECT_EQ(22827,s_dynamic(10,6));

    EXPECT_EQ(5,b_dynamic(3));
    EXPECT_EQ(203,b_dynamic(6));
    EXPECT_EQ(1382958545,b_dynamic(15));
}