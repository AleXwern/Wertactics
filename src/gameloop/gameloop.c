/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:14:12 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/01 15:14:12 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"

void			(*g_render)(t_screen*);
int				(*g_keyhandle)(void);

void			game_loop(void)
{
	u64			time;
	u64			newtime;
	u64			fps;
	t_screen	*top;
	
	top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	time = osGetTime();
	fps = 0;
	while (aptMainLoop())
	{
		hidScanInput();
		if (g_keyhandle())
			break;
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		g_render(top);
		C3D_FrameEnd(0);
		newtime = osGetTime();
		if (newtime - time > 1000)
		{
			printf("\x1b[5;0Hfps %llu\n", fps);
			time = newtime;
			fps = 0;
		}
		fps++;
	}
}

/*
**	Set what functions handle rendering and corresponding key handling.
**	Both are set at the same place just in case to avoid and
**	desyncs.
*/
void	set_gameloop(void (*render)(t_screen*), int (*keyhandle)(void))
{
	g_render = render;
	g_keyhandle = keyhandle;
}
