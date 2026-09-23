	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r2, #0
	ldrh r0, [r4, #0x1a]
	cmp r2, r0
	bge _0801FE8C
	ldr r0, _0801FE94 @ =0x0000042C
	adds r5, r4, r0
	movs r7, #1
	movs r3, #0
_0801FE70:
	ldr r0, [r5]
	adds r1, r0, r3
	ldrh r0, [r1, #0x34]
	cmp r0, r6
	bne _0801FE82
	adds r1, #0x36
	ldrb r0, [r1]
	orrs r0, r7
	strb r0, [r1]
_0801FE82:
	adds r3, #0x8c
	adds r2, #1
	ldrh r0, [r4, #0x1a]
	cmp r2, r0
	blt _0801FE70
_0801FE8C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FE94: .4byte 0x0000042C
