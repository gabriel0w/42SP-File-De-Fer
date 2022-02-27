#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int bresenham (int x1, int y1, int x2, int y2, t_data *img)
{
	int d;
	int dx;
	int dy;
	int E;
	int NE;

	dx = x2 - x1;
	dy = y2 - y1;
	d = 2 * dy - dx;
	E = 2 * dy;
	NE = 2 * (dy - dx);

	my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
	
	while(x1 < x2)
	{
		if (d <= 0)
		{
			d+=E;
			x1++;
		}
		else
		{
			d+=NE;
			x1++;
			y1++;
		}
		my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Da um liga na diagonales");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	bresenham(100, 100, 400, 400, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
