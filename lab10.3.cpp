#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <Windows.h> 

using namespace std;

enum Zod { Aries, Taurus, Gemini, Cancer, Leo, Virgo, Libra, Scorpius, Sagittarius, Capricornus, Aquarius, Pisces };
string zodStr[] = { "«Овен»", "«Телець»","«Близнюки»","«Рак»","«Лев»","«Діва»","«Терези»","«Скорпіон»","«Стрілець»","«Козоріг»","«Водолій»","«Риби»" };
struct Zodiac
{
	string prizv;
	string imia;
	Zod zod;
	int date[3];
};
void Create(Zodiac* p, const int N, char* fname);
void Print(Zodiac* p, const int N);
void PrintW(Zodiac* p, const int N, int k);
int BinSearch(Zodiac* p, const int N, const Zod zod);
int main()
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	char fname[100];
	cout << "enter file name : "; cin >> fname;
	int N;
	int izod;
	string prizv;
	Zod zod;
	int found;
	cout << "Введіть кількість людей: "; cin >> N;
	Zodiac* p = new Zodiac[N];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - пошук людей за їх знаком зодіака" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N, fname);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			cout << "Введіть ключі пошуку:" << endl;
			cout << "Знак зодіаку (0 - Овен, 1 - Телець, 2 - Близнюки, 3 - Рак, 4 -Лев, 5-Діва, 6-Терези ): " << endl;;
			cout << "(7 - Скорпіон, 8 - Стрілець, 9 - Козоріг, 10 - Водолій, 11 -Риби): " << endl;;
			cin >> izod;
			zod = (Zod)izod;
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
			cout << endl;
			if ((found = BinSearch(p, N, zod)) != -1)
			{
				cout << "Знайдено людину з заданим знаком в позиції " << found + 1 << endl;
				cout << "Її дані " << endl;
				PrintW(p, N, found);
			}
			else
				cout << "Шукану людину не знайдено" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Zodiac * p, const int N, char* fname)
{
	ofstream fout(fname);
	int zod;
	string s;
	for (int i = 0; i < N; i++)
	{
		cout << "Людина No " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		cout << " прізвище: "; getline(cin, p[i].prizv); //fprintf(file, " %s", p[i].prizv);
		s = p[i].prizv;
		fout << s << endl;
		cout << " ім'я: "; getline(cin, p[i].imia); //fprintf(file, " %s", p[i].imia);
		cout << " День народження: "; cin >> p[i].date[0]; //fprintf(file, " %d", p[i].date[0]);
		cout << " Місяць народження: "; cin >> p[i].date[1]; //fprintf(file, " %d", p[i].date[1]);
		cout << " Рік народження: "; cin >> p[i].date[2]; //fprintf(file, " %d", p[i].date[2]);
		cout << "Знак зодіаку (0 - Овен, 1 - Телець, 2 - Близнюки, 3 - Рак, 4 -Лев, 5-Діва, 6-Терези ) " << endl;;
		cout << " (7 - Скорпіон, 8 - Стрілець, 9 - Козоріг, 10 - Водолій, 11 -Риби): " << endl;;
		cin >> zod;
		p[i].zod = (Zod)zod; //fprintf(file, " %s", p[i].zod);
		cout << endl;
	}
}
void Print(Zodiac * p, const int N)
{
	cout << "========================================================================================================================"
		<< endl;
	cout << "| No | День Народження | Місяць народження | Рік народження | Прізвище | Ім'я | Знак зодіаку | "
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(4) << right << i + 1 << " ";
		cout << "| " << setw(17) << left << p[i].date[0]
			<< "| " << setw(17) << left << p[i].date[1]
			<< "| " << setw(17) << left << p[i].date[2]
			<< "| " << setw(6) << left << p[i].prizv
			<< "| " << setw(10) << right << p[i].imia
			<< "| " << setw(14) << left << zodStr[p[i].zod]
			<< "|" << endl;
	}
	cout << "========================================================================================================================"
		<< endl;
	cout << endl;
}
void PrintW(Zodiac * p, const int N, int k)
{
	cout << "========================================================================================================================"
		<< endl;
	cout << "| No | День Народження | Місяць народження | Рік народження | Прізвище | Ім'я | Знак зодіаку | "
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------------"
		<< endl;

	cout << "| " << setw(4) << right << k + 1 << " ";
	cout << "| " << setw(17) << left << p[k].date[0]
		<< "| " << setw(17) << left << p[k].date[1]
		<< "| " << setw(17) << left << p[k].date[2]
		<< "| " << setw(6) << left << p[k].prizv
		<< "| " << setw(10) << right << p[k].imia
		<< "| " << setw(14) << left << zodStr[p[k].zod]
		<< "|" << endl;

	cout << "========================================================================================================================"
		<< endl;
	cout << endl;
}

int BinSearch(Zodiac * p, const int N, const Zod zod)
{
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].zod == zod)
			return m;
		if (p[m].zod < zod)
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}
