
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

	// TODO Even though the methods don't have a configurable root yet ...
	root_char = getenv("ROOT");
	if (root_char)
		root = string(root_char);
	if (vm.count("root"))
		root = vm["root"].as<string>();

	if (vm.count("list"))
	{
		System sys;
		if (vm.count("doinst"))
		{
			script_vec scripts;
			scripts = sys.get_installed_scripts();

			for (script_vec::iterator s = scripts.begin(); s != scripts.end() ; s++)
			{
				cout << s->pkg_name << endl;
			}

			cout << endl;

			cout << "Scripts: " << scripts.size() << endl;
		}
		else
		{
			package_vec packages;

			packages = sys.get_installed_packages();

			for (package_vec::iterator p = packages.begin(); p != packages.end() ; p++)
			{
				cout << p->pkg_name() << endl;
			}

			cout << endl;

			cout << "Packages: " << packages.size() << endl;
		}
		return 0;
	}

	cout << argv[0]
		<< ": need proper flags"
		<< endl
		<< "Try "
		<< argv[0]
		<< " --help for help"
		<< endl;

	return 0;
}


