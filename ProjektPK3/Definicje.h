#pragma once
#include "Header.h"

// Deklaracja metod klasy Student

Student::Student(int id_, string pesel_, char* name_, char* surname_, string class_, string address_, char* phone_, int nr_)
{
	id = id_;
	pesel = pesel_;
	name = name_;
	surname = surname_;
	team = class_;
	address = address_;
	phone = phone_;
	nr = nr_;
}

int Student::get_id()
{
	return id;
}

string Student::get_pesel()
{
	return pesel;
}

string Student::get_class_()
{
	return team;
}

char* Student::get_name()
{
	return name;
}

char* Student::get_surname()
{
	return surname;
}

char* Student::get_phone()
{
	return phone;
}

string Student::get_address() 
{
	return address;
}

int Student::get_nr()
{
	return nr;
}

void Student::set_pesel(string pesel_)
{
	pesel = pesel_;
}

void Student::set_name(char* name_)
{
	name = name_;
}

void Student::set_surname(char* surname_)
{
	surname = surname_;
}

void Student::set_phone(char* phone_) 
{
	phone = phone_;
}

void Student::view()
{
	cout /*<< "ID: " << get_id() */<< " PESEL: " << get_pesel() << " Imie: " << get_name() << " Nazwisko: " << get_surname() << " Adres: " << get_address() <<
		" Numer domu: " << get_nr() << " Telefon:  " << get_phone() << endl;
}

//---------------------------------------------------------------------------------------

//Deklaracje metod struktury lista uczniów

student_list::student_list()
{
	first_u = 0;
}

void student_list::add_student(Student* st_)
{
	if (first_u == 0)
	{
		first_u = st_;
	}

	else
	{
		Student *temp = first_u;

		while (temp->next_u)
		{
			temp = temp->next_u;
		}
		temp->next_u = st_;
		st_->next_u = 0;
	}
}

void student_list::delete_student(int id_)
{
	if (id_ == 1)
	{
		Student* temp = first_u;
		first_u = temp->next_u;
	}
	else if (id_ >= 2)
	{
		int i = 1;
		Student *temp = first_u;
		while (temp)
		{
			if ((i + 1) == id_)
			{
				break;
			}
			temp = temp->next_u;
			++i;
		}
		if (temp->next_u->next_u == 0)
		{
			delete temp->next_u;
			temp->next_u = 0;
		}
		else
		{
			Student *del = temp->next_u;
			temp->next_u = temp->next_u->next_u;
			delete del;
		}
	}
}

void student_list::view()
{
	Student* temp = first_u;

	while (temp)
	{
		cout << *temp;
		temp = temp->next_u;
	}
}

int student_list::search(char* name_, char* surname_)
{
	Student* temp = first_u;
	int buff;
	while (temp)
	{
		if (strcmp(name_, temp->get_name())==0 && strcmp(surname_, temp->get_surname())==0)
		{
			buff = temp->get_id();
			return buff;
			break;
		}
		else temp = temp->next_u;
		return -1;
	}
	
}

string student_list::search_pesel(char* name_, char* surname_)
{
	Student* temp = first_u;
	string buff;
	while (temp)
	{
		if (strcmp(name_, temp->get_name()) == 0 && strcmp(surname_, temp->get_surname()) == 0)
		{
			buff = temp->get_pesel();
			return buff;
			break;
		}
		else temp = temp->next_u;
		return "Nie ma takiego ucznia";
	}

}

void student_list::view_adr(string addr_)
{
	Student* temp = first_u;
	while (temp)
	{
		if (addr_ == temp->get_address())
		{
			temp->view();
			temp = temp->next_u;
		}
		else temp = temp->next_u;
	}
}

//---------------------------------------------------------------------------------------

//Definicje metod klasy Grade

Grade::Grade(int id_, string pesel_, double grade_, string subject_, int day_, int month_, int year_)
{
	id = id_;
	pesel = pesel_;
	grade = grade_;
	subject = subject_;
	day = day_;
	month = month_;
	year = year_;
}

int Grade::get_id()
{
	return id;
}

string Grade::get_pesel()
{
	return pesel;
}

double Grade::get_grade()
{
	return grade;
}

string Grade::get_subject()
{
	return subject;
}

int Grade::get_day()
{
	return day;
}

int Grade::get_month()
{
	return month;
}

int Grade::get_year()
{
	return year;
}

void Grade::set_pesel(string pesel_)
{
	pesel = pesel_;
}

void Grade::set_grade(double grade_) 
{
	grade = grade_;
}

void Grade::set_subject(string subject_)
{
	subject = subject_;
}

