#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("minutes: ");
    int shower_duration = GetInt();
    int bottles_used = shower_duration * 12;
    printf("bottles: %d\n", bottles_used);
}