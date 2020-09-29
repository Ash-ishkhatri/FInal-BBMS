
#include"entry.h"


void exit()
{	
system("clear");
    cout<<"\n\n\t\tThank you\n\n";
    cout<<"\n\t\tDevelopers:\n\t\tAshish Kumar Khatri\n\t\tAayam Adhikari\n\t\tAnjali Prajapati\n\t\tAnisha Dhakal";
    exit(1);
}



void main_menu( )
{
	
	system("clear");
    
    cout<<"\n\t\t|--------------------------------------------------------------------|";
     cout<<"\n\t\t\t           BLOOD BANK MANAGEMENT SYSTEM                 \n\t\t\t\t            MAIN MENU         ";
    cout<<"\n\t\t|--------------------------------------------------------------------|";
    
    cout<<"\n\t\t\t\t1|ADD NEW ENTRY";
    cout<<"\n\t\t\t\t2|UPDATE EXISTING ENTRY";
    cout<<"\n\t\t\t\t3|CHECK AVAILABILITY OF BLOOD";
    cout<<"\n\t\t\t\t4|VIEW LIST OF ACTIVE DONORS";
    cout<<"\n\t\t\t\t5|VIEW LIST OF ALL EXISTING RECORDS";
    cout<<"\n\t\t\t\t6|VIEW DETAILS OF PARTICULAR EXISTING RECORD";
    cout<<"\n\t\t\t\t7|Exit the program\n\t\t";
    cout<<"\n\t\t|--------------------------------------------------------------------|";
    cout<<"\n\t\t|--------------------------------------------------------------------|";
    
choose_again:
 	int choice;
    cout<<"\n\n\t\t\t-->";
    cin>>choice;

	switch(choice)
	{
		case 1:
		add();
		break;
		
	   case 2:
	   update();
         break;
		
	  case 3:
        checkavailability();
        break;

        case 4:
        list_active_donor();
        break;

        case 5:
        display_all();
        break;

        case 6:
        display_specific();
        break;

        case 7:
        exit();
        break;
        
        default:
        cout<<"\nInvalid option chosen....choose again\n";
        goto choose_again;
        
        break;
	}
	

}



int main()
{	
	system("clear");

	
    cout<<"\n1.login\n2.change password\n\t--->";
    int choice;
    cin>>choice;

    switch(choice)
    {
        case 1:
        login();
        break;

        case 2:
        change_password();
        main();
        break;

    }
   

	main_menu();
		
	return 0;

}


void delay(int i)
{
	for(int j=1;j<i;j++)
	{

	}

}




void login()
{
    admin temp;
    int password;
    
reenter:
    system("clear");
    cout<<"Enter password:";
    cin>>password;

    fstream pass_file;
    pass_file.open("password.dat",ios::binary|ios::in);
    while(pass_file.read(reinterpret_cast<char *> (&temp),sizeof(admin)))
    {
            if(temp.pass!=password)
            {
                int choice;
                cout<<"Incorrect password!!try again!!\n\n.1re-enter\n2.exit";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    goto reenter;
                    break;

                    case 2:
                    exit();
                    break;
                }
            }
            
    }

   
}



void change_password(){

    admin temp;
    
   
    int old_pass;
reenter:
    bool flag=true;
    cout<<"\n\nEnter old password:";
    cin>>old_pass;
    
     fstream check_password;
    check_password.open("password.dat",ios::in|ios::binary);


    while(check_password.read(reinterpret_cast<char *> (&temp),sizeof(admin)))
    {
        if(temp.pass==old_pass)
        {
            cout<<"Enter new password:";
            cin>>temp.pass;
            fstream changed_password;
            changed_password.open("password.dat",ios::binary|ios::out);
            changed_password.write(reinterpret_cast<char *> (&temp),sizeof(admin));
            changed_password.close();
           
            cout<<"\n\tPassword changed successfully";
        }
        else
        {
            cout<<"Old password didn't match ! try re-entering it again from start";
            flag=false;
            
        }
    
        
    }
    if(flag==false)
    {
        goto reenter;
    }
    check_password.close();
}






