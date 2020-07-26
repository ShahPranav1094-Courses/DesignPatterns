#include <iostream>

using namespace std;

/* 
	Steps for creating a singleton class
	
	1. Create a static member in a class of type class*
	2. Make the constructor private
	3. Delete Copy constructor and Copy assignment operators
	4. Create a GetInstance method which is static and return class*

*/

// Class GameSettings
class GameSettings
{
	int m_width;
	int m_height;
	int m_brightness;

	// Static member
	static GameSettings* m_gameSettings;

	// Make constructor private
	GameSettings() : m_width(100), m_height(200), m_brightness(70){}

	// Delete the Copy constructor and Copy assignment operators
	GameSettings(const GameSettings& obj) = delete;
	GameSettings& operator=(const GameSettings& obj) = delete;

public:

	void PrintDetails()
	{
		cout << "Brightness : " << m_brightness << endl;
		cout << "Width      : " << m_width << endl;
		cout << "Height     : " << m_height << endl << endl;
	}

	// GetInstance returns the singleton object
	static GameSettings* GetInstance()
	{
		if (m_gameSettings == nullptr)
			m_gameSettings = new GameSettings();
		return m_gameSettings;
	}
};

GameSettings* GameSettings::m_gameSettings = nullptr;

// Main method
int main()
{
	GameSettings* instance = GameSettings::GetInstance();
	instance->PrintDetails();
	return 0;
}

/*
Output

Brightness : 70
Width      : 100
Height     : 200

*/
