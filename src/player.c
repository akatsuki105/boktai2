#include "player.h"

#include "global.h"
#include "item.h"

void FUN_082318ac(s32 r0, s32 r1);

s32 GetPlayerCoffinID(void) {
  s32 slot;
  for (slot = 0; slot < VALUABLE_CAP; slot++) {
    u32 itemID = GetValuableItemID(slot);
    if ((itemID - ITEM_OAK_COFFIN) < COFFIN_NUM) {
      return itemID - ITEM_OAK_COFFIN;
    }
  }
  return COFFIN_OAK;
}

NAKED void FUN_08060e90(struct Player* p, u32 r1) {
  asm(".syntax unified\n\
	push {lr}\n\
	sub sp, #0xc\n\
	adds r3, r1, #0\n\
	ldr r1, _08060EC0 @ =0x000009C4\n\
	adds r0, r0, r1\n\
	ldr r2, [r0]\n\
	cmp r2, #0\n\
	beq _08060EBA\n\
	ldr r1, _08060EC4 @ =0xFFFF0000\n\
	ldr r0, [sp, #4]\n\
	ands r0, r1\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	str r0, [sp, #4]\n\
	str r3, [sp]\n\
	add r1, sp, #4\n\
	mov r0, sp\n\
	str r0, [r1, #4]\n\
	adds r0, r2, #0\n\
	bl FUN_082318ac\n\
_08060EBA:\n\
	add sp, #0xc\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08060EC0: .4byte 0x000009C4\n\
_08060EC4: .4byte 0xFFFF0000\n\
 .syntax divided\n");
}

void FUN_08060ec8(struct Player* p, u32 r1) {
  p->unk_9bc |= r1;
  return;
}

u32 FUN_08060ed8(struct Player* p, u32 r1) { return p->unk_9bc & r1; }

void FUN_08060ee8(struct Player* p) {
  if (p->unk_9c0 != 0) {
    FUN_082318ac(p->unk_9c0, 0);
  }
}

