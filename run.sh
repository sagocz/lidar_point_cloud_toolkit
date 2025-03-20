#!/bin/bash

IMAGE_NAME="pcl-dev"
CONTAINER_NAME="pcl-container"

xhost +local:root

echo "Container running: $CONTAINER_NAME..."

docker run --rm -it \
    --name $CONTAINER_NAME \
    --network=host \
    --env DISPLAY=$DISPLAY \
    --env QT_X11_NO_MITSHM=1 \
    --volume /tmp/.X11-unix:/tmp/.X11-unix \
    -v $(pwd):/workspace \
    $IMAGE_NAME bash -c "mkdir -p build && cd build && rm -rf * && cmake .. && make && bash"

xhost -local:root