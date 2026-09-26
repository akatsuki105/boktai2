	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r1, #0
	movs r0, #0x98
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _080DCE2A
	adds r0, r5, #0
	adds r0, #0x1c
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r3, [r1]
	movs r4, #0
	str r4, [sp]
	movs r1, #0x20
	bl Entity080d84f8_Create
	movs r7, #0x1c
	ldrsh r0, [r5, r7]
	movs r2, #0x20
	ldrsh r1, [r5, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #1
	str r3, [sp]
	movs r7, #0x9e
	lsls r7, r7, #1
	adds r3, r5, r7
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	strb r4, [r6]
_080DCE2A:
	ldr r0, _080DCE80 @ =0x0300016C
	ldr r2, [r0]
	ldr r0, _080DCE84 @ =0x0000012F
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r1, _080DCE88 @ =0x00000F68
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r2, #0x97
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0xdc
	bl ParticleShadow_Remove
	adds r0, r5, #0
	adds r0, #0x8c
	bl Hitbox_Unregister
	movs r0, #0xff
	strb r0, [r6]
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	movs r7, #0x99
	lsls r7, r7, #1
	adds r0, r5, r7
	strh r4, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DCE80: .4byte 0x0300016C
_080DCE84: .4byte 0x0000012F
_080DCE88: .4byte 0x00000F68
