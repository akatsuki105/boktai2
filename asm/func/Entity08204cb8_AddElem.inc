	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _082048D8 @ =0x03000220
	ldr r4, [r0]
	bl Entity08204cb8_FindFreeElem
	adds r5, r0, #0
	cmp r5, #0
	beq _082048EC
	adds r4, #0x3c
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	bl Entity08204cb8_SetElemState
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	strh r7, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #1
	strb r1, [r0]
	ldr r2, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5]
	ldrb r0, [r4]
	ands r1, r0
	cmp r1, #0
	bne _082048E0
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	ldr r0, _082048DC @ =0xFFFFFBFF
	b _082048E8
	.align 2, 0
_082048D8: .4byte 0x03000220
_082048DC: .4byte 0xFFFFFBFF
_082048E0:
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r2, r0
	ldr r0, _082048F4 @ =0xFFFFFDFF
_082048E8:
	ands r2, r0
	str r2, [r5]
_082048EC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082048F4: .4byte 0xFFFFFDFF
