#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<fcntl.h>
int main(int argc ,char ** argv){
	if ((strcmp(argv[1],"echo")!=0) &&(strcmp(argv[1],"exit")!=0)){
		write(1,"invalid command\n",strlen("invalid command\n"));
	}
	if (!strcmp(argv[1],"exit")){
		write(1,"Good Bye\n",strlen("Good Bye\n"));
		kill(getppid() , SIGKILL);
	}
	if (!strcmp(argv[1],"echo")){
if (argc < 2)
    
write (1, "\n", 1);
  
  else
    {
      
for (int i = 2; i < argc; i++)
	{
	  
write (1, argv[i], strlen (argv[i]));
	  
 
if (i < argc - 1)
	    
write (1, " ", 1);
	  
	  else
	    
write (1, "\n", 1);
	
}
    
}
  
return 0;

}
}

