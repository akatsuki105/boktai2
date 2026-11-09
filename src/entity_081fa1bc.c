#include "entity.h"
#include "global.h"
#include "particle.h"

// 不使用
// 粒子1個を出して 301 フレーム数えたら自分を消すだけのエンティティ
// 呼び出し元がリポジトリにも Ghidra にも無く, CreateEntity も見つからないため 80 バイトは下限
typedef struct Entity081fa1bc {
  Entity e;              // 0x00
  Particle ptcl;         // 0x18, pos は _Init の第2引数の写し, 初期コマは 0x20, offset は (-8, -8)
  ParticleGroup* group;  // 0x40, PTCL_GROUP_0
  s16 timer;             // 0x44, 毎フレーム +1, 300 を超えると KillEntity する
  Vec3 pos;              // 0x48, '_Init' の第2引数の写し, ptcl.pos の初期値
} Entity081fa1bc;
static_assert(sizeof(Entity081fa1bc) == 80);

const STRING_DATA char s_eneinline_082523f8[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252414[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252430[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_0825244c[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252468[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252484[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_082524a0[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_082524bc[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_082524d8[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_082524f4[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252510[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_0825252c[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252548[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252564[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252580[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_0825259c[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_082525b8[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_082525d4[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_082525f0[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_0825260c[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252628[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252644[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252660[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_0825267c[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eff_eff_00_08252698[] = "eff_eff_00";  // 0x08252698

NAKED s32 Entity081fa1bc_Init(Entity081fa1bc* p, Vec3* pos) { INCFUNC("asm/func/Entity081fa1bc_Init.inc"); }

NAKED s32 Entity081fa1bc_Destroy(Entity081fa1bc* p) { INCFUNC("asm/func/Entity081fa1bc_Destroy.inc"); }

NAKED s32 Entity081fa1bc_Update(Entity081fa1bc* p) { INCFUNC("asm/func/Entity081fa1bc_Update.inc"); }
