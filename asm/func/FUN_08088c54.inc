	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r6, #0
	strb r6, [r0]
	adds r1, r4, #0
	adds r1, #0xe2
	ldrh r0, [r1]
	movs r5, #4
	orrs r0, r5
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0x4b
	bhi _08088C90
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _08088D14
_08088C90:
	cmp r0, #0x53
	bhi _08088CCA
	ldrh r3, [r1]
	adds r2, r4, #0
	adds r2, #0x84
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	adds r0, #0x8c
	strb r5, [r0]
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #0x78
	strb r0, [r1]
	movs r0, #0x54
	subs r0, r0, r3
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xf0
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _08088D14
_08088CCA:
	cmp r0, #0x63
	bhi _08088D14
	ldrh r0, [r1]
	adds r3, r0, #0
	subs r3, #0x54
	movs r0, #0xf
	subs r2, r0, r3
	lsls r1, r2, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x8c
	strb r0, [r1]
	cmp r3, #7
	bgt _08088D04
	lsls r0, r2, #3
	adds r2, r4, #0
	adds r2, #0x8d
	strb r0, [r2]
	movs r0, #8
	subs r0, r0, r3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _08088D14
_08088D04:
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #0x40
	strb r0, [r1]
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r6, [r0]
_08088D14:
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x67
	bls _08088D3E
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl Coffin_SetState
_08088D3E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
