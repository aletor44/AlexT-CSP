// Alexander Torjyan 28 Period 1
// Design and implement a program, substitution, that encrypts messages using a substitution cipher.
// CS50 Week 2 Problem Set 2


int main (int argc, char *argv[])
{
    // look at length
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        // chekc duplicate
        bool valid = false;
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            for (int j = i + 1; j < strlen(argv[1]) + 1; j++)
            {
                if (isalpha(argv[1][i]) && tolower(argv[1][i]) != tolower(argv[1][j]))
                {
                    valid = true;
                }
                else
                {
                    printf("Usage ./substitution key\n");
                    return 1;
                }
                
            }
        }

        // get back text
        char input[500];
        printf("plaintext: ");
        fgets(input, sizeof(input), stdin); 
        printf("\n");

        // encrypt letter
        for (int i = 0; i < strlen(input); i++)
        {
            if (islower(input[i]))
            {
                input[i] = tolower(argv[1][input[i] - 97]);
            }
            else if (isupper(input[i]))
            {
                input[i] = toupper(argv[1][input[i] - 65]);
            }
        }

        // get cipher
        printf("ciphertext: %s", input);
        printf("\n");
        return 0;
    }
    else
    {
      // print
        printf("Usage ./substitution key\n");
        return 1;
    }
    
}
