int standart_input()
{
	char *buffer;
	int len;

	buffer = malloc(sizeof(char*));
	len = read(0, buffer, 700);
	return (buffer);
}
