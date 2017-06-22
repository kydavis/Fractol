/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 11:32:36 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 09:54:12 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
** Uses ft_putnbr_fd to print an int to the standard output.
*/

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}