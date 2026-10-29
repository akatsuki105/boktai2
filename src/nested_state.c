#include "nested_state.h"

#include "global.h"

void NestedState_Reset0(NestedState* s) {
  s->state0 = s->state1 = s->state2 = 0;
  s->timer0 = s->timer1 = s->timer2 = 0;
}

void NestedState_Set0(NestedState* s, u8 state) {
  s->state0 = state;
  s->state1 = s->state2 = 0;
  s->timer0 = s->timer1 = s->timer2 = 0;
}

void NestedState_Advance0(NestedState* s) {
  s->state0++;
  s->state1 = s->state2 = 0;
  s->timer0 = s->timer1 = s->timer2 = 0;
}

void NestedState_Reset1(NestedState* s) {
  s->state1 = s->state2 = 0;
  s->timer1 = s->timer2 = 0;
}

void NestedState_Set1(NestedState* s, u8 state) {
  s->state1 = state;
  s->state2 = 0;
  s->timer1 = s->timer2 = 0;
}

void NestedState_Advance1(NestedState* s) {
  s->state1++;
  s->state2 = 0;
  s->timer1 = s->timer2 = 0;
}

void NestedState_Reset2(NestedState* s) {
  s->state2 = 0;
  s->timer2 = 0;
}

void NestedState_Set2(NestedState* s, u8 state) {
  s->state2 = state;
  s->timer2 = 0;
}

void NestedState_Advance2(NestedState* s) {
  s->state2++;
  s->timer2 = 0;
}
