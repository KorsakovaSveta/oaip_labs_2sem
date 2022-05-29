#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;


struct student
{
	string sorename;
	int birthYear;
	string numberGroup;
	int marks[4];
};

int main()
{

	student inform[100];
	ifstream file("information.txt");
	string line, group, res, sorename;
	double sred_mark2, sred_mark1=0;
	int i = 0, j = 0, sum_marks = 0, newStudents, numberOfStudents = 0, arr[100], kod1;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	if (file)
	{
		while (getline(file, line)) ++numberOfStudents;
		file.clear();
		file.seekg(0);
		for (i = 0; i < numberOfStudents; i++)
		{

			getline(file, res, ',');
			if (res[0] == '\n')
				inform[i].sorename = res.substr(1);
			else
				inform[i].sorename = res;
			getline(file, res, ',');
			inform[i].birthYear = stoi(res);
			getline(file, inform[i].numberGroup, ',');
			for (j = 0; j < 4; j++)
			{
				file >> inform[i].marks[j];
			}

		}
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
				cout << "Сколько студентов хотите добавить\n";
				cin >> newStudents;
				for (i = 0; i < newStudents; i++)
				{
					cout << "Введите фамилию и инициалы студента\n";
					cin.get();
					getline(cin, inform[numberOfStudents].sorename);
					cout << "Введите год рождения студента\n";
					cin >> inform[numberOfStudents].birthYear;
					cout << "Введите номер группы студента\n";
					cin >> inform[numberOfStudents].numberGroup;
					cout << "Введите баллы студента по предметам\n";
					cout << "Баллы по физике, математике, информатике и химии\n";
					for (int j = 0; j < 4; j++)
					{
						cin >> inform[numberOfStudents].marks[j];
					}
					addition << "\n" << inform[numberOfStudents].sorename << "," << inform[numberOfStudents].birthYear << "," << inform[numberOfStudents].numberGroup << ",";
					for (j = 0; j < 4; j++)
					{
						addition << inform[numberOfStudents].marks[j] << " ";
					}
					numberOfStudents++;
				}
				addition.close();
			
			break;
		}

		case 4:
		{

			string res, sorename;
			cout << "Введите номер группы\n";
			cin >> group;
			cout << "Введите искомый балл\n";
			cin >> sred_mark2;
			ofstream result("Best_students.txt", ios::app);

			if (result.is_open())
			{
				result << "Список всех студентов:";
				for (i = 0; i < numberOfStudents; i++)
				{
					result << "\n" << inform[i].sorename << " " << inform[i].birthYear << " " << inform[i].numberGroup << " ";
					for (int j = 0; j < 4; j++)
					{

						result << inform[i].marks[j] << " ";
					}
				}

				result << "\n\nСтуденты имеющие средний балл выше " << sred_mark2 << ":";

				for (i = 0; i < numberOfStudents; i++)
				{
					for (j = 0; j < 4; j++)
					{
						sum_marks += inform[i].marks[j];
					}
					sred_mark1 = sum_marks / 4.0;
					sum_marks = 0;

					if (inform[i].numberGroup == group && sred_mark2 < sred_mark1)
					{
						result << "\n" << inform[i].sorename << " " << inform[i].birthYear << " " << inform[i].numberGroup << " ";
						for (int j = 0; j < 4; j++)
						{

							result << inform[i].marks[j] << " ";
						}
					}
				}
				result.close();
			}

			break;
		}
		case 5:
		{
			string name = "Best_students.txt";
			remove(name.c_str());
			break;
		}
		}
	} while (kod1 <= 5 && kod1 != 0);
}