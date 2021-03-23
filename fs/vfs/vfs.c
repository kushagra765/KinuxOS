/* fs/vfs/vfs.c
 * Author - @kushagra765
 */

#include "vfs.h"
#include <stdint.h>

node_vfs_t *vfs_root = 0;

uint32_t read_vfs(node_vfs_t *node, uint32_t offset, uint32_t f_size, uint8_t *buf) {
    
    if (node->read == 1) {
      return node->read(node, offset, f_size, buf);
    }
    else {
      return 0;
    }
}
