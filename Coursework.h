#ifndef COURSEWORK_H
#define COURSEWORK_H

#include "Course.h"
#include <vector>

class Coursework {
    private:
        std::vector<Course> db;
        float averageGrade;
        int totalCredits;

    public:
        void createDB(const std::string& file);
        Course giveCourse() const { return db.back(); };

};

#endif
