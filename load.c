#include "pgmhead"

void loadFromFile(struct Student* regArray, int size)
{
    char filePath[30] = "";
    //char filePath[30] = "test_Student.txt";
    char fileLine[30] = "";
    FILE* studentFile = NULL;

    printf("Please enter path to the file to load:\n > ");
    scanf("%s", filePath);
    printf("Path = [%s]\n", filePath);
    studentFile = fopen(filePath, "r");

    if (studentFile != NULL)
    {
        int rearPtr = 0;

        while ( strcmp(regArray[rearPtr].StudentID, "D9999999") != 0 && rearPtr<size )
            rearPtr++;

        while( fgets(fileLine, 30, studentFile) != NULL && rearPtr<=MAXSIZE )
        {
            if(fileLine[strlen(fileLine) - 1] == '\n')
                fileLine[strlen(fileLine) - 1] = '\0';
            printf("New Entry@%d: [%s]\n", rearPtr, fileLine);
            strNcpy(regArray[rearPtr].StudentID, fileLine, 0, 7);
            printf("  add: [%s]\n", regArray[rearPtr].StudentID);
            strNcpy(regArray[rearPtr].StudentName, fileLine, 9, strlen(fileLine)-1);
            printf("  add: [%s]\n", regArray[rearPtr].StudentName);
            rearPtr++;
        }

        if (rearPtr >= MAXSIZE)
        {
            printf("Warning, student table fulled, some entry may be ignored!");
        }

        fclose(studentFile);
    }
    else
    {
        printf("ERROR, file cannot be open.\n");
        printf("Please try again!\n");
    }
}

void strNcpy(char* dest, char* src, int startPoint, int endPoint)
{
    int i = 0, j=0;
    for (i=startPoint, j=0; i<=endPoint; i++, j++)
    {
        dest[j] = src[i];
    }
    dest[j] = '\0';
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
