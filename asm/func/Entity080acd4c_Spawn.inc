	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _080ACDF4 @ =0x03002C54
	ldr r0, [r4]
	cmp r0, #0
	bne _080ACDA8
	bl Entity080acd4c_Create
_080ACDA8:
	ldr r2, [r4]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x18
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	movs r1, #0
	strh r1, [r2, #0x2e]
	adds r2, #0x2c
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r4]
	adds r2, r0, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ACDEC
	strh r1, [r2]
_080ACDEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ACDF4: .4byte 0x03002C54
