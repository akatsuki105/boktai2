	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r0, #0xf6
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrh r0, [r7, #0x36]
	subs r0, #0xb0
	movs r3, #0
	strh r0, [r2, #0x20]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r2, r7, r1
	movs r4, #0x36
	ldrsh r1, [r7, r4]
	movs r4, #0x30
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bge _0801E770
	adds r1, r7, #0
	adds r1, #0x38
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xb0
	cmp r0, #1
	beq _0801E7BA
	movs r0, #1
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #0
	b _0801E792
_0801E770:
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bge _0801E79A
	adds r1, r7, #0
	adds r1, #0x38
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xb0
	cmp r0, #2
	beq _0801E7BA
	movs r0, #2
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #1
_0801E792:
	movs r3, #1
	bl MainSprite_SetAnim
	b _0801E7BA
_0801E79A:
	adds r1, r7, #0
	adds r1, #0x38
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xb0
	cmp r0, #3
	beq _0801E7BA
	movs r0, #3
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
_0801E7BA:
	movs r0, #0x20
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r4, r7, r1
	movs r5, #0xc
_0801E7C8:
	adds r0, r4, #0
	adds r1, r6, #0
	bl MainSprite_AdvanceAnim
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801E7C8
	movs r5, #0xd
	mov r0, r8
	ldrb r4, [r0]
	cmp r4, #0
	beq _0801E806
	movs r0, #0
	mov r1, r8
	strb r0, [r1]
	subs r5, #0x10
	movs r6, #0
	movs r4, #0xf
_0801E7EE:
	adds r1, r5, #6
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r2, #0x10
	movs r3, #1
	bl Video_SetBGTile
	adds r5, #1
	cmp r5, #0xa
	ble _0801E7EE
	b _0801E888
_0801E806:
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #3
	movs r2, #0x10
	movs r3, #2
	bl Video_SetBGTile
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #4
	movs r2, #0x10
	movs r3, #3
	bl Video_SetBGTile
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #5
	movs r2, #0x10
	movs r3, #4
	bl Video_SetBGTile
	movs r5, #0
	b _0801E850
_0801E83A:
	adds r1, r5, #6
	movs r0, #0
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #2
	movs r2, #0x10
	movs r3, #5
	bl Video_SetBGTile
	adds r5, #1
_0801E850:
	ldr r0, [r7, #0x40]
	cmp r5, r0
	blo _0801E83A
	cmp r5, #9
	bgt _0801E874
	movs r6, #0
	movs r4, #0xd
_0801E85E:
	adds r1, r5, #6
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r2, #0x10
	movs r3, #6
	bl Video_SetBGTile
	adds r5, #1
	cmp r5, #9
	ble _0801E85E
_0801E874:
	movs r0, #0
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x10
	movs r3, #7
	bl Video_SetBGTile
_0801E888:
	ldrb r4, [r7, #0x1f]
	mov sb, r4
	cmp r4, #0
	beq _0801E8E8
	movs r4, #0
	strb r4, [r7, #0x1f]
	str r4, [sp]
	movs r5, #0xf
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x15
	movs r2, #0x10
	movs r3, #1
	bl Video_SetBGTile
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x16
	movs r2, #0x10
	movs r3, #1
	bl Video_SetBGTile
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x17
	movs r2, #0x10
	movs r3, #1
	bl Video_SetBGTile
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x18
	movs r2, #0x10
	movs r3, #1
	bl Video_SetBGTile
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x19
	movs r2, #0x10
	movs r3, #1
	bl Video_SetBGTile
	b _0801E944
_0801E8E8:
	adds r4, r7, #0
	adds r4, #0x8c
	ldr r0, [r4]
	movs r1, #0x3c
	bl Mod
	movs r1, #0x64
	muls r0, r1, r0
	movs r1, #0x3c
	bl Div
	mov r8, r0
	ldr r0, [r4]
	movs r1, #0x3c
	bl Div
	adds r3, r0, #0
	movs r6, #0x11
	str r6, [sp]
	movs r5, #2
	str r5, [sp, #4]
	movs r4, #0xd
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #0x15
	movs r2, #0x10
	bl Video_DrawBGNumber
	mov r0, sb
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r1, #0x17
	movs r2, #0x10
	movs r3, #0x1b
	bl Video_SetBGTile
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #0x18
	movs r2, #0x10
	mov r3, r8
	bl Video_DrawBGNumber
_0801E944:
	adds r0, r7, #0
	bl FUN_0801e6a0
	adds r0, r7, #0
	bl FUN_0801e3d0
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
