
#include"entry.h"





void display_all()
{	
	int i=1;
	system("clear");
	entry display_all_entry;
	
	fstream read_file;
	read_file.open("record.dat",ios::binary|ios::in);
	
	if(!read_file)
	    {
		  cout<<"No entry done yet";
	    }
    else
	    {
	    
	    		cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<" FIRST NAME"<<setw(15)<<"|"<<setw(15)<<"LAST NAME"<<setw(15.5)<<"|"<<setw(15.5)<<"Blood Group"<<setw(16.5)<<"|"<<setw(16.5)<<"Phone_no"<<setw(15)<<"|"<<setw(15.5)<<"Address ";
		  	    	cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
		
		
		
		  while(read_file.read(reinterpret_cast<char *> (&display_all_entry),sizeof(entry)))
		  {
		  	
		      display_all_entry.display_all_pattern(i);
		  	i++;
		  }

cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------\n";

		  
		  read_file.close();	
		
	   }	
	int choice;
invalid_choice:
    cout<<"\n\n\t\t\tEnter your choice:\n\t\t\t1.Go to main menu\n\t\t\t2.Exit\n\t\t\t3.View detail of particular entry\n\t\t\t--->";cin>>choice;
    switch(choice)
    {
        case 1:
        main_menu();
        break;

        case 2:
        exit();
        break;
        
        case 3:
        cout<<"\n\n";
        display_specific();
        break;
        
        default:
        cout<<"\n\n\t\t\tInvalid choice. Select again\n\n";
        goto invalid_choice;
        

    }


}



void entry::display_all_pattern(int i)
{
	cout<<"\n "<<i<<"-"<<fname<<setw(30)<<lname<<setw(31)<<blood_group<<setw(33)<<phone_no<<setw(35)<<address<<"\n";
}





void display_specific()
{
	//system("clear");
	entry view_entry;
	
	view_entry.find_specific_entry_for_displaying();
    	int choice;
invalid_choice:
	    cout<<"\n\n\t\t\tEnter your choice:\n\t\t\t1.Go to main menu\n\t\t\t2.Exit\n\t\t\t3.View all in list\n\t\t\t\t\t--->";cin>>choice;
	    switch(choice)
	    {
		  case 1:
		  main_menu();
		  break;

		  case 2:
		  exit();
		  break;
		  
		  case 3:
		  display_all();
		  break;
		  
		  default:
		  cout<<"\n\n\t\t\tInvalid choice. Select again\n\n";
	        goto invalid_choice;

	    }

}



void entry::display_details()
{	system("clear");
	cout<<"\n\t\t--------------------------------------------------------------------|";
	cout<<"\n\t\t-------------DETAILS--OF--"<<this->fname<<" "<<this->lname<<"-------------------------------";
	cout<<"\n\t\t--------------------------------------------------------------------|";
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

	cout<<"\n\t\t\t|  Last updated\t\t\t:"<<last_updated_date.month<<"/"<<last_updated_date.day<<"/"<<last_updated_date.year;
	
	cout<<"\n\n\t\t|--------------------------------------------------------------------";
}



void entry::find_specific_entry_for_displaying()
{
	entry present_entry;
	
	fstream read_file;
	read_file.open("record.dat",ios::binary|ios::in);
	
	if(!read_file){cout<<"\n\t\t\tno entry done yet";}
	else
	{
	cout<<"\t\t\tEnter First name:";cin>>this->fname;
	for(int i=0;i<strlen(this->fname);i++)
	{
		this->fname[i]=toupper(this->fname[i]);
	}
	
	   int count=0;
	   while(read_file.read(reinterpret_cast<char *> (&present_entry),sizeof(entry)))
		  {
		  	if(strcmp(present_entry.fname,this->fname)==0)
		  	count++;
		  }
		  
		  read_file.close();
		  
		  read_file.open("record.dat",ios::binary|ios::in); 
		 
		 
		
		if(count==0)
		{cout<<"\n\n\t\t\tNo record found with that name";}
		
		
	    	else if(count==1)
		{
			while(read_file.read(reinterpret_cast<char *> (&present_entry),sizeof(entry)))
			{
				if(strcmp(present_entry.fname,this->fname)==0)
				{
					present_entry.display_details();
					
				}
				
			
			}
			read_file.close();
			
		}
		
		
		else
		{
			cout<<"\n\n\t\t\t!!More than one entry available with that name!!";
			cout<<"\n\n\t\t\tSo enter more detail of that entry::\nphone number:";cin>>this->phone_no;
			
			fstream stream1;
			stream1.open("record.dat",ios::binary|ios::in);
			
			while(stream1.read(reinterpret_cast<char *> (&present_entry),sizeof(entry)))
			{
				if((strcmp(present_entry.fname,this->fname)==0) && (this->phone_no==present_entry.phone_no))
				{
					present_entry.display_details();
					
				}
			}
			stream1.close();
		
		}
	}
	
		

}











