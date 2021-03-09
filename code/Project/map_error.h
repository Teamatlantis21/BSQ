#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int map_lines_count(char *file_name, int desc);
int map_lenght_error(char *file_name, int desc);
int map_dis_char(char *file_name, int desc, char first, char second);

int map_error(char *file_name, int desc, char first, char second)
{
	if(map_lines_count(file_name, desc) == -1)
	{
		return -1;
	}
	if (map_dis_char(file_name, desc, first, second) == -1)
	{
		return -1;
	}
	if(map_lenght_error(file_name, desc) == -1)
	{
		return -1;
	}
	return 0;
}

#pragma region
int map_dis_char(char *file_name, int desc, char first, char second)
{
	char buf[48000];
	int i;

	read(desc, buf, 48000);
	i = 0;
	while(buf[i] != '\0')
	{
		if(buf[i] != first && buf[i] != second && buf[i] != '\n')
		{
			return -1;
		}
		i++;
	}
	return 0;
}

int map_lines_count(char *file_name, int desc)
{
	int i;
	int count;

	i = 0;
	count = 1;
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

int map_lenght_error(char *file_name, int desc)
{
    int i;
    int j;
    char buf[48000];
    int pos[8];

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
	array_check(pos, count_str);
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
			return 0;
		}
        i++;
    }
}
#pragma endregion
