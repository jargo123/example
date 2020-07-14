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

    for (int k = 0; k < CryptoPP::Weak1::MD5::DIGESTSIZE ; ++k) {
        if(calculatedHash[k] != currentHash_->hash[k]){
            return false;
        }
    }
    currentHash_->found= true;
    return true;

}

void RecursiveMD5::start() {

    for(auto& hash: hashList_){

        currentHash_=hash;


        for (int i = startRange_; i <endRange_ ; ++i) {
            //maybe have corresponding field in hashlist with bool value
            //i.e. at worst few more loops, only one thread can find value so it doesn' realy matter if it is
            //atomic or not
            //
            //i need to break this loop if some other thread found password

            //better to have array of atomics that passed to threads as argument by reference, array should be the same
            //length as hashlist, so bool coresponds to hashlist;
            if(!hash->found){
                if (calculateHash(passwordList_[i])){
                    break;
                }
            } else{
//                std::cout<<std::to_string(i)<<std::endl;
                break;
            }

        }
    }

}

