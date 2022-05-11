/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:29:14 by amann             #+#    #+#             */
/*   Updated: 2022/05/11 14:21:04 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINFUCK_H
#define BRAINFUCK_H

#include <unistd.h>
#include <stdlib.h>

void	brainfuck_control(char *str);
char	*create_string(void);

#endif
