#include "Career.h"
#include "Course.h"
#include <sstream>
#include <fstream>

Career::Career() : sumGrade{0}, totalCredits{0}, db{} {};

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

        db.push_back(newCourse);
    }

    // Close the opened file once finished
    txtFile.close();
};

float Career::calcAverageGrade (const int &out_of) const {

    if (!totalCredits) {
        std::cerr << "Can't calculate average because the total amount of credits is zero!" << std::endl;
        std::exit (EXIT_FAILURE);
    }

    if (out_of <= 0) {
        std::cerr << "Can't calculate average out of 0 or a negative number!" << std::endl;
        std::exit (EXIT_FAILURE);
    }


    float average = (float) sumGrade / db.size();
    return average * out_of / 30;
}

void Career::showDatabase () const {
    for (auto course : db) {
        std::cout << course << std::endl;
    }
};

void Career::addCourse (Course& newCourse) {
    db.push_back(newCourse);
    // ALSO WRITE IT IN THE TXT FILE
}

void Career::addCourseWithDetails (std::string& _name, int& _credits, int& _grade) {
    Course newCourse(_name, _credits, _grade);
    db.push_back(newCourse);
}