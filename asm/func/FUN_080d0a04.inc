	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x20]
	adds r0, r4, #0
	bl FUN_080d0824
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D0A70
	adds r0, r4, #0
	bl FUN_080d0790
	adds r5, r0, #0
	bl FUN_080d0890
	ldr r2, _080D0A9C @ =0x00000446
	adds r0, r4, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D0A5A
	subs r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D0A5A
	movs r1, #1
_080D0A5A:
	cmp r1, #0
	beq _080D0A68
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	muls r0, r5, r0
	asrs r5, r0, #6
_080D0A68:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080cc268
_080D0A70:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080d08b8
	adds r0, r4, #0
	bl PlayerLink_SetAnimFacing
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D0A9C: .4byte 0x00000446
