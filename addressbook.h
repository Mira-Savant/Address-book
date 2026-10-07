#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>


struct Contact{
    char name[50];
    char phone[15];
    char email[50];
};

struct AddressBook {
    struct Contact contacts[100];
    int contactCount;
};

void add_contact(struct AddressBook *addressBook);
void search_contact(struct AddressBook *addressBook);
void edit_contact(struct AddressBook *addressBook);
void delete_contact(struct AddressBook *addressBook);
void list_contacts(struct AddressBook *addressBook);
void add_contact(struct AddressBook *addressBook);
void search_contact(struct AddressBook *addressBook);
void edit_contact(struct AddressBook *addressBook);
void delete_contact(struct AddressBook *addressBook);
void list_contacts(struct AddressBook *addressBook);
int is_valid_name(char *str);
int is_valid_mobile_number(struct AddressBook *addressBook,char *str);
int is_valid_mail_id(struct AddressBook *addressBook,char *str);
void search_name(struct AddressBook *addressbook);
void search_mobile(struct AddressBook *addressBook);
void search_mail(struct AddressBook *addressBook);
void edit_name(struct AddressBook *addressBook);
void edit_phone(struct AddressBook *addressBook);
void edit_mail(struct AddressBook *addressBook);
void load_contact(struct AddressBook *addressBook);
void save_contact(struct AddressBook *addressBook);
#endif
