#include <malloc.h>
#include "struct.h"

const size_ DOUBLE_FREE  = 0;
const size_ SUCCESS_FREE = 1;

size_
___free_str___(str *restrict self)
{
  if (self->is_free)
    return DOUBLE_FREE;

  free(self->c_str);
  self->is_free = 1;
  return SUCCESS_FREE;
}
