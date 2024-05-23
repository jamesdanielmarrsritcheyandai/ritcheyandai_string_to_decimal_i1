#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
    po::options_description desc("Allowed options");
    desc.add_options()
        ("string", po::value<std::string>(), "input string to convert")
        ("delimiter", po::value<std::string>()->default_value(" "), "delimiter to use between numbers");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("string")) {
        std::string input = vm["string"].as<std::string>();
        std::string delimiter = vm["delimiter"].as<std::string>();
        for (size_t i = 0; i < input.size(); ++i) {
            std::cout << static_cast<int>(input[i]);
            if (i != input.size() - 1) {
                std::cout << delimiter;
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "No input string was given." << std::endl;
    }

    return 0;
}