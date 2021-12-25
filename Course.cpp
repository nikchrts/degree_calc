#include "Course.h"

Course::Course (std::string _name, int _credits, int _grade) : name{_name}, credits{_credits}, grade{_grade} {}

std::ostream& operator << (std::ostream& out, const Course& course) {
    std::string name {course.getName()};
    std:: transform(name.begin(), name.end(), name.begin(), ::toupper);
    out << name << std::endl;
    out << "Credits: " << course.getCredits() << std::endl;
    out << "Grade: " << course.getGrade() << std::endl;
    return out;
}