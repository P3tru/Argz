//
// Created by Stephane Zsoldos on 11/14/21.
//

#include "Argz/Args.hh"

bool case_insensitive_compare(char a, char b) {
  return std::tolower(a) == std::tolower(b);
}

bool iequals(const std::string& a, const std::string& b) {
  if (a.length() != b.length()) {
	return false;
  }
  return std::equal(a.begin(), a.end(), b.begin(), case_insensitive_compare);
}

void Args::ProcessArgs(const int& argc, char *argv[]) {

  // Reading user input parameters
  if (argc < 2) {
	ShowUsage(argv[0]);
	exit(0);
  }

  for (int i = 1; i < argc; i++) {

	std::string arg = argv[i];
	if ((arg == "-h") || (arg == "--help")) {
	  ShowUsage(argv[0]);
	  exit(0);
	}

	if(std::none_of(v.begin(), v.end(),
				   [&arg, &argc, &argv, &i](BaseArg *ArgPtr){
					 return (*ArgPtr)(arg, argc, argv, i);
				   }))
	  std::cerr << "Unkown parameter: " << arg << std::endl;

  }

}
