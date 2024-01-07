#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <string>

class Roster {
private:
    std::vector<std::string> students;

public:
    void addStudent(const std::string& studentName);
    void print() const;
};

#endif  // ROSTER_H
