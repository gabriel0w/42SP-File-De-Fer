# define FDF_H

# include "mlx.h"
# include <math.h>
# include "../libs/gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct FdF
{
	void	*mlx;
	void	*win;
	int		cols;
	int		rows;
	int		**matrix;
}				fdf_s;

void	read_map();