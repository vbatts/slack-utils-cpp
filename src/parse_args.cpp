
#include "parse_args.hpp"

#include <iostream>
#include <string>
#include <vector>

#include <boost/program_options/parsers.hpp>
#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/environment_iterator.hpp>
#include <boost/program_options/eof_iterator.hpp>
#include <boost/program_options/errors.hpp>
#include <boost/program_options/option.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/version.hpp>

//using namespace std;
using std::string;
using std::cout;
using std::endl;
using std::vector;
namespace po = boost::program_options;

int parse_args(opts_map_t* opts, int argc, char** argv)
{
	po::options_description desc("Allowed Options");
	desc.add_options()
		("help,h", "Show this help")
		("list,l", "List the installed packages")
		("args", po::value< vector< string > >(), "the args filtered for")
		//(",l", po::value<int>(), "set compression level")
	;
	po::positional_options_description p;
	p.add("args", -1);

	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).
			options(desc).positional(p).run(),
			vm);
	po::notify(vm);

	if (vm.count("args"))
	{
		string tmp_s = "";
		vector<string>::iterator s_it;
		vector<string> s_args = vm["args"].as< vector<string> >();

		for (s_it = s_args.begin(); s_it < s_args.end(); s_it++)
		{
			if (tmp_s == "")
				tmp_s = string(*s_it);
			else
				tmp_s = string(*s_it) + " " + tmp_s;
		}

		(*opts)["args"] = string(tmp_s);
	} else {
		(*opts)["args"] = "";
	}

	if (vm.count("help")) {
		cout << desc << endl;
		return 1;
	}

	if (vm.count("list")) {
		(*opts)["list"] = "true";
	} else {
		(*opts)["list"] = "false";
	}

	return 0;
}

