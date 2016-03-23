/* Problem set 2, problem 1. Given an alphabetical string, assumed to
 * represent a name, this program will return the initials of the name
 * in upper case.
 */

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string name = "";
    // Prompt user for a name
    
    do
    {
        name = GetString();
    } while (!(isalpha(name[0])));
    
    // Capitalize first letter
    
    printf("%c", toupper(name[0]));
    
    // For subsequent characters, capitalize when preceded by a space
    
    for (int i = 1; i < strlen(name); i++)
    {
        if (isspace(name[i-1]))
            printf("%c", toupper(name[i]));
    }
    
    printf("\n");
}