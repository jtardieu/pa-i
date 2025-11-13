/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:57:08 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/12 17:45:26 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbword(char const *str, char c);
static void	freeall(char **str, int taille);
static int	newmot(char const *str, char c);

char	**ft_split(char const *s, char c)
{
	char	**envoie;
	int		icmpmotmot[3];

	icmpmotmot[1] = 0;
	icmpmotmot[0] = 0;
	if (!s)
		return (0);
	envoie = ft_calloc(nbword(s, c) + 1, sizeof(char *));
	if (!envoie)
		return (NULL);
	while (s[icmpmotmot[0]])
	{
		while (s[icmpmotmot[0]] && s[icmpmotmot[0]] == c)
			icmpmotmot[0]++;
		if (!s[icmpmotmot[0]])
			break ;
		icmpmotmot[2] = newmot(&s[icmpmotmot[0]], c);
		envoie[icmpmotmot[1]] = ft_substr(s, icmpmotmot[0], icmpmotmot[2]);
		if (!envoie[icmpmotmot[1]])
			return (freeall(envoie, icmpmotmot[1]), NULL);
		icmpmotmot[0] += icmpmotmot[2];
		icmpmotmot[1]++;
	}
	envoie[icmpmotmot[1]] = NULL;
	return (envoie);
}

static int	nbword(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c == '\0')
		return (1);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			j++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (j);
}

static void	freeall(char **str, int taille)
{
	int	i;

	i = 0;
	while (i != taille)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	newmot(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
