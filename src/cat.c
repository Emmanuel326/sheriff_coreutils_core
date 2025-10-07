#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  if(argc < 2 )
  {
	  fprintf(stderr, "Usage: %s <file1> [file2 ...]\n", argv[0]);
	  return 1;

  }
  for(int i=1; i<argc; i++)
  {
	  FILE *fp = fopen(argv[i], "r");
	  if(!fp)
	  {
		  perror(argv[i]);
		  continue;
	  }

	  int c;
	  while ((c = fgetc(fp)) != EOF)
		  putchar(c);

	  fclose(fp);

  }
  return 0;
}
