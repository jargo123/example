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
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

class RecursiveMD5 final: public IBruteforce{

    private:

        //-----------------------class vars--------------------------
        /*
         * range of password list for
         * this class/thread
         */
        int startRange_;
        int endRange_;

        std::vector<std::shared_ptr<byte[]>>& hashList_;

        std::vector<std::string>& passwordList_;

    //--------------------used vars------------------------------
        /*
         * current hash that we bruteforcing
         */
        byte* currentHash_= nullptr;

        /*
         * buffers for digest values
         * (we don't want to create unnecessary vars)
         */
        byte digest[ CryptoPP::Weak1::MD5::DIGESTSIZE ];
        byte digest2[ CryptoPP::Weak1::MD5::DIGESTSIZE ];
        byte digest3[ CryptoPP::Weak1::MD5::DIGESTSIZE ];

        /*
         * instance of MD5 for this class
         */
        CryptoPP::Weak1::MD5 hash;
        //------------------------functions-------------------------
        /*
         * calculate hash of current password from passwordList
         * no copy inside
         */
        void calculateHash(std::string& password);

        /*
         * compares currentHash from hashList with calculated hash
         * no copy inside
         */
        bool hashTrue(const byte* calculatedHash);


    public:
        RecursiveMD5(int startRange,int endRange): startRange_{startRange},endRange_{endRange}{};

        void addHashList(std::vector<std::shared_ptr<byte[]>> &hashList) override;

        void addPasswordList(std::vector<std::string> &passwordList) override;

        void start();

};

#endif //BRUTEFORCE_HASH_RECURCIVEMD5_H
