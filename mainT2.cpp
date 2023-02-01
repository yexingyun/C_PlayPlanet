#include <iostream>
#include <stdlib.h>
int *func(void){
    int *ptr = NULL;
    ptr = (int *) malloc((sizeof (int)));
    if(ptr ==NULL){
        exit(1);
    }
    *ptr  = 439;
    return  ptr;
}

int main() {
    int *po = NULL;
    po = func();
    printf("%d\n" ,*po);

    return 0;
}
