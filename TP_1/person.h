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
	person(string name_, string number_, string email_,bool favorite_);
	string get_name();
	string get_number();	
	string get_email();
	bool get_favorite();
	void set_numer(string number_);
	void set_email(string email_);
	void set_favorite();
private:
	string name;
	string number;
	string email;
	bool favorite = false;
};

class control
{
public:
	control();
	~control();
	 void file_load();
	 void file_save();
	 void show();
	 void show_favorite();
	 void sort_();
	 void show(vector<person*>::iterator it);
	 void add(string name,string number,string email);
	 int remove(string name_);
	 vector<person*>::iterator get_end_it();
	 vector<person*>::iterator find_name(string name_);
	 vector<person*>::iterator find_number(string number_);
private:
	vector<person*> people;
};