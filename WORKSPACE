load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "googletest",
    sha256 = "65fab701d9829d38cb77c14acdc431d2108bfdbf8979e40eb8ae567edf10b27c",
    strip_prefix = "googletest-1.17.0",
    urls = ["https://github.com/google/googletest/releases/download/v1.17.0/googletest-1.17.0.tar.gz"],
)

http_archive(
    name = "rules_oci",
    sha256 = "b8db7ab889d501db33313620b2c8040dbb07e95c26a0fefe06004b35baf80e08",
    strip_prefix = "rules_oci-2.2.7",
    url = "https://github.com/bazel-contrib/rules_oci/releases/download/v2.2.7/rules_oci-v2.2.7.tar.gz",
)

load("@rules_oci//oci:dependencies.bzl", "rules_oci_dependencies")

rules_oci_dependencies()

load("@rules_oci//oci:repositories.bzl", "oci_register_toolchains")

oci_register_toolchains(name = "oci")

http_archive(
    name = "rules_pkg",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_pkg/releases/download/1.2.0/rules_pkg-1.2.0.tar.gz",
        "https://github.com/bazelbuild/rules_pkg/releases/download/1.2.0/rules_pkg-1.2.0.tar.gz",
    ],
    sha256 = "b5c9184a23bb0bcff241981fd9d9e2a97638a1374c9953bb1808836ce711f990",
)
load("@rules_pkg//:deps.bzl", "rules_pkg_dependencies")
rules_pkg_dependencies()

http_archive(
    name = "rules_mayhem",
    strip_prefix = "rules_mayhem",
    urls = ["https://github.com/ForAllSecure/rules_mayhem/releases/download/0.8.4/rules_mayhem-0.8.4.tar.gz"],
    sha256 = "9e1f9d92e4830e978757fcab6587ece0727fe0331d519d177161261255e085ad",
)

load("@rules_mayhem//mayhem:repositories.bzl", "rules_mayhem_repositories")
rules_mayhem_repositories()

load("@rules_oci//oci:pull.bzl", "oci_pull")

oci_pull(
    name = "ubuntu",
    tag = "latest",
    image = "index.docker.io/library/ubuntu",
    platforms = [
        "linux/amd64",
    ],
)