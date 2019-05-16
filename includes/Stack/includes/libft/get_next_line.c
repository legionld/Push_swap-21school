/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:11:16 by jschille          #+#    #+#             */
/*   Updated: 2018/12/27 23:28:27 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	**matrixadd(char **mtrx, int i)
{
	char	**tmp;
	int		n;

	n = 0;
	if (!(tmp = (char **)malloc(sizeof(char*) * i)))
		return (NULL);
	while (mtrx != NULL && mtrx[n] != NULL)
	{
		tmp[n] = ft_strdup(mtrx[n]);
		free(mtrx[n]);
		++n;
	}
	return (tmp);
}

static int	search_fd(int fd, char ***afd)
{
	char	*chfd;
	int		i;

	i = 0;
	chfd = ft_itoa(fd);
	while (*afd != NULL && (*afd)[i] != NULL)
	{
		if (i % 2 == 0)
		{
			if (ft_strcmp((*afd)[i], chfd) == 0)
				return (i);
		}
		++i;
	}
	*afd = matrixadd(*afd, i + 3);
	(*afd)[i] = ft_strdup(chfd);
	(*afd)[i + 1] = ft_strdup("\0");
	(*afd)[i + 2] = NULL;
	free(chfd);
	return (i);
}

static int	ft_strjoin_p(char **des, char *src, char **line, int f)
{
	char	*tmp;

	if (f == 1)
	{
		tmp = ft_strchr(src, '\n');
		ft_strjoin_p(des, tmp + 1, NULL, 0);
		tmp = ft_strsub(src, 0, (tmp - src));
		ft_strjoin_p(line, tmp, NULL, 0);
		free(src);
		return (1);
	}
	tmp = *des;
	*des = ft_strjoin(tmp, src);
	free(tmp);
	return (0);
}

static int	ft_get_line(char **line, char **afd)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*afd)[i] != '\n' && (*afd)[i] != '\0')
		++i;
	if ((*afd)[i] == '\n')
	{
		tmp = *line;
		*line = ft_strsub(*afd, 0, i);
		free(tmp);
		tmp = *afd;
		*afd = ft_strdup(tmp + i + 1);
		free(tmp);
		return (1);
	}
	ft_strjoin_p(line, *afd, NULL, 0);
	free(*afd);
	*afd = ft_strnew(1);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	**afd;
	char		*buff;
	char		*tmp;
	int			i;
	int			r;

	ERR_OUT(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1)));
	if (line == NULL || fd < 0 || !(*line = ft_strnew(1)) || \
	read(fd, buff, 0) < 0 || (i = search_fd(fd, &afd)) == -1)
		return (-1);
	NEXT(ft_get_line(line, &afd[i + 1]));
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if ((tmp = ft_strchr(buff, '\n')) != NULL)
			return (ft_strjoin_p(&afd[i + 1], buff, line, 1));
		else
			ft_strjoin_p(line, buff, NULL, 0);
	}
	free(buff);
	free(afd[i + 1]);
	afd[i + 1] = ft_strnew(1);
	CHECK;
	return (0);
}
