#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

volatile const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

uint8_t InvertByte(uint8_t b)
{

    uint8_t ResultU8 = 0;
    int i;

    for(i=0; i<8; i++)
    {
        ResultU8 >>= 1;
        if (b & 0x80)
        {
            ResultU8 |= 0x80;
        }
        b <<= 1;
    }
    return ResultU8;
} // _U8 InvertByte(_U8 b)

int main()
{
    uint16_t i;
    uint8_t Mirror;

    printf("Byte mirror test\n");

    for (i=0; i<256; i++)
    {
        Mirror = InvertByte((uint8_t)i);

        printf("%s vs ",byte_to_binary(i));
        printf("%s \n",byte_to_binary(Mirror));
    }
    return 0;
}
