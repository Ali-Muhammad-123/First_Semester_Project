#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//all functions
void addcour();
void search();
void searchcour();
void coursemenu();
void courseview();
void insert();
void view();
void viewcri();
void del();
void delcour();
void update();
void mainmenu();
void studmenu();
void resmenu();
void edit();
void newcri();

int main()
{
    char choice;
    do{
        system("cls"); //clears screen
    FILE *filestud ,*fileres , *filestdres ,*filecour;
    int c,c1;
    filestud = fopen("STUDENTS.txt" , "a+");  //a+ is the mode used to enable append and read
    fileres = fopen("RESULTS.txt" , "a+");
    filecour = fopen("COURSES.txt" , "a+");
    filestdres = fopen("STUDENTS_RESULTS.txt" , "a+");
    mainmenu(); //menu is displayed

scanf("%d" , &c);

    if(c == 1)
    {
        studmenu(); //student menu is displayed
        scanf("%d" , &c1);
switch(c1){
case 1 : search(filestud) ;break;
case 2 : filestud = fclose(filestud);
    filestud = fopen("STUDENTS.txt" , "r+");  //filetype is changed to r+ to enable fseek function to work properly
update(filestud) ;break;
case 3 : filestud = fclose(filestud);
    filestud = fopen("STUDENTS.txt" , "r+");   //filetype is changed to r+ to enable fseek function to work properly
     del(filestud) ; break;
case 4 : view(filestud) ;break;
case 5 : insert(filestud) ;break;
case 6 : main() ;break;
 }
    }
    else if ( c == 2)
    {
        resmenu();

          scanf("%d" , &c1);
switch(c1){
case 1 : fileres = fclose(fileres) ;fileres = fopen("RESULTS.txt" , "r+"); edit(fileres);break;
case 2 : viewcri(fileres) ;break;
case 3 : fileres = fclose(fileres) ;fileres = fopen("RESULTS.txt" , "w+"); newcri(fileres);break;  //filetype is changed to w+ to delete all previous data and store new criteria

case 4 : main();break;
}
 }

else if (c== 3 )
{
    coursemenu();
   scanf("%d" , &c1);
switch(c1){
case 1 : courseview(filecour);break;
case 2 : addcour(filecour) ;break;
case 3 : filecour = fclose(filecour);
    filecour = fopen("COURSES.txt" , "r+");delcour(filecour);break;
case 4 : searchcour(filecour);break;
case 5 : main();break;
}

}

else if( c == 4)
{
    char id[2],id1[2] ,fname[100],lname[100],add[100] ,ch ,grade[2];
    int  i=0,id3, entid , finid, flag =0;
    view(filestud);
    rewind(filestud);
    printf("\n\nEnter the ID of the Student to assign the grade to :");
    scanf("%d" , &entid);

    while(!feof(filestud))
            {
        fscanf(filestud,"%s%s%s",id1,fname,lname);


        fgets(add,32,filestud);

        sscanf(id1 , "%d" , &finid);        //sscanf is used to convert string value to int and store it in another variable

        if(entid == finid)
        {
        printf("\nID\tFirst Name\tLast Name\t Address");
                printf("\n%s\t%s\t\t%s\t%s\n\n",id1,fname,lname,add);
                break;
}}

fprintf(filestdres,"%2s\t%10s\t%10s\t%30s" , id1,fname,lname ,add);

 char courname[32],insname[32] ;

courseview(filecour);
rewind(filecour);       //rewind is used to get to the top of the file
printf("\n\nEnter the ID of the course you want to assign the grade of : ");
scanf("%d", &entid);
        while(!feof(filecour))
            {

        fscanf(filecour,"%s",id1);

        fgets(courname , 32 ,filecour);

        fgets(insname, 32 ,filecour);

        sscanf(id1 , "%d" , &finid);

        if(entid == finid)
        {

    printf("\n ID  |            COURSE NAME            |        INSTURCTOR'S NAME\n");

    printf("  %2s | %30s   |  %30s\n" , id1,courname,insname);
    break;
        }
            }

    fprintf(filestdres ,"%2s %30s %30s" , id1,courname ,insname);
            viewcri(fileres);
    printf("\nEnter the grade to be assigned to that course : ");
            scanf("%s" , &grade);
        fprintf(filestdres ,"%2s" , grade);

}

else if( c == 5)
{
 char record[126];

        rewind(filestdres);
printf("ID  |           STUDENT NAME           |                ADDRESS               |C. ID|        COURSE NAME        |     INSTRUCTOR'S NAME        | GRADE\n\n");
do{
        fgets(record,125 , filestdres);
    puts(record);
    printf("\n");

}while(!feof(filestdres));

}
printf("\nDo you want to perform any other operation (Y/N) : ");
scanf(" %c" , &choice);

   fclose(filecour);
   fclose(fileres);
   fclose(filestdres);
   fclose(filestud);

   }while(choice == 'Y' || choice == 'y' );

    return 0;
}


