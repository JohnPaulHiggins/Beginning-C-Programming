/* Hacker set 2, problem 2. Brute force attack on hashed 8-char password.
 */
 
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>

 
int main(int argc, char* argv[])
{
    // Check for valid arguments
     
    if (argc != 2)
    {
        printf("Use: ~/workspace/CS50x/hacker2/crack <hashed password>");
        return 1;
    }
    
    // Set indicator boolean
    
    int pass_guessed = 0;
    
    // Obtain salt from hashed password.
    
    char salt[] = "  ";
    for (int i = 0; i < 2; i++)
    {
        salt[i] = argv[1][i];
    }
    
    // Begin guessing passwords, starting at one character.
    
    int index1 = 32;
    char pass1[] = " ";
    
    while((pass_guessed == 0) && index1 < 127)
    {
        if (strcmp(crypt(pass1, salt), argv[1]) == 0)
        {
            pass_guessed = 1;
            printf("%s\n", pass1);
            return 0;
        }
        
        index1++;
        
        pass1[0] = (char) index1;
    }
    
    // Given that the password is not one character, brute force 2-char passes.
    
    int index2[2] = {32, 32};
    char pass2[] = "  ";
    
    while((pass_guessed == 0) && (index2[0] < 127))
    {
        // Check success condition
        
        if (strcmp(crypt(pass2, salt), argv[1]) == 0)
        {
            pass_guessed = 1;
            printf("%s\n", pass2);
            return 0;
        }
        
        /* Increment characters, starting from last. If last character is ~,
         * increment second-to-last character, and so on.
         */
        
        index2[1]++;
        if (index2[1] > 126)
        {
            index2[1] = 32;
            index2[0]++;
        }
        
        for (int i = 0; i < 2; i++)
        {
            pass2[i] = (char) index2[i];
        }
    }
    
    // Brute force 3-char passwords
    
    int index3[3] = {32, 32, 32};
    char pass3[] = "   ";
    
    while((pass_guessed == 0) && (index3[0] < 127))
    {
        // Check success condition
        
        if (strcmp(crypt(pass3, salt), argv[1]) == 0)
        {
            pass_guessed = 1;
            printf("%s\n", pass3);
            return 0;
        }
        
        /* Increment characters, starting from last. If last character is ~,
         * increment second-to-last character, and so on.
         */
        
        index3[2]++;
        for (int i = 2; i > 0; i--)
        {
            if (index3[i] > 126)
            {
                index3[i] = 32;
                index3[i-1]++;
            }
        }
        
        for (int i = 0; i < 3; i++)
        {
            pass3[i] = (char) index3[i];
        }
    }
    
    // Brute force 4-char passwords
    
    int index4[4] = {32, 32, 32, 32};
    char pass4[] = "    ";
    
    while((pass_guessed == 0) && (index4[0] < 127))
    {
        // Check success condition
        
        if (strcmp(crypt(pass4, salt), argv[1]) == 0)
        {
            pass_guessed = 1;
            printf("%s\n", pass4);
            return 0;
        }
        
        /* Increment characters, starting from last. If last character is ~,
         * increment second-to-last character, and so on.
         */
        
        index4[3]++;
        for (int i = 3; i > 0; i--)
        {
            if (index4[i] > 126)
            {
                index4[i] = 32;
                index4[i-1]++;
            }
        }
        
        for (int i = 0; i < 4; i++)
        {
            pass4[i] = (char) index4[i];
        }
    }
    
    // Brute force 5-char passwords
    
    int index5[5] = {32, 32, 32, 32, 32};
    char pass5[] = "     ";
    
    while((pass_guessed == 0) && (index5[0] < 127))
    {
        // Check success condition
        
        if (strcmp(crypt(pass5, salt), argv[1]) == 0)
        {
            pass_guessed = 1;
            printf("%s\n", pass5);
            return 0;
        }
        
        /* Increment characters, starting from last. If last character is ~,
         * increment second-to-last character, and so on.
         */
        
        index5[4]++;
        for (int i = 4; i > 0; i--)
        {
            if (index5[i] > 126)
            {
                index5[i] = 32;
                index5[i-1]++;
            }
        }
        
        for (int i = 0; i < 5; i++)
        {
            pass5[i] = (char) index5[i];
        }
    }
    
    // Brute force 6-char passwords
    
    int index6[6] = {32, 32, 32, 32, 32, 32};
    char pass6[] = "      ";
    
    while((pass_guessed == 0) && (index6[0] < 127))
    {
        // Check success condition
        
        if (strcmp(crypt(pass6, salt), argv[1]) == 0)
        {
            pass_guessed = 1;
            printf("%s\n", pass6);
            return 0;
        }
        
        /* Increment characters, starting from last. If last character is ~,
         * increment second-to-last character, and so on.
         */
        
        index6[5]++;
        for (int i = 5; i > 0; i--)
        {
            if (index6[i] > 126)
            {
                index6[i] = 32;
                index6[i-1]++;
            }
        }
        
        for (int i = 0; i < 6; i++)
        {
            pass6[i] = (char) index6[i];
        }
    }
    
    // Brute force 6-char passwords
    
    int index7[7] = {32, 32, 32, 32, 32, 32, 32};
    char pass7[] = "       ";
    
    while((pass_guessed == 0) && (index7[0] < 127))
    {
        // Check success condition
        
        if (strcmp(crypt(pass7, salt), argv[1]) == 0)
        {
            pass_guessed = 1;
            printf("%s\n", pass7);
            return 0;
        }
        
        /* Increment characters, starting from last. If last character is ~,
         * increment second-to-last character, and so on.
         */
        
        index7[6]++;
        for (int i = 6; i > 0; i--)
        {
            if (index7[i] > 126)
            {
                index7[i] = 32;
                index7[i-1]++;
            }
        }
        
        for (int i = 0; i < 7; i++)
        {
            pass7[i] = (char) index7[i];
        }
    }
    
    // Brute force 8-char passwords
    
    int index8[8] = {32, 32, 32, 32, 32, 32, 32, 32};
    char pass8[] = "        ";
    
    while((pass_guessed == 0) && (index8[0] < 127))
    {
        // Check success condition
        
        if (strcmp(crypt(pass8, salt), argv[1]) == 0)
        {
            pass_guessed = 1;
            printf("%s\n", pass8);
            return 0;
        }
        
        /* Increment characters, starting from last. If last character is ~,
         * increment second-to-last character, and so on.
         */
        
        index8[7]++;
        for (int i = 7; i > 0; i--)
        {
            if (index8[i] > 126)
            {
                index8[i] = 32;
                index8[i-1]++;
            }
        }
        
        for (int i = 0; i < 8; i++)
        {
            pass8[i] = (char) index8[i];
        }
    }
    
}