#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
class time_type{
public:
	int year, month, day, hour, minute, second;
	bool call_ox;
	friend ostream& operator<< (ostream& os, time_type time);
	time_type(string time);
	time_type();
};
class call
{
public:
	call(string call_from_, string call_to_, string time_from_, string time_to_);
	string get_call_from();
	string get_call_to();
	time_type get_time_from();
	time_type get_time_to();
private:
	string call_from;
	string call_to;
	string time_from_s;
	string time_to_s;
	time_type time_from;
	time_type time_to;
};

class call_control
{
public:
	call_control();
	void file_load();
	void file_save();
	void show();
	void detail(string name_);
	void delete_history(string name_from_, string name_to_);
private:
	vector<call*> call_list;

};

