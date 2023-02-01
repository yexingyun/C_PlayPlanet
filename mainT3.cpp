#include <iostream>
#include <stdio.h>

typedef int (*PTR_TO_ARR)[3];
typedef int (*PTR_TO_FUN)(void);
typedef int (*PTR_TO_FUN2)(int);
int fun(void){
    return 3123;
}
int funA(int num){
    printf("%d\n",num);
    return 3123;
}
int funB(int num){
    printf("%d\n",num);
    return 3123;
}
int funC(int num){
    printf("%d\n",num);
    return 3123;
}

int main(void) {
    int array[3] = {1, 2, 3};
    PTR_TO_ARR toArr = &array;

    int i;
    for (i = 0; i < 3; i++) {
        printf("%d\n", (*toArr)[i]);
    }
    PTR_TO_FUN ptrToFun = &fun;
    PTR_TO_FUN2 ptrToFun2[3] = {&funA, &funB, &funC};;
    printf("%d\n",(*ptrToFun)());

    int j;
    for (j = 0; j < 3; j++) {
        printf("%d\n", (*ptrToFun2[j])(j));
    }
    return 0;
}
