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
		fin.open("Асортимент.txt");
		if (!fin.is_open()) {
			ofstream fout;
			fout.open("Асортимент.txt");
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
		cout << endl << "\t\t\t\t АКЦІЯ!!! " << endl;
		cout << endl << " При покупці товарів на суму від 500 гривень, ви отримуєте знижку - 10%!!! " << endl << endl;
		cout << endl << "\t\tВиберіть один з пунктів:" << endl << endl;
		if (b == 0)
			cout << " --->>> ";
		else cout << "\t";
		cout << " Обслуговування клієнтів " << endl;
		if (b == 1)
			cout << " --->>> ";
		else cout << "\t";
		cout << " Внесення змін в асортимент магазину" << endl;
		if (b == 2)
			cout << endl << " --->>> ";
		else cout << endl << "\t";
		cout << " Вийти з касового апарата" << endl;

		cout << endl << " Загальна виручка магазину - ";
		if (vr == 0)
			cout << " ще не було покупок";
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
				fout.open("Асортимент.txt");
				fout << endl << " Загальна виручка магазину -  " << vr << " грн." << endl;
				fout << endl << "\t Список товарів " << endl;
				fout << " №        Назва товару       Кількість  Ціна " << endl;
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
	cout << endl << endl << endl << " При введенні некоректних даних, апарат замінюватиме їх на 0!!! " << endl;
	cout << " Для пересування по пунктах - клавіші 'W' i 'S" << endl;
	cout << " При цьому слідкуйте, щоб була включена англійська мова!!! " << endl;
	cout << " Для вибору пункту - клавіша 'Enter'" << endl;
	cout << " Для повернення  - клавіша 'Esc'" << endl;
}

void password() {
	int p;
	cout << endl << " Введіть пароль, для доступу до змін списку товарів: ";
	inp_esc();
	p = atoi(st.c_str());
	if (kl == 27)
		return;
	else if (p == 3142)
		shop();
	else {
		cout << endl << " Пароль не вірний!" << endl;
		Sleep(1000);
		return;
	}
}

void shop() {
	a = 0;
	do {
		system("cls");
		cout << endl << "\t\t Що ви бажаєте зробити?" << endl;
		if (a == 0)
			cout << " --->>> ";
		else cout << "\t";
		cout << " 1.Занести нові товари в список" << endl;
		if (a == 1)
			cout << " --->>> ";
		else cout << "\t";
		cout << " 2.Відкоригувати дані про товари" << endl;
		if (a == 2)
			cout << " --->>> ";
		else cout << "\t";
		cout << " 3.Видалити певний товар" << endl;
		if (a == 3)
			cout << " --->>> ";
		else cout << "\t";
		cout << " 4.Переглянути асортимент" << endl;
		if (a == 4)
			cout << " --->>> ";
		else cout << "\t";
		cout << " 5.Вийти з внесення змін в асортимент магазину" << endl;
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
		cout << endl << " Введіть дані про товар:" << endl << endl;
		cout << " Назва товару - ";
		inp_esc();
		if (kl == 27)
			continue;
		kas[i].nazva = st;
		kas[i].number = n++;
		cout << endl << " Кількість товару - ";
		inp_esc();
		kas[i].kilkist = atoi(st.c_str());
		cout << endl << " Ціна товару - ";
		inp_esc();
		kas[i].price = atoi(st.c_str());
		i++;
		cout << "\n\n Для завершення вводу даних, нажміть Esc" << endl;
		cout << "\n Для продовження вводу даних, нажміть Enter" << endl;
		kl = _getch();
	} while (kl != 27);
}

