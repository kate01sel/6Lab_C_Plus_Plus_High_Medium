#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

struct Memo
{
	double number;
};

int main()
{
	int n, i;

	cout << "Enter kolvo number ";
	cin >> n;
	cout << endl;

	Memo * num = new Memo[n];

	cout << "Enter " << n << " integer number through a space" << endl;

	ofstream fout("Laba 6.bin");
	for (i = 0; i < n; i++)
	{
		cin >> num[i].number;
		fout << num[i].number;
		cout << num[i].number << " ";

		num[i].number *= 2;
		fout << num[i].number;
	}
	fout.close();

	cout << endl;
	for (i = 0; i < n; i++)
		cout << num[i].number << " ";
	cout << endl;

	return 0;
}
