//   __  __            _     _            
//  |  \/  | __ _  ___| |__ (_)_ __   ___ 
//  | |\/| |/ _` |/ __| '_ \| | '_ \ / _ \
//  | |  | | (_| | (__| | | | | | | |  __/
//  |_|  |_|\__,_|\___|_| |_|_|_| |_|\___|
                                       
#include "machine.h"

typedef struct machine
{
  data_t A, tq, error; // tq = sampling time
  point_t *zero, *offset;
} machine_t;

// Lifecycle
machine_t *machine_new(const char *ini_path) {
  machine_t *m = (machine_t *)calloc(1, sizeof(machine_t));
  if(!m){
    perror("Error creating machine object");
    exit(EXIT_FAILURE);
  }
  if(ini_path){ // load value from INI file
    // TODO Parse the INI file
  } else { // provide some default value
    m->A = 125;
    m->error = 0.005;
    m->tq = 0.005;
    m->zero = point_new();
    point_set_xyz(m->zero, 0, 0, 0);
    m->offset = point_new();
    point_set_xyz(m->offset, 0, 0, 0);
  }
  return m;
}
void machine_free(machine_t *m) {
  assert(m);
  point_free(m->zero);
  point_free(m->offset);
  free(m);
  m = NULL;
}

// Accessors
data_t machine_A(machine_t *m) { assert(m); return m->A; }

data_t machine_tq(machine_t *m) { assert(m); return m->tq; }

point_t *machine_zero(machine_t *m) { assert(m); return m->zero; }

point_t *machien_offset(machine_t *m) { assert(m); return m->offset; }

data_t machien_error(machine_t *m) { assert(m); return m->error; }