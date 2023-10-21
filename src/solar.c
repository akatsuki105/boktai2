#include "entity.h"
#include "global.h"
#include "time.h"

s32 FUN_082477e0(void);
void FUN_082477b4(void);

s32 FUN_082418c0(void) {
  s32 n = FUN_082477e0();
  if ((n < 0) || (n > gUnkPtr_030047a8->unk_4)) {
    return 0;
  }

  n = gUnkPtr_030047a8->unk_4 - n;
  if (n > 0x8B) {
    return 0x8C;
  }
  return n;
}

void SetOverheatTime(void) {
  (GAME->overheatTime).date.date = GetDate();
  (GAME->overheatTime).hour = GetHour();
  (GAME->overheatTime).minute = GetMinute();
  (GAME->overheatTime).second = GetSecond();
}

NAKED bool32 IsGunCooled(void) {
  // TODO
  INCCODE("asm/todo/IsGunCooled.inc");
}

WIP void overheat_08241a04(struct Entity5 *_ UNUSED) {
#if MODERN
  if (GAME->thermal > 29999) {
    if ((GAME->unk_942 < 3) || (GAME->unk_934 & 0x4200)) {
      if (GAME->unk_1ba > 0) {
        GAME->unk_1ba--;
      }
      if (IsGunCooled()) {
        GAME->thermal = 0;
        GAME->unk_1ba = 0;
      }

    } else {
      SetOverheatTime();
      GAME->unk_1ba += GAME->unk_942;
      if ((s16)GAME->unk_1ba > 5000) {
        GAME->unk_1ba = 5000;
      }
    }
  }
#else
  INCCODE("asm/wip/overheat_08241a04.inc");
#endif
}

