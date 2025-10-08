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


/*
 * // --- Experimental super-fast version (commented out) ---
    // This is just a concept using fread/fwrite + intrinsics (SSE/AVX)
    // to process larger chunks at once instead of byte-by-byte.

    #include <immintrin.h>

    #define BUF_SIZE 4096
    unsigned char buf[BUF_SIZE];
    size_t n;

    while ((n = fread(buf, 1, BUF_SIZE, stdin)) > 0) {
        // Write to stdout
        fwrite(buf, 1, n, stdout);

        // Example vectorized broadcast (dummy idea)
        // __m256i data = _mm256_loadu_si256((__m256i*)buf);
        // _mm256_stream_si256((__m256i*)dest, data);

        for (int i = 0; i < num_files; i++)
            fwrite(buf, 1, n, files[i]);
    }
    */

