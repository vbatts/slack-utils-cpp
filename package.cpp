
#include "package.h"

using namespace std;

namespace Slackware {

Package::Package()
{
	root = "";
	;;
}

Package::Package(string this_name)
{
	root = "";
	name = this_name;

	;;
}

};
