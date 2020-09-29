#include"entry.h"


void update()
{ 
	entry update_entry;

	int choice;
	cout << "\nDo you want to remove a particular record or just update a record?\n\n1.To delete a record\n2.To update a record\n\t\t->";
	cin >> choice;

	switch(choice)
	{
		case 1:
		update_entry.remove_a_record();
		break;

		case 2:
		update_entry.find_specific_entry_for_updating();
        break;
	}

}


void entry::remove_a_record()
{
	bool flag=false;
	system("clear");

	entry present_entry;
	
	fstream old_file,new_file;
	
	old_file.open("record.dat",ios::in|ios::binary);
	new_file.open("new.dat",ios::app|ios::binary);
	
	cout<<"Enter details of entry you want to update:\n-First name:";
	cin>>this->fname;
	
	for(int i=0;i<strlen(fname);i++)
	{
		this->fname[i]=toupper(this->fname[i]);
	}
	cout<<"-Phone no:";cin>>this->phone_no;
	
	while(old_file.read(reinterpret_cast<char *> (&present_entry),sizeof(entry)))
	{
		
		if(strcmp(present_entry.fname,this->fname)==0 && present_entry.phone_no==this->phone_no)
		{
		
		cout<<"Entry found and details of the entry is:\n\n";
		present_entry.display_details();
	
		flag=true;
		delay(100000000);
		cout<<"\n\nDeleted Successfully";
		}
		else
		{
		new_file.write(reinterpret_cast<char *> (&present_entry),sizeof(entry));
		}
	
	}


	delay(100000000);
	if(flag!=true)
	{
	cout<<"\n\n!record not found";
	}
	
	
	
	old_file.close();
	new_file.close();
	
	remove("record.dat");
	rename("new.dat","record.dat");
	
	int choice;
invalid_choice_selected:
    cout<<"\n\nEnter your choice:\n1.Go to main menu\n2.Exit\n3.View detail of particular entry\n4.Update more records\n\t\t-";cin>>choice;
    switch(choice)
    {
        case 1:
        main_menu();
        break;

        case 2:
        exit();
        break;
        
        case 3:
        display_specific();
        break;

		case 4:
		update();
        
        default:
        cout<<"\n\nInvalid choice. Select again\n\n";
        goto invalid_choice_selected;
    }

}




//finding specific entry for updating
void entry::find_specific_entry_for_updating()
{
	bool flag=false;
	system("clear");
	
	entry present_entry;
	
	fstream old_file,new_file;
	
	old_file.open("record.dat",ios::in|ios::binary);
	new_file.open("new.dat",ios::app|ios::binary);
	
	cout<<"Enter details of entry you want to update:\n-First name:";
	cin>>this->fname;
	
	for(int i=0;i<strlen(fname);i++)
	{
		this->fname[i]=toupper(this->fname[i]);
	}
	cout<<"-Phone no:";cin>>this->phone_no;
	
	while(old_file.read(reinterpret_cast<char *> (&present_entry),sizeof(entry)))
	{
		
		if(strcmp(present_entry.fname,this->fname)==0 && present_entry.phone_no==this->phone_no)
		{
			cout<<"pp";
		cout<<"Entry found and details of the entry is:\n\n";
		present_entry.display_details();
update_again:		
		cout<<"\n\nWhat detail you want to update?\n1.First name\n2.Last name\n3.Phone number\n4.Address\n5.Active donor status\n6.Blood Amount\n\t\t-";
		int choice1;

invalid_choice:

		cin>>choice1;

			switch(choice1)
			{
				case 1:
				{
				int choice2;
				present_entry.update_first_name();
				
				cout<<"\n1.Update more\n2.Finish updating\n\t-";cin>>choice2;
				switch(choice2)
					{
						case 1:
						goto update_again;
						system("clear");
						break;
						
						case 2:
						break;
				    }
				}
				break;

		
				case 2:
				int choice3;
				present_entry.update_last_name();	
				
				cout<<"\n1.Update more\n2.Finish updating\n\t-";cin>>choice3;
				switch(choice3)
					{
						case 1:
						goto update_again;
						system("clear");
						break;
						
						case 2:
						break;
				    }
				break;	

				case 3:	
				int choice4;
				present_entry.update_phone_no();

				cout<<"\n1.Update more\n2.Finish updating\n\t-";cin>>choice4;
				switch(choice4)
				{
					case 1:
					goto update_again;
					system("clear");
					break;

					case 2:
					break;
				}
				break;

				case 4:
				int choice5;
				present_entry.update_address();

				cout<<"\n1.Update more\n2.Finish updating\n\t-";cin>>choice5;
				switch(choice5)
				{
					case 1:
					goto update_again;
					system("clear");
					break;

					case 2:
					break;
				}
				break;

				case 5:
				int choice6;
				present_entry.update_active_donor_status();

				cout<<"\n1.Update more\n2.Finish updating\n\t-";
				cin>>choice6;
				switch(choice6)
				{
					case 1:
					goto update_again;
					system("clear");
					break;

					case 2:
					break;
				}
				break;

				case 6:
				int choice7;
				present_entry.update_blood_amount();

				cout<<"\n1.Update more\n2.Finish updating\n\t-";
				cin>>choice7;
				switch(choice7)
				{
					case 1:
					goto update_again;
					system("clear");
					break;

					case 2:
					break;
				}
				break;







			
			
			    default:
				cout<<"Invalid choice! Please choose again.";
				goto invalid_choice; 
				break;
				
			}
			
			
		new_file.write(reinterpret_cast<char *> (&present_entry),sizeof(entry));
	
		flag=true;
		delay(100000000);
		cout<<"\n\nUpdated Successfully";
		}
		else
		{
		new_file.write(reinterpret_cast<char *> (&present_entry),sizeof(entry));
		}
	
	}


	delay(100000000);
	if(flag!=true)
	{
	cout<<"\n\n!record not found";
	}
	
	
	
	old_file.close();
	new_file.close();
	
	remove("record.dat");
	rename("new.dat","record.dat");
	
	int choice;
invalid_choice_selected:
    cout<<"\n\nEnter your choice:\n1.Go to main menu\n2.Exit\n3.View detail of particular entry\n4.Update more records\n\t\t-";cin>>choice;
    switch(choice)
    {
        case 1:
        main_menu();
        break;

        case 2:
        exit();
        break;
        
        case 3:
        display_specific();
        break;

		case 4:
		update();
        
        default:
        cout<<"\n\nInvalid choice. Select again\n\n";
        goto invalid_choice_selected;
    }
}	


