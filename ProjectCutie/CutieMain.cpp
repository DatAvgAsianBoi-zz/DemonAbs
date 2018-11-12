// Cutie Hack 2018
// by Kyle, Matthew, Ryan, and David

#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

// Display stats functions
void stats(int h, int m, int s, int i, int d) {
	cout << endl;
	cout << "Health: " << h << endl;
	cout << "Money: " << m << endl;
	cout << "Strength: " << s << endl;
	cout << "Intelligence: " << i << endl;
	cout << "Dexterity: " << d << endl << endl;
}

// Go home scene 7 (end of the day)
void scene7(int *h, int *m, int *s, int *i, int *d, string N) {
	cout << "\nYou realize how fast time has passed, so you head home as the sun begins to set." << endl;
	cout << "Mother: Did you buy the milk " << N << "?" << endl;
	cout << "You: Well-" << endl;
	cout << "Everything begins to distort, and your mother begins to fade away." << endl;
	cout << "As your vision clears, the figure of your used to be mother turned into a man with horns and glaring teeth." << endl;
	cout << "Demon Lord: Hello " << N << ". I've been expecting you, but not so soon." << endl;
	cout << "You begin to sweat, but before you could make a move the demon lord rushes at you." << endl;

	if (*d < 10) {
		cout << "Your dexterity was not high enough to dodge the initial attack." << endl;
		cout << "-1 Health." << endl;
		*h -= 1;
	}
	else {
		cout << "Your reflexes allow you to evade the lunge from the Demon Lord." << endl;
		cout << "Demon Lord: You're one quick mouse aren't you?" << endl;
	}

	string choice;
	cout << "Press any key and hit enter to continue..." << endl;
	cin >> choice;
}

// Scene 5
// Go buy a sword
void scene5(int *h, int *m, int *s, int *i, int *d, string N) {
	cout << "You are in scene 5." << endl << endl;
	cout << "You go to the armory with the phat amount of money you have in your pocket right now." << endl;
	// User buys strength depending on the amount of gold they have
	if (*m == 100) {
		cout << "You have so much money, you buy the best sword there is." << endl;
		cout << "You gain +9 strength." << endl;
		*s += 9;
	}
	else if (*m < 90) {
		cout << "You have some money to buy a decent sword." << endl;
		cout << "You gain +5 strength." << endl;
		*s += 5;
	}
	// In the end, they have no more money
	cout << "You have no more money." << endl;
	*m = 0;
	
	// Opportunity for user to do situps
	cout << "Armorer: Hey kid, how many situps can you do?" << endl;
	cout << "Depending on the amount of situps you do, you can gain more strength." << endl;
	cout << "Input how many situps you did: " << endl;
	// User inputs how many situps they did
	int choice;
	cin >> choice;

	if (choice < 3) {
		*s += 2;
		cout << "Armorer: Hahaha, you're weak! But I admire your effort." << endl;
		cout << "You gained +2 strength." << endl;
	}
	else if (choice < 10) {
		*s += 7;
		cout << "Armorer: Hmm, fairly strong." << endl;
		cout << "You gained +7 strength." << endl;
	}
	else {
		*s += 10;
		cout << "Armorer: Wow, you're strong kid." << endl;
		cout << "You gained +10 strength." << endl;
	}

	string end;
	cout << "Press any key and hit enter to continue..." << endl;
	cin >> end;

	// Go to scene 7
	scene7(h, m, s, i, d, N);
}

