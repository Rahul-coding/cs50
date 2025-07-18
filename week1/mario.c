#include <cs50.h> // import dependncies
#include <stdio.h>

void hashtag(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int x = 0; x < num - i - 1; x++)
        {
            printf(" ");
        }
        for (int y = 0; y < i + 1; y++)
        {
            printf("#");
        }
        printf("  ");
        for (int z = 0; z < i + 1; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
int main(void)
{
    int height = get_int("Height: ");
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }
    hashtag(height);
}
