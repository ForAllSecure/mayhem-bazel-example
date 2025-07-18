FROM ubuntu AS builder

# Install required packages
RUN apt update -y && DEBIAN_FRONTEND=noninteractive apt install -y curl git unzip clang jq

# Get Python 3.9 - required for Bazel
RUN DEBIAN_FRONTEND=noninteractive apt install -y software-properties-common && \
    add-apt-repository -y ppa:deadsnakes/ppa && \
    apt update -y && \
    DEBIAN_FRONTEND=noninteractive apt install -y python3.9 python3.9-venv python3.9-dev && \
    update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.9 1 && \
    update-alternatives --install /usr/bin/python python /usr/bin/python3.9 1 && \
    update-alternatives --set python3 /usr/bin/python3.9 && \
    update-alternatives --set python /usr/bin/python3.9

RUN LATEST_URL=$(curl -s https://api.github.com/repos/bazelbuild/bazelisk/releases/latest | jq -r '.assets[] | select(.name | test("bazelisk-linux-amd64")) | .browser_download_url') && \
    curl -Lo /usr/local/bin/bazelisk ${LATEST_URL} && \
    chmod +x /usr/local/bin/bazelisk && \
    ln -s /usr/local/bin/bazelisk /usr/local/bin/bazel

RUN useradd -m -d /workspace -s /bin/bash runner
USER runner

WORKDIR /workspace
ADD . .

RUN mkdir out

# Make extra sure we are using Python 3.9
ENV PYTHON_BIN_PATH=/usr/bin/python3.9

#Build libFuzzer target
RUN bazel build --repo_contents_cache= --config=asan-libfuzzer //fuzz:fuzz_calculator_run
RUN cp ./bazel-bin/fuzz/fuzz_calculator_bin ./out/fuzz_calculator_libfuzzer

#Build uninst target
RUN bazel clean --repo_contents_cache=
RUN bazel build --repo_contents_cache= --config=uninstrumented //fuzz:fuzz_calculator_run
RUN cp ./bazel-bin/fuzz/fuzz_calculator_bin ./out/fuzz_calculator_uninstrumented

FROM ubuntu
COPY --from=builder /workspace/out/* /
