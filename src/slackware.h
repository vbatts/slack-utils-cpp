#ifndef SLACKWARE_H
#define SLACKWARE_H


#include <string>
#include <vector>


#define PATH_INSTALLED_PACKAGES "/var/log/packages"
#define PATH_INSTALLED_SCRIPTS "/var/log/scripts"
#define PATH_REMOVED_PACKAGES "/var/log/removed_packages"
#define PATH_REMOVED_SCRIPTS "/var/log/removed_scripts/"

namespace Slackware
{

/**
 *
 * \class Slackware::AbstractPackage
 *
 * \brief Abstract handler for package information 
 *
 * \author Vincent Batts, vbatts@hashbangbash.com
 *
 * \date Fri Jun 17 20:33:03 EDT 2011
 *
 */
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

	//std::string pkg_name;
	std::string root;

	std::string name;
	std::string version;
	std::string arch;
	std::string build;
	std::string tag;
	std::string tag_sep;

	std::vector< std::string > get_owned_files();

	std::string pkg_name();
	void parse_name(std::string filename);
private:
	;;

};

class Script : virtual AbstractPackage
{
	
public:
	Script();
	Script(std::string this_name);

	//std::string pkg_name;
	std::string root;

	std::string pkg_name;
};

/// Slackware::System stuff
typedef std::vector<Package> package_vec;
typedef std::vector<Script> script_vec;
typedef std::vector<std::string> string_vec;

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

#endif

