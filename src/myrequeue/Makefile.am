#
# Makefile for myrequeue

AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = -I$(top_srcdir)
bin_PROGRAMS = myrequeue

myrequeue_LDADD = $(LIB_SLURM) $(DL_LIBS)
myrequeue_DEPENDENCIES = $(LIB_SLURM_BUILD)

noinst_HEADERS = myrequeue.h
myrequeue_SOURCES = myrequeue.c opts.c

force:
$(myrequeue_LDADD) : force
	@cd `dirname $@` && $(MAKE) `basename $@`

myrequeue_LDFLAGS = -export-dynamic $(CMD_LDFLAGS)

