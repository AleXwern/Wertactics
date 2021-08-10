/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_editor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:34:23 by AleXwern          #+#    #+#             */
/*   Updated: 2021/08/05 15:17:43 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tactics.h"
#include "editor.h"

void	render_editor(t_screen *top)
{
	C2D_TargetClear(top, 0x000000ff);
	C2D_SceneBegin(top);
}

void	render_editor_bottom(t_screen *bottom)
{
	return;
}

void	init_editor(void)
{
	
}

void	exit_editor(void)
{
	
}
