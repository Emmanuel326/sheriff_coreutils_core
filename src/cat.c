#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//if no file argument, read from stdin
	if(argc == 1)
	{
		int c;
		while((c = fgetc(stdin)) != EOF)
			putchar(c);
		return 0;
	}
	//otherwise handle each argument
	for(int i =1; i < argc; i++)
	{
		FILE *fp;
		//handle "-" as stdin
		if(strcmp(argv[i], "-")==0)
		{
			fp=stdin;
		}
		else
		{
			fp = fopen(argv[i],"r");
			if (!fp)
			{
				perror(argv[i]);
				continue;
			}
		}
		
		int c;
		while((c = fgetc(fp)) != EOF)
			putchar(c);

		//dont close stdin yet
		//
		if(fp != stdin)
			fclose(fp);

	}
	return 0;
}
