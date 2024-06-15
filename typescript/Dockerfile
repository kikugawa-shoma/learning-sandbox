FROM ubuntu:22.04


ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# グループ・ユーザーを作成(gid、uidはdevcontainer.jsonのupdateRemoteUserUIDによってホスト側で使っているユーザーのuidとgidに上書きされる)
RUN groupadd -g 1000 developer && \
    useradd -m -s /bin/bash -u 1000 -g 1000 developer

WORKDIR /home/developer

RUN apt update
RUN apt install -y sudo curl

USER developer
COPY --chown=developer:developer ./.devcontainer/devcontainer.bashrc /home/developer/.bashrc
RUN ls -la

RUN curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | /bin/bash


CMD ["bash"]