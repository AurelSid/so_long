

int	int_length(int n)
{
	int	length;

	length = 1;
	if (n < 0)
	{
		length++;
		n = -n;
	}
	while (n >= 10)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

char	*int_to_string(int n, int length)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = length - 1;
	str[length] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int	length;

	length = int_length(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (int_to_string(n, length));
}