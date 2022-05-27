#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include <sstream>
using namespace std;

struct device
{
	char productGroup[100];
	string brand;
	string data;
	char condition[12];
};

void Quick_Sort(int*, int, int, device*);
int search(int*, int, int, int);
int readData1(string);
int readDataArr(device*, int);
int main()
{
	device inform[100], change;
	ifstream file("information.txt");
	string line, group[100], datastr;
	char str[100];
	int i = 0, j = 0, newDevices, numberOfDevices = 0, kod1, data[100], arr[100];
	int year1, month1, day1, data1 = 0, day2, month2, year2, index =0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	if (file)
	{
		while (getline(file, line)) ++numberOfDevices;
		file.clear();
		file.seekg(0);
		for (i = 0; i < numberOfDevices; i++)
		{
			file.getline(inform[i].productGroup, 100, ',');
			getline(file, inform[i].brand, ',');
			getline(file, inform[i].data, ',');
			file.getline(inform[i].condition, 12, '\n');
		}
		file.close();
	}
	do
	{
		cout << " Меню\n 1 - Создание\n 2 - Просмотр\n 3 - Добавление новых данных\n 4 - Решение индивидуального задания\n 5 - Линейный поиск\n 6 - Поиск делением пополам\n 7 - Сортировка методом прямого выбора\n 8 - Quick_Sort\n 0 - Выход\n";
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
			int length;
			ofstream addition("information.txt", ios::app);
			cout << "Сколько аппаратуры хотите добавить\n";
			cin >> newDevices;
			for (i = 0; i < newDevices; i++)
			{
				cout << "Введите группу аппаратуры\n";
				cin.get();
				cin.getline(inform[numberOfDevices].productGroup, 100);
				cout << "Введите марку аппаратуры\n";
				getline(cin, inform[numberOfDevices].brand);
				cout << "Введите дату приёма\n";
				getline(cin, inform[numberOfDevices].data);
				cout << "Введите состояние готовности заказа\n";
				fgets(inform[numberOfDevices].condition, 12, stdin);

				addition << inform[numberOfDevices].productGroup << "," << inform[numberOfDevices].brand << "," << inform[numberOfDevices].data << "," << inform[numberOfDevices].condition << "\n";
				numberOfDevices++;
			}
			addition.close();
			break;
		}
		case 4:
		{
			int c = 0;
			for (i = 0; i < numberOfDevices; i++)
			{
				int contained = -1;
				for (j = 0; j < c; j++)
				{
					if (inform[i].productGroup == group[j])
						contained = j;
				}
					if (contained == -1)
						group[c++] = inform[i].productGroup;
				
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
			cout << "Введите интересующую дату приёма в ремонт\n";
			cin.get();
			getline(cin, datastr);
			istringstream(datastr) >> day2 >> month2 >> year2;
			for (i = 0; i < numberOfDevices; i++)
			{
				istringstream(inform[i].data) >> day1 >> month1 >> year1;
				if (day1 == day2 && month1 == month2 && year1 == year2)
					cout << inform[i].productGroup << " " << inform[i].brand << " " << inform[i].condition << endl;
			}
			break;
		}
		case 6:
		{
			cout << "Введите интересующую дату приёма в ремонт\n";
			cin.get();
			getline(cin, datastr);
			data1 = readData1(datastr);
			for (i=0; i<numberOfDevices; i++)
			data[i] = readDataArr(inform, i);
			Quick_Sort(data, 0, numberOfDevices - 1, inform);
			index = search(data, 0, numberOfDevices, data1);
			if (index >= 0)
				cout << inform[index].productGroup << " " << inform[index].brand << " " << inform[index].condition << endl;
			else cout << "Заказ не найден\n";
			break;
		}
		case 7:
		{
			for (i=0; i < numberOfDevices; i++)
			data[i] = readDataArr(inform, i);
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
			for (i = 0; i < numberOfDevices; i++)
				data[i] = readDataArr(inform, i);
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
	if (begin < right) 
		Quick_Sort(data, begin, right, inform);
	if (left < end) 
		Quick_Sort(data, left, end, inform);
}

int search(int* data, int i, int j, int data1)
{
	int middle = 0;
	while (1)
	{
		middle = (i + j) / 2;
		if (data1 < data[middle])
			j = middle - 1;
		else if (data1 > data[middle])
				i = middle + 1;
		else
			return middle;
		if (i > j)
			return -1;
	}
}
int readData1(string datastr)
{
	int day, month, year, data1;
	istringstream(datastr) >> day >> month >> year;
	data1 = day + (month - 1) * 31 + (year - 1900) * 365;
	return data1;
}

int readDataArr(device* inform, int i)
{
	int day, month, year, data2[100];
	istringstream(inform[i].data) >> day >> month >> year;
	data2[i] = day + (month - 1) * 31 + (year - 1900) * 365;
	return data2[i];
}