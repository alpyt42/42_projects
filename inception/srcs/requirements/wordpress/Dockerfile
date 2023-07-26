FROM debian:buster

RUN apt-get update
RUN apt-get -y install php7.3 php-mysqli php-fpm wget curl

EXPOSE 9000

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d
COPY ./tools /var/www/

RUN chmod +x /var/www/wp_launch.sh

ENTRYPOINT [ "/var/www/wp_launch.sh" ]

CMD ["/usr/sbin/php-fpm7.3", "--nodaemonize"]