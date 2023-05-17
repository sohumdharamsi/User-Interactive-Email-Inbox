///////////////////////////////////////////////
//Add program description, author name, last edit date as in project1

//Sohum Dharamsi
//CMSC 257
//Project Description: In this project you are to create a menu driven email client. The email client should be able to display the inbox, display email, search emails by keyword, sort inbox emails in inbox by sender, sort emails in inbox by ID, and delete emails in inbox by ID.
//11.10.22


//Add necessary include statements (I added for you!)
#include "p2-support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////
// Function Definitions
// //////////////////////////////////////////

void initialize(struct Mailbox *ib)
{
  //allocate memory for 2000 emails
  ib->emails = malloc(sizeof(struct Email) * MAILBOX_SIZE);
  ib->size = 0;

  create_email("asonmez@mail.com", user_email, "Welcome to your inbox.",
    "Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.",
    11, 20, 2020, ib);
  create_email("mmartinez@mail.com", user_email, "Padding out your inbox.",
    "Yet another email just to pad out your inbox, have fun!",
    11, 30, 2020, ib);
  create_email("dboyle@mail.com", user_email, "3rd email!",
    "Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!",
    12, 2, 2020, ib);
  create_email("cbluer@mail.com", user_email, "4th email!",
    "Content of fourth email. More coding, more fun!",
    12, 8, 2020, ib);
  create_email("cboyle@mail.com", user_email, "5th email!",
    "Content of fifth email. Coding is fun-tastic!",
    12, 18, 2020, ib);
  create_email("sblack@mail.com", user_email, "6th email!",
    "Content of sixth email. Coding is fun-tastic!",
    1, 1, 2021, ib);
  create_email("sblack@mail.com", user_email, "7th email!",
    "Body of seventh email. Coding is fun-tastic!",
    1, 5, 2021, ib);
  create_email("sblack@mail.com", user_email, "8th email!",
    "Body of eighth email. Coding is fun-tastic!",
    2, 15, 2021, ib);
  create_email("sblack@mail.com", user_email, "9th email!",
    "Body of ninth email. Coding is fun-tastic!",
    2, 25, 2021, ib);
  create_email("dboyle@mail.com", user_email, "Last email!",
    "Body of tenth email. Coding is fun-tastic!",
    3, 15, 2021, ib);
}

//Other function definitions go below

void create_email(char *s, char *r, char *sub, char *b, int m, int d, int y, struct Mailbox *ib){
  struct date d1 = {.month = m, .day = d, .year = y };
  int id = (ib->size) + 1;
  struct Email e = {.sent_date = d1, .ID = id};
  strcpy(e.sender, s);
  strcpy(e.subject, sub);
  strcpy(e.receiver, r);
  strcpy(e.body, b);
  ib->emails[ib->size] = e;
  ib->size = (ib->size)+1;
}

void display_inbox_menu(struct Mailbox* ib){
  int i = 0, id1;
  char str[10];
  while(i != 7){
    printf("***************   dharamsiss Inbox  ****************\n"   );
    printf("***************  Total Inbox: %04d  ****************\n",  ib->size );
    printf("\n");
    printf("1. Show Inbox \n");
    printf("2. Show Email by ID \n");
    printf("3. Sort Inbox by Sender \n");
    printf("4. Sort Inbox by ID \n");
    printf("5. Search Inbox by Keyword \n");
    printf("6. Delete\n");
    printf("7. Exit Box \n");
    printf("\n");
    scanf("%d", &i);
    while(getchar() != '\n');
    switch(i){
      case 1:
//	printf("%d", i);
	printf("\n");
        showInbox(ib);
	printf("\n");
        break;
      case 2:
//	printf("%d", i);
	printf("\n");
        printf("Enter the ID of the email you want to read:\n");
        scanf("%d", &id1);
        emailByID(ib, id1);
	printf("\n");
        break;
      case 3:
//	printf("%d", i);
	printf("\n");
        sortInboxbySender(ib);
	printf("\n");
        break;
      case 4:
//	printf("%d", i);
	printf("\n");
        sortInboxbyId(ib);
	printf("\n");
        break;
      case 5:
//	printf("%d", i);
	printf("\n");
        printf("Enter the keyword you are searching for:\n");
        scanf("%s", str);
        printf("\n");
        searchByKeyword(ib, str);
	printf("\n");
        break;
      case 6:
//	printf("%d", i);
	printf("\n");
        printf("Enter the ID of the e-mail you want to delete:\n");
        scanf("%d", &id1);
//      printf("\n");
        deleteById(ib, id1);
        printf("Email with ID = %d is deleted", id1);
	printf("\n"); 
        break;
      case 7:
        printf("\n");
        printf("Exiting e-mail client - Good Bye!\n\n");
        break;
    } 
  }
}