void searchcour(FILE* filecour) //Searches the requested course
{
    char id[2],id1[2] ,courname[32],insname[32] ,ch ,grade[2];
    int  i=0,id3, entid , finid, flag =0;

              printf("\n-----SEARCH COURSE-----\n");
        printf("\nEnter ID of the course to be searched: ");
        scanf("%d", &entid);
        while(!feof(filecour))
            {

        fscanf(filecour,"%s",id1);

        fgets(courname , 32 ,filecour); //fgets is used because the string might contain spaces

        fgets(insname, 32 ,filecour);

        sscanf(id1 , "%d" , &finid);

        if(entid == finid)
        {

    printf(" ID  |            COURSE NAME            |        INSTURCTOR'S NAME\n");

    printf("  %2s | %30s   |  %30s\n" , id1,courname,insname);
           flag = 1;
        break;

        }}

if(flag==0)
{
    printf("Record not found");
}


}

void delcour(FILE* filecour) //deletes the course
{
    char id[2],id1[2] ,courname[32],insname[32] ,ch ,grade[2];
    int  i=0,id3, entid , finid, flag =0;

              printf("\n-----DELETE COURSE-----\n");
        printf("\nEnter ID of the course to be deleted: ");
        scanf("%d", &entid);
        while(!feof(filecour))
            {

        fscanf(filecour,"%s",id1);

        fgets(courname , 32 ,filecour);

        fgets(insname, 32 ,filecour);

        sscanf(id1 , "%d" , &finid);

        if(entid == finid)
        {

    printf(" ID  |            COURSE NAME            |        INSTURCTOR'S NAME\n");

    printf("  %2s | %30s   |  %30s\n" , id1,courname,insname);

        printf("\nDo you want to delete this record? Y or N");
              scanf(" %c",&ch);
        if (ch == 'Y'||ch == 'y' )
        {
            fseek(filecour,-64,SEEK_CUR);

            strcpy(id , "");    //strcpy is used to out empty spaces in variables
strcpy(courname , "");
strcpy(insname , "");

    fprintf(filecour ,"%2s %30s %30s" , id,courname ,insname);        }
        flag = 1;
        break;
        }
}
if(flag==0)
{
    printf("Record not found");
}



}


void courseview(FILE* filecour) //displays all the courses
{
    char id[3] , courname[32] , insname[32];
    printf("ID |           COURSE NAME             |       INSTURCTOR'S NAME\n\n");
    do{
            fflush(stdin);
            fgets(id,3,filecour);
fflush(stdin);
            fgets(courname,32,filecour);
fflush(stdin);
            fgets(insname,32,filecour);
 if (strcmp(id ,"P@")==0)                       //if no records are present the variable was grabbing "P@" from the file
        {
      printf("No records are present");
      break;
        }

    printf("%2s | %31s   |%s\n\n" , id,courname,insname);

    }while(!feof(filecour));
}

void addcour(FILE* filecour) //adds new courses
{

    char id[3] ,courname[32] ,insname[32] ;
    int finid;

       while(!feof(filecour))
            {
fflush(stdin);
            fgets(id,3,filecour);
            fflush(stdin);
        fgets(courname , 32 ,filecour);
fflush(stdin);
        fgets(insname, 32 ,filecour);

            }
       if (strcmp(id ,"P@")==0) //if no records are present the variable was grabbing "P@" from the file
        {
            strcpy(id ,"0");
        }
        sscanf(id , "%d" , &finid); //last id is grabbed from the file and is them incremented to decide the next id of the course
        finid++;
    fflush(stdin);
    printf("Enter the Course Name : ");
    gets(courname);

    fflush(stdin);
    printf("Enter the Instructor's Name : ");
    gets(insname);

    fprintf(filecour ,"%2d %30s %30s" , finid,courname ,insname);
}

