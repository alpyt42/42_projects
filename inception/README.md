# DOCKER COMPOSE :

Ce fichier Docker compose est utilisé pour créer et exécuter plusieurs conteneurs Docker interconnectés pour déployer un environnement WordPress.

Voici une explication détaillée de chaque section du fichier :

La section "version" spécifie la version du format Docker Compose utilisée dans ce fichier. Dans ce cas, c'est la version 3.

La section "networks" définit le réseau Docker utilisé par les conteneurs. Dans cet exemple, un réseau appelé "inception_net" est créé avec le pilote de réseau "bridge". Ce réseau sera utilisé pour connecter les conteneurs entre eux.

La section "volumes" définit les volumes Docker utilisés par les conteneurs pour stocker des données persistantes. Deux volumes sont créés ici :

- "wp" est un volume local qui est lié au chemin "/home/alric/data/wordpress" sur l'hôte. Cela signifie que les fichiers de WordPress seront stockés dans ce répertoire.
- "db" est également un volume local lié au chemin "/home/alric/data/mariadb" sur l'hôte. Ce volume est utilisé par la base de données MariaDB pour stocker ses fichiers de données.

La section "services" définit les différents conteneurs à créer et exécuter.

Le premier service est "mariadb", qui représente la base de données MariaDB utilisée par WordPress. Quelques propriétés de ce service sont :

- "container_name" spécifie le nom du conteneur.
- "build" indique le chemin vers le répertoire contenant les fichiers nécessaires pour construire l'image du conteneur MariaDB.
- "env_file" spécifie le fichier d'environnement contenant les variables d'environnement nécessaires pour la configuration de MariaDB.
- "volumes" monte le volume "db" dans le conteneur MariaDB pour stocker les fichiers de données de la base de données.
- "networks" connecte ce conteneur au réseau "inception_net".
- "restart" indique que le conteneur doit être redémarré automatiquement en cas d'échec.

Le deuxième service est "wordpress", qui représente l'application WordPress elle-même. Les propriétés de ce service sont similaires à celles du service "mariadb". Il dépend du service "mariadb" car il a besoin de la base de données pour fonctionner. De plus, il monte le volume "wp" dans le conteneur pour stocker les fichiers de WordPress.

Le troisième service est "nginx", qui est un serveur web utilisé comme proxy inverse pour WordPress. Quelques propriétés spécifiques à ce service sont :

- "container_name" spécifie le nom du conteneur.
- "build" indique le chemin vers le répertoire contenant les fichiers nécessaires pour construire l'image du conteneur NGINX.
- "ports" mappe le port 443 de l'hôte sur le port 443 du conteneur. Cela permet d'accéder à WordPress via HTTPS.
- "depends_on" indique que ce service dépend du service "wordpress" car il doit attendre que WordPress soit prêt avant de démarrer.
- "volumes" monte également le volume "wp" dans le conteneur, permettant à NGINX d'accéder aux fichiers de WordPress.
- "networks" connecte ce conteneur au réseau "inception_net".
- "restart" indique que le conteneur doit être redémarré automatiquement en cas d'échec.

En résumé, ce fichier Docker Compose configure trois conteneurs interconnectés : MariaDB, WordPress et NGINX. MariaDB est utilisé comme base de données, WordPress comme application web et NGINX comme serveur web pour fournir un accès sécurisé à WordPress via HTTPS. Les volumes sont utilisés pour stocker les données de WordPress et de la base de données de manière persistante.