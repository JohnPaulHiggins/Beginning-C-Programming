#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    printf("%s\n", crypt(argv[1], argv[2]));
}