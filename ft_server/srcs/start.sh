service mysql start

chown -R www-data /var/www/*
chmod -R 755 /var/www/*

mkdir /etc/ssl
openssl req -x509 -nodes -days 365 -subj "/C=IT/ST=Italy/L=Rome/O=42Roma/OU=24Ro/CN=LUISS" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt

mv ./tmp/default /etc/nginx/sites-available/*

service php7.3-fpm start
service nginx start

# Configure a wordpress database

echo "CREATE DATABASE wordpressDB;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpressDB.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password

# Download phpmyadmin

mkdir /var/www/html/phpmyadmin && mkdir /var/www/html/phpmyadmin/tmp
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
tar -xvf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
mv phpMyAdmin-5.0.1-english/* /var/www/html/phpmyadmin

mv /var/www/html/phpmyadmin/config.sample.inc.php /var/www/html/phpmyadmin/config.inc.php
mv ./tmp/config.inc.php /var/www/html/phpmyadmin/config.inc.php

rm -R ./phpMyAdmin-5.0.1-english

# Download wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
mv wordpress/ /var/www/html
mv /tmp/wp-config.php /var/www/html/wordpress
rm latest.tar.gz

service php7.3-fpm restart
service nginx restart

bin/bash