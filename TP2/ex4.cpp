#include "exercises.h"

bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::overlaps(const Activity &a2) const {
    return (start < a2.finish) && (a2.start < finish);
}
int activitySelectionRecursive(std::vector<Activity> &A, int index, std::vector<Activity> &answer){
    std::vector<Activity> answerCopy = answer;
    std::vector<Activity> bestAnswer = answer;
    for(int i = index; i < A.size(); i++){
        answer = answerCopy;
        bool possible = true;
        for(auto &u: answer){
            if(u.overlaps(A[i])) possible = false;
        }
        if(possible){
            answer.push_back(A[i]);
            if(activitySelectionRecursive(A,i+1, answer) > bestAnswer.size()){
                bestAnswer = answer;
            }
        }
    }
    answer = bestAnswer;
    return bestAnswer.size();
}
std::vector<Activity> activitySelectionBacktracking(std::vector<Activity> A) {
    std::vector<Activity> answer;
    activitySelectionRecursive(A,0,answer);
    return answer;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

bool noOverlaps(const std::vector<Activity> &acts) {
    for(unsigned int i = 0; i < acts.size(); i++) {
        Activity A1 = acts.at(i);
        for(unsigned int j = i + 1; j < acts.size(); j++) {
            Activity A2 = acts.at(j);
            if(A1.overlaps(A2)) return false;
        }
    }
    return true;
}

TEST(TP2_Ex4, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = activitySelectionBacktracking(A);
    EXPECT_EQ(V.size(), 3 );
    EXPECT_EQ(noOverlaps(V), true);
}