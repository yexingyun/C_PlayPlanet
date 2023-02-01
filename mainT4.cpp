#include <iostream>
#include <stdio.h>


int main(void) {
    FILE *fp = NULL;
    fp = fopen("1.txt", "w");
    if (fp!=NULL){
        printf("文件打开成功");
    }

    char Str[] = "AJSDKLJA";
//    fputc('A',fp);
    fputs(Str,fp);
    fclose(fp);
    return 0;
}
