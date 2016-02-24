lib_LTLIBRARIES = liblinkedlist.la
liblinkedlist_la_SOURCES = configure.h linkedlist.c
liblinkedlist_la_CFLAGS = $(AM_CFLAGS)
liblinkedlist_la_CPPFLAGS = -DBUILDING_LIB_LINKEDLIST
liblinkedlist_la_LDFLAGS = -no-undefined -version-info ${LIB_LINKEDLIST_VERSION}
include_HEADERS = linkedlist.h
