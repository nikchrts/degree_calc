#include "Course.h"

Course::Course (std::string name, int credits, int grade) : _name{name}, _credits{credits}, _grade{grade} {}

std::ostream& operator << (std::ostream& out, const Course& course) {
    auto name {course._name};
    std:: transform(name.begin(), name.end(), name.begin(), ::toupper);
    out << name << std::endl;
    out << "Credits: " << course._credits << std::endl;
    out << "Grade: " << course._grade << std::endl;
    return out;
}