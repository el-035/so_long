/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:37:42 by efittant          #+#    #+#             */
/*   Updated: 2024/12/23 15:37:45 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *error_msg, t_mlx data)
{
	ft_printf(error_msg);
	if (data.mlx)
		destroy_everything(&data);
}

void	errors(char *error_msg, t_mlx data)
{
	perror (error_msg);
	if (data.mlx)
		destroy_everything(&data);
}
