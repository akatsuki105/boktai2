	push {lr}
	adds r3, r0, #0
	lsls r2, r2, #0x18
	cmp r2, #0
	bne _0822127E
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, r1
	beq _08221296
_0822127E:
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r3, r2
	str r1, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r3, r0
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08221296:
	pop {r0}
	bx r0
	.align 2, 0
