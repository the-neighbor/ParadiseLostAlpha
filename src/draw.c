#include "../inc/p-lost.h"
void drawHorizontal(t_env *env, int x1, int x2, int y)
{
	int x;
	t_pix color;

	x = x1;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.alpha = 0;
	if (env)
	{
		while (x < x2)
		{
			ft_mlx_ppp(env, x, y, color);
			++x;
		}
	}
}

void drawVertical(t_env *env, int y1, int y2, int x)
{
	int y;
	t_pix color;

	y = y1;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.alpha = 0;
	if (env)
	{
		while (y < y2)
		{
			ft_mlx_ppp(env, x, y, color);
			++y;
		}
	}
}

void	drawGrid(t_env *env)
{
	int	origin;
	int counter;

	counter = 0;
	origin = env->gridSize / 2;
	while (counter < 33)
	{
		drawHorizontal(env, origin, (origin + env->gridSize * 32), (origin + env->gridSize * counter));
		drawVertical(env, origin, (origin + env->gridSize * 32), (origin + env->gridSize * counter));
		++counter;
		printf("counter is %d\n", counter);
	}
}
