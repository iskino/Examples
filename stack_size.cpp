// stack size

#include <iostream>

int main ()
{
  char array[7*(1'024*1'024)+(512*1'024)+(256*1'024)+(128*1'024)+(64*1024)+(32*1024)+(16*1024)+(6*1024)];

  std::cout << (sizeof (array) / (1024)) << " KByte";

  return 0;
}
