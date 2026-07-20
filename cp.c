#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main (int argc, char *argv[])
{
  char buff[100];
  int source_fd;
  int destination_fd;
  int checks;
  int checkd;
  source_fd = open (argv[1], O_RDONLY);
  if (source_fd < 0)
    return -1;
  destination_fd = open (argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
  if (destination_fd < 0)
    return -2;
  while ((checks = read (source_fd, buff, 100)) > 0)
    {
      write (destination_fd, buff, checks);
    }
  return 0;
}
