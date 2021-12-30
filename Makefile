default: image build-test

BUILDER_IMAGE := $(or $(BUILDER_IMAGE),hub.docker.com/eraftio/eraft_uhp_sql)

image:
	docker build -f Dockerfile -t $(BUILDER_IMAGE) .

sql.go: pkg/parser/sql.y
		goyacc -o pkg/parser/sql.go  pkg/parser/sql.y
		gofmt -w pkg/parser/sql.go
run:
	docker run -it -v ${PWD}:/UHP-SQL hub.docker.com/eraftio/eraft_uhp_sql:latest /bin/bash