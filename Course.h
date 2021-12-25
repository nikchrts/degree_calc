#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course {
    private:
        int _grade;
        int _credits;
        std::string _name;

    public:
        Course (std::string name="", int credits=0, int grade=0);

        const int weightedGrade() const { return _grade * _credits; }
        const int& credits() const { return _credits; }
        friend std::ostream& operator << (std::ostream& out, const Course& course);
};

#endif
