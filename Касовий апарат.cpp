#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <fstream>
#include <cstdio>   

using namespace std;

struct kasa {
	int number;
	string nazva;
	int kilkist;
	int price;
}kas[20];

struct basket {
	int number;
	string nazva;
	int kilkist;
	int price;
	int cost;
}bas[20];

void input_sp();
void output_sp();
void choice();
void shop();
void buy();
void password();
void change();
void remove();
void inp_esc();
void basket();
void seen();
void  hint();

int kl, a, b, i = 1, x = 1, vr = 0, sum = 0, n = 1, z = 1;
string st;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (i == 1) {
		ifstream fin;
		fin.open("����������.txt");
		if (!fin.is_open()) {
			ofstream fout;
			fout.open("����������.txt");
			fout.close();
		}
		else {
			getline(fin, st);
			fin >> st >> st >> st >> st >> vr;
			getline(fin, st);
			getline(fin, st);
			getline(fin, st);
			getline(fin, st);

			do {
				fin >> kas[i].number >> kas[i].nazva >> kas[i].kilkist >> kas[i].price;
				i++;
				n++;
			} while (fin);
			i--, n--;
			fin.close();
		}
	}
	b = 0;
	do {
		system("cls");
		cout << endl << "\t\t\t\t ��ֲ�!!! " << endl;
		cout << endl << " ��� ������� ������ �� ���� �� 500 �������, �� �������� ������ - 10%!!! " << endl << endl;
		cout << endl << "\t\t������� ���� � ������:" << endl << endl;
		if (b == 0)
			cout << " --->>> ";
		else cout << "\t";
		cout << " �������������� �볺��� " << endl;
		if (b == 1)
			cout << " --->>> ";
		else cout << "\t";
		cout << " �������� ��� � ���������� ��������" << endl;
		if (b == 2)
			cout << endl << " --->>> ";
		else cout << endl << "\t";
		cout << " ����� � �������� �������" << endl;

		cout << endl << " �������� ������� �������� - ";
		if (vr == 0)
			cout << " �� �� ���� �������";
		else cout << vr;

		hint();
		kl = _getch();
		if (kl == 115 && b < 2)
			b++;
		else if (kl == 115 && b == 2)
			b = 0;
		else if (kl == 119 && b > 0)
			b--;
		else if (kl == 119 && b == 0)
			b = 2;
		else if (kl == 13) {
			system("cls");
			if (b == 0)
				buy();
			else if (b == 1)
				password();
			else if (b == 2) {
				ofstream fout;
				fout.open("����������.txt");
				fout << endl << " �������� ������� �������� -  " << vr << " ���." << endl;
				fout << endl << "\t ������ ������ " << endl;
				fout << " �        ����� ������       ʳ������  ֳ�� " << endl;
				for (int j = 1; j < i; j++) {
					fout << fixed << setw(3) << left << kas[j].number << fixed << setw(25) << left << kas[j].nazva << fixed << setw(10) << left
						<< kas[j].kilkist << fixed << setw(7) << right << kas[j].price << endl;
				}
				fout.close();
				exit(0);
			}
		}
	} while (kl);
	return 0;
}

void  hint() {
	cout << endl << endl << endl << " ��� ������� ����������� �����, ������ ����������� �� �� 0!!! " << endl;
	cout << " ��� ����������� �� ������� - ������ 'W' i 'S" << endl;
	cout << " ��� ����� ��������, ��� ���� �������� ��������� ����!!! " << endl;
	cout << " ��� ������ ������ - ������ 'Enter'" << endl;
	cout << " ��� ����������  - ������ 'Esc'" << endl;
}

void password() {
	int p;
	cout << endl << " ������ ������, ��� ������� �� ��� ������ ������: ";
	inp_esc();
	p = atoi(st.c_str());
	if (kl == 27)
		return;
	else if (p == 3142)
		shop();
	else {
		cout << endl << " ������ �� �����!" << endl;
		Sleep(1000);
		return;
	}
}

