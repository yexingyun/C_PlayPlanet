#include <iostream>
#include <stdio.h>


int main(void) {
    FILE *fp = NULL;
    fp = fopen("1.txt", "r+");//以读取方式打开
    if (fp != NULL) {
//        printf("%s","文件打开成功\n");
    }
    char str[1025] = {'\0'};

    int x = 0;
    while (!feof(fp)) {
        str[x] = fgetc(fp);
//        putchar(str[x]);
        printf("%c",str[x]);
        x++;

    }
    fclose(fp);
    return 0;
}
