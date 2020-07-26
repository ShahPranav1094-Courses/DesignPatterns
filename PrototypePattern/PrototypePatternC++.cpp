#include <iostream>
#include <memory>
#include <unordered_map>

using namespace std;

// Bullet Types enum
enum BulletType
{
	SIMPLE,
	GOOD
};

// Abstract Class Bullet
class Bullet
{
protected:
	string m_name;
	int m_speed;
	int m_direction;
	int m_firePower;
	int m_damagePower;

	Bullet(string name, int firePower, int damagePower, int speed) : m_name(name), m_firePower(firePower), m_damagePower(damagePower), m_speed(speed) {}

public:

	virtual void Fire(int direction) = 0;
	virtual unique_ptr<Bullet> Clone() = 0;

};

// Class SimpleBullet
class SimpleBullet : public Bullet
{
public:

	SimpleBullet(string name, int firePower, int damagePower, int speed) : 
		Bullet(name, firePower, damagePower, speed){}

	void Fire(int direction) 
	{ 
		m_direction = direction; 
		cout << "Bullet Type : " << m_name << endl;
		cout << "Bullet FirePower : " << m_firePower << endl;
		cout << "Bullet DamagePower : " << m_damagePower << endl;
		cout << "Bullet Speed : " << m_speed << endl;
		cout << "Bullet Directon : " << m_direction << endl << endl;
	}

	unique_ptr<Bullet> Clone()
	{
		return make_unique<SimpleBullet>(*this);
	}
};

// Class GoodBullet
class GoodBullet : public Bullet
{
public:

	GoodBullet(string name, int firePower, int damagePower, int speed) :
		Bullet(name, firePower, damagePower, speed) {}

	void Fire(int direction)
	{
		m_direction = direction;
		cout << "Bullet Type : " << m_name << endl;
		cout << "Bullet FirePower : " << m_firePower << endl;
		cout << "Bullet DamagePower : " << m_damagePower << endl;
		cout << "Bullet Speed : " << m_speed << endl;
		cout << "Bullet Directon : " << m_direction << endl << endl;
	}

	unique_ptr<Bullet> Clone()
	{
		return make_unique<GoodBullet>(*this);
	}
};

// Bullet Factory
class BulletFactory
{
	unordered_map<BulletType, unique_ptr<Bullet>, hash<int>> m_bullets;

public:

	BulletFactory()
	{
		m_bullets[SIMPLE] = make_unique<SimpleBullet>("Simple Bullet", 50, 75, 75);
		m_bullets[GOOD] = make_unique<GoodBullet>("Good Bullet", 75, 100, 100);
	}

	unique_ptr<Bullet> CreateBullet(BulletType type)
	{
		return m_bullets[type]->Clone();
	}
};

// Main Method
int main()
{
	BulletFactory bulletFactory;

	auto bullet = bulletFactory.CreateBullet(SIMPLE);
	bullet->Fire(75);

	bullet = bulletFactory.CreateBullet(GOOD);
	bullet->Fire(100);

	return 0;
}

/*
Output

Bullet Type : Simple Bullet
Bullet FirePower : 50
Bullet DamagePower : 75
Bullet Speed : 75
Bullet Directon : 75

Bullet Type : Good Bullet
Bullet FirePower : 75
Bullet DamagePower : 100
Bullet Speed : 100
Bullet Directon : 100

*/
