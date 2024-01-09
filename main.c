#include "monty.h"

/**
 * main - Monty Interpreter
 * @ac: arcuments' count
 * @av: arguments' array
 * Return: 0 if no error during runtime
 */
int main(int ac, char **av)
{
	unsigned int line_number = 1;

	checkFile(ac, av);
	for (; checkLine() != -1; line_number++)
	{
		if (glob.token)
		{
			glob.f = checkOp(glob.token, line_number);
			glob.f(&glob.top, line_number); }
	}
	freeStack();
	fclose(glob.fd);
	return (0);
}
