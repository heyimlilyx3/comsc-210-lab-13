#include <iostream>
#include <fstream>
#include <array>
#include <cmath>

using namespace std;

struct student{
    int id;
    double score;
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

void printMin(array<student, 150>& students) {
    cout << "Minimum score: " << students[0].score << " (ID: " << students[0].id << ")" << endl;
}
void printMax(array<student, 150>& students) {
    cout << "Maximum score: " << students[149].score << " (ID: " << students[149].id << ")" << endl;
}
void printMean(array<student, 150>& students) {
    double sum = 0;
    for (const auto& s : students) {
        sum += s.score;
    }
    double mean = sum / 150;
    cout << "Mean score: " << mean << endl;
}
void printMedian(array<student, 150>& students) {
    double median;
    if (150 % 2 == 0) {
        median = (students[74].score + students[75].score) / 2.0;
    } else {
        median = students[75].score;
    }
    cout << "Median score: " << median << " (ID: " << students[75].id << ")" << endl;
}
void printStandardDeviation(array<student, 150>& students) {
    double mean = 0;
    for (const auto& s : students) {
        mean += s.score;
    }
    mean /= 150;

    double variance = 0;
    for (const auto& s : students) {
        variance += (s.score - mean) * (s.score - mean);
    }
    variance /= 150;

    double stddev = sqrt(variance);
    cout << "Standard Deviation: " << stddev << endl;
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

    selectionSort(students);                                // Sort the students by score


    inputFile.close();                                      // Close the input file

    ofstream outputFile("210-lab-13-grades-sorted.txt");    // Open the output file

    if (!outputFile) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    for (int i = 0; i < 150; i++) {
        outputFile << students[i].id << " " << students[i].score << endl;
    }

    outputFile.close();                                     // Close the output file


    printMin(students);
    printMax(students);
    printMean(students);
    printMedian(students);
    printStandardDeviation(students);

    return 0;
}