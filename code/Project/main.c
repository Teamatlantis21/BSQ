#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char open_pos; /* символ открытой позиции     | done 	*/
char obtacle_pos; /* символ закрытой позиции  | done	*/
char fill_pos; /* символ закрашенной п		  | done	*/
int count_str;/*							  | done	*/
char *config;/*                               | done	*/
int desc;/*                                   | done	*/
char *file_name;/*                            | done	*/
char **map; /* представление мапы в двумерном массиве	*/
char *help;
int j = 0;/*строки */
int k = 0;/*символы */

int format();
void start();
void config_create();
int not_char();
int repeat();
int lenght_error();
int array_check(int *array, int length);
void map_pull();
void print_array();

int	main(int count, char **args)
{
	file_name = args[1];
	start();
	config_create();
	format();
	map_pull();
	/*if(not_char() < 0 || repeat() < 0 || lenght_error() < 0) */
	/*	return -1; */
	return (0);
}

void	map_pull()
{
	int i;/*счетчик*/
	char *array;
	char *buf;

	array = (char *)malloc(sizeof(char) * 45000);
	i = 0;
	while (config[i] != '\0')
	{
		i++;
	}
	i++;
	printf("%s\n", config);
	read(desc, config, 45000);
	printf("%s\n", config);
	while (config[i] != '\0')
	{
		array[k] = config[i];
		k++;
		i++;
	}
	map = (char**)malloc(count_str * sizeof(char*));
	for (int i = 0; i < count_str; i++)
	{
		map[i] = (char*)malloc(50 * sizeof(char));
	}
	i = 0;
	k = 0;
	j = 0;
	printf("%d\n", count_str);
	while (j < count_str)
	{/*место говна*/
		while (array[i] != '\n' && array[i] != '\0')
		{
			map[j][k] = array[i];
			k++;
			i++;
		}
		printf("|%s|\n", map[j]);
		i++;
		j++;
		k = 0;
	}
}

int		lenght_error()
{
	int i;
	int j;
	char buf[48000];
	int pos[6];

	i = 0;
	j = 0;
	read(desc, buf, 48000);
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			pos[j] = i;
			j++;
		}
		i++;
	}
	pos[j] = i;
	return (array_check(pos, count_str));
}

int		array_check(int *array, int length)
{
	int diff;
	int i;

	i = 0;
	diff = array[i + 1] - array[i];
	while (i < length - 1)
	{
		if (array[i + 1] - array[i] != diff)
		{
			printf("i: %d, array[i + 1]: %d, array[i]: %d, fuck\n", i, array[i + 1], array[i]);
			return (-1);
		}
		else
		{
			printf("okey\n");
		}
		i++;
	}
	return (0);
}

int		repeat()
{
	if (open_pos == obtacle_pos || open_pos == fill_pos || obtacle_pos == fill_pos)
	{
		return (-1);
	}
	return (0);
}

int		not_char()
{
	if (config[0] < '0' || config[0] > '9')
	{
		return (-1);
	}
	return (0);
}

int		format()
{
	int i;

	i = 0;
	while (config[i] >= '0' && config[i] <= '9')
	{
		count_str += config[i] - '0';
		count_str *= 10;
		i++;
	}
	open_pos = config[i];
	obtacle_pos = config[i + 1];
	fill_pos = config[i + 2];
	count_str = count_str / 10;
	if(config[i + 3] != '\0')
	{
		return (-1);
	}
	return (0);
}

void	config_create()
{
	int i;

	i = 0;
	config = (char*)malloc(sizeof(char) * 45000);
	read(desc, config, 450);
	while (config[i] != '\n')
	{
		i++;
	}
	config[i] = '\0';
}

void		start()
{
	desc = open(file_name, O_RDWR);
}
