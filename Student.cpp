#include "Student.h"
#include <iostream>

Student::Student(const std::string& studentName) : studentName(studentName) {}

void Student::print() const {
    std::cout << "Student name: " << studentName << "\nList of Courses\n";
    schedule.print();
}

Schedule* Student::getSchedule() {
    course_num++;
    assert(course_num <= 10);
    return &schedule;
}
