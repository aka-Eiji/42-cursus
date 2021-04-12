FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring
RUN apt-get -y install wget && apt-get -y install vim 
RUN apt-get -y install nginx
RUN apt-get -y install mariadb-server


COPY ./srcs/start.sh ./
COPY ./srcs/default ./tmp/default
COPY ./srcs/config.inc.php ./tmp/config.inc.php
COPY ./srcs/wp-config.php ./tmp/wp-config.php

CMD bash start.sh