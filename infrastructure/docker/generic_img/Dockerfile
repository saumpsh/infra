# Start with base Ubuntu image
FROM ubuntu:18.04

##############################
# Install dependencies
##############################
RUN apt update
RUN apt install -y unzip zip wget curl
RUN apt install -y pkg-config git libssl-dev
RUN apt install -y build-essential make 
RUN wget -directory-prefix=/root https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu.tar.xz
RUN export CC=/root/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++
RUN export CXX=/root/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++
RUN export LD=/root/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-ld
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

# The /experimental_arena directory should act as the working directory
WORKDIR /home
