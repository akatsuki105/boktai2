	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r2, _0817FF14 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FF18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817FF1A
	.align 2, 0
_0817FF14: .4byte 0x0000046D
_0817FF18:
	movs r0, #0
_0817FF1A:
	cmp r0, #0
	beq _0817FF3A
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0xf
	bl Enemy_PlayAnim
	ldr r0, _0817FF7C @ =0x000003D1
	bl PlaySound_082406e0
_0817FF3A:
	ldrh r0, [r4, #0x14]
	cmp r0, #4
	beq _0817FF42
	b _081801FA
_0817FF42:
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	beq _0817FF4A
	b _081801FA
_0817FF4A:
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r1, [sp, #0x1c]
	asrs r0, r1, #0x10
	adds r0, #0xdc
	lsls r0, r0, #0x10
	ldr r3, _0817FF80 @ =0x0000FFFF
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #0x1c]
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0817FFB0
	cmp r0, #1
	bgt _0817FF84
	cmp r0, #0
	beq _0817FF8E
	b _08180012
	.align 2, 0
_0817FF7C: .4byte 0x000003D1
_0817FF80: .4byte 0x0000FFFF
_0817FF84:
	cmp r0, #2
	beq _0817FFDC
	cmp r0, #3
	beq _0817FFFC
	b _08180012
_0817FF8E:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817FFAC @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	subs r0, #0x30
	b _0817FFCA
	.align 2, 0
_0817FFAC: .4byte 0xFFFF0000
_0817FFB0:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	subs r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817FFD8 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	adds r0, #0x80
_0817FFCA:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x20]
	b _08180012
	.align 2, 0
_0817FFD8: .4byte 0xFFFF0000
_0817FFDC:
	add r0, sp, #0x1c
	ldrh r0, [r0]
	ldr r1, _0817FFF4 @ =0xFFFFFF00
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0817FFF8 @ =0xFFFF0000
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x1c]
	b _08180012
	.align 2, 0
