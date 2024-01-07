#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <cassert>
#include "Schedule.h"

class Student {
public:
    std::string studentName;
    Schedule schedule;
    int course_num = 0;
    Student(const std::string& studentName);

    void print() const;
    Schedule* getSchedule();
};

#endif  // STUDENT_H
