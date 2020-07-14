//
// Created by jargo on 7/13/20.
//
#include "RecurciveMD5.h"
#include <thread>
#include <string>

bool RecursiveMD5::calculateHash(std::string& password) {

    hash.CalculateDigest( digest, (const byte*)password.c_str(), password.length() );

    for(int i=0;i<3333;i++){

        hash.CalculateDigest( digest2, digest, 16 );
        hash.CalculateDigest( digest3, digest2, 16 );
        hash.CalculateDigest( digest, digest3, 16 );
    }// our value in digest

    if(RecursiveMD5::hashTrue(digest)){

        std::cout<<"found password "<<password<<" id: "<<std::this_thread::get_id()<<std::endl;
        return true;
    }

    return false;
}

bool RecursiveMD5::hashTrue(const byte* calculatedHash) {

    for (int k = 0; k <16 ; ++k) {
        if(calculatedHash[k] != currentHash_[k]){
            return false;
        }
    }
    return true;

}

void RecursiveMD5::start() {

    std::cout<<"this id: "<<std::this_thread::get_id()<<std::endl;
    for(auto& hash: hashList_){

        currentHash_=hash.get();
        std::cout<<"currentHash addr: "<<std::addressof(currentHash_)<<std::endl;
        std::cout<<"password list addr: "<<std::addressof(passwordList_)<<std::endl;
        std::cout<<"hash list addr: "<<std::addressof(hashList_)<<std::endl;


        for (int i = startRange_; i <endRange_ ; ++i) {
            if (calculateHash(passwordList_[i])){
                break;
            }

        }
    }

}

