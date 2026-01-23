/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:31:17 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/23 12:42:54 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	error_msg(char *msg)
{
	printf("Error%s\n", msg);
}

void	error_msg2(char *msg, char print_char)
{
	printf("Error%s %c in map\n", msg, print_char);
}
