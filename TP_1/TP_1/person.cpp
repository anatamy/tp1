#include "person.h"

person::person(string name_,string number_,string email_)
{
	name = name_;
	number = number_;
	email = email_;
}

control::control()
{
	this->file_load();
}


string person::get_name()
{
	return name;
}

string person::get_number()
{
	return number;
}

string person::get_email()
{
	return email;
}

void person::set_email(string email_)
{
email = email_;
}

void person::set_numer(string number_)
{
	number = number_;
}


void control::file_load()
{
	ifstream file;
	file.open("input.txt");
	while (!file.eof())
	{
		string name;
		string number;
		string email;
		file >> name >> number >> email;
		if (name == "")
		{
			break;
		}
		if (number == "")
		{
			number = "No number";
		}
		if (email == "")
		{
			email = "No email";
		}
		auto it = find_name(name);
		if (it == people.end())
		{
			person new_person(name, number, email);
			people.push_back(new_person);
		}
		else
		{
			if (it->get_number() != number)
			{
				it->set_numer(number);
			}
			if (it->get_email() != email)
			{
				it->set_email(email);
			}

			/*			int num = 0;
						cout << "There is someone who has same name" << endl << "is he same person?" << endl << "1.Yes" << endl << "2.No" << endl<<"Enter the number 1 or 2";
						cin >> num;
						if (num == 1)
						{
							if (it->get_number != number)
							{
								it->set_numer(number);
							}
							if (it->get_email != email)
							{
								it->set_email(email);
							}
						}
						else if (num == 2)
						{
							name = name.append("1");
							person new_person(name, number, email);
							people.push_back(new_person);
						}*/
		}

	}
	file.close();
}

void control::file_save()
{
	ofstream file;
	file.open("output.txt");
	for (auto it = people.begin(); it != people.end(); it++)
	{
		file << it->get_name() << "\t" << it->get_number() << "\t" << it->get_email() << "\t" << endl;
	}
	file.close();

}

void control::show()
{
	this->sort_();
	int i = 1;
	for (auto it = people.begin(); it != people.end(); it++, i++)
	{
		cout << i << ". " << it->get_name() << "\t" << it->get_number() << "\t" << it->get_email() << endl;
	}
}

void control::sort_()
{
	vector<string> temp;
	for (auto it = people.begin(); it != people.end(); it++)
	{
		temp.push_back(it->get_name());
	}
	sort(temp.begin(), temp.end());
	vector<person> temp_p;
	for (auto it = temp.begin(); it != temp.end(); it++)
	{
		auto it_p = find_name(*it);
		person new_person(it_p->get_name(), it_p->get_number(), it_p->get_email());
		temp_p.push_back(new_person);
	}
	people.clear();
	for (auto it = temp_p.begin(); it != temp_p.end(); it++)
	{
		people.push_back((*it));
	}
}

vector<person>::iterator control::find_name(string name_)
{
	
	for (auto it=people.begin();it!=people.end();it++)
	{
		if (it->get_name() == name_)
		{
			return it;
		}

	}
	return people.end();
}

vector<person>::iterator control::find_number(string number_)
{
	for (auto it = people.begin(); it != people.end(); it++)
	{
		if (it->get_number == number_)
		{
			return it;
		}
	}
	return people.end();
}
