	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	movs r7, #0
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081E46B4
	ldr r1, _081E46AC @ =0x085AE404
	ldr r2, _081E46B0 @ =0x0000161A
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0]
	b _081E46CA
	.align 2, 0
_081E46AC: .4byte 0x085AE404
_081E46B0: .4byte 0x0000161A
_081E46B4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081E46E4
	ldr r1, _081E46D8 @ =0x085AE404
	ldr r2, _081E46DC @ =0x0000161A
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0, #1]
_081E46CA:
	cmp r2, #0x10
	bne _081E4754
	ldr r1, _081E46E0 @ =0x0000161B
	adds r0, r3, r1
	strb r7, [r0]
	b _081E4748
	.align 2, 0
_081E46D8: .4byte 0x085AE404
_081E46DC: .4byte 0x0000161A
_081E46E0: .4byte 0x0000161B
_081E46E4:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081E4704
	ldr r1, _081E46FC @ =0x085AE404
	ldr r2, _081E4700 @ =0x0000161A
	adds r5, r3, r2
	ldrb r4, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldrb r2, [r0, #2]
	b _081E471A
	.align 2, 0
_081E46FC: .4byte 0x085AE404
_081E4700: .4byte 0x0000161A
_081E4704:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081E473C
	ldr r1, _081E4730 @ =0x085AE404
	ldr r2, _081E4734 @ =0x0000161A
	adds r5, r3, r2
	ldrb r4, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldrb r2, [r0, #3]
_081E471A:
	cmp r2, #0x10
	bne _081E4724
	ldr r1, _081E4738 @ =0x0000161B
	adds r0, r3, r1
	strb r4, [r0]
_081E4724:
	ldrb r0, [r5]
	cmp r0, #0x10
	bne _081E4748
	movs r7, #1
	b _081E4748
	.align 2, 0
_081E4730: .4byte 0x085AE404
_081E4734: .4byte 0x0000161A
_081E4738: .4byte 0x0000161B
_081E473C:
	ldr r2, _081E4744 @ =0x0000161A
	adds r0, r3, r2
	ldrb r0, [r0]
	b _081E47BC
	.align 2, 0
_081E4744: .4byte 0x0000161A
_081E4748:
	cmp r2, #0x10
	bne _081E4754
	movs r0, #0x30
	strh r0, [r6]
	movs r0, #0x48
	b _081E47B8
_081E4754:
	cmp r2, #0x11
	bne _081E4760
	movs r0, #0x38
	strh r0, [r6]
	movs r0, #0x68
	b _081E47B8
_081E4760:
	cmp r7, #0
	beq _081E47A0
	ldr r0, _081E477C @ =0x0000161B
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E47A0
	cmp r0, #7
	beq _081E478A
	cmp r0, #7
	bgt _081E4780
	cmp r0, #4
	beq _081E478A
	b _081E47A0
	.align 2, 0
_081E477C: .4byte 0x0000161B
_081E4780:
	cmp r0, #8
	beq _081E4796
	cmp r0, #0xb
	beq _081E4796
	b _081E47A0
_081E478A:
	cmp r2, #0
	bne _081E4792
	movs r2, #4
	b _081E47A0
_081E4792:
	movs r2, #7
	b _081E47A0
_081E4796:
	cmp r2, #0
	bne _081E479E
	movs r2, #8
	b _081E47A0
_081E479E:
	movs r2, #0xb
_081E47A0:
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r6]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
_081E47B8:
	strh r0, [r6, #2]
	adds r0, r2, #0
_081E47BC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
