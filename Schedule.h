#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <string>

class Schedule {
private:
    std::vector<std::string> courses;

public:
    void addCourse(const std::string& courseName);
    void print() const;
};

#endif  // SCHEDULE_H

