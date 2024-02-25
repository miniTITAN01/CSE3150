#include "student_Info.h"
#include <iostream>



using namespace std;

// Function to compute the total class score
double computeTotalScore(const student& s) {
    double hw_sum = 0;
    double hw_average = 0; // Initialize hw_average to 0
    for (int grade : s.hw_grades) {
        hw_sum += grade;
    }
    // Check if hw_grades is not empty before dividing
    if (!s.hw_grades.empty()) {
        hw_average = hw_sum / s.hw_grades.size();
    }
    
    double totalScore = 0.3 * s.midterm + 0.3 * s.final + 0.4 * hw_average;
    return totalScore;
}


// Function to output a student's details and their total class score
void outputStudent(const student& s) {
    double totalScore = computeTotalScore(s);
    cout << "Student ID: " << s.id << "\n"
         << "Name: " << s.name << "\n"
         << "Midterm: " << s.midterm << "\n"
         << "Final: " << s.final << "\n"
         << "Homework Grades: ";
    for (int grade : s.hw_grades) {
        cout << grade << " ";
    }
    cout << "\nTotal Class Score: " << totalScore << endl;
}