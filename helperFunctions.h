//
// Created by jargo on 7/13/20.
//
#ifndef BRUTEFORCE_HASH_HELPERFUNCTIONS_H
#define BRUTEFORCE_HASH_HELPERFUNCTIONS_H

#include <crypto++/config.h>
#include <bitset>
#include <iostream>
#include <string>

namespace helper{


    void printBinary(std::string value){

        for (std::size_t i = 0; i < value.size(); ++i)
        {
            std::cout << std::bitset<8>(value.c_str()[i]) << std::endl;
        }

    }

    template<typename T>
    void printBinaryOneLine(T value,bool delim){
        printBinary(value,"");
        if(delim){
            std::cout<<"\n"<<"---------------"<<std::endl;
        }else{
            std::cout<<std::endl;
        }
    }

    void printBinaryByLine(std::string value){
        printBinary(value);
        std::cout<<"---------------"<<std::endl;
    }

    void printBinaryDigest(byte (&value)[16]){

        for(int i=0;i<16;i++){
            std::bitset<8> a(value[i]);
            std::cout<<a.to_string()<<std::endl;
        }
    }

}

#endif //BRUTEFORCE_HASH_HELPERFUNCTIONS_H

