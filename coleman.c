// Alexander Torjyan 28
// Design and implement a program, readability, that computes the Coleman-Liau index of text.
// CS50 Week 2 Problem Set 2

int main(void) // int argc, string argv[]
{
    // get user to analyze
    string string = get_string("What is the string to analyze? \n");

    int letterCount = 0, wordCount = 0, sentenceCount = 0;
    
    // assume alphabet
    for (int i = 0, stringLength = strlen(string); i < stringLength + 1; i++)
    {
        if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
        {
            letterCount++;
        }
        // space = seperate words
        if (string[i] == ' ' || string[i] == '\0')
        {
            wordCount++;

        }
        // .-! cout ++ sentence
        if (string[i] == '!' || string[i] == '.'|| string[i] == '?')
        {
            sentenceCount++;
        }

    }

    // grade % index
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
