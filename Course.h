#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <cassert>
#include "Roster.h"

class Course {
public:
    std::string courseName;
    int num_student = 0;
    int Units;
    Roster roster;

    Course(const std::string& courseName, int courseUnits);
    void print() const;
    Roster* getRoster();
};

#endif  // COURSE_H
