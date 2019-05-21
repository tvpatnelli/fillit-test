#include "fillit.h"
#include "get_next_line.h"


static void		buftotab(char tetris[28][4][4], char buf[545], int buflen)
{
	int ct;
	int i;
	int j;

	ct = 0;
	while (buflen && *buf)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while(++j < 4)
			{
				if (*buf != '.')
					tetris[ct][i][j] = ct + 'A';
				else
					tetris[ct][i][j] = *buf;
				--buflen;
				buf++;
			}
			buf++;
			--buflen;
		}
		buf++;
		++ct;
	}
}

*int		terminos_valide(char **str)
{
	int i;
	int j;
	int c;
	int bloc;

	i = 0;
	c = 0;
	bloc = 0;
	while (*str)
	{
		if (i > 3)
			return (error);
		j = 0;
		while (str[i][j] != '\n')
		{
			if (str == NULL || str[i][j] != '.' || str[i][j] != '#' || j > 3)
				return (error);
			if (str[i][j] == '.' || str[i][j] == '#')
				c++;
			if (str[i][j] == '#')
				bloc++;
			j++;
		}
		i++;
	}
	if (c != 16 || bloc != 4)
		return (error);
	return (1);
}

int		bloc_valid(**str)
{
	int i;
	int j;

	i = 0;

	while(*str)
	{
		j = 0;
		while (str[i][j] != '#' && str[i][j] != '\n')
			j++;
		check_fusion_bloc(str[i][j]);

	}
}

int		check_fusion_bloc(**str, int i ,int j)
{
	int fus_Y;
	int fus_X;
	int y_H;
	int y_B;
	int x_G;
	int x_D;

	fus_Y = 0;
	fus_X = 0;
	y_H = str[i - 1][j];
	y_B = str[i + 1][j];
	x_G = str[i][j - 1];
	x_D = str[i][j + 1];
	while ( str[i]!= '\n')
	{
		while (str [j] != '\n')
		{
			if (y_H == '#')
				fus_Y++;
			if ( y_B == '#')
				fus_Y++;
			if (x_G == '#')
				fus_X++;
			if (x_D == '#')
				fus_X++;
			j++;
		}
		i++;
	}
	if( (fus_Y == 0 && fus_X == 6) || (fus_Y == 6 && fus_X == 0))
		return (1);
	if( (fus_Y - fus_X) == 0)
		return (1);
	return (error);
}

int test(char buf[544])
{
	return (0);
}
