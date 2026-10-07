#include "addressbook.h"
#include<string.h>

void add_contact(struct AddressBook *addressBook)
{
    int i=addressBook->contactCount;
    int name_flag=1;
    do{

    char name[50];
    printf("Enter the name:");
    scanf(" %[^\n]",name);
    
    if(is_valid_name(name))
    {
        name_flag=0;
        strcpy(addressBook->contacts[i].name,name);

    }
    else
    {
        printf("please enter a valid name\n");

    }

}while(name_flag);


int mobile_flag=1;
do{

char number[20];
printf("Enter the mobile number:");
scanf(" %[^\n]",number);

if(is_valid_mobile_number(addressBook,number))
{
    mobile_flag=0;
    strcpy(addressBook->contacts[i].phone,number);

}
else
{
    
    printf("please enter a valid mobile number\n");

}

}while(mobile_flag);

int email_flag=1;
do{

char mail[50];
printf("Enter the mail id:");
scanf(" %s",mail);

if(is_valid_mail_id(addressBook,mail))
{
    email_flag=0;
    strcpy(addressBook->contacts[i].email,mail);

}
else
{
    printf("please enter a valid mail id\n");

}

}while(email_flag);

addressBook->contactCount++;

}


void search_contact(struct AddressBook *addressBook)
{
    int flag=0;
    do{
    int opt;
    printf("Enter the option based on what you want to search:\n1.Search using name\n2.Search using mobile number\n3.Search using mail id\n");
    scanf("%d",&opt);
        switch(opt)
        {
            case 1:search_name(addressBook);
                break;
            case 2:search_mobile(addressBook);
                break;
            case 3:search_mail(addressBook);
                break;
            default:flag=1;
                printf("Invalid option,please enter valid option\n");
                break;
                    
        }
    }while(flag);

}

void edit_contact(struct AddressBook *addressBook)
{
    int flag;
    do
    {
        flag=0;
        int opt;
        printf("Enter the option what you want to edit:\n1.Edit name\n2.Edit mobile number\n3.Edit mail id\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:edit_name(addressBook);
                   break;
            case 2:edit_phone(addressBook);
                   break;
            case 3:edit_mail(addressBook);
                   break;
            default:flag=1;
                    printf("Invalid option please enter valid option\n");
                    break;
        }


    }while(flag);

}

void delete_contact(struct AddressBook *addressBook)
{

    char mob[15]; 
    printf("Enter the mobile number of that contact which you want to delete:"); 
    scanf(" %[^\n]",mob);

        int found = 0;

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(mob, addressBook->contacts[i].phone) == 0)
            {
                found = 1;

                printf("Mobile number found. Are you sure to delete?\n1-Yes  2-No: ");
                
                int opt;
                scanf("%d", &opt);

                if(opt == 1)
                {
                    for(int j = i; j < addressBook->contactCount - 1; j++)
                    {
                        addressBook->contacts[j] = addressBook->contacts[j+1];
                    }
                    addressBook->contactCount--;
                    printf("Contact deleted successfully\n");
                }
                else
                {
                    printf("Deletion cancelled\n");
                }

                break;
            }
        }

        if(!found)
        {
            printf("Mobile number not found\n");
        }
}



void list_contacts(struct AddressBook *addressBook)
{
    printf("Contact information is:\n");
    printf("%-20s %-15s %-30s\n", "Name", "Phone", "Email");
    printf("---------------------------------------------------------------\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
             printf("%-20s\t%-15s\t%-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            
    }

}

