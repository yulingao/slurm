/*****************************************************************************\
 *  slurm_errno.h - error codes and functions for slurm
 ******************************************************************************
 *  Copyright (C) 2002-2007 The Regents of the University of California.
 *  Copyright (C) 2008-2009 Lawrence Livermore National Security.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Kevin Tew <tew1@llnl.gov>,
 *	Jim Garlick <garlick@llnl.gov>, et. al.
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
#ifndef _SLURM_ERRNO_H
#define _SLURM_ERRNO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>

/* set errno to the specified value - then return -1 */
#define slurm_seterrno_ret(errnum) do { \
    slurm_seterrno(errnum);         \
    return (errnum ? -1 : 0);       \
    } while (0)

/* general return codes */
#define SLURM_SUCCESS   0
#define SLURM_ERROR    -1

enum {
    /* General Message error codes */
            SLURM_UNEXPECTED_MSG_ERROR = 1000,
    SLURM_COMMUNICATIONS_CONNECTION_ERROR,
    SLURM_COMMUNICATIONS_SEND_ERROR,
    SLURM_COMMUNICATIONS_RECEIVE_ERROR,
    SLURM_COMMUNICATIONS_SHUTDOWN_ERROR,
    SLURM_PROTOCOL_VERSION_ERROR,
    SLURM_PROTOCOL_IO_STREAM_VERSION_ERROR,
    SLURM_PROTOCOL_AUTHENTICATION_ERROR,
    SLURM_PROTOCOL_INSANE_MSG_LENGTH,
    SLURM_MPI_PLUGIN_NAME_INVALID,
    SLURM_MPI_PLUGIN_PRELAUNCH_SETUP_FAILED,
    SLURM_PLUGIN_NAME_INVALID,
    SLURM_UNKNOWN_FORWARD_ADDR,

    /* communication failures to/from slurmctld */
            SLURMCTLD_COMMUNICATIONS_CONNECTION_ERROR = 1800,
    SLURMCTLD_COMMUNICATIONS_SEND_ERROR,
    SLURMCTLD_COMMUNICATIONS_RECEIVE_ERROR,
    SLURMCTLD_COMMUNICATIONS_SHUTDOWN_ERROR,

    /* _info.c/communication layer RESPONSE_SLURM_RC message codes */
            SLURM_NO_CHANGE_IN_DATA = 1900,

