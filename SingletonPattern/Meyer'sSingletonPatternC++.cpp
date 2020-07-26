#include <iostream>

using namespace std;

/*
	Steps for creating a singleton class

	1. Make the constructor private
	2. Delete Copy constructor and Copy assignment operators
	3. Create a GetInstance method which is static and return class&. This method has a local static class object

*/

// Class GameSettings
class GameSettings
{
	int m_width;
	int m_height;
	int m_brightness;

	// Make constructor private
	GameSettings() : m_width(150), m_height(200), m_brightness(70) {}

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

	// GetInstance returns the singleton object reference
	static GameSettings& GetInstance()
	{
		static GameSettings gameSettings;
		return gameSettings;
	}
};

// Main method
int main()
{
	GameSettings& instance = GameSettings::GetInstance();
	instance.PrintDetails();
	return 0;
}

/*
Output

Brightness : 70
Width      : 150
Height     : 200

*/
