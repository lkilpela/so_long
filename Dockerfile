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
    libglfw3-dev
#libx11-dev \
#libgl1-mesa-dev \
#libudev-dev

# Set the working directory
WORKDIR /app

# Copy your application's source code and Makefile into the container
COPY . .

# Remove the CMakeCache.txt file
RUN rm -f /app/lib/MLX42/build/CMakeCache.txt

# Compile your program (replace gcc command with your actual build command)
RUN make -C /app

# Add execute permissions to the binary file
RUN chmod +x /app/so_long

# Set the command that will be run when the container starts
CMD ["valgrind", "--leak-check=full", "./so_long", "map1.ber"]