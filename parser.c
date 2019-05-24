#include "fillit.h"

int checktetri(char buf[544], int buflen)
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

int checkfig(char tetri[4][4])
{
int i;
int j;

i = -1;
while (++i < 4)
{
   while (++j < 4)
   {
      j = -1;
      if (tetri[i][j] == '#')
         if (checkstruct() != 4)
            return (0);
   }
}
return (1);

}

int parser(char buf[544], int buflen)
{
	int i;
	int len;

	len = 0;
	i = -1;

   if (!(len = checksym())
      return (0);
   while (++i < len)
      if (!checkfig(buf[i]))
         return(0);
   
   /*
	while (buflen - i > 0)
	{
		if (!checktetri(buf + i, 19))
			return (0);
		len += 1;
		i += 20;
		if (buflen - i <= 0)
			return (len);
		if (buf[i] != '\n')
			return (0);
		++i;
	}*/
	return (len);
}