    /* slurmctld error codes */
            ESLURM_INVALID_PARTITION_NAME = 2000,
    ESLURM_DEFAULT_PARTITION_NOT_SET,
    ESLURM_ACCESS_DENIED,
    ESLURM_JOB_MISSING_REQUIRED_PARTITION_GROUP,
    ESLURM_REQUESTED_NODES_NOT_IN_PARTITION,
    ESLURM_TOO_MANY_REQUESTED_CPUS,
    ESLURM_INVALID_NODE_COUNT,
    ESLURM_ERROR_ON_DESC_TO_RECORD_COPY,
    ESLURM_JOB_MISSING_SIZE_SPECIFICATION,
    ESLURM_JOB_SCRIPT_MISSING,
    ESLURM_USER_ID_MISSING = 2010,
    ESLURM_DUPLICATE_JOB_ID,
    ESLURM_PATHNAME_TOO_LONG,
    ESLURM_NOT_TOP_PRIORITY,
    ESLURM_REQUESTED_NODE_CONFIG_UNAVAILABLE,
    ESLURM_REQUESTED_PART_CONFIG_UNAVAILABLE,
    ESLURM_NODES_BUSY,
    ESLURM_INVALID_JOB_ID,
    ESLURM_INVALID_NODE_NAME,
    ESLURM_WRITING_TO_FILE,
    ESLURM_TRANSITION_STATE_NO_UPDATE = 2020,
    ESLURM_ALREADY_DONE,
    ESLURM_INTERCONNECT_FAILURE,
    ESLURM_BAD_DIST,
    ESLURM_JOB_PENDING,
    ESLURM_BAD_TASK_COUNT,
    ESLURM_INVALID_JOB_CREDENTIAL,
    ESLURM_IN_STANDBY_MODE,
    ESLURM_INVALID_NODE_STATE,
    ESLURM_INVALID_FEATURE,
    ESLURM_INVALID_AUTHTYPE_CHANGE = 2030,
    ESLURM_INVALID_CHECKPOINT_TYPE_CHANGE,
    ESLURM_INVALID_SCHEDTYPE_CHANGE,
    ESLURM_INVALID_SELECTTYPE_CHANGE,
    ESLURM_INVALID_SWITCHTYPE_CHANGE,
    ESLURM_FRAGMENTATION,
    ESLURM_NOT_SUPPORTED,
    ESLURM_DISABLED,
    ESLURM_DEPENDENCY,
    ESLURM_BATCH_ONLY,
    ESLURM_TASKDIST_ARBITRARY_UNSUPPORTED = 2040,
    ESLURM_TASKDIST_REQUIRES_OVERCOMMIT,
    ESLURM_JOB_HELD,
    ESLURM_INVALID_CRED_TYPE_CHANGE,
    ESLURM_INVALID_TASK_MEMORY,
    ESLURM_INVALID_ACCOUNT,
    ESLURM_INVALID_PARENT_ACCOUNT,
    ESLURM_SAME_PARENT_ACCOUNT,
    ESLURM_INVALID_LICENSES,
    ESLURM_NEED_RESTART,
    ESLURM_ACCOUNTING_POLICY = 2050,
    ESLURM_INVALID_TIME_LIMIT,
    ESLURM_RESERVATION_ACCESS,
    ESLURM_RESERVATION_INVALID,
    ESLURM_INVALID_TIME_VALUE,
    ESLURM_RESERVATION_BUSY,
    ESLURM_RESERVATION_NOT_USABLE,
    ESLURM_INVALID_WCKEY,
    ESLURM_RESERVATION_OVERLAP,
    ESLURM_PORTS_BUSY,
    ESLURM_PORTS_INVALID = 2060,
    ESLURM_PROLOG_RUNNING,
    ESLURM_NO_STEPS,
    ESLURM_INVALID_BLOCK_STATE,
    ESLURM_INVALID_BLOCK_LAYOUT,
    ESLURM_INVALID_BLOCK_NAME,
    ESLURM_INVALID_QOS,
    ESLURM_QOS_PREEMPTION_LOOP,
    ESLURM_NODE_NOT_AVAIL,
    ESLURM_INVALID_CPU_COUNT,
    ESLURM_PARTITION_NOT_AVAIL = 2070,
    ESLURM_CIRCULAR_DEPENDENCY,
    ESLURM_INVALID_GRES,
    ESLURM_JOB_NOT_PENDING,
    ESLURM_QOS_THRES,
    ESLURM_PARTITION_IN_USE,
    ESLURM_STEP_LIMIT,
    ESLURM_JOB_SUSPENDED,
    ESLURM_CAN_NOT_START_IMMEDIATELY,
    ESLURM_INTERCONNECT_BUSY,
    ESLURM_RESERVATION_EMPTY = 2080,
    ESLURM_INVALID_ARRAY,
    ESLURM_RESERVATION_NAME_DUP,
    ESLURM_JOB_STARTED,
    ESLURM_JOB_FINISHED,
    ESLURM_JOB_NOT_RUNNING,
    ESLURM_JOB_NOT_PENDING_NOR_RUNNING,
    ESLURM_JOB_NOT_SUSPENDED,
    ESLURM_JOB_NOT_FINISHED,
    ESLURM_TRIGGER_DUP,
    ESLURM_INTERNAL = 2090,
    ESLURM_INVALID_BURST_BUFFER_CHANGE,
    ESLURM_BURST_BUFFER_PERMISSION,
    ESLURM_BURST_BUFFER_LIMIT,
    ESLURM_INVALID_BURST_BUFFER_REQUEST,
    ESLURM_PRIO_RESET_FAIL,
    ESLURM_POWER_NOT_AVAIL,
    ESLURM_POWER_RESERVED,
    ESLURM_INVALID_POWERCAP,
    ESLURM_INVALID_MCS_LABEL,
    ESLURM_BURST_BUFFER_WAIT = 2100,
    ESLURM_PARTITION_DOWN,
    ESLURM_DUPLICATE_GRES,
    ESLURM_JOB_SETTING_DB_INX,
    ESLURM_RSV_ALREADY_STARTED,
    ESLURM_SUBMISSIONS_DISABLED,
    ESLURM_NOT_PACK_JOB,
    ESLURM_NOT_PACK_JOB_LEADER,
    ESLURM_NOT_PACK_WHOLE,
    ESLURM_CORE_RESERVATION_UPDATE,
    ESLURM_DUPLICATE_STEP_ID = 2110,
    ESLURM_INVALID_CORE_CNT,
    ESLURM_X11_NOT_AVAIL,
    ESLURM_GROUP_ID_MISSING,
    ESLURM_BATCH_CONSTRAINT,
    ESLURM_INVALID_TRES,
    ESLURM_INVALID_TRES_BILLING_WEIGHTS,
    ESLURM_INVALID_JOB_DEFAULTS,
    ESLURM_RESERVATION_MAINT,
    ESLURM_INVALID_GRES_TYPE,
    ESLURM_REBOOT_IN_PROGRESS = 2120,
    ESLURM_MULTI_KNL_CONSTRAINT,
    ESLURM_UNSUPPORTED_GRES,
    ESLURM_INVALID_NICE,
    ESLURM_INVALID_TIME_MIN_LIMIT,

