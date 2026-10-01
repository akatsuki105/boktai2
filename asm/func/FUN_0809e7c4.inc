	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809E816
	movs r0, #1
	strb r0, [r1]
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0x26
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r5, r0
	bge _0809E816
	adds r3, r4, #0
	adds r3, #0xc6
	movs r7, #0
	movs r1, #0x34
	adds r1, r1, r4
	mov ip, r1
_0809E7F0:
	ldrb r0, [r3, #3]
	cmp r0, #0
	beq _0809E80A
	ldrb r0, [r3]
	cmp r0, #0
	beq _0809E80A
	mov r1, ip
	adds r0, r1, r7
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0809E80A:
	adds r3, #0xa8
	adds r7, #0xa8
	adds r5, #1
	ldrb r0, [r6]
	cmp r5, r0
	blt _0809E7F0
_0809E816:
	adds r0, r4, #0
	bl FUN_0809e75c
	ldr r1, [r4, #0x18]
	movs r0, #0x20
	ldr r1, [r1, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809E82C
	movs r1, #2
	b _0809E834
_0809E82C:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809E834:
	adds r0, r4, #0
	bl FUN_0809e630
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
