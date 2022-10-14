/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:06:34 by tayou             #+#    #+#             */
/*   Updated: 2022/10/12 02:00:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}
/*
int main()
{
	char	str[] = "asdfa;ergaerg";
	char	c;

	ft_str_is_lowercase(str);
	c = ft_str_is_lowercase(str) +'0';
	write(1, &c, 1);

	return 0;
}
*/
