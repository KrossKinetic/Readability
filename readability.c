#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letter_count(string sentence);
int word_count(string sentence);
int sentence_count(string sentence);

int main(void)
{
    string sentence = get_string("Text: ");
    int L = letter_count(sentence);
    int W = word_count(sentence);
    int S = sentence_count(sentence);
    double L_avg = (L / (double) W) * 100;
    double S_avg = (S / (double) W) * 100;
    double grade1 = 0.0588 * L_avg - 0.296 * S_avg - 15.8;
    int grade = round(grade1);
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int letter_count(string sentence)
{
    int count = 0;
    for (int i = 0; i < strlen(sentence); i++)
    {
        sentence[i] = tolower(sentence[i]);
        if (sentence[i] >= 'a' && sentence[i] <= 'z')
        {
            count++;
        }
    }
    return count;
}

int word_count(string sentence)
{
    int count = 1;
    for (int i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == ' ')
        {
            count++;
        }
        if (sentence[0] == ' ')
        {
            count--;
        }
        if (sentence[strlen(sentence) - 1] == ' ')
        {
            count--;
        }
    }
    return count;
}

int sentence_count(string sentence)
{
    int count = 0;
    for (int i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == '!' || sentence[i] == '?' || sentence[i] == '.')
        {
            count++;
        }
    }
    return count;
}