#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check_chars(string key)
{
    char curr_char = 'a';
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        for (int x = 0; x < i; x++)
        {
            if (tolower(key[i]) == tolower(key[x]))
            {
                return false;
            }
        }
    }
    return true;
}

void substitute(string plain_text, string key)
{
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain_text); i++)
    {
        if (isalpha(plain_text[i]))
        {
            if (islower(plain_text[i]))
            {
                printf("%c", tolower(key[plain_text[i] - 'a']));
            }
            else
            {
                printf("%c", toupper(key[plain_text[i] - 'A']));
            }
        }
        else
        {
            printf("%c", plain_text[i]);
        }
    }
    printf("\n");
}

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            if (check_chars(argv[1]) == false)
            {
                printf("Invalid key\n");
                return 1;
            }
            else
            {
                string plain_text = get_string("Plain text: ");
                substitute(plain_text, argv[1]);
                printf("\n");
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}
