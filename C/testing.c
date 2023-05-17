#include <stdio.h>
#include <string.h>


int main(void)
{
    char plain[100]; 

    do 
    {
        printf("plaintext: ");
        fgets(plain, sizeof(plain), stdin);
    }
    while (strlen(plain) < 1);
    int length = strlen(plain);
    printf("Length of string: %d\n", length);
    printf("String: %s\n", plain);


}