/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:02:25 by tayou             #+#    #+#             */
/*   Updated: 2022/10/12 02:03:31 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
/*
int	main()
{
	char	str[] = "jab9'1aop-ojg";
	int		i;

    i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	write(1, str, i);
	write(1, "\n", 2);
	write(1, ft_strupcase(str), i);

	return 0;
}
*/
