// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount;
    printf("Bill before tax and tip: ");
    scanf("%f", &bill_amount);
    float tax_percent;
    printf("Sale Tax (%%): ");
    scanf("%f", &tax_percent);
    int tip_percent;
    printf("Sale Tip (%%): ");
    scanf("%d", &tip_percent);

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    float wtax = bill * (tax / 100 + 1);
    printf("%f\n",wtax);
    float wtip = wtax * ((float)tip / 100 + 1);
    printf("%f\n",wtip);
    float half = wtip / 2;
    printf("%f\n",half);
    return half;
}
