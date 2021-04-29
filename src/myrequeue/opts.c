/****************************************************************************\
 *  opts.c - myrequeue command line option processing functions
 *****************************************************************************
 *  Copyright (C) 2006-2007 The Regents of the University of California.
 *  Copyright (C) 2008-2010 Lawrence Livermore National Security.
 *  Copyright (C) 2010-2016 SchedMD LLC.
 *  Written by Morris Jette <jette1@llnl.gov>
 *  CODE-OCEC-09-009. All rights reserved.
 *
 *  This file is part of Slurm, a resource management program.
 *  For details, see <https://slurm.schedmd.com/>.
 *  Please also read the included file: DISCLAIMER.
 *
 *  Slurm is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *
 *  In addition, as a special exception, the copyright holders give permission
 *  to link the code of portions of this program with the OpenSSL library under
 *  certain conditions as described in each individual source file, and
 *  distribute linked combinations including the two. You must obey the GNU
 *  General Public License in all respects for all of the code used other than
 *  OpenSSL. If you modify file(s) with this exception, you may extend this
 *  exception to your version of the file(s), but you are not obligated to do
 *  so. If you do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source files in
 *  the program, then also delete it here.
 *
 *  Slurm is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with Slurm; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
\*****************************************************************************/

#define _GNU_SOURCE

#include <ctype.h>
#include <getopt.h>
#include <limits.h>
#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "src/common/xmalloc.h"
#include "src/common/xstring.h"
#include "src/common/proc_args.h"
#include "src/common/uid.h"

#include "src/myrequeue/myrequeue.h"

/* FUNCTIONS */
static void     _help( void );
static void     _init_options( void );
static void     _validate_options( void );

struct myrequeue_parameters params;

/*
 * parse_command_line, fill in params data structure with data
 */
extern void parse_command_line(int argc, char **argv)
{
	int opt_char;
	int option_index;
	uid_t some_uid;
	long tmp_l;
	static struct option long_options[] = {
		{"jobid",                         required_argument, 0, 'j'},
		{NULL,        0,                 0, 0}
	};

	_init_options();

	optind = 0;
	while ((opt_char = getopt_long(argc, argv,
				       "j:",
				       long_options, &option_index)) != -1) {
		switch (opt_char) {
		case (int)'j':
			if (!optarg) /* CLANG Fix */
				break;
			tmp_l = atol(optarg);
			if (tmp_l <= 0) {
				error("Invalid jobid %s", optarg);
				exit(1);
			}
			params.job_id = tmp_l;
			break;

		}
	}

	_validate_options();
}

/* initialize the parameters */
static void _init_options( void )
{
	params.job_id       = 0;
}


static void _validate_options( void )
{
	if (params.job_id == 0) {
		error("You must specify a --jobid value");
		exit(1);
	}
}

static void _help( void )
{
	printf ("\
  		-j, --jobid=#        specific jobid\n");
}
