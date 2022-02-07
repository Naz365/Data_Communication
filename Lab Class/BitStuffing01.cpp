#include <stdio.h>
#include <cstring>
/*
 * Student name: Mohammad Nazmul Hossain
 * Student id: 193902031
 * Student Sections: PC-DA
*/
int main(void)
{

    char Array[] = {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0};
    int counter = 0;
    printf("Before Stuffing: ");
    for (int i = 0; i < sizeof(Array); i++)
    {
        printf("%d ", Array[i]);
    }
    printf(" -- 15 characters");
    printf("\n");
    printf(" After Stuffing: ");
    int j = 0;
    while (j < sizeof(Array))
    {
        if (Array[j] != 1)
        {
            counter = 0;
        }
        else
        {
            counter++;
        }
        printf("%d ", Array[j]);
        if (counter >= 5)
        {
            counter = 0;
            printf("0 ");
        }
        j++;
    }
    printf(" -- 17 characters");
    printf("\n");
    char flag[] = {0, 1, 1, 1, 1, 1, 1, 0};
    printf("  After framing: ");
    for (int i = 0; i < sizeof(flag); i++)
    {
        printf("%d ", flag[i]);
    }
    int n = 0;
    while (n < sizeof(Array))
    {
        if (Array[n] != 1)
        {
            counter = 0;
        }
        else
        {
            counter++;
        }
        printf("%d ", Array[n]);
        if (counter >= 5)
        {
            counter = 0;
            printf("0 ");
        }
        n++;
    }
    for (int i = 0; i < sizeof(flag); i++)
    {
        printf("%d ", flag[i]);
    }
    printf("\n");
    printf("\n");
}