_0817FFF4: .4byte 0xFFFFFF00
_0817FFF8: .4byte 0xFFFF0000
_0817FFFC:
	add r0, sp, #0x1c
	ldrh r1, [r0, #4]
	ldr r2, _081800A8 @ =0xFFFFFF00
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081800AC @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
_08180012:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _081800B0 @ =0x00000546
	adds r0, r7, r2
	movs r2, #2
	str r2, [sp, #0x28]
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0818002E
	movs r0, #6
	str r0, [sp, #0x28]
_0818002E:
	adds r0, r7, #0
	bl FUN_0817ea84
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081800C0
	ldrb r1, [r7, #5]
	subs r1, #4
	movs r2, #8
	str r2, [sp]
	movs r0, #0x12
	mov sb, r0
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r2, _081800B4 @ =0x00000226
	adds r2, r2, r7
	mov r8, r2
	ldrh r0, [r2]
	str r0, [sp, #0xc]
	ldr r0, _081800B8 @ =0x0000022E
	adds r6, r7, r0
	ldrh r0, [r6]
	str r0, [sp, #0x10]
	movs r2, #0x90
	lsls r2, r2, #2
	adds r5, r7, r2
	ldr r0, [r5]
	str r0, [sp, #0x14]
	ldr r0, _081800BC @ =0x00000236
	adds r4, r7, r0
	ldrh r0, [r4]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x78
	ldr r3, [sp, #0x28]
	bl FUN_080dfeb0
	ldrb r1, [r7, #5]
	adds r1, #4
	movs r2, #8
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r0, #0x80
	str r0, [sp, #8]
	mov r2, r8
	ldrh r0, [r2]
	str r0, [sp, #0xc]
	ldrh r0, [r6]
	str r0, [sp, #0x10]
	ldr r0, [r5]
	str r0, [sp, #0x14]
	ldrh r0, [r4]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x78
	ldr r3, [sp, #0x28]
	bl FUN_080dfeb0
	b _081801DE
	.align 2, 0
_081800A8: .4byte 0xFFFFFF00
_081800AC: .4byte 0xFFFF0000
_081800B0: .4byte 0x00000546
_081800B4: .4byte 0x00000226
_081800B8: .4byte 0x0000022E
_081800BC: .4byte 0x00000236
_081800C0:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r1, [r0]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	adds r2, r0, #0
	cmp r1, #0x80
	ble _081800DC
	ldr r0, _081800D8 @ =0xFFFFFF00
	b _081800E8
	.align 2, 0
_081800D8: .4byte 0xFFFFFF00
_081800DC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081800EA
	movs r0, #0x80
	lsls r0, r0, #1
_081800E8:
	adds r1, r1, r0
_081800EA:
	cmp r1, #0
	bge _081800F0
	rsbs r1, r1, #0
_081800F0:
	cmp r1, #0x17
	bgt _08180170
	adds r1, r2, #0
	subs r1, #0xc
	ldr r2, [sp, #0x28]
	adds r2, #2
	mov sl, r2
	movs r0, #0xc
	str r0, [sp]
	movs r2, #0x16
	mov sb, r2
	str r2, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _08180168 @ =0x00000226
	adds r0, r0, r7
	mov r8, r0
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	ldr r2, _0818016C @ =0x0000022E
	adds r6, r7, r2
	ldrh r0, [r6]
	str r0, [sp, #0x10]
	movs r0, #0x90
	lsls r0, r0, #2
	adds r5, r7, r0
	ldr r0, [r5]
	str r0, [sp, #0x14]
	adds r2, #8
	adds r4, r7, r2
	ldrh r0, [r4]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x78
	mov r3, sl
	bl FUN_080dfeb0
	ldrb r1, [r7, #5]
	adds r1, #0xc
	movs r0, #0xc
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r0, #0x80
	str r0, [sp, #8]
	mov r2, r8
	ldrh r0, [r2]
	str r0, [sp, #0xc]
	ldrh r0, [r6]
	str r0, [sp, #0x10]
	ldr r0, [r5]
	str r0, [sp, #0x14]
	ldrh r0, [r4]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x78
	mov r3, sl
	bl FUN_080dfeb0
	b _081801DE
	.align 2, 0
_08180168: .4byte 0x00000226
_0818016C: .4byte 0x0000022E
_08180170:
	adds r1, r2, #0
	subs r1, #0x20
	ldr r0, [sp, #0x28]
	adds r0, #4
	str r0, [sp, #0x2c]
	movs r4, #0x14
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r2, _0818021C @ =0x00000226
	adds r2, r2, r7
	mov sb, r2
	ldrh r0, [r2]
	str r0, [sp, #0xc]
	ldr r0, _08180220 @ =0x0000022E
	adds r0, r0, r7
	mov r8, r0
	ldrh r0, [r0]
	str r0, [sp, #0x10]
	movs r2, #0x90
	lsls r2, r2, #2
	adds r6, r7, r2
	ldr r0, [r6]
	str r0, [sp, #0x14]
	ldr r0, _08180224 @ =0x00000236
	adds r5, r7, r0
	ldrh r0, [r5]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x14
	ldr r3, [sp, #0x2c]
	bl FUN_080dfeb0
	ldrb r1, [r7, #5]
	adds r1, #0x20
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x80
	str r0, [sp, #8]
	mov r2, sb
	ldrh r0, [r2]
	str r0, [sp, #0xc]
	mov r2, r8
	ldrh r0, [r2]
	str r0, [sp, #0x10]
	ldr r0, [r6]
	str r0, [sp, #0x14]
	ldrh r0, [r5]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	movs r2, #0x14
	ldr r3, [sp, #0x2c]
	bl FUN_080dfeb0
_081801DE:
	ldr r0, [sp, #0x24]
	ldr r1, _08180228 @ =0x00000898
	adds r2, r0, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0818022C @ =0x000003D2
	bl PlaySound_082406e0
	ldr r0, _08180230 @ =0x000002D1
	bl PlaySound_082406e0
_081801FA:
	ldr r2, _08180234 @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0818020C
	ldr r0, _08180238 @ =0x0000046B
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_0818020C:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818021C: .4byte 0x00000226
_08180220: .4byte 0x0000022E
_08180224: .4byte 0x00000236
_08180228: .4byte 0x00000898
_0818022C: .4byte 0x000003D2
_08180230: .4byte 0x000002D1
_08180234: .4byte 0x0000046E
_08180238: .4byte 0x0000046B
