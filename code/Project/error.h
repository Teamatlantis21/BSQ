#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char open_pos; // символ открытой позиции
char obtacle_pos; // символ закрытой позиции
char fill_pos; // символ закрашенной п
int count_str;
char *configargument; // хранит значение конфигурации мапы
int desc;
char *file_name;

int map_dis_char();
int map_lines_count();
int map_lenght_error();
int array_check();
int arg_format();
int arg_not_char();
int arg_repeat();
void arg_founder();
#pragma region map

int map_dis_char()
{
	char buf[48000];
	int i;

	read(desc, buf, 48000);
	i = 0;
	while(buf[i] != '\0')
	{
		if(buf[i] != open_pos && buf[i] != obtacle_pos && buf[i] != '\n')
		{
			return -1;
		}
		i++;
	}
	return 0;
}

int map_lines_count()
{
	int i;
	int count;

	i = 5;
	char buf[48000];
	read(desc, buf, 48000);
	while(buf[i] != '\0')
	{
		if(buf[i] == '\n')
		{
			count++;
		}
		i++;
	}
	if(count_str != count)
	{
		printf("map error: lines error");
		return (-1);
	}
	printf("%d", count);
	return 0;
}

int map_lenght_error()
{
	int i;
	int j;
	char buf[48000];
	int pos[6];

	i=0;
	j= 0;
	read(desc, buf, 48000);
	while(buf[i] != '\0')
	{
		if(buf[i] == '\n')
		{
			pos[j] = i;
			j++;
		}
		i++;
	}
	pos[j] = i;
	return array_check(pos, count_str);
}

int array_check(int *array, int length)
{
	int diff;
	int i;

	i = 0;
	diff = array[i + 1] - array[i];
	while(i < length - 1)
	{
		if(array[i + 1] - array[i] != diff)
		{
			printf("i: %d, array[i + 1]: %d, array[i]: %d, fuck\n", i, array[i + 1], array[i]);
			return -1;
		}
		else
		{
			printf("okey\n");
		}
		i++;
	}
	return 0;
}
int map_error()
{
	if(map_dis_char() == -1)
		return -1;
	else if(map_lines_count() == -1)
		return -1;
	else if(map_lenght_error() == -1)
		return -1;
	else
	{
		return 0;
	}
}
#pragma endregion
#pragma region arg

int arg_format()
{
	int i;

	i = 0;
	while(argument[i] >= '0' && argument[i] <= '9')
	{
		count_str += argument[i] - '0';
		count_str *= 10;
		i++;
	}
	open_pos = argument[i];
	obtacle_pos = argument[i + 1];
	fill_pos = argument[i + 2];
	count_str = count_str / 10;
	if(argument[i + 3] != '\0')
	{
		return (-1);
	}
	return 0;
}
int arg_not_char()
{
	if(argument[0] < '0' && argument[0] > '9')
	{
		return -1;
	}
	return 0;

}
int arg_repeat()
{
	if(open_pos == obtacle_pos || open_pos == fill_pos || obtacle_pos == fill_pos)
	{
		return -1;
	}
	return 0;
}
void arg_founder()
{
	char buf[48000];
	int i;

	read(desc, buf, 48000);
	i = 0;
	while(buf[i] != '\n')
	{
		argument[i] = buf[i];
		i++;
	}
}

int arg_error()
{
	if(arg_format() == -1)
		return -1;
	else if(arg_not_char() == -1)
		return -1;
	else if(arg_repeat() == -1)
		return -1;
	else
	{
		return 0;
	}
}
#pragma endregion

int transform()
{
	int i;

	i = 0;
	while (read(desc, file_name, 1) != '\n')
		i++;
	i++;
	while (read(desc, file_name, 1) != '\0')
	{

	}
}

int global_error(char *file)
{
	file_name = (char *)malloc(sizeof(char) * 100);
	argument = (char *)malloc(sizeof(char) * 100);
	if(map_error() == -1)
		return -1;
	else if(arg_error() == -1)
		return -1;
	else
	{
		return 0;
	}
}
