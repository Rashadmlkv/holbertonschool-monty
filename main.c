#include "monty.h"

/**
 * main - Monty Interpreter
 * @ac: arcuments' count
 * @av: arguments' array
 * Return: 0 if no error during runtime
 */
int main(int ac, char **av)
{
	checkFile(ac, av);
        checkLine();
	freeStack();
	fclose(glob.fd);
	return (0);
}
