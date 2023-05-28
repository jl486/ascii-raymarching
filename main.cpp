#include <iostream>
#include <cmath>
#include <unistd.h>
#include <chrono>
#include <vector3.h>

// move these vars later
const int buffer_width = 80;
const int buffer_height = 40;

const int nlum_chars = 10;
const char* lum_chars = " .:-=+*#%@";
char frame_buffer[buffer_width * buffer_height];

Vector3 center = { 0.0f, 0.0f, 0.0f };
float radius = 0.4f;

float t = 0.0f;

// MOVE TIME FUNCTIONS TO A Time CLASS ONCE READY TO ENDURE TORTURE OF CHANGING CMakeLists.txt
auto start = std::chrono::high_resolution_clock::now();

void reset() {
    start = std::chrono::high_resolution_clock::now();
}

float elapsed() {
   return std::chrono::duration_cast<std::chrono::milliseconds>(
       std::chrono::high_resolution_clock::now() - start
   ).count();
}

float sdf(Vector3 pos, Vector3 center, float radius) {
	return (pos - center).length() - radius;
}

char shade(Vector3 pos) {
    // temporary
    return lum_chars[nlum_chars - 1];
}

void raymarch(Vector3 ray_origin) {
    float steps = 500.0f;
    float min_hit_distance = 1e-5;
    float max_trace_distance = 10000.0f;

    char pixel = lum_chars[0];

    for (int x = 0; x < buffer_width; x++) {
        for (int y = 0; y < buffer_height; y++) {
            Vector3 current_position = ray_origin;
            Vector3 target = {
                x / (float)(buffer_width) - 0.5f,
                y / (float)(buffer_height) - 0.5f,
                -1.5f
            };

            Vector3 ray = target - current_position;
            ray.normalize();

            float distance_to_closest = 0.0f;
            char pixel = lum_chars[0];

            for (int i = 0; i < steps; i++) {
                distance_to_closest = sdf(current_position, center, radius);

                if (abs(current_position.x) > max_trace_distance ||
                    abs(current_position.y) > max_trace_distance ||
                    abs(current_position.z) > max_trace_distance)
                    break;

                if (distance_to_closest < min_hit_distance) {
                    pixel = shade(current_position);
                    break;
                }

                // negate multiplication because of left-handed coords
                current_position = current_position + -ray * distance_to_closest;
            }

            frame_buffer[x + y * buffer_width] = pixel;
        }
    }
}

void display() {
    std::cout << "\x1b[H";
    for (int i = 0; i < buffer_width * buffer_height; i++) {
        putchar(i % buffer_width ? frame_buffer[i] : 10);
    }
}

int main() {
    memset(frame_buffer, ' ', buffer_width * buffer_height);

    Vector3 eye = { 0.0f, 0.0f, -1.0f };

    // reseting timer
    reset();

    while (true) {
        t = elapsed() / 1000;

        raymarch(eye);
        display();
    }

    return 0;
}
