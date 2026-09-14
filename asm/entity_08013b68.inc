	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0801392c
FUN_0801392c: @ 0x0801392C
	push {lr}
	ldrb r2, [r1]
	cmp r2, #0
	beq _0801393A
	movs r0, #1
	rsbs r0, r0, #0
	b _0801394E
_0801393A:
	str r2, [r1, #0x64]
	ldr r2, [r0, #0x1c]
	str r2, [r1, #0x68]
	cmp r2, #0
	beq _08013946
	str r1, [r2, #0x64]
_08013946:
	str r1, [r0, #0x1c]
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0801394E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013954
FUN_08013954: @ 0x08013954
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r1, #0x64]
	ldr r2, [r1, #0x68]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08013968
	movs r0, #1
	rsbs r0, r0, #0
	b _0801397C
_08013968:
	cmp r3, #0
	beq _08013970
	str r2, [r3, #0x68]
	b _08013972
_08013970:
	str r2, [r4, #0x1c]
_08013972:
	cmp r2, #0
	beq _08013978
	str r3, [r2, #0x64]
_08013978:
	movs r0, #0
	strb r0, [r1]
_0801397C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013984
FUN_08013984: @ 0x08013984
	push {lr}
	ldr r1, [r0, #0xc]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #0xc]
	ldr r1, _0801399C @ =FUN_080139b8
	str r1, [r0, #0x60]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0801399C: .4byte FUN_080139b8

	thumb_func_start FUN_080139a0
FUN_080139a0: @ 0x080139A0
	ldr r1, [r0, #0xc]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0xc]
	ldr r1, _080139B0 @ =FUN_080139b4
	str r1, [r0, #0x60]
	bx lr
	.align 2, 0
_080139B0: .4byte FUN_080139b4

	thumb_func_start FUN_080139b4
FUN_080139b4: @ 0x080139B4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080139b8
FUN_080139b8: @ 0x080139B8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #8]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080139E2
	cmp r1, #0
	blt _080139E2
	ldr r0, _080139E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080139E2
	ldr r0, _080139EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080139F0
_080139E2:
	movs r0, #0
	b _080139FE
	.align 2, 0
_080139E8: .4byte 0x030046A8
_080139EC: .4byte 0x030046AC
_080139F0:
	ldr r0, _08013A18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080139FE:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r2, [r4, #8]
	ldrh r0, [r2]
	strh r0, [r4, #0x28]
	ldrb r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08013A1C
	ldrh r0, [r2, #2]
	strh r0, [r4, #0x2a]
	b _08013A5E
	.align 2, 0
_08013A18: .4byte 0x030046A4
_08013A1C:
	adds r5, r2, #0
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08013A2E
	adds r0, #4
	b _08013A3A
_08013A2E:
	ldr r0, _08013A50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08013A3A:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08013A54
	cmp r2, #2
	beq _08013A58
	b _08013A5C
	.align 2, 0
_08013A50: .4byte 0x030046A4
_08013A54:
	ldrb r0, [r5, #4]
	b _08013A5A
_08013A58:
	ldrb r0, [r5]
_08013A5A:
	subs r1, r1, r0
_08013A5C:
	strh r1, [r4, #0x2a]
_08013A5E:
	ldr r1, [r4, #8]
	ldrh r0, [r1, #4]
	strh r0, [r4, #0x2c]
	movs r0, #2
	ldrsh r1, [r1, r0]
	movs r2, #0x2a
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r1, #0
	bgt _08013A7C
	adds r0, r4, #0
	adds r0, #0x56
	ldrb r1, [r0]
	subs r0, #2
	b _08013AA6
_08013A7C:
	adds r0, r4, #0
	adds r0, #0x5a
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08013A92
	adds r2, r4, #0
	adds r2, #0x56
	adds r0, r4, #0
	adds r0, #0x5e
	b _08013AB4
_08013A92:
	adds r0, r4, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble _08013AAC
	adds r0, r4, #0
	adds r0, #0x55
	ldrb r1, [r0]
	subs r0, #1
_08013AA6:
	strb r1, [r0]
	adds r1, r0, #0
	b _08013AC2
_08013AAC:
	adds r2, r4, #0
	adds r2, #0x56
	adds r0, r4, #0
	adds r0, #0x5c
_08013AB4:
	ldrh r0, [r0]
	asrs r1, r0
	ldrb r0, [r2]
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x54
	strb r0, [r1]
_08013AC2:
	adds r2, r1, #0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bgt _08013AD0
	movs r0, #1
	strb r0, [r2]
_08013AD0:
	ldrb r0, [r1]
	strb r0, [r4, #0x14]
	ldrb r0, [r1]
	strb r0, [r4, #0x15]
	ldr r0, [r4, #8]
	movs r1, #2
	ldrsh r0, [r0, r1]
	movs r2, #0x2a
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _08013B10
	cmp r1, #0
	beq _08013B10
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08013AFA
	adds r0, #4
	b _08013B06
_08013AFA:
	ldr r0, _08013B18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08013B06:
	ldrh r0, [r0, #2]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08013B1C
_08013B10:
	ldr r0, [r4, #0xc]
	movs r1, #1
	orrs r0, r1
	b _08013B24
	.align 2, 0
_08013B18: .4byte 0x030046A4
_08013B1C:
	ldr r0, [r4, #0xc]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_08013B24:
	str r0, [r4, #0xc]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Entity08013b68_Update
Entity08013b68_Update: @ 0x08013B2C
	push {r4, lr}
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	beq _08013B42
_08013B34:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r4, [r4, #0x68]
	cmp r4, #0
	bne _08013B34
_08013B42:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity08013b68_Destroy
Entity08013b68_Destroy: @ 0x08013B4C
	ldr r1, _08013B54 @ =0x03000054
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08013B54: .4byte 0x03000054

	thumb_func_start Entity08013b68_Init
Entity08013b68_Init: @ 0x08013B58
	ldr r1, _08013B64 @ =0x03000054
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x1c]
	movs r0, #0
	bx lr
	.align 2, 0
_08013B64: .4byte 0x03000054

	thumb_func_start Entity08013b68_Create
Entity08013b68_Create: @ 0x08013B68
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08013BA0
	ldr r1, _08013B98 @ =Entity08013b68_Update
	ldr r2, _08013B9C @ =Entity08013b68_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity08013b68_Init
	cmp r0, #0
	bge _08013BA0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08013BA2
	.align 2, 0
_08013B98: .4byte Entity08013b68_Update
_08013B9C: .4byte Entity08013b68_Destroy
_08013BA0:
	adds r0, r4, #0
_08013BA2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08013ba8
FUN_08013ba8: @ 0x08013BA8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	mov r8, r3
	ldr r0, _08013BD4 @ =0x03000054
	ldr r7, [r0]
	cmp r7, #0
	bne _08013BD8
	movs r0, #0
	movs r1, #0
	bl Entity08013b68_Create
	adds r7, r0, #0
	cmp r7, #0
	bne _08013BD8
	movs r0, #1
	rsbs r0, r0, #0
	b _08013C58
	.align 2, 0
_08013BD4: .4byte 0x03000054
_08013BD8:
	movs r1, #0
	strb r1, [r6]
	str r4, [r6, #8]
	ldr r0, [sp, #0x30]
	strb r0, [r6, #1]
	strb r1, [r6, #2]
	strh r1, [r6, #4]
	strh r1, [r6, #6]
	adds r0, r6, #0
	adds r0, #0x54
	strb r5, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x56
	ldr r0, [sp, #0x18]
	strb r0, [r1]
	adds r1, #1
	ldr r0, [sp, #0x1c]
	strb r0, [r1]
	adds r1, #1
	ldr r0, [sp, #0x20]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x24]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x2c]
	strh r0, [r1]
	ldrb r0, [r6, #1]
	cmp r0, #0
	bne _08013C28
	ldr r0, _08013C24 @ =FUN_080139b8
	b _08013C2A
	.align 2, 0
_08013C24: .4byte FUN_080139b8
_08013C28:
	ldr r0, _08013C64 @ =FUN_080139b4
_08013C2A:
	str r0, [r6, #0x60]
	adds r5, r6, #0
	adds r5, #0x38
	ldr r1, _08013C68 @ =0x00001C1B
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r4, r6, #0
	adds r4, #0xc
	ldr r2, _08013C6C @ =0x00000202
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a470
	movs r0, #5
	strh r0, [r4, #0x10]
	movs r0, #2
	strb r0, [r6, #0x13]
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_0801392c
	movs r0, #0
_08013C58:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08013C64: .4byte FUN_080139b4
_08013C68: .4byte 0x00001C1B
_08013C6C: .4byte 0x00000202

	thumb_func_start FUN_08013c70
FUN_08013c70: @ 0x08013C70
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc
	bl FUN_0822a4e0
	ldr r0, _08013C90 @ =0x03000054
	ldr r0, [r0]
	cmp r0, #0
	beq _08013C88
	adds r1, r4, #0
	bl FUN_08013954
_08013C88:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08013C90: .4byte 0x03000054

