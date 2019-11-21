
#include <stdio.h>
void findSec(){
    printf("heelo oc");
//    return 1;
}
int main() {
    __block int i = 10;
    void (^myBlock)(void) = ^{
        i = 20;
        printf("nsLog---myBlock\n");
    };
    
    myBlock();
    findSec();
}

