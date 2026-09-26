	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r2, [r1]
	cmp r2, #0
	bne _080A997A
	ldr r0, [r7, #0x18]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r2, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080A997A:
	movs r0, #0
	mov sb, r0
	ldr r0, [r7, #0x18]
	ldr r4, _080A9AA8 @ =0x00000366
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x96
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bne _080A9994
	movs r2, #1
_080A9994:
	ldr r0, [r7, #0x18]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r3, _080A9AAC @ =0x0000FFFF
	mov r8, r3
	ldr r3, [r7, #0x18]
	adds r0, r3, r4
	ldrh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r2
	blo _080A99C6
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	ldr r0, _080A9AB0 @ =0x00000259
	bl sound_08240740
	movs r3, #1
	mov sb, r3
_080A99C6:
	ldr r6, _080A9AB4 @ =0x0203B400
	ldr r4, _080A9AB8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080A9ABC @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #3
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7c
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #1
	strh r1, [r7, #0x3c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #3
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7e
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #1
	strh r1, [r7, #0x3e]
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r5, #7
	ands r5, r0
	cmp r5, #0
	bne _080A9A44
	ldr r3, _080A9AC0 @ =0x0000026E
	adds r4, r7, r3
	ldrh r1, [r4]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x8c
	adds r0, r7, r0
	bl FUN_080a975c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, #7
	bls _080A9A44
	strh r5, [r4]
_080A9A44:
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r0, [r0]
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	bne _080A9A78
	ldr r0, _080A9AC0 @ =0x0000026E
	adds r4, r7, r0
	ldrh r1, [r4]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x8c
	adds r0, r7, r0
	bl FUN_080a9840
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080A9A78
	strh r5, [r4]
_080A9A78:
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	mov r0, sb
	cmp r0, #0
	beq _080A9A9C
	adds r3, #8
	adds r1, r7, r3
	ldr r0, _080A9AC4 @ =FUN_080a98f0
	str r0, [r1]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
_080A9A9C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9AA8: .4byte 0x00000366
_080A9AAC: .4byte 0x0000FFFF
_080A9AB0: .4byte 0x00000259
_080A9AB4: .4byte 0x0203B400
_080A9AB8: .4byte 0x030046B8
_080A9ABC: .4byte 0x000003FF
_080A9AC0: .4byte 0x0000026E
_080A9AC4: .4byte FUN_080a98f0
