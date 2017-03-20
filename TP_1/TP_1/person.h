#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

class person
{
public:
	person(string name_, string number_, string email_);
	string get_name();
	string get_number();	
	string get_email();
	void set_numer(string number_);
	void set_email(string email_);
	bool operator <(person p1);
private:
	string name;
	string number;
	string email;
};

class control
{
public:
	
	 void file_load();
	 void file_save();
	 void show();
	 void sort_();
	 void add();
	 void remove(string name_);
	 vector<person>::iterator find_name(string name_);
	 vector<person>::iterator find_number(string number_);
private:
	vector<person> people;
};