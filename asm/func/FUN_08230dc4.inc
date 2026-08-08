	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r6, #0
	ldr r4, _08230DF8 @ =0x0203B000
	movs r5, #0
	ldr r0, _08230DFC @ =0x03004590
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r6, r1
	bge _08230E22
_08230DD8:
	ldrb r1, [r4, #2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08230E18
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08230E00
	adds r0, r7, #0
	ands r0, r2
	cmp r0, #0
	bne _08230E00
	adds r6, r5, #0
	b _08230E18
	.align 2, 0
_08230DF8: .4byte 0x0203B000
_08230DFC: .4byte 0x03004590
_08230E00:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08230E0E
	ldr r0, [r4, #4]
	bl Free
_08230E0E:
	movs r1, #0
	movs r0, #0
	strh r0, [r4]
	strb r1, [r4, #2]
	ldr r3, _08230E2C @ =0x03004590
_08230E18:
	adds r5, #1
	adds r4, #8
	ldr r0, [r3]
	cmp r5, r0
	blt _08230DD8
_08230E22:
	adds r0, r6, #1
	str r0, [r3]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08230E2C: .4byte 0x03004590
