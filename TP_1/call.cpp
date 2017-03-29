#include"call.h"
#include"person.h"

call_control::call_control()
{
	file_load();
}
time_type::time_type() {
	year = month = day = hour = minute = second = 0;
}
time_type::time_type(string time) { //2017.03.14.21:39:04
	int found;
	bool check = false;
	found = time.find(".");
	if (found != string::npos) {
		year = stoi(time.substr(0, found));
		time = time.substr(found+1);
		check = true;
	}
	found = time.find(".");
	if (found != string::npos && check) {
		month = stoi(time.substr(0, found));
		time = time.substr(found+1);
		check = true;
	}
	found = time.find(".");
	if (found != string::npos && check) {
		day = stoi(time.substr(0, found));
		time = time.substr(found + 1);
		check = true;
	}
	found = time.find(":");
	if (found != string::npos && check) {
		hour = stoi(time.substr(0, found));
		time = time.substr(found + 1);
		check = true;
	}
	found = time.find(":");
	if (found != string::npos && check) {
		minute = stoi(time.substr(0, found));
		time = time.substr(found + 1);
		check = true;
	}
	if (check) second = stoi(time);

}
call::call(string call_from_,string call_to_,string time_from_, string time_to_) {
	call_from = call_from_;
	call_to = call_to_;
	time_from = time_type(time_from_);
	time_to = time_type(time_to_);
}
string call::get_call_from()
{
	return this->call_from;
}
string call::get_call_to()
{
	return this->call_to;
}
time_type call::get_time_from() {
	return time_from;
}
time_type call::get_time_to() {
	return time_to;
}
void call_control::file_load()
{
	ifstream file;
	file.open("call.txt");
	while (!file.eof())
	{
		
		string call_from;
		string call_to;
		string time_from;
		string time_to;
		bool call_ox;
		file >> call_from >> call_to >> time_from >> time_to;
		if (time_from == "")	
		{
			call_ox = false;
		}
		call* temp=new call(call_from, call_to, time_from, time_to);
		call_list.push_back(temp);
	}
	file.close();
}
ostream& operator<< (ostream& os, time_type time) {
	os << time.year << "." << time.month << "." << time.day << "." << time.hour << ":" << time.minute << ":" << time.second << " ";
	return os;
}
void call_control::show()
{
	for (auto it = call_list.begin(); it != call_list.end(); it++)
	{
		cout << (*it)->get_call_from() << " " << (*it)->get_call_to() << " " << (*it)->get_time_from() << (*it)-> get_time_to()<< endl;
	}
}

void call_control::detail(string name_)
{
	for (auto it = call_list.begin(); it != call_list.end(); it++) {
		if (name_ == (*it)->get_call_to()) {
			cout << (*it)->get_call_from() << (*it)->get_time_from() << (*it)->get_time_to() << endl;
		}
	}
}

void call_control::delete_history(string name_from_, string name_to_) {
	for (auto it = call_list.begin(); it != call_list.end(); it++) {
		if (name_to_ == (*it)->get_call_to() && name_from_ == (*it)->get_call_from()) {
			cout << (*it)->get_call_from() <<" " << (*it)->get_call_to() <<" "<< (*it)->get_time_from() <<" "<< (*it)->get_time_to() << endl;
			cout << "Is this history right?? " << endl;
			cout << "please answer (Y/n)";
			string check;
			cin >> check;
			if (check == "y" || check == "Y") {
				call_list.erase(it);
				break;
			}
			else {
				cout << "do you want to exit this section? (Y/n)" << endl;
				cin >> check;
				if (check == "y" || check == "Y") {
					return;
				}
			}
		}
	}
	this->file_save();
}

void call_control::file_save() {
	ofstream file;
	file.open("call.txt");
	for (auto it = call_list.begin(); it != call_list.end(); it++)
	{
		file << (*it)->get_call_from() << "\t" << (*it)->get_call_to() << "\t" << (*it)->get_time_from() << "\t" << (*it)->get_time_to() << endl;
	}
	file.close();
}

