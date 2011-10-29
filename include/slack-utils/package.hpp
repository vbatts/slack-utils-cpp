
#ifndef SLACKWARE_PACKAGE_HPP
#define SLACKWARE_PACKAGE_HPP

#include <string>
#include <vector>

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

};


#endif // SLACKWARE_PACKAGE_HPP

