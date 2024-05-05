#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100
FILE *my_file =NULL;
FILE *temp_file =NULL;
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

typedef enum
{
    Male,
    Female
}Gender;

struct Node{
    unsigned int id;
    Gender gender_type;
    unsigned char name[50];
    unsigned int age;
    char password[30];
    unsigned int grade;
    struct Node *NodeLink;
};


void Add_Student(struct Node **List);
uint32 Get_Length(struct Node *List);
void read_data(struct Node **List, int *count);
void print_student(struct Node *List);
void Display_All_Nodes(struct Node *List);
void Delete_Node(struct Node **List);
void deleteLine( int line_number);


uint8 gender_str[10];
struct Node *ListHead = NULL;

int main()
{
    uint8 UserChoice = 0;
    int count = 0;
    int linesCount = 0;
    char buffer[1000];
    //uint32 ListLength = 0;
    my_file = fopen("test22222.txt","r");
    while (fgets(buffer, sizeof(buffer),  my_file) != NULL)
    {
        linesCount++;
    }
    my_file = fopen("test22222.txt","r");
    for(int i=0;i<linesCount;i++)
    {
        //fgets(data,95,my_file);
        read_data(&ListHead,&count);
    }

    printf("-> Hello to Single Linked List \n");
    while(1){
        printf("\n");
        printf("===============================\n");
        printf("-> 1) Add_Student \n");
        printf("-> 2) Display_All_Nodes \n");
        printf("-> 3) Delete_Node \n");
        printf("-> 4) Quit from application \n");
        printf("===============================\n");


        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);

        switch(UserChoice){
            case 1:
                Add_Student(&ListHead);
            break;
            case 2:
                Display_All_Nodes(ListHead);
            break;
            case 3:
                Delete_Node(&ListHead);
            break;
            case 4:
                printf("Quit from application \n");
                exit(1);
            break;
            default:
                printf("User Choice out of range !!\n");
            break;
        }
    }
    return 0;

}

void Add_Student(struct Node **List){
    my_file = fopen("test22222.txt","a");
    struct Node *TempNode = NULL;
    struct Node *LastNode = NULL;
    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
        printf("Enter Student Details:\n");
        printf("Enter id: ");
        scanf("%d", &TempNode->id);

        //char gender_str[10];
        int valid_gender = 0;
        while (!valid_gender) {
        printf("Enter gender (Male/Female): ");
        scanf("%s", gender_str);

        // مقارنة النص المدخل بالقيم الممكنة
        if (strcmp(gender_str, "Male") == 0) {
            TempNode->gender_type = Male;
            valid_gender = 1;
        } else if (strcmp(gender_str, "Female") == 0) {
            TempNode->gender_type = Female;
            valid_gender = 1;
        } else {
            printf("Invalid gender. Please enter again.\n");
        }
    }
        fflush(stdin);
        printf("Enter Name: ");
        gets(TempNode->name);
        printf("Enter Age: ");
        scanf("%d", &TempNode->age);
        printf("Enter pass: ");
        scanf("%s", &TempNode->password);
        printf("Enter grade: ");
        scanf("%d", &TempNode->grade);

        TempNode->NodeLink = NULL;
        if(NULL == *List)
        {
            *List = TempNode;
        }
        else
        {
            LastNode = *List;
            while(LastNode->NodeLink != NULL)
            {
                LastNode = LastNode->NodeLink;
            }
            LastNode->NodeLink = TempNode;
        }

    }
    if(NULL!=my_file)
    {
        fprintf(my_file, "%d,%s,%s,%d,%s,%d\n",TempNode->id
                                            ,TempNode->gender_type== Male ? "Male" : "Female"
                                            ,TempNode->name
                                            ,TempNode->age
                                            ,TempNode->password
                                            ,TempNode->grade);
    }
    fclose(my_file);
}

void read_data(struct Node **List, int *count)
{
    struct Node *LastNode = NULL;
    struct Node *TempNode = NULL;
    TempNode = (struct Node *)malloc(sizeof(struct Node));


    if(NULL != TempNode)
    {
        fscanf(my_file, "%d ,%[^,] ,%[^,],%d ,%[^,] ,%d \n",&TempNode->id, gender_str, TempNode->name
                                                ,&TempNode->age, TempNode->password, &TempNode->grade);
        if (strcmp(gender_str, "Male") == 0)
        {
        TempNode->gender_type = Male;
        }
        else if (strcmp(gender_str, "Female") == 0)
        {
        TempNode->gender_type = Female;
        }
        TempNode->NodeLink = NULL;
        if(NULL == *List)
        {
            *List = TempNode;
        }
        else
        {
            LastNode = *List;
            while(LastNode->NodeLink != NULL)
            {
                LastNode = LastNode->NodeLink;
            }
            LastNode->NodeLink = TempNode;
        }
    }

}
void Display_All_Nodes(struct Node *List)
{
    struct Node *TempNode = List;
    printf("Node Values : ");
    if(NULL == TempNode)
    {
        printf("List is empty !! \n");
    }
    else
    {
        while(TempNode != NULL)
        {
            printf("===============================\n");
            printf("id=%d\n",TempNode->id);
            printf("gender=%s\n",TempNode->gender_type== Male ? "Male" : "Female");
            printf("name=%s\n",TempNode->name);
            printf("age=%d\n",TempNode->age);
            printf("id=%s\n",TempNode->password);
            printf("grade=%d\n",TempNode->grade);
            printf("===============================\n");
            TempNode = TempNode->NodeLink;
        }
        if(NULL == TempNode)
        {
            printf("NULL \n");
        }

    }
}
void Delete_Node(struct Node **List){
    uint32 deleted_id=0;
    struct Node *TempNode = *List;
    struct Node *NodeListCounter = *List;
    //uint32 NodeCount = 0;
    struct Node *NextNode = *List;
    uint32 NodePosition = 0;
    //uint32 ListLength = 0;
    uint32 NodeCounter = 0;

    printf("Enter the id: ");
    scanf("%i", &deleted_id);

    if (TempNode == NULL)
    {
        printf("ID %d not found in the linked list.\n", deleted_id);

    }
    while(TempNode->id!=deleted_id)
    {
        NodeCounter++;
        TempNode = TempNode->NodeLink;
    }
    NodePosition=NodeCounter+1;
    NodeCounter = 1;
    if(NodePosition==1)
    {
        *List = TempNode->NodeLink;
        TempNode->NodeLink = NULL;
        free(TempNode);
    }
    else
    {
        while(NodeCounter < (NodePosition - 1))
        {
            NodeCounter++;
            NodeListCounter = NodeListCounter->NodeLink;
        }
        NextNode = NodeListCounter->NodeLink;
        NodeListCounter->NodeLink = NextNode->NodeLink;
        free(NextNode);
    }
    deleteLine( NodePosition);
}

void deleteLine( int line_number)
{
    char *old_file_name = "test22222.txt";
    char *new_file_name = "new.txt";
    my_file = fopen(old_file_name,"r");
    if (my_file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    temp_file = fopen(new_file_name, "w");
    if (temp_file == NULL)
     {
        printf("Error creating temporary file.\n");
        fclose(my_file);
        return;
    }

    char line[1000];
    int current_line = 1;
    while (fgets(line, sizeof(line), my_file) != NULL)
    {
        if (current_line != line_number)
        {
            fputs(line, temp_file);
        }
        current_line++;
    }
    fclose(my_file);
    fclose(temp_file);

   if (remove(old_file_name) != 0) {
        printf("Error deleting file");
    } else {
        rename(new_file_name,old_file_name);
        printf("File %s deleted successfully.\n", old_file_name);
    }
}




