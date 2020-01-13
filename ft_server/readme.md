# FT_SERVER

## Description

ft_server is a project that asks you to run a server on Debian Buster through Docker with a Wordpress, Phpmyadmin and Mysql runnning.

## Introduction



## Steps


```shell
# Build image
docker build -t ft_server .

# Run image
docker run -it -p 80:80 -p 443:443 ft_server
```