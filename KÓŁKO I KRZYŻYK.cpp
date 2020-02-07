#include<iostream>
#include<conio.h>
#include <random>
#include <Windows.h>
#include <cstdlib>
using namespace std;


void plansza(int k, int gracz, char* tab);
bool wygranaX(char* tab);
bool remis(char* tab);
void Wygrana();
void X();
void O();
void Remis();
int GRA();
void instrukcja();
void MENU();
int GraZKomputerem();
void WyborNaKoniec();
void tytul();
int CzyMozna(char* tab);

int main()
{
	MENU();

	system("pause");
}

int GRA()
{
	int pole, JakiGracz;
	JakiGracz = 1;
	char tab[9]{}; //plansza
	char* wtab = tab; //wskaznik na plansze

	plansza(1, 0, wtab);
	cout << endl;
	//cout << "        Zaczyna X: " << endl;
	do {
		cout << "        Kolej: ";
		if (JakiGracz == 1)
			cout << "X" << endl;
		else if (JakiGracz != 1)
			cout << "O" << endl;
		cout << "        Wybierz numer pola: ";

		cin >> pole;
		if (cin >> pole)
		{
			cout << "m" << endl;
		}
		else
		{
			cin.clear();
			while (cin.get() != '\n') {}
			cout << "blad wprowadzenia" << endl;
		}

		plansza(pole, JakiGracz, wtab);
		if (JakiGracz == 1)           //zamienia gracza
			JakiGracz++;
		else if (JakiGracz == 2)
			JakiGracz--;
		bool i = wygranaX(wtab);
		if (i == true)
		{
			system("cls");
			Wygrana();
			if (JakiGracz == 1)
				O();
			else
				X();
			_getch();
			return 0;
		}
		if (!remis(wtab))
		{
			system("cls");
			Remis();
			_getch();
			return 0;
		}



	} while ((pole >= 1 && pole <= 9));

	return 1;

}

void plansza(int k, int gracz, char* tab)
{
	system("cls");
	k = k - 1;
	char pole;    //inicjujemy zmienna
	switch (gracz)
	{
	case 1: pole = 'X';
		if (tab[k] == NULL)
			tab[k] = pole; //miejsce w tablicy, w ktorym sie znajdujemy dostaje wartosc ustawiona przez aktualnego gracza
		else
			cout <<endl << "      TO POLE JEST JUZ ZAJETE" ;
		break;
	case 2: pole = 'O';
		if (tab[k] == NULL)
			tab[k] = pole;
		else
			cout<< endl << "      TO POLE JEST JUZ ZAJETE";
		break;
	default:
		cout << "";
		break;
	}

	//RYSOWANIE PLANSZY
	unsigned char lg = 0xDA; //lewy górny róg
	unsigned char ld = 0xC0; // lewy dolny róg
	unsigned char pg = 0xBF; // prawy górny róg 
	unsigned char pd = 0xD9; // prawy dolny róg
	unsigned char pb = 0xB4; // prawy bok
	unsigned char lb = 0xC3; // lewy bok
	unsigned char gora = 0xC2;
	unsigned char dol = 0xC1;
	unsigned char poz = 0xC4;
	unsigned char srod = 0xC5;
	unsigned char pion = 0xB3;
	cout << endl << endl;
	cout << "        " << "*****************" << endl;
	cout << "        * " << lg << poz << poz << poz << gora << poz << poz << poz << gora << poz << poz << poz << pg <<" *"<< endl;
	cout << "        * " << pion << " " << tab[0] << " " << pion << " " << tab[1] << " " << pion << " " << tab[2] << " " << pion << " *" << endl;
	cout << "        * " << lb << poz << poz << poz << srod << poz << poz << poz << srod << poz << poz << poz << pb << " *" << endl;
	cout << "        * " << pion << " " << tab[3] << " " << pion << " " << tab[4] << " " << pion << " " << tab[5] << " " << pion << " *" << endl;
	cout << "        * " << lb << poz << poz << poz << srod << poz << poz << poz << srod << poz << poz << poz << pb << " *" << endl;
	cout << "        * " << pion << " " << tab[6] << " " << pion << " " << tab[7] << " " << pion << " " << tab[8] << " " << pion << " *" << endl;
	cout << "        * " << ld << poz << poz << poz << dol << poz << poz << poz << dol << poz << poz << poz << pd << " *" << endl;
	cout << "        " << "*****************" << endl;

}

bool remis(char* tab)     // sprawdza czy remis
{
	for (int i = 0; i < 9; i++)
	{
		if (tab[i] == NULL)
			return true;
	}
	return false;
}

