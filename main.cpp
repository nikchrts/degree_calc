#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include <fstream>
#include <vector>

class Coursework{
    private:
        struct Course{
            std::string name;
            int credits;
            int grade;
        };
        double average;
        int n_credits;
        std::vector<Course> db;

    public:
        Coursework(){}

    void OpenFile(){
        std::ifstream myfile("coursework");
        std::string line;
        Course temp;

        if (myfile.is_open()){
            while (std::getline(myfile, line)){
                  std::istringstream iss(line);
                  iss >> temp.name;
                  iss >> temp.credits;
                  iss >> temp.grade;
                  db.push_back(temp);
              }
              myfile.close();
        }
        else std::cout << "Unable to open file";
    }

    void CalculateAverage(){
        n_credits = 0;
        int weighted_sum = 0;

        //for (std::vector<Course>::iterator it = db.begin(); it != db.end(); ++it){
        for (int it = 0; it < db.size(); ++it){
          n_credits += db[it].credits;
          weighted_sum += db[it].credits * db[it].grade;
        };
        average = (double)weighted_sum/n_credits;
        Coursework::DisplayOutput();
    }

    void DisplayOutput(){
        std::cout << "\n\tPROGRAM TO CALCULATE DEGREE SCORE\n\t" << std::string(33, '-') << std::endl;
        std::cout << "\n\tCompleted courses: ";
        for (int j = 0; j < 3; j++) {printf ("%s, ",db[j].name.c_str());}
        printf("\n\tNumber of credits: %d/100\n", n_credits);
        printf("\n\tAverage Score:\t%.2f (out of 30)\n\t\t\t%.2f (out of 110)\n\n", average, average*110/30);

    }

};

int main (){
  Coursework start;
  start.OpenFile();
  start.CalculateAverage();

  return 0;
}