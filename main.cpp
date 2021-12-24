#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include "Course.h"
#include "Coursework.h"

using namespace std;

// vector<Course> createDB (const string& file) {
//     std::ifstream txtFile {file};
//     std::string line;
//     vector<Course> dbCourse;

//     if (!txtFile){
//         std::cerr << "Error! " << file << " can't be opened for reading!\n";
//     }

//     while (getline(txtFile, line)) {
//         std::istringstream lineStream {line};

//         Course newCourse;
//         newCourse.setName(words[0]);                // First : Name
//         newCourse.setCredits(stoi(words[1]));       // Second : Credits
//         newCourse.setGrade(stoi(words[2]));         // Third: Grade

//         dbCourse.push_back(newCourse);
//     }

//     txtFile.close();
//     return dbCourse;
// };


int main () {

    const string fileName {"coursework"};
    Coursework myCareer;

    cout << "WELCOME !!\n\nReading data from '" << fileName << "' file ... ";
    myCareer.createDB(fileName);
    // vector<Course> dbCourse = createDB(fileName);
    cout << "DONE!" << endl;
    
    cout << "The last course is: " << endl;
    cout << myCareer.giveCourse();


    return 0;
}

