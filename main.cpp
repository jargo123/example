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
#include "RecurciveMD5.h"
#include "threadHelper.h"
#include "ThreadGuard.h"




int main(int argc, char* argv[]) {

    std::string pathToHash="/home/jargo/Documents/pgr/CppProjects/bruteforce_hash/testHash2.txt";
//    std::string pathToDict="/home/jargo/Documents/pgr/CppProjects/bruteforce_hash/testPass.txt";
    std::string pathToDict="/home/jargo/Documents/pgr/CppProjects/bruteforce_hash/4-digits-num.txt";

    LoadHash hashHolder= LoadHash(pathToHash);
    hashHolder.loadFile();

//    std::cout<<"Hashes:"<<"\n";
//    for(auto hash: hashHolder.hashList_){
//        std::string decodedHash=test::getDecodedHash(hash);
//        std::cout<<decodedHash<<"\n";
//    }

//    std::cout<<"Passwords:"<<"\n";

    LoadDict dictHolder= LoadDict(pathToDict);
    dictHolder.loadFile();

//    for(auto pass: dictHolder.passwordList_){
//        std::cout<<pass<<"\n";
//    }

    std::cout<<"Size: "<<dictHolder.passwordList_.size()<<"\n";

    std::vector<ranges> rangesHolder= split(dictHolder.passwordList_.size(),THREAD_COUNT);

    std::vector<std::thread> threadHolder;
    threadHolder.reserve(THREAD_COUNT);

    for(int i=0;i<THREAD_COUNT;i++){

        threadHolder.emplace_back( std::thread (startThread,
                                                rangesHolder[i],
                                                std::ref(hashHolder.hashList_),
                                                std::ref(dictHolder.passwordList_)
                                                ));

    }

    for (auto& item : threadHolder){
        ThreadGuard guard(item);
    }



}

















