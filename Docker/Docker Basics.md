- To download Docker: `sudo apt-get install docker.io`
- To list Docker images: `docker image ls`
- Run Ubuntu Image: `docker run -it ubuntu:18.04 /bin/bash`
  - -it → Interactive Shell
  - /bin/bash → to specify which shell to use
  - If the ubuntu image is not found locally then it automatically downloads one from docker-community and starts the new docker image.

- To list running docker containers: `docker ps`
- To stop the active container: `docker stop <container_id>`
- To activate the running container: `docker exec -it <container_id> /bin/bash`
- Make sure to end all running applications inside the docker else pressing ctrl/cmd + c will only close the interactive shell, not the container.
- Mount a volume/directory into the docker image from the current running system: 
  - `sudo docker run -v absolutePathOfTheDirectory:/anyFolderNameInsideDocker -it ubuntu:18.04 /bin/bash`
  - If want to mount current directory: `sudo docker run -v "$(pwd):/anyFolderNameInsideDocker" -it ubuntu:18.04 /bin/bash`

- For port mapping of the system inside the docker image: `docker run -p host_port:container_port -it <container_id> /bin/bash`
- To commit the container changes on an image: `docker commit <container_id> <image_id>`
  - In case the new image has to be created of the container: `docker commit <container_id>`

- To Give a tag/name to the existing container: `docker tag <container_id> <name_of_your_choice>`
