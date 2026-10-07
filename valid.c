#include "addressbook.h"
#include<string.h>

int is_valid_name(char *str)
{
    int i=0,flag=0;
    while(str[i])
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')  )
        {
            flag=1;
        }
        else if(str[i]!=' ')
        {
            return 0;
        }
        i++;
    }
    return flag;
}

int is_valid_mobile_number(struct AddressBook *addressBook,char *str)
{
    

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        
        if(strcmp(str, addressBook->contacts[i].phone) == 0)
        {
            
            return 0;
        }
    }
    int i=0,length=0;
    if(str[0]>='0' && str[0]<='5')
    {
    printf("Number should start with 6 to 9 \n");
    return 0;
    }
    while(str[i])
    {
        if(!(str[i]>='0' && str[i]<='9'))
        {
        printf("Non digit character found\n");
        return 0;
        }
    length++;
    i++;
    }

    return (i==10 && length==10);

}

int is_valid_mail_id(struct AddressBook *addressBook,char *str)
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
    
        if((strcmp(str,addressBook->contacts[i].email))==0)
        {
        return 0;
        }
    }
       int i=0,count=0,dotcount=0;
       if(str[0]==' ' || str[0]=='@' || str[0]=='.')
       return 0;
       while(str[i])
       {
              if(str[i]==' ')
              return 0;
              if(str[i]=='@')
              {
               if(str[i+1]=='.')
               return 0;
               int j=i;
               while(str[j])
               {
                     if(str[j]=='.')
                     dotcount++;
                    j++;

               }
              count++;
              }

              if(str[i]=='.')
              {
                     if(str[i+1]=='.')
                     return 0;
                     
                     if(str[i+1]=='\0')
                     return 0;
              }
            i++;

       }

       
       return (!(count!=1 || dotcount==0));
       

}
    
