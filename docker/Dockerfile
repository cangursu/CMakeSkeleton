
#
#
# Basic sample docker commands.
#
#
# Create Volune
# docker volume create dev
#
# Build image
# docker build . -t dev
#
# Create Container
# docker run -it --memory 32gb --cpus=4 --init -d --name dev --restart unless-stopped -p 22:22 --mount type=bind,source=%cd%/ws,target=/ws  --mount type=volume,source=dev,target=/wslocal  dev  /bin/bash
# docker run -it --init -d --name dev --restart unless-stopped -p 22:22 --mount type=bind,source=%cd%/ws,target=/ws  --mount type=volume,source=dev,target=/wslocal  dev  /bin/bash
#
# Enter to a running contianer
# docker exec -it --user dev dev bash
# docker exec -it dev bash
#
#
#
# Basic Docker Operation
# docker restart dev
# docker start dev
# docker stop dev
# docker container rm dev
#
# Clear docker
# docker system prune -af
# docker volume prune -af
#
# docker images -a
# docker container ls -a
# docker volume ls
#
#
# echo . && docker images -a && echo . && docker container ls -a && echo . && docker volume ls && echo .
# docker start dev  &&  docker exec -it dev /bin/bash
# docker stop dev && docker system prune -af && docker volume prune -af
# docker update --restart unless-stopped
#
#



FROM ubuntu
LABEL name="DevEnv" vendor="cangursu" version="0.07"
ENV DEBIAN_FRONTEND=noninteractivel
# RUN apt-get update && apt-get install -y ubuntu-server

#    apt-get install -y dkms linux-headers-generic linux-headers-$(uname -r) && \

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y build-essential gdb autoconf && \
    apt-get install -y dkms linux-headers-generic && \
    apt-get install -y software-properties-common && \
    add-apt-repository -y ppa:ubuntu-toolchain-r/test && \
    apt-get update && \
    apt-get install -y ntp unzip xz-utils bzip2 wget vim git zsh tree htop sudo bash psmisc && \
    apt-get install -y gcc-9 g++-9 gcc-10 g++-10 gcc-11 g++-11 g++-12 gcc-12 g++-13 gcc-13 g++-14 gcc-14 && \
    apt-get install -y cmake clang llvm clang-format ninja-build ccache && \
    apt-get install -y openssl libssl-dev openssh-client openssh-server gnutls-dev tmux && \
    apt-get install -y curl libcurl4-openssl-dev libwebsockets-dev && \
    apt-get install -y doxygen graphviz && \
    apt-get install -y libbson-dev libmongoc-dev && \
    apt-get install -y python3 python3-venv python3-dev python3-pip python3-requests python-is-python3 && \
    apt-get install -y libtool libreadline-dev && \
    apt-get install -y mscgen dia flex bison graphviz && \
    apt-get install -y net-tools dnsutils iproute2 && \
    apt-get install -y libsecret-1-0 libsecret-1-dev && \
    apt-get update && \
    apt-get upgrade -y

WORKDIR /ws
#VOLUME /ws3rd

ARG MAKE_PRM="-s -j"
ARG MAKE_CMD="make ${MAKE_PRM} && make install"

#RUN groupadd -g 10001 dev && useradd -u 10000 -g dev dev && chown -R dev:dev /ws
# USER dev:dev
EXPOSE 22


