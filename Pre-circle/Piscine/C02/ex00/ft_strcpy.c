/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:07:49 by tayou             #+#    #+#             */
/*   Updated: 2022/10/13 20:00:44 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main()
{
	char	dest[8];
	char	src[] = "abcedfg";
	int		i;

	ft_strcpy(dest, src);
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	write(1, src, i);
	write(1, "\n", 1);
	write(1, dest, i);

	return 0;
}
*/
