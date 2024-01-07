#include "registrar.h"
#include <iostream>

void Registrar::enroll(Student& student, Course& course) {
    Roster* roster = course.getRoster();
    roster->addStudent(student.studentName);

    Schedule* schedule = student.getSchedule();
    schedule->addCourse(course.courseName);
}
