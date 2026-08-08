	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, _0823426C @ =0x030046A4
	ldr r0, [r0]
	ldr r3, [r0, #0x18]
	movs r4, #0
	cmp r3, #0
	beq _08234262
	movs r5, #0xf
_08234238:
	ldrh r0, [r3]
	ands r0, r6
	cmp r0, #0
	bne _0823425C
	ldrh r0, [r3, #2]
	cmp r0, r7
	bne _0823425C
	cmp r4, #0
	beq _0823425A
	ldrb r0, [r4, #4]
	ldrb r2, [r3, #4]
	adds r1, r5, #0
	ands r1, r0
	adds r0, r5, #0
	ands r0, r2
	cmp r1, r0
	bhs _0823425C
_0823425A:
	adds r4, r3, #0
_0823425C:
	ldr r3, [r3, #0xc]
	cmp r3, #0
	bne _08234238
_08234262:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823426C: .4byte 0x030046A4
