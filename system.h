#ifndef SYSTEM_H
#define SYSTEM_H

#include "types.h"

namespace Slackware
{

class System
{

public:
	System();

	package_vec get_installed_packages();
	package_vec get_removed_packages();
	script_vec get_installed_scripts();
	script_vec get_removed_scripts();

private:
	string_vec get_files(std::string this_path);


};

};

#endif
