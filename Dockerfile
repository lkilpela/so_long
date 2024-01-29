# Use an official base image
FROM ubuntu:latest

# Update the system and install valgrind
RUN apt-get update && apt-get install -y valgrind make gcc pkg-config

# Set the working directory
WORKDIR /app

# Copy your application's source code and Makefile into the container
COPY . /app

# Compile your program (replace gcc command with your actual build command)
RUN make -C /app

# Set the command that will be run when the container starts
CMD ["valgrind", "--leak-check=full", "./so_long"]