/* Problem set 2, problem 2. Implements a Caesar cipher, taking the key value as
 * a command-line argument. Preserves capitalization, does not shift
 * non-alphabetical characters.
 */

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check for a valid argument
    
    if (argc != 2)
    {
        printf("Usage: ~/workspacce/CS50x/pset2/caesar <key>");
        return 1;
    }
    
    int k = atoi(argv[1]);
    
    if (k < 0)
    {
        printf("Key must be a non-negative integer.");
        return 1;
    }
    
    // Take plaintext input
    
    string plain = GetString();
    
    // Transpose all alphabetical characters
    
    int ciph_int;
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                ciph_int = (((((int) plain[i]) - 65) + k) % 26) + 65;
                printf("%c", ((char) ciph_int));
            }
            else
            {
                ciph_int = (((((int) plain[i]) - 97) + k) % 26) + 97;
                printf("%c", ((char) ciph_int));
            }
        }
        else
            printf("%c", plain[i]);
    }
    printf("\n");
    return 0;
}