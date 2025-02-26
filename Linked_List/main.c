#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

typedef struct
{
    int ID;
    char name[40];
    float height;
} S_data;

typedef struct S_student
{
    S_data Student;
    struct S_student *P_NextNode;
} S_student;

S_student *G_pFirstStudent = NULL;

void add_student()
{
    S_student *P_NewStudent;
    S_student *P_CurrentStudent;
    char temp_text[40];

    if (G_pFirstStudent == NULL)
    {
        P_NewStudent = (S_student *)malloc(sizeof(S_student));
        G_pFirstStudent = P_NewStudent;
    }
    else
    {
        P_CurrentStudent = G_pFirstStudent;
        // Search for the last node
        while (P_CurrentStudent->P_NextNode)
        {
            P_CurrentStudent = P_CurrentStudent->P_NextNode;
        }
        // Create new Node/Record
        P_NewStudent = (S_student *)malloc(sizeof(S_student));
        // Check if Memory allocation failed
        if (P_NewStudent == NULL)
        {
            printf("Memory allocation failed\n");
        }
        else
        {
            printf("New record created successfully\n");
            P_CurrentStudent->P_NextNode = P_NewStudent;
        }
    }
    // Fill new student information
    printf("Enter student ID: ");
    gets(temp_text);
    P_NewStudent->Student.ID = atoi(temp_text);

    printf("Enter student name: ");
    gets(P_NewStudent->Student.name);

    printf("Enter student height: ");
    gets(temp_text);
    P_NewStudent->Student.height = atof(temp_text);
}

void main(void)
{
    add_student();
    add_student();
    add_student();
}