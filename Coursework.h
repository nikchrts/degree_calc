#ifndef COURSEWORK_H
#define COURSEWORK_H

#include "Course.h"
#include <vector>
#include <iostream>

class Coursework {
    private:
        std::vector<Course> db;
        float averageGrade;
        int totalCredits;
        int sumGrade;

    public:
        Coursework();

        void createDB (const std::string& file);

        void calcAverage ();
        void showDatabase () const;
        void addCourse (Course& newCourse);
        void addCourseWithDetails (std::string& _name, int& _credits, int& _grade);

        int getTotalCredits () const { return totalCredits; }
        float getAverageGrade () const { return averageGrade; }
        int getSumGrade () const { return sumGrade; }
        int getNumCourses () const { return db.size(); }

};

#endif
