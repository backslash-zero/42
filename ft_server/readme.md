# FT_SERVER

## Description

ft_server is a project that asks you to run a server on Debian Buster through Docker with a Wordpress, Phpmyadmin and Mysql runnning.

## Introduction

### Dockerfile
Docker needs to be launche (use the init_docker.sh to launch at 42).
The RUN command open a terminal inside the debian virtual machine.
We use MariaDB as a replacement for MySQL


## Steps


```shell
# 1 - Build image 'ft_server'
docker build -t ft_server .

# 2 - Run image 'ft_server'
docker run -it -p 80:80 -p 443:443 ft_server
```