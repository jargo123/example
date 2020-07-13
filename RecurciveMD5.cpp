//
// Created by jargo on 7/13/20.
//
#include "RecurciveMD5.h"

void RecursiveMD5::calculateHash(std::string& password) {

    hash.CalculateDigest( digest, (const byte*)password.c_str(), password.length() );

    for(int i=0;i<3333;i++){

        hash.CalculateDigest( digest2, digest, 16 );
        hash.CalculateDigest( digest3, digest2, 16 );
        hash.CalculateDigest( digest, digest3, 16 );
    }// our value in digest

    if(RecursiveMD5::hashTrue(digest)){

       std::cout<<"found password "+ password<<std::endl;

    }
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

}

