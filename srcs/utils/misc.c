#include <limits.h>
#include <stdio.h>

// Function to skip leading whitespaces
const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
	{
		str++;
	}
	return (str);
}

// Function to determine the sign of the number
int	determine_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		sign = (*(*str)++ == '-') ? -1 : 1;
	}
	return (sign);
}

// Function to determine the base and skip prefix
int	determine_base(const char **str)
{
	int	base;

	base = 0;
	if (**str == '0')
	{
		(*str)++;
		if (**str == 'x' || **str == 'X')
		{
			base = 16;
			(*str)++;
		}
		else
		{
			base = 8;
		}
	}
	return (base);
}

// Function to process digits and convert to long integer
long int	process_digits(const char **str, int base, int sign)
{
	long int	result;
	int			digit;

	result = 0;
	while ((**str >= '0' && **str <= '9') || (**str >= 'a' && **str <= 'z')
		|| (**str >= 'A' && **str <= 'Z'))
	{
		if (**str >= '0' && **str <= '9')
			digit = *(*str)++ - '0';
		else
			digit = ((**str >= 'a' && **str <= 'z') ? (*(*str)++ - 'a'
						+ 10) : (*(*str)++ - 'A' + 10));
		if (digit >= base)
			break ;
		if (result > (LONG_MAX - digit) / base)
		{
			result = (sign == 1) ? LONG_MAX : LONG_MIN;
			break ;
		}
		result = result * base + digit;
	}
	return (result);
}

// Function to convert string to long integer
long int	ft_strtol(const char *str, char **endptr, int base)
{
	int			sign;
	long int	result;

	str = skip_whitespace(str);
	sign = determine_sign(&str);
	base = (base == 0) ? determine_base(&str) : base;
	result = process_digits(&str, base, sign);
	if (endptr != NULL)
	{
		*endptr = (char *)str;
	}
	return (sign * result);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
