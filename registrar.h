#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "Student.h"
#include "Course.h"

class Registrar {
public:
    void enroll(Student& student, Course& course);
};

#endif  // REGISTRAR_H

