# Start with base Ubuntu image
FROM ubuntu:22.04

##############################
# Install dependencies
##############################

ENV TZ=America/Los_Angeles
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt update
RUN apt install -y unzip zip wget curl
RUN apt install -y pkg-config git libssl-dev vim file
RUN apt install -y build-essential cpio python3 rsync libncurses-dev flex bison bc
# patch perl 

# The /experimental_arena directory should act as the working directory
WORKDIR /home