bool wygranaX(char* tab)          // sprawdza wygran¹
{
	if ((tab[0] == tab[1] && tab[1] == tab[2] && tab[0] != NULL) ||
		(tab[3] == tab[4] && tab[4] == tab[5] && tab[3] != NULL) ||
		(tab[6] == tab[7] && tab[7] == tab[8] && tab[6] != NULL) ||
		(tab[0] == tab[3] && tab[3] == tab[6] && tab[0] != NULL) ||
		(tab[1] == tab[4] && tab[4] == tab[7] && tab[1] != NULL) ||
		(tab[2] == tab[5] && tab[5] == tab[8] && tab[2] != NULL) ||
		(tab[0] == tab[4] && tab[4] == tab[8] && tab[0] != NULL) ||
		(tab[6] == tab[4] && tab[4] == tab[2] && tab[6] != NULL))
		return true;
	return false;
};

void Wygrana()
{
	cout << " XXX    XXX    XXX   XXXXX  X   X  X        XXX    XXX   XXXXX   XXXX" << endl;
	cout << "X   X  X   X  X   X    X    X   X  X       X   X  X   X      X  X    " << endl;
	cout << "X      X   X  X   X    X    X   X  X       X   X  X          X  X    " << endl;
	cout << "X  XX  XXXX   XXXXX    X    X   X  X       XXXXX  X          X  XXXX " << endl;
	cout << "X X X  X  X   X   X    X    X   X  X       X   X  X      X   X  X    " << endl;
	cout << "X   X  X   X  X   X    X    X   X  X       X   X  X   X  X   X  X    " << endl;
	cout << " XXX   X   X  X   X    X     XXX    XXXX   X   X   XXX    XXX    XXXX" << endl;
	cout << endl << endl << endl;
	
}

void X()
{
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << "XXX                                                               XXX" << endl;
	cout << "XXX                       XXXX      XXXX                          XXX" << endl;
	cout << "XXX                         XXX    XXX                            XXX" << endl;
	cout << "XXX                          XXX  XXX                             XXX" << endl;
	cout << "XXX                           XXXXXX                              XXX" << endl;
	cout << "XXX                          XXX  XXX                             XXX" << endl;
	cout << "XXX                         XXX    XXX                            XXX" << endl;
	cout << "XXX                       XXXX      XXXX                          XXX" << endl;
	cout << "XXX                                                               XXX" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	Sleep(1000);
	WyborNaKoniec();
}

void O()
{
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << "XXX                                                               XXX" << endl;
	cout << "XXX                           XXXXXX                              XXX" << endl;
	cout << "XXX                         XXXXXXXXXX                            XXX" << endl;
	cout << "XXX                        XXX      XXX                           XXX" << endl;
	cout << "XXX                        XX        XX                           XXX" << endl;
	cout << "XXX                        XXX      XXX                           XXX" << endl;
	cout << "XXX                         XXXXXXXXXX                            XXX" << endl;
	cout << "XXX                           XXXXXX                              XXX" << endl;
	cout << "XXX                                                               XXX" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	Sleep(1000);
	WyborNaKoniec();

}

void Remis()
{
	cout << " XXX    XXXX   X X   X   XXX " << endl;
	cout << "X   X  X      X X X  X  X   X" << endl;
	cout << "X   X  X      X X X  X  X    " << endl;
	cout << "XXXX   XXXX   X   X  X   XXX " << endl;
	cout << "X  X   X      X   X  X      X" << endl;
	cout << "X   X  X      X   X  X  X   X" << endl;
	cout << "X   X   XXXX  X   X  X   XXX " << endl;
	Sleep(1000);
	WyborNaKoniec();
}

void MENU()
{
	system("cls");
	tytul();
	cout << endl << endl << endl;
	cout << "                           *****************************************                                   " << endl;
	cout << "                           *****************************************                                   " << endl << endl;
	cout << cout.width(40)<< "1. Multiplayer" << endl;
	cout << cout.width(40)<< "2. Singleplayer" << endl;
	cout << cout.width(40) << "3. Instrukcja"  << endl;
	cout << cout.width(40) << "4. Wyjscie" << endl<< endl;
	cout << "                           *****************************************                                   " << endl;
	cout << "                           *****************************************                                   " << endl;

	int polecenie;
	cin >> polecenie;
	switch (polecenie)
	{
	case 1:
		GRA();
	case 2:
		GraZKomputerem();
	case 3:
		instrukcja();
	case 4:
		exit(0);
	}
}

