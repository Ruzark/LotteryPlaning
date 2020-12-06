#include <iostream>
#include <ctime>
#include <locale>
using namespace std;
struct lotery
{
	int tickets = 0, time = 0, empty_time = 0, T = 0, copytime = 0;
	bool end = false;

};


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	struct lotery p[6];
	bool finish = false;
	p[1].tickets = 0;
	p[2].tickets = 30;
	p[3].tickets = 35;
	p[4].tickets = 50;
	p[5].tickets = 85;

	p[1].time = 10;
	p[2].time = 1;
	p[3].time = 4;
	p[4].time = 2;
	p[5].time = 3;

	p[1].copytime = 10;
	p[2].copytime = 1;
	p[3].copytime = 4;
	p[4].copytime = 2;
	p[5].copytime = 3;

	p[1].empty_time = 0;
	p[2].empty_time = 6;
	p[3].empty_time = 3;
	p[4].empty_time = 4;
	p[5].empty_time = 5;

	cout << " №   Количество билетов  Время выполнения  Время появления\n";
	for (int i = 1; i != 6; i++)
	{
		cout << i << "\t\t" << p[i].tickets << "\t\t" << p[i].time << "\t\t" << p[i].empty_time << endl;
	}
	int quant = 1;
	bool qcomplited = false;
	int countEnd = 0;
	int TempraryTicket = 0;
	int timedTicket = 100;
	do
	{
		TempraryTicket = 0 + rand() % 100;

		if (quant <= 2) {
			p[1].tickets = 0;
		}
		if (quant <= 3) {
			p[1].tickets = 0;
			p[3].tickets = 85;
		}
		if (quant <= 4) {
			p[1].tickets = 0;
			p[3].tickets = 50;
			p[4].tickets = 85;
		}
		if (quant <= 5) {
			p[1].tickets = 35;
			p[3].tickets = 50;
			p[4].tickets = 85;
			p[5].tickets = 100;
		}
		if (quant <= 6) {
			p[1].tickets = 0;
			p[2].tickets = 30;
			p[3].tickets = 35;
			p[4].tickets = 50;
			p[5].tickets = 85;
		}

		for (int i = 1; i < 6; i++)
		{
			if (quant >= p[i].empty_time)
			{
				if (TempraryTicket > p[i].tickets and qcomplited == false) 
				{
					p[i].copytime--;
					quant++;
					qcomplited = true;
				}
			}
		}
		qcomplited = false; 
		for (int i = 1; i < 6; i++) {
			if (p[i].copytime == 0) {
				if (i == 1) {
					p[i].tickets = 100;
					p[i + 1].tickets = 0;
				}
				else
				{
					p[i].tickets = p[i - 1].tickets;
				}

			}
		}


		for (int i = 1; i < 6; i++) // подсчет общего времени в системе
		{
			if (p[i].copytime == 0) {
				p[i].end = true;
				p[i].T = quant - p[i].empty_time;

			}
		}
		for (int i = 1; i < 6; i++)
		{
			if (p[i].end == true)
				countEnd++;
			if (countEnd == 5) {
				finish = true;
			}

		}
		countEnd = 0;

	} while (finish != true);
	double  SM = 0, SR = 0, SP = 0;
	for (int i = 1; i < 6; i++)
	{

		SM = (p[i].T - p[i].time);
		SR = (double(p[i].time) / p[i].T);
		SP = (double(p[i].T) / p[i].time);
		cout << "Процесс №" << i << ":" << endl << "T=" << p[i].T << "\t\t" << "M=" << SM << "\t\t" << "R=" << SR << "\t\t" << "P=" << SP << endl << endl;
	}

	return 0;
}
