#include <iostream>
#include <cmath>
char chosenClass = 0;
char choose = 0;
bool pass = false;
bool passFight = false;
bool death;
static void ClearScreen()
{
	for (size_t i = 0; i < 57; i++)
	{
		std::cout << std::endl;
	}
}
class enemy
{
public:
	int turn;
	int HP;
	int block;
	int damage;
};
class BaseClass
{
public:
	bool storyBlock;
	bool inBlock;
	int blockPower;
	int level;
	int HP;
	int attackDamage;
	int block;
	virtual void LevelUp() = 0;
	virtual void AttackEnemy(enemy &target) = 0;
	virtual void turnOfFight(enemy &target) = 0;
	void EndOfBlock()
	{
		if (inBlock)
		{
			block -= blockPower;
			inBlock = false;
			storyBlock = false;
		}
	}
	void BlockEnemy(bool I = true)
	{
		ClearScreen();
		block += blockPower;
		inBlock = true;
		if (chosenClass == 'm')
			std::cout << "You cast Magic Shield." << std::endl << std::endl;
		else if (chosenClass == 'a')
			std::cout << "You dash to side." << std::endl << std::endl;
		else
			std::cout << "You raise your shield." << std::endl << std::endl;
		if (I == true)
			storyBlock = true;
	}
};
//Adam's Edit
static void WrongLetter()
{
	std::cout << "Wrong letter, try again." << std::endl;
}
static void DefaultEnemyOffense(int enemyDamage, BaseClass &player)
{
	if (enemyDamage > player.block)
	{
		player.HP -= (enemyDamage - player.block);
		std::cout << "You got hit by it." << std::endl << std::endl;
	}
	else if (chosenClass == 'a')
	{
		std::cout << "You dodged it." << std::endl << std::endl;
	}
	else
	{
		std::cout << "You blocked it completely." << std::endl << std::endl;
	}
}

