

#include"entry.h"

void login()
{

    admin user;

    invalid:

    cout<<"1.Login\n2.change password\n\t--->";

    int choice;
    cin>>choice;

    if(choice==1)
    {
    reenter:
        cout<<"\nEnter your name:";
        cin>>user.name;
        cout<<"Enter the system's 4 digit pin(****):";
        cin>>user.pass;
        bool result=user.check_password();
        // if(result==true)
        // {
            
        // }
        // else if(result==false)
        // {
        //     goto reenter;
        // }
        

    }

    else if(choice==2)
    {

    }

    else
    {
        cout<<"\n\nInvalid choice!!choose again!\n";
        goto invalid;
    }
    
}





bool admin::check_password()
{
    admin temp_obj;
    fstream pass_file;
    pass_file.open("password.dat",ios::binary|ios::in);
    if(!pass_file){cout<<"nothing found";}
    while(pass_file.read(reinterpret_cast<char *> (&temp_obj),sizeof(admin)))
    {
        if(temp_obj.pass==this->pass)
        {
            cout<<"\npassword is correct";
            

        }
        else
        {
            cout<<"\nPassword is incorrect";
            cout<<"reenter the password!";
            
        }
        
    }
return true;

}