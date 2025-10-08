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
	//open all files
	int num_files = argc - start_index;
	FILE **files = malloc(num_files * sizeof(FILE *));
	if(!files)
	{
		perror("Malloc");
		return 1;
	}
	for(int i =0; i<num_files;i++)
	{
		files[i] =fopen(argv[start_index + i], append_mode ? "a" : "w")
			if(!files[i])
			{
				perror(argv[start_index + 1]);
				//close any opened files before we exit
				for(int j =0;j<i;j++)
					fclose(files[j]);
				free(files);
				return 1;
			}
	}
	//cleaning
	for(int i=0;i<num_files; i++)
		fclose(files[i]);
	free(files);

	return 0;
}
