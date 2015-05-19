#include "pgmhead"

void suspend(struct Student* regArray, int size)
{
    char studentID[9] = "";
    int studentPos = 0;

    printf("Please enter the student ID to set as suspended\n > ");
    scanf("%s", studentID);
    studentPos = searchStudent(regArray, studentID, size);
    //printf("found @%d\n", studentPos);
    if (studentPos != -1)
    {
        strcpy( regArray[studentPos].ActFlag, "n" );
        clearCourse( &regArray[studentPos].FirstCourse );
        regArray[studentPos].TotCoursePoints = 0;
        regArray[studentPos].TotalCredits = 0;
        regArray[studentPos].Average = 0;
        printf("Student ID [%s] is now set to suspended\n", studentID);
    }
    else
    {
        printf("Warning, student not found, no recoed updated\n");
    }
}

void clearCourse(struct Course** courseToRemove)
{
    struct Course* coursePtr = *courseToRemove;
    struct Course* tempPtr = *courseToRemove;
    while (coursePtr != NULL)
    {
        tempPtr = coursePtr;
        coursePtr = coursePtr->NextCourse;
        printf("Deleting Record: [%s, %d]\n", tempPtr->CurseCode, tempPtr->Score);
        free(tempPtr);
    }
    //printCourseList(coursePtr);
    *courseToRemove = coursePtr;
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
    int Score;
};
**********************************************************************/
