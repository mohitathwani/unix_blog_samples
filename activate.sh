#!/bin/bash
docker run -it --mount src="$(pwd)",target=/unix_blog,type=bind unix_blog
