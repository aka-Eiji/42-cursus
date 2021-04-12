/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:18:49 by jkosiara          #+#    #+#             */
/*   Updated: 2020/12/09 18:18:51 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (0);
	if (c == '+' || c == '-')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	else
		return (3);
}

void	conversion(char c, int check, int *n)
{
	if (check == 2)
	{
		*n *= 10;
		*n += c - '0';
	}
}

int		ft_atoi(char *str)
{
	int sign;
	int flag;
	int n;
	int i;

	sign = 0;
	flag = 0;
	n = 0;
	i = 0;
	while (str[i] && flag < 3)
	{
		if (check(str[i]) >= flag)
		{
			flag = check(str[i]);
			if (flag == 1 && str[i] == '-')
				sign++;
			conversion(str[i], flag, &n);
		}
		else
			flag = 3;
		i++;
	}
	if (sign % 2 == 1)
		n *= -1;
	return (n);
}
