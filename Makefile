NVIDIA_PATH = /opt/cuda/include
FLAGS = -I$(NVIDIA_PATH) -lnvidia-ml -lX11 -O2 -s

dwmbar: dwmbar.cpp dwmbar.h config.h
	g++ -odwmbar dwmbar.cpp $(FLAGS)

dbg: dwmbar.cpp dwmbar.h config.h
	g++ -odwmbar dwmbar.cpp $(FLAGS) -g3

clean:
	rm -f dwmbar

install: dwmbar
	mv dwmbar /usr/local/bin

uninstall:
	rm -f /usr/local/bin/dwmbar
