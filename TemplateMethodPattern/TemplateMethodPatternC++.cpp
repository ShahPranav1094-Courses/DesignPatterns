#include <iostream>

using namespace std;

// Abstract Class Record
class Record
{
public:

	virtual void BeforeSave()
	{
		cout << "This piece of code might be same for all the sub-classes and can be overriden if needed." << endl;
	}

	virtual void Validate() = 0;
	
	void TemplateMethodSave()
	{
		cout << "Some code......" << endl;
		cout << "\t .............." << endl;
		cout << "\t .............." << endl;
		cout << "\t .............." << endl;
		BeforeSave();
		cout << "Some code......" << endl;
		cout << "\t .............." << endl;
		cout << "\t .............." << endl;
		cout << "\t .............." << endl;
		Validate(); // Delegate to sub-class implementation
		cout << "Some code......" << endl;
		cout << "\t .............." << endl;
		cout << "\t .............." << endl;
		cout << "\t .............." << endl;
		cout << "Actual Save .." << endl << endl;
	}
};

// Class UserRecord
class UserRecord : public Record
{
public:
	void Validate() { cout << "Validating user record.. ." << endl; }
	UserRecord() = default;
};

// Class StudentRecord
class StudentRecord : public Record
{
public:
	void Validate() { cout << "Validating student record.. ." << endl; }
	StudentRecord() = default;
	void BeforeSave()
	{
		cout << "Changing this method for Student..." << endl;
	}
};

// Main Method
int main()
{
	UserRecord u;
	u.TemplateMethodSave();
	StudentRecord s;
	s.TemplateMethodSave();
	return 0;
}

/*
Output

Some code......
		 ..............
		 ..............
		 ..............
This piece of code might be same for all the sub-classes and can be overriden if needed.
Some code......
		 ..............
		 ..............
		 ..............
Validating user record.. .
Some code......
		 ..............
		 ..............
		 ..............
Actual Save ..

Some code......
		 ..............
		 ..............
		 ..............
Changing this method for Student...
Some code......
		 ..............
		 ..............
		 ..............
Validating student record.. .
Some code......
		 ..............
		 ..............
		 ..............
Actual Save ..

*/
