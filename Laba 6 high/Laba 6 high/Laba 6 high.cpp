#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student
{
	string Surname;
	string Name;
	string Patronymic;
	double Ses[3];
	double Scholarchip;
};



int main()
{
	int i, n, j, k = 0;

	cin >> n;
	Student *student = new Student[n];

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	ofstream fout("Laba 5.txt", ios_base::binary);
	for (i = 0; i < n; i++)
	{
		getline(cin, student[i].Surname);
		fout << student[i].Surname;
		getline(cin, student[i].Name);
		fout << student[i].Name;
		getline(cin, student[i].Patronymic);
		fout << student[i].Patronymic;
		for (j = 0; j < 3; j++)
		{
			student[i].Ses[j] = 0 + rand() % 5;
			fout << student[i].Ses[j];
		}
		student[i].Scholarchip = 1000 + rand() % 1600;
		fout << student[i].Scholarchip;
	}

	ofstream out("Laba 5.txt", ios_base::binary);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
			if (student[i].Ses[j] > 2)
				k++;
		if (k == 3)
		{
			cout << student[i].Surname << " " << student[i].Name << " " << student[i].Patronymic << endl << student[i].Ses[0]
			<< " " << student[i].Ses[1] << " " << student[i].Ses[2] << " " << endl << student[i].Scholarchip << endl << endl;

			fout << student[i].Surname << " " << student[i].Name << " " << student[i].Patronymic << endl << student[i].Ses[0]
			<< " " << student[i].Ses[1] << " " << student[i].Ses[2] << " " << endl << student[i].Scholarchip << endl << endl;
		}
		k = 0;
	}
	fout.close();

	for (i = 0; i < n; i++)
		cout << student[i].Surname << " " << student[i].Name << " " << student[i].Patronymic << endl << student[i].Ses[0] << " " <<
		student[i].Ses[1] << " " << student[i].Ses[2] << " " << endl << student[i].Scholarchip << endl << endl;

	return 0;
}