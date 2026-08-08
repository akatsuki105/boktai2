	push {r4, lr}
	adds r4, r1, #0
	movs r3, #0
	ldrb r0, [r0, #4]
	cmp r0, #1
	beq _080F8EA4
	cmp r0, #1
	bgt _080F8E9A
	cmp r0, #0
	beq _080F8EAE
	b _080F8EFC
_080F8E9A:
	cmp r0, #2
	beq _080F8EA8
	cmp r0, #3
	beq _080F8EAC
	b _080F8EFC
_080F8EA4:
	movs r3, #1
	b _080F8EAE
_080F8EA8:
	movs r3, #2
	b _080F8EAE
_080F8EAC:
	movs r3, #3
_080F8EAE:
	ldr r1, _080F8EE0 @ =0x03002BE0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080F8EFC
	cmp r4, #0
	bne _080F8EEC
	ldr r3, _080F8EE4 @ =0x00000446
	adds r0, r1, r3
	ldrh r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _080F8ED6
	ldr r4, _080F8EE8 @ =0x00000442
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, r2
	bne _080F8ED6
	movs r3, #1
_080F8ED6:
	cmp r3, #0
	beq _080F8EFC
	movs r0, #1
	b _080F8EFE
	.align 2, 0
_080F8EE0: .4byte 0x03002BE0
_080F8EE4: .4byte 0x00000446
_080F8EE8: .4byte 0x00000442
_080F8EEC:
	cmp r4, #1
	bne _080F8EFC
	ldr r0, [r1, #0x20]
	ands r0, r2
	cmp r0, #0
	beq _080F8EFC
	movs r0, #1
	b _080F8EFE
_080F8EFC:
	movs r0, #0
_080F8EFE:
	pop {r4}
	pop {r1}
	bx r1
