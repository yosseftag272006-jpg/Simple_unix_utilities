#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int
main (int argc, char **argv)
{
  while (1)
    {
      char buff[20000];
      printf ("my ahla shell:please enter your command $ ");
      if (fgets (buff, 10000, stdin) == NULL)
	{
	  printf ("\n");
	  break;
	}
      buff[strlen (buff) - 1] = 0;
      if (strlen (buff) == 0)
	{
	  continue;
	}
      if (!strcmp (buff, "exit"))
	{
	  printf ("Good Bye \n");
	  return 0;
	}
      else if (!strncmp (buff, "echo ", 5))
	{
	  printf ("%s\n", buff + 5);
	}
      else if (!strcmp (buff, "echo"))
	{
	  printf ("\n");
	}
      else if (!strcmp (buff, "pwd"))
	{
	  char pwd_buff[20000];
	  if (getcwd (pwd_buff, 20000) != NULL)
	    {
	      printf ("%s\n", pwd_buff);
	    }
	}
      else if (!strncmp (buff, "cd ", 3))
	{
	  if (chdir (buff + 3) != 0)
	    {
	      printf ("picoshell: cd: %s: no such file or directory \n",
		      buff + 3);
	    }
	}
      else
	{
	  int pid = fork ();
	  if (pid > 0)
	    {
	      wait (NULL);
	    }
	  else if (pid == 0)
	    {
	      char *argv2[10];
	      int no = 0;
	      char my_string[10][100];
	      int index = 0;
	      for (int i = 0; i <= strlen (buff); i++)
		{
		  if (buff[i] != ' ' && buff[i] != '\0')
		    {
		      my_string[no][index] = buff[i];
		      index++;
		    }
		  else if (index > 0)
		    {
		      my_string[no][index] = '\0';
		      argv2[no] = my_string[no];
		      index = 0;
		      no++;
		    }
		}
	      argv2[no] = NULL;
	      if (execvp (argv2[0], argv2) == -1)
		{
		  printf ("invalid command\n");
		  return (0);
		}
	    }
	}
    }
}
