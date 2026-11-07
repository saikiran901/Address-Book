#include "addressbook.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int validate_phone(char mobile[], struct AddressBook *addressBook, int index);
int validate_email(char email[], struct AddressBook *addressBook, int index);

void add_contact(struct AddressBook *addressBook)
{
    char name[50];
    char mobile[20];
    char email[40];

printf("Enter name: ");
scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
while(1)
{
     printf("Enter Mobile Number: ");
     scanf("%s",mobile);
     if(validate_phone(mobile,addressBook,-1))
     {
        strcpy(addressBook->contacts[addressBook->contactCount].phone,mobile);
        break;
     }
}while(1)
{
    printf("Enter email ID: ");
    scanf("%s",email);
    if(validate_email(email, addressBook,-1))
    {
        strcpy(addressBook->contacts[addressBook->contactCount].email,email);
        break;
    }
}
addressBook->contactCount++;
printf("Contact added Successfully.");
printf("\n");
}
void search_contact(struct AddressBook *addressBook)
{
    int choice;
    char search[50];
    printf("\n....Search Menu....\n");
    printf("1. Search by Name: \n");
    printf("2. Search by phone: \n");
    printf("3. Search by email: \n");
    printf("Back to main menu: \n");


    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice==4)
    {
        return;
    }
    if(choice <1 || choice >3)
    {
        printf("Invalid Choice. \n");
        return ;
    }

        int i;
        char name[50];
        
        addressBook->ir_size=0;
        printf("Enter choice to Search: ");
        scanf(" %[^\n]", search);

        for(i=0; i<addressBook->contactCount; i++)
        {
            if((choice== 1 && strcmp(addressBook->contacts[i].name, search)==0)||
                (choice==2 && strcmp(addressBook->contacts[i].phone,search)==0)||
                (choice==3 && strcmp(addressBook->contacts[i].email,search)==0))
            {

                addressBook->index_record[addressBook->ir_size]=i;
                addressBook->ir_size++;
            }
        }  
          
        if(addressBook->ir_size==0)
        {
            printf("Contact not found.\n");
        } 
        for(i=0; i<addressBook->ir_size; i++)
        {
            int index=addressBook->index_record[i];
                printf("-----------------------------------------------------------------\n");
                printf("%-10s%-20s%-20s%-20s\n","S.No","Name","phone","Email");
                printf("-----------------------------------------------------------------\n");
                printf("%-10d%-20s%-20s%-20s\n",i+1,
                                     addressBook->contacts[index].name,
                                     addressBook->contacts[index].phone,
                                     addressBook->contacts[index].email);
                printf("-----------------------------------------------------------------\n");                   
              //  printf("S.NO: | %d\n",i+1);
                //printf("________________________________________\n");
                //printf("Name  | %s\n", addressBook->contacts[i].name);
                //printf("________________________________________\n");
                //printf("phone | %s\n", addressBook->contacts[i].phone);
                //printf("________________________________________\n");
                //printf("Email | %s\n", addressBook->contacts[i].email);
                //printf("________________________________________\n");
        }
    }

   
