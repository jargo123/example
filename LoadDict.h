//
// Created by jargo on 7/13/20.
//

#ifndef BRUTEFORCE_HASH_LOADDICT_H
#define BRUTEFORCE_HASH_LOADDICT_H

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <memory>

#include <crypto++/config.h>




class LoadDict {
    public:
        /*
         * here we hold passwords
         * this vector is shared by all threads
         */
        std::vector<std::string> passwordList_;

        std::string filename_;

        explicit LoadDict(std::string filename):filename_{std::move(filename)}{};

        void loadFile();

};


#endif //BRUTEFORCE_HASH_LOADDICT_H
