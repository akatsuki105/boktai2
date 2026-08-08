	push {r4, r5, lr}
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	lsls r1, r1, #0x10
	asrs r4, r1, #0x10
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x40
	beq _080E5D9E
	cmp r1, #0xc0
	bne _080E5DAA
_080E5D9E:
	adds r1, r4, #0
	cmp r1, #0
	bge _080E5DA6
	rsbs r1, r1, #0
_080E5DA6:
	lsls r0, r1, #0x10
	b _080E5DC8
_080E5DAA:
	lsls r0, r5, #0xc
	ldr r3, _080E5DD0 @ =0x085B0A08
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	cmp r0, #0
	bge _080E5DC6
	rsbs r0, r0, #0
_080E5DC6:
	lsls r0, r0, #0x10
_080E5DC8:
	asrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080E5DD0: .4byte 0x085B0A08
