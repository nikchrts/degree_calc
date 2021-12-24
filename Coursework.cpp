#include "Coursework.h"
#include "Course.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

void Coursework::createDB (const std::string& file) {
    std::ifstream txtFile {file};
    std::string line;

    if (!txtFile){
        std::cerr << "Error! " << file << " can't be opened for reading!\n";
    }

    while (getline(txtFile, line)) {
        std::istringstream lineStream {line};
        std::string word;

        Course newCourse;
        lineStream >> word;                     // First : Name
        newCourse.setName(word);

        lineStream >> word;                     // Second : Credits
        newCourse.setCredits(stoi(word));

        lineStream >> word;                     // Third: Grade
        newCourse.setGrade(stoi(word));

        db.push_back(newCourse);
    }

    txtFile.close();
};

