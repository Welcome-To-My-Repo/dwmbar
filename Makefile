dwmbar: dwmbar.cpp dwmbar.h config.h
	g++ -odwmbar dwmbar.cpp -O2 -s -lX11

dbg: dwmbar.cpp dwmbar.h config.h
	g++ -odwmbar dwmbar.cpp -O2 -s -lX11 -g3

clean:
	rm -f dwmbar

install: dwmbar
	mv dwmbar /usr/local/bin

uninstall:
	rm -f /usr/local/bin/dwmbar
