/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:24:10 by tayou             #+#    #+#             */
/*   Updated: 2022/10/12 01:57:45 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/*
int	main()
{
	char	str[] = "1345135614560";
	char 	c;

	ft_str_is_numeric(str);
	
	c = ft_str_is_numeric(str) + '0';
	write(1, &c, 1);

	return 0;
}
*/
