#include <iostream>
using namespace std;
#include <ctime>
//test
int main()
{
	int saldo = 1000; // h�r initieras samt deklareras de globala variablerna. 
	int satsning = 0;
	int samvinst = 0;
	int vinst = 0;
	bool omspel;
	while (omspel = true) // medans omspel som bool �r true s� loopas programmet. Detta avg�rs i slutet av programmet med ett alternativ till anv�ndaren.
	{
		if (saldo < 100) // Om saldot �r mindre �n 100 (den minsta m�jliga satsningen) s� f�r man inte spela mer.
		{
			cout << "You do not have any money left to play for" << endl;
			return 0;
		}
		cout << "Your balance is " << (saldo) << "kr." << endl;
		cout << " How much do you want to bet, " << endl;
		cout << "100, 300 or 500 kr?" << endl; 
		cin >> satsning; // H�r f�r anv�ndaren ange hur mycket de vill spela f�r 100, 300 eller 500. Samt se hur mycket deras saldo �r.

		if (satsning != 100 && satsning != 300 && satsning != 500) // om satsningen �r annat �n de tre givna alternativ s� st�ngs programmet av och de m�ste starta om f�r att spela.
		{
			cout << "Given amount not accepted, please try again" << endl;
			return 0;
		}
		if (saldo < satsning) // Om anv�ndaren f�rs�ker satsa mer �n deras saldo s� st�ngs programmet av och de f�r starta om.
		{
			cout << "You do not have enough money to bet that much" << endl;
			return 0;
		}
		if (satsning == 100 || satsning == 300 || satsning == 500) // om satsningen angiven �r en av de tre till�tna f�r de v�lja speltyp. F�rg/nummer.
		{
			saldo = saldo - satsning;
			cout << "You have chosen to bet " << satsning << "kr. " << satsning << "kr " << "has been drawn from balance." << endl;
			cout << "Do you want to pick a color (red for uneven black for even) or a number? (1-36)" <<endl;

			string v�gval1;
			cin >> v�gval1;
			if (v�gval1 == "color" || v�gval1 == "Color") //Om f�rgvalet �r f�rg s� ber programmet de specifera vilken f�rg.
			{
				string f�rgval;
				cout << "Red or Black?" << endl;
				cin >> f�rgval;
				if (f�rgval == "red" || f�rgval == "Red" || f�rgval == "black" || f�rgval == "Black") //Om f�rgvalet �r en av de till�tna.
				{
					srand(time(0));
					int random = rand() % 36 + 1; // h�r slumpas numret fram.

					if (random == 1 || random == 3 || random == 5 || random == 7 || random == 9 || random == 11 || random == 13 || random == 15 || random == 17 || random == 19 || random == 21 || random == 23 || random == 25 || random == 27 || random == 29 || random == 31 || random == 33 || random == 35) // om det slumpade numret �r udda
					{


						if (f�rgval == "red" || f�rgval == "Red") //om inmatade f�rgvalet var r�d.
						{
							vinst = satsning * 2; // h�r best�ms vinsten.
							saldo = saldo + vinst; // h�r adderas vinsten till saldot.
							samvinst = saldo - 1000; // h�r visas den sammanlagda vinsten, vilket �r saldot - 1000. allts� allt �ver startsumman.
							cout << "The number was " << random << " and the color was red." << endl; 
							cout << "You won " << vinst << "kr!" << endl; // h�r ges resultatet.
							cout << "Your balance is now " << saldo << "kr" << endl; // h�r ser anv�ndaren sitt saldo efter att ha vunnit.
							cout << "Your total winnings are " << samvinst << "kr" << endl; 
						}
						else if (f�rgval != "red" || f�rgval != "Red")  // om inmatade f�rgvalet inte var r�d.
						{
							cout << "The number was " << random << " and the color was red." << endl;
							cout << "You lost" <<endl; // h�r ges resultat f�r f�rlust.
							cout << "Your balance is now " << saldo << endl; // h�r ser anv�ndaren sitt saldo efter att ha f�rlorat.

						}
					}

					else if (random == 2 || random == 4 || random == 6 || random == 8 || random == 10 || random == 12 || random == 14 || random == 16 || random == 18 || random == 20 || random == 22 || random == 24 || random == 26 || random == 28 || random == 30 || random == 32 || random == 34 || random == 36) // om det slumpade numret �r j�mnt
					{
						
						if (f�rgval == "black" || f�rgval == "Black") // om f�rgvalet var svart.
						{
							vinst = satsning * 2; 
							saldo = saldo + vinst;
							samvinst = saldo - 1000;
							cout << "You won " << vinst << " kr!" << endl;
							cout << "The number was " << random << " and the color was black" << endl;
							cout << "Your balance is now " << saldo << "kr" << endl;
							cout << "Your total winnings are " << samvinst << "kr" << endl;

						}
						else if (f�rgval != "black" || f�rgval != "Black") 
						{
							cout << "The number was " << random << " and the color was black. " << endl;
							cout << "You lost. " << endl;
							cout << "Your balance is now " << saldo << "kr" << endl; 

						}
					}
				}
			}
			if (v�gval1 == "number" || v�gval1 == "Number") // om speltypen �r nummer.
			{
				int nummerval;
				cout << "Which number (1-36)?" << endl;
				cin >> nummerval;
				srand(time(0));
				int random2 = rand() % 36 + 1; //h�r slumpas nummret fram
				if (random2 == 1 || random2 == 3 || random2 == 5 || random2 == 7 || random2 == 9 || random2 == 11 || random2 == 13 || random2 == 15 || random2 == 17 || random2 == 19 || random2 == 21 || random2 == 23 || random2 == 25 || random2 == 27 || random2 == 29 || random2 == 31 || random2 == 33 || random2 == 35) // om slumpade numret �r j�mnt 
				{
					if (nummerval == random2) // om det angivna numret �r detsamma som slumpade numret.
					{
						vinst = satsning * 10;
						saldo = saldo + vinst;
						samvinst = saldo - 1000;
						cout << "The number was " << random2 << " and the color was red" << endl;
						cout << "You won " << vinst << "kr!" << endl;
						cout << "Your balance is now " << saldo << "kr" << endl;
						cout << "Your total winnings are " << samvinst << "kr" << endl;


					}
					if (nummerval != random2) // om det angivna numret �r detsamma som slumpade numret.
					{
						samvinst = samvinst - satsning;
						cout << "The number was " << random2 << " and the color was red" << endl;
						cout << "You lost. " << endl;
						cout << "Your balance is now " << saldo << "kr" << endl;

					}
				}
				if (random2 == 2 || random2 == 4 || random2 == 6 || random2 == 8 || random2 == 10 || random2 == 12 || random2 == 14 || random2 == 16 || random2 == 18 || random2 == 20 || random2 == 22 || random2 == 24 || random2 == 26 || random2 == 28 || random2 == 30 || random2 == 32 || random2 == 34 || random2 == 36) // om slumpade numret �r j�mnt
				{
					if (nummerval == random2) // om det angivna numret �r detsamma som slumpade numret
					{
						vinst = satsning * 10; // vinsten blir satsning * 10 vid r�tt gissat nummer
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