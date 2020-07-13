//
// Created by jargo on 7/13/20.
//

#ifndef BRUTEFORCE_HASH_LOADHASH_H
#define BRUTEFORCE_HASH_LOADHASH_H

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <memory>

#include <crypto++/config.h>
#include <crypto++/hex.h>


class LoadHash {
    public:
        /*
         * here we hold hashes to crack
         */
        std::vector<std::shared_ptr<byte[]>> hashList_;

        std::string filename_;

        explicit LoadHash(std::string filename):filename_{std::move(filename)}{};

        void loadFile();

        void convertStringToByteArray(std::string& stringHash);

};


#endif //BRUTEFORCE_HASH_LOADHASH_H

