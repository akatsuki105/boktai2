	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x24
	ldrb r0, [r4]
	bl AlbumMenu_GetPhotoSlotCount
	mov r8, r0
	ldrb r0, [r4]
	bl FUN_08211164
	mov sb, r0
	movs r0, #0x91
	lsls r0, r0, #3
	adds r4, r7, r0
	movs r6, #0
	cmp r6, r8
	bge _0821179C
_0821175A:
	mov r3, sb
	adds r5, r3, r6
	adds r0, r5, #0
	bl CheckPhotoUnlocked
	cmp r0, #0
	beq _0821178C
	ldr r1, _08211788 @ =0x085AF9B4
	lsls r0, r5, #2
	adds r0, r0, r1
	ldrh r2, [r0]
	adds r0, r4, #0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r7, r3
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _08211792
	.align 2, 0
_08211788: .4byte 0x085AF9B4
_0821178C:
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
_08211792:
	str r0, [r4, #8]
	adds r4, #0x60
	adds r6, #1
	cmp r6, r8
	blt _0821175A
_0821179C:
	cmp r6, #9
	bgt _082117B0
	movs r1, #1
_082117A2:
	ldr r0, [r4, #8]
	orrs r0, r1
	str r0, [r4, #8]
	adds r4, #0x60
	adds r6, #1
	cmp r6, #9
	ble _082117A2
_082117B0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
