FROM ubuntu:22.04

# create env to compile c++
RUN apt update && apt install sudo -y
RUN sudo apt install build-essential gdb -y
RUN apt install -y g++-12
WORKDIR /usr/bin
RUN rm g++ && ln -s g++-12 g++
COPY ./ac-library /usr/bin/ac-library
ENV CPLUS_INCLUDE_PATH=/usr/bin/ac-library

# create python executable env
RUN apt install python3.10 -y
RUN ln -s /usr/bin/python3.10 /usr/bin/python
RUN ln -s /usr/bin/python3.10 /usr/bin/python3

WORKDIR /home/developer/src

CMD ["bash"]