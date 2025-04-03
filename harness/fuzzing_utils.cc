#include <vector>
#include "fuzzing_utils.h"

// Global variables
fuzzed_data_provider* global_provider = nullptr;
std::vector<FuzzTestFunc> fuzz_tests;

void RegisterFuzzTest(FuzzTestFunc func) {
    fuzz_tests.push_back(func);
}

void RunFuzzTests(const char* file_path) {
    EntireFile file = read_entire_file_into_memory(file_path);
    if (!file.contents) {
        fprintf(stderr, "Failed to open input file: %s\n", file_path);
        return;
    }
	if (file.len < 2) {
        fprintf(stderr, "File is too small\n");
	    return;
    }

    const unsigned char* data = reinterpret_cast<const unsigned char*>(file.contents);
    size_t len = file.len;

    // Create and set up FDP instance
    fuzzed_data_provider provider(data, len);
    global_provider = &provider;  // Make the provider available to all tests without reinitializing it on every pass

    // Run all registered fuzz tests using the same provider
    for (auto& fuzz_test : fuzz_tests) {
        fuzz_test();
    }

    global_provider = nullptr;  // Reset provider; this whole function should only run once anyways
}
