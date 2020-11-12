#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class Menu
{
private:
	void text() const;
public:
	int menu();
	void menu_back(int chc);
};

class Record
{
public:
	virtual string get_pesel()=0;
};

class Student : public Record
{
	string pesel;
	char* name;
	char* surname;
	string team;
	string address;
	int nr;
	char* phone;
	int id;
public:
	Student *next_u;
	Student(int id_, string pesel_, char* name_, char* surname_, string class_, string address_, char* phone_, int nr_);
	~Student() {};
	int get_id();
	string get_pesel();
	string get_class_();
	char* get_name();
	char* get_surname();
	char* get_phone();
	string get_address();
	int get_nr();
	void set_pesel(string pesel_);
	void set_name(char* name_);
	void set_surname(char* surname_);
	void set_phone(char* phone_);
	void view();
	friend ostream& operator<< (ostream& os, Student st_)
	{
		cout << "PESEL: " << st_.get_pesel() << " Imie: " << st_.get_name() << " Nazwisko: " << st_.get_surname() << " Adres: " << st_.get_address() <<
			" Numer domu: " << st_.get_nr() << " Telefon:  " << st_.get_phone() << endl;
		return cout;
	}
};

class Grade : public Record
{
	int id;
	string pesel;
	double grade;
	string subject;
	int day;
	int month;
	int year;
public:
	Grade *next_o;
	Grade(int id_, string pesel_, double grade_, string subject_, int day_, int month_, int year_);
	~Grade() {};
	int get_id();
	string get_pesel();
	double get_grade();
	string get_subject();
	int get_day();
	int get_month();
	int get_year();
	void set_pesel(string pesel_);
	void set_grade(double grade_);
	void set_subject(string subject_);
	void set_day(int day_);
	void set_month(int month_);
	void set_year(int year_);
	void view();
	friend ostream& operator<< (ostream& os, Grade& gd_)
	{
		cout << "PESEL: " << gd_.get_pesel() << " Ocena: " << gd_.get_grade() << " Przedmiot: " << gd_.get_subject() << "Data: " << gd_.get_day() << "." << 
			gd_.get_month() << "." << gd_.get_year() <<endl;
		return cout;
	}
};

struct student_list 
{
	Student *first_u;
	void add_student(Student *st_);
	void delete_student(int id_);
	student_list();
	void view();
	int search(char* name_, char* surname_);
	void view_adr(string address_);
	string search_pesel(char* name_, char* surname_);
};

struct grade_list 
{
	Grade *first_o;
	grade_list();
	void add_grade(Grade *gr_);
	void delete_grade(int id_);
	void view();
	void view_grd(int year_s, int month_s, int day_s, int year_b, int month_b, int day_b);
	double avg(string pesel_);
};