#include <unistd.h>
#include<string.h>
#include <fcntl.h>
int echo_main(int argc, char *argv[]) {
    if(argc <2)
    write(1,"\n",1);
    else {
for(int i=1;i<argc;i++){
    write(1,argv[i],strlen(argv[i]));

if(i<argc -1)
write(1," ",1);
else
write(1,"\n",1);
}
}
return 0;
}