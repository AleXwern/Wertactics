/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:07:07 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/26 15:07:07 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "audio.h"

Mix_Music	*music;

int			load_music(const char *path)
{
	music = Mix_LoadMUS_RW(SDL_RWFromFile(path, "rb"));
	if (!music)
		return (0);
	Mix_OpenAudio(44100, AUDIO_S16LSB, 1, 2048);
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	printf("\x1b[14;0HPlaying on %d\n", Mix_PlayMusic(music, 20));
	return (1);
}

int			swap_music(const char *path)
{
	Mix_FreeMusic(music);
	music = Mix_LoadMUS_RW(SDL_RWFromFile(path, "rb"));
	if (!music)
		return (0);
	Mix_PlayMusic(music, 20);
	return (1);
}
