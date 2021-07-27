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

#include "../includes/tactics.h"

int		init_all(void)
{
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	if (romfsInit())
		return (0);
	consoleInit(GFX_BOTTOM, NULL);
	csndInit();
	return (1);
}

int		exit_all(void)
{
	audio_stop();
	csndExit();
	romfsExit();
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return (1);
}