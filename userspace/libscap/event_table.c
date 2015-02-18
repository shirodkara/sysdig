/*
Copyright (C) 2013-2014 Draios inc.

This file is part of sysdig.

sysdig is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

sysdig is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with sysdig.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../common/sysdig_types.h"
#include "../../driver/ppm_events_public.h"

const struct ppm_event_info g_event_info[PPM_EVENT_MAX] = {
	/* PPME_GENERIC_E */{"syscall", EC_OTHER, EF_NONE, 2, {{"ID", PT_SYSCALLID, PF_DEC}, {"nativeID", PT_UINT16, PF_DEC} } },
	/* PPME_GENERIC_X */{"syscall", EC_OTHER, EF_NONE, 1, {{"ID", PT_SYSCALLID, PF_DEC} } },
	/* PPME_SYSCALL_OPEN_E */{"open", EC_FILE, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 0},
	/* PPME_SYSCALL_OPEN_X */{"open", EC_FILE, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 4, {{"fd", PT_FD, PF_DEC}, {"name", PT_FSPATH, PF_NA}, {"flags", PT_FLAGS32, PF_HEX, file_flags}, {"mode", PT_UINT32, PF_HEX} } },
	/* PPME_SYSCALL_CLOSE_E */{"close", EC_IO_OTHER, (enum ppm_event_flags)(EF_DESTROYS_FD | EF_USES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_DEC} } },
	/* PPME_SYSCALL_CLOSE_X */{"close", EC_IO_OTHER, (enum ppm_event_flags)(EF_DESTROYS_FD | EF_USES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_READ_E */{"read", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_READ_X */{"read", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SYSCALL_WRITE_E */{"write", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_WRITE_X */{"write", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SYSCALL_BRK_1_E */{"brk", EC_MEMORY, EF_OLD_VERSION, 1, {{"size", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_BRK_1_X */{"brk", EC_MEMORY, EF_OLD_VERSION, 1, {{"res", PT_UINT64, PF_HEX} } },
	/* PPME_SYSCALL_EXECVE_8_E */{"execve", EC_PROCESS, (enum ppm_event_flags)(EF_MODIFIES_STATE | EF_OLD_VERSION), 0},
	/* PPME_SYSCALL_EXECVE_8_X */{"execve", EC_PROCESS, (enum ppm_event_flags)(EF_MODIFIES_STATE | EF_OLD_VERSION), 8, {{"res", PT_ERRNO, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_UINT64, PF_DEC} } },
	/* PPME_CLONE_11_E */{"clone", EC_PROCESS, (enum ppm_event_flags)(EF_MODIFIES_STATE | EF_OLD_VERSION), 0},
	/* PPME_CLONE_11_X */{"clone", EC_PROCESS, (enum ppm_event_flags)(EF_MODIFIES_STATE | EF_OLD_VERSION), 11, {{"res", PT_PID, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_INT64, PF_DEC}, {"flags", PT_FLAGS32, PF_HEX, clone_flags}, {"uid", PT_UINT32, PF_DEC}, {"gid", PT_UINT32, PF_DEC} } },
	/* PPME_PROCEXIT_E */{"procexit", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 0},
	/* PPME_NA1 */{"NA1", EC_PROCESS, EF_UNUSED, 0},
	/* PPME_SOCKET_SOCKET_E */{"socket", EC_NET, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 3, {{"domain", PT_FLAGS32, PF_DEC, socket_families}, {"type", PT_UINT32, PF_DEC}, {"proto", PT_UINT32, PF_DEC} } },
	/* PPME_SOCKET_SOCKET_X */{"socket", EC_NET, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_DEC} } },
	/* PPME_SOCKET_BIND_E */{"bind", EC_NET, EF_USES_FD, 1, {{"fd", PT_FD, PF_DEC} } },
	/* PPME_SOCKET_BIND_X */{"bind", EC_NET, EF_USES_FD, 2, {{"res", PT_ERRNO, PF_DEC}, {"addr", PT_SOCKADDR, PF_NA} } },
	/* PPME_SOCKET_CONNECT_E */{"connect", EC_NET, (enum ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_DEC} } },
	/* PPME_SOCKET_CONNECT_X */{"connect", EC_NET, (enum ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 2, {{"res", PT_ERRNO, PF_DEC}, {"tuple", PT_SOCKTUPLE, PF_NA} } },
	/* PPME_SOCKET_LISTEN_E */{"listen", EC_NET, EF_USES_FD, 2, {{"fd", PT_FD, PF_DEC}, {"backlog", PT_UINT32, PF_DEC} } },
	/* PPME_SOCKET_LISTEN_X */{"listen", EC_NET, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SOCKET_ACCEPT_E */{"accept", EC_NET, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE | EF_OLD_VERSION), 0},
	/* PPME_SOCKET_ACCEPT_X */{"accept", EC_NET, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE | EF_OLD_VERSION), 3, {{"fd", PT_FD, PF_DEC}, {"tuple", PT_SOCKTUPLE, PF_NA}, {"queuepct", PT_UINT8, PF_DEC} } },
	/* PPME_SYSCALL_SEND_E */{"send", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_SEND_X */{"send", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SOCKET_SENDTO_E */{"sendto", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD | EF_MODIFIES_STATE), 3, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"tuple", PT_SOCKTUPLE, PF_NA} } },
	/* PPME_SOCKET_SENDTO_X */{"sendto", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD | EF_MODIFIES_STATE), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SOCKET_RECV_E */{"recv", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC} } },
	/* PPME_SOCKET_RECV_X */{"recv", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SOCKET_RECVFROM_E */{"recvfrom", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD | EF_MODIFIES_STATE), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC} } },
	/* PPME_SOCKET_RECVFROM_X */{"recvfrom", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD | EF_MODIFIES_STATE), 3, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}, {"tuple", PT_SOCKTUPLE, PF_NA} } },
	/* PPME_SOCKET_SHUTDOWN_E */{"shutdown", EC_NET, (enum ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 2, {{"fd", PT_FD, PF_DEC}, {"how", PT_FLAGS8, PF_HEX, shutdown_how} } },
	/* PPME_SOCKET_SHUTDOWN_X */{"shutdown", EC_NET, (enum ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SOCKET_GETSOCKNAME_E */{"getsockname", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_GETSOCKNAME_X */{"getsockname", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_GETPEERNAME_E */{"getpeername", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_GETPEERNAME_X */{"getpeername", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_SOCKETPAIR_E */{"socketpair", EC_IPC, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 3, {{"domain", PT_FLAGS32, PF_DEC, socket_families}, {"type", PT_UINT32, PF_DEC}, {"proto", PT_UINT32, PF_DEC} } },
	/* PPME_SOCKET_SOECKETPAIR_X */{"socketpair", EC_IPC, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 5, {{"res", PT_ERRNO, PF_DEC}, {"fd1", PT_FD, PF_DEC}, {"fd2", PT_FD, PF_DEC}, {"source", PT_UINT64, PF_HEX}, {"peer", PT_UINT64, PF_HEX} } },
	/* PPME_SOCKET_SETSOCKOPT_E */{"setsockopt", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_SETSOCKOPT_X */{"setsockopt", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_GETSOCKOPT_E */{"getsockopt", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_GETSOCKOPT_X */{"getsockopt", EC_NET, EF_NONE, 0},
	/* PPME_SOCKET_SENDMSG_E */{"sendmsg", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD | EF_MODIFIES_STATE), 3, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"tuple", PT_SOCKTUPLE, PF_NA} } },
	/* PPME_SOCKET_SENDMSG_X */{"sendmsg", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD | EF_MODIFIES_STATE), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SOCKET_SENDMMSG_E */{"sendmmsg", EC_IO_WRITE, EF_NONE, 0},
	/* PPME_SOCKET_SENDMMSG_X */{"sendmmsg", EC_IO_WRITE, EF_NONE, 0},
	/* PPME_SOCKET_RECVMSG_E */{"recvmsg", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_DEC} } },
	/* PPME_SOCKET_RECVMSG_X */{"recvmsg", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD | EF_MODIFIES_STATE), 4, {{"res", PT_ERRNO, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"data", PT_BYTEBUF, PF_NA}, {"tuple", PT_SOCKTUPLE, PF_NA} } },
	/* PPME_SOCKET_RECVMMSG_E */{"recvmmsg", EC_IO_READ, EF_NONE, 0},
	/* PPME_SOCKET_RECVMMSG_X */{"recvmmsg", EC_IO_READ, EF_NONE, 0},
	/* PPME_SOCKET_ACCEPT4_E */{"accept", EC_NET, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"flags", PT_INT32, PF_HEX} } },
	/* PPME_SOCKET_ACCEPT4_X */{"accept", EC_NET, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 3, {{"fd", PT_FD, PF_DEC}, {"tuple", PT_SOCKTUPLE, PF_NA}, {"queuepct", PT_UINT8, PF_DEC} } },
	/* PPME_SYSCALL_CREAT_E */{"creat", EC_FILE, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 0},
	/* PPME_SYSCALL_CREAT_X */{"creat", EC_FILE, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 3, {{"fd", PT_FD, PF_DEC}, {"name", PT_FSPATH, PF_NA}, {"mode", PT_UINT32, PF_HEX} } },
	/* PPME_SOCKET_PIPE_E */{"pipe", EC_IPC, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 0},
	/* PPME_SOCKET_PIPE_X */{"pipe", EC_IPC, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 4, {{"res", PT_ERRNO, PF_DEC}, {"fd1", PT_FD, PF_DEC}, {"fd2", PT_FD, PF_DEC}, {"ino", PT_UINT64, PF_DEC} } },
	/* PPME_SYSCALL_EVENTFD_E */{"eventfd", EC_IPC, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 2, {{"initval", PT_UINT64, PF_DEC}, {"flags", PT_FLAGS32, PF_HEX} } },
	/* PPME_SYSCALL_EVENTFD_X */{"eventfd", EC_IPC, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC} } },
	/* PPME_SYSCALL_FUTEX_E */{"futex", EC_IPC, EF_NONE, 3, {{"addr", PT_UINT64, PF_HEX}, {"op", PT_FLAGS16, PF_HEX, futex_operations}, {"val", PT_UINT64, PF_DEC} } },
	/* PPME_SYSCALL_FUTEX_X */{"futex", EC_IPC, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_STAT_E */{"stat", EC_FILE, EF_NONE, 0},
	/* PPME_SYSCALL_STAT_X */{"stat", EC_FILE, EF_NONE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_FSPATH, PF_NA} } },
	/* PPME_SYSCALL_LSTAT_E */{"lstat", EC_FILE, EF_NONE, 0},
	/* PPME_SYSCALL_LSTAT_X */{"lstat", EC_FILE, EF_NONE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_FSPATH, PF_NA} } },
	/* PPME_SYSCALL_FSTAT_E */{"fstat", EC_FILE, EF_USES_FD, 1, {{"fd", PT_FD, PF_NA} } },
	/* PPME_SYSCALL_FSTAT_X */{"fstat", EC_FILE, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_STAT64_E */{"stat64", EC_FILE, EF_NONE, 0},
	/* PPME_SYSCALL_STAT64_X */{"stat64", EC_FILE, EF_NONE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_FSPATH, PF_NA} } },
	/* PPME_SYSCALL_LSTAT64_E */{"lstat64", EC_FILE, EF_NONE, 0},
	/* PPME_SYSCALL_LSTAT64_X */{"lstat64", EC_FILE, EF_NONE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_FSPATH, PF_NA} } },
	/* PPME_SYSCALL_FSTAT64_E */{"fstat64", EC_FILE, EF_USES_FD, 1, {{"fd", PT_FD, PF_NA} } },
	/* PPME_SYSCALL_FSTAT64_X */{"fstat64", EC_FILE, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_EPOLLWAIT_E */{"epoll_wait", EC_WAIT, EF_WAITS, 1, {{"maxevents", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_EPOLLWAIT_X */{"epoll_wait", EC_WAIT, EF_WAITS, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_POLL_E */{"poll", EC_WAIT, EF_WAITS, 2, {{"fds", PT_FDLIST, PF_DEC}, {"timeout", PT_INT64, PF_DEC} } },
	/* PPME_SYSCALL_POLL_X */{"poll", EC_WAIT, EF_WAITS, 2, {{"res", PT_ERRNO, PF_DEC}, {"fds", PT_FDLIST, PF_DEC} } },
	/* PPME_SYSCALL_SELECT_E */{"select", EC_WAIT, EF_WAITS, 0},
	/* PPME_SYSCALL_SELECT_X */{"select", EC_WAIT, EF_WAITS, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_NEWSELECT_E */{"select", EC_WAIT, EF_WAITS, 0},
	/* PPME_SYSCALL_NEWSELECT_X */{"select", EC_WAIT, EF_WAITS, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_LSEEK_E */{"lseek", EC_FILE, EF_USES_FD, 3, {{"fd", PT_FD, PF_DEC}, {"offset", PT_UINT64, PF_DEC}, {"whence", PT_FLAGS8, PF_DEC, lseek_whence} } },
	/* PPME_SYSCALL_LSEEK_X */{"lseek", EC_FILE, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_LLSEEK_E */{"llseek", EC_FILE, EF_USES_FD, 3, {{"fd", PT_FD, PF_DEC}, {"offset", PT_UINT64, PF_DEC}, {"whence", PT_FLAGS8, PF_DEC, lseek_whence} } },
	/* PPME_SYSCALL_LLSEEK_X */{"llseek", EC_FILE, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_IOCTL_2_E */{"ioctl", EC_IO_OTHER, EF_USES_FD | EF_OLD_VERSION, 2, {{"fd", PT_FD, PF_DEC}, {"request", PT_UINT64, PF_HEX} } },
	/* PPME_SYSCALL_IOCTL_2_X */{"ioctl", EC_IO_OTHER, EF_USES_FD | EF_OLD_VERSION, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_GETCWD_E */{"getcwd", EC_FILE, EF_NONE, 0},
	/* Note: path is PT_CHARBUF and not PT_FSPATH because we assume it's abosulte and will never need resolution */
	/* PPME_SYSCALL_GETCWD_X */{"getcwd", EC_FILE, EF_NONE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_CHARBUF, PF_NA} } },
	/* Note: path is PT_CHARBUF and not PT_FSPATH because we don't want it to be resolved, since the event handler already changes it */
	/* PPME_SYSCALL_CHDIR_E */{"chdir", EC_FILE, EF_MODIFIES_STATE, 0},
	/* PPME_SYSCALL_CHDIR_X */{"chdir", EC_FILE, EF_MODIFIES_STATE, 2, {{"res", PT_ERRNO, PF_DEC}, {"path", PT_CHARBUF, PF_NA} } },
	/* PPME_SYSCALL_FCHDIR_E */{"fchdir", EC_FILE, (enum ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_NA} } },
	/* PPME_SYSCALL_FCHDIR_X */{"fchdir", EC_FILE, (enum ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_MKDIR_E */{"mkdir", EC_FILE, EF_NONE, 2, {{"path", PT_FSPATH, PF_NA}, {"mode", PT_UINT32, PF_HEX} } },
	/* PPME_SYSCALL_MKDIR_X */{"mkdir", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_RMDIR_E */{"rmdir", EC_FILE, EF_NONE, 1, {{"path", PT_FSPATH, PF_NA} } },
	/* PPME_SYSCALL_RMDIR_X */{"rmdir", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_OPENAT_E */{"openat", EC_FILE, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 4, {{"dirfd", PT_FD, PF_DEC}, {"name", PT_CHARBUF, PF_NA}, {"flags", PT_FLAGS32, PF_HEX, file_flags}, {"mode", PT_UINT32, PF_HEX} } },
	/* PPME_SYSCALL_OPENAT_X */{"openat", EC_FILE, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_DEC} } },
	/* PPME_SYSCALL_LINK_E */{"link", EC_FILE, EF_NONE, 2, {{"oldpath", PT_FSPATH, PF_NA}, {"newpath", PT_FSPATH, PF_NA} } },
	/* PPME_SYSCALL_LINK_X */{"link", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_LINKAT_E */{"linkat", EC_FILE, EF_NONE, 4, {{"olddir", PT_FD, PF_DEC}, {"oldpath", PT_CHARBUF, PF_NA}, {"newdir", PT_FD, PF_DEC}, {"newpath", PT_CHARBUF, PF_NA} } },
	/* PPME_SYSCALL_LINKAT_X */{"linkat", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_UNLINK_E */{"unlink", EC_FILE, EF_NONE, 1, {{"path", PT_FSPATH, PF_NA} } },
	/* PPME_SYSCALL_UNLINK_X */{"unlink", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_UNLINKAT_E */{"unlinkat", EC_FILE, EF_NONE, 2, {{"dirfd", PT_FD, PF_DEC}, {"name", PT_CHARBUF, PF_NA} } },
	/* PPME_SYSCALL_UNLINKAT_X */{"unlinkat", EC_FILE, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_PREAD_E */{"pread", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 3, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"pos", PT_UINT64, PF_DEC} } },
	/* PPME_SYSCALL_PREAD_X */{"pread", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SYSCALL_PWRITE_E */{"pwrite", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 3, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"pos", PT_UINT64, PF_DEC} } },
	/* PPME_SYSCALL_PWRITE_X */{"pwrite", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SYSCALL_READV_E */{"readv", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 1, {{"fd", PT_FD, PF_DEC} } },
	/* PPME_SYSCALL_READV_X */{"readv", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 3, {{"res", PT_ERRNO, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SYSCALL_WRITEV_E */{"writev", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_WRITEV_X */{"writev", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SYSCALL_PREADV_E */{"preadv", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 2, {{"fd", PT_FD, PF_DEC}, {"pos", PT_UINT64, PF_DEC} } },
	/* PPME_SYSCALL_PREADV_X */{"preadv", EC_IO_READ, (enum ppm_event_flags)(EF_USES_FD | EF_READS_FROM_FD), 3, {{"res", PT_ERRNO, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SYSCALL_PWRITEV_E */{"pwritev", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 3, {{"fd", PT_FD, PF_DEC}, {"size", PT_UINT32, PF_DEC}, {"pos", PT_UINT64, PF_DEC} } },
	/* PPME_SYSCALL_PWRITEV_X */{"pwritev", EC_IO_WRITE, (enum ppm_event_flags)(EF_USES_FD | EF_WRITES_TO_FD), 2, {{"res", PT_ERRNO, PF_DEC}, {"data", PT_BYTEBUF, PF_NA} } },
	/* PPME_SYSCALL_DUP_E */{"dup", EC_IO_OTHER, (enum ppm_event_flags)(EF_CREATES_FD | EF_USES_FD | EF_MODIFIES_STATE), 1, {{"fd", PT_FD, PF_DEC} } },
	/* PPME_SYSCALL_DUP_X */{"dup", EC_IO_OTHER, (enum ppm_event_flags)(EF_CREATES_FD | EF_USES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC} } },
	/* PPME_SYSCALL_SIGNALFD_E */{"signalfd", EC_SIGNAL, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 3, {{"fd", PT_FD, PF_DEC}, {"mask", PT_UINT32, PF_HEX}, {"flags", PT_FLAGS8, PF_HEX} } },
	/* PPME_SYSCALL_SIGNALFD_X */{"signalfd", EC_SIGNAL, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC} } },
	/* PPME_SYSCALL_KILL_E */{"kill", EC_SIGNAL, EF_NONE, 2, {{"pid", PT_PID, PF_DEC}, {"sig", PT_SIGTYPE, PF_DEC} } },
	/* PPME_SYSCALL_KILL_X */{"kill", EC_SIGNAL, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_TKILL_E */{"tkill", EC_SIGNAL, EF_NONE, 2, {{"tid", PT_PID, PF_DEC}, {"sig", PT_SIGTYPE, PF_DEC} } },
	/* PPME_SYSCALL_TKILL_X */{"tkill", EC_SIGNAL, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_TGKILL_E */{"tgkill", EC_SIGNAL, EF_NONE, 3, {{"pid", PT_PID, PF_DEC}, {"tid", PT_PID, PF_DEC}, {"sig", PT_SIGTYPE, PF_DEC} } },
	/* PPME_SYSCALL_TGKILL_X */{"tgkill", EC_SIGNAL, EF_NONE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_NANOSLEEP_E */{"nanosleep", EC_SLEEP, EF_WAITS, 1, {{"interval", PT_RELTIME, PF_DEC} } },
	/* PPME_SYSCALL_NANOSLEEP_X */{"nanosleep", EC_SLEEP, EF_WAITS, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_TIMERFD_CREATE_E */{"timerfd_create", EC_TIME, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 2, {{"clockid", PT_UINT8, PF_DEC}, {"flags", PT_FLAGS8, PF_HEX} } },
	/* PPME_SYSCALL_TIMERFD_CREATE_X */{"timerfd_create", EC_TIME, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC} } },
	/* PPME_SYSCALL_INOTIFY_INIT_E */{"inotify_init", EC_IPC, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"flags", PT_FLAGS8, PF_HEX} } },
	/* PPME_SYSCALL_INOTIFY_INIT_X */{"inotify_init", EC_IPC, (enum ppm_event_flags)(EF_CREATES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC} } },
	/* PPME_SYSCALL_GETRLIMIT_E */{"getrlimit", EC_PROCESS, EF_NONE, 1, {{"resource", PT_FLAGS8, PF_DEC, rlimit_resources} } },
	/* PPME_SYSCALL_GETRLIMIT_X */{"getrlimit", EC_PROCESS, EF_NONE, 3, {{"res", PT_ERRNO, PF_DEC}, {"cur", PT_INT64, PF_DEC}, {"max", PT_INT64, PF_DEC} } },
	/* PPME_SYSCALL_SETRLIMIT_E */{"setrlimit", EC_PROCESS, EF_NONE, 1, {{"resource", PT_FLAGS8, PF_DEC, rlimit_resources} } },
	/* PPME_SYSCALL_SETRLIMIT_X */{"setrlimit", EC_PROCESS, EF_NONE, 3, {{"res", PT_ERRNO, PF_DEC}, {"cur", PT_INT64, PF_DEC}, {"max", PT_INT64, PF_DEC} } },
	/* PPME_SYSCALL_PRLIMIT_E */{"prlimit", EC_PROCESS, EF_NONE, 2, {{"pid", PT_PID, PF_DEC}, {"resource", PT_FLAGS8, PF_DEC, rlimit_resources} } },
	/* PPME_SYSCALL_PRLIMIT_X */{"prlimit", EC_PROCESS, EF_NONE, 5, {{"res", PT_ERRNO, PF_DEC}, {"newcur", PT_INT64, PF_DEC}, {"newmax", PT_INT64, PF_DEC}, {"oldcur", PT_INT64, PF_DEC}, {"oldmax", PT_INT64, PF_DEC} } },
	/* PPME_SCHEDSWITCH_1_E */{"switch", EC_SCHEDULER, (enum ppm_event_flags)(EF_SKIPPARSERESET | EF_OLD_VERSION), 1, {{"next", PT_PID, PF_DEC} } },
	/* PPME_SCHEDSWITCH_1_X */{"NA2", EC_SCHEDULER, (enum ppm_event_flags)(EF_SKIPPARSERESET | EF_UNUSED | EF_OLD_VERSION), 0},
	/* PPME_DROP_E */{"drop", EC_INTERNAL, EF_SKIPPARSERESET, 1, {{"ratio", PT_UINT32, PF_DEC} } },
	/* PPME_DROP_X */{"drop", EC_INTERNAL, EF_SKIPPARSERESET, 1, {{"ratio", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_FCNTL_E */{"fcntl", EC_IO_OTHER, (enum ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 2, {{"fd", PT_FD, PF_DEC}, {"cmd", PT_FLAGS8, PF_DEC, fcntl_commands} } },
	/* PPME_SYSCALL_FCNTL_X */{"fcntl", EC_IO_OTHER, (enum ppm_event_flags)(EF_USES_FD | EF_MODIFIES_STATE), 1, {{"res", PT_FD, PF_DEC} } },
	/* PPME_SCHEDSWITCH_6_E */{"switch", EC_SCHEDULER, EF_NONE, 6, {{"next", PT_PID, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC} } },
	/* PPME_SCHEDSWITCH_6_X */{"NA2", EC_SCHEDULER, EF_UNUSED, 0},
	/* PPME_SYSCALL_EXECVE_13_E */{"execve", EC_PROCESS, (enum ppm_event_flags)(EF_MODIFIES_STATE | EF_OLD_VERSION), 0},
	/* PPME_SYSCALL_EXECVE_13_X */{"execve", EC_PROCESS, (enum ppm_event_flags)(EF_MODIFIES_STATE | EF_OLD_VERSION), 13, {{"res", PT_ERRNO, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_UINT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC} } },
	/* PPME_CLONE_16_E */{"clone", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 0},
	/* PPME_CLONE_16_X */{"clone", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 16, {{"res", PT_PID, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_INT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"flags", PT_FLAGS32, PF_HEX, clone_flags}, {"uid", PT_UINT32, PF_DEC}, {"gid", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_BRK_4_E */{"brk", EC_MEMORY, EF_NONE, 1, {{"addr", PT_UINT64, PF_HEX} } },
	/* PPME_SYSCALL_BRK_4_X */{"brk", EC_MEMORY, EF_NONE, 4, {{"res", PT_UINT64, PF_HEX}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_MMAP_E */{"mmap", EC_MEMORY, EF_NONE, 6, {{"addr", PT_UINT64, PF_HEX}, {"length", PT_UINT64, PF_DEC}, {"prot", PT_FLAGS32, PF_HEX, prot_flags}, {"flags", PT_FLAGS32, PF_HEX, mmap_flags}, {"fd", PT_FD, PF_DEC}, {"offset", PT_UINT64, PF_DEC} } },
	/* PPME_SYSCALL_MMAP_X */{"mmap", EC_MEMORY, EF_NONE, 4, {{"res", PT_UINT64, PF_HEX}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_MMAP2_E */{"mmap2", EC_MEMORY, EF_NONE, 6, {{"addr", PT_UINT64, PF_HEX}, {"length", PT_UINT64, PF_DEC}, {"prot", PT_FLAGS32, PF_HEX, prot_flags}, {"flags", PT_FLAGS32, PF_HEX, mmap_flags}, {"fd", PT_FD, PF_DEC}, {"pgoffset", PT_UINT64, PF_DEC} } },
	/* PPME_SYSCALL_MMAP2_X */{"mmap2", EC_MEMORY, EF_NONE, 4, {{"res", PT_UINT64, PF_HEX}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_MUNMAP_E */{"munmap", EC_MEMORY, EF_NONE, 2, {{"addr", PT_UINT64, PF_HEX}, {"length", PT_UINT64, PF_DEC} } },
	/* PPME_SYSCALL_MUNMAP_X */{"munmap", EC_MEMORY, EF_NONE, 4, {{"res", PT_ERRNO, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_SPLICE_E */{"splice", EC_IO_OTHER, EF_USES_FD, 4, {{"fd_in", PT_FD, PF_DEC}, {"fd_out", PT_FD, PF_DEC}, {"size", PT_UINT64, PF_DEC}, {"flags", PT_FLAGS32, PF_HEX, splice_flags} } },
	/* PPME_SYSCALL_SPLICE_X */{"splice", EC_IO_OTHER, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_PTRACE_E */{"ptrace", EC_PROCESS, EF_NONE, 2, {{"request", PT_FLAGS16, PF_DEC, ptrace_requests}, {"pid", PT_PID, PF_DEC} } },
	/* PPME_SYSCALL_PTRACE_X */{"ptrace", EC_PROCESS, EF_NONE, 3, {{"res", PT_ERRNO, PF_DEC}, {"addr", PT_DYN, PF_HEX, ptrace_dynamic_param, PPM_PTRACE_IDX_MAX}, {"data", PT_DYN, PF_HEX, ptrace_dynamic_param, PPM_PTRACE_IDX_MAX} } },
	/* PPME_SYSCALL_IOCTL_3_E */{"ioctl", EC_IO_OTHER, EF_USES_FD, 3, {{"fd", PT_FD, PF_DEC}, {"request", PT_UINT64, PF_HEX}, {"argument", PT_UINT64, PF_HEX} } },
	/* PPME_SYSCALL_IOCTL_3_X */{"ioctl", EC_IO_OTHER, EF_USES_FD, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_EXECVE_14_E */{"execve", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 0},
	/* PPME_SYSCALL_EXECVE_14_X */{"execve", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 14, {{"res", PT_ERRNO, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_UINT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"env", PT_BYTEBUF, PF_NA} } },
	/* PPME_SYSCALL_RENAME_E */{"rename", EC_FILE, EF_NONE, 0 },
	/* PPME_SYSCALL_RENAME_X */{"rename", EC_FILE, EF_NONE, 3, {{"res", PT_ERRNO, PF_DEC}, {"oldpath", PT_FSPATH, PF_NA}, {"newpath", PT_FSPATH, PF_NA} } },
	/* PPME_SYSCALL_RENAMEAT_E */{"renameat", EC_FILE, EF_NONE, 0 },
	/* PPME_SYSCALL_RENAMEAT_X */{"renameat", EC_FILE, EF_NONE, 5, {{"res", PT_ERRNO, PF_DEC}, {"olddirfd", PT_FD, PF_DEC}, {"oldpath", PT_CHARBUF, PF_NA}, {"newdirfd", PT_FD, PF_DEC}, {"newpath", PT_CHARBUF, PF_NA} } },
	/* PPME_SYSCALL_SYMLINK_E */{"symlink", EC_FILE, EF_NONE, 0 },
	/* PPME_SYSCALL_SYMLINK_X */{"symlink", EC_FILE, EF_NONE, 3, {{"res", PT_ERRNO, PF_DEC}, {"target", PT_CHARBUF, PF_NA}, {"linkpath", PT_FSPATH, PF_NA} } },
	/* PPME_SYSCALL_SYMLINKAT_E */{"symlinkat", EC_FILE, EF_NONE, 0 },
	/* PPME_SYSCALL_SYMLINKAT_X */{"symlinkat", EC_FILE, EF_NONE, 4, {{"res", PT_ERRNO, PF_DEC}, {"target", PT_CHARBUF, PF_NA}, {"linkdirfd", PT_FD, PF_DEC}, {"linkpath", PT_CHARBUF, PF_NA} } },
	/* PPME_SYSCALL_FORK_E */{"fork", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 0},
	/* PPME_SYSCALL_FORK_X */{"fork", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 16, {{"res", PT_PID, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_INT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"flags", PT_FLAGS32, PF_HEX, clone_flags}, {"uid", PT_UINT32, PF_DEC}, {"gid", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_VFORK_E */{"vfork", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 0},
	/* PPME_SYSCALL_VFORK_X */{"vfork", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 16, {{"res", PT_PID, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_INT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"flags", PT_FLAGS32, PF_HEX, clone_flags}, {"uid", PT_UINT32, PF_DEC}, {"gid", PT_UINT32, PF_DEC} } },
	/* PPME_PROCEXIT_1_E */{"procexit", EC_PROCESS, EF_MODIFIES_STATE, 1, {{"status", PT_ERRNO, PF_DEC} } },
	/* PPME_NA1 */{"NA1", EC_PROCESS, EF_UNUSED, 0},
	/* PPME_SYSCALL_SENDFILE_E */{"sendfile", EC_IO_WRITE, EF_USES_FD, 4, {{"out_fd", PT_FD, PF_DEC}, {"in_fd", PT_FD, PF_DEC}, {"offset", PT_UINT64, PF_DEC}, {"size", PT_UINT64, PF_DEC} } },
	/* PPME_SYSCALL_SENDFILE_X */{"sendfile", EC_IO_WRITE, EF_USES_FD, 2, {{"res", PT_ERRNO, PF_DEC}, {"offset", PT_UINT64, PF_DEC} } },
	/* PPME_SYSCALL_QUOTACTL_E */{"quotactl", EC_USER, EF_NONE, 4, {{"cmd", PT_FLAGS16, PF_DEC, quotactl_cmds }, {"type", PT_FLAGS8, PF_DEC, quotactl_types}, {"id", PT_UINT32, PF_DEC}, {"quota_fmt", PT_FLAGS8, PF_DEC, quotactl_quota_fmts } } },
	/* PPME_SYSCALL_QUOTACTL_X */{"quotactl", EC_USER, EF_NONE, 14, {{"res", PT_ERRNO, PF_DEC}, {"special", PT_CHARBUF, PF_NA }, {"quotafilepath", PT_CHARBUF, PF_NA}, {"dqb_bhardlimit", PT_UINT64, PF_DEC }, {"dqb_bsoftlimit", PT_UINT64, PF_DEC }, {"dqb_curspace", PT_UINT64, PF_DEC }, {"dqb_ihardlimit", PT_UINT64, PF_DEC }, {"dqb_isoftlimit", PT_UINT64, PF_DEC }, {"dqb_btime", PT_RELTIME, PF_DEC }, {"dqb_itime", PT_RELTIME, PF_DEC }, {"dqi_bgrace", PT_RELTIME, PF_DEC }, {"dqi_igrace", PT_RELTIME, PF_DEC }, {"dqi_flags", PT_FLAGS8, PF_DEC, quotactl_dqi_flags }, {"quota_fmt_out", PT_FLAGS8, PF_DEC, quotactl_quota_fmts } } },
	/* PPME_SYSCALL_SETRESUID_E */ {"setresuid", EC_USER, EF_MODIFIES_STATE, 3, {{"ruid", PT_UID, PF_DEC }, {"euid", PT_UID, PF_DEC }, {"suid", PT_UID, PF_DEC } } },
	/* PPME_SYSCALL_SETRESUID_X */ {"setresuid", EC_USER, EF_MODIFIES_STATE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_SETRESGID_E */ {"setresgid", EC_USER, EF_MODIFIES_STATE, 3, {{"rgid", PT_GID, PF_DEC }, {"egid", PT_GID, PF_DEC }, {"sgid", PT_GID, PF_DEC } } },
	/* PPME_SYSCALL_SETRESGID_X */ {"setresgid", EC_USER, EF_MODIFIES_STATE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSDIGEVENT_E */{"sysdigevent", EC_INTERNAL, EF_SKIPPARSERESET, 2, {{"event_type", PT_UINT32, PF_DEC}, {"event_data", PT_UINT64, PF_DEC} } },
	/* PPME_NA1 */{"NA1", EC_INTERNAL, EF_UNUSED, 0},
	/* PPME_SYSCALL_SETUID_E */ {"setuid", EC_USER, EF_MODIFIES_STATE, 1, {{"uid", PT_UID, PF_DEC} } },
	/* PPME_SYSCALL_SETUID_X */ {"setuid", EC_USER, EF_MODIFIES_STATE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_SETGID_E */ {"setgid", EC_USER, EF_MODIFIES_STATE, 1, {{"gid", PT_GID, PF_DEC} } },
	/* PPME_SYSCALL_SETGID_X */ {"setgid", EC_USER, EF_MODIFIES_STATE, 1, {{"res", PT_ERRNO, PF_DEC} } },
	/* PPME_SYSCALL_GETUID_E */ {"getuid", EC_USER, EF_NONE, 0},
	/* PPME_SYSCALL_GETUID_X */ {"getuid", EC_USER, EF_NONE, 1, {{"uid", PT_UID, PF_DEC} } },
	/* PPME_SYSCALL_GETEUID_E */ {"geteuid", EC_USER, EF_NONE, 0 },
	/* PPME_SYSCALL_GETEUID_X */ {"geteuid", EC_USER, EF_NONE, 1, {{"euid", PT_UID, PF_DEC} } },
	/* PPME_SYSCALL_GETGID_E */ {"getgid", EC_USER, EF_NONE, 0},
	/* PPME_SYSCALL_GETGID_X */ {"getgid", EC_USER, EF_NONE, 1, {{"gid", PT_GID, PF_DEC} } },
	/* PPME_SYSCALL_GETEGID_E */ {"getegid", EC_USER, EF_NONE, 0 },
	/* PPME_SYSCALL_GETEGID_X */ {"getegid", EC_USER, EF_NONE, 1, {{"egid", PT_GID, PF_DEC} } },
	/* PPME_SYSCALL_GETRESUID_E */ {"getresuid", EC_USER, EF_NONE, 0 },
	/* PPME_SYSCALL_GETRESUID_X */ {"getresuid", EC_USER, EF_NONE, 4, {{"res", PT_ERRNO, PF_DEC}, {"ruid", PT_UID, PF_DEC }, {"euid", PT_UID, PF_DEC }, {"suid", PT_UID, PF_DEC } } },
	/* PPME_SYSCALL_GETRESGID_E */ {"getresgid", EC_USER, EF_NONE, 0 },
	/* PPME_SYSCALL_GETRESGID_X */ {"getresgid", EC_USER, EF_NONE, 4, {{"res", PT_ERRNO, PF_DEC}, {"rgid", PT_GID, PF_DEC }, {"egid", PT_GID, PF_DEC }, {"sgid", PT_GID, PF_DEC } } },
	/* PPME_SYSCALL_EXECVE_15_E */{"execve", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 0},
	/* PPME_SYSCALL_EXECVE_15_X */{"execve", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 15, {{"res", PT_ERRNO, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_UINT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"comm", PT_CHARBUF, PF_NA}, {"env", PT_BYTEBUF, PF_NA} } },
	/* PPME_CLONE_17_E */{"clone", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 0},
	/* PPME_CLONE_17_X */{"clone", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 17, {{"res", PT_PID, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_INT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"comm", PT_CHARBUF, PF_NA}, {"flags", PT_FLAGS32, PF_HEX, clone_flags}, {"uid", PT_UINT32, PF_DEC}, {"gid", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_FORK_17_E */{"fork", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 0},
	/* PPME_SYSCALL_FORK_17_X */{"fork", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 17, {{"res", PT_PID, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_INT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"comm", PT_CHARBUF, PF_NA}, {"flags", PT_FLAGS32, PF_HEX, clone_flags}, {"uid", PT_UINT32, PF_DEC}, {"gid", PT_UINT32, PF_DEC} } },
	/* PPME_SYSCALL_VFORK_17_E */{"vfork", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 0},
	/* PPME_SYSCALL_VFORK_17_X */{"vfork", EC_PROCESS, EF_MODIFIES_STATE | EF_OLD_VERSION, 17, {{"res", PT_PID, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_INT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"comm", PT_CHARBUF, PF_NA}, {"flags", PT_FLAGS32, PF_HEX, clone_flags}, {"uid", PT_UINT32, PF_DEC}, {"gid", PT_UINT32, PF_DEC} } },
	/* PPME_CLONE_20_E */{"clone", EC_PROCESS, EF_MODIFIES_STATE, 0},
	/* PPME_CLONE_20_X */{"clone", EC_PROCESS, EF_MODIFIES_STATE, 20, {{"res", PT_PID, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_INT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"comm", PT_CHARBUF, PF_NA}, {"cgroups", PT_BYTEBUF, PF_NA}, {"flags", PT_FLAGS32, PF_HEX, clone_flags}, {"uid", PT_UINT32, PF_DEC}, {"gid", PT_UINT32, PF_DEC}, {"vtid", PT_PID, PF_DEC}, {"vpid", PT_PID, PF_DEC} } },
	/* PPME_SYSCALL_FORK_20_E */{"fork", EC_PROCESS, EF_MODIFIES_STATE, 0},
	/* PPME_SYSCALL_FORK_20_X */{"fork", EC_PROCESS, EF_MODIFIES_STATE, 20, {{"res", PT_PID, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_INT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"comm", PT_CHARBUF, PF_NA}, {"cgroups", PT_BYTEBUF, PF_NA}, {"flags", PT_FLAGS32, PF_HEX, clone_flags}, {"uid", PT_UINT32, PF_DEC}, {"gid", PT_UINT32, PF_DEC}, {"vtid", PT_PID, PF_DEC}, {"vpid", PT_PID, PF_DEC} } },
	/* PPME_SYSCALL_VFORK_20_E */{"vfork", EC_PROCESS, EF_MODIFIES_STATE, 0},
	/* PPME_SYSCALL_VFORK_20_X */{"vfork", EC_PROCESS, EF_MODIFIES_STATE, 20, {{"res", PT_PID, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_INT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"comm", PT_CHARBUF, PF_NA}, {"cgroups", PT_BYTEBUF, PF_NA}, {"flags", PT_FLAGS32, PF_HEX, clone_flags}, {"uid", PT_UINT32, PF_DEC}, {"gid", PT_UINT32, PF_DEC}, {"vtid", PT_PID, PF_DEC}, {"vpid", PT_PID, PF_DEC} } },
	/* PPME_CONTAINER_E */{"container", EC_INTERNAL, EF_SKIPPARSERESET | EF_MODIFIES_STATE, 4, {{"id", PT_CHARBUF, PF_NA}, {"type", PT_UINT32, PF_DEC}, {"name", PT_CHARBUF, PF_NA}, {"image", PT_CHARBUF, PF_NA} } },
	/* PPME_CONTAINER_X */{"container", EC_INTERNAL, EF_UNUSED, 0},
	/* PPME_SYSCALL_EXECVE_16_E */{"execve", EC_PROCESS, EF_MODIFIES_STATE, 0},
	/* PPME_SYSCALL_EXECVE_16_X */{"execve", EC_PROCESS, EF_MODIFIES_STATE, 16, {{"res", PT_ERRNO, PF_DEC}, {"exe", PT_CHARBUF, PF_NA}, {"args", PT_BYTEBUF, PF_NA}, {"tid", PT_PID, PF_DEC}, {"pid", PT_PID, PF_DEC}, {"ptid", PT_PID, PF_DEC}, {"cwd", PT_CHARBUF, PF_NA}, {"fdlimit", PT_UINT64, PF_DEC}, {"pgft_maj", PT_UINT64, PF_DEC}, {"pgft_min", PT_UINT64, PF_DEC}, {"vm_size", PT_UINT32, PF_DEC}, {"vm_rss", PT_UINT32, PF_DEC}, {"vm_swap", PT_UINT32, PF_DEC}, {"comm", PT_CHARBUF, PF_NA}, {"cgroups", PT_BYTEBUF, PF_NA}, {"env", PT_BYTEBUF, PF_NA} } },
	/* PPME_PROCINFO_E */{"procinfo", EC_USER, EF_NONE, 3, {{"pid", PT_PID, PF_DEC}, {"cpu_usr", PT_UINT64, PF_DEC}, {"cpu_sys", PT_UINT64, PF_DEC} } },
	/* PPME_PROCINFO_X */{"NA2", EC_USER, EF_UNUSED, 0},
};
