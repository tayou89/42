#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class	Harl
{
	public:
		Harl(void);
		void		setComplainLevel(std::string complainName);
		void		printFilteredComplain(void);

	private:
		void		printComplainTitle(int complainLevel);
		void		complain(int complainLevel);
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);

		int			complainLevel;
		std::string	complainName[4];
		void		(Harl::*functionPTR[4])(void);
};

#endif
