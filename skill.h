#ifndef SKILL_H
#define SKILL_H

#include "typebentukan.h"
#include "queue.h"
#include "array.h"
#include "stack.h"
#include "command.h"

void InstantUpgrade(PLAYER Pl, TabBang *Bang);

void Shield (PLAYER *Pl);

void ExtraTurn (boolean *ET);

void AttackUp(PLAYER *Pl);

void CriticalHit(PLAYER *Pl);

void InstantReinforcement(PLAYER Pl, TabBang *Bang);

void Barrage(PLAYER Enemy,TabBang *Bang);

void UseSkill(Queue *Skill, PLAYER Pl, PLAYER Enemy, TabBang *Bang, boolean *ET);

#endif