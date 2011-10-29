
#include <iostream>
#include <string>
#include <cstdlib>

#include <slackware.hpp>

#include "parse_args.hpp"

using std::cout;
using std::endl;
using std::string;
using namespace Slackware;

int main(int argc, char** argv)
{
	boost::program_options::variables_map vm;
	string root = PATH_ROOT;
	char* root_char;

	if (parse_args(&vm, argc, argv) != 0)
		return 1;

	root_char = getenv("ROOT");
	if (root_char)
		root = string(root_char);
	if (vm.count("root"))
		root = vm["root"].as<string>();

	if (vm.count("list"))
	{
		package_vec packages;
		System sys;

		packages = sys.get_installed_packages();

		for (package_vec::iterator p = packages.begin(); p != packages.end() ; p++)
		{
			cout << p->pkg_name() << endl;
		}

		cout << endl;

		cout << "Packages: " << packages.size() << endl;
		return 0;
	}

	cout << "Please provide flags." << endl;

	return 0;
}


