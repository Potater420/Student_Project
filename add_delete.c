#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STUDENTS 100
FILE *my_file =NULL;

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

struct Node{
    unsigned int id;
    unsigned char name[50];
    unsigned int age;
    unsigned int grade;
    struct Node *NodeLink;
};


void Add_Student(struct Node **List);
uint32 Get_Length(struct Node *List);
void read_data(struct Node **List,uint8 *read_data, int *count);
void print_student(struct Node *List);
void Display_All_Nodes(struct Node *List);
void Delete_Node(struct Node *List);


uint8 data[50];
struct Node *ListHead = NULL;

int main()
{
    uint8 UserChoice = 0;
    int count = 0;
    int linesCount = 0;
    char buffer[1000];

    //ÇÓÊÑÌÇÚ ÇáÈíÇäÇÊ ãä ÇáãáÝ
    uint32 ListLength = 0;
    my_file = fopen("text_fun add.txt","r");
    while (fgets(buffer, sizeof(buffer),  my_file) != NULL)
    {
        linesCount++;
    }
    my_file = fopen("text_fun add.txt","r");
    for(int i=0;i<linesCount;i++)
    {
        fgets(data,95,my_file);
        read_data(&ListHead,read_data, &count);
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
                Delete_Node(ListHead);
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
    my_file = fopen("text_fun add.txt","a");
    struct Node *TempNode = NULL;
    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
        printf("Enter Student Details:\n");
        printf("Enter id: ");
        scanf("%d", &TempNode->id);
        printf("Enter Name: ");
        scanf("%s", &TempNode->name);
        printf("Enter Age: ");
        scanf("%d", &TempNode->age);
        printf("Enter grade: ");
        scanf("%d", &TempNode->grade);

        if(NULL == *List)
        {
            TempNode->NodeLink = NULL;
            *List = TempNode;
        }
        else
        {
            TempNode->NodeLink = *List;
            *List = TempNode;
        }

    }
    if(NULL!=my_file)
    {
        int length_name = strlen(TempNode->name);
        for (int i = 0; i < 50-length_name; i++)
        {
            strcat(TempNode->name, " ");
        }
        fprintf(my_file, "id: [%0*d] Name: [%s] Age: [%0*d] Grade: [%0*d]\n",4,TempNode->id
                                                                            ,TempNode->name
                                                                            ,3,TempNode->age
                                                                            ,3,TempNode->grade);
    }
    fclose(my_file);
}

void read_data(struct Node **List,uint8 *read_data, int *count)
{

    uint8 id[5]={0};
    uint8 name[51]={0};
    uint8 age[4]={0};
    uint8 grade[4]={0};

    strncpy(id,data+5,4);
    strncpy(name,data+18,50);
    strncpy(age,data+76,3);
    strncpy(grade,data+89,3);

    struct Node *TempNode = NULL;
    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
        TempNode->id=atoi(id);
        strncpy(TempNode->name,name,50);
        TempNode->age=atoi(age);
        TempNode->grade=atoi(grade);


        if(NULL == *List)
        {
            TempNode->NodeLink = NULL;
            *List = TempNode;
        }
        else
        {
            TempNode->NodeLink = *List;
            *List = TempNode;
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
            printf("name=%s\n",TempNode->name);
            printf("age=%d\n",TempNode->age);
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
void Delete_Node(struct Node *List){
    uint32 deleted_id=0;
    struct Node *TempNode = List;
    struct Node *NodeListCounter = List;
    //uint32 NodeCount = 0;
    struct Node *NextNode = List;
    uint32 NodePosition = 0;
    //uint32 ListLength = 0;
    uint32 NodeCounter = 0;

    printf("Enter the id: ");
    scanf("%i", &deleted_id);
    while(TempNode->id!=deleted_id)
    {
        NodeCounter++;
        TempNode = TempNode->NodeLink;
    }
    NodePosition=NodeCounter+1;
    NodeCounter = 1;
    if (TempNode == NULL)
    {
        printf("ID %d not found in the linked list.\n", deleted_id);

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
}



