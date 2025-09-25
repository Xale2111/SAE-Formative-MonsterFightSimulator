#include <iostream>
#include <thread>
#include <chrono>
#include "Monster.h"



int main()
{
	const int NUMBER_OF_MONSTERS = 3;
	Monster allMonsters[NUMBER_OF_MONSTERS] = {
	Monster(25,5,4,2, Race::Orc),
	Monster(19,7,2,4, Race::Troll),
	Monster(15,9,1,8, Race::Gobelin),
	};

	int input;

	do
	{
		system("cls");

		for (int i = 0; i < NUMBER_OF_MONSTERS; ++i)
		{
			std::cout << allMonsters[i].DisplayStats() << "\n\n";
		}
		std::cout << "Who is our first fighter ?" << std::endl;
		for (int i = 0; i < NUMBER_OF_MONSTERS; ++i)
		{
			std::cout << i + 1 << " : " << allMonsters[i].GetName() << std::endl;
		}

		std::cout << "Choose fighter 1 : ";
		std::cin >> input;

	} while (input <0 || input > NUMBER_OF_MONSTERS);

	input -= 1;

	Monster fightingMonster1 = allMonsters[input];

	do
	{
		std::cout << "Who is our second fighter ?" << std::endl;
		for (int i = 0; i < NUMBER_OF_MONSTERS; ++i)
		{
			std::cout << i + 1 << " : " << allMonsters[i].GetName() << std::endl;
		}

		std::cout << "Choose fighter 2 : ";
		std::cin >> input;

	} while (input <0 || input > NUMBER_OF_MONSTERS || fightingMonster1.GetRace() == allMonsters[input - 1].GetRace());


	input -= 1;

	Monster fightingMonster2 = allMonsters[input];

	system("cls");

	for (int i = 3; i > 0; --i)
	{
		std::cout << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	std::cout << "FIGHT!!!" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));


	Monster fighters[2] = { fightingMonster1,fightingMonster2 };

	if (fightingMonster1.GetSpeed() < fightingMonster2.GetSpeed())
	{
		fighters[0] = fightingMonster2;
		fighters[1] = fightingMonster1;
	}

	int roundNumber = 1;
	std::string roundText;

	do
	{
		system("cls");

		roundText = "ROUND " + std::to_string(roundNumber);

		for (auto& c : roundText)
		{
			std::cout << c;
			std::this_thread::sleep_for(std::chrono::milliseconds(2000/roundText.size()));
		}
		std::cout << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		for (auto& monster : fighters)
		{
			monster.DecreaseParyRoundLeft();
		}

		srand((unsigned)time(NULL));
		int actionToPerform = rand() % 3;

		int damageHealth;


		int fighter1Action = actionToPerform;

		switch (actionToPerform)
		{
			//Attack
		case 0:
			damageHealth = fighters[1].GetHealthPoint() - fighters[0].Attack(fighters[1].GetParyDefensePoint());
			fighters[1].SetHealthPoint(damageHealth);
			std::cout << fighters[0].GetName() << " IS ATTACKING. HE DEALT AN AMAZING AMOUNT OF DAMAGE !" << std::endl;
			std::cout << fighters[1].GetName() << " LOST AN IMPRESSIVE " << std::to_string(fighters[0].Attack(fighters[1].GetParyDefensePoint())) << " HP" << std::endl;
			break;
			//Heal
		case 1:
			fighters[0].Heal();
			std::cout << fighters[0].GetName() << " IS HEALING HIMSELF ! (isn't that kinda of cheating?)" << std::endl;
			std::cout << fighters[0].GetName() << " NOW HAS " << std::to_string(fighters[0].GetHealthPoint()) << " HP" << std::endl;
			break;
			//Pary
		case 2:
			fighters[0].Pary();
			std::cout << fighters[0].GetName() << " IS PARYING !! " << std::endl;
			std::cout << fighters[0].GetName() << " DEFENSE IS NOW  "<< std::to_string(fighters[0].GetParyDefensePoint()) << " FOR THE NEXT 2 ROUNDS" << std::endl;
			break;
		default:
			std::cout << "Wait, HOW ARE YOU HERE ????";
			break;
		}

		//Monster 2 turn
		actionToPerform = rand() % 3;
		int fighter2Action = actionToPerform;

		if (fighters[1].GetHealthPoint() > 0)
		{
			switch (actionToPerform)
			{
				//Attack
			case 0:
				damageHealth = fighters[0].GetHealthPoint() - fighters[1].Attack(fighters[0].GetParyDefensePoint());
				fighters[0].SetHealthPoint(damageHealth);
				std::cout << fighters[1].GetName() << " IS ATTACKING. HE DEALT AN AMAZING AMOUNT OF DAMAGE !" << std::endl;
				std::cout << fighters[0].GetName() << " LOST AN IMPRESSIVE " << std::to_string(fighters[1].Attack(fighters[0].GetParyDefensePoint())) << " HP" << std::endl;
				break;
				//Heal
			case 1:
				fighters[1].Heal();
				std::cout << fighters[1].GetName() << " IS HEALING HIMSELF ! (isn't that kinda of cheating?)" << std::endl;
				std::cout << fighters[1].GetName() << " NOW HAS " << std::to_string(fighters[1].GetHealthPoint()) << " HP" << std::endl;
				break;
				//Pary
			case 2:
				fighters[1].Pary();
				std::cout << fighters[1].GetName() << " IS PARYING !! " << std::endl;
				std::cout << fighters[1].GetName() << " DEFENSE IS NOW  " << std::to_string(fighters[1].GetParyDefensePoint()) << " FOR THE NEXT 2 ROUNDS" << std::endl;
				break;
			default:
				std::cout << "Wait, HOW ARE YOU HERE ????";
				break;
			}
		}

		std::cout << "\nEND OF ROUND\n";
		for (Monster& monster : fighters)
		{
			std::cout << monster.GetName() << " Has " << monster.GetHealthPoint() << " HP" << std::endl;
			if (monster.GetParyRoundLeft() >0)
			{
				std::cout << monster.GetName() << " Is parying for the next " << monster.GetParyRoundLeft() << " rounds" << std::endl;
			}
		}

		std::cout << "PRESS A KEY TO CONTINUE" << std::endl;

		//random to decide which actions is made
		//perform monster 1 action
		//(and so, apply consequences)
		//new random
		//perform monster 2 action
		//(and so, apply consequences)
		//Display round results
		//continue to next round (little animation for the "Round X"?)

		roundNumber++;

		char confirm;
		std::cin >> confirm;

		

	} while (fighters[0].GetHealthPoint() > 0 && fighters[1].GetHealthPoint() > 0);

	system("cls");

	if (fighters[0].GetHealthPoint() < 0)
	{
		std::cout << fighters[0].GetName() << " IS DEAD !! WHAT A LOOSER" << std::endl;
		std::cout << fighters[1].GetName() << " IS THE WINNER !!!!";
	}
	else
	{
		std::cout << fighters[1].GetName() << " IS DEAD !! WHAT A LOOSER" << std::endl;
		std::cout << fighters[0].GetName() << " IS THE WINNER !!!!";
	}

	return 0;
}
