#include "Electric.h"
#include <iostream>

using namespace std; 

Electric::Electric(std::string name) : Vehicle(name, 0) {
    cout << "Constructor: Electric" << endl;
}

Electric::~Electric() {
    cout << "Destructor: Electric" << endl;
}

void Electric::Start() {
    cout << "Electric START" << endl;
}

void Electric::Stop() {
    cout << "Electric STOP" << endl;
}

double Electric::CostOfFuel() {
    // Implement actual fuel efficiency logic for electric vehicle
    return 0.05; // Placeholder value
}

double Electric::FuelEfficiency() {
    return 100.0; // Placeholder for electric vehicle's fuel efficiency
}
