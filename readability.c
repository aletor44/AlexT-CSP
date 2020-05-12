// readability.c

// Design and implement a program, readability, that computes the Coleman-Liau index of the text.

// Implement your program in a file called readability.c in a directory called readability.
// Your program must prompt the user for a string of text (using get_string).

// Your program should count the number of letters, words, and sentences in the text. You may
// assume that a letter is any lowercase character from a to z or any uppercase character from
// A to Z, any sequence of characters separated by spaces should count as a word, and that any
// occurrence of a period, exclamation point, or question mark indicates the end of a sentence.

// Your program should print as output "Grade X" where X is the grade level computed by the
// Coleman-Liau formula, rounded to the nearest integer.

// If the resulting index number is 16 or higher (equivalent to or greater than a senior
// undergraduate reading level), your program should output "Grade 16+" instead of giving the
// exact index number. If the index number is less than 1, your program should output "Before Grade 1".

// One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed
// to output what (U.S.) grade level is needed to understand the text. The formula is:

// index = 0.0588 * L - 0.296 * S - 15.8

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) // int argc, string argv[]
{
    // get user to analyze
    string string = get_string("What is the string to analyze? \n");

    int letterCount = 0, wordCount = 0, sentenceCount = 0;

    // count letters, words, and sentences
    // assume a..z and A..Z is a letter
    for (int i = 0, stringLength = strlen(string); i < stringLength + 1; i++)
    {
        if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
        {
            letterCount++;
        }
        // any chars seperated by space is a word, check end of string count last word
        if (string[i] == ' ' || string[i] == '\0')
        {
            wordCount++;

        }
        // when you see a . ! or ? count as sentence
        if (string[i] == '!' || string[i] == '.'|| string[i] == '?')
        {
            sentenceCount++;
        }

    }

    // calculate the grade reading index
    float averageWordsPer100 = (100 / (float) wordCount) * (float) letterCount;
    float averageSentencePer100 = (100 / (float) wordCount) * (float) sentenceCount;
    int readingIndex = round(0.0588 * averageWordsPer100 - 0.296 * averageSentencePer100 - 15.8);

    if (readingIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readingIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", readingIndex);
    }

    return 0;
}