void instrukcja()
{
	system("cls");
	unsigned char lg = 0xDA; //lewy górny róg
	unsigned char ld = 0xC0; // lewy dolny róg
	unsigned char pg = 0xBF; // prawy górny róg 
	unsigned char pd = 0xD9; // prawy dolny róg
	unsigned char pb = 0xB4; // prawy bok
	unsigned char lb = 0xC3; // lewy bok
	unsigned char gora = 0xC2;
	unsigned char dol = 0xC1;
	unsigned char poz = 0xC4;
	unsigned char srod = 0xC5;
	unsigned char pion = 0xB3;
	cout << endl << endl << endl;
	cout <<"          "<<"1. Zaczyna gracz X" << endl << "          " << "2. Numer pola to miejsce w ktore zostanie wstawiony znak" << endl << "          " << "3. Po wstawieniu znaku nastepuje zmiana gracza" << endl << endl << endl;

	cout << "                    " << lg << poz << poz << poz << gora << poz << poz << poz << gora << poz << poz << poz << pg << endl;
	cout << "                    " << pion << " " << "1" << " " << pion << " " << "2" << " " << pion << " " << "3" << " " << pion << endl;
	cout << "                    " << lb << poz << poz << poz << srod << poz << poz << poz << srod << poz << poz << poz << pb << endl;
	cout << "                    " << pion << " " << "4" << " " << pion << " " << "5" << " " << pion << " " << "6" << " " << pion << endl;
	cout << "                    " << lb << poz << poz << poz << srod << poz << poz << poz << srod << poz << poz << poz << pb << endl;
	cout << "                    " << pion << " " << "7" << " " << pion << " " << "8" << " " << pion << " " << "9" << " " << pion << endl;
	cout << "                    " << ld << poz << poz << poz << dol << poz << poz << poz << dol << poz << poz << poz << pd << endl;
	cout << endl << endl << endl;
	int wybor;
	cout << "          " << "1.Powrot";
	cin >> wybor;

	if (wybor == 1)
		MENU();
	else
		cout << "NIE MA TAKIEJ OPCJI";
}

int GraZKomputerem()
{

	random_device device;
	mt19937 generator(device());
	uniform_int_distribution <int > distribution(1, 9);
	
	int pole, JakiGracz;
	JakiGracz = 1;
	char tab[9]{}; //plansza
	char* wtab = tab; //wskaznik na plansze

	plansza(1, 0, wtab);
	cout << endl;
	do {
		cout << "        Kolej: ";
		if (JakiGracz == 1)
			cout << "X" << endl;
		else if (JakiGracz != 1)
			cout << "O" << endl;
		cout << "        Wybierz numer pola: ";
		if (JakiGracz == 1)
			cin >> pole;
		else if (JakiGracz != 1)
		{
			Sleep(1000);
			pole = CzyMozna(wtab);
			//pole = distribution(generator);
			
		}
		plansza(pole, JakiGracz, wtab);
		if (JakiGracz == 1)           //zamienia gracza
			JakiGracz++;
		else if (JakiGracz == 2)
			JakiGracz--;
		bool i = wygranaX(wtab);  //sprawdza wygrana
		if (i == true)
		{
			system("cls");
			Wygrana();
			if (JakiGracz == 1)
				O();
			else
				X();
			_getch();
			return 0;
		}
		if (!remis(wtab))   // sprawdza remis
		{
			system("cls");
			Remis();
			_getch();
			return 0;
		}
	} while ((pole >= 1 && pole <= 9));
	return 1;
}

void WyborNaKoniec()
{
	cout << endl;
	int powrot;
	cout << "1. Powrot do menu" << endl;
	cout << "2. Wyjdz z gry" << endl;
	cin >> powrot;
	if (powrot == 1)
		MENU();
	else if (powrot == 2)
		exit(0);
 }

void tytul()
{
	cout << endl << endl;
	cout << "     #   #          #   #              #    #                           #           #               " << endl;
	cout << "     #  #     #     #   #                   #                                       #             " << endl;
	cout << "     # #     ###    #   #  #   ###     #    #  #  # ##  #####  #   #  #####  #   #  #  #              " << endl;
	cout << "     ##     # # #   ##  # #   #   #    #    # #   ##       #   #   #     #   #   #  # #               " << endl;
	cout << "     # #    #   #  ##   ##    #   #    #    ##    #       #    #   #    #    #   #  ##              " << endl;
	cout << "     #  #   #   #   #   # #   #   #    #    # #   #      #     #   #   #     #   #  # #              " << endl;
	cout << "     #   #   ###    #   #  #   ###     #    #  #  #     #####   ####  #####   ####  #  #                  " << endl;
	cout << "                                                                   #             #           " << endl;
	cout << "                                                                   #             #           " << endl;
	cout << "                                                                 ##            ##             " << endl;
	cout << endl;
}

int CzyMozna(char *tab)
{
	int a{};
	random_device device;
	mt19937 generator(device());
	uniform_int_distribution <int > distribution(1, 9);
	for(;;)
	{
	a = distribution(generator);
	if (tab[a-1] == NULL)
		break;
	}
	return a;
}
