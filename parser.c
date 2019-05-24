#include "fillit.h"

void		buftotab(char tetris[28][4][4], char buf[545], int buflen, int ct)
{
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

static int checkstruct(char tetri[4][4])
{
	int k;
	int i;
	int j;
	int fus;

	fus = 1;
	while (**tetri)
	{
		while (tetri[i++][j] != '\n' && fus <= 4)
		{
			k = j;
			while (tetri[i][k++] != '\n')
			{
				if (fus > 1)
				{
					while (k - 1 >=0 && tetri[i][k - 1] == '#')
					{
						fus++;
						tetri[i][k] = tetri[i][k - 1];
					}
				}
				while (k + 1 < 4 && tetri[i][k + 1] == '#' && fus < 4)
				{
					fus++;
					tetri[i][k] = tetri[i][k + 1];
				}
				while(k + 1 < 4 && tetri[i][k + 1] == '#')
				{
					fus++;
					tetri[i][k] = tetri [i][k + 1];
				}
				if (fus > 4)
					return (0);
			}
		}
	}
	return (1);
}


	static int checkfig(char tetri[4][4])
	{
		static int i;
		static int j;

		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
			{
				if(tetri[i][j] == '#')
					if (checkstruct(tetri[i][j]) != 4)
						return (0);
			}
		}
		return (1);
	}

	static int checknumb_blocks(char buff[544], int buflen)
	{
		int i;
		int j;
		int bloc;

		i = -1;
		bloc = 0;
		while (++i < 4 && buflen >= 0)
		{
			j = -1;
			while (++j < 4 && --buflen >= 0)
			{
				if (buff[i * 5 + j] == '#')
					bloc++;
			}
			if (buflen == 0)
				break;
		}
		if (bloc != 4)
			return (0);
		return (1);
	}


	static int checktetri(char buf[544], int buflen)
	{
		int i;
		int j;

		i = -1;
		while (++i < 4 && buflen >= 0)
		{
			j = -1;
			while (++j < 4 && --buflen >= 0)
			{
				if (buf[i * 5 + j] != '.' && buf[i * 5 + j] != '#')
					return (0);
			}
			if (buflen == 0)
				break;
			buflen--;
			if (buf[i * 5 + j] != '\n')
				return (0);
		}
		return (1);
	}


	int parser(char buf[544], int buflen)
	{
		int i;
		int len;
		char tetris[28][4][4];

		len = 0;
		i = 0;
		while (buflen - i > 0)
		{
			if (!checktetri(buf + i, 19))
				return (0);
			if(!checknumb_blocks(buf + i, 19))
				return (0);
			len += 1;
			i += 20;
			if (buflen - i <= 0)
				return (len);
			if (buf[i] != '\n')
				return (0);
			++i;
		}
		buftotab(tetris, buf, buflen, 0);
		return (len);
	}
