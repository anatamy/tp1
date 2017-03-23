#include<iostream>
#include<fstream>
#include"sms.h"
#include"call.h"
#include "person.h"

int main()
{
	control cont;

	while (true)
	{
		int menu;
		cout << "This is Addressbook" << endl;
		cout << "Choose number which you want to do" << endl;
		cout << "1.Address" << endl;
		cout << "2.Call History" << endl;
		cout << "3.SMS" << endl;
		cout << "4.Exit" << endl;
		cin >> menu;
		if (menu == 1)
		{
			while (true)
			{
				int menu_a;
				cout << "This is Address book section" << endl;
				cout << "Choose number which you want to do" << endl;
				cout << "1.Add" << endl;
				cout << "2.Show" << endl;
				cout << "3.Delete" << endl;
				cout << "4.Find" << endl;
				cout << "5.Favorite" << endl;
				cout << "6.Exit" << endl;
				cin >> menu_a;
				if (menu_a == 1)
				{

					while (true)
					{
						char check;
						string name;
						string number;
						string email;
						cout << "This is Adding section" << endl;
						cout << "what is his/her name?" << endl;
						cin >> name;
						cout << "what is his/her number?" << endl;
						cin >> number;
						cout << "what is his/her email?" << endl;
						cin >> email;
						cont.add(name, number, email);
						cout << "Do you want to add more (Y/N)" << endl;
						cin >> check;
						if (check == 'y' ||check== 'Y')
						{

						}
						else if(check=='n'||check=='N')
						{
							cout << "return to Address section" << endl;
							break;
						}
						else
						{
							cout << "Error" << endl;
							break;
						}
					}
				}
				else if (menu_a == 2)
				{
					int check;
					cout << "1. List all entries" << endl;
					cout << "2. List only favorite entries" << endl;
					cin >> check;
					if (check == 1)
					{
						cont.show();
					}
					else if (check == 2)
					{
						cont.show_favorite();
					}
					else
					{
						cout << "Error";
					}

				}
				else if (menu_a == 3)
				{
					cout << "This is Deleting section" << endl;
					while (true)
					{
						string name;
						char check;
						cout << "Enter his/her name" << endl;
						cin >> name;
						int check_a=cont.remove(name);
						if (check_a != 1)
						{
							cout << "Error! He/She is not in Address book" << endl;
						}
						cout << "Do you want to delete more? (Y/N)" << endl;
						cin >> check;
						if (check == 'y' || check == 'Y')
						{

						}
						else if (check == 'n' || check == 'N')
						{
							cout << "return to Address section" << endl;
							break;
						}
						else
						{
							cout << "Error" << endl;
							break;
						}
					}
				}
				else if (menu_a == 4)
				{
					cout << "This is Finding section" << endl;
					cout << "1.Find with name" << endl;
					cout << "2.Find with number" << endl;
					int num;
					cin >> num;
					if (num == 1)
					{
						string name;
						cout << "Enter His/Her name" << endl;
						cin >> name;
						auto it=cont.find_name(name);
						if (it == cont.get_end_it())
						{
							cout << "Error He/She is not in address book" << endl;
						}
						else
						{
							cont.show(it);
						}
					}
					if (num == 2)
					{
						string number;
						cout << "Enter His/Her number" << endl;
						cin >> number;
						auto it = cont.find_number(number);
						if (it == cont.get_end_it())
						{
							cout << "Error He/She is not in address book" << endl;
						}
						else
						{
							cont.show(it);
						}
					}
				}
				else if (menu_a == 5)
				{
					string name;
					char check;
					cout << "Enter his/her name" << endl;
					cin >> name;
					auto it = cont.find_name(name);
					if ((*it)->get_favorite() == true)
					{
						cout << "He/She is on the list" << endl << "Do you want to remove him/her from list? (Y/N)" << endl;
						cin >> check;
						if (check == 'y' || check == 'Y')
						{
							(*it)->set_favorite();
							cout << "OK now he/she is not on the list" << endl;
						}
						else if (check == 'n' || check == 'N')
						{
	
						}
						else
						{
							cout << "Error" << endl;
						}
					}
					else
					{

						cout << "He/She is not on the list" << endl << "Do you want to add him/her to list? (Y/N)" << endl;
						cin >> check;
						if (check == 'y' || check == 'Y')
						{
							(*it)->set_favorite();
							cout << "OK now he/she is on the list" << endl;
						}
						else if (check == 'n' || check == 'N')
						{

						}
						else
						{
							cout << "Error" << endl;
						}
					}
				}
				else if (menu_a == 6)
				{
					cout << "return to main" << endl;
					break;
				}
				else
				{
					cout << "Error" << endl;
					break;
				}
			}
	
		}
		else if (menu == 2)
		{
			cout << "This is Call History section" << endl;

		}
		else if (menu == 3)
		{
			cout << "This is SMS section" << endl;
		}
		else if (menu == 4)
		{
			break;
		}
		else
		{
			cout << "Error" << endl;
			break;
		}
	}
	return 0;
}