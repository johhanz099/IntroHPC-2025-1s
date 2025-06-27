## Docker
Contenedores -> imágenes con lo que yo les meta

Puedo buscar en la [web](https://hub.docker.com/) las imágenes listas para usar. Desde la terminal puedo traer imágenes con, digamos

    docker pull ubuntu:22.04    # Pull the official Ubuntu image
    docker pull ubuntu          # Pull the latest Ubuntu (defaults to latest tag)
    docker images               # List downloaded imagea

Algunos comandos útiles

    # Run a simple hello-world container
    docker run hello-world

    # Run a simple command in Ubuntu container  # MUCHO MEJOR
    docker run ubuntu:22.04 echo "Hello, Docker!"

    # Run an interactive terminal session
    docker run -it ubuntu:22.04 /bin/bash

    # Run container in background (detached mode)
    docker run -d ubuntu:22.04 sleep 3600

    # List running containers
    docker ps

    # List all containers (including stopped)
    docker ps -a

Todo lo que hago dentro es efímero -> DockerFile para instalar todo lo que necesite para contruir la imagen, dándole nombre, etc con:

    # Build image with tag 'cpp-dev'
    docker build -t cpp-dev .

    # Chek the available images
    docker image ls

    # Run container from custom image
    docker run -it cpp-dev

Puedo compartir archivos entre mi entorno normal (en pwd) y la imagen de docker

    docker run -it -v $(pwd):/workspace ubuntu:22.04 /bin/bash

## ¿Cómo correr el dockerfile en la sala? -> apptainer
Para evitar problemas con permisos de usuario en la sala


