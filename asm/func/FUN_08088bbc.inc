	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r4, r5, r2
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08086024
	ldrh r0, [r4]
	cmp r0, #0x1b
	bls _08088C4C
	cmp r0, #0x2b
	bhi _08088C28
	adds r4, r0, #0
	adds r3, r4, #0
	subs r3, #0x1c
	adds r2, r5, #0
	adds r2, #0x84
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	lsls r1, r3, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x8c
	strb r0, [r1]
	cmp r3, #8
	ble _08088C4C
	lsls r0, r3, #3
	adds r2, #9
	strb r0, [r2]
	adds r1, r4, #0
	subs r1, #0x24
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	b _08088C36
_08088C28:
	cmp r0, #0x33
	bhi _08088C40
	ldrh r0, [r4]
	subs r0, #0x2c
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xf0
_08088C36:
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	b _08088C4C
_08088C40:
	adds r0, r5, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_08088C4C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
