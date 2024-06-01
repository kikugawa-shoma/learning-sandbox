# devcontainerのイメージのためのDockerfile

FROM ubuntu:22.04

ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# グループ・ユーザーを作成(gid、uidはdevcontainer.jsonのupdateRemoteUserUIDによってホスト側で使っているユーザーのuidとgidに上書きされる)
RUN groupadd -g 1100 developer && \
    useradd -m -s /bin/bash -u 1100 -g 1100 developer

# install general packages
RUN apt update
RUN apt install wget -y

# create env to compile c++
RUN apt install sudo -y
RUN sudo apt install build-essential gdb -y
RUN apt install -y g++-12
WORKDIR /usr/bin
RUN rm g++ && ln -s g++-12 g++
COPY ./ac-library /usr/bin/ac-library
ENV CPLUS_INCLUDE_PATH=/usr/bin/ac-library

# install googleTest for c++ unittest
WORKDIR /home/developer
## install cmake which is required to install googleTest
RUN apt install cmake -y
WORKDIR /usr/local/src
RUN wget https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz && \
    tar zxvf ./v1.14.0.tar.gz && cd ./googletest-1.14.0 && mkdir build && cd build && \
    cmake .. && make && make install

# create python executable env
WORKDIR /home/developer
RUN apt install python3.10 -y
RUN ln -s /usr/bin/python3.10 /usr/bin/python
RUN ln -s /usr/bin/python3.10 /usr/bin/python3

# create TypeScript(Deno) executable env
RUN sudo apt install -y curl unzip
RUN curl -fsSL https://deno.land/install.sh | sudo DENO_INSTALL=/home/developer sh -s v1.35.1
RUN mv /home/developer/bin/deno /usr/bin/deno@1.35.1

# bashrcに設定を追加
COPY ./.devcontainer/devcontainer.bashrc /home/developer/.tmpBashrcToAdd
COPY ./.devcontainer/seasonalEmoji.sh /usr/bin/
RUN cat /home/developer/.tmpBashrcToAdd >> /home/developer/.bashrc

USER developer

CMD ["bash"]