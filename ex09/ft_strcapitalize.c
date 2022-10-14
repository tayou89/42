/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:00:48 by tayou             #+#    #+#             */
/*   Updated: 2022/10/13 16:11:34 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			if ((str[i - 1] < '0') || ((str[i - 1] > '9') && (str[i - 1] < 'A'))
				|| ((str[i - 1] > 'Z') && (str[i - 1] < 'a'))
				|| (str[i - 1] > 'z'))
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
/*
int	main()
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	write(1, str, i);
	write(1, "\n", 2);
	write(1, ft_strcapitalize(str), i);
	return 0;
}
*/
