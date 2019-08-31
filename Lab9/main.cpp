#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    int size = 15000;
    int size3D = 600;

    int * data2D = new int[size*size];
    int * data3D = new int[size3D*size3D*size3D];

    {
        //Optimized 2D
        std::chrono::time_point<std::chrono::system_clock> start, end, start2, end2;
        start = std::chrono::system_clock::now();

        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                data2D[y * size + x] += x;
            }
        }

        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Elapsed time (2D Optimized): " << elapsed_seconds.count() << "s\n";
    }

    {
        //Unoptimized 2D
        std::chrono::time_point<std::chrono::system_clock> start, end, start2, end2;
        start = std::chrono::system_clock::now();

        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                data2D[y * size + x] += x;
            }
        }

        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Elapsed time (2D Unoptimized): " << elapsed_seconds.count() << "s\n";
    }

    {
        //Optimized 3D
        std::chrono::time_point<std::chrono::system_clock> start, end, start2, end2;
        start = std::chrono::system_clock::now();

        for (int x = 0; x < size3D; x++) {
            for (int y = 0; y < size3D; y++) {
                for (int z = 0; z < size3D; z++) {
                    data3D[x*size3D*size3D + y*size3D + z] += x;
                }
            }
        }

        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Elapsed time (3D Optimized): " << elapsed_seconds.count() << "s\n";
    }

    {
        //Unoptimized 3D
        std::chrono::time_point<std::chrono::system_clock> start, end, start2, end2;
        start = std::chrono::system_clock::now();

        for (int z = 0; z < size3D; z++) {
            for (int y = 0; y < size3D; y++) {
                for (int x = 0; x < size3D; x++) {
                    data3D[x*size3D*size3D + y*size3D + z] += x;
                }
            }
        }

        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Elapsed time (3D Unoptimized): " << elapsed_seconds.count() << "s\n";
    }

    {
        //Unoptimized 3D
        std::chrono::time_point<std::chrono::system_clock> start, end, start2, end2;
        start = std::chrono::system_clock::now();

        for (int x = 0; x < size3D; x++) {
            for (int z = 0; z < size3D; z++) {
                for (int y = 0; y < size3D; y++) {
                    data3D[x*size3D*size3D + y*size3D + z] += x;
                }
            }
        }

        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Elapsed time (3D Unoptimized): " << elapsed_seconds.count() << "s\n";
    }



    delete[](data2D);
    delete[](data3D);
}