#include "Career.h"
#include "Course.h"
#include <sstream>
#include <fstream>
#include <algorithm>

Career::Career() : _totalCredits{0}, _db{} {};

void Career::createDB (const std::string& file) {

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
        struct courseData {
            int credits;
            int grade;
            std::string name;
        } newData;

        lineStream >> newData.name >> newData.credits >> newData.grade;
        Course newCourse (newData.name, newData.credits, newData.grade);
        _totalCredits += newData.credits;
        _db.push_back(newCourse);
    }

    // Close the opened file once finished
    txtFile.close();
};

float Career::calcAverageGrade (const int &out_of) const {

    if (!_totalCredits) {
        std::cerr << "Can't calculate average because the total amount of credits is zero!" << std::endl;
        std::exit (EXIT_FAILURE);
    }

    if (out_of <= 0) {
        std::cerr << "Can't calculate average out of 0 or a negative number!" << std::endl;
        std::exit (EXIT_FAILURE);
    }

    float averageNum {0};
    std::for_each(this->_db.begin(), this->_db.end(), [&](auto const &c){ return averageNum += c.weightedGrade();});
    return (averageNum / _totalCredits) * out_of / 30;
}

void Career::showDatabase () const {
    for (auto course : _db) {
        std::cout << course << std::endl;
    }
};

void Career::addCourse (Course& newCourse) {
    _db.push_back(newCourse);
    _totalCredits += newCourse.credits();
    // ALSO WRITE IT IN THE TXT FILE
}

void Career::addCourseWithDetails (std::string& name, int& credits, int& grade) {
    Course newCourse(name, credits, grade);
    _db.push_back(newCourse);
    _totalCredits += credits;
}