
#include "package.h"

using namespace std;

namespace Slackware {

AbstractPackage::AbstractPackage()
{
	;;
}

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

Script::Script()
{
	;;
}

Script::Script(string this_name)
{
	root = "";
	name = this_name;

	;;
}

};
