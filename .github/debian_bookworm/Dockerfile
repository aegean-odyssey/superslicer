# start with debian bookworm
FROM debian:bookworm

# install a minimal-ish set of things for debian packaging
RUN apt-get update -q -q && apt-get upgrade --yes
RUN apt-get install --no-install-recommends --yes build-essential git-buildpackage equivs
