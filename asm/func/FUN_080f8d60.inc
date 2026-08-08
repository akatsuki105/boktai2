	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, _080F8D74 @ =0x03000184
	ldr r0, [r0]
	cmp r0, #0
	beq _080F8D9C
	cmp r3, #0
	bne _080F8D7C
	b _080F8D9C
	.align 2, 0
_080F8D74: .4byte 0x03000184
_080F8D78:
	adds r0, r1, #0
	b _080F8D9E
_080F8D7C:
	ldr r2, [r0, #0x28]
	cmp r2, #0
	beq _080F8D9C
	movs r4, #1
_080F8D84:
	ldrb r1, [r2, #4]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080F8D96
	ldr r1, [r2]
	ldrh r0, [r1]
	cmp r0, r3
	beq _080F8D78
_080F8D96:
	ldr r2, [r2, #0xc]
	cmp r2, #0
	bne _080F8D84
_080F8D9C:
	movs r0, #0
_080F8D9E:
	pop {r4}
	pop {r1}
	bx r1
