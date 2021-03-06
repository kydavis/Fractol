/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 12:10:00 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 12:40:30 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function 'f' to each character in a string.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (*s)
		f(s++);
}