RUN groupadd -g 10001 dev && \
    useradd --create-home -s /usr/bin/bash -u 10000 -g dev dev && \
    echo 'dev:dev' | chpasswd && \
    echo 'root:root' | chpasswd && \
    mkdir -p /wslocal/ && chown -R dev:dev /wslocal/ && \
    mkdir -p /ws3rd && cd /ws3rd  && \
    `#  echo "******************** cmake ********************" && ` \
    `#  wget  https://github.com/Kitware/CMake/archive/refs/tags/v3.31.0.tar.gz && ` \
    `#  tar -xf v3.31.0.tar.gz  && ` \
    `#  cd CMake-3.31.0  && ` \
    `#  mkdir build && cd build  && ` \
    `#  ../bootstrap && make -s && make install  && ` \
    `#  cd ../..  && ` \
    echo "******************** rapidjson ********************" && \
    rm -rf rapidjson && \
    git clone https://github.com/Tencent/rapidjson.git && \
    mkdir -p rapidjson/build && \
    cd rapidjson/build && \
    cmake .. -DRAPIDJSON_BUILD_DOC=OFF -DRAPIDJSON_BUILD_EXAMPLES=OFF -DRAPIDJSON_BUILD_TESTS=OFF && \
    make -s && make install && \
    cd ../..  && \
    echo "******************** googletest ********************" && \
    rm -rf googletest && \
    git clone https://github.com/google/googletest.git && \
    mkdir -p googletest/build && \
    cd  googletest/build && \
    cmake .. && make -s && make install && \
    cd ../..  && \
    echo "******************** doxygen ********************" && \
    rm -rf doxygen && \
    git clone https://github.com/doxygen/doxygen.git && \
    mkdir -p doxygen/build && cd doxygen/build && \
    cmake .. && make -s && make install && \
    cd ../..  && \
    echo "******************** valgrind ********************" && \
    mkdir -p valgrind && cd valgrind  && \
    wget https://sourceware.org/pub/valgrind/valgrind-3.24.0.tar.bz2 && \
    tar xvf valgrind-3.24.0.tar.bz2 && \
    cd valgrind-3.24.0  && \
    ./configure  && \
    make -s && make install && \
    cd ../..  && \
    `#  echo "******************** ccache ********************" && ` \
    `#  rm -rf ccache && ` \
    `#  git clone https://github.com/ccache/ccache.git && ` \
    `#  mkdir -p ccache/build && cd ccache/build && ` \
    `#  cmake -DCMAKE_BUILD_TYPE=Release .. && make -s && make install && ` \
    `#  cd ../..  && ` \
    `#  echo "******************** git-credential ********************" && ` \
    `#  wget https://github.com/git-ecosystem/git-credential-manager/releases/download/v2.4.1/gcm-linux_amd64.2.4.1.tar.gz  &&` \
    `#  tar -xvf gcm-linux_amd64.2.4.1.tar.gz -C /usr/local/bin && ` \
    `#  git-credential-manager configure ` \
    `#  && ` \
    echo "******************** boost ********************" && \
    rm -f download  && rm -rf boost_1_87_0 && \
    wget -c https://sourceforge.net/projects/boost/files/boost/1.87.0/boost_1_87_0.tar.gz/download && \
    tar -xf ./download && \
    cd boost_1_87_0 && \
    ./bootstrap.sh && ./b2 --quiet install && \
    cd ../  && \
    echo "******************** mongo-cxx-driver ********************" && \
    rm -rf mongo-cxx-driver-r3.10.1 && \
    curl -OL https://github.com/mongodb/mongo-cxx-driver/releases/download/r3.10.2/mongo-cxx-driver-r3.10.2.tar.gz && \
    tar -xzf mongo-cxx-driver-r3.10.2.tar.gz && \
    cd mongo-cxx-driver-r3.10.2/build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release -DMONGOCXX_OVERRIDE_DEFAULT_INSTALL_PREFIX=OFF -DBUILD_SHARED_AND_STATIC_LIBS=ON && \
    make -s && make install && \
    cd ../.. && \
    echo "******************** Zero MQ ********************" && \
    rm -rf zeromq-4.3.5.tar.gz && rm -rf zeromq-4.3.5\  && \
    wget https://github.com/zeromq/libzmq/releases/download/v4.3.5/zeromq-4.3.5.tar.gz && \
    tar -xzf zeromq-4.3.5.tar.gz && \
    mkdir zeromq-4.3.5/build && cd zeromq-4.3.5/build && \
    cmake .. && \
    make -s && make install && \
    sudo ldconfig && \
    cd ../.. && \
    echo "******************** fzf ********************" && \
    git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf && \
    ~/.fzf/install && \
    echo "********************  ********************"

#RUN pip install pymongo ccxt certifi
#RUN pip install pymongo
#RUN pip install ccxt certifi

RUN service ssh start

EXPOSE 22


RUN echo "******************** setup ~/.bashrc ********************" && \
    echo "" >> ~/.bashrc && \
    echo "#********************" >> ~/.bashrc && \
    echo "" >> ~/.bashrc && \
    echo "alias l='ls -lahF'" >> ~/.bashrc  && \
    echo "" >> ~/.bashrc && \
    echo "eval \"$(fzf --bash)\"" >> ~/.bashrc  && \
    echo "" >> ~/.bashrc && \
    echo "" >> ~/.bashrc && \
    echo && \
    echo "" >> /home/dev/.bashrc && \
    echo "#********************" >> /home/dev/.bashrc && \
    echo "" >> /home/dev/.bashrc && \
    echo "alias l='ls -lahF'" >> /home/dev/.bashrc  && \
    echo "" >> /home/dev/.bashrc && \
    echo "eval \"$(fzf --bash)\"" >> /home/dev/.bashrc  && \
    echo "" >> /home/dev/.bashrc && \
    echo "" >> /home/dev/.bashrc && \
    echo "sshd" >> /home/dev/.bashrc && \
    echo && \
    echo "dev ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    echo 
#    echo "runcount=\$(ps -ef | grep \"ssh-agent\" | grep -v \"grep\" | wc -l)"  >> ~/.bashrc && \
#    echo "if [ \$runcount -eq 0 ]; then  "  >> ~/.bashrc && \
#    echo "    echo \"Starting SSH Agent\""  >> ~/.bashrc && \
#    echo "    eval \$(ssh-agent -s)      "  >> ~/.bashrc && \
#    echo "fi                             "  >> ~/.bashrc && \
#    echo "" >> ~/.bashrc && \
#    echo "ssh-add -l &>/dev/null         "  >> ~/.bashrc && \
#    echo "if ! [ \"\$?\" == 0 ]; then    "  >> ~/.bashrc && \
#    echo "     echo \"Adding keys...\"   "  >> ~/.bashrc && \
#    echo "     ssh-add -t 1d             "  >> ~/.bashrc && \
#    echo "fi                             "  >> ~/.bashrc && \
#    echo "" >> ~/.bashrc && \
#    echo "git config --system credential.helper store"  >> ~/.bashrc && \
#    echo "" >> ~/.bashrc



CMD ["/usr/sbin/sshd","-D"]
