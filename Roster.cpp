#include "Roster.h"
#include <iostream>

void Roster::addStudent(const std::string& studentName) {
    students.push_back(studentName);
}

void Roster::print() const {
    for (const auto& student : students) {
        std::cout << student << "\n";
    }
}
