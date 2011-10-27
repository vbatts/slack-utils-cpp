
#ifndef PARSE_ARGS_HPP
#define PARSE_ARGS_HPP

#include <vector>
#include <map>
#include <string>

typedef std::map<std::string, std::string> opts_map_t;
int parse_args(opts_map_t* opts, int argc, char** argv);

#endif // PARSE_ARGS_HPP

