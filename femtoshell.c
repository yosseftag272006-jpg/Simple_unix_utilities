#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
	  break;
	}
      else if (!strncmp (buff, "echo ", 5))
	{
	  printf ("%s\n", buff + 5);
	}
      else if (!strcmp (buff, "echo"))
	{
	  printf ("\n");
	}
      else
	{
	  printf ("invalid command\n");
	}

    }
  return 0;
}
