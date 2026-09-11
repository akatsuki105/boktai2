	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08009B64
	movs r0, #0xe0
	lsls r0, r0, #1
	ldr r3, [r3, #0x34]
	ands r3, r0
	cmp r3, #0
	bne _08009B64
	adds r1, r4, #0
	adds r1, #0x43
	movs r0, #1
	strb r0, [r1]
	strb r0, [r2, #2]
	strh r3, [r2, #0xa]
	strb r0, [r2, #7]
	ldrh r1, [r2, #0x1a]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #0x1a]
_08009B64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
