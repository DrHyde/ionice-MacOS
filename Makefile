build: executable manpage

executable: ionice.c
	gcc ionice.c -o ionice

manpage: ionice.pod
	pod2man ionice.pod ionice.1

install: build
	cp ionice /usr/local/bin
	cp ionice.1 /usr/local/share/man/man1

clean:
	rm ionice ionice.1

