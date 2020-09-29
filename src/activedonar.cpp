#include "entry.h"

void list_active_donor()
{
    entry view_active_donor;
    
    view_active_donor.active_donor_list();

}


void entry::active_donor_list()
{   
    int i=1;
    entry list_active_donor;
    fstream active_donor_stream;
    active_donor_stream.open("record.dat",ios::in|ios::binary);
    if(!active_donor_stream)
    {
        cout<<"\nNo enteries done yet";
    }
    system("clear");
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------\n";

     cout<<"List of active donors:"<<endl;
     cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<" FIRST NAME"<<setw(15)<<"|"<<setw(15)<<"LAST NAME"<<setw(15.5)<<"|"<<setw(15.5)<<"Blood Group"<<setw(16.5)<<"|"<<setw(16.5)<<"Phone_no"<<setw(15)<<"|"<<setw(15.5)<<"Address\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------\n";


    while (active_donor_stream.read(reinterpret_cast<char*>(&list_active_donor),sizeof(entry)))
    {
        if(list_active_donor.active_donor=='Y')
        {
           

            list_active_donor.display_all_pattern(i);
            i++;
        }
       
    }
cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------\n";

     active_donor_stream.close();


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

