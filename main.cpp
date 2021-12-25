#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Career.h"

#define EXIT_OPTION 5

using namespace std;

void showActions() {
    cout << "Available actions:\n"
        "1. Show the database\n"
        "2. Add a new course\n"
        "3. Delete a course\n"
        "4. Print the average\n"
        "5. Exit Program\n" << endl;
}

int main () {

    const string fileName {"career.txt"};
    Career myCareer;

    cout << "\n ~~~ WELCOME ~~~\n\nReading data from '" << fileName << "' file ... ";
    myCareer.createDB(fileName);
    cout << "DONE!\n" << endl;
    showActions();

    int userChoice;
    do {
        try {
            cout << "Type an action's number: ";
            cin >> userChoice;
            
            if (userChoice < 1 || userChoice > 5) { // Throw an exception if wrong input 
                throw std::out_of_range("User choice should be one of the following integers: 1, 2, 3, 4 !!");
            }

            switch (userChoice) {
                case 1: { // Print the already imported courses 
                    cout << "... printing database!\n" << endl;
                    myCareer.showDatabase();
                    break;
                }
                case 2: { // Add a new course 
                    std::string _name;
                    int _credits, _grade;
                    
                    cout << "... new course incoming!\n" << endl;

                    std::cout << "Name? ";
                    std::cin >> _name;

                    std::cout << "Credits? ";
                    std::cin >> _credits;

                    std::cout << "Grade? ";
                    std::cin >> _grade;

                    myCareer.addCourseWithDetails(_name, _credits, _grade);
                    break;
                }
                case 3: { // Delete an imported course 
                    cout << "... deletion on the way!\n" << endl;
                    // myCareer.deleteCourse();
                    break;
                }
                case 4: { // Calculate and print the average 
                    cout << "... printing the average!\n" << endl;
                    cout << "The average grade is " << myCareer.calcAverageGrade(30) 
                            << "/30 or equivalently " << myCareer.calcAverageGrade(110) 
                            << "/110\n";
                    break;
                }
                default: { // Exit program 
                    cout << "...exiting program, thank you!" << endl;
                    break;
                }
            }


        }
        catch(const std::exception& e) {
            std::cerr << "ERROR!! " << e.what() << '\n';
            return 1;
        }
        cout << endl;
    } while ( userChoice != EXIT_OPTION );

    return EXIT_SUCCESS;
}