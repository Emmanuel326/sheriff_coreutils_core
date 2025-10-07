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
	//"w" mode creates the file if it doesnt exist or truncates it if it does
	dest_fp = fopen(argv[2], "w");
	if(dest_fp = NULL)
	{
		perror("Error opening destination file");
		fclose(source_fp);//close the source file before closing
		exit(EXIT_FAILURE);
	}

	//CORE COPY LOOP METHOD(). it copies cha-by-char
	while((c = fgetc(source_fp)) != EOF)
	{
		//read char from source and write in dest
		if(fputc(c, dest_fp) == EOF)
		{
			perror("Error writing to destination file");
			break; //exit the loop on write error
		}
	}

	//5. close files and check for I/O errors
	//the loop may have terminated due to EOF or a read error 
	if(ferror(source_fp))
	{
		fprintf(stderr, "Read error occurred on source file.\n");
	}

	//always close file streams
	fclose(source_fp);
	fclose(dest_fp);

	return 0;


}


