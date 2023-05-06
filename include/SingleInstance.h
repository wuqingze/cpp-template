#ifndef DEMO_SINGLEINSTANCE_H
#define DEMO_SINGLEINSTANCE_H
#include <mutex>
#include <stdio.h>

class SingleInstance {
public:
    static SingleInstance& getInstance(){
        if (nullptr == instance) {
           std::lock_guard<std::mutex> lock(mtx);
            instance = new SingleInstance();
        }
        return *instance;
    }
    int ii = 0;
    void hello(){
        printf("---- Hello from SingleInstance ----\n");
    }

    SingleInstance(const SingleInstance&) = delete;
    SingleInstance& operator=(const SingleInstance&) = delete;

private:
    SingleInstance(){
        printf("---- SingleInstance Constructor ----\n");
    }

    static SingleInstance* instance;
    static std::mutex mtx;
};

//SingleInstance* SingleInstance::instance = nullptr;
//std::mutex SingleInstance::mtx;
#endif
