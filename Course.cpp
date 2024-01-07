#include "Course.h"
#include <iostream>

Course::Course(const std::string& courseName, int courseUnits) : courseName(courseName), Units(courseUnits) {}

void Course::print() const {
    std::cout << "\nCourse Name: " << courseName << "\nNumber of Units: " << Units << "\nList of Students\n";
    roster.print();
}

Roster* Course::getRoster() {
    num_student++;
    assert(num_student <= 300);
    return &roster;
}