void Grade::set_day(int day_)
{
	day = day_;
}

void Grade::set_month(int month_)
{
	month = month_;
}

void Grade::set_year(int year_)
{
	year = year_;
}

void Grade::view()
{
	cout << "PESEL: " << get_pesel() << " Ocena: " << get_grade() << " Przedmiot: " << get_subject() << endl;
}

//---------------------------------------------------------------------------------------

// Definicje metod struktury Lista ocen

grade_list::grade_list()
{
	first_o = 0;
}

void grade_list::add_grade(Grade *gr_)
{
	if (first_o == 0)
	{
		first_o = gr_;
	}

	else
	{
		Grade *temp = first_o;

		while (temp->next_o)
		{
			temp = temp->next_o;
		}
		temp->next_o = gr_;
		gr_->next_o = 0;
	}
}

void grade_list::view()
{
	Grade* temp = first_o;

	while (temp)
	{
		cout << *temp;
		temp = temp->next_o;
	}
}

void grade_list::delete_grade(int id_)
{
	if (id_ == 1)
	{
		Grade* temp = first_o;
		first_o = temp->next_o;
		delete temp;
	}
	else if (id_ >= 2)
	{
		int i = 1;
		Grade *temp = first_o;
		while (temp)
		{
			if ((i + 1) == id_)
			{
				break;
			}
			temp = temp->next_o;
			++i;
		}
		if (temp->next_o->next_o == 0)
		{
			delete temp->next_o;
			temp->next_o = 0;
		}
		else
		{
			Grade *del = temp->next_o;
			temp->next_o = temp->next_o->next_o;
			delete del;
		}
	}
}

void grade_list::view_grd(int year_s, int month_s, int day_s, int year_b, int month_b, int day_b)
{
	Grade* temp = first_o;

	while (temp)
	{
		if ((day_s <= temp->get_day() <= day_b) && (month_s <= temp->get_month() <= month_b) && (year_s <= temp->get_year() <= year_b))
		{
			cout << *temp;
			temp = temp->next_o;
		}
		else temp = temp->next_o;
	}
}

double grade_list::avg(string pesel_)
{
	Grade* temp = first_o;
	double sum = 0.0;
	double res = 0.0;
	int counter = 0;
	while (temp)
	{
		if (pesel_ == temp->get_pesel())
		{
			sum += temp->get_grade();
			++counter;
			temp = temp->next_o;
		}
		else temp = temp->next_o;
	}
	if (counter != 0) res = sum / counter;
	return res;
}

//---------------------------------------------------------------------------------------

// Pozosta³e funkcje

int data_start_s() {
	string id;
	fstream info;
	info.open("id_s.txt", ios::in);
	if (info.good()) {
		info >> id;
		info.close();
		stringstream chc(id);
		int ret;
		chc >> ret;
		return ret;
	}
	else {
		info.close();
		info.open("id_s.txt", ios::out);
		info << "1";
		info.close();
		return 1;
	}
}

int data_start_g() {
	string id;
	fstream info;
	info.open("id_g.txt", ios::in);
	if (info.good()) {
		info >> id;
		info.close();
		stringstream chc(id);
		int ret;
		chc >> ret;
		return ret;
	}
	else {
		info.close();
		info.open("id_s.txt", ios::out);
		info << "1";
		info.close();
		return 1;
	}
}

void save_ids(int id_s)
{
	fstream info;
	info.open("id_s.txt", ios::out | ios::trunc);
	info << id_s;
	info.flush();
	info.close();
}

void save_idg(int id_g)
{
	fstream info;
	info.open("id_g.txt", ios::out | ios::trunc);
	info << id_g;
	info.flush();
	info.close();
}

void save_stu(Student st)
{
	fstream info;
	info.open("students.txt", ios::app);
	if (info.good())
	{
		if (info.is_open())
		{
			info << st.get_id() << "\n";
			info << st.get_pesel() << "\n";
			info << st.get_name() << " " << st.get_surname() << " " << st.get_class_() << "\n";
			info << st.get_address() << " " << st.get_nr() << " " << st.get_phone() << "\n";
			info.close();
		}
	}
}

void save_grd(Grade gr)
{
	fstream info;
	info.open("grades.txt", ios::app);
	if (info.good())
	{
		if (info.is_open())
		{
			info << gr.get_id() << "\n";
			info << gr.get_pesel() << "\n";
			info << gr.get_grade() << " " << gr.get_subject() << "\n";
			info << gr.get_day() << "." << gr.get_month() << "." << gr.get_year() << "\n";
			info.close();
		}
	}
}

