#include "monty.h"

/**
 * main - Entry point for Monty bytecode interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Description:
 * - The main function is the starting point for the Monty
 * bytecode interpreter.
 * - It takes the number of command-line arguments (argc) and an array of
 * command-line argument strings (argv).
 * - The function is responsible for opening a Monty bytecode file,
 * reading and
 * interpreting the instructions within it, managing the stack,
 * and performing the necessary operations based on the instructions.
 *
 * Return: EXIT_SUCCESS if the interpreter runs successfully,
 *         EXIT_FAILURE on failure (e.g., if the file cannot be opened or an
 *         error occurs during execution).
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_len = 0;
	ssize_t read = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &line_len, file)) != -1)
	{
		line_number++;
		execute_instruction(line, &stack, line_number);
	}
	fclose(file);
	free(line);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