void shop() {
	a = 0;
	do {
		system("cls");
		cout << endl << "\t\t �� �� ������ �������?" << endl;
		if (a == 0)
			cout << " --->>> ";
		else cout << "\t";
		cout << " 1.������� ��� ������ � ������" << endl;
		if (a == 1)
			cout << " --->>> ";
		else cout << "\t";
		cout << " 2.³����������� ��� ��� ������" << endl;
		if (a == 2)
			cout << " --->>> ";
		else cout << "\t";
		cout << " 3.�������� ������ �����" << endl;
		if (a == 3)
			cout << " --->>> ";
		else cout << "\t";
		cout << " 4.����������� ����������" << endl;
		if (a == 4)
			cout << " --->>> ";
		else cout << "\t";
		cout << " 5.����� � �������� ��� � ���������� ��������" << endl;
		hint();
		kl = _getch();
		if (kl == 115 && a < 4)
			a++;
		else if (kl == 115 && a == 4)
			a = 0;
		else if (kl == 119 && a > 0)
			a--;
		else if (kl == 119 && a == 0)
			a = 4;
		else if (kl == 13) {
			choice();
		}
	} while (kl);
}

void choice() {
	system("cls");
	if (a == 0)
		input_sp();
	else if (a == 1)
		change();
	else if (a == 2)
		remove();
	else if (a == 3)
		output_sp();
	else if (a == 4)
		main();
}

void input_sp() {
	do {
		system("Cls");
		cout << endl << " ������ ��� ��� �����:" << endl << endl;
		cout << " ����� ������ - ";
		inp_esc();
		if (kl == 27)
			continue;
		kas[i].nazva = st;
		kas[i].number = n++;
		cout << endl << " ʳ������ ������ - ";
		inp_esc();
		kas[i].kilkist = atoi(st.c_str());
		cout << endl << " ֳ�� ������ - ";
		inp_esc();
		kas[i].price = atoi(st.c_str());
		i++;
		cout << "\n\n ��� ���������� ����� �����, ������ Esc" << endl;
		cout << "\n ��� ����������� ����� �����, ������ Enter" << endl;
		kl = _getch();
	} while (kl != 27);
}

void change() {
	int c = 1, j;
	do {
		system("cls");
		cout << endl << "\t\t ������ ������ " << endl;
		cout << "\t �        ����� ������       ʳ������  ֳ�� " << endl;
		for (j = 1; j<i; j++) {
			if (c == j)
				cout << " --->>> ";
			else cout << "\t";
			cout << fixed << setw(3) << kas[j].number << fixed << setw(25) << kas[j].nazva << fixed << setw(10) << kas[j].kilkist << fixed
				<< setw(7) << kas[j].price << endl;
		}
		hint();
		kl = _getch();
		if (kl == 115 && c < i - 1)
			c++;
		else if (kl == 115 && c == i - 1)
			c = 1;
		else if (kl == 119 && c > 1)
			c--;
		else if (kl == 119 && c == 1)
			c = i - 1;
		else if (kl == 13) {
			int d = 0;
			do {
				system("cls");
				cout << endl << "\t\t �� �� ������ ������?" << endl;
				if (d == 0)
					cout << " --->>> ";
				else cout << "\t";
				cout << " �����" << endl;
				if (d == 1)
					cout << " --->>> ";
				else cout << "\t";
				cout << " ֳ��" << endl;
				if (d == 2)
					cout << " --->>> ";
				else cout << "\t";
				cout << " ������ ������� ������" << endl;
				hint();
				kl = _getch();
				if (kl == 115 && d < 2)
					d++;
				else if (kl == 115 && d == 2)
					d = 0;
				else if (kl == 119 && d > 0)
					d--;
				else if (kl == 119 && d == 0)
					d = 2;
				else if (kl == 13) {
					do {
						if (d == 0) {
							system("Cls");
							cout << endl << " ������ ���� ����� - ";
							inp_esc();
							if (kl == 27) {
								kl = 13;
								break;
							}
							kas[c].nazva = st;
							break;
						}
						if (d == 1) {
							system("Cls");
							cout << endl << " ������ ���� ���� - ";
							inp_esc();
							if (kl == 27) {
								kl = 13;
								break;
							}
							if (atoi(st.c_str()) != 0)
								kas[c].price = 0;
							kas[c].price += atoi(st.c_str());
							break;
						}
						else if (d == 2) {
							system("Cls");
							cout << endl << " ������, ��� ������� ������ ������ ��������� � ������� - ";
							inp_esc();
							if (kl == 27) {
								kl = 13;
								break;
							}
							kas[c].kilkist += atoi(st.c_str());
							break;
						}
					} while (kl != 27);
				}
			} while (kl != 27);
		}
		else if (kl == 27)
			break;
	} while (kl);
}

