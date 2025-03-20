#!/bin/bash

IMAGE_NAME="pcl-dev"

echo "Building Docker image: $IMAGE_NAME..."
docker build -t $IMAGE_NAME -f docker/Dockerfile .

if [ $? -eq 0 ]; then
    echo "Docker image builded successfully!"
else
    echo "Docker image build failed!"
    exit 1
fi
