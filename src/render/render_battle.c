/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_battle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:45:57 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/16 16:28:02 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "battle.h"

t_battlechar	g_battle[MAX_CHARA];
C2D_Sprite		g_enemies[MAX_ENEMY];
C2D_Sprite		g_battlebg;
u8				g_enemycount;

void			render_battle(t_screen *top)
{
	C2D_TargetClear(top, 0xff000000);
	C2D_SceneBegin(top);
	C2D_DrawSprite(&g_battlebg);
	for (u8 i = 0; i < ACTIVE_SIZE; i++)
	{
		C2D_SpriteSetPos(&g_npcs[NPC_DIR_LEFT], g_battle[i].x, g_battle[i].y);
		C2D_DrawSprite(&g_npcs[NPC_DIR_LEFT]);
	}
	for (u8 i = 0; i < g_enemycount; i++)
	{
		C2D_SpriteSetPos(&g_enemies[i], g_battle[ACTIVE_SIZE + i].x, g_battle[ACTIVE_SIZE + i].y);
		C2D_DrawSprite(&g_enemies[i]);
	}
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
	if (!(id = ft_strsjoin("romfs:/enemyform/", id)))
		exit_out(MALLOC_ERROR);
	fd = open(id, O_RDONLY | O_BINARY);
	free(id);
	if (fd == -1)
		return;
	clear_next_line(fd);
	for (u16 i = 0; i < ACTIVE_SIZE; i++)
	{
		//g_battle[i].sprite = g_active[i]->sprite;
		g_battle[i].x = 310;
		g_battle[i].y = 20 + (i * 50);
		g_battle[i].dir = NPC_DIR_LEFT;
	}
	if (get_next_lineg(fd, &id) != 1)
		exit_out(MALLOC_ERROR);
	close(fd);
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
	get_battle_bg(&g_battlebg, 0);
	set_gameloop(render_battle, render_battle_bottom, key_state_battle);
	swap_music("romfs:/audio/bgm/finboss.ogg");
}

void			exit_battle(void)
{
	set_gameloop(render_game, render_game_bottom, key_state_game);
	g_player.aggro = 0;
	g_player.maxaggro = randomx() % 50 + 20;
	swap_music("romfs:/audio/bgm/str4E.ogg");
}

