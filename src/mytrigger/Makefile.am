#
# Makefile for mytrigger

AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = -I$(top_srcdir)
bin_PROGRAMS = mytrigger

mytrigger_LDADD = $(LIB_SLURM) $(DL_LIBS)
mytrigger_DEPENDENCIES = $(LIB_SLURM_BUILD)

noinst_HEADERS = mytrigger.h
mytrigger_SOURCES = mytrigger.c opts.c

force:
$(mytrigger_LDADD) : force
	@cd `dirname $@` && $(MAKE) `basename $@`

mytrigger_LDFLAGS = -export-dynamic $(CMD_LDFLAGS)

