/* Hacker set 2, problem 1. Given an alphabetical string, assumed to
 * represent a name, this program will return the initials of the name
 * in upper case. Must account for erratic whitespace.
 */

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // Prompt user for a name
    string name = GetString();
    
    // Capitalize first letter, if it is not whitespace
    
    if (!isspace(name[0]))
        printf("%c", toupper(name[0]));
    
    // For subsequent characters, capitalize letters preceded by spaces
    
    for (int i = 1; i < strlen(name); i++)
    {
        if (isspace(name[i-1]) && isalpha(name[i]))
            printf("%c", toupper(name[i]));
    }
    
    printf("\n");
}