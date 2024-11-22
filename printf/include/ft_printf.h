/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:37:40 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/22 14:27:32 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIB_H
# define PRINTF_LIB_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *s, ...);

void	ft_putstr(char *str);
int		ft_putnbr_base(unsigned long nbr, char	*base);
char	*ft_utoa(unsigned int n);

int		ft_char(va_list args);
int		ft_hex(va_list args, char *case_type);
int		ft_int(va_list args);
int		ft_pointer(va_list args);
int		ft_string(va_list args);
int		ft_unsigned_int(va_list args);

#endif
