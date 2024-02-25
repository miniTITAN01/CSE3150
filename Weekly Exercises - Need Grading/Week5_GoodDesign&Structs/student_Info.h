#ifndef STUDENT_INFO__H
#define STUDENT_INFO_H

#include <vector>
#include <string>


// Declare the student struct
struct student {
    int id;
    std::string name;
    int final;
    int midterm;
    std::vector<int> hw_grades;
};

// Function prototypes
double computeTotalScore(const student& s);
void outputStudent(const student& s);


#endif 