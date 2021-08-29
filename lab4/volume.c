// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// aaa
typedef uint8_t BYTE;
typedef int16_t TWO_BYTE;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Abre arquivos
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


    // Copy header from input file to output file
    BYTE cabecalho[HEADER_SIZE];
    fread(cabecalho, HEADER_SIZE, 1, input);
    fwrite(cabecalho, HEADER_SIZE, 1, output);


    // Read samples from input file and write updated data to output file
    TWO_BYTE buffer;
    while (fread(&buffer, sizeof(TWO_BYTE), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(TWO_BYTE), 1, output);
    }


    // Close files
    fclose(input);
    fclose(output);
}
