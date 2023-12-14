// main.c
#include "monty.h"

int main(int argc, char *argv[])
{
	// Check for correct number of arguments
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	// Open file
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// TODO: Read and parse the Monty byte code file, execute instructions

	fclose(file);

	return 0;
}
