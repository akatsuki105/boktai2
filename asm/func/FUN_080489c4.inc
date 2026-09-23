	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	bne _08048A18
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	bne _08048A18
	ldrb r0, [r4, #9]
	cmp r0, #1
	bls _080489E0
	ldrb r0, [r4, #0x16]
	cmp r0, #0
	beq _080489E6
_080489E0:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08048A08
_080489E6:
	cmp r1, #0
	beq _08048A02
	ldr r0, _08048A0C @ =0x030047D8
	ldrh r0, [r0]
	cmp r1, r0
	beq _08048A02
	ldr r0, _08048A10 @ =0x085AB458
	ldrb r1, [r4, #0x11]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl PlaySound_082406e0
_08048A02:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08048A14
_08048A08:
	movs r0, #0
	b _08048A16
	.align 2, 0
_08048A0C: .4byte 0x030047D8
_08048A10: .4byte 0x085AB458
_08048A14:
	adds r0, #1
_08048A16:
	strb r0, [r4, #0x12]
_08048A18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
