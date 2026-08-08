	push {r4, r5, r6, lr}
	cmp r0, #0
	beq _0823099E
	adds r3, r0, #0
	subs r3, #0x10
	ldr r4, [r3]
	ldr r5, [r3, #4]
	ldr r1, [r3, #8]
	movs r6, #0x80
	lsls r6, r6, #0x18
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _0823099E
	adds r2, r6, #0
	orrs r2, r1
	str r2, [r3, #8]
	str r0, [r3, #0xc]
	cmp r4, #0
	beq _08230976
	ldr r1, [r4, #8]
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	beq _08230976
	ldr r0, _082309A4 @ =0x000FFFFF
	ands r1, r0
	ands r2, r0
	adds r0, r1, r2
	orrs r0, r6
	str r0, [r4, #8]
	str r5, [r4, #4]
	cmp r5, #0
	beq _08230974
	ldr r0, [r3, #4]
	str r4, [r0]
_08230974:
	adds r3, r4, #0
_08230976:
	cmp r5, #0
	beq _0823099E
	ldr r2, [r5, #8]
	movs r4, #0x80
	lsls r4, r4, #0x18
	cmp r2, #0
	bge _0823099E
	ldr r0, [r3, #8]
	ldr r1, _082309A4 @ =0x000FFFFF
	ands r0, r1
	ands r2, r1
	adds r0, r0, r2
	orrs r0, r4
	str r0, [r3, #8]
	ldr r0, [r5, #4]
	str r0, [r3, #4]
	cmp r0, #0
	beq _0823099E
	ldr r0, [r5, #4]
	str r3, [r0]
_0823099E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082309A4: .4byte 0x000FFFFF
