/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 22:30:13 by imorimot          #+#    #+#             */
/*   Updated: 2018/07/12 23:32:48 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else
		{
			i++;
		}
	}
	return ('\0' - s2[i]);
}

char	**ft_swap(char **tab, int size)
{
	int		i;
	char	*buffer;

	i = 0;
	while (i < size - 1)
	{
		buffer = tab[i];
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			buffer = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = buffer;
		}
		i++;
	}
	return (tab);
}

void	ft_sort_string_table(char **tab, int size)
{
	int		count;

	count = 1;
	while (count <= size - 1)
	{
		tab = ft_swap(tab, size);
		count++;
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		ft_sort_string_table(argv, argc);
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
