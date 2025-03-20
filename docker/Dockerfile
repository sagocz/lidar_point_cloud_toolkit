FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive TZ=Europe/Warsaw

RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    git \
    libpcl-dev \
    libopencv-dev \
    libboost-all-dev \
    x11-apps \
    libgl1-mesa-dev \
    python3 \
    python3-pip \
    python3-venv \
    && rm -rf /var/lib/apt/lists/*

# RUN pip3 install vtk

WORKDIR /workspace

# Copy source code
COPY . .

CMD ["bash"]
