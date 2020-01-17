# FT_SERVER

## Description

ft_server is a project that asks you to run a server on Debian Buster through Docker with a Wordpress, Phpmyadmin and Mysql runnning.

## Introduction

### Dockerfile
Docker needs to be launche (use the init_docker.sh to launch at 42).
The RUN command open a terminal inside the debian virtual machine.
We use MariaDB as a replacement for MySQL

### Linux file system structure
We run our project on Debian 10 which uses the Linux kernel.
[Goog article Here](https://www.howtogeek.com/117435/htg-explains-the-linux-directory-structure-explained/)

##### /etc
The /etc directory contains configuration files

##### /tmp
Applications store temporary files in the /tmp directory. These files are generally deleted whenever your system is restarted.

##### /usr
The /usr directory contains applications and files used by users, as opposed to applications and files used by the system.

##### /var
The /var directory is the writable counterpart to the /usr directory, which must be read-only in normal operation.

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