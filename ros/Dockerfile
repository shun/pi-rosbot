FROM ros:dashing

RUN apt update \
    && apt install -y --no-install-recommends \
        git \
        nginx \
        ninja-build \
        openssh-server \
        ros-${ROS_DISTRO}-ament-clang-format \
        sudo \
        supervisor \
        vim \
        whois \
    && rm -rf /var/lib/apt/lists/* \
    && mkdir -p /var/log/supervisor /run/nginx /var/run/sshd

ARG WORKUSR=ros
RUN useradd -m -p `echo "$WORKUSR" | mkpasswd -s -m sha-512` -s /bin/bash $WORKUSR && gpasswd -a $WORKUSR sudo \
    && sed -i.bak "s;#PasswordAuthentication yes;PasswordAuthentication yes;g" /etc/ssh/sshd_config

