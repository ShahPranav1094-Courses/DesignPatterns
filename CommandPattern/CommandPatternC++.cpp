#include <iostream>
#include <stack>

using namespace std;

// Light Class
class Light
{
	string m_name;

public:
	Light(string name) : m_name(name) {}
	void TurnOn() { cout << "Powering On the " << m_name << " lights ...." << endl << endl; }
	void TurnOff() { cout << "Powering Off the " << m_name << " lights ..." << endl << endl; }
};

// Fan Class
class Fan
{
	string m_name;

public:
	Fan(string name) : m_name(name) {}
	void Start() { cout << "Starting the " << m_name << " fan ...." << endl << endl; }
	void Stop() { cout << "Stopping the "<< m_name << " fan ..." << endl << endl; }
};

// Abstract class Command
class Command
{
public:

	virtual void Execute() = 0;
	virtual void Unexecute() = 0;
};

// Class LightOnCommand
class LightOnCommand : public Command
{
	Light* m_light;
public:
	LightOnCommand(Light* light) : m_light(light){}
	void Execute() { m_light->TurnOn(); }
	void Unexecute() { m_light->TurnOff(); }
};

// Class FanOnCommand
class FanOnCommand : public Command
{
	Fan* m_fan;
public:
	FanOnCommand(Fan* fan) : m_fan(fan) {}
	void Execute() { m_fan->Start(); }
	void Unexecute() { m_fan->Stop(); }
};

// Class ButtonInvoker
class ButtonInvoker
{
	Command* m_command;
	stack<Command*> m_history;

public:

	ButtonInvoker() = default;
	void SetCommand(Command* command) { m_command = command; }
	void ExecuteCommand() { m_history.push(m_command); m_command->Execute(); }
	void UnexecuteCommand() 
	{ 
		if (!m_history.empty())
		{
			m_history.top()->Unexecute();
			m_history.pop();
		}
	}
};

// Main Method
int main()
{
	// Here we have one instance of button
	ButtonInvoker button;

	// Let's create two instances of each FanOnCommand and LightOnCommand
	LightOnCommand* syskaLightCommand = new LightOnCommand(new Light("Syska"));
	LightOnCommand* philipsLightCommand = new LightOnCommand(new Light("Philips"));
	FanOnCommand* bajajFanCommand = new FanOnCommand(new Fan("Bajaj"));
	FanOnCommand* kaitanFanCommand = new FanOnCommand(new Fan("Kaitan"));

	// Now let's assign syskaLightOnCommand to button
	button.SetCommand(syskaLightCommand);

	// Let's turn on syska light
	button.ExecuteCommand();

	// Let's undo above operation
	button.UnexecuteCommand();

	// Now let's assign philipsLightCommand to button
	button.SetCommand(philipsLightCommand);

	// Let's turn on philips light
	button.ExecuteCommand();

	// Now let's assign bajajFanCommand to button
	button.SetCommand(bajajFanCommand);

	// Let's turn on bajaj fan
	button.ExecuteCommand();

	// Now let's assign kaitanFanCommand to button
	button.SetCommand(kaitanFanCommand);

	// Let's turn on katan fan
	button.ExecuteCommand();

	// Now lets undo all the operations to save electricity
	button.UnexecuteCommand();
	button.UnexecuteCommand();
	button.UnexecuteCommand();

	return 0;
}

/*
Output

Powering On the Syska lights ....

Powering Off the Syska lights ...

Powering On the Philips lights ....

Starting the Bajaj fan ....

Starting the Kaitan fan ....

Stopping the Kaitan fan ...

Stopping the Bajaj fan ...

Powering Off the Philips lights ...

*/
