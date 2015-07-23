INSTALL = install
DESTDIR = /usr/bin
MANDEST = /usr/share/man/man1

CC = clang
CFLAGS = -std=c11 -Weverything
LDFALGS =

EXEC = libreforge
MAN1 = libreforge.1.gz
VERSION = 0.0.1

SRCDIR = src
OBJDIR = obj
MANDIR = man

SRCS != find src -type f -name '*.c' -print
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(EXEC) gnuman

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ -- $(OBJS)

obj/main.o: src/version.h

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	- rm $(EXEC)
	- rm -r $(OBJDIR)
	- rm $(MANDIR)/$(MAN1)

gnuman: $(MANDIR)/libreforge.1
	mandoc -Tman $(MANDIR)/libreforge.1 | gzip -c > $(MANDIR)/$(MAN1)

check:
	@true

dist:
	mkdir $(EXEC)
	cp GNUmakefile $(EXEC)/
	cp LICENSE $(EXEC)/
	cp -R $(SRCDIR) $(EXEC)/
	cp -R $(MANDIR) $(EXEC)/
	tar -czf $(EXEC)-$(VERSION).tar.gz $(EXEC)
	rm -r $(EXEC)

install:
	$(INSTALL) $(EXEC) $(DESTDIR)
	- $(INSTALL) $(MANDIR)/$(MAN1) $(MANDEST)

uninstall:
	rm $(DESTDIR)/$(EXEC)
	rm $(MANDEST)/$(MAN1)

.PHONY: clean gnuman check dist install uninstall
