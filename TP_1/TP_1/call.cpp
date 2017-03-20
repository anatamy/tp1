#include"call.h"
#include"person.h"

call_control::call_control()
{
	file_load();
}
call::call(string call_from_,string call_to_,string time_)
{
	call_from = call_from_;
	call_to = call_to_;
	time = time_;
}
string call::get_call_from()
{
	return this->call_from;
}
string call::get_call_to()
{
	return call_to;
}
string call::get_time()
{
	return time;
}
void call_control::file_load()
{
	ifstream file;
	file.open("call.txt");
	while (!file.eof())
	{
		
		string call_from;
		string call_to;
		string time;
		file >> call_from >> call_to >> time;
		if (time == "")	
		{
			time = "missed call";
		}
		call temp(call_from, call_to, time);
		call_list.push_back(temp);
	}
	file.close();
}

void call_control::show()
{
	for (auto it = call_list.begin(); it != call_list.end(); it++)
	{
		cout << it->get_call_from() << " " << it->get_call_to() << " " << it->get_time() << endl;
	}
}

string call_control::detail()
{
	return "asd";
}

