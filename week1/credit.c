#include <cs50.h> // import dependncies
#include <stdio.h>

void check_type(long card_num)
{
    int length = 0;
    long first_two = card_num;
    long first = card_num;

    while (card_num > 0)
    {
        length++;
        card_num /= 10;
    }

    while (first_two > 99)
    {
        first_two /= 10;
    }
    first = first_two / 10;

    if ((first_two == 34 || first_two == 37) && length == 15)
    {
        printf("AMEX\n");
    }
    else if ((first_two >= 51 && first_two <= 55) && length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (first == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check_valid(long credit)
{
    int sum = 0;
    bool odd = false;
    while (credit > 0)
    {
        int digit = credit % 10;
        if (odd)
        {
            int product = digit * 2;
            sum += product / 10 + product % 10;
        }
        else
        {
            sum += digit;
        }
        odd = !odd;
        credit /= 10;
    }
    return sum % 10 == 0;
}

int main(void)
{
    long credit = get_long("Number: "); // get input
    if (check_valid(credit) != false)
    {
        check_type(credit);
    }
    else
    {
        printf("INVALID\n");
    }
}
