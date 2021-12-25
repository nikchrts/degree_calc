#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course {
    private:
        int grade;
        int credits;
        std::string name;

    public:
        Course (std::string _name="", int _credits=0, int _grade=0);

        friend std::ostream& operator << (std::ostream& out, const Course& course);
};

#endif
