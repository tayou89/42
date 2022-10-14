/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:11:42 by tayou             #+#    #+#             */
/*   Updated: 2022/10/12 12:44:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		if (str[i] < 'A' || str[i] > 'Z')
			return (0);
		i++;
	}
	return (1);
}
/*
int	main()
{
	char	c;
	char	str[] = "adfga;3ergaerg";

	ft_str_is_uppercase(str);
	c = ft_str_is_uppercase(str) + '0';
	write(1, &c, 1);

	return 0;
}
*/
