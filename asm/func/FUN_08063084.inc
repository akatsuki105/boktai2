	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_08062c14
	adds r0, r4, #0
	bl FUN_08062c3c
	ldr r0, _080630DC @ =0x0000094C
	adds r1, r4, r0
	ldr r0, _080630E0 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0x95
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080630E4 @ =0x0000094A
	adds r5, r4, r1
	ldrh r0, [r5]
	adds r1, r4, #0
	adds r1, #0xc2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r3, r4, r1
	str r3, [r0]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, [r2]
	ldrh r0, [r5]
	strh r0, [r1, #6]
	ldr r0, [r2]
	str r3, [r0, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08062688
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080630DC: .4byte 0x0000094C
_080630E0: .4byte 0x0000FFFF
_080630E4: .4byte 0x0000094A
