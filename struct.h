//
// Created by jargo on 7/14/20.
//

#ifndef BRUTEFORCE_HASH_STRUCT_H
#define BRUTEFORCE_HASH_STRUCT_H

#include "global_difines.h"

#include <crypto++/config.h>

/*
 * struct for holding:
 *      hash in form of byte array of size defined in global_define.h
 *      bool found for threads to check if any thread found password
 */
struct hashStruct{
    byte hash[BYTE_ARRAY_SIZE];
    bool found;
};

#endif //BRUTEFORCE_HASH_STRUCT_H
