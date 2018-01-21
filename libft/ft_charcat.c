/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 03:10:07 by adaly             #+#    #+#             */
/*   Updated: 2017/05/27 03:13:39 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_charcat(char *str, unsigned int c)
{
	if (str)
	{
		while (*str)
			++str;
		*str = c;
	}
}
