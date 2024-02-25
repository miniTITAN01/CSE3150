#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student_Info.h" // Make sure this includes the definition of the student struct and computeTotalScore function

TEST_CASE("Edge Cases") {
    
    SUBCASE("All 0's") {
        student student1 = {1, "Kay", 0, 0, {0, 0, 0}};
        double expected_score1 = 0.0;
        CHECK(computeTotalScore(student1) == doctest::Approx(expected_score1));
    }

    SUBCASE("Full Score") {
        student student2 = {2, "Anthony", 100, 100, {100, 100, 100}};
        double expected_score2 = 100.0;
        CHECK(computeTotalScore(student2) == doctest::Approx(expected_score2));
    }

    SUBCASE("No Exam Scores") {
        student student3 = {3, "Jayda", 0, 0, {60, 75, 90}};
        double expected_score3 = (((60 + 75 + 90) / 3.0) * 0.4);
        CHECK(computeTotalScore(student3) == doctest::Approx(expected_score3));
    }

    SUBCASE("No HW Scores") {
        student student4 = {4, "Trang", 78, 91, {}};
        double expected_score4 = 0.3 * 78 + 0.3 * 91;
        CHECK(computeTotalScore(student4) == doctest::Approx(expected_score4));
    }
}

TEST_CASE("Regular --> Multiple HW grades") {
    SUBCASE("Test1") {
        student student5 = {5, "Rhianna", 88, 77, {90, 99, 90}};
        double expected_score5 = 0.3 * 88 + 0.3 * 77 + (((90 + 99 + 90) / 3.0) * 0.4);
        CHECK(computeTotalScore(student5) == doctest::Approx(expected_score5));
    }

    SUBCASE("Test2") {
        student student6 = {6, "Allison", 77, 70, {83, 87, 34, 90}};
        double expected_score6 = 0.3 * 77 + 0.3 * 70 + (((83 + 87 + 34 + 90) / 4.0) * 0.4);
        CHECK(computeTotalScore(student6) == doctest::Approx(expected_score6));
    }

    SUBCASE("Test3") {
        student student7 = {7, "Joe", 99, 85, {81, 82, 83, 84, 85}};
        double expected_score7 = 0.3 * 99 + 0.3 * 85 + (((81 + 82 + 83 + 84 + 85) / 5.0) * 0.4);
        CHECK(computeTotalScore(student7) == doctest::Approx(expected_score7));
    }

    SUBCASE("Test4") {
        student student8 = {8, "Connor", 45, 74, {60, 75}};
        double expected_score8 = 0.3 * 45 + 0.3 * 74 + (((60 + 75) / 2.0) * 0.4);
        CHECK(computeTotalScore(student8) == doctest::Approx(expected_score8));
    }
}
