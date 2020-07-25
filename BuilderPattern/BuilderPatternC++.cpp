#include <iostream>

using namespace std;

// Class Plane
class Plane 
{
private:
	string m_name;
	string m_body;
	string m_engine;

public:

	Plane(string name) : m_name(name){}
	string GetBody(){ return m_body; }
	void SetBody(string body) { m_body = body; }
	string GetEngine() { return m_engine; }
	void SetEngine(string engine) { m_engine = engine; }
	void ShowPlaneInfo()
	{
		cout << "Plane Type : " << m_name << endl;
		cout << "Plane Body : " << m_body << endl;
		cout << "Plane Engine : " << m_engine << endl << endl;
	}
};

// Abstract Class IPlaneBuilder
class IPlaneBuilder
{
protected:
	Plane* planePtr;
public:

	virtual void BuildBody() = 0;
	virtual void BuildEngine() = 0;
	virtual void GetPartsDone() = 0;
	Plane* GetPlane(){ return planePtr; }
};


// Concrete implementation of JetBuilder
class JetBuilder : public IPlaneBuilder
{
public:

	JetBuilder() = default;

	void GetPartsDone(){ planePtr = new Plane("Jet Plane"); }

	void BuildBody() { planePtr->SetBody("Jet Body"); }
	
	void BuildEngine() { planePtr->SetEngine("Jet Engine"); }
};

// Concrete implementation of PropellerBuilder
class PropellerBuilder : public IPlaneBuilder
{
public:

	PropellerBuilder() = default;

	void GetPartsDone() { planePtr = new Plane("Propeller Plane"); }

	void BuildBody() { planePtr->SetBody("Propeller Body"); }

	void BuildEngine() { planePtr->SetEngine("Propeller Engine"); }
};

// Class Director
class Director 
{
public:

	Director() = default;

	Plane* CreatePlane(IPlaneBuilder* builder) 
	{
		builder->GetPartsDone();
		builder->BuildBody();
		builder->BuildEngine();
		return builder->GetPlane();
	}
	
};

int main()
{
	Director d;
	JetBuilder jb;
	PropellerBuilder pb;

	Plane* jetPlane = d.CreatePlane(&jb);
	cout << "Created a jetplane object" << endl;
	jetPlane->ShowPlaneInfo();

	Plane* propellerPlane = d.CreatePlane(&pb);
	cout << "Created a propellerplane object" << endl;
	propellerPlane->ShowPlaneInfo();

	delete jetPlane;
	delete propellerPlane;
	return 0;
}

/* 
Output

Created a jetplane object
Plane Type : Jet Plane
Plane Body : Jet Body
Plane Engine : Jet Engine

Created a propellerplane object
Plane Type : Propeller Plane
Plane Body : Propeller Body
Plane Engine : Propeller Engine

*/
