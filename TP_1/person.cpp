#include "person.h"

person::person(string name_,string number_,string email_,bool favorite_)
{
	string check = number_.substr(4, 8);
	name = name_;
	number = number_;
	email = email_;
	favorite = favorite_;
	find_num = check;
}

void control::change_info(string name_, string check_) {
	for (auto it = people.begin(); it != people.end(); it++)
	{
		if ((*it)->get_name() == name_)
		{
			if (check_ == "e-mail") {
				cout << "Please input e-mail" << endl;
				string email_;
				cin >> email_;
				(*it)->set_email(email_);
				break;
			}
			else if (check_ == "number") {
				cout << "Please input number" << endl;
				string number_;
				cin >> number_;
				(*it)->set_number(number_);
				break;

			}
			else if (check_ == "favorite") {
				(*it)->set_favorite();
			}
			this->file_save();
			return ;
		}
	}
	this->file_save();
	return ;
}

control::control()
{
	this->file_load();
}

control::~control()
{
	file_save();
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

bool person::get_favorite()
{
	return favorite;
}

string person::get_find_num()
{
	return find_num;
}

void person::set_email(string email_)
{
email = email_;
}



void person::set_favorite()
{
	favorite = !favorite;
}

void person::set_number(string number_)
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
		bool favorite;
			file >> name >> number >> email>>favorite;
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
			person*  new_person=new person(name,number,email,favorite);
			people.push_back(new_person);
		}
		else
		{
			if ((*it)->get_number() != number)
			{
				(*it)->set_number(number);
			}
			if ((*it)->get_email() != email)
			{
				(*it)->set_email(email);
			}

		/*			int num = 0;
						cout << "There is someone who has same name" << endl << "is he same person?" << endl << "1.Yes" << endl << "2.No" << endl<<"Enter the number 1 or 2";
						cin >> num;
						if (num == 1)
						{
							if (it->get_number != number)
							{
								it->set_number(number);
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
	file.open("input.txt");
	for (auto it = people.begin(); it != people.end(); it++)
	{
		file << (*it)->get_name() << "\t" << (*it)->get_number() << "\t" << (*it)->get_email() << "\t"<<(*it)->get_favorite() << endl;
	}
	file.close();
}

void control::show()
{
	this->sort_();
	int i = 1;
	for (auto it = people.begin(); it != people.end(); it++, i++)
	{
		cout << i << ". " << (*it)->get_name() << "\t" << (*it)->get_number() << "\t" << (*it)->get_email() << endl;
	}
}
void control::show_favorite()
{
	this->sort_();
	int i = 1;
	for (auto it = people.begin(); it != people.end(); it++)
	{
		if ((*it)->get_favorite() == true)
		{
			cout << i << ". " << (*it)->get_name() << "\t" << (*it)->get_number() << "\t" << (*it)->get_email() << endl;
			i++;
		}
	}
}
bool comp(person *p1, person *p2)
{
	return p1->get_name() < p2->get_name();
}

void control::sort_()
{
	/*vector<string> temp;
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
	}*/
	sort(people.begin(), people.end(),comp);
}
void control::show(vector<person*>::iterator it)
{
	cout <<"His/Her name is" <<(*it)->get_name() << endl<<"His/Her number is" << (*it)->get_number() << endl<<"His/Her email is" << (*it)->get_email() << endl;
}

void control::add(string name,string number,string email)
{
	char check;
	bool favorite = false;
	if (name == "")
	{
		cout << "Error" << endl;
		name = "No_name";
	}
	if (number == "")
	{
		number = "No number";
	}
	if (email == "")
	{
		email == "No Email";
	}
	person* temp=new person(name, number, email,favorite);
	cout << "Do you want to add him/her to favorite list? (Y/N)" << endl;
	cin >> check;
	if (check == 'y' || check == 'Y')
	{
		temp->set_favorite();
	}
	else if (check == 'n' || check == 'N')
	{
	}
	else
	{
		cout << "Error" << endl;
	}

	people.push_back(temp);
	sort_();
	show();
}
int control::remove(string name_)
{
	for (auto it = people.begin(); it != people.end(); it++)
	{
		if ((*it)->get_name() == name_)
		{
			people.erase(it);
			return 1;
		}
	}
	return 0;
}
vector<person*>::iterator control::get_end_it()
{
	return people.end();
}
/*bool person::operator <(person p1)
{
	return this->get_name() < p1.get_name();
}*/

vector<person*>::iterator control::find_name(string name_)
{
	
	for (auto it=people.begin();it!=people.end();it++)
	{
		if ((*it)->get_name() == name_)
		{
			return it;
		}

	}
	return people.end();
}

vector<person*>::iterator control::find_number(string number_)
{
	vector<vector<person*>::iterator> list_p;
	for (auto it = people.begin(); it != people.end(); it++)
	{
		if (number_ == "")
		{
			number_ = "No number";
		}
		if ((*it)->get_number() == "No number")
		{
			return people.end();
		}
		if ((*it)->get_find_num() == number_.substr(4,8))
		{
			list_p.push_back(it);
		}
	}
	if (list_p.size() == 0)
	{
		return people.end();
	}
	else if (list_p.size() == 1)
	{
		return list_p[0];
	}
	else if (list_p.size() > 1)
	{
		
		for (auto it = list_p.begin(); it != list_p.end(); it++)
		{
			if ((*(*it))->get_number() == number_)
			{
				return (*it);
			}
		}
	}
	return people.end();
}
