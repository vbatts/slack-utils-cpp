#include <iostream>

#include "package.h"
#include "system.h"
#include "types.h"

using namespace std;
using namespace Slackware;

int main()
{
	package_vec packages;
	script_vec scripts;
	System sys;

	packages = sys.get_installed_packages();
	scripts = sys.get_installed_scripts();

	for (package_vec::iterator p = packages.begin(); p != packages.end() ; p++)
	{
		cout << p->name << endl;
	}

	cout << endl;

	cout << "Packages: " << packages.size() << endl;
	cout << "Scripts: " << scripts.size() << endl;

	return 0;
}


