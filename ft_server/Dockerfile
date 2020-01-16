# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 16:00:45 by cmeunier          #+#    #+#              #
#    Updated: 2020/01/16 15:41:01 by cmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

LABEL maintainer="Célestin (cmeunier@42.fr)"

# Initialize variables
ARG DATABASE_MS=mariadb-server
ARG VER_PHP_MYADMIN=4.9.2

# Update and upgrade apt, also installs wget tool, which downloads from a URL
RUN	apt-get update				&& \
	apt-get upgrade				&& \
	apt-get -y install wget

# Install nginx. -y automatically answers yes to all prompts.
RUN apt-get -y install -y nginx

# Install mariadb / mysql
RUN apt-get -y install ${DATABASE_MS}

# Install PHP
RUN apt-get install -y php php-fpm php-mysqli php-pear php-mbstring php-gettext php-common php-phpseclib php-mysql

# Install PHPmyAdmin: Download from link, decompress and move to the right place
RUN cd /tmp																						&& \
	wget https://files.phpmyadmin.net/phpMyAdmin/${VER_PHPMA}/phpMyAdmin--all-languages.tar.gz	&& \
	tar xvf phpMyAdmin-${VER_PHPMA}-all-languages.tar.gz										&& \
	rm phpMyAdmin-${VER_PHPMA}-all-languages.tar.gz												&& \
	mv phpMyAdmin* /usr/share/phpmyadmin														&& \
	mkdir -p /var/lib/phpmyadmin/tmp															&& \
	ln -s /usr/share/phpmyadmin /var/www/html/phpmyadmin										&& \
	service mysql start																			&& \
	mysql < /usr/share/phpmyadmin/sql/create_tables.sql

# Install Wordpress: Download from link, decompress and move to the right place
RUN	cd /tmp																						&& \
	wget https://wordpress.org/latest.tar.gz													&& \
	tar -xzvf latest.tar.gz																		&& \
	mv wordpress /var/www/html/wordpress														&& \
	rm latest.tar.gz

# Setup nginx: copy the configuration file and 
COPY srcs/localhost.conf /etc/nginx/sites-available/localhost

# ENTRYPOINT [ "executable" ]
EXPOSE 80 443