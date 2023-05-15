#ifndef PRODUCER_CONSUMER_H
#define PRODUCER_CONSUMER_H

#include <iostream>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

const char *const SEM_FULL_NAME = "/sem_full";
const char *const SEM_EMPTY_NAME = "/sem_empty";
const char *const SHM_NAME = "/shm_buffer";

struct SharedBuffer {
    int data[10];
    int read_idx;
    int write_idx;
};

#endif // PRODUCER_CONSUMER_HPP
