
#include "system.h"
#include <dirent.h>

using namespace std;

namespace Slackware
{

System::System()
{
	;;
}

package_vec System::get_installed_packages()
{
	package_vec vp;

	string_vec files = get_files(PATH_INSTALLED_PACKAGES);

	for (string_vec::iterator i = files.begin(); i != files.end(); i++)
	{
		vp.push_back(*i);
	}

	return vp;
}

string_vec System::get_files(string this_path)
{
	string_vec vs;

	DIR *dp;
	struct dirent *dirp;

	if ((dp = opendir(this_path.c_str())) == NULL)
	{
		throw("F");
	}

	while ((dirp = readdir(dp)) != NULL)
	{
		vs.push_back(string(dirp->d_name));
	}

	return vs;
}

};

