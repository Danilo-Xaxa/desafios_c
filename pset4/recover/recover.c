#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>


// defining stuff
typedef uint8_t BYTE;
BYTE buffer[512];


int main(int argc, char *argv[])
{
    // usage error
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }


    // opening the memory card
    FILE *memory_card = fopen(argv[1], "r");

    if (memory_card == NULL)
    {
        printf("ERROR\n");
        return 2;
    }


    int files_count = 0;
    char nome_current_file[42];
    FILE *current_file;

    size_t bytes_lidos;

    int is_first, found = 0;


    while(0 == 0)
    {
        bytes_lidos = fread(buffer, sizeof(BYTE), 512, memory_card);

        if (bytes_lidos == 0)
        {
            break;
        }

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            found = 1;

            if (is_first == 0)
            {
                is_first = 1;
            }

            else
            {
                fclose(current_file);
            }

            sprintf(nome_current_file, "%03i.jpg", files_count);
            files_count++;
            current_file = fopen(nome_current_file, "w");
            fwrite(buffer, sizeof(BYTE), bytes_lidos, current_file);
        }

        else
        {
            if (found == 1)
            {
                fwrite(buffer, sizeof(BYTE), bytes_lidos, current_file);
            }
        }

    }

    fclose(current_file);
    fclose(memory_card);

    return 0;
}
