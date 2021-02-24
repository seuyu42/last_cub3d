/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuyu <seuyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:12:36 by seuyu             #+#    #+#             */
/*   Updated: 2021/02/24 20:25:00 by seuyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_order(int *order, double *dist, int sp_num)
{
	int		i;
	int		j;
	int		tmp_order;
	double	tmp_dist;

	i = -1;
	while (++i < sp_num)
	{
		j = -1;
		while (++j < sp_num - 1)
		{
			if (dist[j] > dist[j + 1])
			{
				tmp_dist = dist[j];
				tmp_order = order[j];
				dist[j] = dist[j + 1];
				order[j] = order[j + 1];
				dist[j + 1] = tmp_dist;
				order[j + 1] = tmp_order;
			}
		}
	}
}

void	sort_sprite(int *order, double *dist, int sp_num)
{
	int		i;
	int		sp_order[sp_num];
	double	sp_dist[sp_num];

	i = -1;
	while (++i < sp_num)
	{
		sp_dist[i] = dist[i];
		sp_order[i] = order[i];
	}
	sort_order(sp_order, sp_dist, sp_num);
	i = -1;
	while (++i < sp_num)
	{
		dist[i] = sp_dist[sp_num - i - 1];
		order[i] = sp_order[sp_num - i - 1];
	}
}
