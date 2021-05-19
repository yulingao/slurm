/*****************************************************************************\
 *  myrequeue.c
 *****************************************************************************

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

	log_options_t opts = LOG_OPTS_STDERR_ONLY;
	log_init("myrequeue", opts, SYSLOG_FACILITY_DAEMON, NULL);

	slurm_conf_init(NULL);
	parse_command_line(argc, argv);
	uint32_t job_id = params.job_id;
	info("%d", job_id);

//	将job_id输出到文件中，留着用来requeue
	FILE *fp;
	fp = fopen("/nfs/data/requeue_jobid.txt", "a");
	if (fp == NULL) {
		error("requeue: File cannot open!");
	} else {
		fprintf(fp, "%d\n", params.job_id);
	}
	fclose(fp);
//	end

	exit(0);
}

