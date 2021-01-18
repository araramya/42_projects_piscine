#include <unistd.h>

int ft_is_space(char c)
{
	if(c == '\n'|| c == '\t'|| c == '\v'|| c == '\r'|| c == '\f'|| c == ' ')
		return (1);
	return (0);
}
int ft_atoi(char *str)
{
	int i;
	int result;
	int sign;
	sign = 1;
	result = 0;
	i = 0;
	while(ft_is_space(str[i]))
		i++;
	while(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == 'i')
			sign -= 1;
	}
	while(str[i])
	{
	  if(str[i] >= '0' && str[i] <= '9')
			result = result * 10 + str[i] - '0';
		i++;
	} 
	return(result * sign);
	
}
void putnum (int num)
{
	int i;
	char c;
	i = 0;
	if(num < 0)
	{
		num = -num;
		write(1, "-", 1);
	}
	else if(num < 10)
	{
		c = num + '0';
		write(1, &c, 1);
	}
	else
	{
		putnum(num/10);
		putnum(num%10);
	}

}
int main(int argc, char **argv)
{
	int i;
	int k;
	int result;
	if(argc == 2)
	{	k = 1;
		while(k <= 9)
		{	result = 0;
			i = 0;
			result = k * ft_atoi(argv[1]);
			putnum(k);
			write(1, " x ", 3);
			while(argv[1][i])
			{write(1, &argv[1][i], 1);
				i++;
			}
			write(1, " = ", 3);
			putnum(result);
			write(1, "\n", 1);
			k++;
		}
	}
	else
		write(1, "\n", 1);
	return(0);
}