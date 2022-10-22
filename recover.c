// Alexander Torjyan 28 Per 1
// CS50 Problem set 4: Recover

int main(int argc, char *argv[])
{

    typedef uint8_t BYTE;


    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    char *nameofrawfile = argv[1];

  
    FILE *rawfile_ptr = fopen(nameofrawfile, "r");

    
    if (rawfile_ptr == NULL)
    {
        printf("Could not open %s.\n", nameofrawfile);
        return 1;
    }

    BYTE buffer[512]; //to store the currently read chunk

    //  title to name jpeg
    int counter = 0;
    char title[8];
    bool open = false;
    FILE *image_ptr;

    
    while (fread(&buffer, 512, 1, rawfile_ptr) > 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 224) == 0xe0) ) //(224 = 0xe0 = 11100000 in binary)
            {
                sprintf(title, "%d%d%d.jpg", counter / 100, (counter % 100) / 10, counter % 10);
//                printf(title[7] == '\0' ? "true" : "false"); 
                image_ptr = fopen(title, "w");
                open = true;
                fwrite(buffer, 512, 1, image_ptr);
                counter++;
            }
        else if (open == true)
        {
//            
            fwrite(buffer, 512, 1, image_ptr);
        }
    }
    fclose(image_ptr);
    fclose(rawfile_ptr);
}
