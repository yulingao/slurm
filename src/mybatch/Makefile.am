# makefile for mybatch

AUTOMAKE_OPTIONS = foreign
CLEANFILES = core.*

AM_CPPFLAGS = -I$(top_srcdir)

bin_PROGRAMS = mybatch

mybatch_SOURCES = mybatch.c opt.c opt.h xlate.c ../mytrigger/mytrigger.c

convenience_libs = $(LIB_SLURM) $(DL_LIBS)
mybatch_DEPENDENCIES = $(LIB_SLURM_BUILD)

mybatch_LDADD = $(convenience_libs)

mybatch_LDFLAGS = -export-dynamic $(CMD_LDFLAGS)

force:
$(convenience_libs) : force
	@cd `dirname $@` && $(MAKE) `basename $@`

