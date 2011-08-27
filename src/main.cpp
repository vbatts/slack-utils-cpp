#include <iostream>

#include "slackware.h"

using namespace std;
using namespace Slackware;

int main()
{
	package_vec packages;
	System sys;

	packages = sys.get_installed_packages();

	for (package_vec::iterator p = packages.begin(); p != packages.end() ; p++)
	{
		cout << "Name: " << p->name << endl
			<< "  Version: " << p->version << endl
			<< "  Arch: " << p->arch << endl
			<< "  Build: " << p->build << endl
			<< endl;
	}

	cout << endl;

	cout << "Packages: " << packages.size() << endl;

	return 0;
}


