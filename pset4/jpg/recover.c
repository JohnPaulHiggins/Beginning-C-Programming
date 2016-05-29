/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
 #include <stdint.h>
 #include <stdio.h>


int main(int argc, char* argv[])
{
    // open raw card data
    FILE* input = fopen("card.raw", "r");
    
    // initialize block for file data
    uint8_t block[512];
    
    // prepare counter for jpg name
    int i = 0;
    
    // build indicator for open output
    int output_open = 0;
    
    // prepare output pointer
    FILE* output = NULL;
    
    // iterate through file
    while(fread(block, 1, 512, input) == 512)
    {
        // check if starting a new jpg
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && block[3] <= 0xef && block[3] >= 0xe0)
        {
            if (output_open)
            {
                fclose(output);
                output_open = 0;
            }
            
            // make jpg name
            char name[8];
            sprintf(name, "%03d.jpg", i);
            i++;
            
            // open output file
            output = fopen(name, "w");
            output_open = 1;
        }
        
        // write to output file, if open (i.e. jpg has been detected)
        if (output_open)
        {
            fwrite(block, 1, 512, output);
        }
    }
    
    fclose(input);
    
    // close output if open
    if (output_open)
    {
        fclose(output);
        output_open = 0;
    }
}