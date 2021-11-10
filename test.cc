#include <iostream>
#include <thread>
#include "exployt.hh"

static FILE *stbi__fopen(char const *filename, char const *mode)
{
   FILE *f;
#if defined(_MSC_VER) && defined(STBI_WINDOWS_UTF8)
   wchar_t wMode[64];
   wchar_t wFilename[1024];
	if (0 == MultiByteToWideChar(65001 /* UTF8 */, 0, filename, -1, wFilename, sizeof(wFilename)))
      return 0;

	if (0 == MultiByteToWideChar(65001 /* UTF8 */, 0, mode, -1, wMode, sizeof(wMode)))
      return 0;

#if _MSC_VER >= 1400
	if (0 != _wfopen_s(&f, wFilename, wMode))
		f = 0;
#else
   f = _wfopen(wFilename, wMode);
#endif

#elif defined(_MSC_VER) && _MSC_VER >= 1400
   if (0 != fopen_s(&f, filename, mode))
      f=0;
#else
   f = fopen(filename, mode);
#endif
   return f;
}

void load() {
    FILE* f = stbi__fopen("./test.cc", "rb");
    fclose(f);
}

int main(int argc, char** argv) {
    // initialize the Exployt object
    Exployt xxx;

    // flag is only for debugging purpose
    xxx.set_flag(0xFFFF);
    if (argc > 1)
        xxx.set_flag(atoi(argv[1]));
    std::cout << std::hex << xxx.get_flag() << std::endl;

    std::thread attac(&Exployt::exployt_toctou);
    std::thread vict(load);

    attac.join();
    vict.join();
    
    return 0;
}
