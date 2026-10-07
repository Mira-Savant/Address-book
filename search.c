#include "addressbook.h"
#include<string.h>




void search_name(struct AddressBook *addressbook)
{
    int flag=0;
    
        char name[50];
        printf("Enter the name that you want to search:");
        scanf(" %[^\n]",name);

        for(int i=0;i<addressbook->contactCount;i++)
        {
            if((strcmp(name,addressbook->contacts[i].name))==0)
            {
                flag=1;
                printf("Contact information is:\n");
                printf("%s\n",addressbook->contacts[i].name);
                printf("%s\n",addressbook->contacts[i].phone);
                printf("%s\n",addressbook->contacts[i].email);

            }
        }

        if(flag==0)
        printf("Contact is not found");
   
}

void search_mobile(struct AddressBook *addressBook)
{
    int flag=0;
    char mobile[15];
    printf("Enter the number that you want to search:");
    scanf(" %[^\n]",mobile);

    for(int i=0;i<addressBook->contactCount;i++)
    {
        if((strcmp(mobile,addressBook->contacts[i].phone))==0)
        {
            flag=1;
            printf("Contact information is:\n");
            printf("%s\n",addressBook->contacts[i].name);
            printf("%s\n",addressBook->contacts[i].phone);
            printf("%s\n",addressBook->contacts[i].email);

        }
    }

    if(flag==0)
     printf("Contact is not found");
}

void search_mail(struct AddressBook *addressBook)
{
    int flag=0;
    char mail[50];
    printf("Enter the email that you want to search:");
    scanf(" %[^\n]",mail);

    for(int i=0;i<addressBook->contactCount;i++)
    {
        if((strcmp(mail,addressBook->contacts[i].email))==0)
        {
            flag=1;
            printf("Contact information is:\n");
            printf("%s\n",addressBook->contacts[i].name);
            printf("%s\n",addressBook->contacts[i].phone);
            printf("%s\n",addressBook->contacts[i].email);

        }
    }

    if(flag==0)
    printf("Contact is not found");
}