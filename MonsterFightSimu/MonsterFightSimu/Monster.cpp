#include "Monster.h"
#include <format>

Monster::Monster(int HealthPoint, int AttackDamage, int DefensePoint, int Speed, Race Race)
{
	_healthPoint = HealthPoint;
	_attackDamage = AttackDamage;
	_defensePoint = DefensePoint;
	_paryDefense = _defensePoint;
	_speed = Speed;
	_race = Race;
	SetName();

}

//Monster Actions (Heal, Attack, Pary)

void Monster::Heal()
{
	SetHealthPoint(GetHealthPoint() + 2);
}

int Monster::Attack(int enemyDefensePoint)
{
	int damage = GetAttackDamage() - enemyDefensePoint;
	return damage = damage > 0 ? damage : 0;
}

void Monster::Pary()
{
	SetParyDefensePoint(GetDefensePoint() + ceil(GetDefensePoint()/2));
	SetParyRoundLeft(2);
}

//Display Monster Stats
std::string Monster::DisplayStats()
{
	std::string allStats = "Race '" + GetName() + "' Stats are :\n" +"HP : " + std::to_string(GetHealthPoint()) + " | AD : "
		+ std::to_string(GetAttackDamage()) + " | DP : "+ std::to_string(GetDefensePoint()) + " | Speed : " + std::to_string(GetSpeed());
	return allStats;
}

//Set Monster Name based on race
void Monster::SetName()
{
	switch (GetRace())
	{
	case Race::Orc:
		_name = "Orc";
		break;
	case Race::Troll:
		_name = "Troll";
		break;
	case Race::Gobelin:
		_name = "Gobelin";
		break;
	default:
		_name = "No race, I guess ...?";
		break;;
	}
}


std::string Monster::GetName()
{
	return _name;
}

//Access Health

int Monster::GetHealthPoint()
{
	return _healthPoint;
}

void Monster::SetHealthPoint(int newHealth)
{
	_healthPoint = newHealth;
}

//Access Damage

int Monster::GetAttackDamage()
{
	return _attackDamage;
}

//Access Defense and Pary

int Monster::GetDefensePoint()
{
	return _defensePoint;
}

int Monster::GetParyDefensePoint()
{
	return _paryDefense;
}

void Monster::SetParyDefensePoint(int newDefense)
{
	_paryDefense = newDefense;
}

//Access Pary rounds

int Monster::GetParyRoundLeft()
{
	return _paryRoundLeft;
}

void Monster::SetParyRoundLeft(int newValue)
{
	_paryRoundLeft = newValue;
}


void Monster::DecreaseParyRoundLeft()
{
	if (GetParyRoundLeft()<= 0)
	{
		SetParyDefensePoint(GetDefensePoint());
	}
	SetParyRoundLeft(GetParyRoundLeft()-1);

}

//Access Speed

int Monster::GetSpeed()
{
	return _speed;
}

//Access Race

Race Monster::GetRace()
{
	return _race;
}


