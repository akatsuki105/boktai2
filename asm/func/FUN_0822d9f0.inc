	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldrb r5, [r4, #4]
	cmp r5, #0
	bne _0822DA46
	str r7, [r4]
	str r5, [r4, #0x14]
	movs r0, #2
	strb r0, [r4, #0xf]
	strb r5, [r4, #0x10]
	strb r5, [r4, #7]
	movs r0, #0x40
	strb r0, [r4, #5]
	strb r0, [r4, #6]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0822dad4
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822dafc
	ldrh r0, [r6, #6]
	ldr r1, _0822DA4C @ =0x03003584
	lsls r2, r0, #5
	ldr r1, [r1]
	adds r1, r1, r2
	bl FUN_0822d12c
	strb r0, [r4, #0xe]
	movs r1, #0x80
	ands r1, r7
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	str r5, [r4, #0x20]
	str r5, [r4, #0x24]
	adds r0, r4, #0
	bl FUN_0822a398
_0822DA46:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822DA4C: .4byte 0x03003584
