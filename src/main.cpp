#include "SingleInstance.h"
#include "utility/CalculateUtility.h"
#include <stdio.h>

int main(){
    printf("---- hello world ----\n");
    auto& obj = SingleInstance::getInstance();
    obj.hello();
    CalculateUtility cal;
    int i = cal.add(3,9);
//    int i = 1;
    printf("---- i is %d ----\n", i);
    return 0;
}
