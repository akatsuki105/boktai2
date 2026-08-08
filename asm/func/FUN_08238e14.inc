	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl FUN_0823860c
	ldr r2, _08238E34 @ =0x03000824
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	beq _08238E38
	strh r4, [r2]
	movs r4, #0
	b _08238E3C
	.align 2, 0
_08238E34: .4byte 0x03000824
_08238E38:
	movs r4, #4
	rsbs r4, r4, #0
_08238E3C:
	bl FUN_08238618
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