void remove() {
	int c = 1, j;
	do {
		system("cls");
		cout << endl << "\t\t ������� �����, ���� �� ������ ��������: " << endl;
		cout << "\t �        ����� ������       ʳ������  ֳ�� " << endl;
		for (j = 1; j<i; j++) {
			if (c == j)
				cout << " --->>> ";
			else cout << "\t";
			cout << fixed << setw(3) << kas[j].number << fixed << setw(25) << kas[j].nazva << fixed << setw(10) << kas[j].kilkist
				<< fixed << setw(7) << kas[j].price << endl;
		}
		hint();
		kl = _getch();
		if (kl == 115 && c < i - 1)
			c++;
		else if (kl == 115 && c == i - 1)
			c = 1;
		else if (kl == 119 && c > 1)
			c--;
		else if (kl == 119 && c == 1)
			c = i - 1;
		else if (kl == 13) {
			int d = 0;
			do {
				system("cls");
				cout << endl << "\t �� �������, �� ������ �������� � ������ ����� '" << kas[c].nazva << "' ?" << endl;
				if (d == 0)
					cout << " --->>> ";
				else cout << "\t";
				cout << " ���" << endl;
				if (d == 1)
					cout << " --->>> ";
				else cout << "\t";
				cout << " ͳ" << endl;
				hint();
				kl = _getch();
				if (kl == 115 && d < 1)
					d++;
				else if (kl == 115 && d == 1)
					d = 0;
				else if (kl == 119 && d > 0)
					d--;
				else if (kl == 119 && d == 0)
					d = 1;
				else if (kl == 13) {
					if (d == 0) {
						for (j = c; j < i; j++) {
							kas[j].nazva = kas[j + 1].nazva;
							kas[j].kilkist = kas[j + 1].kilkist;
							kas[j].price = kas[j + 1].price;
						}
						i--;
						n--;
						break;
					}
					else if (d == 1)
						break;
				}
			} while (kl != 27);
		}
		else if (kl == 27)
			break;
	} while (kl);
}

void output_sp() {
	cout << endl << "\t ������ ������ " << endl;
	cout << " �        ����� ������        ʳ������  ֳ�� " << endl;
	for (int j = 1; j<i; j++) {
		cout << fixed << setw(3) << kas[j].number << fixed << setw(25) << kas[j].nazva << fixed << setw(10) << kas[j].kilkist
			<< fixed << setw(7) << kas[j].price << endl;
	}
	_getch();
}

void inp_esc() {
	st = "";
	kl = _getch();
	while (kl != 13) {
		if (kl == 27)
			return;
		else
			st += char(kl);
		cout << char(kl);
		kl = _getch();
	}
}

