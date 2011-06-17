#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

namespace Slackware {

#define PATH_INSTALLED_PACKAGES "/var/log/packages"
#define PATH_INSTALLED_SCRIPTS "/var/log/scripts"
#define PATH_REMOVED_PACKAGES "/var/log/removed_packages"
#define PATH_REMOVED_SCRIPTS "/var/log/removed_scripts/"

class AbstractPackage
{
	
public:
	AbstractPackage();

};

class Package : virtual AbstractPackage
{
	
public:
	Package();
	Package(std::string this_name);

	std::string name;
	std::string root;

};

class Script : virtual AbstractPackage
{
	
public:
	Script();
	Script(std::string this_name);

	std::string name;
	std::string root;

};

};

#endif
