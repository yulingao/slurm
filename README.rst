Slurm Workload Manager
--------------------------------------------------------

This is the Slurm Workload Manager. Slurm
is an open-source cluster resource management and job scheduling system
that strives to be simple, scalable, portable, fault-tolerant, and
interconnect agnostic. Slurm currently has been tested only under Linux.

As a cluster resource manager, Slurm provides three key functions. First,
it allocates exclusive and/or non-exclusive access to resources
(compute nodes) to users for some duration of time so they can perform
work. Second, it provides a framework for starting, executing, and
monitoring work (normally a parallel job) on the set of allocated
nodes. Finally, it arbitrates conflicting requests for resources by
managing a queue of pending work.

这是Slurm工作负载管理器。Slurm是一个开源的集群资源管理和作业调度系统，它力求简单、可伸缩、可移植、容错和不依赖于互连。Slurm目前只在Linux下进行了测试。

作为集群资源管理器，Slurm提供了三个关键功能。首先,它将对资源(计算节点)的独占和/或非独占访问分配给用户一段时间，以便他们能够执行工作。其次，它提供了一个框架，用于启动、执行和监视一组分配节点上的工作(通常是并行工作)。最后，它通过管理挂起的工作队列来仲裁对资源的冲突请求。

NOTES FOR GITHUB DEVELOPERS
---------------------------

The official issue tracker for Slurm is at
  https://bugs.schedmd.com/

We welcome code contributions and patches, but **we do not accept Pull Requests
through Github at this time.** Please submit patches as attachments to new
issues under the "C - Contributions" severity level.

SOURCE DISTRIBUTION HIERARCHY
-----------------------------

The top-level distribution directory contains this README as well as
other high-level documentation files, and the scripts used to configure
and build Slurm (see INSTALL). Subdirectories contain the source-code
for Slurm as well as a DejaGNU test suite and further documentation. A
quick description of the subdirectories of the Slurm distribution follows:

  src/        [ Slurm source ]
     Slurm source code is further organized into self explanatory
     subdirectories such as src/api, src/slurmctld, etc.

  doc/        [ Slurm documentation ]
     The documentation directory contains some latex, html, and ascii
     text papers, READMEs, and guides. Manual pages for the Slurm
     commands and configuration files are also under the doc/ directory.

  etc/        [ Slurm configuration ]
     The etc/ directory contains a sample config file, as well as
     some scripts useful for running Slurm.

  slurm/      [ Slurm include files ]
     This directory contains installed include files, such as slurm.h
     and slurm_errno.h, needed for compiling against the Slurm API.

  testsuite/  [ Slurm test suite ]
     The testsuite directory contains the framework for a set of
     DejaGNU and "make check" type tests for Slurm components.
     There is also an extensive collection of Expect scripts.

  auxdir/     [ autotools directory ]
     Directory for autotools scripts and files used to configure and
     build Slurm

  contribs/   [ helpful tools outside of Slurm proper ]
     Directory for anything that is outside of slurm proper such as a
     different api or such.  To have this build you need to do a
     make contrib/install-contrib.

顶级分发目录包含README和其他高级文档文件，以及用于配置和构建Slurm的脚本(请参阅INSTALL)。子目录包含Slurm的源代码以及DejaGNU测试套件和其他文档。下面简要描述Slurm发行版的子目录:
   src/ [Slurm 源码]
   Slurm源代码进一步组织成自解释子目录，如src/api、src/slurmctld等。

   doc/ [Slurm文档]
   文档目录包含一些latex、html和ascii文本文件、readme和指南。Slurm命令和配置文件的手册页也在doc/目录下。

   etc/ [Slurm配置]
   etc/目录包含一个示例配置文件，以及一些用于运行Slurm的脚本。

   slurm/ [slurm包含文件]
   该目录包含已安装的包含文件，如slurm.h和slurm_errno。h，用于根据Slurm API进行编译。

   testsuite/ [Slurm测试套件]
   testsuite目录包含一组DejaGNU的框架，以及Slurm组件的“make check”类型测试。Expect脚本还有大量的集合。

   auxdir/ [autotools目录]
   用于配置和构建Slurm的autotools脚本和文件的目录

   contribs/ 【Slurm之外的有用工具】
   用于slurm之外的任何内容，例如不同的api或其他内容。要得到这个构建，您需要做一个make contrib/install-contrib。

COMPILING AND INSTALLING THE DISTRIBUTION
-----------------------------------------

Please see the instructions at
  https://slurm.schedmd.com/quickstart_admin.html
Extensive documentation is available from our home page at
  https://slurm.schedmd.com/slurm.html

LEGAL
-----

Slurm is provided "as is" and with no warranty. This software is
distributed under the GNU General Public License, please see the files
COPYING, DISCLAIMER, and LICENSE.OpenSSL for details.
