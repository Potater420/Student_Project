#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    int grade;
    int id;
    int age;
    char gender[10];
    int pw;
}Student;  //to define new struct don't do "Struct Student students".Instead, do "Student students"



void View_All(int records,Student students[100])  //display struct (student) info
{
    printf("the number of records read: %d \n", records);
    printf("the students: \n");

    for(int i=0;i<records;i++)     //(2) display struct (student) info
    {
        printf("Name: %s, Grade: %d, ID: %d, Age: %d, Gender: %s, \n",students[i].name,
                                                                     students[i].grade,
                                                                     students[i].id,
                                                                     students[i].age,
                                                                     students[i].gender);
    }

}

void View_Student(int records,int id,Student student1[100]) //display one student
{
    for(int i = 0;i<records;i++)
        {
               if(student1[i].id==id)
            {
                   printf("Name: %s, Grade: %d, ID: %d, Age: %d, Gender: %s  \n",student1[i].name,
                                                                                 student1[i].grade,
                                                                                 student1[i].id,
                                                                                 student1[i].age,
                                                                                 student1[i].gender);
            }
        }
}


void Delete_Student(int records,int id,Student students[100])
{
    FILE *file;
    file=fopen("new.csv","w");

    for(int i = 0;i<records;i++)     //loop to check which student to be removed
        {
            if(students[i].id==id)
            {
                  continue;
            }
            else
            {
                  fprintf(file,"%s,%d,%d,%d,%s,%d\n",students[i].name,
                                                         students[i].grade,
                                                         students[i].id,
                                                         students[i].age,
                                                         students[i].gender,
                                                         students[i].pw);

            }
        }
        fclose(file);
        remove("file.csv");
        rename("new.csv","file.csv");

}

Edit_Student(int records,int id,Student students[100])
{
    int grade;
    printf("Enter new grade: ");
    scanf("%d",&grade);
    FILE *file;
    file=fopen("new.csv","w");

    for(int i = 0;i<records;i++)     //loop to check which student to be removed
        {
            if(students[i].id==id)
            {
                                  fprintf(file,"%s,%d,%d,%d,%s,%d\n",students[i].name,
                                                         grade,
                                                         students[i].id,
                                                         students[i].age,
                                                         students[i].gender,
                                                         students[i].pw);

            }
            else
            {
                  fprintf(file,"%s,%d,%d,%d,%s,%d\n",students[i].name,
                                                         students[i].grade,
                                                         students[i].id,
                                                         students[i].age,
                                                         students[i].gender,
                                                         students[i].pw);

            }
        }
        fclose(file);
        remove("file.csv");
        rename("new.csv","file.csv");
}
void Add_Student(int records,Student students[100])
{
    int grade,id,age,pw;
    char name[50],gender[10];

    FILE *file;
    file=fopen("file.csv","a");

    printf("Enter student name: ");
    scanf("%s", name);

    printf("Enter student grade: ");
    scanf(" %d", &grade);

    printf("Enter student ID: ");
    scanf("%d", &id);

    printf("Enter student age: ");
    scanf("%d", &age);

    printf("Enter student gender (M/F): ");
    scanf(" %s", gender);

    printf("Enter student password: ");
    scanf("%d", &pw);

    fprintf(file,"%s,%d,%d,%d,%s,%d\n",name,grade,id,age,gender,pw);
}


int main()
{
    int id=0;
    int pw=0;
    FILE *file;
    file =fopen("file.csv", "r");   //file type .csv (i don't remember why)

    if(file==NULL)                 //check if the file oppened correctly
    {
        printf("Error opening the file \n");
        exit(-1);
    }
    printf("Opened file \n");

    Student students[100];
    int records=0;                  // counter for the array of structs

    do                              //(1) reads info from file to struct
    {
        fscanf(file,"%49[^,], %d, %d, %d, %9[^,], %d  \n",students[records].name,
                                                         &students[records].grade,
                                                         &students[records].id,
                                                         &students[records].age,
                                                         students[records].gender,
                                                         &students[records].pw);

        records++;
    }while(!feof(file));          //as long as it's not the end of the file, it keeps reading
    printf("\n");


    fclose(file);                //successfully copied the information from the file to struct array

    int user_choice;
    printf("Enter which action you'd like to do \n");
    printf("1. Print all students \n");
    printf("2. Print a certain student \n");
    printf("3. delete a certain student \n");
    printf("4. Edit student grade \n");
    printf("5. Add student \n");
    printf("Your choice: ");
    scanf("%d",&user_choice);
    printf("======================\n");

    switch (user_choice)
    {
    case 1:
        View_All(records,students);
        break;
    case 2:
           printf("Enter id of student to View their grades: ");
           scanf("%d",&id);    // View_Student(records,id,students); -> calling function when password entered correctly
           printf("Enter password: ");
           scanf("%d",&pw);

           for(int i = 0;i<records;i++)
           {
               if(students[i].id==id) //id check
               {
                   if(students[i].pw==pw) //pw check
                   {
                       View_Student(records,id,students);
                       break;
                   }
                   else
                   {
                       printf("Wrong password!");
                       exit(-1);
                   }
               }

           }


        break;
    case 3:
           printf("Enter id of student to Delete their grades: ");
           scanf("%d",&id);    // Delete_Student(records,id,students); -> calling function when password entered correctly
           printf("Enter password: ");
           scanf("%d",&pw);

           for(int i = 0;i<records;i++)
           {

               if(students[i].id==id) // id check
               {
                   if(students[i].pw==pw) // pw check
                   {
                       Delete_Student(records,id,students);  //records= number of students, id=id given by user, students= passing the struct information
                       break;
                   }
                   else
                   {
                       printf("Wrong password!");
                       exit(-1);
                   }
               }

           }
        break;
    case 4:
           printf("Enter id of student to Edit their grades: ");
           scanf("%d",&id);    // Delete_Student(records,id,students); -> calling function when password entered correctly
           printf("Enter password: ");
           scanf("%d",&pw);

           for(int i = 0;i<records;i++)
           {

               if(students[i].id==id) // id check
               {
                   if(students[i].pw==pw) // pw check
                   {
                       Edit_Student(records,id,students);  //records= number of students, id=id given by user, students= passing the struct information
                       break;
                   }
                   else
                   {
                       printf("Wrong password!");
                       exit(-1);
                   }
               }

           }
        break;
    case 5:
        Add_Student(records,students);
        break;

    }


    return 0;
}
