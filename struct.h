//
// Created by jargo on 7/14/20.
//

#ifndef BRUTEFORCE_HASH_STRUCT_H
#define BRUTEFORCE_HASH_STRUCT_H

#include <crypto++/config.h>

struct hashStruct{
    byte hash[16];
    bool found;
};

#endif //BRUTEFORCE_HASH_STRUCT_H
