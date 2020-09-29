

#include"entry.h"



void add()
{
	

	system("clear");
	int choice;
	entry new_entry;
	
	new_entry.enter_info();
	
	fstream write_file;
	write_file.open("record.dat",ios::binary|ios::app);
	write_file.write(reinterpret_cast<char *>  (&new_entry),sizeof(entry));
	write_file.close();
invalid_choice:
    cout<<"\n\n\t\t\tEnter your choice:\n\t\t\t1.Go to main menu\n\t\t\t2.Exit\n\t\t\t-";cin>>choice;
    switch(choice)
    {
        case 1:
        main_menu();
        break;

        case 2:
        exit();
        break;
        
         default:
		  cout<<"\n\n\t\t\tInvalid choice. Select again\n\n";
	        goto invalid_choice;


    }

}



void entry::enter_info()
{
	cout<<"\t\t\tToday's date(mm dd yyyy) \t\t:";cin>>today_date.month>>today_date.day>>today_date.year;

	cout<<"\t\t\tFirst name     \t\t\t\t:";cin>>fname;
	for(int i=0;i<strlen(fname);i++)
	{
		fname[i]=toupper(fname[i]);
	}
	
	
	cout<<"\t\t\tLast name     \t\t\t\t:";cin>>lname;
	for(int i=0;i<strlen(lname);i++)
	{
		lname[i]=toupper(lname[i]);
	}
	
	cout<<"\t\t\tSex(M/F)   \t\t\t\t:";cin>>sex;
	sex=toupper(sex);
	
	cout<<"\t\t\tAge\t\t\t\t\t:";cin>>age;
	
reenter:
bool flag=false;
	cout<<"\t\t\tphone no \t\t\t\t:";cin>>phone_no;
	

	entry temp;
	fstream check_phone_no;
	check_phone_no.open("record.dat",ios::in|ios::binary);

	while(check_phone_no.read(reinterpret_cast<char *> (&temp),sizeof(entry)))
	{
		if(temp.phone_no==phone_no)
		{
			cout<<"\n\n!!Phone no already in used with another record!!Use another number\n\n";
			flag=true;
		
		}

	}	
	if(flag==true)
	{
		goto reenter;
	}
	

	cout<<"\t\t\tAddress\t\t\t\t\t:";cin>>address;
	for(int i=0;i<strlen(address);i++)
	{
		address[i]=toupper(address[i]);
	}
	
	cout<<"\t\t\tBlood group(eg.A,AB+.) \t\t\t: ";cin>>blood_group;
	for(int i=0;i<strlen(blood_group);i++)
	{
	blood_group[i]=toupper(blood_group[i]);
	}
	
	cout<<"\t\t\tAmount of blood donated(ml)\t       :";cin>>blood_amount;
	cout<<"\t\t\tDate of Birth(mm dd yyyy)\t\t:";cin>>DOB.month>>DOB.day>>DOB.year;
	
	cout<<"\t\t\tDo you want to be active donor(Y/N)     :";cin>>active_donor;
	active_donor=toupper(active_donor);
	
	
	//confirming details entered
	cout<<"\n\n\n\n\t\tConfirm your details\n";
	cout<<"\n\t\t|--------------------------------------------------------------------|";
	cout<<"\n\t\t\t|  Date of entry\t\t:"<<today_date.month<<"/"<<today_date.day<<"/"<<today_date.year;
	cout<<"\n\t\t\t|  First name     \t\t:"<<fname;
	cout<<"\n\t\t\t|  Last name     \t\t:"<<lname;
	cout<<"\n\t\t\t|  Age\t\t\t\t:"<<age;
	
	if(sex=='F')
	{
		cout<<"\n\t\t\t|  Sex \t\t\t\t:"<<"Female";
	}
	else if(sex=='M')
	{
		cout<<"\n\t\t\t|  Sex \t\t\t\t:"<<"Male";
	}
	
	cout<<"\n\t\t\t|  phone no \t\t\t:"<<phone_no;
	cout<<"\n\t\t\t|  Blood group \t\t\t:"<<blood_group;
	cout<<"\n\t\t\t|  Address\t\t\t:"<<address;
	cout<<"\n\t\t\t|  Amount of blood donated      :"<<blood_amount<<" ml";
	cout<<"\n\t\t\t|  Date of Birth\t\t:"<<DOB.month<<"/"<<DOB.day<<"/"<<DOB.year;
	
	if(active_donor=='Y')
	{
		cout<<"\n\t\t\t|  Active donor          \t:"<<"YES";
	}
	
	else if(active_donor=='N')
	{
		cout<<"\n\t\t\t|  Active donor          \t:"<<"NO";
	}
	
	cout<<"\n\t\t|--------------------------------------------------------------------|";

	char choice;
invalid_selection:
	cout<<"\n\t\t\tDo you agree to add the entry(Y/N)?";cin>>choice;
	choice=toupper(choice);
	if(choice=='Y'){
	cout<<"\n\n\t\t\tNew Entry Added Successfully";
	}
	else if(choice=='N'){
		cout<<"\n\n\t\t\t This entry was not added";
		not_added();
	}
	else
	{
		cout<<"\n\n\t\t\tinvalid selection\tSelect again:";
		goto invalid_selection;
	}
	
	
	

}


void not_added()
{

		int choice;
invalid_choice:
	      cout<<"\n\n\t\t\tEnter your choice:\n1.Go to main menu\n2.Exit\n\t\t-";cin>>choice;
	    	switch(choice)
	    	{
		  case 1:
		  main_menu();
		  break;

		  case 2:
		  exit();
		  break;
		  
		   default:
		  cout<<"\n\n\t\t\tInvalid choice. Select again\n\n";
	        goto invalid_choice;


	    	}


}






