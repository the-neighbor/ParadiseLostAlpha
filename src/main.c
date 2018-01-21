#include "../inc/p-lost.h"

void	prepare(t_env *env)
{
	env->gridSize = 15;
	env->resX = 1024;
	env->resY = 1024;
	env->mlx.mlx = mlx_init();
	env->mlx.win = mlx_new_window(env->mlx.mlx, env->resX, env->resY, "PARADISE LOST! Alpha");
	env->mlx.frame.framePtr = mlx_new_image(env->mlx.mlx, env->resX, env->resY);
	env->mlx.frame.frameData = (unsigned int *)mlx_get_data_addr(env->mlx.frame.framePtr, &(env->mlx.bppx), &(env->mlx.bpln), &(env->mlx.endi));	
}

int main()
{
	t_env env;

	ft_bzero(&env, sizeof(env));
	prepare(&env);
	while(1)
	{
		drawGrid(&env);
		mlx_put_image_to_window(env.mlx.mlx, env.mlx.win, env.mlx.frame.framePtr, 0, 0);
		ft_framebuffer_forget(&env);
	}
}
