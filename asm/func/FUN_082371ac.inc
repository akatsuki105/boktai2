	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, [r7, #0x10]
	lsrs r2, r2, #0xd
	adds r6, r2, r0
	ldr r1, [r7, #0x18]
	ldr r0, [r6, #4]
	adds r1, r1, r0
	strh r3, [r5, #0x14]
	ldrh r0, [r6, #2]
	cmp r3, r0
	blo _082371D0
	subs r0, #1
	strh r0, [r5, #0x14]
_082371D0:
	ldrh r4, [r5, #0x14]
	lsls r4, r4, #2
	adds r4, r1, r4
	ldrh r2, [r4]
	ldrb r3, [r5, #0x1b]
	adds r0, r5, #0
	adds r1, r7, #0
	bl Sprite_SetSprite
	ldrh r0, [r6, #2]
	strh r0, [r5, #0x16]
	ldrh r1, [r4, #2]
	ldrh r0, [r5, #0x10]
	muls r0, r1, r0
	cmp r0, #0
	blt _082371F4
	asrs r0, r0, #6
	b _082371FA
_082371F4:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_082371FA:
	strh r0, [r5, #0xe]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08237206
	movs r0, #1
	strh r0, [r5, #0xe]
_08237206:
	movs r0, #0
	strh r0, [r5, #0xc]
	strb r0, [r5, #0x1d]
	ldrh r0, [r5, #0xc]
	adds r0, #1
	ldrh r1, [r5, #0xe]
	cmp r0, r1
	blt _08237236
	ldrh r1, [r5, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08237228
	ldrh r0, [r5, #0x14]
	cmp r0, #0
	bne _08237236
	b _08237232
_08237228:
	ldrh r0, [r5, #0x14]
	adds r0, #1
	ldrh r1, [r5, #0x16]
	cmp r0, r1
	blt _08237236
_08237232:
	movs r0, #1
	strb r0, [r5, #0x1d]
_08237236:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
