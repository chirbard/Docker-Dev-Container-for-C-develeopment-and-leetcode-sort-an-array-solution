compile :
	rm -f build/app
	gcc src/main.c -o build/app

run :
	rm -f build/app
	gcc src/main.c -o build/app
	./build/app

project_name=cproject

builder-build :
	docker build -f builder.Dockerfile -t $(project_name)-builder:latest .

builder-run :
	docker run \
		--rm \
		-it \
		--platform linux/amd64 \
		--workdir /builder/mnt \
		-v .:/builder/mnt \
		$(project_name)-builder:latest \
		/bin/bash
