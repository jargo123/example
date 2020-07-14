//
// Created by jargo on 7/13/20.
//

#include "LoadHash.h"

void LoadHash::loadFile() {

    std::fstream newfile;

    newfile.open(filename_,std::ios::in); //open a file to perform read operation using file object

    if (newfile.is_open()){   //checking whether the file is open

        std::string tmp ;

        while(getline(newfile, tmp)){ //read data from file object and put it into string.

            LoadHash::convertStringToByteArray(tmp);
        }

        newfile.close(); //close the file object.
    }

}

void LoadHash::convertStringToByteArray(std::string &stringHash) {

    std::string decoded="";

    std::shared_ptr<hashStruct> hashPtr=std::make_shared<hashStruct>();

    CryptoPP::HexDecoder decoder;

    decoder.Attach( new CryptoPP::StringSink( decoded ) );
    decoder.Put( (byte*)stringHash.data(), stringHash.size() );
    decoder.MessageEnd();

    for (int j = 0; j <16 ; ++j) {
        hashPtr->hash[j]=(byte)decoded[j];
    }

    hashPtr->found= false;

    hashList_.emplace_back(hashPtr);


}
