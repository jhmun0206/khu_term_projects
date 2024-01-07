#include "Schedule.h"
#include <iostream>

void Schedule::addCourse(const std::string& courseName) {
    courses.push_back(courseName);
}

void Schedule::print() const {
    for (const auto& course : courses) {
        std::cout << course << "\n";
    }
    std::cout << "\n";
}
