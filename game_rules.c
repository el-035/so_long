/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:38:12 by efittant          #+#    #+#             */
/*   Updated: 2024/12/23 15:38:14 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectibles(t_mlx *data, int x, int y)
{
	data->map[y][x] = '0';
	data->collectible_count--;
	if (data->collectible_count == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->end_open, \
		data->x_end, data->y_end);
}

void	end_of_game(t_mlx *data)
{
	if (data->collectible_count == 0)
	{
		ft_printf("moves: %d\n", data->moves++);
		ft_printf("You won!\n");
		destroy_everything(data);
	}
	else
		return ;
}
