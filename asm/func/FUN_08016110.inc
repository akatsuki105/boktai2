	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, _0801618C @ =0x03002B44
	ldr r0, [r0]
	cmp r0, #0
	bne _08016136
	ldr r0, _08016190 @ =0x0000C0DB
	movs r1, #0
	bl Entity08016660_Create
	cmp r0, #0
	bne _08016136
	b _0801630A
_08016136:
	movs r0, #0x80
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	bne _08016144
	b _0801630A
_08016144:
	adds r0, r4, #0
	movs r1, #0x80
	bl ClearMemory
	strb r5, [r4]
	strb r6, [r4, #3]
	strh r7, [r4, #8]
	ldr r0, [sp, #0x34]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0xc]
	str r1, [r4, #0x10]
	adds r6, r4, #0
	adds r6, #0xc
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _08016186
	cmp r1, #0
	blt _08016186
	ldr r0, _08016194 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08016186
	ldr r0, _08016198 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0801619C
_08016186:
	movs r5, #0
	b _080161AA
	.align 2, 0
_0801618C: .4byte 0x03002B44
_08016190: .4byte 0x0000C0DB
_08016194: .4byte 0x030046A8
_08016198: .4byte 0x030046AC
_0801619C:
	ldr r0, _080161BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080161AA:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080161C0
	adds r0, #4
	b _080161CC
	.align 2, 0
_080161BC: .4byte 0x030046A4
_080161C0:
	ldr r0, _080161E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080161CC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080161E4
	cmp r2, #2
	beq _080161E8
	b _080161EC
	.align 2, 0
_080161E0: .4byte 0x030046A4
_080161E4:
	ldrb r0, [r6, #4]
	b _080161EA
_080161E8:
	ldrb r0, [r6]
_080161EA:
	subs r1, r1, r0
_080161EC:
	strh r1, [r4, #0x14]
	mov r0, r8
	strh r0, [r4, #0x16]
	ldrb r0, [r4, #3]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0801627C
	movs r0, #0x50
	bl Malloc
	str r0, [r4, #0x18]
	cmp r0, #0
	bne _0801620A
	b _0801630A
_0801620A:
	movs r1, #0x50
	bl ClearMemory
	ldr r2, _0801626C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x5a
	orrs r0, r3
	ldr r1, _08016270 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r0, [r4, #0x18]
	ldr r2, _08016274 @ =0x00004001
	movs r1, #0x10
	str r1, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r4, #0x18]
	ldr r1, _08016278 @ =FUN_0801606c
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r0, [r4, #0x18]
	bl FUN_08236400
	ldr r0, [r4, #0x18]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _0801627E
	.align 2, 0
_0801626C: .4byte 0xFFFF0000
_08016270: .4byte 0x0000FFFF
_08016274: .4byte 0x00004001
_08016278: .4byte FUN_0801606c
_0801627C:
	str r1, [r4, #0x18]
_0801627E:
	ldrb r0, [r4, #3]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _080162F8
	movs r0, #0x50
	bl Malloc
	str r0, [r4, #0x1c]
	cmp r0, #0
	beq _0801630A
	movs r1, #0x50
	bl ClearMemory
	movs r2, #0
	movs r3, #0x64
	add r0, sp, #0xc
	strh r3, [r0]
	adds r1, r0, #0
	movs r0, #0x78
	strh r0, [r1, #2]
	strh r3, [r1, #4]
	add r3, sp, #0x14
	strh r2, [r3]
	strh r2, [r3, #2]
	strh r2, [r3, #4]
	ldr r0, [r4, #0x1c]
	ldr r2, _080162F0 @ =0x00002001
	movs r1, #0x10
	str r1, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r4, #0x1c]
	ldr r1, _080162F4 @ =nop_08016090
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r0, [r4, #0x1c]
	movs r1, #0x32
	movs r2, #0x14
	bl FUN_082364f0
	ldr r0, [r4, #0x1c]
	bl FUN_08236400
	ldr r0, [r4, #0x1c]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _080162FA
	.align 2, 0
_080162F0: .4byte 0x00002001
_080162F4: .4byte nop_08016090
_080162F8:
	str r1, [r4, #0x1c]
_080162FA:
	adds r5, r4, #0
	adds r5, #0x20
	ldr r1, _08016310 @ =0x0000863A
	adds r0, r5, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08016314
_0801630A:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801637A
	.align 2, 0
_08016310: .4byte 0x0000863A
_08016314:
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	adds r1, r4, #0
	adds r1, #0x43
	movs r6, #0
	movs r0, #2
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x68
	ldr r1, _08016358 @ =0x03002B44
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r6, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrb r1, [r4]
	ldr r0, _0801635C @ =0x00000113
	adds r1, r1, r0
	adds r0, r5, #0
	bl Video_SetActorSpritePltt
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08016360
	movs r0, #1
	strb r0, [r4, #2]
	strh r6, [r4, #6]
	b _08016366
	.align 2, 0
_08016358: .4byte 0x03002B44
_0801635C: .4byte 0x00000113
_08016360:
	strb r6, [r4, #2]
	strh r6, [r4, #6]
	movs r0, #1
_08016366:
	strb r0, [r4, #1]
	movs r0, #0
	strb r0, [r4, #5]
	str r0, [r4, #0x78]
	str r0, [r4, #0x7c]
	ldr r0, _08016388 @ =0x03002B44
	ldr r0, [r0]
	adds r1, r4, #0
	bl FUN_08016094
_0801637A:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016388: .4byte 0x03002B44
