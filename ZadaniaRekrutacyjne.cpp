#include <iostream>

using namespace std;

/// <summary>
/// Funkcja odopowiadajaca za wyswietlenie poczatkowego interfejsu oraz przyjecie wartosci kolorow.
/// </summary>
void Input(float& green, float& yellow, float& red) {

	cout << "Prosze podac wartosc zmienno przecinkowo przy uzyciu kropki zuzycia energii na przejechanie metra dlugosci koloru" << endl;

	cout << "Zielonego" << endl;
	cin >> green;

	cout << "Zoltego" << endl;
	cin >> yellow;

	cout << "Czerwonego" << endl;
	cin >> red;

	cout << endl << endl;
}

//Stworzenie zmiennej pzyjmujacej za wartosc najwiekszego mozliwego flota.
float infinity = std::numeric_limits<float>::infinity();

/// <summary>
/// Obsłużenie przypadku, w którym użytkownik podał błędny numer punktu
/// </summary>
void UserInputValidation(float& green, float& yellow, float& red)
{
	if (green < 0 || yellow < 0 || red < 0)
	{
		cout << endl << "Sprobuj ponownie " << endl << endl;

		UserInputValidation(green, yellow, red);
	}
}

/// <summary>
/// Algorytm obliczajacy najkrotsza trase i zaisujacy go do tablicy z wynikami.
/// </summary>
void FindShortestPath(float results[14][2], float tab[14][14])
{
	for (int j = 0; j < 14; j++)
	{
		for (int k = 0; k < 14; k++)
		{
			if (tab[j][k] >= 0)
			{
				if (tab[j][k] + results[j][0] <= results[k][0])
				{
					results[k][0] = tab[j][k] + results[j][0];
					results[k][1] = j;
				}
			}
		}
	}
}

/// <summary>
/// Funkcja dodajaca mozliwosc obliczenia najkrotszej trasy do innego punktu niz punkt podstawowy.
/// </summary>
int GetDestinationPoint()
{
	int x;

	cout << "Chcesz poznac najnizsze zuzycie energii w trasie do punktu innego niz podstwowy?" << endl << "Jesli tak wcisnij 1, a jesli nie wcisnij 2" << endl;
	cin >> x;
	cout << endl;

	//Przypadek w ktorym jest wyrazona chec obliczenia trasy do innego pnajnizszego zuzycia energi podczas trasy di innego punktu.
	if (x == 1)
	{
		cout << "Wpisz numer punktu, od 0 do 13" << endl;
		cin >> x;

		if (x >= 0 && x <= 13)
		{
			return x;
		}
		// Obsłużenie przypadku, w którym użytkownik podał błędny numer.
		else
		{
			cout << endl << "Sprobuj ponownie" << endl << endl;
			GetDestinationPoint();
		}
	}
	//Przypadek w ktorym nie ma ow checi.
	else if (x == 2)
	{
		x = 12;
		return x;
	}
	// Obsłużenie przypadku, w którym użytkownik podał błędny numer
	else
	{
		cout << endl << "Sprobuj ponownie" << endl << endl;
		GetDestinationPoint();
	}
}

/// <summary>
/// Funkcja wyswietlajaca punkty przez ktore przebiega trasa.
/// </summary>
void RouteCourse(int x, float results[14][2])
{
	int n;

	cout << "Chcesz poznac poszczegolne punkty najkrotszej trasy?" << endl << "Jesli tak wcisnij 1, a jesli nie wcisnij 2" << endl;
	cin >> n;

	//Przypadek w ktorym jest wyrazona chec obliczenia trasy do innego punktu. 
	if (n == 1)
	{
		cout << endl;
		while (x != 0)
		{
			cout << results[x][1] << " ";
			x = results[x][1];
		}
	}
	//Przypadek w ktorym nie ma ow checi.
	else if (n == 2)
	{
		return;
	}
	// Obsłużenie przypadku, w którym użytkownik podał błędny numer
	else
	{
		cout << endl << endl << "Sprobuj ponownie" << endl << endl;
		RouteCourse(x, results);
	}
}

int main()
{
	//Stworzenie potrzebnych zmiennych.
	float green = 0, yellow = 0, red = 0;
	int x;

	//Wywolanie wyzej zadeklarowanych funkcji.
	Input(green, yellow, red);
	UserInputValidation(green, yellow, red);

	//Stworzenie macierz na podstawie sciezek trasy oraz ich kolorow.
	float tab[14][14] =
	{
		{0,	10 * green,	2 * yellow, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{10 * green, -1, -1,	4.5 * green, -1, -1, -1, -1, -1, -1,	7.8 * red, -1, -1, -1},
		{2 * yellow, -1, -1,	7.5 * yellow,	3 * red, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{-1,	4.5 * green,	7.5 * yellow, -1, -1,	3.5 * green, -1, -1, -1,	4.2 * yellow, -1, -1, -1, -1},
		{-1, -1,	3 * red, -1, -1,	3.8 * red, -1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1,	3.5 * green,	3.8 * red, -1, -1,	2 * red, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1,	3.8 * yellow, -1, -1, -1,	3.5 * yellow, -1, -1,},
		{-1, -1, -1, -1, -1,	2 * red,	3.8 * yellow, -1,	1.3 * red, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1,	1.3 * red, -1,	3.7 * green, -1, -1,	3.3 * red, -1},
		{-1, -1, -1,	4.2 * yellow, -1, -1, -1, -1,	3.7 * green, -1,	1.7 * yellow, -1, -1, -1},
		{-1,	7.8 * red, -1, -1, -1,-1, -1, -1, -1,	1.7 * yellow, -1, -1, -1,	2.2 * green},
		{-1, -1, -1, -1, -1, -1,	3.5 * yellow, -1, -1, -1, -1, -1,	5 * yellow, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1,	3.3 * red, -1, -1,	5 * yellow,-1,	5 * green},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	2.2 * green, -1,	5 * green, -1}
	};

	//Stworzenie tablicy w ktorej bedzie zapisywal sie wynik oraz trasa do niego.
	float results[14][2] =
	{
		{0,-1},
		{infinity,-1},
		{infinity,-1},
		{infinity,-1},
		{infinity,-1},
		{infinity,-1},
		{infinity,-1},
		{infinity,-1},
		{infinity,-1},
		{infinity,-1},
		{infinity,-1},
		{infinity,-1},
		{infinity,-1},
		{infinity,-1},
	};

	FindShortestPath(results, tab);

	x = GetDestinationPoint();

	cout << endl << results[x][0] << endl << endl << endl;;
	RouteCourse(x, results);

	return 0;
}
