#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Coursework.h"

using namespace std;

int main () {

    const string fileName {"coursework"};
    Coursework myCareer;

    cout << "WELCOME !!\n\nReading data from '" << fileName << "' file ... ";
    myCareer.createDB(fileName);
    cout << "DONE!" << endl;
    
    cout << "The last course is: " << endl;
    cout << myCareer.giveCourse();


    return 0;
}