void update(FILE* filestud)  //updates a specific record
{
    char id[2],id1[2] ,fname[100],lname[100],add[100] ,ch;
    int  i=0,id3, entid , finid, flag =0;
              printf("\n-----UPDATE RECORDS-----\n");
        printf("\nEnter ID of the record to be replaced: ");
        scanf("%d", &entid);
        while(!feof(filestud))
            {
        fscanf(filestud,"%s%s%s",id1,fname,lname);


        fgets(add,32,filestud);

        sscanf(id1 , "%d" , &finid);

        if(entid == finid)
        {
        printf("\nID\tFirst Name\tLast Name\t Address");
                printf("\n%s\t%s\t\t%s\t%s ",id1,fname,lname,add);

        printf("\nDo you want to update this record? Y or N : ");
              scanf(" %c",&ch);
        if (ch == 'Y'||ch == 'y' )
        {
    printf("Enter the First Name : ");
    scanf("%s" , &fname);
    printf("Enter the Last Name : ");
    scanf("%s" , &lname);
fflush(stdin);
    printf("Enter Address : ");
    gets(add);
fseek(filestud,-54,SEEK_CUR);       //Pointer is set to the start of the record
    fprintf(filestud ,"%2d\t%10s\t%10s\t%30s" , finid,fname,lname ,add);

        }
        flag = 1;
        break;
        }
}
if(flag==0)
{
    printf("Record not found");
}


}

void del(FILE* filestud) //deletes a specific record
{
    char id[2],id1[2] ,fname[100],lname[100],add[100] ,ch;
    int  i=0,id3, entid , finid, flag =0;
              printf("\n-----DELETE RECORDS-----\n");
        printf("\n\nEnter ID of the record to be deleted: ");
        scanf("%d", &entid);
        while(!feof(filestud))
            {
        fscanf(filestud,"%s%s%s",id1,fname,lname);


        fgets(add,32,filestud);

        sscanf(id1 , "%d" , &finid);

        if(entid == finid)
        {
        printf("\nID\tFirst Name\tLast Name\t Address");
                printf("\n%s\t%s\t\t%s\t%s ",id1,fname,lname,add);

        printf("\nDo you want to delete this record? Y or N");
              scanf(" %c",&ch);
        if (ch == 'Y'||ch == 'y' )
        {
            strcpy(id1," ");
             strcpy(fname," ");
              strcpy(lname," ");
               strcpy(add," ");
        fseek(filestud,-54,SEEK_CUR); //filepointer is set to the start of file

    fprintf(filestud ,"%2s\t%10s\t%10s\t%30s" , id1,fname,lname ,add);

        }
        flag = 1;
        break;
        }
}
if(flag==0)
{
    printf("Record not found");
}



}

void view(FILE* filestud) //Views all records present in file
{ char id[2],id1[2] ,fname[100],lname[100],add[100];
    int entid , finid ,flag;
    flag=0;
        printf("\n-----VIEW ALL RECORDS-----\n");

        printf("\nID\tFirst Name\tLast Name\t\tAddress\n");
        do
            {
        fscanf(filestud,"%s%s%s",id1,fname,lname);
        fgets(add,32,filestud);

                printf("\n%s\t%s\t\t%s%s\n",id1,fname,lname,add);

        }while(!feof(filestud)); //loop runs until the end of file

}
void search(FILE* filestud) //searches for a specific record
{
    char id[2],id1[2] ,fname[100],lname[100],add[100];
    int entid , finid ,flag;
    flag=0;
        printf("\n-----SEARCH RECORDS-----\n");
        printf("\nEnter ID : ");
        scanf("%d", &entid);
        while(!feof(filestud))
            {
        fscanf(filestud,"%s%s%s",id1,fname,lname);


        fgets(add,32,filestud);

        sscanf(id1 , "%d" , &finid);

        if(entid == finid)
        {
        printf("\nID\tFirst Name\tLast Name\t\tAddress");
                printf("\n%s\t%s\t\t%s%s",id1,fname,lname,add);

        flag = 1;
        break;
        }
}
if(flag==0)
{
    printf("Record not found");
}
        printf("\n\n");

}

