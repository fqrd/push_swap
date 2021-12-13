/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:00:07 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/13 11:57:06 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

t_list	*new_status(t_list *s)
{
	s = malloc(sizeof(t_list) * 1);
	if (!s)
		return (NULL);
	s->buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!s->buffer)
		return (NULL);
	s->buffer[BUFFER_SIZE] = '\0';
	s->rest = NULL;
	s->line = NULL;
	s->start = 0;
	s->end = 0;
	s->populated = 0;
	return (s);
}

int	find_char(t_list **s, char c)
{
	while ((*s)->buffer[(*s)->end])
	{
		if ((*s)->buffer[(*s)->end] == c)
			return (1);
		(*s)->end++;
	}
	return (0);
}

char	*substrjoin(t_list **s, size_t start, size_t len, size_t restlen)
{
	char	*output;
	size_t	i;

	i = 0;
	output = malloc(sizeof(char) * (restlen + len + 1));
	if (!output)
		return (NULL);
	while (i < restlen)
	{
		if ((*s)->rest && (*s)->rest[i])
			output[i] = (*s)->rest[i];
		i++;
	}
	while (len > i - restlen)
	{
		if ((*s)->buffer && (*s)->buffer[start])
			output[i] = (*s)->buffer[start++];
		i++;
	}
	output[i] = '\0';
	if ((*s)->rest)
		free((*s)->rest);
	(*s)->rest = NULL;
	return (output);
}

char	*set_value(t_list **s, int res)
{
	if (res == 1)
		return ((*s)->line);
	else
		return (mfree(&*s, NULL));
}
