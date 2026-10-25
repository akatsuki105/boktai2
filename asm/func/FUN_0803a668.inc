	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A6BA
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0x1d
	bl Boss_PlayAnim
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r0, _0803A6E8 @ =0x0000FFFA
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, #0
	bl FUN_08036884
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
_0803A6BA:
	movs r2, #0x1c
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A6E8: .4byte 0x0000FFFA
