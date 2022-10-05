#include <iostream>
using namespace std;
#include <ctime>
//test
int main()
{
	int saldo = 1000; // här initieras samt deklareras de globala variablerna. 
	int satsning = 0;
	int samvinst = 0;
	int vinst = 0;
	bool omspel;
	while (omspel = true) // medans omspel som bool är true så loopas programmet. Detta avgörs i slutet av programmet med ett alternativ till användaren.
	{
		if (saldo < 100) // Om saldot är mindre än 100 (den minsta möjliga satsningen) så får man inte spela mer.
		{
			cout << "You do not have any money left to play for" << endl;
			return 0;
		}
		cout << "Your balance is " << (saldo) << "kr." << endl;
		cout << " How much do you want to bet, " << endl;
		cout << "100, 300 or 500 kr?" << endl; 
		cin >> satsning; // Här får användaren ange hur mycket de vill spela för 100, 300 eller 500. Samt se hur mycket deras saldo är.

		if (satsning != 100 && satsning != 300 && satsning != 500) // om satsningen är annat än de tre givna alternativ så stängs programmet av och de måste starta om för att spela.
		{
			cout << "Given amount not accepted, please try again" << endl;
			return 0;
		}
		if (saldo < satsning) // Om användaren försöker satsa mer än deras saldo så stängs programmet av och de får starta om.
		{
			cout << "You do not have enough money to bet that much" << endl;
			return 0;
		}
		if (satsning == 100 || satsning == 300 || satsning == 500) // om satsningen angiven är en av de tre tillåtna får de välja speltyp. Färg/nummer.
		{
			saldo = saldo - satsning;
			cout << "You have chosen to bet " << satsning << "kr. " << satsning << "kr " << "has been drawn from balance." << endl;
			cout << "Do you want to pick a color (red for uneven black for even) or a number? (1-36)" <<endl;

			string vägval1;
			cin >> vägval1;
			if (vägval1 == "color" || vägval1 == "Color") //Om färgvalet är färg så ber programmet de specifera vilken färg.
			{
				string färgval;
				cout << "Red or Black?" << endl;
				cin >> färgval;
				if (färgval == "red" || färgval == "Red" || färgval == "black" || färgval == "Black") //Om färgvalet är en av de tillåtna.
				{
					srand(time(0));
					int random = rand() % 36 + 1; // här slumpas numret fram.

					if (random == 1 || random == 3 || random == 5 || random == 7 || random == 9 || random == 11 || random == 13 || random == 15 || random == 17 || random == 19 || random == 21 || random == 23 || random == 25 || random == 27 || random == 29 || random == 31 || random == 33 || random == 35) // om det slumpade numret är udda
					{


						if (färgval == "red" || färgval == "Red") //om inmatade färgvalet var röd.
						{
							vinst = satsning * 2; // här bestäms vinsten.
							saldo = saldo + vinst; // här adderas vinsten till saldot.
							samvinst = saldo - 1000; // här visas den sammanlagda vinsten, vilket är saldot - 1000. alltså allt över startsumman.
							cout << "The number was " << random << " and the color was red." << endl; 
							cout << "You won " << vinst << "kr!" << endl; // här ges resultatet.
							cout << "Your balance is now " << saldo << "kr" << endl; // här ser användaren sitt saldo efter att ha vunnit.
							cout << "Your total winnings are " << samvinst << "kr" << endl; 
						}
						else if (färgval != "red" || färgval != "Red")  // om inmatade färgvalet inte var röd.
						{
							cout << "The number was " << random << " and the color was red." << endl;
							cout << "You lost" <<endl; // här ges resultat för förlust.
							cout << "Your balance is now " << saldo << endl; // här ser användaren sitt saldo efter att ha förlorat.

						}
					}

					else if (random == 2 || random == 4 || random == 6 || random == 8 || random == 10 || random == 12 || random == 14 || random == 16 || random == 18 || random == 20 || random == 22 || random == 24 || random == 26 || random == 28 || random == 30 || random == 32 || random == 34 || random == 36) // om det slumpade numret är jämnt
					{
						
						if (färgval == "black" || färgval == "Black") // om färgvalet var svart.
						{
							vinst = satsning * 2; 
							saldo = saldo + vinst;
							samvinst = saldo - 1000;
							cout << "You won " << vinst << " kr!" << endl;
							cout << "The number was " << random << " and the color was black" << endl;
							cout << "Your balance is now " << saldo << "kr" << endl;
							cout << "Your total winnings are " << samvinst << "kr" << endl;

						}
						else if (färgval != "black" || färgval != "Black") 
						{
							cout << "The number was " << random << " and the color was black. " << endl;
							cout << "You lost. " << endl;
							cout << "Your balance is now " << saldo << "kr" << endl; 

						}
					}
				}
			}
			if (vägval1 == "number" || vägval1 == "Number") // om speltypen är nummer.
			{
				int nummerval;
				cout << "Which number (1-36)?" << endl;
				cin >> nummerval;
				srand(time(0));
				int random2 = rand() % 36 + 1; //här slumpas nummret fram
				if (random2 == 1 || random2 == 3 || random2 == 5 || random2 == 7 || random2 == 9 || random2 == 11 || random2 == 13 || random2 == 15 || random2 == 17 || random2 == 19 || random2 == 21 || random2 == 23 || random2 == 25 || random2 == 27 || random2 == 29 || random2 == 31 || random2 == 33 || random2 == 35) // om slumpade numret är jämnt 
				{
					if (nummerval == random2) // om det angivna numret är detsamma som slumpade numret.
					{
						vinst = satsning * 10;
						saldo = saldo + vinst;
						samvinst = saldo - 1000;
						cout << "The number was " << random2 << " and the color was red" << endl;
						cout << "You won " << vinst << "kr!" << endl;
						cout << "Your balance is now " << saldo << "kr" << endl;
						cout << "Your total winnings are " << samvinst << "kr" << endl;


					}
					if (nummerval != random2) // om det angivna numret är detsamma som slumpade numret.
					{
						samvinst = samvinst - satsning;
						cout << "The number was " << random2 << " and the color was red" << endl;
						cout << "You lost. " << endl;
						cout << "Your balance is now " << saldo << "kr" << endl;

					}
				}
				if (random2 == 2 || random2 == 4 || random2 == 6 || random2 == 8 || random2 == 10 || random2 == 12 || random2 == 14 || random2 == 16 || random2 == 18 || random2 == 20 || random2 == 22 || random2 == 24 || random2 == 26 || random2 == 28 || random2 == 30 || random2 == 32 || random2 == 34 || random2 == 36) // om slumpade numret är jämnt
				{
					if (nummerval == random2) // om det angivna numret är detsamma som slumpade numret
					{
						vinst = satsning * 10; // vinsten blir satsning * 10 vid rätt gissat nummer
						saldo = saldo + vinst;
						samvinst = saldo - 1000;
						cout << "The number was " << random2 << " and the color was black" << endl;
						cout << "You won " << vinst << "kr!" << endl;
						cout << "Your balance is now " << saldo << "kr" << endl;
						cout << "Your total winnings are " << samvinst << "kr" << endl;


					}
					if (nummerval != random2)
					{
						samvinst = samvinst - satsning;
						cout << "The number was " << random2 << " and the color was black" << endl;
						cout << "You lost. " << endl;
						cout << "Your balance is now " << saldo << "kr" << endl;

					}

				}

			}
			string spelaigen;
			cout << "Do you want to play again?" << endl;
			cin >> spelaigen;
			if (spelaigen == "yes" || spelaigen == "Yes")
			{
				omspel = true;
			}
			else if (spelaigen == "no" || spelaigen == "No")
			{
				cout << "Thank you for playing" << endl;
				cout << "Goodbye!" << endl;
				omspel = false;
				exit(0);

			}
		}
	}
}