class You : public enemy
{
public:
	You()
	{
			turn = 0;
			block = 5;
			HP = 30;
			damage = 4;
		std::cout << "You go to the top of mountain...";
		std::cin.get();
		ClearScreen();
		std::cout << "and you see a chalet. Someone is running in it.";
		std::cin.get();
		ClearScreen();
		if (chosenClass == 'a')
		{
			std::cout << "Some assassin opens the door and dashes towards you.";
			std::cin.get();
		}
		else if (chosenClass == 'k')
		{
			std::cout << "Some knight opens the door and runs towards you.";
			std::cin.get();
		}
		else
		{
			std::cout << "Some mage opens the door and starts casting a spell.";
			std::cin.get();
		}
		ClearScreen();
	}
	void dead()
	{
		std::cout << "You kill him.";
		std::cin.get();
		std::cin.get();
		ClearScreen();
		std::cout << "Then you go rest and look down to the beautiful magic nature and the golem slowly gets back to his position.";
		std::cin.get();
		ClearScreen();
		std::cout << "You see the forest...";
		std::cin.get();
		ClearScreen();
		std::cout << "and the golem slowly getting back to his position.";
		std::cin.get();
		ClearScreen();
		std::cout << "You go to chalet and treat it like your own house.";
		std::cin.get();
		ClearScreen();
		std::cout << "About two weeks later, some goblin steals the gilded armor.";
		std::cin.get();
		ClearScreen();
		std::cout << "But you don't care, because you found your home.";
		std::cin.get();
		ClearScreen();
		std::cout << "A few weeks later, you hear someone.";
		std::cin.get();
		ClearScreen();
		std::cout << "he goes towards your house, look through the window and you see...";
		std::cin.get();
		ClearScreen();
		if (chosenClass == 'a')
		{
			std::cout << "an assassin covered in blood!";
			std::cin.get();
		}
		else if (chosenClass == 'k')
		{
			std::cout << "a knight who is heavily armed!";
			std::cin.get();
		}
		else
		{
			std::cout << "a very powerful mage!";
			std::cin.get();
		}
		ClearScreen();
		std::cout << "You are scared of losing your home...";
		std::cin.get();
		ClearScreen();
		std::cout << "so you run out of your house and...";
		std::cin.get();
		ClearScreen();
		if (chosenClass == 'a')
		{
			std::cout << "dash towards him and slash him three times.";
			std::cin.get();
		}
		else if (chosenClass == 'k')
		{
			std::cout << "run towards him and attack him three times.";
			std::cin.get();
		}
		else
		{
			std::cout << "start casting spell that you have learned. It's an explosive laser; you do it three times.";
			std::cin.get();
		}
		ClearScreen();
		std::cout << "Then you realize it you,so you drop your weapon...";
		std::cin.get();
		ClearScreen();
		std::cout << "and wait for death." << std::endl << std::endl << std::endl;
	}
	void SecretEnd()
	{
		std::cout << "He asks why won't you kill him.";
		std::cin.get();
		std::cin.get();
		ClearScreen();
		std::cout << "\"You know that you are me.\"";
		std::cin.get();
		ClearScreen();
		std::cout << "\"You know that this is an endless loop.\"";
		std::cin.get();
		ClearScreen();
		std::cout << "\"Now we can break the loop and save more of us.\"";
		std::cin.get();
		ClearScreen();
		std::cout << "\"A goblin will be here in two weeks.\"";
		std::cin.get();
		ClearScreen();
		std::cout << "\"We will go with him and go back to where we came from...\"";
		std::cin.get();
		ClearScreen();
		std::cout << "\"and try stop this loop for ever.\"" << std::endl << std::endl << std::endl;
	}
	~You()
	{
		std::cout << "Thanks for playing the game." << std::endl << "I must thank to: " << std::endl << "playtesters:                Jiri Nemec" << std::endl << "                            Tades Letocha" << std::endl << "Quality controller:                    Adam Janulik" << std::endl;
		std::cin.get();
		std::cin.get();
	}
};
class golem : public enemy
{
public:
	golem()
	{
		turn = 0;
		HP = 22;
		block = 5;
		damage = 7;
		std::cout << "You go past the forest and up to the mountains. The road is not too steep...";
		std::cin.get();
		ClearScreen();
		std::cout << "and next to you there are strange shaped rocks";
		std::cin.get();
		ClearScreen();
		std::cout << "and suddenly they start moving. You know it's a golem.";
		std::cin.get();
		ClearScreen();
		std::cout << "He is built out of those rocks, that's why you didn't see him earlier.";
		std::cin.get();
		ClearScreen();
	}
	void dead()
	{
		std::cout << "You kill the golem, go further up and you see another one..." << std::endl;
		std::cin.get();
	}
};
class element : public enemy
{
public:
	element()
	{
		turn = 0;
		HP = 25;
		block = 4;
		damage = 9;
		std::cout << "But this one is a lot slimmer than the previous one.";
		std::cin.get();
		ClearScreen();
		std::cout << "He has gaps between the stones and you can see some magic flowing between those gaps.";
		std::cin.get();
		ClearScreen();
		std::cout << "He is extremely fast.";
		std::cin.get();
		ClearScreen();
	}
};
class goblin : public enemy
{
public:
	goblin()
	{
		turn = 0;
		HP = 13;
		block = 3;
		damage = 6;
		std::cout << "You are in a forest and see strange trees. Each tree has runes carved into it and the leaves rise up into the clouds instead of falling down.";
		std::cin.get();
		ClearScreen();
		std::cout << "You don't care, because you have been on the road for two weeks and you ran out of food a week ago. You feel tired.";
		std::cin.get();
		ClearScreen();
		std::cout << "Suddenly, a goblin starts running at you out of nowhere. He has armour made of iron and the edges of the plates on his armour are gilded...";
		std::cin.get();
		ClearScreen();
		std::cout << "and ";
	}
	void dead(BaseClass &player)
	{
		std::cout << "He died. You notice he had food on him, so you take his food and rest.";
		std::cin.get();
		std::cin.get();
		ClearScreen();
		if (chosenClass == 'k')
		{
			player.blockPower++;
			std::cout << "Then you take his armor, because it's better than yours." << std::endl;
			std::cin.get();
			ClearScreen();
		}
		else
		{
			if (chosenClass == 'a')
				player.blockPower--;
			std::cout << "Then you take his armor, because you think it will be worth something." << std::endl;
			std::cin.get();
			ClearScreen();
		}
		std::cout << "And then you move on." << std::endl;
		std::cin.get();
		ClearScreen();
	}
};
class mage : public BaseClass
{
public:
	void Display()
	{
		std::cout << "You are level " << level << std::endl << "You have " << HP << " HP" << std::endl << "Magic Shield Power: " << blockPower << std::endl << "Your magic power: " << attackDamage << std::endl;
		if (level >= 1)
		{
			std::cout << "Your spell: " << std::endl << "Magic Missile" << std::endl;
		}
		if (level >= 2)
		{
			std::cout << "Fireball" << std::endl;
		}
		if (level >= 3)
		{
			std::cout << "Frozen Bullets" << std::endl;
		}
		std::cout << std::endl << std::endl;
		std::cin.get();
		std::cin.get();
		ClearScreen();
	}
	mage()
	{
		inBlock = false;
		level = 1;
		block = 1;
		blockPower = 4;
		attackDamage = 6;
		HP = 20;
		Display();
	}
	void LevelUp() override
	{
		level += 1;
		std::cout << "You have leveled up!" << std::endl << "Choose what you want to upgrade. You can do so 3 times." << std::endl << "Magic power = m" << std::endl << "Magic Shield power = s" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			while (!pass)
			{
				std::cin >> choose;
				std::cout << std::endl;
				if (choose == 'm')
				{
					attackDamage++;
					std::cout << "Attack damage upgraded!" << std::endl;
					pass = true;
				}
				else if (choose == 's')
				{
					blockPower++;
					std::cout << "Block power upgraded!" << std::endl;
					pass = true;
				}
				else
				{
					WrongLetter();
				}

			}
			pass = false;
		}
		Display();
	}
	void AttackEnemy(enemy &target) override
	{
		ClearScreen();
		if (level <= 1)
		{
			if (attackDamage > target.block)
				target.HP -= (attackDamage - target.block);
			std::cout << "You cast Magic Missile." << std::endl;
		}
		else
		{
			std::cout << "Choose what spell do you want to use." << std::endl;
			if (level >= 2)
			{
				std::cout << "Magic Missile = m" << std::endl << "Fireball = f" << std::endl;
			}
			if (level >= 3)
			{
				std::cout << "Frozen Bullets = b" << std::endl;
			}
			while (!pass)
			{
				std::cin >> choose;
				if (choose == 'm')
				{
					if (attackDamage > target.block)
						target.HP -= (attackDamage - target.block);
					std::cout << "You cast Magic Missile." << std::endl;
					pass = true;
				}
				else if (choose == 'f')
				{
					if (1.2f * attackDamage > target.block - 3)
						target.HP -= round(1.2f * attackDamage - (target.block - 3));
					std::cout << "You cast Fireball." << std::endl;
					pass = true;
				}
				else if (choose == 'b')
				{
					if (level >= 3)
					{
						if (1.5f * attackDamage > target.block)
							target.HP -= round(1.5f * attackDamage) - target.block;
						std::cout << "You cast Frozen Bullets." << std::endl;
						pass = true;
					}
					else
					{
						WrongLetter();
					}
				}
				else
				{
					WrongLetter();
				}

			}
			pass = false;
		}
	}
	void turnOfFight(enemy &target) override
	{
		EndOfBlock();
		std::cout << "So, what are you going to do?" << std::endl << "Cast spell = s" << std::endl << "Raise your magic sheild = m" << std::endl;
		while (!pass)
		{
			std::cin >> choose;
			if (choose == 's')
			{
				AttackEnemy(target);
				pass = true;
			}
			else if (choose == 'm')
			{
				BlockEnemy();
				pass = true;
			}
			else
			{
				WrongLetter();
			}
		}
		pass = false;
	}
};
class assassin : public BaseClass
{
public:
	void Display()
	{
		std::cout << "You are level " << level << std::endl << "You have " << HP << " HP" << std::endl << "Dash speed: " << blockPower << std::endl << "Your damage: " << attackDamage << std::endl << std::endl;
		std::cin.get();
		std::cin.get();
		ClearScreen();
	}
	assassin()
	{
		inBlock = false;
		level = 1;
		block = 0;
		blockPower = 5;
		attackDamage = 6;
		HP = 20;
		Display();
	}
	void LevelUp() override
	{
		level += 1;
		std::cout << "You have leveled up!" << std::endl << "Choose what you want to upgrade. You can do so 3 times." << std::endl << "Speed of dash = s " << std::endl << "Damage = d" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			while (!pass)
			{
				std::cin >> choose;
				if (choose == 'd')
				{
					attackDamage ++;
					std::cout << "Attack damage upgraded!" << std::endl;
					pass = true;
				}
				else if (choose == 's')
				{
					blockPower ++;
					std::cout << "Dash speed upgraded!" << std::endl;
					pass = true;
				}
				else
				{
					WrongLetter();
				}
			}
			pass = false;
		}
		Display();
	}
	void AttackEnemy(enemy &target) override
	{
		ClearScreen();
		if (level <= 1)
		{
			if (attackDamage > target.block)
				target.HP -= (attackDamage - target.block);
			std::cout << "You have slashed the enemy." << std::endl << std::endl;
		}
		else if (level <= 2)
		{
			if (round(1.2f * attackDamage) > target.block)
				target.HP -= round(1.2f * attackDamage - target.block);
			std::cout << "You have slashed the enemy from one side and the other." << std::endl << std::endl;
		}
		else if (level >= 3)
		{
			if (round(1.5f * attackDamage) > target.block)
				target.HP -= round(1.5 * attackDamage - target.block);
			std::cout << "You've dashed past the enemy and slashed them from side to side." << std::endl << std::endl;
		}
	}
	void turnOfFight(enemy &target) override
	{
		EndOfBlock();
		std::cout << "So, what are you going to do?" << std::endl << "Try to hit enemy = h" << std::endl << "Dash to the side  = d" << std::endl;
		while (!pass)
		{
			std::cin >> choose;
			if (choose == 'h')
			{
				AttackEnemy(target);
				pass = true;
			}
			else if (choose == 'd')
			{
				BlockEnemy();
				pass = true;
			}
			else
			{
				WrongLetter();
			}
		}
		pass = false;
	}
};
class knight : public BaseClass
{
public:
	void Display()
	{
		std::cout << "You are level " << level << std::endl << "You have " << HP << " HP" << std::endl << "Shield grip: " << blockPower << std::endl << "Your damage: " << attackDamage << std::endl << std::endl;
		std::cin.get();
		std::cin.get();
		ClearScreen();
	}
	knight()
	{
		inBlock = false;
		level = 1;
		block = 3;
		blockPower = 2;
		attackDamage = 5;
		HP = 20;
		Display();
	}
	void LevelUp() override
	{
		level += 1;
		std::cout << "You have leveled up!" << std::endl << "Choose what you want to upgrade. You can do so 3 times." << std::endl << "Shield grip = h" << std::endl << "Sword sharpness = s" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			while (!pass)
			{
				std::cin >> choose;
				if (choose == 's')
				{
					attackDamage ++;
					std::cout << "Attack damage upgraded!" << std::endl;
					pass = true;
				}
				else if (choose == 'h')
				{
					blockPower ++;
					std::cout << "Shield grip upgraded!" << std::endl;
					pass = true;
				}
				else
				{
					WrongLetter();
				}
			}
			pass = false;
		}
		Display();
	}
	void AttackEnemy(enemy &target) override
	{
		ClearScreen();
		if (level <= 1)
		{
			if (attackDamage > target.block)
				target.HP -= (attackDamage - target.block);
			std::cout << "You swing with your sword." << std::endl;
		}
		else
		{
			std::cout << "Choose your attack." << std::endl;
			if (level >= 2)
			{
				std::cout << "Sword swing = s" << std::endl << "Make a feint with the sword = f" << std::endl;
			}
			if (level >= 3)
			{
				std::cout << "Attack and block = b" << std::endl;
			}
			while (!pass)
			{
				std::cin >> choose;
				if (choose == 's')
				{
					if (attackDamage > target.block)
						target.HP -=(attackDamage - target.block);
					std::cout << "You swing with your sword." << std::endl;
					pass = true;
				}
				else if (choose == 'f')
				{
					if (round(1.2f * attackDamage) > target.block - 3)
						target.HP -= round(1.2f * attackDamage - (target.block - 3));
					std::cout << "You do a feint." << std::endl;
					pass = true;
				}
				else if (choose == 'b')
				{
					if (level >= 3)
					{
						if (attackDamage > target.block)
							target.HP -= (attackDamage - target.block);
						std::cout << "You do an attack and block." << std::endl;
						BlockEnemy(false);
						pass = true;
					}
					else
					{
						WrongLetter();
					}
				}
				else
				{
					WrongLetter();
				}
			}
			pass = false;
		}
	}
	void turnOfFight(enemy &target) override
	{
		EndOfBlock();
		std::cout << "So, what are you going to do?" << std::endl << "Try to hit enemy = h" << std::endl << "Raise your sheild = r" << std::endl;
		while (!pass)
		{
			std::cin >> choose;
			if (choose == 'h')
			{
				AttackEnemy(target);
				pass = true;
			}
			else if (choose == 'r')
			{
				BlockEnemy();
				pass = true;
			}
			else
			{
				WrongLetter();
			}
		}
		pass = false;
	}
};
static bool CampaignGoblin(BaseClass &player)
{
	goblin goblin;
	while (!passFight)
	{
		if (goblin.HP <= 0)
		{
			goblin.dead(player);
			player.LevelUp();
			return true;
		}
		if ((goblin.turn % 2) == 1)
		{
			if (goblin.damage > player.block)
			{
				player.HP -= (goblin.damage - player.block);
				std::cout << "He hit you." << std::endl << std::endl;
			}
			else if (chosenClass == 'a')
			{
				std::cout << "You dodged it." << std::endl << std::endl;
			}
			else
			{
				std::cout << "You blocked it completely." << std::endl << std::endl;
			}
		}
		else
			std::cout << "The goblin is preparing to swing his short sword." << std::endl << std::endl;
		goblin.turn++;
		if (player.HP <= 0)
		{
			std::cout << std::endl << std::endl << std::endl << "Game Over";
			std::cin.get();
			std::cin.get();
			return false;
		}
		player.turnOfFight(goblin);
	}
	return true;
}
static bool CampaignGolem(BaseClass &player)
{
	golem golem;
	while (!passFight)
	{
		if (golem.HP <= 0)
		{
			golem.dead();
			player.LevelUp();
			return true;
		}
		if (golem.turn == 0)
		{
			std::cout << "He stares you down." << std::endl << std::endl;
		}
		else if (golem.turn == 1)
		{
			std::cout << "he stretches out both arms and prepeares for a strike." << std::endl << std::endl;
		}
		else if (golem.turn == 2)
		{
			std::cout << "He smashes the ground." << std::endl << std::endl;
			DefaultEnemyOffense(golem.damage, player);
		}
		else
		{
			std::cout << "Out of nowhere, he struck you from the side with his other hand." << std::endl << std::endl;
			DefaultEnemyOffense(golem.damage, player);
			golem.turn = -1;
		}
		golem.turn++;
		if (player.HP <= 0)
		{
			std::cout << std::endl << std::endl << std::endl << "Game Over";
			std::cin.get();
			std::cin.get();
			return false;
		}
		player.turnOfFight(golem);
	}
	return true;
}
static bool CampaignElemental(BaseClass &player)
{
	element element;
	while (!passFight)
	{
		if (element.HP <= 0)
		{
			player.LevelUp();
			return true;
		}
		if (element.turn == 0)
		{
			std::cout << "He dashes towards you." << std::endl << std::endl;
		}
		else if (element.turn == 1)
		{
			std::cout << "He bumps into you." << std::endl << std::endl;
			DefaultEnemyOffense(element.damage, player);
		}
		else if (element.turn == 2)
		{
			std::cout << "He dashes behind you and hits you in the back." << std::endl << std::endl;
			DefaultEnemyOffense(element.damage, player);
		}
		else
		{
			std::cout << "He dashes away and his magic hits you." << std::endl << std::endl;
			DefaultEnemyOffense(element.damage, player);
			element.turn = -1;
		}
		element.turn++;
		if (player.HP <= 0)
		{
			std::cout << std::endl << std::endl << std::endl << "Game Over";
			std::cin.get();
			std::cin.get();
			return false;
		}
		player.turnOfFight(element);
	}
	return true;
}
static bool InTheEnd(BaseClass &player)
{
	int spare = 0;
	You you;
	while (!passFight)
	{
		if (you.HP <= 0)
		{
			you.dead();
			return true;
		}
		else if (spare >= 5)
		{
			you.SecretEnd();
			return true;
		}
		if (you.turn <= 0)
		{
			if (you.damage > player.block)
			{
				player.HP -= (you.damage - player.block);
				if (chosenClass == 'm')
					std::cout << "The spell hit you." << std::endl;
				else
					std::cout << "The slash hit you." << std::endl;
			}
			else if (chosenClass == 'a')
				std::cout << "You dodged it." << std::endl;
			else
				std::cout << "You blocked it completely." << std::endl;
			if (chosenClass == 'm')
			{
				std::cout << "It's a strange spell, because you can't see anything and then an explosion happened." << std::endl;
				std::cout << "He cast another one." << std::endl;
			}
		}
		else if (you.turn <= 2)
		{
			if (chosenClass == 'm')
				std::cout << "The cast spell." << std::endl;
			else
				std::cout << "he slash you." << std::endl;
			if (you.damage > player.block)
			{
				player.HP -= (you.damage - player.block);
				if (chosenClass == 'm')
					std::cout << "The spell hit you." << std::endl;
				else
					std::cout << "hit you." << std::endl;
			}
			else if (chosenClass == 'a')
				std::cout << "You dodged it." << std::endl;
			else
				std::cout << "You blocked it completely." << std::endl;
		}
		else if (you.turn == 3)
		{
			std::cout << "He dropped his weapon." << std::endl << std::endl;
		}
		else
		{
			std::cout << "He stared you down." << std::endl;
			if (player.storyBlock)
				spare++;
		}
		you.turn++;
		if (player.HP <= 0)
		{
			std::cout << std::endl << std::endl << std::endl << "Game Over";
			std::cin.get();
			std::cin.get();
			return false;
		}
		player.turnOfFight(you);
	}
	return true;
}

void StoryStructure(BaseClass &player)
{
	passFight = CampaignGoblin(player);

	if (!passFight) return;
	
	passFight = false;
	passFight = CampaignGolem(player);
	
	if (passFight == false) return;
	
	passFight = false;
	passFight = CampaignElemental(player);
	
	if (passFight == false) return;
	
	passFight = false;
	passFight = InTheEnd(player);
}

int main()
{
	std::cout << "Choose class:" << std::endl << "Mage = m" << std::endl << "Knight = k" << std::endl << "Assassin = a" << std::endl << "choose :";
	while (!pass)
	{
		std::cin >> chosenClass;
		std::cout << std::endl;
		if (chosenClass == 'm' || chosenClass == 'k' || chosenClass == 'a')
		{
			pass = true;
		}
		else
		{
			WrongLetter();
		}
	}
	pass = false;
	if (chosenClass == 'm')
	{
		mage playerMage;
		StoryStructure(playerMage);
	}
	else if (chosenClass == 'k')
	{
		knight playerKnight;
		StoryStructure(playerKnight);
	}
	else if (chosenClass == 'a')
	{
		assassin playerAssassin;
		StoryStructure(playerAssassin);
	}
}