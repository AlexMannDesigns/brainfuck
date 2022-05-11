/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:18:14 by amann             #+#    #+#             */
/*   Updated: 2022/05/11 14:37:04 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	brackets(char c, char *input, int *i)
{
	int loop;

	loop = 0;
	if (c == '[')
		(*i)++;
	else
		(*i)--;
	while (input[*i] && *i >= 0)
	{
		if ((c == '[' && input[*i] == '[') || (c == ']' && input[*i] == ']'))
			loop++;
		else if ((c == '[' && input[*i] == ']' && loop > 0)	|| (c == ']' && input[*i] == '[' && loop > 0))
			loop--;
		else if ((c == '[' && input[*i] == ']' && loop == 0) || (c == ']' && input[*i] == '[' && loop == 0))
			return ;
		if (c == '[')
			(*i)++;
		else
			(*i)--;
	}
}

void	brainfuck_control(char *input)
{
	char	*output;
	char	c;
	int		i, cursor;

	output = create_string();
	i = cursor = 0;
	while (input[i])
	{
		c = input[i];
		if (c == '>')
		{
			output++;
			cursor++;
		}
		else if (c == '<')
		{
			output--;
			cursor--;
		}
		else if (c == '+')
			(*output)++;
		else if (c == '-')
			(*output)--;
		else if (c == '.')
			write(1, output, 1);
		else if ((c == '[' && !(*output)) || (c == ']' && *output))
			brackets(c, input, &i);
		i++;
	}
	free(output - cursor);
}
