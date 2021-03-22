#ifndef _VFS_H
#define _VFS_H

/* fs/vfs/vfs.h
 * Author - @kushagra765
 */

#include <stdint.h>

struct node_vfs {
   char fname[50];
   uint32_t uid;
   uint32_t gid;
   uint32_t file_len;
   uint32_t flags;
   uint32_t permission;
};

#endif //_VFS_H