//updating first name
void entry::update_first_name()
{
	
			cout<<"\nEnter new first name: ";cin>>(this->fname);
			for(int i=0;i<strlen(this->fname);i++)
			{
				(this->fname[i])=toupper(this->fname[i]);
			}
            cout << "\nEnter Today's Date(mm/dd/yyyy):: ";
            cin >> this->last_updated_date.month >> this->last_updated_date.day >> this->last_updated_date.year;
}

 
//updaing last name
void entry::update_last_name()
{
			cout<<"\nEnter new last name: ";cin>>(this->lname);
			for(int i=0;i<strlen(this->lname);i++)
			{
				(this->lname[i])=toupper(this->lname[i]);
			}
            cout << "\nEnter Today's Date(mm/dd/yyyy):: ";
            cin >> this->last_updated_date.month >> this->last_updated_date.day >> this->last_updated_date.year;
}

void entry::update_phone_no()
{
	cout << "\nEnter new phone number: ";
	cin >> (this->phone_no);
    cout << "\nEnter Today's Date(mm/dd/yyyy): ";
            cin >> this->last_updated_date.month >> this->last_updated_date.day >> this->last_updated_date.year;

}

void entry::update_address()
{
	cout << "\nEnter new address: ";
		   cin >> this->address;
		   for(int i=0;i<strlen(this->address);i++)
		   {
			   (this->address[i]) = toupper(this->address[i]);
		   }
           cout << "\nEnter Today's Date(mm/dd/yyyy):: ";
            cin >> this->last_updated_date.month >> this->last_updated_date.day >> this->last_updated_date.year;
}

void entry::update_active_donor_status()
{
	 cout << "\nDo you want to be an active donor?[y/n]: ";
	 cin >> this->active_donor;
	 (this->active_donor) = toupper(this->active_donor);

     cout << "\nEnter Today's Date(mm/dd/yyyy):: ";
            cin >> this->last_updated_date.month >> this->last_updated_date.day >> this->last_updated_date.year;
}

void entry::update_blood_amount()
{
	int choice;
	double new_blood;
	cout << "Enter your choice:\n";
	cout << "\n1.To add blood amount\n2.To Remove existing blood amount\n\t\t->";
	cin >> choice;
	system("clear");

	if(choice == 1)
	{
		cout << "\nHow many litres of blood do you want to add?: ";
		cin >> new_blood;
		(this->blood_amount) = (this->blood_amount) + new_blood;

        cout << "\nEnter Today's Date(mm/dd/yyyy): ";
            cin >> this->last_updated_date.month >> this->last_updated_date.day >> this->last_updated_date.year;
    }
	else if(choice == 2)
	{
		cout << "\nHow many litres of blood do you want to remove?: ";
		cin >> new_blood;
		(this->blood_amount) = (this->blood_amount) - new_blood;

        cout << "\nEnter Today's Date(mm/dd/yyyy): ";
            cin >> this->last_updated_date.month >> this->last_updated_date.day >> this->last_updated_date.year;
	}
	
}
