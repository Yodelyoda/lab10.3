#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <Windows.h> 

using namespace std;

enum Zod { Aries, Taurus, Gemini, Cancer, Leo, Virgo, Libra, Scorpius, Sagittarius, Capricornus, Aquarius, Pisces };
string zodStr[] = { "������", "��������","���������","����","����","�ĳ��","�������","���������","���������","�������","�������","�����" };
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
{ // ������������ ����������� ��������:
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
	char fname[100];
	cout << "enter file name : "; cin >> fname;
	int N;
	int izod;
	string prizv;
	Zod zod;
	int found;
	cout << "������ ������� �����: "; cin >> N;
	Zodiac* p = new Zodiac[N];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ����� ����� �� �� ������ ������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
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
			cout << "������ ����� ������:" << endl;
			cout << "���� ������ (0 - ����, 1 - ������, 2 - ��������, 3 - ���, 4 -���, 5-ĳ��, 6-������ ): " << endl;;
			cout << "(7 - �������, 8 - �������, 9 - ������, 10 - ������, 11 -����): " << endl;;
			cin >> izod;
			zod = (Zod)izod;
			cin.get(); // ������� ����� ��������� � �� ����������� �������
			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
			cout << endl;
			if ((found = BinSearch(p, N, zod)) != -1)
			{
				cout << "�������� ������ � ������� ������ � ������� " << found + 1 << endl;
				cout << "�� ���� " << endl;
				PrintW(p, N, found);
			}
			else
				cout << "������ ������ �� ��������" << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
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
		cout << "������ No " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
		cout << " �������: "; getline(cin, p[i].prizv); //fprintf(file, " %s", p[i].prizv);
		s = p[i].prizv;
		fout << s << endl;
		cout << " ��'�: "; getline(cin, p[i].imia); //fprintf(file, " %s", p[i].imia);
		cout << " ���� ����������: "; cin >> p[i].date[0]; //fprintf(file, " %d", p[i].date[0]);
		cout << " ̳���� ����������: "; cin >> p[i].date[1]; //fprintf(file, " %d", p[i].date[1]);
		cout << " г� ����������: "; cin >> p[i].date[2]; //fprintf(file, " %d", p[i].date[2]);
		cout << "���� ������ (0 - ����, 1 - ������, 2 - ��������, 3 - ���, 4 -���, 5-ĳ��, 6-������ ) " << endl;;
		cout << " (7 - �������, 8 - �������, 9 - ������, 10 - ������, 11 -����): " << endl;;
		cin >> zod;
		p[i].zod = (Zod)zod; //fprintf(file, " %s", p[i].zod);
		cout << endl;
	}
}
void Print(Zodiac * p, const int N)
{
	cout << "========================================================================================================================"
		<< endl;
	cout << "| No | ���� ���������� | ̳���� ���������� | г� ���������� | ������� | ��'� | ���� ������ | "
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
	cout << "| No | ���� ���������� | ̳���� ���������� | г� ���������� | ������� | ��'� | ���� ������ | "
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
