
#include "slackware.h"
#include <dirent.h>
#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/regex.hpp>

#define DEBUG cout << __FILE__ << ":" << __LINE__ << ": " << __func__ << "(): "

using namespace std;
namespace fs = boost::filesystem;
using namespace boost;

namespace Slackware
{

System::System()
{
	;;
}

package_vec System::get_installed_packages()
{
	package_vec vp;

	DEBUG << endl;
	string_vec files = get_files(PATH_INSTALLED_PACKAGES);
	DEBUG << endl;

	for (string_vec::iterator i = files.begin(); i != files.end(); i++)
	{
		vp.push_back(Package(*i)); /* BOOM */
	}
	DEBUG << endl;

	return vp;
}

package_vec System::get_removed_packages()
{
	package_vec vp;

	string_vec files = get_files(PATH_REMOVED_PACKAGES);

	for (string_vec::iterator i = files.begin(); i != files.end(); i++)
	{
		vp.push_back(Package(*i));
	}

	return vp;
}

script_vec System::get_installed_scripts()
{
	script_vec vp;

	string_vec files = get_files(PATH_INSTALLED_SCRIPTS);

	for (string_vec::iterator i = files.begin(); i != files.end(); i++)
	{
		vp.push_back(Script(*i));
	}

	return vp;
}

script_vec System::get_removed_scripts()
{
	script_vec vp;

	string_vec files = get_files(PATH_REMOVED_SCRIPTS);

	for (string_vec::iterator i = files.begin(); i != files.end(); i++)
	{
		vp.push_back(*i);
	}

	return vp;
}

string_vec System::get_files(string this_path)
{
	string_vec vs;
	fs::directory_iterator end_itr;

	DEBUG << endl;
	if (fs::exists(this_path))
	{
		fs::directory_iterator end_itr;
		for ( fs::directory_iterator dir_itr(this_path);
				dir_itr != end_itr;
				dir_itr++)
		{
			if ( fs::is_regular_file( dir_itr->status() ) )
			{
				vs.push_back( dir_itr->path().filename() );
			}
		}
	}
	DEBUG << endl;

	return vs;
}

};

