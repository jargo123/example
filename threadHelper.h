//
// Created by jargo on 7/13/20.
//

#ifndef BRUTEFORCE_HASH_THREADHELPER_H
#define BRUTEFORCE_HASH_THREADHELPER_H

#include <vector>

#include "RecurciveMD5.h"

struct ranges
{
    int start;
    int end;
};


std::vector<ranges> split(int elements, int parts){

    std::vector<ranges> rangeHolder;

    parts=std::min(elements,parts);
    int chunk=elements/parts;
    int remainder= elements%parts;

    int start=0;
    int end=0;
    ranges tmp;

    for(int i=0;i<parts-1;++i){

        end=start+chunk+(remainder ? 1:0);

        tmp.start=start;
        tmp.end=end;
        rangeHolder.emplace_back(tmp);

        start=end;

        if (remainder) remainder -= 1;

    }

    tmp.start=start;
    tmp.end=elements;
    rangeHolder.emplace_back(tmp);

    return rangeHolder;

}

void startThread(ranges range, std::vector<std::shared_ptr<hashStruct>> &hashList,std::vector<std::string> &passwordList){

    RecursiveMD5 md5Bruteforce= RecursiveMD5(range.start,range.end,hashList,passwordList);
    md5Bruteforce.start();
}


#endif //BRUTEFORCE_HASH_THREADHELPER_H
