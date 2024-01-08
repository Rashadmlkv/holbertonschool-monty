#include "monty.h"
/**
 * checkfile - checks file status
 * @str: filename
 * Return: doesn't
 */
int checkfile(char *str)
{
	glob.fd = fopen(str, "r");

	if (!glob.fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		freeStack();
		fclose(glob.fd);
		exit(EXIT_FAILURE); }
	else
	{
		checkline(glob.fd); }
	fclose(glob.fd);
	return (0);
}
