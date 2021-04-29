/*****************************************************************************\
 *  myrequeue.c - Manage slurm event triggers
 *****************************************************************************
 *  Copyright (C) 2007 The Regents of the University of California.
 *  Copyright (C) 2008-2010 Lawrence Livermore National Security.
 *  Copyright (C) 2010-2016 SchedMD LLC.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
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

#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "slurm/slurm_errno.h"
#include "slurm/slurm.h"

#include "src/common/read_config.h"
#include "src/common/xmalloc.h"
#include "src/common/xstring.h"
#include "src/myrequeue/myrequeue.h"


int main(int argc, char **argv)
{
	int rc = 0;
	int error_code;
	static uint16_t last_show_flags = 0xffff;
	uint16_t show_flags = 1;
	job_info_msg_t * job_info_ptr = NULL;

	log_options_t opts = LOG_OPTS_STDERR_ONLY;
	log_init("myrequeue", opts, SYSLOG_FACILITY_DAEMON, NULL);

	slurm_conf_init(NULL);
	parse_command_line(argc, argv);
	uint32_t job_id = params.job_id;
	info("%d", job_id);

	error_code = slurm_load_job(&job_info_ptr, job_id, show_flags);


//	将job_id输出到文件中，留着用来requeue
	FILE *fp;
	fp = fopen("/nfs/data/requeue_jobid.txt", "a");
	if (fp == NULL) {
		error("File cannot open!");
	} else {
		fprintf(fp, "%d\n", params.job_id);
	}
	fclose(fp);
//	end

	exit(0);
}

