	push {r4, r5, lr}
	adds r3, r0, #0
	ldrb r4, [r3, #0x1a]
	lsls r4, r4, #1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r3, r1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r3, r2
	adds r1, r1, r4
	ldrh r1, [r1]
	movs r5, #0xad
	lsls r5, r5, #2
	adds r2, r3, r5
	adds r2, r2, r4
	ldrh r2, [r2]
	adds r5, #0x80
	adds r3, r3, r5
	adds r3, r3, r4
	ldrh r3, [r3]
	bl TextBox_SetRect
	pop {r4, r5}
	pop {r0}
	bx r0
