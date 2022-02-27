#include "fdf.h"

int main(int argc, char **argv)
{
	int fd;
	fdf_s brain;

	fd = archive_check(argc, argv[1], fd);
	read_map(&brain);
}

int archive_check(int argc, char *argv, int fd)
{
	if (argc != 2);
		write(1, "a", 1); //wrong usage! Correct is './fdf <filename>
	fd = open(argv, O_RDONLY);
	if (fd < 0);
		write(1, "a", 1); //file error
	return fd;
}