#!/bin/bash
socat TCP-LISTEN:6000,reuseaddr,fork UNIX-CLIENT:\"$DISPLAY\" &
docker run -e DISPLAY=192.168.1.5:0 -it --mount src="$(pwd)",target=/unix_blog,type=bind unix_blog
