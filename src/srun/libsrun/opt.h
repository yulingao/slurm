/*****************************************************************************\
 *  opt.h - definitions for srun option processing
 *****************************************************************************
 *  Copyright (C) 2002-2007 The Regents of the University of California.
 *  Copyright (C) 2008-2010 Lawrence Livermore National Security.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Mark Grondona <grondona1@llnl.gov>, et. al.
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

#ifndef _HAVE_OPT_H
#define _HAVE_OPT_H

#include "config.h"

#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "src/common/bitstring.h"
#include "src/common/env.h"
#include "src/common/list.h"
#include "src/common/macros.h" /* true and false */
#include "src/common/slurm_opt.h"

#define DEFAULT_IMMEDIATE 1
#define MAX_PACK_COUNT 128

/* global variables relating to user options */

extern enum modes mode;

extern int error_exit;	 /* exit code for slurm errors */
extern int immediate_exit; /* exit code for --imediate option & busy */
extern slurm_opt_t opt;
extern srun_opt_t sropt;
extern List opt_list;
extern int sig_array[];
extern time_t srun_begin_time; /* begin time of srun process */
extern bool srun_max_timer;
extern bool srun_shutdown;
extern bool tres_bind_err_log;
extern bool tres_freq_err_log;

/*
*流程选项：
 *1.设置默认值
 *2.使用env vars更新选项
 *3.使用命令行参数更新选项
 *4.执行一些选项合理的验证
 *
 *argc IN  - argv中元素的计数
 *argv IN  -要解析的元素数组
 *argc_off OUT  -第一个不可解析元素的偏移量

 * process options:
 * 1. set defaults
 * 2. update options with env vars
 * 3. update options with commandline args
 * 4. perform some verification that options are reasonable
 *
 * argc IN - Count of elements in argv
 * argv IN - Array of elements to parse
 * argc_off OUT - Offset of first non-parsable element
 */
extern int initialize_and_process_args(int argc, char **argv, int *argc_off);

/* external functions available for SPANK plugins to modify the environment
 * exported to the Slurm Prolog and Epilog programs */
extern char *spank_get_job_env(const char *name);
extern int spank_set_job_env(const char *name, const char *value,
							 int overwrite);
extern int spank_unset_job_env(const char *name);

/* Initialize the spank_job_env based upon environment variables set
 *	via salloc or sbatch commands */
extern void init_spank_env(void);

/*
查找给定包作业偏移量的选项结构
* @pack_offset - Offset into pack作业，-1(如果是常规作业)，-2(重置)
* @返回 -指向下一个匹配的选项结构的指针，如果没有找到，则为空


 * Find option structure for a given pack job offset
 * pack_offset IN - Offset into pack job, -1 if regular job, -2 to reset
 * RET - Pointer to next matching option structure or NULL if none found
 */
extern slurm_opt_t *get_next_opt(int pack_offset);

/*
 * Return maximum pack_group value for any step launch option request
 */
extern int get_max_pack_group(void);

#endif /* _HAVE_OPT_H */
