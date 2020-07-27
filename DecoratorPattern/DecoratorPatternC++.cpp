#include <iostream>

using namespace std;

// Abstract class Coffee
class Coffee
{
public:

	virtual int Cost() = 0;
	virtual string Description() = 0;
};

// Class Decaf
class Decaf : public Coffee
{
public:
	Decaf() = default;
	int Cost() override { return 12; }
	string Description() override { return "Coffee type : Decaf, Ingredients : "; }
};

// Class Espresso
class Espresso : public Coffee
{
public:
	Espresso() = default;
	int Cost() { return 18; }
	string Description() { return "Coffee type : Espresso, Ingredients : "; }
};

// Abstract decorator class CoffeeDecorator
class CoffeeDecorator : public Coffee
{
protected:
	Coffee* m_coffee;

public:
	virtual int Cost() = 0;
	virtual string Description() = 0;
};

// Class Caramel
class Caramel : public CoffeeDecorator
{
public:
	Caramel(Coffee* coffee) { m_coffee = coffee; }
	int Cost() { return m_coffee->Cost() + 3; }
	string Description() { return m_coffee->Description() + "Caramel "; }
};

// Class ChocoChips
class ChocoChips : public CoffeeDecorator
{
public:
	ChocoChips(Coffee* coffee) { m_coffee = coffee; }
	int Cost() { return m_coffee->Cost() + 5; }
	string Description() { return m_coffee->Description() + "ChocoChips "; }
};

// Main Method
int main()
{
	// Let's create a decaf with caramel
	Coffee* decaf = new Decaf;
	Coffee* coffee = new Caramel(decaf);
	cout << coffee->Description() << endl;
	cout << "The Cost of the coffee is : " << coffee->Cost() << endl << endl;
	
	// Let's create a espresso with caramel and chocochips
	Coffee* espresso = new Espresso;
	Coffee* caramel = new Caramel(espresso);
	Coffee* chocochip = new ChocoChips(caramel);
	cout << chocochip->Description() << endl;
	cout << "The Cost of the coffee is : " << chocochip->Cost() << endl << endl;

	return 0;
	
}

/*
Output

Coffee type : Decaf, Ingredients : Caramel
The Cost of the coffee is : 15

Coffee type : Espresso, Ingredients : Caramel ChocoChips
The Cost of the coffee is : 26

*/
