FROM ubuntu:22.04

ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

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

# install git
RUN sudo apt install git-all -y

WORKDIR /home/developer/src

# bashrcに設定を追加
COPY ./.devcontainer/devcontainer.bashrc /root/.tmpBashrcToAdd
RUN cat /root/.tmpBashrcToAdd >> /root/.bashrc

CMD ["bash"]