// Scene 6
// Go buy a book
void scene6(int *h, int *m, int *s, int *i, int *d, string N) {
	cout << "You are in scene 6." << endl << endl;
	cout << "You walk into the bookstore and see many different things." << endl;
	cout << "You have enough money to buy a various amount of books." << endl;
	*m = 0;
	cout << "You gain some intelligence." << endl;

	// Random Number Generator for intelligence
	// Decides how much intelligence is given to the user
	int a = rand() % 3;
	if (a == 1) {
		*i += 3;
		cout << "You gain +3 intelligence." << endl;
	}
	else if (a == 2) {
		*i += 6;
		cout << "You gain +6 intelligence." << endl;
	}
	else {
		*i += 9;
		cout << "You gain +9 intelligence." << endl;
	}

	// Intelligence stat booster
	cout << "You learn secret tips and tricks." << endl;
	cout << "You gain more stats in your other skills." << endl;
	*s = *s * *i - 2;
	*d = *d * *i;

	string choice;
	cout << "Press any key and hit enter to continue..." << endl;
	cin >> choice;

	// Go to scene 7
	scene7(h,m,s,i,d,N);
}

// Scene 4
// Go to store
void scene4(int *h, int *m, int *s, int *i, int *d, string N) {
	cout << "You are in scene 4." << endl;
	cout << "You go to the store and look for the milk like the good child you are." << endl;
	// Random Number Generator
	// Decides how much dexterity is given to the user
	int a = rand() % 91;
	if (a < 30)
	{
		// Dexterity increased by 3
		*d += 3;

		cout << "You trip on a wet puddle in the store." << endl;
		cout << "You gained +3 dexterity." << endl;
		
	}
	else if (a >= 30 && a < 60)
	{
		// Dexterity increased by 5
		*d += 5;
		
		cout << "You manage to dodge a couple of children running around." << endl;
		cout << "You gained +5 dexterity." << endl;
	}
	else {
		// Dexterity increased by 9
		*d += 9;

		cout << "You suddenly see everything in the store and manage to find the most efficient path to the milk section." << endl;
		cout << "You gained +9 dexterity." << endl;
	}

	// Still in scene 4 right now
	// Gives the user choices
	// Scene 5: Go buy a sword
	// Scene 6: Go buy a book
	// Scene 7: Go home (ends the day)
	cout << "You buy milk and have time to spare. What else do you want to do?" << endl;
	*m -= 20;

	// User chooses their options (from scene 4)
	bool verify = true;
	int choice = 0;

	while (verify) {
		// Displays choices
		cout << "1. Go buy a sword (increase strength) \n2. Go buy a book (increase intelligence)\n3. Go home \n4. Check stats" << endl << endl;
		cin >> choice;

		if (choice == 1) {
			// Go to store: scene 5
			// Buy a sword
			scene5(h, m, s, i, d, N);
			verify = false;
		}
		else if (choice == 2) {
			// Go buy a sword: scene 6
			scene6(h, m, s, i, d, N);
			verify = false;
		}
		else if (choice == 3) {
			// Go home: scene 7
			scene7(h, m, s, i, d, N);
			verify = false;
		}
		else if (choice == 4) {
			stats(*h, *m, *s, *i, *d);
		}
		else {
			cout << "I'm sorry, I don't recognize that choice. Please input it again. \n \n";
		}

	}
	
}

// Scene 2 function
// Scene 2 goes to scene 4 and 5
// Goes downstairs
void sceneB(int *h, int *m, int *s, int *i, int *d, string N) {
	int choice;

	cout << endl << "Mother: HI " << N << ". GLAD TO SEE YOU'RE AWAKE." << endl;
	cout << "Mother: HAVE SOME MONEY" << endl;
	cout << "You have gained 100 coins." << endl;
	*m += 100;
	cout << "Mother: GO BUY SOME MILK >:(" << endl;
	cout << "You can either go to the store and listen to her or... use the money for personal use ;)" << endl << endl;
	// Go to store: scene 4
	// Go buy a sword: scene 5
	// Go buy a book: scene 6
	// User chooses their options
	bool verify = true;

	while (verify) {
		// Displays choices
		cout << "1. Go to store \n2. Go buy a sword (increase strength)\n3. Go buy a book (increase intelligence)\n4. Check stats" << endl;
		cin >> choice;

		if (choice == 1) {
			// Go to store: scene 4 / D
			scene4(h, m, s, i, d, N);
			verify = false;
		}
		else if (choice == 2) {
			// Go buy a sword: scene 5 / E
			scene5(h, m, s, i, d, N);
			verify = false;
		}
		else if (choice == 3) {
			// Go buy a book: scene 6 / F
			// Goes to that scene
			scene6(h, m, s, i, d, N);
			verify = false;
		}
		else if (choice == 4) {
			stats(*h, *m, *s, *i, *d);
		}
		else {
			cout << "I'm sorry, I don't recognize that choice. Please input it again. \n \n";
		}

	}

}

