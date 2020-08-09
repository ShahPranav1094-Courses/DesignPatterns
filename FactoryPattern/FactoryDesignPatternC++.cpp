#include <iostream>

using namespace std;

// IToy Abstract Class
class IToy
{
protected:
	string m_name;
	int m_price;

public:

	virtual void PrepareParts() = 0;
	virtual void CombineParts() = 0;
	virtual void AssembleParts() = 0;
	virtual void ApplyLabel() = 0;
	virtual void ShowProduct() = 0;
};

// Class Car
class Car : public IToy
{
public:
	Car() = default;
	void PrepareParts() { m_name = "Car"; cout << "Preparing Car Parts" << endl; }
	void CombineParts() { cout << "Combining Car Parts" << endl; }
	void AssembleParts() { cout << "Assembling Car Parts" << endl; }
	void ApplyLabel() { m_price = 100; cout << "Applying label for Car Parts" << endl; }
	void ShowProduct() { cout << "Toy Name : " << m_name << endl; cout << "Toy Price is : " << m_price << endl; }
};

// Class Bike
class Bike : public IToy
{
public:
	Bike() = default;
	void PrepareParts() { m_name = "Bike"; cout << "Preparing Bike Parts" << endl; }
	void CombineParts() { cout << "Combining Bike Parts" << endl; }
	void AssembleParts() { cout << "Assembling Bike Parts" << endl; }
	void ApplyLabel() { m_price = 50; cout << "Applying label for Bike Parts" << endl; }
	void ShowProduct() { cout << "Toy Name : " << m_name << endl; cout << "Toy Price is : " << m_price << endl; }
};

// Class Plane
class Plane : public IToy
{
public:
	Plane() = default;
	void PrepareParts() { m_name = "Plane"; cout << "Preparing Plane Parts" << endl; }
	void CombineParts() { cout << "Combining Plane Parts" << endl; }
	void AssembleParts() { cout << "Assembling Plane Parts" << endl; }
	void ApplyLabel() { m_price = 200; cout << "Applying label for Plane Parts" << endl; }
	void ShowProduct() { cout << "Toy Name : " << m_name << endl; cout << "Toy Price is : " << m_price << endl; }
};

class ToyFactory
{
public:
	static IToy* CreateToy(int type)
	{
		IToy* toy = nullptr;
		switch (type)
		{
		case 1:
			toy = new Car;
			break;
		case 2:
			toy = new Bike;
			break;
		case 3:
			toy = new Plane;
			break;
		default:
			cout << "Invalid selection !!" << endl;
			return nullptr;
		}
		toy->PrepareParts();
		toy->CombineParts();
		toy->AssembleParts();
		toy->ApplyLabel();
		return toy;
	}
};

// Main Method
int main()
{
	int option;
	while (1)
	{
		cout << endl << "Enter the type of toy : ";
		cin >> option;
		cout << endl;
		IToy* toy = ToyFactory::CreateToy(option);
		if(toy != nullptr)
			toy->ShowProduct();
		delete toy;
	}
	return 0;
}

/* 
Output

Enter the type of toy : 1

Preparing Car Parts
Combining Car Parts
Assembling Car Parts
Applying label for Car Parts
Toy Name : Car
Toy Price is : 100

Enter the type of toy : 2

Preparing Bike Parts
Combining Bike Parts
Assembling Bike Parts
Applying label for Bike Parts
Toy Name : Bike
Toy Price is : 50

Enter the type of toy : 3

Preparing Plane Parts
Combining Plane Parts
Assembling Plane Parts
Applying label for Plane Parts
Toy Name : Plane
Toy Price is : 200

Enter the type of toy : 4

Invalid selection !!

*/
