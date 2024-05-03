#include <stdio.h>
#include <stdlib.h>


void main()
{
    int choice_1;                             //variables
    int admin_PW;
    static int PW=1234;
    int choice_admin;
    int choice_student;

    int attempt=0;

    printf("=====STUDENT APP=====\n");        //main interface (1)
    printf("1. Admin mode \n");
    printf("2. Student mode \n");
    scanf("%d",&choice_1);
    system("cls");                            //clearing the screen (looks very cool :D)

    if(choice_1==1)                           //[admin interface (2)]
    {
        for(int i = 0; i < 3; i++)            //check password
        {
            printf("Enter password: ");
            scanf("%d",&admin_PW);
            if(admin_PW==PW)
            {
                system("cls");
                attempt=1;
                break;
            }
            else
            {
                printf("wrong password, attempts remaining: %d \n", 2-i);
                printf("__________________\n");
            }
        }

        if(attempt==1)                         //admin options
        {
            printf("=====Admin mode====== \n");
            printf("1. Add student record \n");
            printf("2. Remove student record \n");
            printf("3. View student record \n");
            printf("4. View all records \n");
            printf("5. Edit admin password \n");
            printf("6. Edit student grade \n");
            scanf("%d",&choice_admin);
            system("cls");

            switch(choice_admin)              //calling admin functions
            {
            case 1:
                printf("Student add \n");
                //Student_Add();
                break;
            case 2:
                printf("Student remove \n");
                //Student_Remove();
                break;
            case 3:
                printf("Student view \n");
                //Student_View();
                break;
            case 4:
                printf("All Records \n");
                //All_view();
                break;
            case 5:
                printf("Enter new password: ");
                scanf("%d",&PW);
                break;
            case 6:
                printf("Student grade edit");
                //Student_GradeEdit();
                break;
            default:
                printf("Please pick a valid choice");
                break;
            }
        }
    }
    else if(choice_1==2)                       //student interface (3)
    {
        printf("Enter user ID: \n");
        //scanf("%d",&user_ID);
        printf("Enter user Password: \n");
        //scanf("%d",&user_PW);
        if(1)                                 //condition for student password
        {
            printf("=====Student Mode===== \n");
            printf("1. View your record \n");
            printf("2. Edit your password \n");
            printf("3. Edit your name \n");
            scanf("%d",&choice_student);

            switch (choice_student)
            {
            case 1:
                printf("View Student record \n");
                //Student_View();
                break;
            case 2:
                printf("Edit Student password \n");
                //Student_EditPW;
                break;
            case 3:
                printf("Edit Student name \n");
                //Student_EditName;
            }
        }

    }
    else
    {
        printf("Please pick a valid choice \n");
    }
    int rerun;
    printf("would u like to run the program again? 1.(yes)  2.(no): ");
    scanf("%d",&rerun);
    if(rerun==1)
    {
        system("cls");
        main();
    }
}
