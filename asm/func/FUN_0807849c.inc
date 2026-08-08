	push {lr}
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r3, [r0]
	movs r0, #0x40
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r2, r0, #0x1f
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _080784C0
	movs r0, #2
	orrs r2, r0
_080784C0:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _080784D4
	movs r1, #4
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080784D4:
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq _080784E8
	movs r1, #8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_080784E8:
	ldr r0, _080784F8 @ =0x085ABC8A
	lsls r1, r2, #0x10
	asrs r1, r1, #0xf
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	pop {r1}
	bx r1
	.align 2, 0
_080784F8: .4byte 0x085ABC8A