// Scene 3 function
// Premature death
void sceneC(int *h, bool *death) {
	cout << endl << "You died a silly death." << endl;
	*death = true;
	*h = 0;
}

int main() {

	// In the end I want to have an option where players can see their stats and go back
	// to the original scene.

	string name;
	string adjective;

	int choice;
	bool verify;
	bool badEnd = false;
	bool *bpoint = &badEnd;

	// Stats of the player
	int Health = 5;
	int Money = 0;
	int Strength = 1;
	int Intel = 1;
	int Dext = 1;

	// Declare pointers
	int *hpoint = &Health;
	int *mpoint = &Money;
	int *spoint = &Strength;
	int *ipoint = &Intel;
	int *dpoint = &Dext;

	// Random number generator
	srand(time(0));
	if (rand() % 2 == 1)
	{
		adjective = "beautiful";
	}
	else
	{
		adjective = "silly";
	}

	cout << "***DISCLAIMER: DO NOT TYPE IN A LETTER WHEN INPUTTING CHOICES. (to be fixed in the future) ***" << endl << endl;
	cout << "Welcome to the land of INSERT TITLE HERE. \n";
	cout << "NANI is your name?" << endl;
	cin >> name;

	// Outputs user's name and uses a random number to put in an adjective
	cout << endl << name << ", WHAT A " << adjective << " NAME! \n" << endl;

	// Introduces player to story
	cout << "Slay the demon lord. You are a peasant. It's dangerous to go alone, take this o' young'un. \n";
	cout << "";

	// Scene 1
	cout << "You wake up, mother is calling you.\n";
	cout << name << "!!! WAKE UP AND COME DOWN HERE RIGHT NOW. >:( \n";
	cout << "Do you go or not?\n" << endl;

	// User chooses first option
	verify = true;
	while (verify) {
		cout << "1. Go downstairs. \n";
		cout << "2. Stay in bed. \n";
		cout << "3. Check stats. \n";
		cin >> choice;

		if (choice == 1) {
			// Go downstairs choice (scene 2)
			verify = false;
		}
		else if (choice == 2) {
			// Stay in bed (scene 3)
			cout << "You decided to stay in bed, but realize this is a bad idea." << endl;
			cout << "Suddenly, you see a shadow. It gets bigger and bigger." << endl;
			cout << "It's your mother's voice." << endl;
			cout << "Then a cold hand covers your mouth and a knife is pressed against your throat." << endl;
			cout << "Demon: The demon lord sends his regards." << endl;
			cout << "As you fade away, you see your mother scream in horror as she drops her cake in despair." << endl;
			// Health is equal to zero. They dead.
			Health = 0;
			verify = false;
		}
		else if (choice == 3) {
			stats(Health, Money, Strength, Intel, Dext);
		}
		else if (choice != 1) {
			cout << "I'm sorry, I don't recognize that choice. Please input it again. \n \n";
		}

	}
	
	if (choice == 1) {
		// Scene 2
		cout << endl << "You are in Scene 2" << endl;
		sceneB(&Health, &Money, &Strength, &Intel, &Dext, name);
	}
	else if (choice == 2) {
		// Scene 3
		sceneC(&Health, &badEnd);
	}

	// Boss stats and variables
	int bHealth = 5;
	int bConfuse = 0;

	// Inside main function
	// Scene 8 where the magic happens
	// The boss battle
	// Introduction to fight
	cout << "You realize that you're going to die if you don't fight." << endl;
	cout << "Go get him kid." << endl;
	while (Health > 0 && bHealth > 0) {
		// Displays health before every action
		cout << "Your Health: " << Health << endl;
		cout << "Boss Health: " << bHealth << endl;

		// User chooses their move
		verify = true;
		while (verify) {
			// User moves
			cout << "What do you do?" << endl;
			cout << "1. Punch him" << endl;
			cout << "2. Hit him with some knowledge" << endl;
			cout << "3. Heal up" << endl;
			cout << "4. Check stats" << endl;

			cin >> choice;
			if (choice == 1) {
				// Punch him
				if (Strength > 5) {
					cout << "You deal 2 damage to his health." << endl;
					bHealth -= 2;
				}
				else {
					cout << "You deal 1 damage to his health." << endl;
					bHealth -= 1;
				}
				verify = false;
			}
			else if (choice == 2) {
				// Hit him with knowledge
				if (Intel > 8) {
					cout << "The demon lord gets confused!" << endl;
					cout << "He misses two turns." << endl;
					bConfuse = 2;
				}
				else if (Intel > 4) {
					cout << "The demon lord seems to be confused about one thing you said." << endl;
					cout << "He misses one turn." << endl;
					bConfuse = 1;
				}
				else {
					cout << "You spew nonsense, so the demon lord doesn't care." << endl;
				}
				verify = false;
			}
			else if (choice == 3) {
				// Heal
				// Random Number Generator for Health given back
				int a = rand() % 3;
				if (a == 1) {
					Health += 1;
					cout << "You manage to heal yourself." << endl;
					cout << "+1 Health" << endl;
				}
				else if (a == 2) {
					Health += 2;
					cout << "You heal yourself very well." << endl;
					cout << "+2 Health" << endl;
				}
				else {
					cout << "You fail to heal yourself. :(" << endl;
				}
				verify = false;
			}
			else if (choice == 4) {
				stats(Health, Money, Strength, Intel, Dext);
			}
			else if (choice != 1) {
				cout << "I'm sorry, I don't recognize that choice. Please input it again. \n \n";
			}
		}

		// Boss MOVE --- HIS TURN
		// Is the boss alive?
		// If the boss is alive, continue

		// RNG for the boss move
		if (bHealth > 0) {
			// Is the boss confused?
			// If the boss is not confused, continue
			if (bConfuse <= 0) {
				// RDG Hit Chance
				// RNG for boss hit chance
				int a = rand() % 4;
				if (a > 0) {
					// RNG for how much damage the boss deals to you
					// The boss hits the user
					// RNG How strong his attack is
					int a = rand() % 6;
					if (a == 5) {
						// 1/5 chance for boss to deal -2 damage
						cout << "The boss strikes you very strongly." << endl;
						cout << "-2 Health" << endl;
						Health -= 2;
					}
					else if (a > 2) {
						// 2/5 chance for boss to deal -1 damage
						cout << "The boss punches you." << endl;
						cout << "-1 Health" << endl;
						Health -= 1;
					}
					else {
						cout << "You manage to deflect his attack.";
					}
				}
				else {
					cout << "The boss misses you!" << endl;
				}
			}
			else {
				// If statement if the boss was hit with knowledge
				cout << "The boss is confused!" << endl;
			}
		}

		bConfuse -= 1;
	}

	// Ending / Conclusion
	if (bHealth <= 0) {
		cout << "Demon Lord: Impossible, a mere peasant has bested me?!?" << endl;
		cout << "Demon Lord: You won this time, but I will be back..." << endl;
		cout << "The Demon Lord unravels his wings and flies away into the night sky." << endl;
		cout << "Congratulations! You have won the game!" << endl;
		stats(Health, Money, Strength, Intel, Dext);
		
		return 0;
	}

	// Checks if it was a bad end
	if (badEnd) {
		cout << endl << "Game Over. You tried :(" << endl;
	}
	else {
		cout << endl << "Game Over." << endl;
	}

	//Game Over

	cout << "Thanks for playing!" << endl;
	cout << "End stats: " << endl;
	stats(Health, Money, Strength, Intel, Dext);
	cout << "";

	return 0;
}

