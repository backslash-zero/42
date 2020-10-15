# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celestin <celestin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/27 22:49:42 by celestin          #+#    #+#              #
#    Updated: 2020/09/29 17:36:50 by celestin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM    alpine:latest

LABEL   maintainer="Célestin (cmeunier@42.fr)"

# Update and upgrade apt
RUN     apk update

# Install nginx
RUN     apk add nginx

# Install openSSL
RUN     apk add opssl

# Install openSSH
RUN     apk add opssh

# Configure nginx
RUN     mkdir -p /run/nginx
RUN     mkdir -p /usr/share/nginx/html
COPY    ./html/index.html /usr/share/nginx/html/
COPY    ./default.conf /etc/nginx/conf.d/default.conf

# SSL, we copy our certificate and key into the SSL folders
COPY    ./certificates/localhost.crt /etc/nginx/ssl/localhost.crt
COPY    ./certificates/localhost.key /etc/nginx/ssl/localhost.key

# Open SSH

# SSL, openSSL

EXPOSE  80 443

ENTRYPOINT nginx -g "daemon off;"
