#include "Coursework.h"
#include "Course.h"
#include <sstream>
#include <fstream>

Coursework::Coursework() : sumGrade{0}, totalCredits{0}, averageGrade{0}, db{} {};

void Coursework::createDB (const std::string& file) {

    // Attempt to open the file and throw an error if it fails
    std::ifstream txtFile;
    try {
         txtFile.open(file);

        if (!txtFile.good()){
            throw std::invalid_argument("Error! " + file + " can't be opened for reading!\n");
        }
    }
    catch(const std::exception& e) {
        txtFile.close();
        std::cerr << e.what() << '\n';
        std::exit (EXIT_FAILURE);
    }
    
    // If the file is successfully opened, read the content and add to db
    std::string line;
    while (getline(txtFile, line)) {
        std::istringstream lineStream{line};
        std::string word;
        int word_int;

        Course newCourse;
        lineStream >> word;                     // First : Name
        newCourse.setName(word);

        lineStream >> word;                     // Second : Credits
        word_int = stoi(word);
        newCourse.setCredits(word_int);
        totalCredits += stoi(word);

        lineStream >> word;                     // Third: Grade
        word_int = stoi(word);
        newCourse.setGrade(word_int);
        sumGrade += stoi(word);

        db.push_back(newCourse);
    }

    // Close the opened file once finished
    txtFile.close();

    calcAverage();
};

void Coursework::calcAverage () {
    if (totalCredits) {
        averageGrade = (float) sumGrade / totalCredits;
    }
    else {
        std::cerr << "Can't calculate average because the total amount of credits is zero!" << std::endl;
        std::exit (EXIT_FAILURE);
    }
}

void Coursework::showDatabase () const {
    for (auto course : db) {
        std::cout << course << std::endl;
    }
};

void Coursework::addCourse (Course& newCourse) {
    db.push_back(newCourse);
}

void Coursework::addCourseWithDetails (std::string& _name, int& _credits, int& _grade) {
    Course newCourse;
    newCourse.setName(_name);
    newCourse.setCredits(_credits);
    newCourse.setGrade(_grade);
    db.push_back(newCourse);
}