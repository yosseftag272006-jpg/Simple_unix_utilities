#include <stdio.h>
#include <unistd.h>
#include <string.h>
int pwd_main() {
    char buff[2000];
    if((getcwd(buff,sizeof(buff)))!=NULL);
    write(1,buff,strlen(buff));
    return 0;
}