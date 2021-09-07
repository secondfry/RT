/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:36:16 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/09/07 19:38:13 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace/raytrace_texture.h"
#include "defines.h"
#include "rtv.h"
#include "vector.h"

static void	_check_texture(
	t_rtv *rtv,
	const t_light_params *params,
	t_intersection *intr
)
{
	const t_plane		plane = rtv->planes[intr->idx];
	const t_vector_4	vec_pc = vector_uv(rtv, \
		vector_sub(plane.position, params->vec_p));
	const size_t		uv[2] = {vec_pc.x, vec_pc.z};
	const size_t		offset = 4 * (uv[1] * rtv->textures[0].width + uv[0]);
	const t_color		color = {
		rtv->textures[0].data[offset + 0],
		rtv->textures[0].data[offset + 1],
		rtv->textures[0].data[offset + 2],
	};

	if (rtv->textures[0].data[offset + 3] == 0)
		return ;
	ft_memcpy((void *)&params->color, &color, sizeof(t_color));
}

void	check_texture(
	t_rtv *rtv,
	const t_light_params *params,
	t_intersection *intr
)
{
	if (intr->type != IPLANE)
		return ;
	if (!(rtv->planes[intr->idx].traits & TRAIT_TEXTURED))
		return ;
	if (!rtv->textures[0].data)
		return ;
	return (_check_texture(rtv, params, intr));
}
