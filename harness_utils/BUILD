load("@rules_cc//cc:cc_library.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "harness_utils",
    hdrs = ["fuzzing_utils/entire_file_utils.h", "harness_utils.h"],
)

cc_library(
    name = "fuzzing_utils",
    hdrs = ["fuzzing_utils/entire_file_utils.h", "fuzzing_utils/fuzzing_utils.h", "fuzzing_utils/fuzzed_data_provider.h"],
    srcs = ["fuzzing_utils/fuzzing_utils.cc"],
)
