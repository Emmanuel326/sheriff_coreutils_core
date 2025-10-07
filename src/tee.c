#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//the block below is for testing purposes.
	for(int i =0; i < argc; i++)
	printf("argv[%d] = %s\n", i, argv[i]);


	int append_mode =0;
	int start_index =1;

	//if first argument is "-a"
	if(argc > 1 && argv[1][0] == '-' && argv[1][1]== 'a')
	{
		append_mode =1;
		start_index =2;
	}
}
