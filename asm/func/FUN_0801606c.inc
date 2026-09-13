	push {lr}
	ldrh r3, [r1, #0x3e]
	movs r1, #8
	ldr r0, [r0, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0801607C
	lsls r3, r3, #1
_0801607C:
	ldrh r0, [r2, #0x16]
	subs r0, r0, r3
	strh r0, [r2, #0x16]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0801608C
	movs r0, #0
	strh r0, [r2, #0x16]
_0801608C:
	pop {r0}
	bx r0
