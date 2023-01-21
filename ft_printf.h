/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:43:52 by tayou             #+#    #+#             */
/*   Updated: 2023/01/21 17:51:01 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);

int		my_strlen(const char *str);

void	ft_print_character(char c, int *print_count);
void	ft_print_string(char *str, int *print_count);
void	ft_print_address(void *address, int *print_count);
void	ft_print_decimal(int n, int *print_count);
void	ft_print_unsigned(unsigned int number, int *print_count);
void	ft_print_hexa(char character, unsigned int number, int *print_count);
void	ft_print_percent(int *print_count);

#endif
