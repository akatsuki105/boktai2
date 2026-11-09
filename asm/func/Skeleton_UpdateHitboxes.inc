	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08103694
	b _0810387A
_08103694:
	ldr r2, _081036AC @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #8
	bne _081036B4
	ldr r0, _081036B0 @ =0x0000065E
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _0810387A
	.align 2, 0
_081036AC: .4byte 0x000001DF
_081036B0: .4byte 0x0000065E
_081036B4:
	movs r1, #0x80
	lsls r1, r1, #4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081036C8
	b _0810387A
_081036C8:
	ldr r1, _08103704 @ =0x00000553
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x38
	bne _081036D4
	b _0810387A
_081036D4:
	cmp r0, #0x3c
	bne _081036DA
	b _0810387A
_081036DA:
	ldr r2, _08103708 @ =0x00000724
	adds r3, r5, r2
	ldrb r0, [r3]
	cmp r0, #0
	beq _08103710
	adds r2, r4, #0
	adds r2, #0xde
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0810370C @ =0x0000065E
	adds r2, r5, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	b _08103728
	.align 2, 0
_08103704: .4byte 0x00000553
_08103708: .4byte 0x00000724
_0810370C: .4byte 0x0000065E
_08103710:
	adds r3, r4, #0
	adds r3, #0xde
	ldrh r2, [r3]
	ldr r1, _0810375C @ =0x0000FFFB
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r0, _08103760 @ =0x0000065E
	adds r2, r5, r0
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
_08103728:
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	ldr r2, _08103764 @ =gSineTable
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08103768
	asrs r1, r0, #0xc
	b _0810376E
	.align 2, 0
_0810375C: .4byte 0x0000FFFB
_08103760: .4byte 0x0000065E
_08103764: .4byte gSineTable
_08103768:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810376E:
	mov r0, sp
	ldrh r0, [r0]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldr r1, _08103790 @ =gSineTable
	ldrb r2, [r4, #5]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08103794
	asrs r3, r0, #0xc
	b _0810379A
	.align 2, 0
_08103790: .4byte gSineTable
_08103794:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0810379A:
	mov r1, sp
	ldrh r0, [r1, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	adds r0, r2, #0
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _08103808
	cmp r0, #1
	bgt _081037BA
	cmp r0, #0
	beq _081037C4
	b _08103848
_081037BA:
	cmp r0, #2
	beq _081037C4
	cmp r0, #3
	beq _08103808
	b _08103848
_081037C4:
	ldr r2, _081037E4 @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #6
	bne _081037EC
	ldr r3, _081037E8 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0xb4
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x54
	b _08103844
	.align 2, 0
_081037E4: .4byte 0x000001DF
_081037E8: .4byte 0xFFFF0000
_081037EC:
	ldr r3, _08103804 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0xa0
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x40
	b _08103844
	.align 2, 0
_08103804: .4byte 0xFFFF0000
_08103808:
	ldr r1, _08103828 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _08103830
	ldr r3, _0810382C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0x54
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0xb4
	b _08103844
	.align 2, 0
_08103828: .4byte 0x000001DF
_0810382C: .4byte 0xFFFF0000
_08103830:
	ldr r3, _08103884 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0x40
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0xa0
_08103844:
	orrs r0, r1
	str r0, [r2, #4]
_08103848:
	ldr r1, _08103888 @ =0x0000FFFF
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #8]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
_0810387A:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08103884: .4byte 0xFFFF0000
_08103888: .4byte 0x0000FFFF
