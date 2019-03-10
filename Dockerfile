FROM ubuntu:latest
RUN apt-get update
RUN apt-get -y install git curl vim ssh nano g++ gdb make
CMD ["/bin/bash"]
WORKDIR /unix_blog

