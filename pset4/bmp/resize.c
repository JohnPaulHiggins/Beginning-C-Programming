/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    // set resize factor
    int n = atoi(argv[1]);

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
    
    // check that n is in required range
    if (n < 1 || n > 100)
    {
        printf("Must resize by factor between 1 and 100, inclusive.");
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // create new file header and info header for outfile
    BITMAPFILEHEADER bfOut = bf;
    BITMAPINFOHEADER biOut = bi;

    // modify outfile's BITMAPINFOHEADER
    biOut.biHeight *= n;
    biOut.biWidth *= n;
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // determine padding for output file
    int outpadding = (4 - (biOut.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // finish BITMAPINFOHEADER
    biOut.biSizeImage = (biOut.biWidth * sizeof(RGBTRIPLE) + outpadding) * abs(biOut.biHeight);
    
    // modify outfile's BITMAPFILEHEADER
    bfOut.bfSize = biOut.biSizeImage + 54;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bfOut, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&biOut, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // prepare file position indicators
    long int line_start = 0;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline n times
        for (int k = 0; k < n; k++)
        {
            line_start = ftell(inptr);
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
    
                // write RGB triple to outfile n times
                for (int l = 0; l < n; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            
            // write in padding
            for (int m = 0; m < outpadding; m++)
            {
                fputc(0x00, outptr);
            }
            fseek(inptr, line_start, SEEK_SET);
        }
        
        // move to end of line
        fseek(inptr, (bi.biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
            
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
