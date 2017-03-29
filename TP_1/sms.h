#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

class sms
{
public:
	sms(string sms_from_,string sms_to_,string time,string text);
	string get_from();
	string get_to();
	string get_time();
	string get_text();
private:
	string sms_from;
	string sms_to;
	string time;
	string text;
};
class sms_control
{
public:
	sms_control();
	void file_load();
	void file_save();
	void show();
	void show_history(string name_);
	void delete_history(string name_from_, string name_to_);
private:
	vector<sms*> sms_list;
};
