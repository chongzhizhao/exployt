#include <iostream>
#include <cstdlib>

#include "filesystem.hpp"

int main(int argc, char** argv) {
    // Put a malicious value into an environmental variable
    // that temp_directory_path() will access with getenv().
    std::string bad_str = "TMPDIR=malicious";
    //std::string bad_str = "TMPDIR=" + std::string(10000000, 'x');
    char bad_path[bad_str.size() + 1];
    strcpy(bad_path, bad_str.c_str());
    putenv(bad_path);

    // Call temp_directory_path(), causing it to access the
    // malicious value with std::getenv().
    ghc::filesystem::path ret_path = ghc::filesystem::temp_directory_path();
    std::cout << ret_path << std::endl;

    return 0;
}
