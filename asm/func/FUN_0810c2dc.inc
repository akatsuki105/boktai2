	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _0810C2FC @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810C300
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810C302
	.align 2, 0
_0810C2FC: .4byte 0x0000046D
_0810C300:
	movs r0, #0
_0810C302:
	adds r2, r0, #0
	cmp r2, #0
	beq _0810C3F0
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r3, r0
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r2, r3, r0
	ldrh r0, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r4, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r4, r0
	mvns r1, r1
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	ldrb r3, [r4, #5]
	ldr r2, _0810C37C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810C380 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0810C384 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r1, r0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r5, r4, r0
	adds r6, r3, #0
	adds r7, r1, #0
	adds r7, #0x1c
	ldr r3, _0810C388 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0810C38C
	asrs r1, r0, #0xc
	b _0810C392
	.align 2, 0
_0810C37C: .4byte 0x030046B8
_0810C380: .4byte 0x000003FF
_0810C384: .4byte 0x0203B400
_0810C388: .4byte gSineTable
_0810C38C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810C392:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0810C3AA
	asrs r0, r0, #0xc
	b _0810C3B0
_0810C3AA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810C3B0:
	strh r0, [r5, #4]
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810C3E8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0810C3EC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x18
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ParticleShadow_Show
	b _0810C458
	.align 2, 0
_0810C3E8: .4byte 0x000003FF
_0810C3EC: .4byte 0x0203B400
_0810C3F0:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0810C40A
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r2, [r0]
_0810C40A:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810C458
	movs r1, #0x80
	lsls r1, r1, #4
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810C430
	movs r0, #1
	b _0810C432
_0810C430:
	movs r0, #0
_0810C432:
	cmp r0, #0
	beq _0810C43C
	ldr r0, _0810C460 @ =0x000003AD
	bl PlaySound_082406e0
_0810C43C:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #1
	mov r0, sp
	strh r1, [r0]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080e59d0
_0810C458:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810C460: .4byte 0x000003AD
