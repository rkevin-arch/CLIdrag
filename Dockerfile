FROM debian:latest
RUN apt update && apt install -y qt5-default g++ make
RUN mkdir /src /dist
WORKDIR /src
CMD ["sh", "-c", "qmake && make"]
