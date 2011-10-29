
//#include <slackware.hpp>
#include <slack-utils/package.hpp>
#include <slack-utils/constants.hpp>

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include <boost/algorithm/string.hpp>

#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

#define DEBUG cout << __FILE__ << ":" << __LINE__ << ": " << __func__ << "(): "

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ios;

const char* PACKAGE_NAME_TOKEN = "-";

namespace Slackware {

/* http://www.boost.org/doc/libs/1_47_0/doc/html/string_algo/usage.html */
//typedef vector< iterator_range<string::iterator> > find_vector_type;
typedef vector< string > split_vector_type;

/// A base class to derive from
AbstractPackage::AbstractPackage()
{
	;;
}


/// The primary class to use for packages
Package::Package() :
	root(string("")),
	name(string()),
	version(string()),
	arch(string()),
	build(string()),
	tag(string()),
	tag_sep(string())
{
}

Package::Package(string this_name) :
	root(string("")),
	name(string()),
	version(string()),
	arch(string()),
	build(string()),
	tag(string()),
	tag_sep(string())
{
	parse_name(this_name);
}

Package::~Package()
{
	;;
}

string Package::pkg_name()
{
	return name + PACKAGE_NAME_TOKEN + version + PACKAGE_NAME_TOKEN + arch + PACKAGE_NAME_TOKEN + build;
}

vector< string > Package::get_owned_files()
{
	int length;
	char * buffer;
	ifstream f;
	vector< string > my_files;
	
	string path = root + PATH_INSTALLED_PACKAGES + pkg_name();

	f.open(path.c_str(), ios::binary);

	// TODO add a population for this list

	f.close();

	return my_files;
}

void Package::parse_name(string filename)
{
	split_vector_type splitVec;
	boost::split( splitVec,
			filename,
			boost::is_any_of(PACKAGE_NAME_TOKEN),
			boost::token_compress_on );

	// TODO split this up further, for tag
	// although that'll require a pattern search for alienBob's format
	build = splitVec.back();
	splitVec.pop_back();

	arch = splitVec.back();
	splitVec.pop_back();

	version = splitVec.back();
	splitVec.pop_back();

	name = "";
	while (splitVec.size() > 0)
	{
		if (name == "")
			name = splitVec.back();
		else
			name = splitVec.back() + PACKAGE_NAME_TOKEN + name;
		splitVec.pop_back();
	}
}

/// A subclass to handle the scripts, similarly as packages
Script::Script() :
	root(string("")),
	pkg_name(string())
{
}

Script::Script(string this_name) :
	root(string("")),
	pkg_name(this_name)
{
}

};
