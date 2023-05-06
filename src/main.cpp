#include "SingleInstance.h"
#include <stdio.h>

int main(){
    printf("---- hello world ----\n");
    auto& obj = SingleInstance::getInstance();
    obj.hello();
    return 0;
}
