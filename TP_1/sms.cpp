#include "sms.h"
#include "person.h"

sms_control::sms_control()
{
	file_load();
}
void sms_control::show_history(string name_) {
	for (auto it = sms_list.begin(); it != sms_list.end(); it++) {
		if (name_ == (*it)->get_to()) {
			cout << (*it)->get_from() << (*it)->get_time() << (*it)->get_text() << endl;
		}
	}
}

void sms_control::delete_history(string name_from_, string name_to_) {
	for (auto it = sms_list.begin(); it != sms_list.end(); it++) {
		if (name_from_ == (*it)->get_from() && name_to_ == (*it)->get_to()) {
			cout << (*it)->get_from() << " " << (*it)->get_to() << " " << (*it)->get_time() << " " << (*it)->get_text() << endl;
			cout << "Is this history right?? " << endl;
			cout << "please answer (Y/n)";
			string check;
			cin >> check;
			if (check == "y" || check == "Y") {
				sms_list.erase(it);
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

void sms_control::file_load()
{
	ifstream file;
	file.open("sms.txt");
	string sms_from_;
	string sms_to_;
	string time_;
	string text_;
	while (!file.eof())
	{
		
		file >> sms_from_ >> sms_to_ >> time_ >>text_;
		if (sms_from_ == "")
		{
			break;
		}
		sms* temp=new sms(sms_from_, sms_to_, time_, text_);
		sms_list.push_back(temp);
	}
	file.close();
}

void sms_control::show()
{
	for (auto it = sms_list.begin(); it != sms_list.end(); it++)
	{
		cout << (*it)->get_from()<<" " << (*it)->get_to() << " " << (*it)->get_time() << " " << (*it)->get_text() << endl;
	}
}

sms::sms(string sms_from_, string sms_to_, string time_, string text_)
{
	sms_from = sms_from_;
	sms_to = sms_to_;
	time = time_;
	text = text_;
}

string sms::get_from()
{
	return sms_from;
}

string sms::get_to()
{
	return sms_to;
}

string sms::get_time()
{
	return time;
}

string sms::get_text()
{
	return text;
}

void sms_control::file_save() {
	ofstream file;
	file.open("sms.txt");
	for (auto it = sms_list.begin(); it != sms_list.end(); it++)
	{
		file << (*it)->get_from() << "\t" << (*it)->get_to() << "\t" << (*it)->get_time() << "\t" << (*it)->get_text() << endl;
	}
	file.close();
}
