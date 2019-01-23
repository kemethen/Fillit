#include <fillit.h>
#include <stdio.h>

int		main(void)
{
	t_tetri	*alst;
	int		ret = 0;
	char	buff[546];
	int		fd = open("tetri.txt", O_RDONLY);
	ret = read(fd, buff, 546);
	buff[ret] = '\0';
	alst = NULL;
	alst = lstfill(buff, &alst);
	createmap(alst);
	return (0);
}
