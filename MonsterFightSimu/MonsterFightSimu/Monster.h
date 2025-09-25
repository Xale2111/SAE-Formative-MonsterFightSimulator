#pragma once
#include <condition_variable>

enum class Race
{
	Orc,
	Troll,
	Gobelin
};

class Monster
{
public:
	//Constructor
	Monster(int HealthPoint, int AttackDamage, int DefensePoint, int Speed, Race Race);

	//Actions
	int Attack(int enemyDefensePoint);
	void Pary();
	void Heal();

	std::string DisplayStats();

	//Access Name
	std::string GetName();
	void SetName();

	//Access Health
	int GetHealthPoint();
	void SetHealthPoint(int newHealth);

	//Access Damage
	int GetAttackDamage();

	//Access Defense and Pary
	int GetDefensePoint();
	int GetParyDefensePoint();
	void SetParyDefensePoint(int newDefense);

	//Access Pary round
	int GetParyRoundLeft();
	void SetParyRoundLeft(int newValue);
	void DecreaseParyRoundLeft();

	//Access speed
	int GetSpeed();

	//Access race
	Race GetRace();
private:
	std::string _name;
	int _healthPoint;
	int _attackDamage;
	int _defensePoint;
	int _paryDefense;
	int _speed;
	int _paryRoundLeft = 0;
	Race _race;
};