void edit_contact(struct AddressBook *addressBook)
{
int index;
int choice;
int sno;
search_contact(addressBook);
   if(addressBook->ir_size==0)
    {
        return; 
    }
    if("addressBook->ir_size >1")
    {
        printf("Enter S.No to Edit: ");
        scanf("%d", &sno);
    
    if(sno < 1 || sno > addressBook->ir_size )
    {
        printf("Invalid S.No\n");
        return;
    }
    index=addressBook->index_record[sno-1];
}
    else
    {
    index=addressBook->index_record[0];
    }
    printf("------Selected Contact-------\n");
    printf("Name  : %s\n",addressBook->contacts[index].name);
    printf("phone : %s\n",addressBook->contacts[index].phone);
    printf("email : %s\n",addressBook->contacts[index].email);

    printf("--------Edit Menu----------\n");
    printf("1. Edit Name\n");
    printf("2. Edit phone\n");
    printf("3. Edit email\n");
    printf("4. Back to menu\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
    printf("Enter new Name: ");
    scanf(" %[^\n]",addressBook->contacts[index].name);
    printf("Name Updated Successfully.\n");
    break;

    case 2:
    { 
    char mobile[20];
    while(1)
    {
    printf("Enter new mobile Number: ");
    scanf("%s",mobile);
    if(validate_phone(mobile,addressBook,index))
    {
        strcpy(addressBook->contacts[index].phone,mobile);
        printf("Mobile Number Updated Successfully.\n");
        break;
    }
   
}
 break;
    }
    case 3:
    {
    char email[50];
    while(1)
    {
        printf("Enter new email ID: ");
        scanf("%s",email);
        if(validate_email(email,addressBook,index))
        {
            strcpy(addressBook->contacts[index].email,email);
            printf("Email ID Updated Successfully.\n");
            break;
        }
        
    }
    break;
}
    case 4:
    return;

    default:
    printf("Invalid choice.\n");

    
    }

}
void delete_contact(struct AddressBook *addressBook)
{
    
    int index;
    int sno;
    int i;
    search_contact(addressBook);
    if(addressBook->ir_size==0)
    {
        return;
    }
    if(addressBook->ir_size > 1)
    {
        printf("Enter S.No to Delete: ");
        scanf("%d", &sno);
        if(sno < 1 || sno > addressBook->ir_size)
        {
            printf("Invalid S.No\n");
            return;
        }
        index=addressBook->index_record[sno-1];
    }
    else
    {
        index=addressBook->index_record[0];
    }
    printf("----------Selected Contact------------\n");
    printf("Name  : %s\n",addressBook->contacts[index].name);
    printf("Phone : %s\n",addressBook->contacts[index].phone);
    printf("email : %s\n",addressBook->contacts[index].email);
char choice;
    printf("Are you sure you want to delete ? (y/n): ");
    scanf(" %c",&choice);
    
    if(choice == 'Y' || choice == 'y')
    {
       for(i=index ; i < addressBook->contactCount-1; i++)
       {
        addressBook->contacts[i]=addressBook->contacts[i+1];
       } 
       addressBook->contactCount--;
       printf("Contact Deleted Successfully.\n");
    }
    else
    {
        printf("Delete Cancelled.\n");
    }

}
void list_contacts(struct AddressBook *addressBook)
{
int i;
if(addressBook->contactCount==0)
{
    printf("No. Contacts Available.\n");
    return ;
}
printf("\n-----Contact List-----\n");
for(i=0; i<addressBook->contactCount; i++)
{
   
    printf("\n Contact %d \n", i+1);
    printf("------------------------------------------------------------------------\n");
    printf("%-10s%-20s%-20s%-20s\n","S.No","Name","Phone","email\n");
    printf("------------------------------------------------------------------------\n");
    printf("%-10d%-20s%-20s%-20s\n",i+1,
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
    printf("------------------------------------------------------------------------\n");               

  
    
}
}

int validate_phone(char mobile[], struct AddressBook *addressBook, int index)
{
    int i;
   if(strlen(mobile)!=10)
   {
    printf("Error: The Entered digits should be 10 only\n");
    return 0;
   }
   if(mobile[0]<54 || mobile[0]>57)
    {
        printf("Error: The strating digits should be in between 6 to 9\n");
        return 0;
    }

   for(int i=0; i<10; i++)
   {
    if(!isdigit(mobile[i]))
    {
        printf("Error: The Enetered letters should be digits only\n");
        return 0;
    }
}
        for(int i=0; i<addressBook->contactCount; i++)
        {
            if(i!=index && strcmp(addressBook->contacts[i].phone,mobile)==0)
            {
               printf("Error: The phone number is already exists.\n");
               return 0;
            }
           
        }
    
   return 1;
}
int validate_email(char email[], struct AddressBook *addressBook, int index)
{
    int i;
    int at=0;
    //check @ is present or not
    for(i=0; email[i]!='\0'; i++)
    {
        if(email[i]== '@')
        {
            at=1;
            if(i==0)
            {
                 printf("Error: The '@' is not be first charcter.\n");
                return 0;
            }
        }
    }
    if(at==0)
    {
       printf("Error: '@' is not present.\n");
        return 0;
    }
    //convert upper case to lower case
        for(i=0; email[i]!='\0'; i++)
        {
            if(email[i] >= 'A' && email[i] <= 'Z')
            {
                email[i]= email[i]+32;
            }
        }
    // check .com at end
    int len=strlen(email);
    {
        if((len < 4) || strcmp(&email[len-4],".com")!=0)
        {
            printf("Error: The '.com' should be present at end only\n");
            return 0;
        }
    }
   
  //check unique email address
        for(i=0; i< addressBook-> contactCount; i++)
        {
            if(i!=index && strcmp(addressBook->contacts[i].email,email)==0)
            {
                printf("Error: The 'email' id already exists.\n");
                return 0;
            }
        }
        return 1;  
}
void save_contacts(struct AddressBook *addressBook)
{
    int i;
    FILE *fp;
    fp = fopen("database.csv", "w");
    if(fp == NULL)
    {
        printf("File Cannot be opened.\n");
        return;
    }
        for(i=0; i<addressBook->contactCount; i++)
        {
            fprintf(fp," %s %s %s\n",
            
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
        }
       // fwrite(addressBook->contacts, sizeof(struct Contact),addressBook->contactCount, fp);
        fclose(fp);
        printf("Contact Saved successfully.\n");
    
}
void load_contacts(struct AddressBook *addressBook)
{
    FILE *fp;
    //int sno;
    fp =fopen("database.csv", "r");
    if(fp ==NULL)
    {
        printf("file cannot be opened.\n");
        return;
    }
    while(fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[addressBook->contactCount].phone,
     addressBook->contacts[addressBook->contactCount].email)!=EOF)
     {
        addressBook->contactCount++;
     }
     fclose(fp);

}