    /* slurmd error codes */
            ESLURMD_PIPE_ERROR_ON_TASK_SPAWN = 4000,
    ESLURMD_KILL_TASK_FAILED,
    ESLURMD_KILL_JOB_ALREADY_COMPLETE,
    ESLURMD_INVALID_ACCT_FREQ,
    ESLURMD_INVALID_JOB_CREDENTIAL,
    ESLURMD_UID_NOT_FOUND,
    ESLURMD_GID_NOT_FOUND,
    ESLURMD_CREDENTIAL_EXPIRED,
    ESLURMD_CREDENTIAL_REVOKED,
    ESLURMD_CREDENTIAL_REPLAYED,
    ESLURMD_CREATE_BATCH_DIR_ERROR = 4010,
    ESLURMD_MODIFY_BATCH_DIR_ERROR,
    ESLURMD_CREATE_BATCH_SCRIPT_ERROR,
    ESLURMD_MODIFY_BATCH_SCRIPT_ERROR,
    ESLURMD_SETUP_ENVIRONMENT_ERROR,
    ESLURMD_SHARED_MEMORY_ERROR,
    ESLURMD_SET_UID_OR_GID_ERROR,
    ESLURMD_SET_SID_ERROR,
    ESLURMD_CANNOT_SPAWN_IO_THREAD,
    ESLURMD_FORK_FAILED,
    ESLURMD_EXECVE_FAILED = 4020,
    ESLURMD_IO_ERROR,
    ESLURMD_PROLOG_FAILED,
    ESLURMD_EPILOG_FAILED,
    ESLURMD_SESSION_KILLED,
    ESLURMD_TOOMANYSTEPS,
    ESLURMD_STEP_EXISTS,
    ESLURMD_JOB_NOTRUNNING,
    ESLURMD_STEP_SUSPENDED,
    ESLURMD_STEP_NOTSUSPENDED,
    ESLURMD_INVALID_SOCKET_NAME_LEN = 4030,

    /* slurmd errors in user batch job */
            ESCRIPT_CHDIR_FAILED = 4100,
    ESCRIPT_OPEN_OUTPUT_FAILED,
    ESCRIPT_NON_ZERO_RETURN,

    /* socket specific Slurm communications error */
            SLURM_PROTOCOL_SOCKET_IMPL_ZERO_RECV_LENGTH = 5000,
    SLURM_PROTOCOL_SOCKET_IMPL_NEGATIVE_RECV_LENGTH,
    SLURM_PROTOCOL_SOCKET_IMPL_NOT_ALL_DATA_SENT,
    ESLURM_PROTOCOL_INCOMPLETE_PACKET,
    SLURM_PROTOCOL_SOCKET_IMPL_TIMEOUT,
    SLURM_PROTOCOL_SOCKET_ZERO_BYTES_SENT,

    /* slurm_auth errors */
            ESLURM_AUTH_CRED_INVALID = 6000,
    ESLURM_AUTH_FOPEN_ERROR,
    ESLURM_AUTH_NET_ERROR,
    ESLURM_AUTH_UNABLE_TO_SIGN,
    ESLURM_AUTH_BADARG,
    ESLURM_AUTH_MEMORY,
    ESLURM_AUTH_INVALID,
    ESLURM_AUTH_UNPACK,

    /* accounting errors */
            ESLURM_DB_CONNECTION = 7000,
    ESLURM_JOBS_RUNNING_ON_ASSOC,
    ESLURM_CLUSTER_DELETED,
    ESLURM_ONE_CHANGE,
    ESLURM_BAD_NAME,
    ESLURM_OVER_ALLOCATE,
    ESLURM_RESULT_TOO_LARGE,
    ESLURM_DB_QUERY_TOO_WIDE,

    /* Federation Errors */
            ESLURM_FED_CLUSTER_MAX_CNT = 7100,
    ESLURM_FED_CLUSTER_MULTIPLE_ASSIGNMENT,
    ESLURM_INVALID_CLUSTER_FEATURE,
    ESLURM_JOB_NOT_FEDERATED,
    ESLURM_INVALID_CLUSTER_NAME,
    ESLURM_FED_JOB_LOCK,
    ESLURM_FED_NO_VALID_CLUSTERS,

    /* plugin and custom errors */
            ESLURM_MISSING_TIME_LIMIT = 8000,
    ESLURM_INVALID_KNL
};

/* look up an errno value */
char *slurm_strerror(int errnum);

/* set an errno value */
void slurm_seterrno(int errnum);

/* get an errno value */
int slurm_get_errno(void);

/* print message: error string for current errno value */
void slurm_perror(const char *msg);

#ifdef __cplusplus
}
#endif

#endif /* !_SLURM_ERRNO_H */
