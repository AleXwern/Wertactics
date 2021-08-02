/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:31:19 by AleXwern          #+#    #+#             */
/*   Updated: 2021/01/02 15:31:19 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "menu.h"

int		init_all(void)
{
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	if (romfsInit())
		return (0);
	consoleInit(GFX_BOTTOM, NULL);
	SDL_Init(SDL_INIT_AUDIO);
	Mix_Init(MIX_INIT_OGG);
	Mix_HookMusicFinished(resume_music);
	init_menu();
	init_mm_sequence();
	return (1);
}

int		exit_all(void)
{
	Mix_Quit();
	SDL_Quit();
	romfsExit();
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return (1);
}
