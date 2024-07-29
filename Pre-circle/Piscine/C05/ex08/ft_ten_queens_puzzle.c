/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:23:02 by tayou             #+#    #+#             */
/*   Updated: 2022/10/18 16:51:37 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(char board[10][10])
{
	int		x;
	int		y;
	char	result[10];

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (board[y][x] == 1)
				result[y] = x + '0';
			x++;
		}
		y++;
	}
	write(1, result, 10);
	write(1, "\n", 1);
}

int	check_queen(char board[10][10], int x, int y)
{
	int	copy_y;
	int	copy_x;

	copy_y = y;
	copy_x = x;
	while (copy_y-- > 0 && copy_x-- > 0)
		if (board[copy_y][copy_x] == 1)
			return (0);
	copy_y = y;
	copy_x = x;
	while (copy_y-- > 0)
		if (board[copy_y][copy_x] == 1)
			return (0);
	copy_y = y;
	copy_x = x;
	while (copy_y-- > 0 && copy_x++ < 9)
		if (board[copy_y][copy_x] == 1)
			return (0);
	return (1);
}

void	recursive(char board[10][10], int x, int y, int *count)
{
	if (check_queen(board, x, y) == 1)
	{
		board[y][x] = 1;
		if (y == 9)
		{
			print_board(board);
			(*count)++;
		}
		else
			recursive(board, 0, y + 1, count);
	}
	board[y][x] = 0;
	if (x != 9)
		recursive(board, x + 1, y, count);
	else
		return ;
}

void	initialize_board(char board[10][10])
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			board[y][x] = '0';
			x++;
		}
		y++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10][10];
	int		x;
	int		y;
	int		count;

	initialize_board(board);
	count = 0;
	x = 0;
	y = 0;
	recursive(board, x, y, &count);
	return (count);
}
/*
#include <stdio.h>

int	main()
{
	ft_ten_queens_puzzle();
	printf("%d\n", ft_ten_queens_puzzle());
	return (0);
}
*/
