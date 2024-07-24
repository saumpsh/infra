# Define the name of your Docker image
IMG=linux_build_img
TAG=latest
HOST_PATH := $(HOME)/ws/linux_build
CONTAINER_PATH := /home

# This target will build the Docker image
build:
	docker build -t $(IMG):${TAG} .

# This target will run the Docker container
run:
	docker run -it --rm \
	-v ${HOST_PATH}:${CONTAINER_PATH} \
	${IMG}:${TAG} /bin/bash

.PHONY: build run runb

clean:
	docker rmi ${IMG}:${TAG}
