#include "addressbook.h"
#include <stdio.h>
#include<stdlib.h>


void load_contact(struct AddressBook *addressBook)
{
    FILE *fptr = fopen("contact.csv", "r");

    if (fptr == NULL)
    {
        printf("No existing file. Starting fresh.\n");
        return;
    }

    addressBook->contactCount = 0;

    while (addressBook->contactCount < 100 &&
           fscanf(fptr, " %[^,],%[^,],%49[^\n]",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;
    }

    fclose(fptr);
}

void save_contact(struct AddressBook *addressBook)
{
    FILE *fptr = fopen("contact.csv", "w");

    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fptr);
}