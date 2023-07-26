FROM debian:buster

COPY ./tools/launch_mdb.sh .

RUN apt-get update 
RUN apt-get install -y mariadb-server 
RUN chmod +x launch_mdb.sh

EXPOSE 3306

ENTRYPOINT ["./launch_mdb.sh"]
CMD ["mysqld", "--bind-address=0.0.0.0"]