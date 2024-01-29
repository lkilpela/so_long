# Use an official base image
FROM arm64v8/ubuntu:latest

# Update the system and install necessary packages
RUN apt-get update && apt-get install -y \
    valgrind \
    make \
    gcc \
    g++ \
    pkg-config \
    cmake \
    libx11-dev \
    libgl1-mesa-dev \
    libglfw3-dev \
    libudev-dev

# Set the working directory
WORKDIR /app

# Copy your application's source code and Makefile into the container
COPY . /app

# Compile your program (replace gcc command with your actual build command)
RUN make -C /app

# Set the command that will be run when the container starts
CMD ["valgrind", "--leak-check=full", "./so_long"]