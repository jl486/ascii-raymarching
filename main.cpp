#include <iostream>
#include <fstream>
#include <cmath>
#include <unistd.h>
#include <vector3.h>

// move these vars later
const int buffer_width = 80;
const int buffer_height = 40;

const int nlum_chars = 13;
const char* lum_chars = " .,-~:;=!*#$@";
char frame_buffer[buffer_width * buffer_height];

int main()
{
    std::cout << "Hello world";

    return 0;
}
