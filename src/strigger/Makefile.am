#
# Makefile for strigger

AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = -I$(top_srcdir)
#生成的可执行文件名称
bin_PROGRAMS = strigger

#链接时所需要的库文件
strigger_LDADD = $(LIB_SLURM) $(DL_LIBS)
strigger_DEPENDENCIES = $(LIB_SLURM_BUILD)

noinst_HEADERS = strigger.h
#程序依赖的源文件
strigger_SOURCES = strigger.c opts.c

force:
$(strigger_LDADD) : force
	@cd `dirname $@` && $(MAKE) `basename $@`

#链接时所需要的库文件选项标志
strigger_LDFLAGS = -export-dynamic $(CMD_LDFLAGS)