void showInbox(struct Mailbox *ib){
  printf("ID   SENDER--------------   MM/DD/YYYY   Subject---------------- \n");
  printf("--   --------------------   ----------   ----------------------- \n");
  int i, j, dash;
  for(i=0; i<ib->size; i++){
    struct Email *e = ib->emails;
    struct Email e1 = e[i];
    int id = e1.ID;
    printf("%02d", id);
    printf(" - ");
    char *send = e1.sender;
    printf("%s", send);
    dash = 21 - strlen(send);
    for(j = 0;j < dash; j++){
      printf(" ");
    }
    printf("- ");
    struct date d = e1.sent_date;
    printf("%02d/%02d/%04d", d.month,d.day,d.year);
    printf(" - ");
    printf("%s", e1.subject);
    printf("\n"); 
  } 
}

void emailByID(struct Mailbox *ib, int idNum){
  struct Email *e = ib->emails;
  struct Email e1 = e[idNum-1];
  char *send = e1.sender;
  struct date d = e1.sent_date;
  printf("\n%s - %s\nEmail Recieved on: %02d/%02d/%04d\n\n%s\n\n", send, e1.subject, d.month,d.day,d.year,e1.body);
}

void sortInboxbySender(struct Mailbox *ib){
    int i;
    int j;
    int size = ib->size;
    struct Email temp;
    for (i=0; i<size; i++) {
        for (j=i+1; j<size; j++) {
            if (strcmp(ib->emails[i].sender,ib->emails[j].sender)>0) {
                temp = ib->emails[i];
                ib->emails[i] = ib->emails[j];
                ib->emails[j] = temp;
            }
        }
    }
}

void sortInboxbyId(struct Mailbox *ib) {
    int i;
    int j;
    int size = ib->size;
    struct Email temp;
    for (i=0; i<size; i++) {
        for (j=i+1; j<size; j++) {
            if (ib->emails[i].ID > ib->emails[j].ID) {
                temp = ib->emails[i];
                ib->emails[i] = ib->emails[j];
                ib->emails[j] = temp;
            }
        }
    }
}

void searchByKeyword(struct Mailbox *ib, char keyword[10]) {
	struct Mailbox* temp;
	temp = (struct Mailbox*)malloc(sizeof(struct Mailbox));
	temp->emails = malloc(sizeof(struct Email)*MAILBOX_SIZE);
	temp->size = 0;
	int i;
	int size = ib->size;
	int num = 0;
	int tempSize = temp->size;
	for (i=0; i<size; i++) {
		if(strstr(ib->emails[i].sender, keyword) || strstr(ib->emails[i].subject, keyword) || strstr(ib->emails[i].body, keyword)) {
	strcpy(temp->emails[num].sender, ib->emails[i].sender);
	strcpy(temp->emails[num].subject, ib->emails[i].subject);
	strcpy(temp->emails[num].body, ib->emails[i].body);
	temp->emails[num].sent_date.day = ib->emails[i].sent_date.day;
	temp->emails[num].sent_date.month = ib->emails[i].sent_date.month;
        temp->emails[num].sent_date.year = ib->emails[i].sent_date.year;
	temp->emails[num].ID = ib->emails[i].ID;
	num++;
	tempSize++;
}

}	
	temp->size = tempSize;
	showInbox(temp);
	free(temp->emails);
	free(temp);	
}

void deleteById(struct Mailbox *ib, int idNum){
  struct Email *e = ib->emails;
  int i;
  int j;
  for(i = idNum-1; i < ib->size; i++){
    j = i+1;
    *(e+i)=*(e+j);
  }
  ib->size = (ib->size)-1
;
}   
