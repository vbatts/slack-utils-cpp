
#include <iostream>

#include "slackware.h"
#include "parse_args.hpp"

using std::cout;
using std::endl;
using namespace Slackware;

int main(int argc, char** argv)
{
	opts_map_t opts;
	if (parse_args(&opts, argc, argv) != 0)
		return 1;

	if (opts.count("list") > 0 and opts["list"] == "true")
	{
		package_vec packages;
		System sys;

		packages = sys.get_installed_packages();

		for (package_vec::iterator p = packages.begin(); p != packages.end() ; p++)
		{
			cout << p->pkg_name() << endl;
		/*
		cout << "< Package  name:\"" << p->name
			<< "\" version:\"" << p->version
			<< "\" arch:\"" << p->arch
			<< "\" build:\"" << p->build
			<< "\" >" << endl;
		*/
		}

		cout << endl;

		cout << "Packages: " << packages.size() << endl;
		return 0;
	}

	cout << "Please provide flags." << endl;

	return 0;
}


