	push {lr}
	adds r2, r1, #0
	ldrb r3, [r2, #3]
	cmp r3, #0
	beq _0800CD7E
	movs r0, #0
	b _0800CDAE
_0800CD7E:
	movs r0, #2
	movs r1, #2
	strb r0, [r2, #3]
	str r3, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	ldrb r0, [r2, #2]
	orrs r1, r0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r2, #2]
	strh r3, [r2, #0x38]
	adds r1, r2, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	movs r0, #1
_0800CDAE:
	pop {r1}
	bx r1
	.align 2, 0
