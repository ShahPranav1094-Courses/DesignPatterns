#include <iostream>

using namespace std;

// Abstract Quack Interface
class IQuackBehavior
{
public:

	virtual void Quack() = 0;
};

// SimpleQuackBehavior Class
class SimpleQuackBehavior : public IQuackBehavior
{
public:
	SimpleQuackBehavior() = default;
	void Quack() override
	{
		cout << "\t QuackBehavior : Simple" << endl;
	}
};

// WildQuackBehavior Class
class WildQuackBehavior : public IQuackBehavior
{
public:
	WildQuackBehavior() = default;
	void Quack() override
	{
		cout << "\t QuackBehavior : Wild" << endl;
	}
};


// Abstract Fly Interface
class IFlyBehavior
{
public:

	virtual void Fly() = 0;
};

// RegularFlyBehavior Class
class RegularFlyBehavior : public IFlyBehavior
{
public:
	RegularFlyBehavior() = default;
	void Fly() override
	{
		cout << "\t FlyBehavior : Regular" << endl;
	}
};

// JetFlyBehavior Class
class JetFlyBehavior : public IFlyBehavior
{
public:
	JetFlyBehavior() = default;
	void Fly() override
	{
		cout << "\t FlyBehavior : Jet" << endl;
	}
};


// Abstract Display Interface
class IDisplayBehavior
{
public:

	virtual void Display() = 0;
};

// NormalDisplayBehavior Class
class NormalDisplayBehavior : public IDisplayBehavior
{
public:
	NormalDisplayBehavior() = default;
	void Display() override
	{
		cout << "\t DisplayBehavior : Normal" << endl << endl;
	}
};

// GraphicalDisplayBehavior Class
class GraphicalDisplayBehavior : public IDisplayBehavior
{
public:
	GraphicalDisplayBehavior() = default;
	void Display() override
	{
		cout << "\t DisplayBehavior : Graphical" << endl << endl;
	}
};


// Duck Class
class Duck
{
	IDisplayBehavior* m_displayBehavior;
	IQuackBehavior* m_quackBehavior;
	IFlyBehavior* m_flyBehavior;

public:

	Duck(IDisplayBehavior* displayBehavior, IQuackBehavior* quackBehavior, IFlyBehavior* flyBehavior) 
		: m_displayBehavior(displayBehavior), m_quackBehavior(quackBehavior), m_flyBehavior(flyBehavior){}

	void Display() { m_displayBehavior->Display(); }
	void Quack() { m_quackBehavior->Quack(); }
	void Fly() { m_flyBehavior->Fly(); }
	void DuckInfo()
	{
		cout << "New Duck created with following behavior :" << endl;
		Quack();
		Fly();
		Display();
	}
};

// Main Method
int main()
{
	IQuackBehavior* simpleQuack = new SimpleQuackBehavior;
	IQuackBehavior* wildQuack = new WildQuackBehavior;
	IFlyBehavior* regularFly = new RegularFlyBehavior;
	IFlyBehavior* jetFly = new JetFlyBehavior;
	IDisplayBehavior* normalDisplay = new NormalDisplayBehavior;
	IDisplayBehavior* graphicalDisplay = new GraphicalDisplayBehavior;

	// Duck with normal display, simple quack and regular fly
	Duck d1(normalDisplay, simpleQuack, regularFly);
	d1.DuckInfo();

	// Duck with graphical display, wild quack and jet fly
	Duck d2(graphicalDisplay, wildQuack, jetFly);
	d2.DuckInfo();

	// Duck with normal display, wild quack and regular fly
	Duck d3(normalDisplay, wildQuack, regularFly);
	d3.DuckInfo();

	// Duck with graphical display, simple quack and jet fly
	Duck d4(graphicalDisplay, simpleQuack, jetFly);
	d4.DuckInfo();

	return 0;
}

/*
Output

New Duck created with following behavior :
	QuackBehavior : Simple
	FlyBehavior : Regular
	DisplayBehavior : Normal

New Duck created with following behavior :
	QuackBehavior : Wild
	FlyBehavior : Jet
	DisplayBehavior : Graphical

New Duck created with following behavior :
	QuackBehavior : Wild
	FlyBehavior : Regular
	DisplayBehavior : Normal

New Duck created with following behavior :
	QuackBehavior : Simple
	FlyBehavior : Jet
	DisplayBehavior : Graphical

*/
