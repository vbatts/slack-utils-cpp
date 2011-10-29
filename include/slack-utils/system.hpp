
#ifndef SLACKWARE_SYSTEM_HPP
#define SLACKWARE_SYSTEM_HPP

#include <slack-utils/package.hpp>
#include <string>

namespace Slackware
{

/**
 *
 * \class Slackware::System
 *
 * \brief Provides the access to fetch system info
 *
 * \author Vincent Batts, vbatts@hashbangbash.com
 *
 * \date Fri Jun 17 20:33:03 EDT 2011
 *
 */
class System
{

public:
	/// Constructor for Slackware::System
	System();

	/// returns a vector of the currently installed packages
	package_vec get_installed_packages();

	/// returns a vector of the removed/upgraded packages
	package_vec get_removed_packages();

	/// returns a vector of the scripts of currently installed packages
	script_vec get_installed_scripts();

	/// returns a vector of the scripts of removed/upgraded packages
	script_vec get_removed_scripts();

private:
	/// returns a vector of string, of the files in a given file path 
	string_vec get_files(std::string this_path);


};


};

#endif // SLACKWARE_SYSTEM_HPP

