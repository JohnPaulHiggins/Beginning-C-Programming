/* Problem set 2, problem 3. Implements Vigenere's cipher, taking an alphabetical
 * key as a command-line argument. Preserves capitalization, does not shift
 * non-alphabetical characters.
 */

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check for a valid key
    
    if (argc != 2)
    {
        printf("Usage: ~/workspacce/CS50x/pset2/vigenere <key>\n");
        return 1;
    }
    
    int key_length = strlen(argv[1]);
    
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetical characters.\n");
            return 1;
        }
    }
    
    // Convert key from string to array of ints
    
    int key_ints[key_length];
    
    for (int i = 0; i < key_length; i++)
    {
        key_ints[i] = ((int) toupper(argv[1][i])) - 65;
    }
    
    // Take plaintext input
    
    string plain = GetString();
    
    // Transpose all alphabetical characters
    
    int ciph_int;
    int key_index = 0;
    int plain_int;
    int shift;
    
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                plain_int = ((int) plain[i]) - 65;
                shift = key_ints[(key_index % key_length)];
                ciph_int = ((plain_int + shift) % 26) + 65;
                key_index++;
                printf("%c", ((char) ciph_int));
            }
            else
            {
                plain_int = ((int) plain[i]) - 97;
                shift = key_ints[(key_index % key_length)];
                ciph_int = ((plain_int + shift) % 26) + 97;
                key_index++;
                printf("%c", ((char) ciph_int));
            }
        }
        else
            printf("%c", plain[i]);
    }
    printf("\n");
    return 0;
}