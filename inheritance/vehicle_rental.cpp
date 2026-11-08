#include<iostream>
#include<string>

using namespace std;

class Vehicle {
public:
	string brand;
	string model;
public:
	virtual double calculateRentalFee(int days) = 0;
	Vehicle(string brand, string model) :brand(brand), model(model) {}
	virtual void displayInfo() = 0;
};

class Car :public Vehicle {
private:
	int seats;
public:
	Car(string brand, string model, int seats) :Vehicle(brand, model), seats(seats) {}

	double calculateRentalFee(int days)override {
		return 200 * days + 15 * seats * days;
	}

	void displayInfo()override {
		cout << "Car" << " " << brand << " " << model;
	}
};

class Motorcycle :public Vehicle {
private:
	int cc;
public:
	Motorcycle(string brand, string model, int cc) :Vehicle(brand, model), cc(cc) {}
	double calculateRentalFee(int days)override {
		return 2 * cc * days;
	}
	void displayInfo()override {
		cout << "Motorcycle" << " " << brand << " " << model;
	}
};

class Bicycle :public Vehicle {
private:
	int isElectric;
public:
	Bicycle(string brand, string model, int is) :Vehicle(brand, model), isElectric(is) {}
	double calculateRentalFee(int days)override {
		if (isElectric == 0) {
			return 20 * days;
		}
		else {
			return 40 * days;
		}
	}
	void displayInfo()override {
		cout << "Bicycle" << " " << brand << " " << model << " ";
		if (isElectric == 0)cout << "False";
		else cout << "True";
	}
};

int main() {
	int N;
	cin >> N;
	while (N--) {
		char type;
		string brand;
		string model;
		int days;
		cin >> type;
		if (type == 'C') {
			int seats;
			cin >> brand >> model >> seats >> days;
			Car c(brand, model, seats);
			c.displayInfo();
			cout << " " << c.calculateRentalFee(days) << endl;
		}

		if (type == 'M') {
			int cc;
			cin >> brand >> model >> cc >> days;
			Motorcycle m(brand, model, cc);
			m.displayInfo();
			cout << " " << m.calculateRentalFee(days) << endl;
		}

		if (type == 'B') {
			int is;
			cin >> brand >> model >> is >> days;
			Bicycle b(brand, model, is);
			b.displayInfo();
			cout << " " << b.calculateRentalFee(days) << endl;
		}
	}
}