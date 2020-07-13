#include <crypto++/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <crypto++/md5.h>
#include <crypto++/files.h>
#include <crypto++/hex.h>

#include <iostream>
#include <string>

#include "helperFunctions.h"
#include "testFunctions.h"
#include "LoadHash.h"
#include "LoadDict.h"



int main(int argc, char* argv[]) {

    std::string pathToHash="/home/jargo/Documents/pgr/CppProjects/bruteforce_hash/testHash.txt";
    std::string pathToDict="/home/jargo/Documents/pgr/CppProjects/bruteforce_hash/testPass.txt";

    LoadHash hashHolder= LoadHash(pathToHash);
    hashHolder.loadFile();

    std::cout<<"Hashes:"<<"\n";
    for(auto hash: hashHolder.hashList_){
        std::string decodedHash=test::getDecodedHash(hash);
        std::cout<<decodedHash<<"\n";
    }

    std::cout<<"Passwords:"<<"\n";

    LoadDict dictHolder= LoadDict(pathToDict);
    dictHolder.loadFile();

    for(auto pass: dictHolder.passwordList_){
        std::cout<<pass<<"\n";
    }

}

















