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
	void show();
private:
	vector<sms*> sms_list;
};
