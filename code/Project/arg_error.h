int arg_format(char *arg);
int arg_not_char(char *arg);
int arg_repeat(char open_pos, char obtacle_pos, char fill_pos);

int arg_error(char *arg, char open_pos, char obtacle_pos, char fill_pos)
{
	if(arg_format(arg); == -1)
	{
		return -1;
	}
	if (arg_not_char(arg) == -1)
	{
		return -1;
	}
	if(arg_repeat(open_pos, obtacle_pos, fill_pos) == -1)
	{
		return -1;
	}
	return 0;
}

#pragma region
int arg_format(char *arg)
{
	int i;

	i = 0;
	while(arg[i] >= '0' && arg[i] <= '9')
	{
	    count_str += arg[i] - '0';
	    count_str *= 10;
	    i++;
	}
	open_pos = arg[i];
	obtacle_pos = arg[i + 1];
	fill_pos = arg[i + 2];
	count_str = count_str / 10;
	if(arg[i + 3] != '\0')
	{
	    return (-1);
	}
	return 0;
}
int arg_not_char(char *arg)
{
	if(arg[0] < '0' && arg[0] > '9')
	{
		return -1;
	}
	return 0;

}
int arg_repeat(char open_pos, char obtacle_pos, char fill_pos)
{
	if(open_pos == obtacle_pos || open_pos == fill_pos || obtacle_pos == fill_pos)
	{
		return -1;
	}
	return 0;
}
#pragma endregion
