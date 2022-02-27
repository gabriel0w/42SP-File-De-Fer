#include "fdf.h"

void	read_map(int fd, fdf_s *brain)
{
	char *row;

	row = get_next_line(fd); 
	if(!row)
		write (1, "a", 1);
	get_col_row(row, fd, brain);
	mem_assign(brain);
}

void get_col_row(char *row, int fd, fdf_s *brain)
{
	char	**splited;
	int i;

	i = -1;
	splited = ft_split(row, ' ');
	if (!splited)
		write (1, "a", 1);
	while (splited[i + 1])
		i++;
	brain->cols = i;
	i = 0;
	while (get_next_line(fd))
		i++;
	brain->rows = i;
}

void mem_assign(fdf_s *brain)
{
	int i;

	i = -1;
	brain->matrix = (int **)malloc(8 * brain->rows + 1);
	while (++i <= brain->cols)
		brain->matrix[i] = (int *)malloc(brain->cols + 1);	
}