#include <stdio.h>


int main(void)
{
    char str[200];

    // Prompt user for their name
    printf("Name: ");
    fgets(str, 100, stdin);
    printf("Hello, %s", str);

    printf("Testing GitHub\n");

}




