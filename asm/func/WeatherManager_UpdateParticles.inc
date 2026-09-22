	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r4, r6, r1
	movs r7, #0x1f
_08017DFC:
	adds r3, r4, #0
	adds r3, #0x14
	ldrb r1, [r4]
	cmp r1, #0
	beq _08017E5C
	ldrb r1, [r4, #3]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldr r2, [r1, #8]
	ldr r1, [r1, #4]
	str r1, [r4, #0x2c]
	str r2, [r4, #0x30]
	ldrb r2, [r4, #3]
	movs r1, #1
	subs r1, r1, r2
	movs r5, #0
	strb r1, [r4, #3]
	ldrb r1, [r4, #2]
	cmp r1, #0
	beq _08017E2A
	cmp r1, #1
	beq _08017E48
	b _08017E56
_08017E2A:
	ldrb r1, [r4, #1]
	cmp r1, #2
	bls _08017E56
	movs r0, #1
	strb r0, [r4, #2]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r3, #0
	movs r2, #0x1f
	bl FUN_0822dafc
	strb r5, [r4, #1]
	b _08017E56
_08017E48:
	ldrb r1, [r4, #1]
	cmp r1, #2
	bls _08017E56
	adds r0, r3, #0
	bl Particle_Remove
	strb r5, [r4]
_08017E56:
	ldrb r1, [r4, #1]
	adds r1, #1
	strb r1, [r4, #1]
_08017E5C:
	subs r7, #1
	adds r4, #0x3c
	cmp r7, #0
	bge _08017DFC
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
