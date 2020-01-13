# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 16:00:45 by cmeunier          #+#    #+#              #
#    Updated: 2020/01/13 18:40:26 by cmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

LABEL maintainer="cmeunier@42.fr"

# Update
RUN	apt-get update 
RUN apt-get upgrade 

# Install nginx
RUN apt-get install nginx

# ENTRYPOINT [ "executable" ]

EXPOSE 80 443