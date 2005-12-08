/* Use new style mmap for mips */
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/syscall.h>

#if 0
/* For now, leave mmap using mmap1 since mmap2 seems
 * to have issues (i.e. it doesn't work 100% properly).
 */
#ifdef __NR_mmap2
# undef __NR_mmap
# define __NR_mmap __NR_mmap2
#endif
#endif

#define __NR___mmap __NR_mmap
attribute_hidden _syscall6 (__ptr_t, __mmap, __ptr_t, addr, size_t, len, int, prot,
	   int, flags, int, fd, __off_t, offset);
strong_alias(__mmap,mmap)
