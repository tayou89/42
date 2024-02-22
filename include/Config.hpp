#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <string>
# include <map>
# include "Location.hpp"

typedef std::map<std::string, Location>::iterator		location_iterator;
typedef std::map<std::string, Location>::const_iterator	const_location_iterator;
typedef std::map<std::string, Location>					location_map;

class	Config : public Location
{
	public:
		typedef void(Config::*ConfigFunctionPTR) (void);
		typedef std::map<std::string, ConfigFunctionPTR>	config_function_map;
		typedef std::map<std::string, std::string>			location_block_map;

		Config(const std::string &serverBlock);
		virtual	~Config(void);
		Config(const Config &object);
		Config	&operator=(const Config &object);

		const std::string		&getServerName(void) const;
		const std::string		&getIPAddress(void) const;
		const int				&getPortNumber(void) const;
		const location_map		&getLocationMap(void) const;
		bool					isLocationExist(const std::string &path) const;
		//매치되는 Location을 반환하는 함수, 못 찾을시 자기 자신(config객체)를 반환
		const Location			&getLocation(const std::string &urlPath) const;

	private:
		Config(void);

		virtual string_set		_getDirectiveSet(void) const;
		virtual	void			_setFunctionPTRSet(void);
		virtual void			_setDirectiveData(void);
		void					_setListenData(void);
		void					_setServerName(void);
		void					_setLocationBlock(void);
		void					_setLocation(void);
		void					_checkConfigValidation(void) const;

		config_function_map		_configFunctions;
		std::string				_serverName;
		std::string				_ipAddress;
		int						_portNumber;
		location_block_map		_locationBlocks;
		location_map			_locations;
};

#endif