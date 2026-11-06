	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0x60
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0805B658
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #4
	strh r0, [r3, #0x10]
_0805B658:
	ldrh r0, [r4, #4]
	cmp r0, #3
	bne _0805B6C4
	ldrb r0, [r4, #3]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0805B67C
	movs r0, #7
	b _0805B68A
_0805B67C:
	asrs r0, r1, #1
	ands r0, r2
	cmp r0, #0
	beq _0805B688
	movs r0, #8
	b _0805B68A
_0805B688:
	movs r0, #6
_0805B68A:
	strh r0, [r3, #0x10]
	cmp r1, #2
	bgt _0805B698
	ldr r0, [r3]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _0805B6BE
_0805B698:
	cmp r1, #4
	bgt _0805B6A8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _0805B6B0
_0805B6A8:
	cmp r1, #5
	bgt _0805B6B6
	ldr r0, [r3]
	movs r1, #0xc
_0805B6B0:
	orrs r0, r1
	str r0, [r3]
	b _0805B6D2
_0805B6B6:
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_0805B6BE:
	ands r0, r1
	str r0, [r3]
	b _0805B6D2
_0805B6C4:
	cmp r0, #5
	bls _0805B6D2
	adds r0, r5, #0
	adds r1, r4, #0
	bl Entity0805b790_ReleaseElem
	b _0805B6D8
_0805B6D2:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805B6D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