void buy() {
	if (i == 1) {
		system("Cls");
		cout << endl << " �� �� ������� ������� ������ � ���������� ��������!!!";
		Sleep(2000);
	}
	else {
		int c = 0;
		do {
			system("cls");
			cout << endl << "\t ������� ���� � ������:" << endl << endl;
			if (c == 0)
				cout << " --->>> ";
			else cout << "\t";
			cout << " ������ ������ �� ������ " << endl;
			if (c == 1)
				cout << " --->>> ";
			else cout << "\t";
			cout << " ����������� ����� � ������ ���� " << endl;
			if (c == 2)
				cout << " --->>> ";
			else cout << "\t";
			cout << " ϳ��������� ������� " << endl;
			hint();
			kl = _getch();
			if (kl == 115 && c < 2)
				c++;
			else if (kl == 115 && c == 2)
				c = 0;
			else if (kl == 119 && c > 0)
				c--;
			else if (kl == 119 && c == 0)
				c = 2;
			else if (kl == 27)
				break;
			else if (kl == 13) {
				system("cls");
				if (c == 0)
					basket();
				else if (c == 1)
					seen();
				else if (c == 2) {
					if (sum == 0) {
						system("Cls");
						cout << endl << " ����� ���, �� ��������� �������, �����������, ���� �����, �����!!!";
						Sleep(2000);
						continue;
					}
					int d = 0;
					do {
						system("cls");
						cout << endl << " �������� ������� ��������� - " << sum << " ���." << endl;
						cout << endl << "\t\t ϳ��������� ������� ?" << endl << endl;
						if (d == 0)
							cout << " --->>> ";
						else cout << "\t";
						cout << " ���" << endl;
						if (d == 1)
							cout << " --->>> ";
						else cout << "\t";
						cout << " ͳ" << endl;
						hint();
						kl = _getch();
						if (kl == 115 && d < 1)
							d++;
						else if (kl == 115 && d == 1)
							d = 0;
						else if (kl == 119 && d > 0)
							d--;
						else if (kl == 119 && d == 0)
							d = 1;
						else if (kl == 13) {
							if (d == 0) {
								vr += sum;
								for (int j = 1; j < x; j++) {
									a = 1;
									while (kas[a].nazva != bas[j].nazva) {
										a++;
									}
									kas[a].kilkist -= bas[j].kilkist;
								}
								x = 1;
								z = 1;
								sum = 0;
								break;
							}
							else if (d == 1)
								break;
						}
					} while (kl != 27);
				}
			}
		} while (kl);
	}
	x = 1;
	sum = 0;
	z = 1;
}

void basket() {
	int c = 1, j, f;
	do {
		f = 0;
		system("cls");
		cout << endl << "\t\t ������ ������ " << endl;
		cout << "\t �        ����� ������       ʳ������ ֳ��" << endl;
		for (j = 1; j<i; j++) {
			if (c == j)
				cout << " --->>> ";
			else cout << "\t";
			cout << fixed << setw(3) << kas[j].number << fixed << setw(25) << kas[j].nazva << fixed << setw(10) << kas[j].kilkist
				<< fixed << setw(7) << kas[j].price << endl;
		}
		hint();
		kl = _getch();
		if (kl == 115 && c < i - 1)
			c++;
		else if (kl == 115 && c == i - 1)
			c = 1;
		else if (kl == 119 && c > 1)
			c--;
		else if (kl == 119 && c == 1)
			c = i - 1;
		else if (kl == 27)
			return;
		else if (kl == 13) {
			for (int j = 1; j < x; j++) {
				if (bas[j].nazva == kas[c].nazva) {
					system("Cls");
					cout << endl << " �� ��� ������ ��� ����� � �����!";
					Sleep(1000);
					f = 1;
				}
			}
			if (f == 1)
				continue;
			system("Cls");
			cout << endl << " ������, ��� ������� ������ ������ �� ������ �������� - ";
			inp_esc();
			do {
				if (atoi(st.c_str()) > kas[c].kilkist) {
					cout << endl << endl << " ���� ������� ������ ������ ���� � ��������!";
					cout << endl << " " << kas[c].kilkist << " - ������� ������ � ��������.";
					cout << endl << " ������ ���� ������� ��� ������ ������� ������ ������ ������� 'Esc' - ";
					inp_esc();
				}
			} while (atoi(st.c_str()) > kas[c].kilkist);
			if (kl == 27 || atoi(st.c_str()) == 0)
				continue;
			bas[x].number = z++;
			bas[x].kilkist = atoi(st.c_str());
			bas[x].nazva = kas[c].nazva;
			bas[x].price = kas[c].price;
			x++;
		}
	} while (kl);
}

