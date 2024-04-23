#include "Hybrid.h"
#include <iostream>

using namespace std;

Hybrid::Hybrid(std::string name) : Vehicle(name, 0), Electric(name), Gasoline(name) {
    cout << "Constructor: Hybrid" << endl;
}

Hybrid::~Hybrid() {
    cout << "Destructor: Hybrid" << endl;
}

void Hybrid::Start() {
    Electric::Start(); // Or Gasoline::Start();
}

void Hybrid::Stop() {
    Electric::Stop(); // Or Gasoline::Stop();
}

double Hybrid::CostOfFuel() {
    // Combines the fuel efficiency of both electric and gasoline
    return (Electric::CostOfFuel() + Gasoline::CostOfFuel()) / 2.0; // Placeholder combining logic
}

double Hybrid::FuelEfficiency() {
    // Hybrid's fuel efficiency could be a combination of Electric and Gasoline efficiencies
    return (Electric::FuelEfficiency() + Gasoline::FuelEfficiency()) / 2.0; // Simple average for placeholder
}
