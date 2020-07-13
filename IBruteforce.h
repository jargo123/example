//
// Created by jargo on 7/13/20.
//
#ifndef BRUTEFORCE_HASH_IBRUTEFORCE_H
#define BRUTEFORCE_HASH_IBRUTEFORCE_H

#include <string>
#include <vector>

#include <crypto++/config.h>
#include <crypto++/cryptlib.h>

class IBruteforce{

    public:
        /*
         * reference to vector of hashes to break,stored as bytes for faster comparision
         */
        virtual void addHashList(std::vector<byte[16]>& hashList) = 0;
        /*
         * password list for bruteforcing
         */
        virtual void addPasswordList(std::vector<std::string>& passwordList) = 0;

};

#endif //BRUTEFORCE_HASH_IBRUTEFORCE_H

