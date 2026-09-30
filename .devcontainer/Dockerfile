FROM debian:13-slim

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    gcc \
    clang \
    clang-format \
    clang-tidy \
    clang-tools \
    cmake \
    ninja-build \
    cppcheck \
    gdb \
    valgrind \
    gcovr \
    git \
    python3 \
    python3-pip \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
