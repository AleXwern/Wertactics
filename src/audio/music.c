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

u8*		buffer;
u32		size;

void	audio_load(void)
{
	FILE *file = fopen("romfs:/str4E.wav", "rb");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	buffer = linearAlloc(size);
	off_t bytesRead = fread(buffer, 1, size, file);
	fclose(file);
	csndPlaySound(8, SOUND_FORMAT_16BIT | SOUND_REPEAT, SAMPLERATE, 1, 0, buffer, buffer, size);
	//linearFree(buffer);
}

void	audio_swap(const char *path)
{
	audio_stop();		//Calling this once cuts audio but twice makes it work properly??
	audio_stop();		//Investigation is needed.
	FILE *file = fopen(path, "rb");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	buffer = linearAlloc(size);
	off_t bytesRead = fread(buffer, 1, size, file);
	fclose(file);
	csndPlaySound(MUSIC_CHANNEL, SOUND_FORMAT_16BIT | SOUND_REPEAT, SAMPLERATE, 1, 0, buffer, buffer, size);
	//linearFree(buffer);
}

void	audio_stop(void)
{
	csndExecCmds(true);
	CSND_SetPlayState(0x8, 0);
	memset(buffer, 0, size);
	GSPGPU_FlushDataCache(buffer, size);
	linearFree(buffer);
}

u8*		eff_buffer[2];
u32		eff_size[2];

void	load_effect(const char *path, u8 id)
{
	FILE *file = fopen(path, "rb");
	fseek(file, 0, SEEK_END);
	eff_size[id] = ftell(file);
	fseek(file, 0, SEEK_SET);
	eff_buffer[id] = linearAlloc(eff_size[id]);
	off_t bytesRead = fread(eff_buffer[id], 1, eff_size[id], file);
	fclose(file);
}

void	play_effect(u8 id)
{
	static int	chn;

	if (chn < MIN_EFFCHANNEL || chn >= MAX_CHANNELS)
		chn = MIN_EFFCHANNEL;
	csndPlaySound(chn, SOUND_FORMAT_16BIT | SOUND_ONE_SHOT, SAMPLERATE, 1, 0, eff_buffer[id], eff_buffer[id], eff_size[id]);
	chn++;
	//linearFree(eff_buffer[id]);
}
