#ifndef SLACKWARE_TYPES_H
#define SLACKWARE_TYPES_H

#include <string>
#include <vector>

#include "system.h"
#include "package.h"

namespace Slackware
{

typedef std::vector<Slackware::Package> package_vec;
typedef std::vector<Slackware::Script> script_vec;
typedef std::vector<std::string> string_vec;

};

#endif
