/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:41:07 by jkosiara          #+#    #+#             */
/*   Updated: 2020/12/11 12:41:22 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int res;

	res = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (res * ft_recursive_power(nb, power - 1));
}
