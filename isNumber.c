#include "monty.h"
/**
 * isNumber - check string is full of numbers or not
 * @number: string
 * Return: if string is not number return 0
 */
int isNumber(char *number)
{
	int i = 0;

	for (i = 0; number[i] != '\0'; i++)
	{
		if(number[0] == '-')
			++i;
		if ((isdigit(number[i])) == 0)
			return (0); }
	return (-1);
}
