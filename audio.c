// Alexander Torjyan 28 Period 1
// Write a program to modify the volume of an audio file.
// CS50 Lab 4

// # bytes in .wav 
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Determine scaling and open file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    uint8_t header[HEADER_SIZE];
    /* 1 header
    fread(&header, sizeof(header), 1, input);
    fwrite(&header, sizeof(header), 1, output);

    // Read file
    int16_t buffer;
    while (fread(&buffer, sizeof(buffer), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(buffer), 1, output);
    }

    // End
    fclose(input);
    // Output
    fclose(output);
}
