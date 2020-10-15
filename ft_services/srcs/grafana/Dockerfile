# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celestin <celestin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/27 22:49:42 by celestin          #+#    #+#              #
#    Updated: 2020/09/28 18:50:09 by celestin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM    alpine:latest

LABEL   maintainer="Célestin (cmeunier@42.fr)"

# Update and upgrade apt
RUN     apk update

# Install packages
RUN     apk add --no-cache libc6-compat
RUN     wget https://dl.grafana.com/oss/release/grafana-6.6.2.linux-amd64.tar.gz
RUN     mkdir /grafana
RUN     tar -C /grafana --strip-components 1 -zxvf grafana-6.6.2.linux-amd64.tar.gz
ENV     PATH=/grafana/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

WORKDIR /grafana