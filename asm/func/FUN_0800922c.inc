	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	cmp r2, #0
	beq _0800923C
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r2]
_0800923C:
	ldr r3, [r4, #0x20]
	movs r1, #0
	ldrb r0, [r4, #0x18]
	cmp r1, r0
	bge _0800926E
	movs r7, #1
	ldr r5, [r4, #0x1c]
	adds r4, r0, #0
_0800924C:
	adds r0, r7, #0
	lsls r0, r1
	ands r0, r5
	cmp r0, #0
	beq _08009266
	ldrh r0, [r3]
	cmp r0, r6
	bne _08009266
	cmp r2, #0
	beq _08009262
	str r1, [r2]
_08009262:
	adds r0, r3, #0
	b _08009270
_08009266:
	adds r1, #1
	adds r3, #0x6c
	cmp r1, r4
	blt _0800924C
_0800926E:
	movs r0, #0
_08009270:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
