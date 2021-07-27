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
	t_background	bg;
	u64				time, newtime;
	u64				fps;

	if (init_all())
		ft_putendl("Inizialized systems!");
	top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	if (!load_backgrounds())
		exit_out("Couldn't load backdrops!");
	if (!load_PlayerNPC())
		exit_out("Couldn't load npcs!");
	time = osGetTime();
	fps = 0;
	bg = (t_background){{.id = 0, .effect = EFF_SCROLL_WPLR},
						{.id = 1, .effect = EFF_SCROLL_WPLR},
						{.id = 2, .effect = EFF_SCROLL_WPLR}};
	audio_load();
	load_effect("romfs:/eff0.wav", 0);
	load_effect("romfs:/eff1.wav", 1);
	while (aptMainLoop())
	{
		hidScanInput();
		if (key_state_game())
			break;
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, 0x000000ff);
		C2D_SceneBegin(top);
		draw_background(&bg);
		C3D_FrameEnd(0);
		newtime = osGetTime();
		if (newtime - time > 1000)
		{
			printf("\x1b[5;0Hfps %llu\nLinear %ld\n", fps, linearSpaceFree());
			time = newtime;
			fps = 0;
		}
		fps++;
	}
	exit_out("Graceful exit.");
	return 0;
}