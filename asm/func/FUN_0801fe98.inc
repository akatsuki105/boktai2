	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	movs r3, #0
	ldrh r0, [r5, #0x1a]
	cmp r3, r0
	bge _0801FED0
	ldr r0, _0801FED8 @ =0x0000042C
	adds r6, r5, r0
	movs r4, #0
	movs r0, #0xfe
	mov ip, r0
_0801FEB2:
	ldr r0, [r6]
	adds r2, r0, r4
	ldrh r0, [r2, #0x34]
	cmp r0, r7
	bne _0801FEC6
	adds r2, #0x36
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	strb r0, [r2]
_0801FEC6:
	adds r4, #0x8c
	adds r3, #1
	ldrh r0, [r5, #0x1a]
	cmp r3, r0
	blt _0801FEB2
_0801FED0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FED8: .4byte 0x0000042C
