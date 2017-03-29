#include<iostream>
#include<fstream>
#include"sms.h"
#include"call.h"
#include "person.h"

int main()
{
	control cont;
	call_control call_cont;
	sms_control sms_cont;
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
				cout << "6.Change one's information" << endl;
				cout << "7.Exit" << endl;
				cin >> menu_a;
				if (menu_a == 1)
				{

					while (true)
					{
						char check;
						string name;
						string number;
						string email;
						bool error = false;
						cout << "This is Adding section" << endl;
						cout << "what is his/her name?" << endl;
						cin >> name;
						cout << "what is his/her number?" << endl;
						cin >> number;
						if (number.size() != 13) {
							cout << "Check the number size or check '-' sign" << endl;
							break;
						}
						for (int i = 0; i < 13; i++) {
							if (number[i] < '0' && number[i] > '9' && number[i] != '-') {
								cout << "Check the number" << endl;
								error = true;
								break;
							}
						}
						if (error == true) {
							break;
						}
						cout << "what is his/her email?" << endl;
						cin >> email;
						int cnt = 0;
						for (int i = 0; i < 13; i++) {
							if (number[i] == '@' || number[i] == '.') {
								cnt++;
							}
						}
						if (cnt != 2) {
							cout << "Check the e-mail" << endl;
							break;
						}
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
						if (number.size() != 13) {
							cout << "Check the number" << endl;
							break;
						}
						for (int i = 0; i < 13; i++) {
							if (number[i] < '0' && number[i] > '9' && number[i] != '-') {
								cout << "Check the number" << endl;
								break;
							}
						}
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
				else if (menu_a == 6) {
					string name;
					cout << "who's information?? please give one's name!!" << endl;
					cin >> name;
					auto it = cont.find_name(name);
					if (it == cont.get_end_it()) {
						cout << "Check name" << endl;
						break;
					}
					else {
						cout << "Which information do you want to change?" << endl;
						cout << "number, e-mail, favorite" << endl;
						string check;
						cin >> check;
						if (check == "number" || check == "e-mail" || check == "favorite") {
							cont.change_info(name, check);
						}
 					}

				}
				else if (menu_a == 7)
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
			while (true) {
				cout << "This is Call History section" << endl;
				cout << "Choose which you want to do" << endl;
				cout << "1. Show Call History" << endl;
				cout << "2. Show someone's History" << endl;
				cout << "3. Delete someone's History" << endl;
				cout << "4. Return to Home" << endl;
				int menu_b;
				cin >> menu_b;
				if (menu_b == 1) {
					call_cont.show();
				}
				else if (menu_b == 2) {
					string name;
					cout << "who's history?" << endl;
					cin >> name;
					auto it = cont.find_name(name);
					if (it == cont.get_end_it()) {
						cout << "Check name" << endl;
					}
					else {
						call_cont.detail(name);
					}
				}
				else if (menu_b == 3) {
					cout << "Please type from, to" << endl;
					string name_from, name_to;
					cin >> name_from >> name_to;
					auto it = cont.find_name(name_to);
					auto it2 = cont.find_name(name_from);
					if (it == cont.get_end_it() && it2 == cont.get_end_it()) {
						cout << "Check name" << endl;
					}
					else {
						call_cont.delete_history(name_from, name_to);
					}
				}
				else if (menu_b == 4) {
					cout << "goto main menu" << endl;
					break;
				}
				else {
					cout << "Please check menu" << endl;
				}
			}
		}
		
		else if (menu == 3)
		{
			while (true) {
				cout << "This is SMS section" << endl;
				cout << "Choose which you want to de" << endl;
				cout << "1. Show SMS History" << endl;
				cout << "2. Find someone's history" << endl;
				cout << "3. Delete History" << endl;
				cout << "4. Return to home" << endl;
				int menu_c;
				cin >> menu_c;
				if (menu_c == 1) {
					sms_cont.show();
				}
				else if (menu_c == 2) {
					string name;
					cout << "who's history?" << endl;
					cin >> name;
					auto it = cont.find_name(name);
					if (it == cont.get_end_it()) {
						cout << "Check name" << endl;
					}
					else {
						sms_cont.show_history(name);
					}
				}
				else if (menu_c == 3) {
					cout << "Please type from, to" << endl;
					string name_from, name_to;
					cin >> name_from >> name_to;
					auto it = cont.find_name(name_to);
					auto it2 = cont.find_name(name_from);
					if (it == cont.get_end_it() && it2 == cont.get_end_it()) {
						cout << "Check name" << endl;
					}
					else {
						sms_cont.delete_history(name_from, name_to);
					}

				}
				else if (menu_c == 4) {
					cout << "Return to Home" << endl;
					break;
				}
				else {
					cout << "Please check menu" << endl;
				}
			}
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