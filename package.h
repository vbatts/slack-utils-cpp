#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <vector>

namespace Slackware {

#define PATH_INSTALLED_PACKAGES "/var/log/packages"
#define PATH_INSTALLED_SCRIPTS "/var/log/scripts"
#define PATH_REMOVED_PACKAGES "/var/log/removed_packages"
#define PATH_REMOVED_SCRIPTS "/var/log/removed_scripts/"

typedef std::vector<std::string> file_vec;
typedef struct {
	std::string name;
	std::string version;
	std::string arch;
	std::string build;
	std::string tag;
	std::string tag_sep;
} pkg_info_t;


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
	~Package();

	std::string pkg_name;
	std::string root;

	file_vec get_owned_files();

};

class Script : virtual AbstractPackage
{
	
public:
	Script();
	Script(std::string this_name);

	std::string pkg_name;
	std::string root;

};

};

#endif
