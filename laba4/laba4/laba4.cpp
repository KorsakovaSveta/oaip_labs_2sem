#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<chrono>
#include <ctime>
#include <sstream>
#include <algorithm>
using namespace std;

struct device
{
	string productGroup;
	string brand;
	string data;
	string condition;
};

void Quick_Sort(int*, int, int, device*);

int main()
{

	device inform[100];
	ifstream file("information.txt");
	string line, group[100];
	int i = 0, j = 0, newDevices, numberOfDevices = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int kod1;
	string res, sorename;
	if (file)
	{
		while (getline(file, line)) ++numberOfDevices;
		file.clear();
		file.seekg(0);
		for (i = 0; i < numberOfDevices; i++)
		{

			getline(file, inform[i].productGroup, ',');
			getline(file, inform[i].brand, ',');
			getline(file, inform[i].data, ',');
			getline(file, inform[i].condition, '\n');

		}
		file.close();
	}
	do
	{

		cout << " Меню\n 1 - Создание\n 2 - Просмотр\n 3 - Добавление новых данных\n 4 - Решение индивидуального задания\n 5 - Удаление файла с индивидуальным заданием\n 0 - Выход\n";
		cin >> kod1;
		switch (kod1)
		{
		case 1:
		{
			ifstream file("information.txt");
			if (file.is_open())
				cout << "Файл открыт\n";
			else
				cout << "Нужно создать файл\n";
			file.close();
			break;
		}
		case 2:
		{
			ifstream file("information.txt");
			cout << "\t\n--------Информация--------\n";
			while (getline(file, line))
			{
				cout << line << endl;
			}
			file.close();
			break;
		}
		case 3:
		{

			ofstream addition("information.txt", ios::app);
			cout << "Сколько аппаратуры хотите добавить\n";
			cin >> newDevices;
			for (i = 0; i < newDevices; i++)
			{
				cout << "Введите группу аппаратуры\n";
				cin.get();
				getline(cin, inform[numberOfDevices].productGroup);
				cout << "Введите марку аппаратуры\n";
				cin >> inform[numberOfDevices].brand;
				cout << "Введите дату приёма\n";
				cin >> inform[numberOfDevices].data;
				cout << "Введите состояние готовности заказа\n";
				cin >> inform[numberOfDevices].condition;

				addition << inform[numberOfDevices].productGroup << "," << inform[numberOfDevices].brand << "," << inform[numberOfDevices].data[11] << "," << inform[numberOfDevices].condition << "\n";
			}
			addition.close();

			break;
		}
		case 4:
		{
			chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();
			time_t start_time = chrono::system_clock::to_time_t(now);
			char currentData[100];
			struct tm buf;
			errno_t err = localtime_s(&buf, &start_time);
			strftime(currentData, sizeof(currentData), "%F", &buf);

			int c = 0;
			for (i = 0; i < numberOfDevices; i++)
			{
				int contained = -1;
				for (j = 0; j < c; j++) if (inform[i].productGroup == group[j]) contained = j;
				if (contained == -1) group[c++] = inform[i].productGroup;
			}
			for (i = 0; i < c; i++)
			{
				cout << group[i] << ":\n";
				for (j = 0; j < numberOfDevices; j++)
				{
					if (inform[j].productGroup == group[i])
						cout << inform[j].brand << " " << inform[j].data << " " << inform[j].condition << endl;
				}
			}
			break;
		}
		case 5:
		{
			string data;
			cout << "Введите интересующую дату приёма в ремонт\n";
			cin >> data;
			for (i = 0; i < numberOfDevices; i++)
			{
				if (inform[i].data == data)
					cout << inform[i].productGroup << " " << inform[i].brand << " " << inform[i].data << " " << inform[i].condition << endl;
			}
			break;
		}
		case 6:
		{
			int i = 0, j = numberOfDevices - 1, index;
			string data;
			cout << "Введите интересующую дату приёма в ремонт\n";
			cin >> data;
			while (i < j)
			{
				index = (i + j) / 2;
				if (inform[index].data < data)
					i = index + 1;
				else j = index;
			}
			if (inform[i].data == data)
				cout << inform[i].productGroup << " " << inform[i].brand << " " << inform[i].data << " " << inform[i].condition << endl;
			break;
		}
		case 7:
		{
			int index;
			device change;
			time_t rawtime;
			struct tm* timeinfo;
			int year, month, day, data[100], arr[100];
			for (i = 0; i < numberOfDevices; i++)
			{

				istringstream(inform[i].data) >> day >> month >> year;

				time(&rawtime);
				#pragma warning (suppress : 4996);
				timeinfo = localtime(&rawtime);
				timeinfo->tm_year = year - 1900;
				timeinfo->tm_mon = month - 1;
				timeinfo->tm_mday = day;
				data[i] = timeinfo->tm_mday + timeinfo->tm_mon * 31 + timeinfo->tm_year * 365;
			}

			for (i = 0; i < numberOfDevices - 1; i++)
			{
				index = i;

				for (j = i + 1; j < numberOfDevices; j++)
				{

					if (data[j] < data[index])
						index = j;
				}
				if (index == i) continue;
				arr[100] = data[i];
				data[i] = data[index];
				data[index] = arr[100];
				change = inform[i];
				inform[i] = inform[index];
				inform[index] = change;
			}
			for (i = 0; i < numberOfDevices; i++)
				cout << inform[i].productGroup << " " << inform[i].brand << " " << inform[i].data << " " << inform[i].condition << endl;
			break;
		}
		case 8:
		{
			device change;
			time_t rawtime;
			struct tm* timeinfo;
			int year, month, day, data[100], arr[100];
			for (i = 0; i < numberOfDevices; i++)
			{

				istringstream(inform[i].data) >> day >> month >> year;

				time(&rawtime);
				#pragma warning (suppress : 4996);
				timeinfo = localtime(&rawtime);
				timeinfo->tm_year = year - 1900;
				timeinfo->tm_mon = month - 1;
				timeinfo->tm_mday = day;
				data[i] = timeinfo->tm_mday + timeinfo->tm_mon * 31 + timeinfo->tm_year * 365;
			}
			i = 0, j = numberOfDevices - 1;
			int left = 0, right = numberOfDevices - 1;
			Quick_Sort(data, 0, numberOfDevices - 1, inform);
			for (i = 0; i < numberOfDevices; i++)
				cout << inform[i].productGroup << " " << inform[i].brand << " " << inform[i].data << " " << inform[i].condition << endl;
			break;
		}
		}
	} while (kod1 <= 8 && kod1 != 0);
}
void Quick_Sort(int* data, int begin, int end, device* inform)
{
	device change;
	int left, right, x, X;
	left = begin;
	right = end;
	x = data[(left + right) / 2];
	do {
		while (data[left] < x)  left++;
		while (x < data[right]) right--;
		if (left <= right) {
			X = data[left];
			data[left] = data[right];
			data[right] = X;
			change = inform[left];
			inform[left] = inform[right];
			inform[right] = change;
			left++;
			right--;
		}
	} while (left <= right);
	if (begin < right) Quick_Sort(data, begin, right, inform);
	if (left < end) Quick_Sort(data, left, end, inform);
}