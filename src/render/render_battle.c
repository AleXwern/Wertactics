/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_battle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:45:57 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/10 16:38:34 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "battle.h"

t_battlechar	g_battle[MAX_CHARA];
C2D_Sprite		g_enemies[MAX_ENEMY];
u8				g_enemycount;

void			render_battle(t_screen *top)
{
	
}

void			render_battle_bottom(t_screen *bottom)
{
	return;
}

void			init_battle(char *id)
{
	int			fd;
	char		**data;

	ft_bzero(&g_battle, sizeof(g_battle));
	id = ft_strsjoin("romfs:/enemyform/", id);
	fd = open(id, O_RDONLY | O_BINARY);
	free(id);
	clear_next_line(fd);
	for (u16 i = 0; i < ACTIVE_SIZE; i++)
	{
		g_battle[i].sprite = g_active[i]->sprite;
		g_battle[i].x = 250;
		g_battle[i].y = 20 + (i * 50);
		g_battle[i].dir = NPC_DIR_LEFT;
	}
	get_next_lineg(fd, &id);
	data = ft_strsplit(id, ',');
	free(id);
	g_enemycount = ft_listlen(data) / 3;
	for (u16 i = 0; i < g_enemycount; i++)
	{
		g_battle[PLAYER_END + i].sprite = ft_atoi(data[i * 3]);
		g_battle[PLAYER_END + i].x = ft_atoi(data[i * 3 + 1]);
		g_battle[PLAYER_END + i].y = ft_atoi(data[i * 3 + 2]);
		g_battle[PLAYER_END + i].dir = NPC_DIR_RIGHT;
	}
	ft_splitfree(data);
	get_enemy_sprites(g_enemies, g_battle + PLAYER_END);
	set_gameloop(render_battle, render_battle_bottom, key_state_battle);
}

void			exit_battle(void)
{
	set_gameloop(render_game, render_game_bottom, key_state_game);
}
