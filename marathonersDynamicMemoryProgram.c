#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void marathonersCover()
{
    system("color 0B");
    printf("******************************************************\n");
    printf("*                                                    *\n");
    printf("*           Marathoners DataBase Bulgaria            *\n");
    printf("*                                                    *\n");
    printf("******************************************************\n");
}

void printNewLines(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("\n");
    }
}

void clearScreen()
{
    system("cls");
}

void charDefault(char *c)
{
    *c = 0;
}

void resetCounter(int *counter)
{
    *counter = 0;
}

int *createDynamicIntArr(int *intArr, int size)
{
    intArr = malloc(size * sizeof(int));
    return intArr;
}

void print2DStrArr(char **names, char **families, int *ids, int *ages, int rows, int flag)
{
    if (flag == -1) // BEFORE SOTRING
    {
        for (int i = 0; i < rows; i++)
        {
            printf(" -- UNIQUE ID %d. %s %s, %d years old. -- \n", ids[i], names[i], families[i], ages[i]);
        }
    }
    else if (flag == 1) // AFTER SORTING
    {
        for (int i = 0; i < rows; i++)
        {
            printf(" -- %i. -- -- UNIQUE ID %d. %s %s, %d years old. --  \n", i + 1, ids[i], names[i], families[i], ages[i]);
        }
    }
}

void sortByFirstName(char **names, char **families, int *ids, int *ages, int namesSize)
{
    char temp[100] = {0};
    int tempInt = 0;
    for (int i = 0; i < namesSize; i++)
    {
        for (int j = i + 1; j < namesSize; j++)
        {
            if (strcmp(names[i], names[j]) > 0)
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);

                strcpy(temp, families[i]);
                strcpy(families[i], families[j]);
                strcpy(families[j], temp);

                tempInt = ids[i];
                ids[i] = ids[j];
                ids[j] = tempInt;

                tempInt = ages[i];
                ages[i] = ages[j];
                ages[j] = tempInt;
            }
        }
    }
}

void getInt(int *integer)
{
    scanf("%d", integer);
    fflush(stdin);
}

int isContinue(char *contin)
{
    printf("Do you want to continue? [y/n]: ");
    scanf("%c", contin);
    fflush(stdin);
    if (*contin != 'n')
    {
        return 1;
    }
    else if (*contin == 'n' || *contin == 'N')
    {
        return 0;
    }
}

void dynamicEntryInArr(char **array, char *c, int *row, int *charCounter)
{
    while (*c != '\n' && *c != ' ')
    {
        *c = getchar();
        if (*c != '\n')
        {
            array[*row][*charCounter] = *c;
            (*charCounter)++;
            array[*row] = (char *)realloc(array[*row], (*charCounter) + 1);
        }
    }

    array[*row][*charCounter] = '\0';
}

void myProgram()
{
    int *ages = createDynamicIntArr(ages, 128), *ids = createDynamicIntArr(ids, 128);

    char **names = (char **)malloc(1 * sizeof(char *));
    char **families = (char **)malloc(1 * sizeof(char *));

    int row = 0, charCounter = 0;
    char c = 0, contin = 0;

    while (contin != 'n' && contin != 'N')
    {
        names[row] = (char *)malloc(1 * sizeof(char));
        families[row] = (char *)malloc(1 * sizeof(char));
        clearScreen();
        marathonersCover();
        printf(" -- Marathoner ID: %d -- \n", row + 1);
        printf(" -- Please enter name: ");
        charDefault(&c);
        dynamicEntryInArr(names, &c, &row, &charCounter);
        resetCounter(&charCounter);
        charDefault(&c);
        printf(" -- Please enter family: ");
        dynamicEntryInArr(families, &c, &row, &charCounter);
        resetCounter(&charCounter);
        printf(" -- Please enter age: ");
        getInt(&ages[row]);
        ids[row] = row + 1;
        row++;
        isContinue(&contin);
        names = (char **)realloc(names, (row + 1) * sizeof(char *));
        families = (char **)realloc(families, (row + 1) * sizeof(char *));
    }

    clearScreen();
    marathonersCover();
    printf("\n -- Marathoners -- \n");
    print2DStrArr(names, families, ids, ages, row, -1);
    sortByFirstName(names, families, ids, ages, row);
    printf("\n -- Sorted By first name --\n");
    print2DStrArr(names, families, ids, ages, row, 1);

    free(names);
    free(families);
    free(ages);
    free(ids);
}

int main()
{
    myProgram();
    printNewLines(2);
    system("PAUSE");
    return 0;
}
