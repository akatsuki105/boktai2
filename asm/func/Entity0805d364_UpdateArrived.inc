	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805D0BC
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805D0BC:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Entity0805d364_SetElemAnim
	ldrb r1, [r5, #0x1d]
	cmp r1, #0
	beq _0805D0D2
	movs r0, #0xb
	movs r1, #0
	b _0805D0DA
_0805D0D2:
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq _0805D0E4
	movs r0, #5
_0805D0DA:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805D0EA
_0805D0E4:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805D0EA:
	pop {r4, r5}
	pop {r0}
	bx r0
