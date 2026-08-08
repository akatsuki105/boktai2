	push {lr}
	adds r3, r0, #0
	ldr r0, _080F627C @ =0x0000046D
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F625E
	movs r0, #0
	strb r0, [r1]
_080F625E:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, _080F6280 @ =0x000FFFFF
	cmp r1, r0
	bhi _080F6288
	movs r0, #1
	ldr r1, _080F6284 @ =0x00000222
	adds r2, r3, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080F6296
	.align 2, 0
_080F627C: .4byte 0x0000046D
_080F6280: .4byte 0x000FFFFF
_080F6284: .4byte 0x00000222
_080F6288:
	ldr r1, _080F62A4 @ =0x00000222
	adds r0, r3, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080F6296:
	adds r0, r3, #0
	movs r1, #1
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_080F62A4: .4byte 0x00000222
