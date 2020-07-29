#include "CyclicBarrier.h"
#include <pthread.h>


int cyclic_barrier_await(cyclic_barrier_t* CycBarrier)
{
  pthread_mutex_lock(&(CycBarrier->barrier_mutex));

  CycBarrier->outstanding = CycBarrier->outstanding - 1;

  if (0 != CycBarrier->outstanding) {
    pthread_cond_wait(&(CycBarrier->barrier_cond), &(CycBarrier->barrier_mutex));
  } else {
    (CycBarrier->barrier_action)();
    CycBarrier->outstanding = CycBarrier->participants;
    pthread_cond_broadcast(&(CycBarrier->barrier_cond));
  }

  pthread_mutex_unlock(&(CycBarrier->barrier_mutex));

  return 0;
}


int cyclic_barrier_init(cyclic_barrier_t* CycBarrier, pthread_mutexattr_t* threadMutex, pthread_condattr_t* threadCond,  int participants, void (*barrier_action)(void)) {
  pthread_mutex_init(&(barrier->barrier_mutex), threadMutex);
  pthread_cond_init(&(barrier->barrier_cond), threadCond);
  barrier->participants = participants;
  barrier->outstanding = participants;
  barrier->barrier_action = barrier_action;

  return 0;
}

int cyclic_barrier_destroy(cyclic_barrier_t* CycBarrier)
{
  pthread_mutex_destroy(&(CycBarrier->barrier_mutex));
  pthread_cond_destroy(&(CycBarrier->barrier_cond));

  return 0;
}
