	push {r4, lr}
	adds r4, r0, #0
	lsls r1, r1, #2
	ldr r3, _08050F64 @ =gSineTable
	movs r0, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08050F68
	asrs r1, r0, #0xc
	b _08050F6E
	.align 2, 0
_08050F64: .4byte gSineTable
_08050F68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08050F6E:
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r4, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	pop {r4}
	pop {r0}
	bx r0
