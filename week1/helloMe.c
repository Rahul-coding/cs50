#include <cs50.h> // import dependncies
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? "); // get input
    printf("hello, %s\n", name);                    // output
}
