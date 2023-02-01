#include <iostream>

void callBackMethod(char *fileName,int current,int total){
    printf("%s图片压缩进度是 %d/ %d\n",fileName,current,total);
}

void compress(char *fileName,void(*callbackp)(char *,int ,int) ){
    callbackp(fileName,5,10);
}


int main() {
//    compress("wenjianming",callBackMethod("wenjianming",100,200));
    compress("wenjianming",*callBackMethod);
//    std::cout << "Hello, World333W!" << std::endl;
    if (0){
        std::cout << "Hello, World333W!" << std::endl;
    }else{
        std::cout << "Hello, World777W!" << std::endl;
    }
    return 0;
}
