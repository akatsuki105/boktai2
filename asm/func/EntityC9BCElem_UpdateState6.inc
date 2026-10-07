	push {r4, lr}
	sub sp, #0xc
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D42E
	movs r0, #0
	strb r0, [r4, #1]
	add r2, sp, #4
	ldr r0, [r4, #0x50]
	ldr r1, [r4, #0x54]
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r2, #0
	ldrh r0, [r0]
	adds r0, #0x40
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r2, #4]
	adds r0, #0x40
	strh r0, [r2, #4]
	movs r0, #7
	str r0, [sp]
	adds r0, r1, #0
	movs r1, #0x90
	movs r2, #0x28
	movs r3, #8
	bl FUN_08019814
_0800D42E:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r3, #0
	orrs r1, r0
	strh r1, [r4, #0x2a]
	ldr r2, [r4, #4]
	cmp r2, #0xf
	bhi _0800D448
	movs r0, #7
	ands r0, r2
	cmp r0, #4
	bne _0800D456
	b _0800D450
_0800D448:
	movs r0, #3
	ands r0, r2
	cmp r0, #2
	bne _0800D456
_0800D450:
	movs r0, #0xc
	orrs r1, r0
	strh r1, [r4, #0x2a]
_0800D456:
	cmp r2, #0x1f
	bls _0800D462
	adds r1, r4, #0
	adds r1, #0x44
	movs r0, #1
	strb r0, [r1]
_0800D462:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
