#include "addressbook.h"
#include<string.h>



void edit_name(struct AddressBook *addressBook)
{
    char name[50];
    printf("Enter the contact name that you want to edit: ");
    scanf(" %[^\n]", name);

    int count = 0;
    int index[100];   

    printf("\nMatching contacts:\n");
    printf("No.\tIndex\tName\tPhone\tEmail\n");
    printf("---------------------------------------------------------\n");

    
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(name, addressBook->contacts[i].name) == 0)
        {
            printf("%d\t%d\t%s\t%s\t%s\n",count + 1,i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

            index[count] = i;
            count++;
        }
    }

    if(count == 0)
    {
        printf("Contact not found\n");
        return;
    }

    int selected_index;

    
    if(count == 1)
    {
        selected_index = index[0];
    }
    else
    {
        int choice;

        
        do {
            printf("Enter choice (1 to %d): ", count);
            scanf("%d", &choice);

            if(choice < 1 || choice > count)
                printf("Invalid choice, try again\n");

        } while(choice < 1 || choice > count);

        selected_index = index[choice - 1];
    }

    
    char new_name[50];
    printf("Enter the new name: ");
    scanf(" %[^\n]", new_name);

    
    strcpy(addressBook->contacts[selected_index].name, new_name);

    printf("Name updated successfully!\n");
}

void edit_phone(struct AddressBook *addressBook)
{
    printf("Enter the mobile number which you want to edit:");
    char mobile[15];
    scanf(" %[^\n]",mobile);

    for(int i=0;i<addressBook->contactCount;i++)
    {
        if((strcmp(mobile,addressBook->contacts[i].phone))==0)
        {

        
            printf("Contact found now you can edit\n");

            int new_flag=1;
            do{
                char new_phone[20];
                printf("Enter the phone number new one:");
                scanf(" %[^\n]",new_phone);

                if(is_valid_mobile_number(addressBook,new_phone))
                {
                   strcpy(addressBook->contacts[i].phone, new_phone);
                   new_flag=0;
                }
                else
                {
                    printf("Enter valid phone number");
                }

            }while(new_flag);
             return;
        }
    }
}

void edit_mail(struct AddressBook *addressBook)
{
    printf("Enter the mobile email which you want to edit:");
    char mail[50];
    scanf(" %[^\n]",mail);

    for(int i=0;i<addressBook->contactCount;i++)
    {
        if((strcmp(mail,addressBook->contacts[i].email))==0)
        {

        
            printf("email found now you can edit\n");

            int new_flag=1;
            do{
                char new_mail[50];
                printf("Enter the mail new one:");
                scanf(" %[^\n]",new_mail);

                if(is_valid_mail_id(addressBook,new_mail))
                {
                   strcpy(addressBook->contacts[i].email, new_mail);
                   new_flag=0;
                }
                else
                {
                    printf("Enter valid email id");
                }

            }while(new_flag);
             return;
        }
    }

}

