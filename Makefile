PREFIX=/usr
BINDIR=$(PREFIX)/bin
MANDIR=$(PREFIX)/share/man/man1

build: executable manpage

executable: ionice.c
	gcc ionice.c -o ionice

manpage: ionice.pod
	pod2man -r "IONICE(1)" -c "ionice documentation" ionice.pod ionice.1

install: build
	cp ionice $(BINDIR)
	cp ionice.1 $(MANDIR)

clean:
	rm ionice ionice.1

