#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
	public:
		Vehicle(){}
		Vehicle(string name) {
			cout << "Constructor: Vehicle" << endl;
		}
		
		~Vehicle() {
			cout << "destructor: Vehicle" << endl;
		}
		
		string name;
};


class Gasoline : public Vehicle {
	public:
		Gasoline(string name) : Vehicle(name) {
			cout << "Constructor: Gasoline" << endl;
		}
		~Gasoline() {
			cout << "destructor: Gasoline" << endl;
		}
};

class Electric : public Vehicle {
	public:
		Electric(string name) : Vehicle(name) {
			cout << "Constructor: Electric" << endl;
		}
		~Electric() {
			cout << "destructor: Electric" << endl;
		}
};

class Hybrid : public Electric, public Gasoline {
	public:
		Hybrid(string name) : Electric("Dad"), Gasoline("Mom") {
			cout << "Constructor: Hybrid" << endl;
		}
		~Hybrid() {
			cout << "Destructor: Hybrid" << endl;
		}
};


int main() {
	string whichVehicle = "Super vehicle";
	Hybrid Hybrid(whichVehicle);

}