#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int num_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}
int num_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' && text[i - 1] != ' ')
        {
            words += 1;
        }
    }
    return words;
}
int num_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences += 1;
        }
    }
    return sentences;
}
float letters_per_words(int letters, int words)
{
    return ((float) letters / words * 100);
}
float sentences_per_words(int sentences, int words)
{
    return ((float) sentences / words * 100);
}
int main(void)
{
    string text = get_string("Text: ");
    int words = num_words(text);
    int letters = num_letters(text);
    int sentences = num_sentences(text);
    float sentences_per = sentences_per_words(sentences, words);
    float letters_per = letters_per_words(letters, words);
    int index = round(0.0588 * letters_per - 0.296 * sentences_per - 15.8);
    if (index > 1 && index < 16)
    {
        printf("Grade %d\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
