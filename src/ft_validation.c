#include "lemin.h"


void	ft_check_comment(char *str)
{
	if (str[0] != '#')
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
}

void	ft_check_neg(char *str)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (str[i++])
	{
		if (str[i] == ' ')
			nbr++;
	}
	if (nbr != 2)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
}

void	ft_check_line(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0' && str[i] != ' ')
	{
		if (str[i] < 48 || str[i] > 59)
		{
			ft_putstr("ERROR\n");
			exit(0);
		}
		i++;
	}
}

void	ft_valid_room(char *line)
{
	int		nbr;
	char	*str;
	
	nbr = 0;
	str = line;
	ft_check_neg(str);
	str = ft_strchr(str, ' ');
	ft_check_line(str);
	nbr = ft_atoi(str);
	if (nbr < 0 || nbr > 2147483647)
	{
		ft_putstr("ERROR\n");
		return ;
	}
	str++;
	str = ft_strchr(str, ' ');
	ft_check_line(str);
	nbr = ft_atoi(str);
	if (nbr < 0 || nbr > 2147483647)
	{
		ft_putstr("ERROR\n");
		return ;
	}
}

void	ft_eddfunc(char *str, int *room, int *link)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (str[i] == ' ')
			(*room)++;
		else if (str[i] == '-' && str[i - 1] != ' ')
			(*link)++;
	}
}