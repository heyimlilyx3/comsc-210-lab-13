#include <iostream>
#include <fstream>
#include <array>

using namespace std;

struct student{
    int id;
    int score;
};

void selectionSort(array<student, 150>& students) {
    for (int i = 0; i < 149; i++) {
        int minIndex = i;
        for (int j = i + 1; j < 150; j++) {
            if (students[j].score < students[minIndex].score) {
                minIndex = j;
            }
        }
        swap(students[i], students[minIndex]);
    }
}

int main() {
    ifstream inputFile("210-lab-13-grades.txt");            // Open the input file

    if (!inputFile) {                                       // Check if the file was opened successfully
        cerr << "Error opening file." << endl;
        return 1;
    }

    array<student, 150> students;                           // create an array of 150 student structs

    for (int i = 0; i < 150; i++) {                         // Loop to read data for 150 students
        inputFile >> students[i].id >> students[i].score;
    }

    selectionSort(students);                                 // Sort the students by score


    inputFile.close();                                      // Close the input file

    return 0;
}