void studmenu ()  //Displays the student menu
{
    printf("\n\n\n\t\t========== STUDENTS ========== \n\n 1 : Search \n 2 : Update \n 3 : Delete \n 4 : View \n 5 : Insert\n 6 : Back \n Choose an option : ");
}

void resmenu ()  //Displays the results menu
{
    printf("\n\n\n\t\t========== RESULTS ========== \n\n 1 : Update \n 2 : View \n 3: Set a new criteria \n 4 : Back \n Choose an option : ");
}


void coursemenu () //Displays the course menu
{
    printf("\n\n\n\t\t========== Courses ========== \n\n 1 : View \n 2 : Add a new course \n 3 : Delete a course \n 4 : Search for a course \n 5 : Back \n Choose an option : ");
}


void mainmenu ()  //Displays the main menu
{
    printf("\n\t\t========== WELCOME TO STUDENT RESULT MANAGER ========== \n\n 1 : Student \n 2 : Results \n 3 : Courses \n 4 : Insert New Record \n 5 : Show all records \n Choose an option : ");

}

void insert (FILE* filestud)  //inserts a new record into the student file
{

    char rec[100] , id1[2] ,fname[100] ,lname[100],add[100] ;
    int entid ,record , finid;
    int c;
    rewind(filestud);
    do
            {
        fscanf(filestud,"%s%s%s",id1,fname,lname);


        fgets(add,32,filestud);

                if (strcmp(id1 ,"a")==0)
        {
            strcpy(id1 ,"0");
        }

        sscanf(id1 , "%d" , &finid);
        finid++;


}while(!feof(filestud));

    printf("Enter the First Name : ");
    scanf("%s" , &fname);
    printf("Enter the Last Name : ");
    scanf("%s" , &lname);
    fflush(stdin);
    printf("Enter Address : ");
    gets(add);

    fprintf(filestud ,"%2d\t%10s\t%10s\t%30s" , finid,fname,lname ,add);
}
void newcri(FILE* fileres)  //sets a new criteria
{
    int markrange=100 ; // hihgest mark range
    char grade[2];
    do {
        printf("Enter the grade for %d to %d : " ,markrange , markrange -10);
        scanf("%s" , &grade);
        fprintf(fileres , "%3d %3d %s" ,markrange , markrange -10 , grade );


        markrange = markrange-10;
    } while (markrange-10> 0);
}
void viewcri(FILE* fileres)  //views the current criteria
{
    char markrangeu[3] , markrangel[3] , grade[2];
    printf("\nGRADE RANGE | GRADE\n");
    do{
    fscanf(fileres,"%s %s %s" , markrangeu,markrangel,grade);
    printf("  %3s - %2s   |  %s\n" , markrangeu,markrangel,grade);

    }while(!feof(fileres));
}
void edit(FILE* fileres)  //edits a specific grade range
{
char frange1[3] , frange2[3]  ,grade[2] ,ch;
 int range1,range2 , intrange1 ,intrange2;
 int flag =0 ,pos2,pos1;
 printf("Enter the range you want to edit (eg 100-90) : ");
 scanf("%d-%d" , &range1 , &range2);
do
{
 fscanf(fileres,"%s %s %s" ,frange1,frange2 ,grade);
sscanf(frange1 , "%d" , &intrange1);
sscanf(frange2 , "%d" , &intrange2);

 if(range1 == intrange1 && range2 == intrange2)
        {
        printf("\n\nGRADE RANGE | GRADE\n");
    printf("  %3s - %2s   |  %s\n" , frange1,frange2,grade);
        flag = 1;

           printf("\nDo you want to edit this criteria? Y or N");
              scanf(" %c",&ch);

        if (ch == 'Y'||ch == 'y' )
        {
            fseek(fileres,-1 , SEEK_CUR);   //pointer is set to the start of the grade
            printf("Enter the new grade : ");
            scanf("%s" , &grade);
            fprintf(fileres,"%s" , grade);
        }
        break;
        }

}while(!feof(fileres));

if(flag==0)
{
    printf("Record not found");
}
        printf("\n\n");

}


