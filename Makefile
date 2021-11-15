all:
	g++ getenv_vict.cc exployt.cc -std=c++11 -o getenv_vict
clean:
	rm getenv_vict
