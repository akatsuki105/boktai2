	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x74]
	movs r6, #0
	b _0800D9FE
_0800D9EE:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0800cb7c
	adds r6, #1
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r5, r5, r0
_0800D9FE:
	ldr r0, [r4, #0x1c]
	cmp r6, r0
	blo _0800D9EE
	ldr r0, [r4, #0x74]
	cmp r0, #0
	beq _0800DA12
	bl Free
	movs r0, #0
	str r0, [r4, #0x74]
_0800DA12:
	ldr r1, _0800DA20 @ =0x03002B38
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0800DA20: .4byte 0x03002B38
