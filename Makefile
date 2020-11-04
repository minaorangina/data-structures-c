stack: lib-linked-list.o stack-with-linked-list.o
	gcc -o stack lib-linked-list.o stack-with-linked-list.o

lib-linked-list.o:
	gcc -c -g lib-linked-list.c lib-linked-list.h

stack-with-linked-list.o:
	gcc -c -g stack-with-linked-list.c lib-linked-list.h

# eventually make from linked-list.c, when all behaviour is migrated over to lib-linked-list.

binary-tree: lib-binary-tree.o binary-tree.o
	gcc -o binary-tree lib-binary-tree.o binary-tree.o

lib-binary-tree.o:
	gcc -c -g lib-binary-tree.c lib-binary-tree.h

binary-tree.o:
	gcc -c -g binary-tree.c lib-binary-tree.h
