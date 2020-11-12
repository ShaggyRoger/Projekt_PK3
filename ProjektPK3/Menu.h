#pragma once
#include "Definicje.h"

void Menu::text() const
{
	cout << "Dziennik elektroniczny" << endl;
	cout << "Wybierz opcjê:" << endl;
	cout << "1. Zarz¹dzanie uczniem." << endl;
	cout << "2. Zarz¹dzanie ocenami." << endl;
	cout << "3. Oblicz œredni¹." << endl;
	cout << "4. Wyœwietlanie danych." << endl;
	cout << "5. Zamknij program" << endl;
}

int Menu::menu()
{
	text();
	string choice;
	cin >> choice;
	if (choice == "5") exit(0);
	while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
	{
		cout << "Niepoprawny wybór!\n";
		Sleep(2000);
		system("cls");
		text();
		cin >> choice;
	}
	stringstream int_chc(choice);
	int chc;
	int_chc >> chc;
	return chc;
}

void Menu::menu_back(int chc)
{
	static grade_list glist;
	static student_list slist;
	static int id_s = data_start_s();
	static int id_g = data_start_g();
	switch (chc)
	{
	case 1:
		{
			cout << "Wybierz operacjê:" << endl;
			cout << "1. Dodaj ucznia \n2. Usun ucznia \n3. Wyswietl uczniow \n4. Powrót" << endl;
			int fp;
			cin >> fp;
			switch (fp)
			{
			case 1:
				{
					string pesel_, class_, address_;
					char* name_ = (char*)malloc(sizeof(char) * 20);
					char* surname_ = (char*)malloc(sizeof(char) * 30);
					char* phone_ = (char*)malloc(sizeof(char) * 9);
					int nr_;
					cout << "Podaj numer PESEL: ";
					cin >> pesel_;
					cout << "\nPodaj imiê: ";
					cin >> name_;
					cout << "\nPodaj nazwisko: ";
					cin >> surname_;
					cout << "\nPodaj klasê: ";
					cin >> class_;
					cout << "\nPodaj adres: ";
					cin >> address_;
					cout << "\nPodaj numer domu: ";
					cin >> nr_;
					cout << "\nPodaj numer telefonu: ";
					cin >> phone_;
					Student st(id_s, pesel_, name_, surname_, class_, address_, phone_, nr_);
					++id_s;
					save_ids(id_s);
					save_stu(st);
					Student *stptr = &st;
					slist.add_student(stptr);
					slist.view();
					Sleep(4000);					
					system("cls");
					menu_back(menu());
				}
				break;
			case 2:
				{
					char* name_d = new char[30];
					char* surname_d = new char[20];
					cout << "Podaj dane ucznia: \nImiê: ";
					cin >> name_d;
					cout << "\nNazwisko: ";
					cin >> surname_d;
					int buff;
					buff = slist.search(name_d, surname_d);
					slist.delete_student(buff);
					Sleep(3000);
					system("cls");
					menu_back(menu());
				}
				break;
			case 3:
				{
					slist.view();
					Sleep(3000);
					menu_back(menu());
				}
				break;
			case 4:
				{
					system("cls");
					menu_back(menu());
				}
				break;
			default:
				{
					system("cls");
					menu_back(menu());
				}
			}
		}
		break;
	case 2:
	{
		cout << "Wybierz operacjê:" << endl;
		cout << "1. Dodaj ocenê \n2. Usun ocenê \n3. Wyswietl uoceny \n4. Powrót" << endl;
		int fp;
		cin >> fp;
		switch (fp)
		{
		case 1:
		{
			int day_, month_, year_;
			double grade_;
			string pesel_, subject_;
			char* name_d = new char[30];
			char* surname_d = new char[20];
			cout << "Podaj dane ucznia: \nImiê: ";
			cin >> name_d;
			cout << "\nNazwisko: ";
			cin >> surname_d;
			pesel_ = slist.search_pesel(name_d, surname_d);
			cout << "Podaj dane na temat oceny" << endl;
			cout << "Podaj ocenê ucznia: ";
			cin >> grade_;
			cout << "Podaj przedmiot: ";
			cin >> subject_;
			cout << "Podaj dzieñ: ";
			cin >> day_;
			cout << "Podaj miesi¹c: ";
			cin >> month_;
			cout << "Podaj rok: ";
			cin >> year_;
			Grade gd(id_g, pesel_, grade_, subject_, day_, month_, year_);
			++id_g;
			save_idg(id_g);
			save_grd(gd);
			Grade *gdptr = &gd;
			glist.add_grade(gdptr);
			glist.view();
			Sleep(3000);
			system("cls");
			menu_back(menu());
		}
		break;
		case 2:
		{
			char* name_d = new char[30];
			char* surname_d = new char[20];
			cout << "Podaj dane ucznia: \nImiê: ";
			cin >> name_d;
			cout << "\nNazwisko: ";
			cin >> surname_d;
			int buff;
			buff = slist.search(name_d, surname_d);
			glist.delete_grade(buff);
			Sleep(3000);
			system("cls");
			menu_back(menu());
		}
		break;
		case 3:
		{
			glist.view();
			Sleep(3000);
			menu_back(menu());
		}
		break;
		default:
		{
			system("cls");
			menu_back(menu());
		}
		}
	}
		break;
	case 3:
		{
			char* name_d = new char[30];
			char* surname_d = new char[20];
			cout << "Podaj dane ucznia: \nImiê: ";
			cin >> name_d;
			cout << "\nNazwisko: ";
			cin >> surname_d;
			string buff;
			buff = slist.search_pesel(name_d, surname_d);
			if (buff == "Nie ma takiego ucznia")
			{
				cout << buff;
				Sleep(3000);
				system("cls");
				menu_back(menu());
			}
			else
			{
				double sr = glist.avg(buff);
				cout << "Srednia wybranego ucznia to: " << sr;
				Sleep(3000);
				system("cls");
				menu_back(menu());
			}
		}
		break;
	case 4:
	{
		int ch4;
		cout << "Wybierz dzia³anie" << endl;
		cout << "1. Wyœwietl uczniów ¿yj¹cych przy tej samej ulicy\n2. Wyœwietl oceny w przedziale czasowym" << endl;
		cin >> ch4;
		switch (ch4)
		{
		case 1:
		{
			string st_;
			cout << "Podaj ulicê: ";
			cin >> st_;
			slist.view_adr(st_);
			Sleep(3000);
			system("cls");
			menu_back(menu());
		}
		break;
		case 2:
		{
			int day_s, month_s, year_s, day_b, month_b, year_b;
			cout << "Szukaj ocen od " << endl;
			cout << "Roku: ";
			cin >> year_s;
			cout << "Miesi¹ca: ";
			cin >> month_s;
			cout << "Dnia: ";
			cin >> day_s;
			cout << "Do dnia ";
			cin >> day_b;
			cout << "Miesi¹ca: ";
			cin >> month_b;
			cout << "Roku: ";
			cin >> year_b;
			glist.view_grd(year_s, month_s, day_s, year_b, month_b, day_b);
			Sleep(5000);
			system("cls");
			menu_back(menu());
		}
		break;
	default:
		{
			system("cls");
			menu_back(menu());
		}
		}
	}
	default:
		{
			system("cls");
			menu_back(menu());
		}
	}
}