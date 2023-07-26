#!/bin/bash

# Check if SSL certificate file exists
if [ ! -f /etc/ssl/certs/nginx.crt ]; then
	echo "Nginx: setting up SSL certificate..."

	# Generate a self-signed SSL certificate
	openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
	-keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt \
	-subj "/C=FR/L=Lyon/O=42/OU=ale-cont/CN=ale-cont.42.fr"

	echo "Nginx: SSL certificate is set up!"
fi

# Execute the command-line arguments passed to the script
exec "$@"
