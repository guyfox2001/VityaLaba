#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include "md5.h"
#include <list>
#include <map>


struct DataField {
    char msg[255];
    size_t length;
    int count;
    uint8_t result[16];
};

struct hash_table {
    std::list<DataField> collisionData;
};



int main(int argc, char** argv)
{
    std::map<uint8_t, DataField> Hash;
    char msg[] = "Hello, world";
    size_t len;
    int i;
    uint8_t result[16];

  /*  if (argc < 2) {
        printf("usage: %s 'string'\n", argv[0]);
        return 1;
    }*/

    len = strlen(msg);
    md5((uint8_t*)msg, len, result);
    for (i = 0; i < 16; i++)
        printf("%2.2x", result[i]);
    puts("");
    system("pause");
    return 0;
}