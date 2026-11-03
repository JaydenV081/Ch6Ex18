/*
Developer: Jayden Veloz
File Name: Ch6Ex18.cpp
Date: 11 / 3 / 26
*/

#include <iostream>
#include <iomanip>

using namespace std;

int calculateNP(int initialPopulation, double birthRate, double deathRate);

int main() {
    int initialPopulation, years;
    double birthRate, deathRate;

    // Initial Population
    cout << "Please enter the following \nStarting size of population (minimum 2): ";
    cin >> initialPopulation;

    while (initialPopulation < 2) {
        cout << "Please enter a valid number: ";
        cin >> initialPopulation;
    }

    // Annual Birth Rate
    cout << "Annual birth rate (per 1,000): ";
    cin >> birthRate;
    birthRate /= 1000;

    while (birthRate > 1000) {
        cout << "Birth rate cannot exceed 1000 people. Please enter a valid number: ";
        cin >> birthRate;
    }

    // Annual Death Rate
    cout << "Annual death rate (per 1,000: ";
    cin >> deathRate;
    deathRate /= 1000;

    while (deathRate > 1000) {
        cout << "Death rate cannot exceed 1000 people. Please enter a valid number: ";
        cin >> deathRate;
    }

    // Years displayed
    cout << "Number of years to display (minimum 1): ";
    cin >> years;

    while (years < 1) {
        cout << "Please enter a valid number: ";
        cin >> years;
    }

    int newPopulation = calculateNP(initialPopulation, birthRate, deathRate);

    // Displays menu
    cout << "\n" << setw(5) << "Year" << setw(5) << " " << setw(5) << "Initial Population"
    << setw(5) << " " << setw(5) << "New Population" << endl;
    cout << "------------------------------------------------" << endl;

    // Displays initial and new population after each year
    for (int i = 1; i <= years; i++) {
        cout << setw(3) << right << i << setw(18) << right << initialPopulation
        << setw(21) << right << newPopulation << endl;

        // After new year, the new population of the previous year becomes the initial for the following year
        initialPopulation = newPopulation;
        newPopulation = calculateNP(initialPopulation, birthRate, deathRate);
    }
}

int calculateNP(int initialPopulation, double birthRate, double deathRate) {
    return static_cast<int>(initialPopulation * (1 + birthRate) * (1 - deathRate));
}