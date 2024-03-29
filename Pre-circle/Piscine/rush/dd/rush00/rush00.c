void ft_putchar(char c);

void	rush(X, Y)
{
	int	x_index;
	int y_index;
	if(X <= 0 || Y <= 0)
		return ;
	y_index = 1;
	while (y_index <= Y)
	{
		x_index = 1;
		while (x_index <= X)
		{
			if ((x_index == 1 || x_index == X) && (y_index == 1 || y_index == Y))
				ft_putchar('o');
			else if ((x_index > 1 && x_index < X) && (y_index == 1 || y_index == Y))
				ft_putchar('-');
			else if (x_index > 1 && x_index < X && y_index > 1 && y_index < Y)
				ft_putchar(' ');
			else
				ft_putchar('|');
			x_index++;
		}
		ft_putchar('\n');
		y_index++;
	}
}
