#include <stdio.h>
#include <unistd.h>
#include "shellmans.h"
int main(int argc, char const *ar)
{
  printf("isatty(%d) -> %d\n", stdin->_fileno, isatty(STDIN_FILENO));
  return 0;
}
