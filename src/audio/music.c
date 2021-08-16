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
	Mix_AllocateChannels(MAX_CHANNELS);
	Mix_OpenAudio(44100, AUDIO_S16LSB, 1, 2048);
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	Mix_PlayMusic(music, -1);
	return (1);
}

int			swap_music(const char *path)
{
	Mix_Music	*temp;
	
	temp = Mix_LoadMUS_RW(SDL_RWFromFile(path, "rb"));
	if (!temp)
		return (0);
	Mix_HaltMusic();
	Mix_FreeMusic(music);
	music = temp;
	Mix_PlayMusic(music, -1);
	return (1);
}

// This function is given to Mixer to make music start again if
// 65000 loops (at least 3 months) pass and music stops.
void		resume_music(void)
{
	Mix_PlayMusic(music, -1);
}
