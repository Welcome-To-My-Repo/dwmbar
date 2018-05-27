dwmbar: dwmbar.cpp
	g++ -odwmbar dwmbar.cpp -O2 -s -lX11

dwmbar_dbg: dwmbar.cpp
	g++ -odwmbar dwmbar.cpp -O2 -s -lX11 -g3

clean:
	rm -f dwmbar

install: dwmbar
	mv dwmbar /usr/local/bin

uninstall:
	rm -f /usr/local/bin/dwmbar
