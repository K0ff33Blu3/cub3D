/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:31:17 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/18 16:56:31 by elmondo          ###   ########.fr       */
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



