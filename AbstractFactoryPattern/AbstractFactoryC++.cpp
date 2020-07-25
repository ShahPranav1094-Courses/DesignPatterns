#include <iostream>

using namespace std;

/* --------------------------------------------
	      Tire & Body Classes
-------------------------------------------- */

// Tire Class
class Tire
{
	string name;
	int pressure;

public:

	Tire(string name, int pressure) : name(name), pressure(pressure) {}
	string GetName() { return name; }
	int GetPressure() { return pressure; }
};

// Simple Tire Class
class SimpleTire : public Tire
{
public:
	SimpleTire() : Tire("SimpleTire", 75) {}
};

// Luxury Tire Class
class LuxuryTire : public Tire
{
public:
	LuxuryTire() : Tire("LuxuryTire", 100) {}
};


// Body Class
class Body
{
	string name;
	int strength;

public:

	Body(string name, int strength) : name(name), strength(strength) {}
	int GetStrength() { return strength; }
	string GetName() { return name; }
};

// Simple Body Class
class SimpleBody : public Body
{
public:
	SimpleBody() : Body("SimpleBody", 75) {}
};

// Luxury Body Class
class LuxuryBody : public Body
{
public:
	LuxuryBody() : Body("LuxuryBody", 100) {}
};


/* --------------------------------------------
	        Car Class
-------------------------------------------- */

// Car Class
class Car
{
	Body* bodyPtr;
	Tire* tirePtr;
	string name;
public:
	void PrintDetails()
	{
		cout << endl << "Car Type : " << name << endl;
		cout << "Tire : " << tirePtr->GetName() << " Pressure : " << tirePtr->GetPressure() << endl;
		cout << "Body : " << bodyPtr->GetName() << " Strength : " << bodyPtr->GetStrength() << endl << endl;
	}

	Car(string name) : name(name) {}
	void SetBody(Body* b) { bodyPtr = b; }
	void SetTire(Tire* t) { tirePtr = t; }
};



/* --------------------------------------------
	    Factory Classes
-------------------------------------------- */

// Abstract Car Factory
class CarFactory
{
	Car* carPtr;

protected:
	virtual Body* BuildBody() = 0;
	virtual Tire* BuildTire() = 0;

public:
	virtual Car* BuildWholeCar() = 0;
};

// SimpleCarFactory Class
class SimpleCarFactory : public CarFactory
{
protected:
	Body* BuildBody() { return new SimpleBody(); }
	Tire* BuildTire() { return new SimpleTire(); }
public:
	Car* BuildWholeCar() 
	{
		Car* car = new Car("SimpleCar");
		car->SetBody(BuildBody());
		car->SetTire(BuildTire());
		return car;
	}
};

// LuxuryCarFactory Class
class LuxuryCarFactory : public CarFactory
{
protected:
	Body* BuildBody() { return new LuxuryBody(); }
	Tire* BuildTire() { return new LuxuryTire(); }
public:
	Car* BuildWholeCar()
	{
		Car* car = new Car("LuxuryCar");
		car->SetBody(BuildBody());
		car->SetTire(BuildTire());
		return car;
	}
};


#define SIMPLE_CAR 1
//#define LUXURY_CAR 1

int main()
{
	#ifdef SIMPLE_CAR
		CarFactory* factory = new SimpleCarFactory;
	#elif LUXURY_CAR
		CarFactory* factory = new LuxuryCarFactory;
	#endif
		
	Car* car = factory->BuildWholeCar();
	car->PrintDetails();

	return 0;
}

/*
Output

Car Type : SimpleCar
Tire : SimpleTire Pressure : 75
Body : SimpleBody Strength : 75

Car Type : LuxuryCar
Tire : LuxuryTire Pressure : 100
Body : LuxuryBody Strength : 100

*/