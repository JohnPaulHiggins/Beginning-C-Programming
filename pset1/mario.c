#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do 
    {
        printf("height: ");
        height = GetInt();
    } while ((height < 0) || (height > 23));
    if (height == 0)
        return 0;
    for (int i = height; i > 0; i--)
    {
        for (int j = 0; j < (height + 1); j++)
        {
            if (j < i-1)
                printf(" ");
            else
                printf("#");
         }
         printf("\n");
    }
}