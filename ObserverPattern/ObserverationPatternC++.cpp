#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Subject;

// Abstract Observer Class
class Observer
{
	Subject* m_subject;

public:
	Observer(Subject* subject) : m_subject(subject){}
	virtual void Update() = 0;

protected:
	Subject* GetSubject() { return m_subject; }
};

// ObserverA class
class ObserverA : public Observer
{
	void Update() 
	{ 
		cout << "Inside ObserverA::Update" << endl;
	}

public:
	ObserverA(Subject* subject) : Observer(subject){}
};

// ObserverB class
class ObserverB : public Observer
{
	void Update()
	{
		cout << "Inside ObserverB::Update" << endl;
		cout << endl;
	}

public:
	ObserverB(Subject* subject) : Observer(subject) {}
};

// Subject Class (Observerable)
class Subject
{
	vector<Observer*> m_observerList;
	int m_updater=0;

public:

	Subject() = default;
	int GetUpdater() { return m_updater; }
	void SetUpdater(int updater) { m_updater = updater; Notify(); }
	void RegisterObserver(Observer* observer) { m_observerList.emplace_back(observer); }
	void UnRegisterObserver(Observer* observer) { m_observerList.erase(std::remove(m_observerList.begin(), m_observerList.end(), observer), m_observerList.end()); }
	void Notify()
	{
		for (const auto obs : m_observerList)
			obs->Update();
	}
};

// Main Method
int main()
{
	Subject* subject = new Subject;

	ObserverA* obsA = new ObserverA(subject);
	ObserverB* obsB = new ObserverB(subject);

	subject->RegisterObserver(obsA);
	subject->RegisterObserver(obsB);

	subject->SetUpdater(3);

	subject->SetUpdater(4);

	return 0;
}
