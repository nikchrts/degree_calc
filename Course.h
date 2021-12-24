#ifndef COURSE_H
#define COURSE_H

#include <ostream>
#include <string>

class Course {
    private:
        int grade;
        int credits;
        std::string name;

    public:
        Course ();

        int getGrade() const { return grade; };
        int getCredits() const { return credits; };
        std::string getName() const { return name; };

        void setGrade(int _grade) { grade = _grade; }
        void setCredits(int _credits) { credits = _credits; }
        void setName(std::string _name) { name = _name; }

        friend std::ostream& operator << (std::ostream& out, const Course& course);
};

#endif
