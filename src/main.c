/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:53:56 by AleXwern          #+#    #+#             */
/*   Updated: 2021/01/02 14:53:56 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "player.h"

int				main()
{
	C3D_RenderTarget	*top;
	u64				time, newtime;
	u64				fps;
	u8				kill = 0;

	if (init_all())
		ft_putendl("Inizialized systems!");
	top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	if (!load_backgrounds())
		exit_out("Couldn't load backdrops!");
	if (!load_PlayerNPC())
		exit_out("Couldn't load npcs!");
	time = osGetTime();
	fps = 0;
	g_map = (t_area*)linearAlloc(sizeof(t_area));
	if (load_map(ft_itoa(0), 1, 1))
		exit_out("Map error");
	if (!load_music("romfs:/str4E.ogg"))
		printf("\x1b[14;0HWääää\n");
	while (aptMainLoop())
	{
		hidScanInput();
		kill = key_state_game();
		if (kill)
			break;
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, 0x000000ff);
		C2D_SceneBegin(top);
		draw_background();
		C3D_FrameEnd(0);
		newtime = osGetTime();
		if (newtime - time > 1000)
		{
			printf("\x1b[5;0Hfps %llu\nLinear %ld Heap %ld\n", fps, linearSpaceFree(), envGetHeapSize());
			time = newtime;
			fps = 0;
		}
		fps++;
	}
	exit_out("Graceful exit.");
	return 0;
}