void change() {
	int c = 1, j;
	do {
		system("cls");
		cout << endl << "\t\t Список товарів " << endl;
		cout << "\t №        Назва товару       Кількість  Ціна " << endl;
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
				cout << endl << "\t\t Що ви бажаєте змінити?" << endl;
				if (d == 0)
					cout << " --->>> ";
				else cout << "\t";
				cout << " Назву" << endl;
				if (d == 1)
					cout << " --->>> ";
				else cout << "\t";
				cout << " Ціну" << endl;
				if (d == 2)
					cout << " --->>> ";
				else cout << "\t";
				cout << " Додати кількість товару" << endl;
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
							cout << endl << " Введіть нову назву - ";
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
							cout << endl << " Введіть нову ціну - ";
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
							cout << endl << " Введіть, яку кількість даного товару доставили в магазин - ";
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
		cout << endl << "\t\t Виберіть товар, який ви бажаєте видалити: " << endl;
		cout << "\t №        Назва товару       Кількість  Ціна " << endl;
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
				cout << endl << "\t Ви впевнені, що бажаєте видалити зі списку товар '" << kas[c].nazva << "' ?" << endl;
				if (d == 0)
					cout << " --->>> ";
				else cout << "\t";
				cout << " Так" << endl;
				if (d == 1)
					cout << " --->>> ";
				else cout << "\t";
				cout << " Ні" << endl;
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
	cout << endl << "\t Список товарів " << endl;
	cout << " №        Назва товару        Кількість  Ціна " << endl;
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
		cout << endl << " Ще не внесено жодного товару в асортимент магазину!!!";
		Sleep(2000);
	}
	else {
		int c = 0;
		do {
			system("cls");
			cout << endl << "\t Виберіть один з пунктів:" << endl << endl;
			if (c == 0)
				cout << " --->>> ";
			else cout << "\t";
			cout << " Додати товари до кошика " << endl;
			if (c == 1)
				cout << " --->>> ";
			else cout << "\t";
			cout << " Переглянути кошик і внести зміни " << endl;
			if (c == 2)
				cout << " --->>> ";
			else cout << "\t";
			cout << " Підтвердити покупку " << endl;
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
						cout << endl << " Перед тим, як підвердити покупку, перегляньте, будь ласка, кошик!!!";
						Sleep(2000);
						continue;
					}
					int d = 0;
					do {
						system("cls");
						cout << endl << " Покупець повинен заплатити - " << sum << " грн." << endl;
						cout << endl << "\t\t Підтвердити покупку ?" << endl << endl;
						if (d == 0)
							cout << " --->>> ";
						else cout << "\t";
						cout << " Так" << endl;
						if (d == 1)
							cout << " --->>> ";
						else cout << "\t";
						cout << " Ні" << endl;
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
		cout << endl << "\t\t Список товарів " << endl;
		cout << "\t №        Назва товару       Кількість Ціна" << endl;
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
					cout << endl << " Ви вже додали цей товар у кошик!";
					Sleep(1000);
					f = 1;
				}
			}
			if (f == 1)
				continue;
			system("Cls");
			cout << endl << " Введіть, яку кількість даного товару ви бажаєте придбати - ";
			inp_esc();
			do {
				if (atoi(st.c_str()) > kas[c].kilkist) {
					cout << endl << endl << " Такої кількості даного товару немає в наявності!";
					cout << endl << " " << kas[c].kilkist << " - кількість товару в наявності.";
					cout << endl << " Введіть іншу кількість або відмініть покупку даного товару клавішею 'Esc' - ";
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
		cout << endl << "\t Список товарів у кошику " << endl;
		cout << "\t №        Назва товару       Кількість  Ціна  Вартість" << endl;
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
			cout << endl << " З врахуванням знижки, покупець повинен заплатити - " << sum << " грн." << endl;
		}
		else
			cout << endl << " Покупець повинен заплатити - " << sum << " грн." << endl;
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
				cout << endl << "\t\t Що ви бажаєте змінити?" << endl;
				if (d == 0)
					cout << " --->>> ";
				else cout << "\t";
				cout << " Кількість товару" << endl;
				if (d == 1)
					cout << " --->>> ";
				else cout << "\t";
				cout << " Видалити товар із кошика" << endl;
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
						cout << endl << " Введіть нову кількість товару - ";
						inp_esc();
						a = 1;
						while (kas[a].nazva != bas[c].nazva) {
							a++;
						}
						do {
							if (atoi(st.c_str()) > kas[a].kilkist) {
								cout << endl << endl << " Такої кількості даного товару немає в наявності!";
								cout << endl << " " << kas[a].kilkist << " - кількість товару в наявності.";
								cout << endl << " Введіть іншу кількість або відмініть зміну кілкьості даного товару клавішею 'Esc' - ";
								inp_esc();
							}
						} while (atoi(st.c_str()) > kas[a].kilkist);
						bas[c].kilkist = atoi(st.c_str());
					}
					else if (d == 1) {
						int d = 0;
						do {
							system("cls");
							cout << endl << "\t Ви впевнені, що бажаєте видалити товар '" << bas[c].nazva << "' з кошика  ?" << endl;
							if (d == 0)
								cout << " --->>> ";
							else cout << "\t";
							cout << " Так" << endl;
							if (d == 1)
								cout << " --->>> ";
							else cout << "\t";
							cout << " Ні" << endl;
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
