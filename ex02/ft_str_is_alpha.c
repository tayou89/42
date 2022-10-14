/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:03:04 by tayou             #+#    #+#             */
/*   Updated: 2022/10/12 01:55:55 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}
/*
int	main()
{
	char	str[] = "5'aergaerb";
	int		number;

	ft_str_is_alpha(str);
	number = ft_str_is_alpha(str) + '0';

	write(1, &number, 1);

	return 0;
}
*/
