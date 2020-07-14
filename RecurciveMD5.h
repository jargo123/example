//
// Created by jargo on 7/13/20.
//

#ifndef BRUTEFORCE_HASH_RECURCIVEMD5_H
#define BRUTEFORCE_HASH_RECURCIVEMD5_H

#include "IBruteforce.h"
#include <crypto++/md5.h>
#include <crypto++/hex.h>
#include <vector>
#include <iostream>

#include "struct.h"

class RecursiveMD5 final: public IBruteforce{

    private:

        //-----------------------class vars--------------------------
        /*
         * range of password list for
         * this class/thread
         */
        int startRange_;
        int endRange_;

        std::vector<std::string>& passwordList_;
        std::vector<std::shared_ptr<hashStruct>>& hashList_;


    //--------------------used vars------------------------------
        /*
         * current hash that we bruteforcing
         * this is pointer to value that is owned by shared pointer in hashList
         */
        std::shared_ptr<hashStruct> currentHash_;

        /*
         * buffers for digest values
         * (we don't want to create unnecessary vars)
         */
        byte digest[ CryptoPP::Weak1::MD5::DIGESTSIZE ]{};
        byte digest2[ CryptoPP::Weak1::MD5::DIGESTSIZE ]{};
        byte digest3[ CryptoPP::Weak1::MD5::DIGESTSIZE ]{};

        /*
         * instance of MD5 for this class
         */
        CryptoPP::Weak1::MD5 hash;
        //------------------------functions-------------------------
        /*
         * calculate hash of current password from passwordList
         * no copy inside
         */
        bool calculateHash(std::string& password);

        /*
         * compares currentHash from hashList with calculated hash
         * no copy inside
         */
        bool hashTrue(const byte* calculatedHash);


    public:
        RecursiveMD5(int startRange, int endRange,
                    std::vector<std::shared_ptr<hashStruct>> &hashList,
                    std::vector<std::string> &passwordList)
                    : startRange_{startRange},
                    endRange_{endRange},
                    hashList_(hashList),
                    passwordList_(passwordList) {};


        /*
         * start bruteforce
         */
        void start() override ;

};

#endif //BRUTEFORCE_HASH_RECURCIVEMD5_H
