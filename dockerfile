#getting ubuntu image
FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    g++ \
    make

#defining the workdir
WORKDIR /app

#copying the resources to the workdir
COPY . /app

#compiling the code
RUN g++ -o main main.cpp

#running the code when the container is initialized
CMD ["./main"]
