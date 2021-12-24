#include "Course.h"
#include <iostream>

Course::Course () : grade{0}, credits{0}, name{""} {};

std::ostream& operator << (std::ostream& out, const Course& course) {
    out << "COURSE DETAILS" << std::endl;
    out << "Name : " << course.getName() << std::endl;
    out << "Credits : " << course.getCredits() << std::endl;
    out << "Grade : " << course.getGrade() << std::endl;
    return out;
}