FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    build-essential git wget curl neovim
WORKDIR /work
