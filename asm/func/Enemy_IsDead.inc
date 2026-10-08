	push {lr}
	adds r2, r0, #0
	cmp r2, #0
	beq _080E8A9A
	movs r1, #0x40
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080E8A96
	movs r1, #0x80
	lsls r1, r1, #0xa
	subs r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080E8A96
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bgt _080E8A9A
_080E8A96:
	movs r0, #1
	b _080E8A9C
_080E8A9A:
	movs r0, #0
_080E8A9C:
	pop {r1}
	bx r1
