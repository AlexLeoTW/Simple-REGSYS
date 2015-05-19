#include "pgmhead"

int main()
{
    int quitFlag = 0;
    int choice = 0;
    struct Student RegArray[MAXSIZE];
    struct Credit* credit = NULL;

    printf("Welcome to use PGM_NAME,");
    while(quitFlag == 0)
    {
        printf("\n\n");
        printf("Please select a function you want: \n\n");
        printf("  1. Initialize the Reg Array \n");
        printf("      - set initial value for Reg. Array \n");
        printf("  2. Load \n");
        printf("      - load student id + name into Reg. Array \n");
        printf("  3. Group insert \n");
        printf("      - insert grade (cs101, eng102, math103) \n");
        printf("  4. Suspend \n");
        printf("      - mark off in Reg. array and free all nodes following(ActFlag='n') \n");
        printf("  5. Calculate Average \n");
        printf("      - average = total course points / total credits \n");
        printf("  6. Print Grade Report (for all student) \n");
        printf("      - Print all active nodes \n");
        printf("  7. Print Grade Report (for individual) \n");
        printf("      - Search a student by student ID and print his/her active nodes \n");
        printf("  8. Quit \n");
        printf("      - Leave this program \n");
        printf(" > ");
        scanf("%d*s", &choice);

        printf("\n\n");

        switch(choice)
        {
        case 1:
            printf("1. Initialize the Reg Array \n");
            initalRegArray(RegArray, MAXSIZE);
            break;
        case 2:
            printf("2. Load \n");
            loadFromFile(RegArray, MAXSIZE);
            break;
        case 3:
            printf("3. Group insert \n");
            groupInsert(RegArray, MAXSIZE, &credit);
            break;
        case 4:
            printf("4. Suspend \n");
            suspend(RegArray, MAXSIZE);
            break;
        case 5:
            printf("5. Calculate Average \n");
            calculateAvg(RegArray, MAXSIZE, credit);
            break;
        case 6:
            printf("6. Print Grade Report (for all student) \n");
            printRegArray(RegArray, MAXSIZE);
            break;
        case 7:
            printf("7. Print Grade Report (for individual) \n");
            printIndividual(RegArray, MAXSIZE);
            break;
        case 8:
            printf("8. Quit \n");
            quitFlag = 1;
            break;
        default:
            printf("Wrong selection, Try again \n");
        }
    }

    return 0;
}
