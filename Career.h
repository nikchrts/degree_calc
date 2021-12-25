#ifndef CAREER_H
#define CAREER_H

#include "Course.h"
#include <vector>
#include <iostream>

class Career {
    private:
        std::vector<Course> _db;
        int _totalCredits;

    public:
        Career();

        void createDB (const std::string& file);

        float calcAverageGrade (const int &out_of) const;
        void showDatabase () const;
        void addCourse (Course& newCourse);
        void addCourseWithDetails (std::string& _name, int& _credits, int& _grade);
};

#endif
