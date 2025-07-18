#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calc_score(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            char letter = tolower(word[i]);
            score += points[letter - 'a'];
        }
    }
    return score;
}

int main(void)
{
    string player_one = get_string("Player 1: ");
    string player_two = get_string("Player 2: ");
    int player_one_score = calc_score(player_one);
    int player_two_score = calc_score(player_two);

    if (player_one_score > player_two_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_one_score < player_two_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
