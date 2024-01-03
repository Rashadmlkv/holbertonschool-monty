#include "monty.h"

int main(int ac, char **av)
{
        FILE *fd;
	char *buffer = NULL, *token = NULL;
	size_t max = 0;
	int i, j;
	char *f;
	stack_t *top = malloc(sizeof(stack_t));
	void instructions[]= {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	}

	if (ac > 2 || ac == 1)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

        if((fd = fopen(av[1], "r")) == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", av[1]),
			exit(EXIT_FAILURE);

	for (i = 1; getline(&buffer, &max, fd) != -1; i++)
	{
		token = strtok(buffer, " \n");

		for (j = 0; instructions[j] != NULL; j++)
		{
			if (instructions[j] == token)
				f = instructions[j];
		}
		token = strtok(NULL, " $\n");
	        if (token != NULL)
		{
			if(atoi(token) == 0 && (strcmp(token, "0")) != 0)
				printf("err\n");
			else
			{
				top->n = atoi(token);
				push(&top, i);
			}
		}
	}
	pall(&top, i);
	printf("::%d\n", top->n);
	fclose(fd);
}
