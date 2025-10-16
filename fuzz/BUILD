package(default_visibility = ["//visibility:public"])

load("@rules_fuzzing//fuzzing:cc_defs.bzl", "cc_fuzz_test")

cc_fuzz_test(
    name = "fuzz_calculator",
    srcs = ["fuzz_calculator.cc"],
    copts = ["-fprofile-instr-generate", "-fcoverage-mapping"],
    linkopts = ["-fprofile-instr-generate", "-fcoverage-mapping"],
    deps = [
        "//main:calculator_lib",
    ]
)
