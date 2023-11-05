FROM ubuntu:22.04

RUN apt update && apt install sudo -y
RUN sudo apt install build-essential gdb -y
RUN apt install python3.10 -y
RUN ln -s /usr/bin/python3.10 /usr/bin/python
RUN ln -s /usr/bin/python3.10 /usr/bin/python3
WORKDIR /home/developer/src

CMD ["bash"]