NAKED void solar_08241ac0(struct Entity5 *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, _08241B38 @ =0x03002BE0\n\
	ldr r3, [r0]\n\
	adds r6, r0, #0\n\
	cmp r3, #0\n\
	bne _08241AD0\n\
	b _08241CD0\n\
_08241AD0:\n\
	ldr r0, _08241B3C @ =0x030047A4\n\
	ldr r1, [r0]\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #5\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08241AE0\n\
	b _08241CD0\n\
_08241AE0:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	ands r2, r1\n\
	cmp r2, #0\n\
	bne _08241AF0\n\
	ldr r0, [r3, #0x1c]\n\
	cmp r0, #2\n\
	bne _08241B64\n\
_08241AF0:\n\
	ldr r7, _08241B40 @ =0x030046A0\n\
	ldr r0, [r7]\n\
	movs r6, #0xde\n\
	lsls r6, r6, #1\n\
	adds r3, r0, r6\n\
	ldr r2, [r3]\n\
	ldr r5, _08241B44 @ =0x0000752F\n\
	cmp r2, r5\n\
	bgt _08241B4C\n\
	movs r1, #0x94\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0\n\
	bgt _08241B12\n\
	b _08241CCA\n\
_08241B12:\n\
	ldrh r1, [r4, #0x24]\n\
	movs r0, #0x3f\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08241B1E\n\
	b _08241CCA\n\
_08241B1E:\n\
	ldrh r0, [r4, #0x1e]\n\
	adds r0, r2, r0\n\
	str r0, [r3]\n\
	cmp r0, r5\n\
	bgt _08241B2A\n\
	b _08241CCA\n\
_08241B2A:\n\
	ldr r0, [r7]\n\
	adds r0, r0, r6\n\
	ldr r1, _08241B48 @ =0x00007530\n\
	str r1, [r0]\n\
	bl SetOverheatTime\n\
	b _08241CCA\n\
	.align 2, 0\n\
_08241B38: .4byte 0x03002BE0\n\
_08241B3C: .4byte 0x030047A4\n\
_08241B40: .4byte 0x030046A0\n\
_08241B44: .4byte 0x0000752F\n\
_08241B48: .4byte 0x00007530\n\
_08241B4C:\n\
	ldr r2, _08241B60 @ =0x00000942\n\
	adds r0, r0, r2\n\
	movs r3, #0\n\
	ldrsh r0, [r0, r3]\n\
	cmp r0, #2\n\
	bgt _08241B5A\n\
	b _08241CCA\n\
_08241B5A:\n\
	bl SetOverheatTime\n\
	b _08241CCA\n\
	.align 2, 0\n\
_08241B60: .4byte 0x00000942\n\
_08241B64:\n\
	ldr r0, _08241B70 @ =0x030044E0\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	beq _08241B74\n\
	strh r2, [r4, #0x26]\n\
	b _08241B80\n\
	.align 2, 0\n\
_08241B70: .4byte 0x030044E0\n\
_08241B74:\n\
	ldrh r1, [r4, #0x26]\n\
	ldr r0, _08241C04 @ =0x00000383\n\
	cmp r1, r0\n\
	bhi _08241B80\n\
	adds r0, r1, #1\n\
	strh r0, [r4, #0x26]\n\
_08241B80:\n\
	ldr r0, _08241C08 @ =0x030046A0\n\
	ldr r3, [r0]\n\
	movs r7, #0x94\n\
	lsls r7, r7, #4\n\
	adds r1, r3, r7\n\
	movs r2, #0\n\
	ldrsh r1, [r1, r2]\n\
	adds r5, r0, #0\n\
	cmp r1, #0\n\
	bgt _08241B96\n\
	b _08241CC4\n\
_08241B96:\n\
	ldrh r1, [r4, #0x24]\n\
	movs r0, #0x3f\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08241BA2\n\
	b _08241CC4\n\
_08241BA2:\n\
	ldrh r1, [r4, #0x26]\n\
	ldr r0, _08241C04 @ =0x00000383\n\
	cmp r1, r0\n\
	bhi _08241C9C\n\
	movs r7, #0xec\n\
	lsls r7, r7, #1\n\
	adds r1, r3, r7\n\
	ldr r2, [r1]\n\
	ldr r0, _08241C0C @ =0x7FFFFFFE\n\
	cmp r2, r0\n\
	bgt _08241BCA\n\
	ldr r7, _08241C10 @ =0x00000942\n\
	adds r0, r3, r7\n\
	movs r3, #0\n\
	ldrsh r0, [r0, r3]\n\
	adds r0, r2, r0\n\
	cmp r0, #0\n\
	bge _08241BC8\n\
	ldr r0, _08241C14 @ =0x7FFFFFFF\n\
_08241BC8:\n\
	str r0, [r1]\n\
_08241BCA:\n\
	ldr r2, [r5]\n\
	movs r7, #0xef\n\
	lsls r7, r7, #2\n\
	adds r0, r2, r7\n\
	ldr r1, [r0]\n\
	ldr r0, _08241C18 @ =0x0000270E\n\
	cmp r1, r0\n\
	bgt _08241C52\n\
	ldr r0, [r6]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	movs r3, #0xde\n\
	lsls r3, r3, #2\n\
	adds r0, r0, r3\n\
	ldr r0, [r0]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08241C1C\n\
	ldr r6, _08241C10 @ =0x00000942\n\
	adds r0, r2, r6\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	adds r0, #5\n\
	lsls r0, r0, #1\n\
	ldrh r7, [r4, #0x28]\n\
	adds r0, r0, r7\n\
	b _08241C2C\n\
	.align 2, 0\n\
_08241C04: .4byte 0x00000383\n\
_08241C08: .4byte 0x030046A0\n\
_08241C0C: .4byte 0x7FFFFFFE\n\
_08241C10: .4byte 0x00000942\n\
_08241C14: .4byte 0x7FFFFFFF\n\
_08241C18: .4byte 0x0000270E\n\
_08241C1C:\n\
	ldr r1, _08241CD8 @ =0x00000942\n\
	adds r0, r2, r1\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x11\n\
	adds r0, #5\n\
	ldrh r2, [r4, #0x28]\n\
	adds r0, r0, r2\n\
_08241C2C:\n\
	strh r0, [r4, #0x28]\n\
	ldrh r0, [r4, #0x28]\n\
	lsrs r2, r0, #4\n\
	lsls r1, r2, #4\n\
	subs r0, r0, r1\n\
	strh r0, [r4, #0x28]\n\
	ldr r0, [r5]\n\
	movs r3, #0xef\n\
	lsls r3, r3, #2\n\
	adds r0, r0, r3\n\
	ldr r1, [r0]\n\
	adds r1, r1, r2\n\
	str r1, [r0]\n\
	ldr r2, _08241CDC @ =0x0000270F\n\
	cmp r1, r2\n\
	ble _08241C52\n\
	ldr r0, [r5]\n\
	adds r0, r0, r3\n\
	str r2, [r0]\n\
_08241C52:\n\
	ldr r3, [r5]\n\
	movs r6, #0xf0\n\
	lsls r6, r6, #1\n\
	adds r1, r3, r6\n\
	ldr r2, [r1]\n\
	ldr r0, _08241CE0 @ =0x7FFFFFFE\n\
	cmp r2, r0\n\
	bgt _08241C82\n\
	ldr r7, _08241CD8 @ =0x00000942\n\
	adds r0, r3, r7\n\
	movs r3, #0\n\
	ldrsh r0, [r0, r3]\n\
	adds r0, r2, r0\n\
	cmp r0, #0\n\
	bge _08241C72\n\
	ldr r0, _08241CE4 @ =0x7FFFFFFF\n\
_08241C72:\n\
	str r0, [r1]\n\
	ldr r1, [r5]\n\
	movs r6, #0xf2\n\
	lsls r6, r6, #1\n\
	adds r1, r1, r6\n\
	ldr r0, [r1]\n\
	adds r0, #1\n\
	str r0, [r1]\n\
_08241C82:\n\
	ldrh r1, [r4, #0x24]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08241C9C\n\
	ldr r0, _08241CE8 @ =0x030046A0\n\
	ldr r0, [r0]\n\
	ldr r7, _08241CD8 @ =0x00000942\n\
	adds r0, r0, r7\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	bl RotItem\n\
_08241C9C:\n\
	ldr r6, _08241CE8 @ =0x030046A0\n\
	ldr r0, [r6]\n\
	movs r5, #0xde\n\
	lsls r5, r5, #1\n\
	adds r2, r0, r5\n\
	ldr r1, [r2]\n\
	ldr r3, _08241CEC @ =0x0000752F\n\
	cmp r1, r3\n\
	bgt _08241CC4\n\
	ldrh r0, [r4, #0x1e]\n\
	adds r0, r1, r0\n\
	str r0, [r2]\n\
	cmp r0, r3\n\
	ble _08241CC4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r5\n\
	ldr r1, _08241CF0 @ =0x00007530\n\
	str r1, [r0]\n\
	bl SetOverheatTime\n\
_08241CC4:\n\
	adds r0, r4, #0\n\
	bl overheat_08241a04\n\
_08241CCA:\n\
	ldrh r0, [r4, #0x24]\n\
	adds r0, #1\n\
	strh r0, [r4, #0x24]\n\
_08241CD0:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08241CD8: .4byte 0x00000942\n\
_08241CDC: .4byte 0x0000270F\n\
_08241CE0: .4byte 0x7FFFFFFE\n\
_08241CE4: .4byte 0x7FFFFFFF\n\
_08241CE8: .4byte 0x030046A0\n\
_08241CEC: .4byte 0x0000752F\n\
_08241CF0: .4byte 0x00007530\n\
 .syntax divided\n");
}

NAKED void FUN_08241cf4(struct Entity5 *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	ldrb r4, [r7, #0x19]\n\
	cmp r4, #1\n\
	beq _08241D28\n\
	cmp r4, #1\n\
	bgt _08241D08\n\
	cmp r4, #0\n\
	beq _08241D0E\n\
	b _08241D90\n\
_08241D08:\n\
	cmp r4, #2\n\
	beq _08241D40\n\
	b _08241D90\n\
_08241D0E:\n\
	ldrh r0, [r7, #0x20]\n\
	adds r0, #1\n\
	strh r0, [r7, #0x20]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x1d\n\
	bls _08241D90\n\
	bl FUN_08247774\n\
	movs r0, #1\n\
	strb r0, [r7, #0x19]\n\
	strh r4, [r7, #0x20]\n\
	b _08241D90\n\
_08241D28:\n\
	ldrh r0, [r7, #0x20]\n\
	adds r0, #1\n\
	strh r0, [r7, #0x20]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x3b\n\
	bls _08241D90\n\
	movs r0, #2\n\
	strb r0, [r7, #0x19]\n\
	movs r0, #0\n\
	strh r0, [r7, #0x20]\n\
	b _08241D90\n\
_08241D40:\n\
	bl FUN_082418c0\n\
	strh r0, [r7, #0x1c]\n\
	movs r1, #0x1c\n\
	ldrsh r0, [r7, r1]\n\
	bl FUN_08241774\n\
	strh r0, [r7, #0x1e]\n\
	movs r1, #0x1c\n\
	ldrsh r0, [r7, r1]\n\
	bl FUN_082417ec\n\
	ldr r5, _08241D98 @ =0x030046A0\n\
	ldr r1, [r5]\n\
	movs r4, #0x94\n\
	lsls r4, r4, #4\n\
	adds r1, r1, r4\n\
	strh r0, [r1]\n\
	ldr r0, [r5]\n\
	adds r0, r0, r4\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	bl FUN_08241774\n\
	ldr r1, [r5]\n\
	ldr r6, _08241D9C @ =0x00000942\n\
	adds r1, r1, r6\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	bl solar_08241ac0\n\
	ldr r2, _08241DA0 @ =0x03004870\n\
	ldr r1, [r5]\n\
	adds r4, r1, r4\n\
	ldrh r0, [r4]\n\
	strh r0, [r2]\n\
	ldr r2, _08241DA4 @ =0x03004874\n\
	adds r1, r1, r6\n\
	ldrh r0, [r1]\n\
	strh r0, [r2]\n\
_08241D90:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08241D98: .4byte 0x030046A0\n\
_08241D9C: .4byte 0x00000942\n\
_08241DA0: .4byte 0x03004870\n\
_08241DA4: .4byte 0x03004874\n\
 .syntax divided\n");
}

NAKED u32 FUN_08241da8(struct Entity5 *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r2, r0, #0\n\
	ldr r0, _08241DC8 @ =0x030047A4\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08241DE0\n\
	ldr r0, _08241DCC @ =0x03002C68\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _08241DD0\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	b _08241DD4\n\
	.align 2, 0\n\
_08241DC8: .4byte 0x030047A4\n\
_08241DCC: .4byte 0x03002C68\n\
_08241DD0:\n\
	movs r1, #0x18\n\
	ldrsh r0, [r0, r1]\n\
_08241DD4:\n\
	lsls r1, r0, #3\n\
	ldr r0, _08241DDC @ =0x030044E0\n\
	adds r0, r1, r0\n\
	b _08241DE2\n\
	.align 2, 0\n\
_08241DDC: .4byte 0x030044E0\n\
_08241DE0:\n\
	ldr r0, _08241E10 @ =0x030044E0\n\
_08241DE2:\n\
	ldrh r1, [r0]\n\
	movs r3, #1\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	ldr r4, _08241E14 @ =0x03004868\n\
	cmp r0, #0\n\
	beq _08241E38\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08241E18\n\
	ldrh r0, [r2, #0x22]\n\
	adds r0, #1\n\
	strh r0, [r2, #0x22]\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	bne _08241E38\n\
	ldrh r0, [r4]\n\
	cmp r0, #0x8b\n\
	bhi _08241E38\n\
	adds r0, #1\n\
	b _08241E36\n\
	.align 2, 0\n\
_08241E10: .4byte 0x030044E0\n\
_08241E14: .4byte 0x03004868\n\
_08241E18:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08241E38\n\
	ldrh r0, [r2, #0x22]\n\
	adds r0, #1\n\
	strh r0, [r2, #0x22]\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	bne _08241E38\n\
	ldrh r0, [r4]\n\
	cmp r0, #0\n\
	beq _08241E38\n\
	subs r0, #1\n\
_08241E36:\n\
	strh r0, [r4]\n\
_08241E38:\n\
	ldrh r0, [r4]\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED void FUN_08241e40(struct Entity5 *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	ldrb r4, [r7, #0x19]\n\
	cmp r4, #1\n\
	beq _08241E74\n\
	cmp r4, #1\n\
	bgt _08241E54\n\
	cmp r4, #0\n\
	beq _08241E5A\n\
	b _08241EDE\n\
_08241E54:\n\
	cmp r4, #2\n\
	beq _08241E8C\n\
	b _08241EDE\n\
_08241E5A:\n\
	ldrh r0, [r7, #0x20]\n\
	adds r0, #1\n\
	strh r0, [r7, #0x20]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x1d\n\
	bls _08241EDE\n\
	bl FUN_08247774\n\
	movs r0, #1\n\
	strb r0, [r7, #0x19]\n\
	strh r4, [r7, #0x20]\n\
	b _08241EDE\n\
_08241E74:\n\
	ldrh r0, [r7, #0x20]\n\
	adds r0, #1\n\
	strh r0, [r7, #0x20]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x3b\n\
	bls _08241EDE\n\
	movs r0, #2\n\
	strb r0, [r7, #0x19]\n\
	movs r0, #0\n\
	strh r0, [r7, #0x20]\n\
	b _08241EDE\n\
_08241E8C:\n\
	adds r0, r7, #0\n\
	bl FUN_08241da8\n\
	strh r0, [r7, #0x1c]\n\
	movs r1, #0x1c\n\
	ldrsh r0, [r7, r1]\n\
	bl FUN_08241774\n\
	strh r0, [r7, #0x1e]\n\
	movs r1, #0x1c\n\
	ldrsh r0, [r7, r1]\n\
	bl FUN_082417ec\n\
	ldr r5, _08241EE4 @ =0x030046A0\n\
	ldr r1, [r5]\n\
	movs r4, #0x94\n\
	lsls r4, r4, #4\n\
	adds r1, r1, r4\n\
	strh r0, [r1]\n\
	ldr r0, [r5]\n\
	adds r0, r0, r4\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	bl FUN_08241774\n\
	ldr r1, [r5]\n\
	ldr r6, _08241EE8 @ =0x00000942\n\
	adds r1, r1, r6\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	bl solar_08241ac0\n\
	ldr r2, _08241EEC @ =0x03004870\n\
	ldr r1, [r5]\n\
	adds r4, r1, r4\n\
	ldrh r0, [r4]\n\
	strh r0, [r2]\n\
	ldr r2, _08241EF0 @ =0x03004874\n\
	adds r1, r1, r6\n\
	ldrh r0, [r1]\n\
	strh r0, [r2]\n\
_08241EDE:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08241EE4: .4byte 0x030046A0\n\
_08241EE8: .4byte 0x00000942\n\
_08241EEC: .4byte 0x03004870\n\
_08241EF0: .4byte 0x03004874\n\
 .syntax divided\n");
}

struct Entity5 *FUN_08241ef4(struct Entity5 *p) {
  if (u16_0300486c == 0) {
    p->unk_2c((struct Entity *)p);
  }
  return NULL;
}

struct Entity *FUN_08241f14(struct Entity *_) {
  FUN_082477b4();
  PTR_03001708 = NULL;
  return NULL;
}

NON_MATCH void FUN_08241f28(struct Entity5 *p) {
#if MODERN
  p->unk_18 = 1;
  p->unk_2c = (EntityFunc)FUN_08241cf4;
  p->unk_22 = p->unk_20 = p->unk_19 = 0;
  (GAME->unk_940) = u16_03004870;
  (GAME->unk_942) = u16_ARRAY_03004874[0];
#else
  INCCODE("asm/wip/FUN_08241f28.inc");
#endif
}
