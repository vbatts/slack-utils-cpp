
#include "package.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;

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


	return my_files;
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
