// Laba42.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


//Кольцевой автобус.
//Автобус, вместимостью N пассажиров, движется по кольцевому маршруту, на остановках в него садятся пассажиры, 
//которые платят за проезд и выходят из автобуса на своей остановке
//Необходимо датчиком случайных чисел  сформировать список пассажиров на остановке и пункт назначения для каждого пассажира и 
//обеспечивать своевременный выход пассажиров на своей остановке.Организовать движение автобуса по остановкам.Вычислить выручку автобуса.


#include <iostream>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
using namespace std;

// 10
// 3: 1 2 3 
int main()
{

	setlocale(LC_ALL, "Russian");
	cout << "Введите Вместимость автобуса и кол-во остановок" << endl;
	unsigned int N, CountBusQuit;
	unsigned int CountPersonOnBus = 0;
	unsigned int price = 0;
	cin >> N;
	cin >> CountBusQuit;
	bool flag = true;
	srand(time(0)); //чтобы лучше рандомить
	map <unsigned int, unsigned int> BusPerson; // пассажиры в автобусе и нужные им остановки 
	
	while (flag)
	{
		for (int i = 1; i <= CountBusQuit; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// пассажиры выходят
				if (BusPerson[j] == i)
				{
					BusPerson.erase(j);
					CountPersonOnBus--;
				}
			}
			unsigned int CountPerson = rand() % N;
			for (int j = 0; j < CountPerson; j++)
			{
				// пассажиры заходят
				
				if (CountPersonOnBus < N)
				{
					while (true)
					{
						unsigned int iterator = rand() % N;
						if (!BusPerson[iterator])
						{
							BusPerson[iterator] = (rand() % CountBusQuit) + 1;
							break;
						}
					}
					price += 26;
					CountPersonOnBus++;
				}
				else
				{
					break;
				}
			}


		}// for поехали на новую остановку
		cout << "Автобус стоит на конечной и заработал всего " << price << endl;
		cout << "0 закончить работу автобуса" << endl;
		cout << "1 начать новый круг" << endl;
		cin >> flag;
	}
}

