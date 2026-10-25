	push {r4, r5, r6, lr}
	adds r4, r1, #0
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	adds r3, r0, #0
	cmp r3, #0
	beq _0803C6E6
	movs r5, #0
	ldrsh r1, [r3, r5]
	movs r6, #0
	ldrsh r0, [r4, r6]
	movs r5, #0
	cmp r1, r0
	blt _0803C6DE
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bgt _0803C6DE
	movs r0, #4
	ldrsh r3, [r3, r0]
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r3, r0
	blt _0803C6DE
	movs r6, #4
	ldrsh r0, [r2, r6]
	cmp r3, r0
	bgt _0803C6DE
	movs r5, #1
_0803C6DE:
	cmp r5, #0
	beq _0803C6E6
	movs r0, #0
	b _0803C6EA
_0803C6E6:
	movs r0, #1
	rsbs r0, r0, #0
_0803C6EA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
