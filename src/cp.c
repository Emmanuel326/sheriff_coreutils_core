#include <stdio.h>
#include <stdlib.h>  // This is used for exit()
		     

int main(int argc, char *argv[])
{
	FILE *source_fp, *dest_fp;
	int c; //Must be an int to correctly hold EOF(end of file)

	//1. i will check for the correct number of arguments
	if(argc != 3)
	//argv[0] is the program name,	
	{
		fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
		exit(EXIT_FAILURE);

	}

	//2. we open the source file for reading
	source_fp = fopen(argv[1], "r");
	if(source_fp ==NULL)
	{
		perror("Error opening source fie");
		exit(EXIT_FAILURE);
	}

	//3.Open the destination file for writing


}