NAKED void FUN_08060f00(struct Player* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	movs r1, #0xd6\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #5\n\
	beq _08060F44\n\
	ldr r0, _08060F40 @ =0x030046A0\n\
	ldr r0, [r0]\n\
	adds r1, #4\n\
	adds r2, r5, r1\n\
	adds r1, r0, #0\n\
	adds r1, #0x18\n\
	movs r4, #0x63\n\
	movs r3, #3\n\
_08060F20:\n\
	ldrh r0, [r1, #8]\n\
	ldrh r5, [r1]\n\
	adds r0, r0, r5\n\
	strh r0, [r2]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x63\n\
	bls _08060F32\n\
	strh r4, [r2]\n\
_08060F32:\n\
	adds r2, #2\n\
	adds r1, #2\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _08060F20\n\
	b _08060F9A\n\
	.align 2, 0\n\
_08060F40: .4byte 0x030046A0\n\
_08060F44:\n\
	ldr r7, _08060FA0 @ =0x030046A0\n\
	ldr r0, [r7]\n\
	adds r0, #0x40\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	adds r0, #0xa\n\
	cmp r0, #0x63\n\
	ble _08060F56\n\
	movs r0, #0x63\n\
_08060F56:\n\
	subs r0, #1\n\
	lsls r4, r0, #1\n\
	adds r4, r4, r0\n\
	adds r0, r4, #0\n\
	movs r1, #4\n\
	bl Div\n\
	lsls r1, r0, #2\n\
	subs r4, r4, r1\n\
	adds r6, r0, #0\n\
	adds r6, #0xa\n\
	movs r0, #0xd7\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	ldr r2, [r7]\n\
	movs r5, #0x63\n\
	movs r3, #3\n\
_08060F78:\n\
	ldrh r0, [r2, #0x20]\n\
	adds r0, r0, r6\n\
	strh r0, [r1]\n\
	cmp r4, #0\n\
	ble _08060F88\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	subs r4, #1\n\
_08060F88:\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x63\n\
	bls _08060F90\n\
	strh r5, [r1]\n\
_08060F90:\n\
	adds r1, #2\n\
	adds r2, #2\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _08060F78\n\
_08060F9A:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08060FA0: .4byte 0x030046A0\n\
 .syntax divided\n");
}

s32 CalcMaxHP(struct Player* p) {
  s32 val;
  struct Player_264* unk264 = &p->unk_264;
  if (p->kind == PLAYER_SOLAR_DJANGO) {
    val = (p->unk_35c + unk264->unk_26c) + unk264->unk_274;
  } else {
    val = (p->unk_35c + unk264->unk_26c) - unk264->unk_274;
  }
  if (99 < val) {
    val = 99;
  }
  return val * 10;
}

s32 CalcMaxEne(struct Player* p) {
  s32 val;
  struct Player_264* unk264 = &p->unk_264;
  if (u32_030047a4 & 0x1000) {
    return 10;
  }

  if (p->kind == PLAYER_SOLAR_DJANGO) {
    val = (p->unk_35e + unk264->unk_26e) + unk264->unk_276;
  } else {
    val = (p->unk_35e + unk264->unk_26e) - unk264->unk_276;
  }
  if (99 < val) {
    val = 99;
  }
  return val * 5 + 100;
}

void UpdateMaxHPEne(struct Player* p) {
  s32 maxHP, maxEne;

  maxHP = CalcMaxHP(p);
  p->maxHP = maxHP;
  if (p->hp > (u16)maxHP) {
    p->hp = maxHP;
  }

  maxEne = CalcMaxEne(p);
  p->maxEne = maxEne;
  if (p->ene > (u16)maxEne) {
    p->ene = maxEne;
  }
}

NAKED void FUN_080610a4(struct Player* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	bl CalcMaxHP\n\
	ldr r1, _080610C8 @ =0x00000366\n\
	adds r5, r4, r1\n\
	strh r0, [r5]\n\
	movs r0, #0x6c\n\
	movs r1, #0\n\
	bl FUN_0823174c\n\
	cmp r0, #0\n\
	beq _080610CC\n\
	ldrh r1, [r5]\n\
	movs r2, #0xd9\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	b _080610F8\n\
	.align 2, 0\n\
_080610C8: .4byte 0x00000366\n\
_080610CC:\n\
	movs r3, #0xd6\n\
	lsls r3, r3, #2\n\
	adds r0, r4, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #5\n\
	bne _080610EC\n\
	ldr r0, _080610E8 @ =0x030046A0\n\
	ldr r0, [r0]\n\
	ldrh r1, [r0, #0x38]\n\
	movs r2, #0xd9\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	b _080610F8\n\
	.align 2, 0\n\
_080610E8: .4byte 0x030046A0\n\
_080610EC:\n\
	ldr r0, _0806110C @ =0x030046A0\n\
	ldr r0, [r0]\n\
	ldrh r1, [r0, #0x28]\n\
	movs r3, #0xd9\n\
	lsls r3, r3, #2\n\
	adds r0, r4, r3\n\
_080610F8:\n\
	strh r1, [r0]\n\
	movs r0, #0xd9\n\
	lsls r0, r0, #2\n\
	adds r1, r4, r0\n\
	ldrh r2, [r1]\n\
	cmp r2, #0\n\
	bne _08061110\n\
	movs r0, #1\n\
	b _0806111A\n\
	.align 2, 0\n\
_0806110C: .4byte 0x030046A0\n\
_08061110:\n\
	ldr r3, _08061140 @ =0x00000366\n\
	adds r0, r4, r3\n\
	ldrh r0, [r0]\n\
	cmp r2, r0\n\
	bls _0806111C\n\
_0806111A:\n\
	strh r0, [r1]\n\
_0806111C:\n\
	adds r0, r4, #0\n\
	bl CalcMaxEne\n\
	ldr r1, _08061144 @ =0x0000036A\n\
	adds r5, r4, r1\n\
	strh r0, [r5]\n\
	movs r0, #0x65\n\
	movs r1, #0\n\
	bl FUN_0823174c\n\
	cmp r0, #0\n\
	beq _08061148\n\
	ldrh r1, [r5]\n\
	movs r2, #0xda\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	b _08061174\n\
	.align 2, 0\n\
_08061140: .4byte 0x00000366\n\
_08061144: .4byte 0x0000036A\n\
_08061148:\n\
	movs r3, #0xd6\n\
	lsls r3, r3, #2\n\
	adds r0, r4, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #5\n\
	bne _08061168\n\
	ldr r0, _08061164 @ =0x030046A0\n\
	ldr r0, [r0]\n\
	ldrh r1, [r0, #0x3a]\n\
	movs r2, #0xda\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	b _08061174\n\
	.align 2, 0\n\
_08061164: .4byte 0x030046A0\n\
_08061168:\n\
	ldr r0, _08061190 @ =0x030046A0\n\
	ldr r0, [r0]\n\
	ldrh r1, [r0, #0x2c]\n\
	movs r3, #0xda\n\
	lsls r3, r3, #2\n\
	adds r0, r4, r3\n\
_08061174:\n\
	strh r1, [r0]\n\
	movs r0, #0xda\n\
	lsls r0, r0, #2\n\
	adds r2, r4, r0\n\
	ldr r1, _08061194 @ =0x0000036A\n\
	adds r0, r4, r1\n\
	ldrh r1, [r0]\n\
	ldrh r0, [r2]\n\
	cmp r0, r1\n\
	bls _0806118A\n\
	strh r1, [r2]\n\
_0806118A:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08061190: .4byte 0x030046A0\n\
_08061194: .4byte 0x0000036A\n\
 .syntax divided\n");
}

NAKED void FUN_08061198(struct Player* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov ip, r0\n\
	movs r5, #0x99\n\
	lsls r5, r5, #2\n\
	add r5, ip\n\
	movs r0, #0xd6\n\
	lsls r0, r0, #2\n\
	add r0, ip\n\
	ldrb r1, [r0]\n\
	cmp r1, #5\n\
	bne _080611D4\n\
	ldr r0, _080611CC @ =0x030046A0\n\
	ldr r0, [r0]\n\
	adds r0, #0x40\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	adds r4, r0, #0\n\
	adds r4, #0xa\n\
	cmp r4, #0x63\n\
	ble _080611C2\n\
	movs r4, #0x63\n\
_080611C2:\n\
	ldr r0, _080611D0 @ =0x00000362\n\
	add r0, ip\n\
	ldrh r1, [r0]\n\
	b _0806121C\n\
	.align 2, 0\n\
_080611CC: .4byte 0x030046A0\n\
_080611D0: .4byte 0x00000362\n\
_080611D4:\n\
	ldr r0, _08061204 @ =0x030046A0\n\
	ldr r0, [r0]\n\
	adds r0, #0x40\n\
	movs r2, #0\n\
	ldrsh r4, [r0, r2]\n\
	cmp r1, #0\n\
	bne _0806120C\n\
	ldr r0, _08061208 @ =0x00000362\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	ldrh r1, [r5, #0xe]\n\
	adds r0, r0, r1\n\
	movs r2, #0x16\n\
	ldrsh r1, [r5, r2]\n\
	adds r1, r0, r1\n\
	movs r0, #0x9f\n\
	lsls r0, r0, #2\n\
	add r0, ip\n\
	ldr r2, [r0]\n\
	movs r0, #1\n\
	orrs r2, r0\n\
	movs r6, #2\n\
	b _0806122A\n\
	.align 2, 0\n\
_08061204: .4byte 0x030046A0\n\
_08061208: .4byte 0x00000362\n\
_0806120C:\n\
	ldr r0, _08061284 @ =0x00000362\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	ldrh r1, [r5, #0xe]\n\
	adds r0, r0, r1\n\
	movs r2, #0x16\n\
	ldrsh r1, [r5, r2]\n\
	subs r1, r0, r1\n\
_0806121C:\n\
	movs r0, #0x9f\n\
	lsls r0, r0, #2\n\
	add r0, ip\n\
	ldr r2, [r0]\n\
	movs r0, #2\n\
	orrs r2, r0\n\
	movs r6, #1\n\
_0806122A:\n\
	ldr r0, _08061288 @ =0x00000446\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	movs r3, #0\n\
	cmp r0, #0\n\
	beq _08061242\n\
	ldr r0, _0806128C @ =0x00000442\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	cmp r0, #8\n\
	bne _08061242\n\
	movs r3, #1\n\
_08061242:\n\
	cmp r3, #0\n\
	bne _08061252\n\
	movs r0, #0x9f\n\
	lsls r0, r0, #2\n\
	add r0, ip\n\
	ldr r0, [r0]\n\
	cmp r0, #0x40\n\
	bne _08061254\n\
_08061252:\n\
	movs r2, #0x40\n\
_08061254:\n\
	cmp r1, #0x63\n\
	ble _0806125A\n\
	movs r1, #0x63\n\
_0806125A:\n\
	adds r0, r1, r4\n\
	asrs r0, r0, #1\n\
	ldrh r5, [r5, #2]\n\
	adds r1, r0, r5\n\
	movs r0, #0xd6\n\
	lsls r0, r0, #2\n\
	add r0, ip\n\
	ldrb r0, [r0]\n\
	cmp r0, #5\n\
	bne _08061272\n\
	ldr r0, _08061290 @ =0x03002B74\n\
	strh r1, [r0]\n\
_08061272:\n\
	movs r0, #0xb6\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	adds r3, r6, #0\n\
	bl FUN_08236514\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08061284: .4byte 0x00000362\n\
_08061288: .4byte 0x00000446\n\
_0806128C: .4byte 0x00000442\n\
_08061290: .4byte 0x03002B74\n\
 .syntax divided\n");
}

void FUN_08061294(struct Player* p) {
  FUN_080610a4(p);
  FUN_08061198(p);
}

void FUN_080612a8(struct Player* p) {
  UpdateMaxHPEne(p);
  FUN_08061198(p);
}

void FUN_080612bc(struct Player* p) {
  FUN_08060f00(p);
  UpdateMaxHPEne(p);
  FUN_08061198(p);
}
