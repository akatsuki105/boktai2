	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08055b58
FUN_08055b58: @ 0x08055B58
	bx lr
	.align 2, 0

	thumb_func_start SpriteHolder_SetAnim
SpriteHolder_SetAnim: @ 0x08055B5C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, [sp, #0x1c]
	ldr r7, [sp, #0x20]
	ldr r0, [r4]
	cmp r0, #0
	bne _08055B74
	movs r0, #1
	rsbs r0, r0, #0
	b _08055BFC
_08055B74:
	cmp r0, #1
	bne _08055BB0
	adds r5, r4, #0
	adds r5, #0xc
	strb r2, [r4, #8]
	strb r3, [r4, #9]
	ands r3, r0
	cmp r3, #0
	beq _08055B88
	orrs r1, r0
_08055B88:
	str r6, [r4, #4]
	ldr r5, [r5, #0x58]
	cmp r5, #0
	beq _08055BFA
	adds r0, r4, #0
	adds r0, #0x54
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	ldrb r3, [r4, #8]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	adds r1, r5, #0
	bl AuxAnim_SetAnim
	cmp r0, #0
	beq _08055BFA
	movs r0, #0
	strb r0, [r4, #0xa]
	b _08055BFA
_08055BB0:
	adds r5, r4, #0
	adds r5, #0xc
	strb r2, [r4, #8]
	strb r3, [r4, #9]
	ldrb r2, [r4, #8]
	adds r2, r6, r2
	str r2, [r4, #4]
	adds r0, r4, #0
	adds r0, #0x2c
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, [sp, #0x18]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	adds r1, r5, #0
	bl MainSprite_SetAnim
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	bne _08055BE2
	strb r0, [r4, #0xa]
_08055BE2:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08055BF0
	ldr r0, [r5, #0x28]
	movs r1, #4
	orrs r0, r1
	b _08055BF8
_08055BF0:
	ldr r0, [r5, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08055BF8:
	str r0, [r5, #0x28]
_08055BFA:
	movs r0, #0
_08055BFC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055c04
FUN_08055c04: @ 0x08055C04
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r3, [r6]
	cmp r3, #0
	bne _08055C14
	movs r0, #1
	rsbs r0, r0, #0
	b _08055D18
_08055C14:
	cmp r3, #1
	bne _08055D08
	ldr r0, [r6, #0x64]
	cmp r0, #0
	beq _08055D16
	adds r7, r6, #0
	adds r7, #0x28
	adds r4, r6, #0
	adds r4, #0x54
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x54]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08055C50
	ldr r0, [r6, #0x28]
	movs r1, #4
	orrs r0, r1
	b _08055C58
_08055C50:
	ldr r0, [r6, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08055C58:
	str r0, [r6, #0x28]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08055C7C
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08055C84
_08055C7C:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08055C84:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08055CBC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08055D02
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08055CC6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08055CC0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08055CDC
	.align 2, 0
_08055CBC: .4byte 0x0000FFFF
_08055CC0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08055CDA
_08055CC6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08055CDA
	strh r1, [r4, #8]
	movs r2, #1
	b _08055CDC
_08055CDA:
	movs r2, #0
_08055CDC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08055D04
	movs r0, #1
	strb r0, [r4, #7]
	b _08055D04
_08055D02:
	movs r2, #0
_08055D04:
	strb r2, [r6, #0xa]
	b _08055D16
_08055D08:
	adds r1, r6, #0
	adds r1, #0xc
	adds r0, r6, #0
	adds r0, #0x2c
	bl MainSprite_AdvanceAnim
	strb r0, [r6, #0xa]
_08055D16:
	ldrb r0, [r6, #0xa]
_08055D18:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055d20
FUN_08055d20: @ 0x08055D20
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1]
	cmp r0, #1
	bne _08055D2E
	ldrb r0, [r1, #0xa]
	b _08055D42
_08055D2E:
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r1, [r0, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08055D40
	movs r0, #0
	b _08055D42
_08055D40:
	movs r0, #1
_08055D42:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055d48
FUN_08055d48: @ 0x08055D48
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2]
	cmp r0, #2
	bne _08055D64
	adds r2, #0x2c
	ldrb r1, [r2, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08055D76
	ldrh r0, [r2, #0x14]
	b _08055D70
_08055D64:
	adds r1, r2, #0
	adds r1, #0x54
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _08055D76
	ldrh r0, [r1, #8]
_08055D70:
	str r0, [r3]
	movs r0, #1
	b _08055D78
_08055D76:
	movs r0, #0
_08055D78:
	pop {r1}
	bx r1

	thumb_func_start FUN_08055d7c
FUN_08055d7c: @ 0x08055D7C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	bne _08055D8C
	movs r0, #1
	rsbs r0, r0, #0
	b _08055DA6
_08055D8C:
	cmp r0, #1
	bne _08055D9A
	adds r0, r4, #0
	adds r0, #0x28
	bl AuxSprite_Remove
	b _08055DA2
_08055D9A:
	adds r0, r4, #0
	adds r0, #0x2c
	bl MainSprite_Remove
_08055DA2:
	movs r0, #0
	str r0, [r4]
_08055DA6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08055dac
FUN_08055dac: @ 0x08055DAC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	mov r8, r3
	ldr r0, [r6]
	cmp r0, #0
	bne _08055DF0
	adds r0, r6, #0
	movs r1, #0x94
	bl ClearMemory
	movs r0, #1
	str r0, [r6]
	adds r5, r6, #0
	adds r5, #0xc
	adds r0, r5, #0
	adds r1, r7, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	beq _08055DF0
	cmp r4, #0
	beq _08055DFC
	ldr r0, _08055DF8 @ =0x0000922E
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	str r0, [r5, #0x58]
	cmp r0, #0
	bne _08055DFE
_08055DF0:
	movs r0, #1
	rsbs r0, r0, #0
	b _08055E28
	.align 2, 0
_08055DF8: .4byte 0x0000922E
_08055DFC:
	str r4, [r5, #0x58]
_08055DFE:
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, r8
	bl AuxSprite_Add
	ldr r0, [sp, #0x18]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x38]
	str r1, [r5, #0x3c]
	adds r1, r6, #0
	adds r1, #0x8c
	adds r0, r5, #0
	adds r0, #0x38
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0x90
	str r4, [r0]
	movs r0, #0
_08055E28:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055e34
FUN_08055e34: @ 0x08055E34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	adds r6, r1, #0
	mov sb, r2
	mov r8, r3
	ldr r0, [r4]
	mov sl, r0
	cmp r0, #0
	bne _08055E70
	adds r0, r4, #0
	movs r1, #0x94
	bl ClearMemory
	movs r0, #2
	str r0, [r4]
	adds r5, r4, #0
	adds r5, #0xc
	ldr r0, _08055E78 @ =0x0000CB05
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08055E7C
_08055E70:
	movs r0, #1
	rsbs r0, r0, #0
	b _08055EC2
	.align 2, 0
_08055E78: .4byte 0x0000CB05
_08055E7C:
	adds r1, r5, #0
	adds r0, r2, #0
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r0, r5, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #1
	str r1, [sp]
	mov r7, sl
	str r7, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0
	mov r3, sb
	bl MainSprite_Add
	adds r2, r4, #0
	adds r2, #0x8c
	adds r1, r4, #0
	adds r1, #0x4c
	str r1, [r2]
	adds r2, #4
	subs r1, #0x18
	str r1, [r2]
_08055EC2:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055ed4
FUN_08055ed4: @ 0x08055ED4
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r1, [r3]
	cmp r1, #0
	bne _08055EE6
	movs r0, #1
	rsbs r0, r0, #0
	b _08055EF4
_08055EE6:
	adds r1, r3, #0
	adds r1, #0x8c
	ldr r3, [r1]
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r3]
	str r2, [r3, #4]
_08055EF4:
	pop {r1}
	bx r1

	thumb_func_start FUN_08055ef8
FUN_08055ef8: @ 0x08055EF8
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2]
	cmp r0, #0
	beq _08055F14
	adds r0, r2, #0
	adds r0, #0x90
	ldr r1, [r0]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	movs r0, #0
	b _08055F18
_08055F14:
	movs r0, #1
	rsbs r0, r0, #0
_08055F18:
	pop {r1}
	bx r1

	thumb_func_start FUN_08055f1c
FUN_08055f1c: @ 0x08055F1C
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2]
	cmp r0, #0
	beq _08055F38
	adds r0, r2, #0
	adds r0, #0x90
	ldr r1, [r0]
	ldr r0, [r1]
	bics r0, r3
	str r0, [r1]
	movs r0, #0
	b _08055F3C
_08055F38:
	movs r0, #1
	rsbs r0, r0, #0
_08055F3C:
	pop {r1}
	bx r1

	thumb_func_start FUN_08055f40
FUN_08055f40: @ 0x08055F40
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2]
	cmp r0, #0
	beq _08055F56
	adds r0, r2, #0
	adds r0, #0x90
	ldr r0, [r0]
	ldr r0, [r0]
	ands r0, r1
	b _08055F58
_08055F56:
	movs r0, #0
_08055F58:
	pop {r1}
	bx r1

	thumb_func_start FUN_08055f5c
FUN_08055f5c: @ 0x08055F5C
	push {lr}
	ldr r2, [r0]
	cmp r2, #0
	bne _08055F6A
	movs r0, #1
	rsbs r0, r0, #0
	b _08055F7A
_08055F6A:
	cmp r2, #1
	bne _08055F74
	adds r0, #0x28
	strb r1, [r0, #7]
	b _08055F78
_08055F74:
	adds r0, #0x2c
	strb r1, [r0, #0x1a]
_08055F78:
	movs r0, #0
_08055F7A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055f80
FUN_08055f80: @ 0x08055F80
	push {r4, lr}
	mov ip, r0
	adds r4, r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne _08055F92
	movs r0, #1
	rsbs r0, r0, #0
	b _08055FB4
_08055F92:
	cmp r0, #1
	bne _08055FA2
	mov r0, ip
	adds r0, #0x28
	strb r4, [r0, #8]
	strb r2, [r0, #9]
	strb r3, [r0, #6]
	b _08055FB2
_08055FA2:
	mov r0, ip
	adds r0, #0x2c
	mov r1, ip
	adds r1, #0x60
	strb r4, [r1]
	adds r1, #1
	strb r2, [r1]
	strh r3, [r0, #0x36]
_08055FB2:
	movs r0, #0
_08055FB4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start SpriteHolder_SetPlttID
SpriteHolder_SetPlttID: @ 0x08055FBC
	push {lr}
	ldr r2, [r0]
	cmp r2, #0
	bne _08055FCA
	movs r0, #1
	rsbs r0, r0, #0
	b _08055FDE
_08055FCA:
	cmp r2, #1
	bne _08055FD6
	adds r0, #0xc
	bl Video_SetAuxSpritePltt
	b _08055FDC
_08055FD6:
	adds r0, #0x2c
	bl MainSprite_SetPlttID
_08055FDC:
	movs r0, #0
_08055FDE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08055fe4
FUN_08055fe4: @ 0x08055FE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	adds r6, r1, #0
	movs r0, #0x30
	adds r0, r0, r6
	mov ip, r0
	ldrh r0, [r6, #6]
	cmp r0, #0xf
	bls _0805606A
	ldrb r1, [r6, #5]
	mov sb, r1
	ldrb r5, [r6, #8]
	adds r4, r6, #0
	adds r4, #0x4c
	ldr r3, _080560C4 @ =0x00000DAC
	adds r0, r7, r3
	ldr r3, [r0]
	movs r0, #0x2c
	adds r0, r0, r3
	mov r8, r0
	ldr r1, _080560C8 @ =0x085AB990
	lsls r0, r5, #1
	adds r0, r0, r1
	ldrh r1, [r7, #0x24]
	ldrh r0, [r0]
	cmp r1, r0
	bhs _0805606A
	ldr r0, [r7, #0x20]
	movs r1, #3
	ands r0, r1
	ands r2, r1
	cmp r0, r2
	bne _0805606A
	movs r2, #0x2c
	ldrsh r1, [r3, r2]
	movs r3, #0
	ldrsh r0, [r4, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _0805603E
	rsbs r0, r0, #0
_0805603E:
	cmp r0, #0x7f
	bgt _0805606A
	mov r0, r8
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _08056054
	rsbs r1, r1, #0
_08056054:
	cmp r1, #0x7f
	bgt _0805606A
	adds r0, r7, #0
	adds r0, #0x2a
	strb r5, [r0]
	ldrh r0, [r7, #0x24]
	adds r0, #1
	strh r0, [r7, #0x24]
	ldrh r0, [r7, #0x28]
	add r0, sb
	strh r0, [r7, #0x28]
_0805606A:
	mov r1, ip
	adds r1, #0x1c
	adds r2, r6, #0
	adds r2, #0xc
	ldrh r0, [r6, #0xc]
	mov r4, ip
	ldrh r4, [r4, #0x1c]
	adds r0, r0, r4
	mov r3, ip
	strh r0, [r3, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r4, r6, #0
	adds r4, #0x5c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x5c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r3, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _080560CC
	mov r3, ip
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _080560DA
	.align 2, 0
_080560C4: .4byte 0x00000DAC
_080560C8: .4byte 0x085AB990
_080560CC:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080560DA:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08056100
	mov r3, ip
	ldr r0, [r3]
	movs r1, #8
	orrs r0, r1
	str r0, [r3]
	b _0805610E
_08056100:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_0805610E:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08056144 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0805618A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805614E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08056148
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08056164
	.align 2, 0
_08056144: .4byte 0x0000FFFF
_08056148:
	subs r0, #1
	strh r0, [r4, #8]
	b _08056162
_0805614E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08056162
	strh r1, [r4, #8]
	movs r2, #1
	b _08056164
_08056162:
	movs r2, #0
_08056164:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805618C
	movs r0, #1
	strb r0, [r4, #7]
	b _0805618C
_0805618A:
	movs r2, #0
_0805618C:
	cmp r2, #0
	beq _080561A8
	ldrb r0, [r6, #2]
	adds r0, #1
	movs r3, #0
	strb r0, [r6, #2]
	strh r3, [r6, #6]
	ldr r1, [r7, #0x18]
	ldrb r2, [r6, #2]
	adds r2, #3
	str r3, [sp]
	mov r0, r8
	bl AuxAnim_SetAnim
_080561A8:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080561b8
FUN_080561b8: @ 0x080561B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov ip, r1
	mov sl, r2
	mov r7, ip
	adds r7, #0x30
	mov r3, ip
	adds r3, #0x4c
	adds r1, #0xc
	mov r2, ip
	ldrh r0, [r2, #0xc]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	ldrh r0, [r1, #2]
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	mov r2, ip
	ldrb r2, [r2, #5]
	mov sb, r2
	mov r0, ip
	ldrb r5, [r0, #8]
	ldr r1, _0805629C @ =0x00000DAC
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0x2c
	adds r2, r2, r4
	mov r8, r2
	ldr r1, _080562A0 @ =0x085AB990
	lsls r0, r5, #1
	adds r0, r0, r1
	ldrh r1, [r6, #0x24]
	ldrh r0, [r0]
	cmp r1, r0
	bhs _0805625C
	ldr r0, [r6, #0x20]
	movs r2, #3
	ands r0, r2
	mov r1, sl
	ands r1, r2
	cmp r0, r1
	bne _0805625C
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08056230
	rsbs r0, r0, #0
_08056230:
	cmp r0, #0x7f
	bgt _0805625C
	mov r0, r8
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08056246
	rsbs r1, r1, #0
_08056246:
	cmp r1, #0x7f
	bgt _0805625C
	adds r0, r6, #0
	adds r0, #0x2a
	strb r5, [r0]
	ldrh r0, [r6, #0x24]
	adds r0, #1
	strh r0, [r6, #0x24]
	ldrh r0, [r6, #0x28]
	add r0, sb
	strh r0, [r6, #0x28]
_0805625C:
	mov r1, ip
	ldrh r0, [r1]
	cmp r0, #0
	beq _08056268
	subs r0, #1
	strh r0, [r1]
_08056268:
	mov r4, ip
	adds r4, #0x5c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x5c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _080562A4
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080562AC
	.align 2, 0
_0805629C: .4byte 0x00000DAC
_080562A0: .4byte 0x085AB990
_080562A4:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080562AC:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080562D0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080562D8
_080562D0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080562D8:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08056310 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08056356
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805631A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08056314
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08056330
	.align 2, 0
_08056310: .4byte 0x0000FFFF
_08056314:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805632E
_0805631A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805632E
	strh r1, [r4, #8]
	movs r2, #1
	b _08056330
_0805632E:
	movs r2, #0
_08056330:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08056358
	movs r0, #1
	strb r0, [r4, #7]
	b _08056358
_08056356:
	movs r2, #0
_08056358:
	cmp r2, #0
	beq _0805639E
	mov r0, ip
	ldrh r3, [r0]
	cmp r3, #0
	bne _0805639E
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq _0805636E
	cmp r0, #3
	bne _0805638C
_0805636E:
	mov r1, ip
	ldrb r0, [r1, #2]
	adds r0, #1
	strb r0, [r1, #2]
	strh r3, [r1, #6]
	ldr r1, [r6, #0x18]
	mov r0, ip
	ldrb r2, [r0, #2]
	adds r2, #3
	str r3, [sp]
	mov r0, r8
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0805639E
_0805638C:
	movs r1, #1
	mov r2, sl
	lsls r1, r2
	ldr r0, [r6, #0x1c]
	bics r0, r1
	str r0, [r6, #0x1c]
	adds r0, r7, #0
	bl AuxSprite_Remove
_0805639E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080563b0
FUN_080563b0: @ 0x080563B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov ip, r1
	mov r8, r2
	mov r6, ip
	adds r6, #0x30
	adds r1, #0x4c
	mov r2, ip
	adds r2, #0xc
	mov r3, ip
	ldrh r0, [r3, #0xc]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	mov r4, ip
	adds r4, #0x5c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r3, ip
	ldr r1, [r3, #0x5c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08056418
	mov r1, ip
	ldr r0, [r1, #0x30]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2, #0x30]
	b _08056424
_08056418:
	mov r3, ip
	ldr r0, [r3, #0x30]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x30]
_08056424:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08056446
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0805644E
_08056446:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805644E:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08056488 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080564CE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08056492
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0805648C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080564A8
	.align 2, 0
_08056488: .4byte 0x0000FFFF
_0805648C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080564A6
_08056492:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080564A6
	strh r1, [r4, #8]
	movs r2, #1
	b _080564A8
_080564A6:
	movs r2, #0
_080564A8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080564D0
	movs r0, #1
	strb r0, [r4, #7]
	b _080564D0
_080564CE:
	movs r2, #0
_080564D0:
	cmp r2, #0
	beq _080564E6
	movs r1, #1
	mov r3, r8
	lsls r1, r3
	ldr r0, [r7, #0x1c]
	bics r0, r1
	str r0, [r7, #0x1c]
	adds r0, r6, #0
	bl AuxSprite_Remove
_080564E6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity08056728_Update
Entity08056728_Update: @ 0x080564F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0
	strh r0, [r5, #0x24]
	strh r0, [r5, #0x28]
	adds r4, r5, #0
	adds r4, #0x2c
	movs r6, #0
	ldr r0, _08056548 @ =0x0000011F
	mov r8, r0
	ldr r7, _0805654C @ =0x0000021F
_0805650C:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r5, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _0805657E
	ldr r1, _08056550 @ =0x085AB998
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _08056578
	adds r1, r4, #0
	adds r1, #0x4c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, r8
	bgt _08056554
	movs r0, #0x90
	lsls r0, r0, #1
	strh r0, [r1]
	b _0805655E
	.align 2, 0
_08056548: .4byte 0x0000011F
_0805654C: .4byte 0x0000021F
_08056550: .4byte 0x085AB998
_08056554:
	movs r2, #0xbe
	lsls r2, r2, #4
	cmp r0, r2
	ble _0805655E
	strh r2, [r1]
_0805655E:
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, r7
	bgt _0805656E
	movs r0, #0x88
	lsls r0, r0, #2
	strh r0, [r1, #4]
	b _08056578
_0805656E:
	movs r2, #0xc8
	lsls r2, r2, #4
	cmp r0, r2
	ble _08056578
	strh r2, [r1, #4]
_08056578:
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_0805657E:
	adds r6, #1
	adds r4, #0x6c
	cmp r6, #0x1f
	ble _0805650C
	ldrh r0, [r5, #0x24]
	cmp r0, #0
	beq _0805660C
	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldrh r1, [r5, #0x26]
	adds r0, r0, r1
	strh r0, [r5, #0x26]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _08056612
	movs r0, #0
	strh r0, [r5, #0x26]
	adds r0, r5, #0
	adds r0, #0x2a
	ldrb r3, [r0]
	cmp r3, #1
	beq _080565D8
	cmp r3, #1
	bgt _080565BA
	cmp r3, #0
	beq _080565C2
	b _08056612
_080565BA:
	cmp r3, #2
	beq _080565F0
	cmp r3, #3
	bne _08056612
_080565C2:
	ldr r2, _080565D4 @ =0x00000DAC
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r5, #0x28]
	movs r2, #8
	str r2, [sp]
	movs r2, #0x10
	str r2, [sp, #4]
	b _080565FE
	.align 2, 0
_080565D4: .4byte 0x00000DAC
_080565D8:
	ldr r1, _080565EC @ =0x00000DAC
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r5, #0x28]
	movs r2, #8
	str r2, [sp]
	movs r2, #0x20
	str r2, [sp, #4]
	b _080565FE
	.align 2, 0
_080565EC: .4byte 0x00000DAC
_080565F0:
	ldr r2, _08056608 @ =0x00000DAC
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r5, #0x28]
	movs r2, #8
	str r2, [sp]
	str r3, [sp, #4]
_080565FE:
	movs r2, #0
	movs r3, #0
	bl FUN_0807e7fc
	b _08056612
	.align 2, 0
_08056608: .4byte 0x00000DAC
_0805660C:
	ldrh r0, [r5, #0x26]
	subs r0, #1
	strh r0, [r5, #0x26]
_08056612:
	ldr r0, [r5, #0x20]
	adds r0, #1
	str r0, [r5, #0x20]
	movs r0, #0
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity08056728_Destroy
Entity08056728_Destroy: @ 0x08056628
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x2c
	movs r4, #0
_08056632:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _08056646
	adds r0, r5, #0
	adds r0, #0x30
	bl AuxSprite_Remove
_08056646:
	adds r4, #1
	adds r5, #0x6c
	cmp r4, #0x1f
	ble _08056632
	ldr r1, _0805665C @ =0x03000128
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805665C: .4byte 0x03000128

	thumb_func_start Entity08056728_Init
Entity08056728_Init: @ 0x08056660
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _080566A8 @ =0x03000128
	str r7, [r0]
	ldr r0, _080566AC @ =0x0000922E
	ldr r1, _080566B0 @ =0x000031F4
	bl GetFile
	str r0, [r7, #0x18]
	movs r0, #0
	str r0, [r7, #0x1c]
	adds r5, r7, #0
	adds r5, #0x2c
	mov sb, r0
	mov r8, r0
_08056686:
	mov r0, r8
	strb r0, [r5, #4]
	strb r0, [r5, #3]
	adds r4, r5, #0
	adds r4, #0x14
	adds r0, r4, #0
	ldr r1, _080566B4 @ =0x000061F9
	bl Video_GetAuxSprite
	adds r6, r5, #0
	adds r6, #0x30
	cmp r0, #0
	bne _080566B8
	movs r0, #1
	rsbs r0, r0, #0
	b _0805670E
	.align 2, 0
_080566A8: .4byte 0x03000128
_080566AC: .4byte 0x0000922E
_080566B0: .4byte 0x000031F4
_080566B4: .4byte 0x000061F9
_080566B8:
	adds r0, r4, #0
	movs r1, #0x89
	lsls r1, r1, #2
	bl Video_SetAuxSpritePltt
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Setup
	movs r0, #0xc
	strh r0, [r6, #0x10]
	adds r0, r5, #0
	adds r0, #0x5c
	ldr r1, [r7, #0x18]
	mov r2, r8
	str r2, [sp]
	movs r2, #3
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #2
	strb r0, [r6, #7]
	adds r1, r5, #0
	adds r1, #0x4c
	mov r0, r8
	str r0, [sp, #4]
	add r0, sp, #4
	ldr r2, _0805671C @ =0x05000002
	bl CpuSet
	movs r2, #1
	add sb, r2
	adds r5, #0x6c
	mov r0, sb
	cmp r0, #0x1f
	ble _08056686
	ldr r0, _08056720 @ =0x03002BE0
	ldr r1, [r0]
	ldr r2, _08056724 @ =0x00000DAC
	adds r0, r7, r2
	str r1, [r0]
	movs r0, #0
_0805670E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805671C: .4byte 0x05000002
_08056720: .4byte 0x03002BE0
_08056724: .4byte 0x00000DAC

	thumb_func_start Entity08056728_Create
Entity08056728_Create: @ 0x08056728
	push {r4, lr}
	ldr r0, _08056760 @ =0x03000128
	ldr r0, [r0]
	cmp r0, #0
	bne _0805676E
	movs r1, #0xdb
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805676C
	ldr r1, _08056764 @ =Entity08056728_Update
	ldr r2, _08056768 @ =Entity08056728_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08056728_Init
	cmp r0, #0
	bge _0805676C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805676E
	.align 2, 0
_08056760: .4byte 0x03000128
_08056764: .4byte Entity08056728_Update
_08056768: .4byte Entity08056728_Destroy
_0805676C:
	adds r0, r4, #0
_0805676E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08056774
FUN_08056774: @ 0x08056774
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r1, _080567A4 @ =0x03000128
	ldr r1, [r1]
	mov r8, r1
	cmp r1, #0
	bne _080567A8
	bl Entity08056728_Create
	mov r8, r0
	cmp r0, #0
	bne _080567A8
	movs r0, #1
	rsbs r0, r0, #0
	b _080569E2
	.align 2, 0
_080567A4: .4byte 0x03000128
_080567A8:
	ldr r1, [sp, #0x58]
	cmp r1, #1
	beq _080567D2
	cmp r1, #1
	bgt _080567B8
	cmp r1, #0
	beq _080567C2
	b _080567F4
_080567B8:
	ldr r2, [sp, #0x58]
	cmp r2, #2
	beq _080567E2
	cmp r2, #3
	bne _080567F4
_080567C2:
	movs r3, #3
	str r3, [sp, #0x20]
	movs r5, #0x89
	lsls r5, r5, #2
	str r5, [sp, #0x24]
	movs r1, #2
	str r1, [sp, #0x28]
	b _08056802
_080567D2:
	movs r2, #6
	str r2, [sp, #0x20]
	movs r3, #0x8b
	lsls r3, r3, #2
	str r3, [sp, #0x24]
	movs r5, #1
	str r5, [sp, #0x28]
	b _08056802
_080567E2:
	movs r1, #8
	str r1, [sp, #0x20]
	ldr r2, _080567F0 @ =0x0000023A
	str r2, [sp, #0x24]
	movs r3, #2
	str r3, [sp, #0x28]
	b _08056802
	.align 2, 0
_080567F0: .4byte 0x0000023A
_080567F4:
	movs r5, #3
	str r5, [sp, #0x20]
	movs r1, #0x89
	lsls r1, r1, #2
	str r1, [sp, #0x24]
	movs r2, #2
	str r2, [sp, #0x28]
_08056802:
	ldr r3, [sp, #0xc]
	asrs r3, r3, #1
	str r3, [sp, #0x18]
	ldr r5, [sp, #0x4c]
	asrs r5, r5, #1
	str r5, [sp, #0x1c]
	movs r1, #0
	str r1, [sp, #0x14]
	mov r4, r8
	adds r4, #0x2c
	mov sl, r1
	movs r2, #0x40
	add r2, r8
	mov sb, r2
_0805681E:
	movs r2, #1
	mov r3, sl
	lsls r2, r3
	mov r5, r8
	ldr r1, [r5, #0x1c]
	ands r1, r2
	cmp r1, #0
	beq _08056830
	b _080569D0
_08056830:
	adds r7, r4, #0
	adds r7, #0x30
	add r0, sp, #0x58
	ldrb r0, [r0]
	strb r0, [r4, #8]
	movs r1, #0
	add r2, sp, #0x50
	ldrh r2, [r2]
	strh r2, [r4]
	ldr r3, [sp, #0x58]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08056850
	cmp r0, #3
	bne _08056854
_08056850:
	strb r1, [r4, #2]
	b _08056858
_08056854:
	movs r5, #1
	strb r5, [r4, #2]
_08056858:
	movs r0, #0
	strh r0, [r4, #6]
	add r1, sp, #0x54
	ldrb r1, [r1]
	strb r1, [r4, #5]
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _08056870
	mov r3, sp
	ldrb r3, [r3, #8]
	strb r3, [r4, #3]
	b _08056894
_08056870:
	ldr r5, _080568A0 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080568A4 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _080568A8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #0xc]
	bl Mod
	ldr r2, [sp, #8]
	adds r0, r2, r0
	ldr r3, [sp, #0x18]
	subs r0, r0, r3
	strb r0, [r4, #3]
_08056894:
	ldr r5, [sp, #0x4c]
	cmp r5, #0
	bne _080568AC
	mov r0, sp
	ldrb r0, [r0, #0x10]
	b _080568D0
	.align 2, 0
_080568A0: .4byte 0x030046B8
_080568A4: .4byte 0x000003FF
_080568A8: .4byte 0x0203B400
_080568AC:
	ldr r1, _080568F8 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080568FC @ =0x000003FF
	ands r0, r1
	ldr r2, _080568F8 @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08056900 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x4c]
	bl Mod
	ldr r5, [sp, #0x10]
	adds r0, r5, r0
	ldr r1, [sp, #0x1c]
	subs r0, r0, r1
_080568D0:
	strb r0, [r4, #4]
	adds r3, r4, #0
	adds r3, #0xc
	ldrb r5, [r4, #3]
	ldrb r6, [r4, #4]
	ldr r2, _08056904 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08056908
	asrs r0, r0, #0xc
	b _0805690E
	.align 2, 0
_080568F8: .4byte 0x030046B8
_080568FC: .4byte 0x000003FF
_08056900: .4byte 0x0203B400
_08056904: .4byte 0x085B0A08
_08056908:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805690E:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08056926
	asrs r0, r0, #0xc
	b _0805692C
_08056926:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805692C:
	strh r0, [r3, #4]
	movs r2, #0
	strh r2, [r4, #0xe]
	ldr r3, [sp, #0x5c]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r0, r4, #0
	adds r0, #0x5c
	mov r5, r8
	ldr r1, [r5, #0x18]
	ldr r3, [sp, #0x20]
	lsls r2, r3, #0x10
	movs r5, #0
	str r5, [sp]
	lsrs r2, r2, #0x10
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #0x12
	strh r0, [r7, #0x10]
	add r0, sp, #0x28
	ldrb r0, [r0]
	strb r0, [r7, #7]
	adds r0, r7, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	mov r0, sb
	ldr r1, [sp, #0x24]
	bl Video_SetAuxSpritePltt
	ldrb r1, [r4, #8]
	cmp r1, #0
	bne _080569B6
	adds r3, r4, #0
	adds r3, #0x4c
	mov r1, sb
	movs r5, #0x38
	ldrsh r2, [r1, r5]
	ldr r1, _0805698C @ =0x0000011F
	cmp r2, r1
	bgt _08056990
	adds r1, #1
	mov r2, sb
	strh r1, [r2, #0x38]
	b _0805699A
	.align 2, 0
_0805698C: .4byte 0x0000011F
_08056990:
	movs r1, #0xbe
	lsls r1, r1, #4
	cmp r2, r1
	ble _0805699A
	strh r1, [r3]
_0805699A:
	movs r5, #4
	ldrsh r2, [r3, r5]
	ldr r1, _080569A8 @ =0x0000021F
	cmp r2, r1
	bgt _080569AC
	adds r1, #1
	b _080569B4
	.align 2, 0
_080569A8: .4byte 0x0000021F
_080569AC:
	movs r1, #0xc8
	lsls r1, r1, #4
	cmp r2, r1
	ble _080569B6
_080569B4:
	strh r1, [r3, #4]
_080569B6:
	movs r2, #1
	mov r1, sl
	lsls r2, r1
	mov r3, r8
	ldr r1, [r3, #0x1c]
	orrs r1, r2
	str r1, [r3, #0x1c]
	ldr r5, [sp, #0x14]
	adds r5, #1
	str r5, [sp, #0x14]
	ldr r1, [sp, #4]
	cmp r5, r1
	bge _080569E2
_080569D0:
	movs r2, #1
	add sl, r2
	movs r3, #0x6c
	add sb, r3
	adds r4, #0x6c
	mov r5, sl
	cmp r5, #0x1f
	bgt _080569E2
	b _0805681E
_080569E2:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
