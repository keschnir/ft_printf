/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format_setters.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 14:36:07 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 15:56:10 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_set_flags(char *c, t_format *f)
{
	int		i;

	if (c && f)
	{		
		i = 0;
		if (ft_strchr(c, '+'))
			f->flags[i] = '+';
		i++;
		if (ft_strchr(c, '-'))
			f->flags[i] = '-';
		i++;
		if (ft_strchr(c, '0'))
			f->flags[i] = '0';
		i++;
		if (ft_strchr(c, '#'))
			f->flags[i] = '#';
		i++;
		if (ft_strchr(c, ' '))
			f->flags[i] = ' ';
		while (*c == '+' || *c == '-' || *c == '0' || *c == '#' || *c == ' ')
			c++;
		if ((f->flags[2] == '0' && f->flags[1] == '-') || 
			(f->preci != -1 && (f->type == 'd' || f->type == 'i' ||	f->type == 'o' || f->type == 'u' || f->type == 'x' || f->type == 'X')))
			f->flags[2] = -1;
	}
	return (c);
}

char		*ft_set_width(char *c, t_format *f)
{
	if (ft_isdigit(*c))
	{
		f->width = ft_atoi(c);
		while(ft_isdigit(*c))
			c++;
	}
	return (c);
}

char		*ft_set_preci(char *c, t_format *f)
{
	if (c && *c == '.')
	{
		c++;
		if (ft_isdigit(*c) || *c == '+' || *c == '-')
		{
			f->preci = ft_atoi(c);
			if (*c == '+' || *c == '-')
				c++;
			while(ft_isdigit(*c))
				c++;
		}
	}
	else
		f->preci = -1;
	return (c);
}

char		*ft_set_size(char *c, t_format *f)
{
	if (*c == 'h' || *c == 'l' || *c == 'j' || *c == 'z')
	{
		if (!ft_strncmp(c, "hh", 2))
			f->size = HH;
		else if (!ft_strncmp(c, "h", 1))
			f->size = H;
		else if (!ft_strncmp(c, "ll", 2))
			f->size = LL;
		else if (!ft_strncmp(c, "l", 1))
			f->size = L;
		else if (!ft_strncmp(c, "j", 1))
			f->size = J;
		else if (!ft_strncmp(c, "z", 1))
			f->size = Z;
		while (*c == 'h' || *c == 'l' || *c == 'j' || *c == 'z')
			c++;
	}
	return (c);
}

char		*ft_set_type(char *c, t_format *f)
{
	if (*c == 's' || *c == 'S' || *c == 'p' || *c == 'd' || *c == 'D' ||
		*c == 'i' || *c == 'o' || *c == 'O' || *c == 'u' || *c == 'U' ||
		*c == 'x' || *c == 'X' || *c == 'c' || *c == 'C' || *c == '%')
	{
		f->type = *c;
		c++;
	}
	else
	 	f->type = 0;
	return (c);
}

void		ft_set_len(t_format *f)
{
	f->len = ft_strlen((char *)f->tostring);
}
