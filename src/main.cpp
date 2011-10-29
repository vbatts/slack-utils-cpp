
#include <iostream>

#include <slackware.hpp>

#include "parse_args.hpp"

using std::cout;
using std::endl;
using namespace Slackware;

int main(int argc, char** argv)
{
	boost::program_options::variables_map vm;
	if (parse_args(&vm, argc, argv) != 0)
		return 1;

	if (vm.count("list"))
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


