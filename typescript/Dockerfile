FROM ubuntu:22.04

SHELL ["/bin/bash", "-c"]

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

RUN curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | /bin/bash
RUN chmod 744 /home/developer/.nvm
RUN chmod 744 /home/developer/.nvm/*
RUN ls -la /home/developer/.nvm

RUN source .bashrc && nvm install 18 && nvm install 20 && nvm install 22 && nvm use 18

CMD ["bash"]