//
// Created by jargo on 7/13/20.
//

#ifndef BRUTEFORCE_HASH_THREADGUARD_H
#define BRUTEFORCE_HASH_THREADGUARD_H

#include <thread>


class ThreadGuard {

    private:
        std::thread& thread_;
    public:
        explicit ThreadGuard(std::thread& thread): thread_(thread) {};

        ~ThreadGuard()
        {
            if(thread_.joinable())
            {
                thread_.join();
            }

        }

        ThreadGuard(ThreadGuard const&)=delete;
        ThreadGuard& operator=(ThreadGuard const&)=delete;

};


#endif //BRUTEFORCE_HASH_THREADGUARD_H
