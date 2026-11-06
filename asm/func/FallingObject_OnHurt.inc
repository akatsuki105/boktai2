	push {r4, r5, lr}
	adds r1, r0, #0
	adds r5, r2, #0
	ldrb r4, [r2, #2]
	cmp r4, #0
	bne _0800E4D2
	ldr r0, [r1, #0x38]
	ldrh r3, [r1, #0x3e]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0800E4C8
	lsls r3, r3, #1
	ldrh r0, [r2, #0x10]
	subs r0, r0, r3
	strh r0, [r2, #0x10]
_0800E4C8:
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _0800E4D2
	strh r4, [r5, #0x10]
_0800E4D2:
	pop {r4, r5}
	pop {r0}
	bx r0
