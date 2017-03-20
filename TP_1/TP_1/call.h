#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

class call_control
{
public:
	call_control();
	void file_load();
	void show();
	string detail();
private:
	vector<call> call_list;

};

class call
{
public:
	call(string call_from_, string call_to_, string time_);
	string get_call_from();
	string get_call_to();
	string get_time();
private:
	string call_from;
	string call_to;
	string time;
};