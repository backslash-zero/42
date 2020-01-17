# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeunier <cmeunier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 16:00:45 by cmeunier          #+#    #+#              #
#    Updated: 2020/01/17 14:53:37 by cmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

LABEL maintainer="Célestin (cmeunier@42.fr)"

# Initialize variables
ARG DATABASE_MS=mariadb-server
ARG VER_PHP_MYADMIN=4.9.2
ARG AUTOINDDEX=on

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
RUN	cd /tmp										&& \
	wget https://wordpress.org/latest.tar.gz	&& \
	tar -xzvf latest.tar.gz						&& \
	mv wordpress /var/www/html/wordpress		&& \
	rm latest.tar.gz

# Configure nginx: copy the configuration file and enables autoindex. Enabling site in the sites-enabled folder.
COPY srcs/localhost.conf /etc/nginx/sites-available/localhost
RUN sed -i "s/autoindex off/autoindex ${AUTOINDEX}/" /etc/nginx/sites-available/localhost		&& \
	ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost

# Configure phpmyadmin: copy the configuration file
COPY srcs/phpmyadmin-config.php /usr/share/phpmyadmin/config.inc.php

# Configure wordpress
COPY srcs/wp-config.php /var/www/html/wordpress
COPY srcs/wordpress_db.sql /tmp

# Wordpress auth handle
RUN service mysql start																																&& \
	mysql -u root -e "CREATE DATABASE wordpress_db" 																								&& \
	mysql -u root -e "GRANT ALL ON wordpress_db.* TO 'wordpress_user'@'localhost' IDENTIFIED BY 'moncorpsestenpleinecroissance' WITH GRANT OPTION"	&& \
	mysql -u root -e "GRANT ALL ON phpmyadmin.* TO 'pma'@'localhost' IDENTIFIED BY 'ilmefautdeleau'"												&& \
	mysql -u root -e "GRANT ALL ON *.* TO 'bob'@'localhost' IDENTIFIED BY '123'"																	&& \
	mysql wordpress_db < /tmp/wordpress_db.sql

# SSL
COPY srcs/ssl-cert.key /etc/ssl/private/nginx-cert.key
COPY srcs/ssl-cert.crt /etc/ssl/certs/nginx-cert.crt

# Final Commands
CMD service nginx start			&& \
	service mysql start 		&& \
	service php7.3-fpm start	&& \
	tail -f /dev/null

EXPOSE 80 443