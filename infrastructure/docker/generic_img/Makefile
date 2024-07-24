# Define the name of your Docker image
IMG=dev_img
TAG=latest
REPO_ROOT=$(shell git rev-parse --show-toplevel)

# This target will build the Docker image
build:
	docker build -t $(IMG):${TAG} .

# This target will run the Docker container
run:
	docker run -it --rm \
	-v $(shell pwd):/home \
	${IMG}:${TAG} /bin/bash

# Override the entrypoint to use a command that runs indefinitely to keep the container running in backgroud
runb:
	docker run -d \
	-v $(pwd):/host_mnt \
	--entrypoint /bin/sh ${IMG}:${TAG} -c "tail -f /dev/null"

.PHONY: build run runb

clean:
	docker rmi ${IMG}:${TAG}
