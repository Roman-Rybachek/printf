/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:02:59 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/26 19:40:26 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_align(t_fmt **fmt_flags, char *str)
{
	char	*spaces;
	int		value_spaces;

	value_spaces = (*fmt_flags)->width - ft_strlen(str);
	if (!(spaces = (char*)malloc(sizeof(char) * value_spaces + 1)))
		return (0);
	ft_memset(spaces, ' ', value_spaces);
	spaces[value_spaces] = '\0';
	if ((*fmt_flags)->align > 0)
	{
		spaces = ft_strjoin(str, spaces);
		ft_putstr_fd(spaces, 1);
	}
	else
	{
		spaces = ft_strjoin(spaces, str);
		ft_putstr_fd(spaces, 1);
	}
	value_spaces = ft_strlen(spaces);
	free(spaces);
	return (value_spaces);
}

int				ft_strtype(t_fmt **fmt_flags, va_list ap)
{
	char	*str;
	char	*base_str;
	int		len;

	str = va_arg(ap, char*);
	base_str = str;
	if (!str && (*fmt_flags)->accuracy_exist && (*fmt_flags)->accuracy < 6 \
											&& (*fmt_flags)->accuracy > 0)
		str = ft_strdup("(null)");
	if (!str)
		str = ft_strdup("(null)");
	if ((*fmt_flags)->accuracy_exist)
		str = ft_substr(str, 0, (*fmt_flags)->accuracy);
	if ((*fmt_flags)->width > (int)ft_strlen(str))
		return (ft_align(fmt_flags, str));
	else
		ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	if (str != base_str)
		free(str);
	return (len);
}
