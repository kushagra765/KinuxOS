#ifndef _VFS_H
#define _VFS_H

/* fs/vfs/vfs.h
 * Author - @kushagra765
 */

#include <stdint.h>

typedef struct node_vfs {
   char fname[50];
   uint32_t uid;
   uint32_t gid;
   uint32_t file_len;
   uint32_t flags;
   uint32_t permission;
   read_vfs_t read;
} node_vfs_t;

struct dirent_vfs {
   char fname[50];
   uint32_t inode_num;
};

typedef uint32_t (*read_vfs_t)(struct node_vfs*, uint32_t, uint32_t, uint8_t);
uint32_t read_vfs(node_vfs_t *node, uint32_t offset, uint32_t f_size, uint8_t *buf);

node_vfs_t *vfs_root;

#endif //_VFS_H
