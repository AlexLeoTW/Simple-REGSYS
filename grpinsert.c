#include "pgmhead"
#define FOUND 1
#define NOTFOUND 0

void groupInsert(struct Student* regArray, int size, struct Credit** credit)
{
    char filePath[30] = "";
    //char filePath[30] = "test_cs101.txt";
    char fileLine[30] = "";
    int courseCredit = 0;
    //int courseCredit = 3;
    FILE* studentFile = NULL;

    printf("Please enter path to the file to load:\n > ");
    scanf("%s", filePath);
    printf("Path = [%s]\n", filePath);
    studentFile = fopen(filePath, "r");

    if (studentFile != NULL)
    {
        char stuID[9] = "";
        char stuScore[5] = "";
        char courseCode[10] = "";
        //char courseCode[10] = "cs101";
        int stuPos = 0;

        printf("Please enter the course code:\n > ");
        scanf("%s", courseCode);
        printf("Please enter the course credit for %s:\n > ", courseCode);
        scanf("%d", &courseCredit);

        printf("Insert data pair [%s, %d] into credit list\n", courseCode, courseCredit);
        insertCredit(credit, courseCode, courseCredit);

        while( fgets(fileLine, 30, studentFile) != NULL )
        {
            if(fileLine[strlen(fileLine) - 1] == '\n')
                fileLine[strlen(fileLine) - 1] = '\0';
                // Remove Line Break(\n) Character

            strNcpy(stuID, fileLine, 0, 7);
            strNcpy(stuScore, fileLine, 9, strlen(fileLine)-1);

            printf("New Entry@: [%s]\n", fileLine);
            printf("  add: [%s]\n", courseCode);
            printf("  add: [%s]\n", stuID);
            printf("  add: [%s]\n", stuScore);

            stuPos = searchStudent(regArray, stuID, size);
            //printf("stuPos = %d\n", stuPos);
            if (insertCourse(&regArray[stuPos].FirstCourse, courseCode, atoi(stuScore)) )
            {
                printf("One Entry Updated!\n");
            }
            else
            {
                regArray[stuPos].TotalCredits += courseCredit;
                printf("One Entry Added!\n");
            }
            printf("Result:\n");
            printCourseList(regArray[stuPos].FirstCourse);\
            printf("\n");
        }
        fclose(studentFile);
    }
    else
    {
        printf("ERROR, file cannot be open.\n");
        printf("Please try again!\n");
    }
}

int insertCourse(struct Course** firstCourse, char* courseCode, int score)
{
    struct Course* coursePtr = (*firstCourse);
    struct Course* backworCcoursePtr = (*firstCourse);

    struct Course* newCourse = (struct Course*)calloc(sizeof(struct Course), 1);
    newCourse->NextCourse = NULL;
    strcpy( newCourse->CurseCode, courseCode );
    newCourse->Score = score;
    //printCourseList(newCourse);

    if (coursePtr == NULL)
    {
        *firstCourse = newCourse;
        return NOTFOUND;
    }
    else
    {
        while( coursePtr->NextCourse!=NULL && strcmp(coursePtr->CurseCode, courseCode)!=0 )
        {
            backworCcoursePtr = coursePtr;
            coursePtr = coursePtr->NextCourse;
        }

        if ( strcmp(backworCcoursePtr->CurseCode, courseCode)==0 )
        {
            //printf("%s == %s\n",backworCcoursePtr->CurseCode, courseCode);
            backworCcoursePtr->Score = score;
            return FOUND;
        }
        else
        {
            //printf("%s != %s\n",backworCcoursePtr->CurseCode, courseCode);
            backworCcoursePtr->NextCourse = newCourse;
            return NOTFOUND;
        }
    }
}

void insertCredit(struct Credit** headPtr, char* courseCode, int credit)
{
    struct Credit* tempPtr = (*headPtr);

    struct Credit* newCredit = (struct Credit*)calloc(sizeof(struct Credit), 1);
    strcpy(newCredit->CurseCode, courseCode);
    newCredit->CourseCredit = credit;
    newCredit->NextCourse = NULL;
    printf("New data pair generated [%s, %d]\n", newCredit->CurseCode, newCredit->CourseCredit);

    if (tempPtr == NULL)
    {
        *headPtr = newCredit;
    }
    else
    {
        if ( (tempPtr = searchCredit(tempPtr, courseCode)) == NULL)
        {
            tempPtr = *headPtr;

            while (tempPtr->NextCourse != NULL)
            {
                tempPtr = tempPtr->NextCourse;
            }
            tempPtr->NextCourse = newCredit;
        }
        else
        {
            tempPtr->CourseCredit = credit;
        }
    }

    printf("Result: \n");
    tempPtr = (*headPtr);
    while (tempPtr != NULL)
    {
        printf("[%s, %d]\t", tempPtr->CurseCode, tempPtr->CourseCredit);
        tempPtr = tempPtr->NextCourse;
    }
    printf("\n\n");
}

/*void updateCoursePoint(struct Student* student, int credit, int score)
{
    printf("Updateing Total Course Point\n");

    struct Course* tempPtr = student->FirstCourse;
    int newTotalScore = 0;

    while (tempPtr != NULL)
    {
        printf("  Found: [%s, %d]\n", tempPtr->CurseCode, tempPtr->Score);
        newTotalScore += tempPtr->Score;
        printf("  New Total = %d\n", newTotalScore);
        tempPtr = tempPtr->NextCourse;
    }
    student->TotCoursePoints = newTotalScore;
}*/

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
