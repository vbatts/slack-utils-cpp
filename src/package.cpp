
#include "package.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;

const int PACKAGE_NAME_TOKEN = '-';

namespace Slackware {

/// A base class to derive from
AbstractPackage::AbstractPackage()
{
	;;
}


/// The primary class to use for packages
Package::Package()
{
	root = "";
}

Package::Package(string this_name)
{
	root = "";
	pkg_name = this_name;
}

Package::~Package()
{
	;;
}

file_vec Package::get_owned_files()
{
	int length;
	char * buffer;
	ifstream f;
	file_vec my_files;
	
	string path = root + PATH_INSTALLED_PACKAGES + pkg_name;

	f.open(path.c_str(), ios::binary);

	//TODO add a population for this list

	return my_files;
}

void Package::parse_name()
{
	/// since strchr is destructive
	string tmp_str = pkg_name;

	/// This will desconstruct the name, in reverse order

	// BUILD first
	info.build.assign(strchr(tmp_str.c_str(), PACKAGE_NAME_TOKEN)+1);

	info.arch.assign(strchr(tmp_str.c_str(), PACKAGE_NAME_TOKEN)+1);
	info.version.assign(strchr(tmp_str.c_str(), PACKAGE_NAME_TOKEN)+1);
	info.name.assign(strchr(tmp_str.c_str(), PACKAGE_NAME_TOKEN)+1);
	;;
}

/// A subclass to handle the scripts, similarly as packages
Script::Script()
{
	;;
}

Script::Script(string this_name)
{
	root = "";
	pkg_name = this_name;
}

};
