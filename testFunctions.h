//
// Created by jargo on 7/13/20.
//

#ifndef BRUTEFORCE_HASH_TESTFUNCTIONS_H
#define BRUTEFORCE_HASH_TESTFUNCTIONS_H

#include <crypto++/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <crypto++/md5.h>
#include <crypto++/files.h>
#include <crypto++/hex.h>

#include <iostream>
#include <string>
#include <memory>

#include "struct.h"

namespace test{
    std::string getDecodedHash(std::shared_ptr<hashStruct> hash){

        CryptoPP::HexEncoder encoder;
        std::string output;

        encoder.Attach( new CryptoPP::StringSink( output ) );
        encoder.Put( hash.get()->hash, sizeof(hash.get())*2 );
        encoder.MessageEnd();

        return std::move(output);
    }

}
#endif //BRUTEFORCE_HASH_TESTFUNCTIONS_H
