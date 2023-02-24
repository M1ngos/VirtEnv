#include <stdio.h>
#include <stdbool.h>
#include "instruc_set.h"

int pc = 0;
int sp = -1;
int stack[256];
bool running = true;

int fetch(){
  return program[pc];
}

void evaluation(int instr) {
  switch (instr) {
    
    case HLT:
      running = false;
      break;
    
    case PSH:
      sp++;
      stack[sp] = program[++pc];
      break;
  }
}

int main() {
    while (running) {
       evaluation(fetch());
       pc++;
    }
}

