/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:24:24 by AleXwern          #+#    #+#             */
/*   Updated: 2021/07/26 15:24:24 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUDIO_H
# define AUDIO_H

#include "tactics.h"

/*
**	Note the following:
**	All audio is to be Mono and Signed 16-bit PCM with 44100 Hz
**	Main BG music is played on channel 8 and other small
**	sound effects on channels 9-31
*/
# define SAMPLERATE		44100
# define MAX_CHANNELS	CSND_NUM_CHANNELS
# define MIN_EFFCHANNEL	9
# define MUSIC_CHANNEL	8

#endif