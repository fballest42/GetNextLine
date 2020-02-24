/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineBB.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:07:09 by fballest          #+#    #+#             */
/*   Updated: 2019/12/12 10:34:50 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>

static char		*ft_substr(char const *s, unsigned int start, size_t len);
static void		ft_putstr_fd(char *s, int fd);
static size_t	ft_strlen(const char *str);
static char		*ft_strdup(const char *s1);
static char		*ft_strjoin(char const *s1, char const *s2);

static char		*ft_strdup(const char *s1)
{
	size_t		ln;
	size_t		i;
	char		*str;

	ln = 0;
	i = 0;
	while (s1[ln] != '\0')
		ln++;
	str = (char*)malloc(ln + 1);
	if (str == '\0')
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*dst;
	size_t		i;
	size_t		j;

	j = 0;
	if (s1 == '\0' || s2 == '\0')
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(dst = (char *)malloc(sizeof(char) * i)))
		return (0);
	while (s1[j] != '\0')
	{
		dst[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		dst[j] = s2[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}

static void		ft_putstr_fd(char *s, int fd)
{
	if (!(s == '\0'))
		write(fd, s, ft_strlen(s));
}

static char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*dst;
	size_t			size;

	i = 0;
	if (s == '\0')
		return (0);
	i = ft_strlen(s);
	if (i < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static size_t	ft_strlen(const char *str)
{
	size_t		a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

int				get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*aux[4096];
	char			*tmp;
	int				cnt;

	if (!(line) || !(fd) || BUFFER_SIZE < 1)
		return(-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return(-1);
	while (cnt = read(fd, buff, BUFFER_SIZE) > 0)
	{
		buff[cnt] = '\0';
		if (aux[fd] == NULL)
			aux[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(aux[fd], buff);
			free(aux[fd]);
			aux[fd] = tmp;
		}

	}

int		main()
{
	int		fd;
	char	*line1;

	fd = open("prueba.txt", O_RDONLY);
	get_next_line(fd, &line1);
	printf("%s", line1);
}
