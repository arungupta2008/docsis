


#include "helper_functions.h"
#include <netdb.h>
//#include <endian.h>
#include "endian.h"
char* mystrcat( char* dest, char* src )
{
     while (*dest) dest++;
     while (*dest++ = *src++);
     return --dest;
}




const int bsti = 1;  // Byte swap test integer
#define is_bigendian() ( (*(char*)&bsti) == 0 )

/**
  In-place swapping of bytes to match endianness of hardware

  @param[in/out] *object : memory to swap in-place
  @param[in]     _size   : length in bytes
*/
void swapbytes(void *_object, size_t _size)
{
  unsigned char *start, *end;

  if(!is_bigendian())
    {
      for ( start = (unsigned char *)_object, end = start + _size - 1; start < end; ++start, --end )
        {
          unsigned char swap = *start;
          *start = *end;
          *end = swap;
        }
    }
}

void print_bits(unsigned int x)
{
  int i;
  for(i=8*sizeof(x)-1; i>=0; i--) {
    (x & (1 << i)) ? putchar('1') : putchar('0');
  }
  printf("\n");
}
