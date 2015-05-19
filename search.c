#include "pgmhead"

int searchStudent(struct Student* regArray, char* studentID, int size)
{
    int i= 0;
    for (i=0; i<size; i++)
    {
        //printf("search %s @%d\n", studentID, i);
        //printf("compare with %s", regArray[i].StudentID);
        //printf(" = %d\n", strcmp(regArray[i].StudentID, studentID));
        if ( strcmp(regArray[i].StudentID, studentID) == 0 )
        {
            //printf("%s found @%d\n", studentID, i);
            return i;
        }
    }
    return -1;
}

struct Credit* searchCredit(struct Credit* credit, char* courseCode)
{
    while (credit!=NULL)
    {
        if (strcmp(credit->CurseCode, courseCode) == 0)
        {
            printf("Found data pair match course code %s: [%s, %d]\n", courseCode, credit->CurseCode, credit->CourseCredit);
            return credit;
        }

        credit = credit->NextCourse;
    }
    return NULL;
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
