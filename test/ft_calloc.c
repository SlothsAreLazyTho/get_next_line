char	*ft_calloc(int count, int type)
{
	char	*str;

	str = (char *) malloc(count * type);
	if (!str)
		return (NULL);
	while(count--)
		str[count] = 0;
	return (str);
}
