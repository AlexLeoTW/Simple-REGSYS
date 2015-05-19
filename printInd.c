#include "pgmhead"

void printIndividual(struct Student* student, int size)
{
    char studentID[9] = "";
    int stuPos = -1;

    printf("Please enter the student ID for printing\n > ");
    scanf("%s", studentID);
    stuPos = searchStudent(student, studentID, size);
    if (stuPos != -1)
    {
        printf("Name: %s\n", student[stuPos].StudentName);
        printf("Student ID: %s\n", student[stuPos].StudentID);
        printCourseList(student[stuPos].FirstCourse);
        printf("Total Course Points: %d\n", student[stuPos].TotCoursePoints);
        printf("Total Credits: %d\n", student[stuPos].TotalCredits);
        printf("Average: %.2f\n", student[stuPos].Average);
    }
    else
    {
        printf("Warning, no student match ID [%s]\n", studentID);
    }
}

void printCourseList(struct Course* course)
{
    struct Course* temp = course;

    printf("+----------+---+\n");
    while (temp != NULL)
    {
        printf("|%10s|%3d|\n", temp->CurseCode, temp->Score);
        temp = temp->NextCourse;
    }
    printf("+----------+---+\n");
}

/**********************************************************************
struct Student
{
    char ActFlag[2];            // initial value = y\0  suspend = n\0
    char StudentID[9];          // initial value = D9999999\0
    char StudentName[21];       // initial value = all 'x' & \0
    int TotCoursePoints;        // initial value = 0
    int TotalCredits;           // initial value = 0
    float Average;              // initial value = 0.00
    struct Course* FirstCourse; // initial value = null
};
**********************************************************************/

/**********************************************************************
struct Course
{
    struct Course* NextCourse;
    char CurseCode[10];         // value = course code + \0
    int Sourse;
};
**********************************************************************/
