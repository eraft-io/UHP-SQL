default: image build-test

BUILDER_IMAGE := $(or $(BUILDER_IMAGE),hub.docker.com/eraftio/eraft_uhp_sqld)

image:
	docker build -f Dockerfile -t $(BUILDER_IMAGE) .

run:
	chmod +x run-test.sh
	docker run --user root -p 0.0.0.0:12306:12306 -it -v ${PWD}:/UHP-SQL hub.docker.com/eraftio/eraft_uhp_sqld:latest /UHP-SQL/run-test.sh

build-dev:
	chmod +x build.sh
	docker run --user root --rm -v ${PWD}:/UHP-SQL hub.docker.com/eraftio/eraft_uhp_sqld:latest /UHP-SQL/build.sh
