/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:59:14 by tayou             #+#    #+#             */
/*   Updated: 2022/10/14 21:32:25 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{	
			i++;
			continue ;
		}
		else
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}	
/*
int	main()
{
	char s1[] = "ab";
	char s2[] = "abcd";
	
	printf("%d\n", ft_strcmp(s1, s2));

	return (0);
}
*/
