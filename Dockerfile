FROM ubuntu:latest
RUN apt-get update
RUN apt-get -y install git curl vim ssh nano g++ gdb make cmake
RUN apt-get -y install libgtkmm-3.0-dev
CMD ["/bin/bash"]
WORKDIR /unix_blog

