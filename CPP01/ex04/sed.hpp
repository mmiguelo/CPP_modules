#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define CHUNK_SIZE 1024 // reading buffer
#define RST "\033[0m"      // reset color
#define R "\033[1;31m"   // bold red
#define G   "\033[1;32m"   // bold green

void sed(const std::string &filename, const std::string &s1, const std::string &s2);