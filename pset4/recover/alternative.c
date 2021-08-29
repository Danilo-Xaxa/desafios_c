#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// defining stuff
typedef uint8_t BYTE;

int block_size = 512;

BYTE buffer[512];
BYTE temp[512];
BYTE temporario[512];


int main(int argc, char *argv[])
{
    // usage error
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
    }


    // opening the memory card
    FILE *memory_card = fopen(argv[1], "r");

    // declarando e inicializando a quantidade de arquivos jpeg gerados
    int files_count = 0;

    // GAMBIARRA PRA SABER QUANTOS BLOCOS DE 512 BYTES TEM DENTRO DE MEMORY_CARD
    //int medidor = 0;
    //while (fread(temporario, block_size, 1, memory_card) == 1) // ou temporario[medidor] ???
    //{
        //medidor++;
    //}
    //fclose(memory_card);
    //printf("%lu\n", sizeof(temporario));
    //printf("%i\n", medidor);

    // repetir até o final de memory_card
    for (int o = 0; o < medidor; o++) // TÁ CERTO ISSO?
    {
        // lendo os primeiros 512 bytes de memory_card pra dentro do array buffer
        fread(buffer, block_size, 1, memory_card); // TÁ CERTO ISSO?

        // se esse bloco é o começo de um jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            files_count++;
            char *filename = "blablak"; // [7] ???
            sprintf(filename, "%03i.jpg", files_count);
            FILE *novo_jpeg = fopen(filename, "w");
            fwrite(buffer, block_size, 1, novo_jpeg); // TÁ CERTO ISSO?
        }
    }
    fclose(memory_card); // TÁ CERTO ISSO?
}
