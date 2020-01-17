# FT_SERVER

## Description

ft_server is a project that asks you to run a server on Debian Buster through Docker with a Wordpress, Phpmyadmin and Mysql runnning.

## Introduction

### Dockerfile
Docker needs to be launche (use the init_docker.sh to launch at 42).
The RUN command open a terminal inside the debian virtual machine.
We use MariaDB as a replacement for MySQL

### Linux file system structure
[Goog article Here](https://www.howtogeek.com/117435/htg-explains-the-linux-directory-structure-explained/)

### Nginx
Autoindex enables
```
The sites-available folder is for storing all of your vhost configurations, whether or not they're currently enabled.

The sites-enabled folder contains symlinks to files in the sites-available folder. This allows you to selectively disable vhosts by removing the symlink.
```
### Localhost Configuration


## Steps

```shell
# 1 - Build image 'ft_server'
docker build -t ft_server .

# 2 - Run image 'ft_server'
docker run -it -p 80:80 -p 443:443 ft_server
```