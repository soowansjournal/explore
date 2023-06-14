#include <stdio.h>

int collatz(int n);

int main()
{
    int result = collatz(12);
}



int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if ((n%2) == 0)
    {
        printf("Even");
        int one = collatz(n/2);
        return one;
    }
    return 0;
}
