//
// Created by jargo on 7/13/20.
//

#include "LoadDict.h"

void LoadDict::loadFile() {

    std::fstream newfile;

    newfile.open(filename_,std::ios::in); //open a file to perform read operation using file object

    if (newfile.is_open()){   //checking whether the file is open

        std::string tmp ;

        while(getline(newfile, tmp)){ //read data from file object and put it into string.

            passwordList_.emplace_back(tmp);
//            cout << tp << "\n"; //print the data of the string
        }

        newfile.close(); //close the file object.
    }

}