void seen() {
	int c = 1, j, t = 0;
	do {
		system("cls");
		cout << endl << "\t ������ ������ � ������ " << endl;
		cout << "\t �        ����� ������       ʳ������  ֳ��  �������" << endl;
		for (j = 1; j < x; j++) {
			bas[j].cost = bas[j].kilkist*bas[j].price;
			if (c == j)
				cout << " --->>> ";
			else cout << "\t";
			cout << fixed << setw(3) << bas[j].number << fixed << setw(25) << bas[j].nazva << fixed << setw(10) << bas[j].kilkist
				<< fixed << setw(7) << bas[j].price << fixed << setw(9) << bas[j].cost << endl;
		}
		sum = 0;
		for (j = 1; j < x; j++) {
			sum += bas[j].cost;
		}
		if (sum >= 500) {
			sum = sum - (sum / 10);
			cout << endl << " � ����������� ������, �������� ������� ��������� - " << sum << " ���." << endl;
		}
		else
			cout << endl << " �������� ������� ��������� - " << sum << " ���." << endl;
		hint();

		kl = _getch();
		if (kl == 115 && c < x - 1)
			c++;
		else if (kl == 115 && c == x - 1)
			c = 1;
		else if (kl == 119 && c > 1)
			c--;
		else if (kl == 119 && c == 1)
			c = x - 1;
		else if (kl == 27)
			break;
		else if (kl == 13 && x != 1) {
			int d = 0;
			do {
				system("cls");
				cout << endl << "\t\t �� �� ������ ������?" << endl;
				if (d == 0)
					cout << " --->>> ";
				else cout << "\t";
				cout << " ʳ������ ������" << endl;
				if (d == 1)
					cout << " --->>> ";
				else cout << "\t";
				cout << " �������� ����� �� ������" << endl;
				hint();
				kl = _getch();
				if (kl == 115 && d < 1)
					d++;
				else if (kl == 115 && d == 1)
					d = 0;
				else if (kl == 119 && d > 0)
					d--;
				else if (kl == 119 && d == 0)
					d = 1;
				else if (kl == 27)
					break;
				else if (kl == 13) {
					if (d == 0) {
						system("Cls");
						cout << endl << " ������ ���� ������� ������ - ";
						inp_esc();
						a = 1;
						while (kas[a].nazva != bas[c].nazva) {
							a++;
						}
						do {
							if (atoi(st.c_str()) > kas[a].kilkist) {
								cout << endl << endl << " ���� ������� ������ ������ ���� � ��������!";
								cout << endl << " " << kas[a].kilkist << " - ������� ������ � ��������.";
								cout << endl << " ������ ���� ������� ��� ������ ���� ������� ������ ������ ������� 'Esc' - ";
								inp_esc();
							}
						} while (atoi(st.c_str()) > kas[a].kilkist);
						bas[c].kilkist = atoi(st.c_str());
					}
					else if (d == 1) {
						int d = 0;
						do {
							system("cls");
							cout << endl << "\t �� �������, �� ������ �������� ����� '" << bas[c].nazva << "' � ������  ?" << endl;
							if (d == 0)
								cout << " --->>> ";
							else cout << "\t";
							cout << " ���" << endl;
							if (d == 1)
								cout << " --->>> ";
							else cout << "\t";
							cout << " ͳ" << endl;
							hint();
							kl = _getch();
							if (kl == 115 && d < 1)
								d++;
							else if (kl == 115 && d == 1)
								d = 0;
							else if (kl == 119 && d > 0)
								d--;
							else if (kl == 119 && d == 0)
								d = 1;
							else if (kl == 13) {
								if (d == 0) {
									for (j = c; j < i; j++) {
										bas[j].nazva = bas[j + 1].nazva;
										bas[j].kilkist = bas[j + 1].kilkist;
										bas[j].price = bas[j + 1].price;
									}
									sum = -bas[j].price;
									x--;
									z--;
									break;
								}
								else if (d == 1)
									break;
							}
						} while (kl != 27);
						if (d == 0)
							break;
					}
				}
			} while (kl);
		}
	} while (kl);
}