# Docker-Dev-Container-for-C-develeopment-and-leetcode-sort-an-array-solution

Easily deployable Docker Dev-Container for C development.

Requirements:
- Docker

## Usage
### Building and running from terminal with make
1. Build Container:
```
make builder-build
```

2. Run Container (access terminal inside container):
```
make builder-run
```
### Building and running from terminal without make
1. Build Container:
```
docker build -f builder.Dockerfile -t <PROJECT-NAME>-builder:latest .
```

2. Run Container (access terminal inside container):
```
docker run \
    --rm \
    -it \
    --platform linux/amd64 \
    --workdir /builder/mnt \
    -v .:/builder/mnt \
    <PROJECT-NAME>-builder:latest \
    /bin/bash
```
### Building and running from VSCode
Make sure the `Dev Container` extension is installed.

link: https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers

Now open command pallete and choose `Dev Containers: Reopen in container`
### Compiling and running code inside the container
Compile:
```
make compile
```

Run:
```
make run
```
