	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r3, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #2
	ldr r2, _0818FA9C @ =0x0000077A
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818FAA0
	movs r0, #1
	b _0818FAA2
	.align 2, 0
_0818FA9C: .4byte 0x0000077A
_0818FAA0:
	movs r0, #0
_0818FAA2:
	cmp r0, #0
	beq _0818FAE4
	lsls r2, r3, #3
	adds r0, r2, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #1
	ldr r6, _0818FAC4 @ =0x0000077A
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818FAC8
	movs r0, #1
	b _0818FACA
	.align 2, 0
_0818FAC4: .4byte 0x0000077A
_0818FAC8:
	movs r0, #0
_0818FACA:
	cmp r0, #0
	bne _0818FAE4
	adds r0, r2, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r1, _0818FAEC @ =0x0000076C
	adds r0, r0, r1
	ldr r1, [r5]
	ldr r2, [r5, #4]
	str r1, [r0]
	str r2, [r0, #4]
_0818FAE4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0818FAEC: .4byte 0x0000076C
