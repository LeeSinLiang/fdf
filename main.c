#include <mlx.h>
#include <stdio.h>
typedef struct s_meta
{
	void *mlx;
	void *win;
	void *image;
	char *buffer;
	int pixel_bits;
	int line_bytes;
	int endian;
	int color;
} t_meta;



int	mouse_move(int button, int x, int y, void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	int color = 0xFFFFFF;

	// if (meta->pixel_bits != 32)
	// 	color = mlx_get_color_value(meta->mlx, color);
	printf("x: %d, y: %d, meta: %p\n", x, y, meta);
	for(int y = 0; y < 360; ++y)
	for(int x = 0; x < 640; ++x)
	{
		int pixel = (y * meta->line_bytes) + (x * 4);

		if (meta->endian == 1)        // Most significant (Alpha) byte first
		{
			meta->buffer[pixel + 0] = (color >> 24);
			meta->buffer[pixel + 1] = (color >> 16) & 0xFF;
			meta->buffer[pixel + 2] = (color >> 8) & 0xFF;
			meta->buffer[pixel + 3] = (color) & 0xFF;
		}
		else if (meta->endian == 0)   // Least significant (Blue) byte first
		{
			meta->buffer[pixel + 0] = (color) & 0xFF;
			meta->buffer[pixel + 1] = (color >> 8) & 0xFF;
			meta->buffer[pixel + 2] = (color >> 16) & 0xFF;
			meta->buffer[pixel + 3] = (color >> 24);
		}
	}
	mlx_put_image_to_window(meta->mlx, meta->win, meta->image, 0, 0);
}

int key_hook(int keycode, void *param)
{
	printf("keycode: %d\n", keycode);
}

int main()
{
	t_meta meta;

	meta.mlx = mlx_init();
	meta.win = mlx_new_window(meta.mlx, 640, 360, "Tutorial Window - Create Image");

	meta.image = mlx_new_image(meta.mlx, 640, 360);
	

	meta.buffer = mlx_get_data_addr(meta.image, &meta.pixel_bits, &meta.line_bytes, &meta.endian);
	printf("pixel_bits: %d\n", meta.pixel_bits);
	printf("line_bytes: %d\n", meta.line_bytes);
	printf("endian: %d\n", meta.endian);
	mlx_hook(meta.win, 4, 1L<<2, mouse_move, &meta);
	mlx_key_hook(meta.win, key_hook, &meta);
	// int color = 0xABCDEF;

	// // if (meta.pixel_bits != 32)
	// // 	color = mlx_get_color_value(meta.mlx, color);

	// for(int y = 0; y < 360; ++y)
	// for(int x = 0; x < 640; ++x)
	// {
	// 	int pixel = (y * meta.line_bytes) + (x * 4);

	// 	if (meta.endian == 1)        // Most significant (Alpha) byte first
	// 	{
	// 		meta.buffer[pixel + 0] = (color >> 24);
	// 		meta.buffer[pixel + 1] = (color >> 16) & 0xFF;
	// 		meta.buffer[pixel + 2] = (color >> 8) & 0xFF;
	// 		meta.buffer[pixel + 3] = (color) & 0xFF;
	// 	}
	// 	else if (meta.endian == 0)   // Least significant (Blue) byte first
	// 	{
	// 		meta.buffer[pixel + 0] = (color) & 0xFF;
	// 		meta.buffer[pixel + 1] = (color >> 8) & 0xFF;
	// 		meta.buffer[pixel + 2] = (color >> 16) & 0xFF;
	// 		meta.buffer[pixel + 3] = (color >> 24);
	// 	}
	// }
	mlx_put_image_to_window(meta.mlx, meta.win, meta.image, 0, 0);
	// mlx_string_put(meta.mlx, meta.win, 10, 10, 0xFFFFFF, "Hello World!");
	mlx_loop(meta.mlx);
}