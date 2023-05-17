#ifndef CMSC257_P2SUPPORT_INCLUDED
#define CMSC257_P2SUPPORT_INCLUDED

//Sohum Dharamsi
//CMSC 257
//Project Description: In this project you are to create a menu driven email client. The email client should be able to display the inbox, display email, search emails by keyword, sort inbox emails in inbox by sender, sort emails in inbox by ID, and delete emails in inbox by ID.
//11.10.22

#define MAILBOX_SIZE 2000
#define ADDRESS_SIZE 50
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
#define user_email "dharamsiss@vcu.edu"


//add other define Macros as needed

struct date
{
  int month;
  int day;
  int year;
};

struct Email
{
  char sender[ADDRESS_SIZE];
  char receiver[ADDRESS_SIZE];
  char subject[SUBJECT_SIZE];
  char body[BODY_SIZE];
  struct date sent_date;
  int ID;
  //add other struct members as needed
  //consider adding a nested struct here
};

struct Mailbox
{
  struct Email *emails;
  int size;
  //add other struct members as needed
};

///////////////////////////////////////////////////////////////////////////////
// This is a sample comment for the initialize function
// You should include a similar comment for each function declared within the 
// 	.h file
//
// Function     : initialize
// Description  : Initializes the database for CMSC257 project #2 by manually 
//                entering the records using create_email function
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void

void initialize(struct Mailbox *ib);

//add other function declarations as needed

#endif // CMSC257_P2SUPPORT_INCLUDED
