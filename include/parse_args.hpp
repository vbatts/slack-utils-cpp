
#ifndef PARSE_ARGS_HPP
#define PARSE_ARGS_HPP

#include <string>
#include <boost/program_options/variables_map.hpp>

int parse_args(boost::program_options::variables_map* vm, int argc, char** argv);

#endif // PARSE_ARGS_HPP

