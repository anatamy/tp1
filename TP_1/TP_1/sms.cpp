#include "sms.h"

sms_control::sms_control()
{
	file_load();
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
		sms temp(sms_from_, sms_to_, time_, text_);
		sms_list.push_back(temp);
	}
	file.close();
}

void sms_control::show()
{
	for (auto it = sms_list.begin(); it != sms_list.end(); it++)
	{
		cout << it->get_from()<<" " << it->get_to() << " " << it->get_time() << " " << it->get_text() << endl;
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

