/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 04:58:56 by adaly             #+#    #+#             */
/*   Updated: 2017/11/24 15:03:03 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/p-lost.h"

void		ft_hooks(t_env *env)
{
	if (env)
	{
	mlx_do_key_autorepeatoff(env->mlx.mlx);
	mlx_hook(env->mlx.win, 2, 0, key_press_hook, env);
	mlx_hook(env->mlx.win, 3, 0, key_release_hook, env);
//	mlx_hook(env->mlx.win, 12, 0, expose_hook, env);
	mlx_hook(env->mlx.win, 17, 0, exit_hook, env);
	mlx_loop_hook(env->mlx.mlx, ft_loop, env);
	}
}

int		ft_loop(t_env *env)
{
	drawSelf(env, env->views);
	drawGrid(env, env->views);
	drawBattleUnderlay(env, env->views + 1);
	drawViews(env);
	if (env->inBattle)
		ft_battleControl(env);
	else
		ft_dungeonControl(env);
	usleep(env->tickLength);
	ft_decay(env);
	return (0);
}

int		key_release_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_SHIFT_LEFT)
		;
	else if (keycode == KEY_W)
		env->keys.up = 0;
	else if (keycode == KEY_A)
		env->keys.left = 0;
	else if (keycode == KEY_S)
		env->keys.down = 0;
	else if (keycode == KEY_D)
		env->keys.right = 0;
	return (0);
}

int		key_press_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESCAPE)
		exit_hook(env);
	if (keycode == KEY_SPACEBAR)
		;//ft_attack(env);
	else if (keycode == KEY_W)
		env->keys.up = 1;
	else if (keycode == KEY_A)
		env->keys.left = 1;
	else if (keycode == KEY_S)
		env->keys.down = 1;
	else if (keycode == KEY_D)
		env->keys.right = 1;
	return (0);
}

void			ft_battleControl(t_env *env)
{
	if (env)
	{
		if (env->keys.targetFriendly)
			env->targetFriendly = 1;
		if (env->keys.up)
			env->target = 0;
		else if (env->keys.down)
			env->target = 1;
		else if (env->keys.left)
			env->target = 2;
		else if (env->keys.right)
			env->target = 3;
//		if (env->keys.leftNormal)
//			player_leftNormal(env);
//		else if (env->keys.leftSpecial)
//			player_leftSpecial(env);
//		else if (env->keys.rightNormal)
//			player_rightNormal(env);
//		else if (env->keys.rightSpecial)
//			player_rightSpecial(env);
	}
}

void			ft_dungeonControl(t_env *env)
{
	if (env)
	{

		if (env->keys.up)
			ft_moveUp(env);
		if (env->keys.down)
			ft_moveDown(env);
		if (env->keys.left == 1)
			ft_moveLeft(env);
		if (env->keys.right == 1)
			ft_moveRight(env);
		if (!env->chainTime && env->keys.startChain)
			;
//			ft_startChain(env);
	}
}

int		exit_hook(t_env *env)
{
	int i;

	i = -1;
	if (env)
	{
		if (env->mlx.mlx && env->mlx.win)
//			mlx_destroy_window(env->mlx.mlx, env->mlx.win);
//		mlx_destroy_image(env->mlx.mlx, env->mlx.frame.framePtr);
		ft_bzero(env, sizeof(t_env));
	}
	exit(0);
}