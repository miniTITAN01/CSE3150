#include "Gasoline.h"
#include <iostream>

using namespace std;

Gasoline::Gasoline(std::string name) : Vehicle(name, 0) {
    cout << "Constructor: Gasoline" << endl;
}

Gasoline::~Gasoline() {
    cout << "Destructor: Gasoline" << endl;
}

void Gasoline::Start() {
    cout << "Gasoline START" << endl;
}

void Gasoline::Stop() {
    cout << "Gasoline STOP" << endl;
}

double Gasoline::CostOfFuel() {
    // Implement actual cost calculation for gasoline vehicle
    return 0.15; // Placeholder value
}

double Gasoline::FuelEfficiency() {
    return 30.0; // Placeholder for gasoline vehicle's fuel efficiency
}
