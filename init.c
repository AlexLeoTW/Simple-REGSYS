#include "pgmhead"

void initalRegArray(struct Student* regArray, int size)
{
    int i=0;
    for(i=0; i< size; i++)
    {
        strcpy(regArray[i].ActFlag, "y");
        strcpy(regArray[i].StudentID, "D9999999");
        strcpy(regArray[i].StudentName, "xxxxxxxxxxxxxxxxxxxx");
        regArray[i].TotCoursePoints = 0;
        regArray[i].TotalCredits = 0;
        regArray[i].Average = 0.0;
        regArray[i].FirstCourse = NULL;
    }
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
