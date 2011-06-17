#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

namespace Slackware {

#define PATH_INSTALLED_PACKAGES "/var/log/packages"
#define PATH_INSTALLED_SCRIPTS "/var/log/scripts"
#define PATH_REMOVED_PACKAGES "/var/log/removed_packages"
#define PATH_REMOVED_SCRIPTS "/var/log/removed_scripts/"

class Package
{
	
public:
	Package();
	Package(std::string this_name);

	std::string name;
	std::string root;

};

};

#endif
