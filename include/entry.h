#pragma once

#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>

using namespace std;

struct date
{
	int month,day,year;
};



class entry
{
	char fname[25];
	char lname[25];
	char sex;
	int age;
	long phone_no;
	char address[40];
	char blood_group[3];
	double blood_amount;
	struct date today_date;	
	struct date DOB;
	char active_donor;
	//char list_active_donor;
	
	struct date last_updated_date;
	
	
	
    public:
	
	entry(){last_updated_date.day=0;last_updated_date.month=0;last_updated_date.year=0;}
	
	void enter_info();
	void display_all_pattern(int i);
	void find_specific_entry_for_displaying();
	void display_details();
	
	//void age_only();
   
   	void find_specific_entry_for_updating(); // added by aayam
	void remove_a_record(); // added by aayam

 	void limited_list_pattern();
	
	void update_first_name(); // added by aayam
	void update_last_name();  // added by aayam
	void update_phone_no();   // added by aayam
	void update_address();    // added by aayam
	void update_active_donor_status();  // added by aayam
	void update_blood_amount();  // added by aayam


	void compare_bloodgroup();
	void displaybloodgroup();
	void display_list(char bgn[]);
	void active_donor_list();

};


void checkavailability();
void update();
void add();
void display_all();
void display_specific();
void exit();
void main_menu();
void delay(int);
void not_added();

void list_active_donor();




class admin{
	public:
	int pass;

	
};



void login();
void change_password();