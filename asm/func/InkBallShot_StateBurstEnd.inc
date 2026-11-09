	push {r4, r5, lr}
	sub sp, #8
	adds r5, r1, #0
	adds r3, r5, #0
	adds r3, #0xfb
	ldrb r0, [r3]
	cmp r0, #0
	bne _082032FC
	movs r0, #0x1f
	strh r0, [r5, #0x10]
	adds r2, r5, #0
	adds r2, #0x3c
	subs r0, #0x24
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_082032FC:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bls _08203340
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r5, #0
	adds r1, #0xf0
	ldrh r1, [r1]
	adds r2, r5, #0
	adds r2, #0xf2
	ldrh r2, [r2]
	adds r3, r5, #0
	adds r3, #0xf4
	ldrh r3, [r3]
	adds r4, r5, #0
	adds r4, #0xf6
	ldrh r4, [r4]
	str r4, [sp]
	adds r4, r5, #0
	adds r4, #0xf8
	ldrh r4, [r4]
	str r4, [sp, #4]
	bl InkBallPuddle_Spawn
	movs r0, #0xf2
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl InkBallShotManager_Remove
_08203340:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
