//Zayd Siwan 
//CSC-134 Lab 7

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Define the Student struct
struct Student {
    string id;
    string name;
    double mathSkills;
    double scienceSkills;
    double presentationSkills;
    double computerSkills;
    double musicSkills;
    string bestSkill = "";
};

// Function to determine the best skill
string getBestSkill(Student student) {
    double maxSkill = student.mathSkills;
    string bestSkill = "Math";

    if (student.scienceSkills > maxSkill) {
        maxSkill = student.scienceSkills;
        bestSkill = "Science";
    }
    if (student.presentationSkills > maxSkill) {
        maxSkill = student.presentationSkills;
        bestSkill = "Presentation";
    }
    if (student.computerSkills > maxSkill) {
        maxSkill = student.computerSkills;
        bestSkill = "Computer";
    }
    if (student.musicSkills > maxSkill) {
        maxSkill = student.musicSkills;
        bestSkill = "Music";
    }

    return bestSkill;
}

int main() {
    const int SIZE = 6;
    Student studentArray[SIZE];

    // Open the file
    ifstream inputFile("students.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Read student records from the file
    for (int i = 0; i < SIZE; i++) {
        inputFile >> studentArray[i].id;
        inputFile >> studentArray[i].name;
        inputFile >> studentArray[i].mathSkills;
        inputFile >> studentArray[i].scienceSkills;
        inputFile >> studentArray[i].presentationSkills;
        inputFile >> studentArray[i].computerSkills;
        inputFile >> studentArray[i].musicSkills;

        // Determine the best skill for the student
        studentArray[i].bestSkill = getBestSkill(studentArray[i]);

        // Display the student information
        cout << "Student ID: " << studentArray[i].id << endl;
        cout << "Name: " << studentArray[i].name << endl;
        cout << "Math Skills: " << studentArray[i].mathSkills << endl;
        cout << "Science Skills: " << studentArray[i].scienceSkills << endl;
        cout << "Presentation Skills: " << studentArray[i].presentationSkills << endl;
        cout << "Computer Skills: " << studentArray[i].computerSkills << endl;
        cout << "Music Skills: " << studentArray[i].musicSkills << endl;
        cout << "Best Skill: " << studentArray[i].bestSkill << endl;
        cout << "-----------------------------------" << endl;
    }

    // Close the file
    inputFile.close();

    // Display the best skill for each student
    cout << "Best Skills for Each Student:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << studentArray[i].name << "'s best skill is: " << studentArray[i].bestSkill << endl;
    }

    return 0;
}