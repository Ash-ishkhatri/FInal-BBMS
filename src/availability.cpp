#include "entry.h"
using namespace std;
void checkavailability()
{
    entry checkavailability;
    checkavailability.compare_bloodgroup();
}

void entry::compare_bloodgroup()
{   
     double ap,an,bp,bn,abp,abn,op,on;
    ap=an=bp=bn=abp=abn=op=on=0;

    entry compare;
  
    fstream find_blood_group;
	find_blood_group.open("record.dat",ios::in|ios::binary);
	
	if(!find_blood_group){cout<<"\nNo entry done yet\n";}
    else
	{
	
		while(find_blood_group.read(reinterpret_cast<char *> (&compare),sizeof(entry)))
		{
            if(strcmp(compare.blood_group,"A+")==0)
            {
             ap+=compare.blood_amount;
            }
            else  if(strcmp(compare.blood_group,"A-")==0)
            {
               an+=compare.blood_amount;
            }
            else if(strcmp(compare.blood_group,"B+")==0)
            {
                bp+=compare.blood_amount;;
            }
           else if(strcmp(compare.blood_group,"B-")==0)
            {
                bn+=compare.blood_amount;
            }
           else if(strcmp(compare.blood_group,"AB+")==0)
            {
               abp+=compare.blood_amount;
            }
           else if(strcmp(compare.blood_group,"AB-")==0)
            {
                abn+=compare.blood_amount;
            }
           else if(strcmp(compare.blood_group,"O+")==0)
            {
                op+=compare.blood_amount;
            }
           else if (strcmp(compare.blood_group,"O-")==0)
            {
                on+=compare.blood_amount;
            }
  

        } 
    
         
    }
    find_blood_group.close();

    system("clear");
	cout<<"\n\n\n\t\t|---------------------------------------------------------------------------------------|";

    cout<<"\n\t\t\t\t\t   ----------AVAILABILITY TABLE----------\n\t\t\tBlood Group"<<setw(34)<<"|"<<setw(34)<<"Blood Amouint available in ml";
    cout<<"\n\t\t|---------------------------------------------------------------------------------------|";
    cout<<"\n\t\t|---------------------------------------------------------------------------------------|";
    cout<<"\n\t\t\tA+ "<<setw(70)<<ap << "\n";
     cout<<"\t\t\tA- "<<setw(70)<<an << "\n";
    cout<<"\t\t\tB+ "<<setw(70)<<bp << "\n";
    cout<<"\t\t\tB- "<<setw(70)<<bn << "\n"; 
     cout<<"\t\t\tAB+"<<setw(70)<<abp<< "\n";
     cout<<"\t\t\tAB-"<<setw(70)<<abn << "\n";
     cout<<"\t\t\tO+ "<<setw(70)<<op << "\n";
     cout<<"\t\t\tO- "<<setw(70)<<on << "\n";
    cout<<"\n\t\t|---------------------------------------------------------------------------------------|";
    cout<<"\n\t\t|---------------------------------------------------------------------------------------|";
   entry display;
    char bgn[3];
    cout << "\n\n\t\tWhich blood group do you want? \n\t\t\t\t--->";
    cin >> bgn ;
    
    for(int i=0;i<strlen(bgn);i++)
    {
        bgn[i]=toupper(bgn[i]);
    }
    
    fstream display_blood_amount;
	display_blood_amount.open("record.dat",ios::in|ios::binary);
	
	if(!display_blood_amount){cout<<"\nNo entry done yet\n";}
    else
	{
        system("clear");
	 cout<< "\n\n\n\t\t|------------------  LIST OF DONORS WITH " << bgn <<" BLOOD GROUP ----------------------------------|";
     cout<< "\n\t\t|-----------------------------------------------------------------------------------------|";
     cout<<"\n\t\t  FIRST NAME"<<setw(19)<<"|"<<setw(19)<<"LAST NAME"<<setw(19)<<"|"<<setw(19)<<"BLOOD GROUP";
      cout<< "\n\t\t|-----------------------------------------------------------------------------------------|";


		while(display_blood_amount.read(reinterpret_cast<char *> (&display),sizeof(entry)))
		{
            if(strcmp(display.blood_group,bgn)==0)
            {
                 display.display_list(bgn);
            }
        }  
   cout<< "\n\t\t|-----------------------------------------------------------------------------------------|\n";
    
        

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


}



void entry::display_list(char bgn[])
{
   
    
    cout<<"\n\t\t  "<<fname<<setw(38)<<lname<<setw(36)<<blood_group<<"\n";
    

    

}

