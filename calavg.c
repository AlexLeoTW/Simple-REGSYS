#include"pgmhead"

void calculateAvg(struct Student* regArray, int size, struct Credit* credit)
{
    int i=0;
    for (i=0; i<size; i++)
    {
        if (regArray[i].FirstCourse != NULL)
        {
            printf("Caculating student %d\n", i);
            int totalPoint = calculateTotalPoint(regArray[i].FirstCourse, credit);
            regArray[i].TotCoursePoints = totalPoint;
            regArray[i].Average = regArray[i].TotCoursePoints/regArray[i].TotalCredits;
            printf("  Result: Total Course Point = %d, Average = %f\n", totalPoint, regArray[i].Average);
        }
    }
}

int calculateTotalPoint(struct Course* course, struct Credit* credit)
{
    int totalPoint = 0;
    struct Credit* tempCredit = NULL;
    while (course!=NULL)
    {
        if (course == NULL)
            printf("Fetal ERROR\n");
        tempCredit = searchCredit(credit, course->CurseCode);
        if ( tempCredit != NULL )
        {
            printf("CourseCode Match, ");
            totalPoint += course->Score*tempCredit->CourseCredit;
            printf(" Total Point = %d*%d\n", course->Score, tempCredit->CourseCredit);
        }
        else
        {
            printf("Warning: No matched course code found [%s, %d] is ignored\n", course->CurseCode, course->Score);
        }

        course = course->NextCourse;
    }

    return totalPoint;
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
