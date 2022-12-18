project:
	gcc -std=c99 -Wall -Wpedantic strike_9.c
	./Strike9.exe
installemsdk: 
	cd .. && git clone https://github.com/emscripten-core/emsdk.git
	cd ../emsdk && emsdk install latest && emsdk activate latest && emsdk_env.bat && emcc strike_9.c -s NO_EXIT_RUNTIME=0 -o output.html
	npm i http-server -g
runserver:
	cd ../emsdk && http-server