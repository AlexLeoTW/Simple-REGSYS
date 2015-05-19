#include "pgmhead"

void printRegArray(struct Student* regArray, int size)
{
    printf("=======================================================================\n");
    printf("No. Act ID       Name                 Total_Point Total_Credits Average\n");

    int i=0;
    for(i=0; i< size; i++)
    {
        printf("%3d ", i+1);
        printf("%2s  ", regArray[i].ActFlag);
        printf("%8s ", regArray[i].StudentID);
        printf("%-20s ", regArray[i].StudentName);
        printf("%9d   ", regArray[i].TotCoursePoints);
        printf("%5d         ", regArray[i].TotalCredits);
        printf("[%3.2f]", regArray[i].Average);
        printf("\n");
    }

    printf("=======================================================================\n");
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
