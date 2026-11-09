	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r0, _081380A0 @ =0x00000B4C
	adds r3, r1, r0
	ldr r0, [r3]
	ldr r4, _081380A4 @ =0x7FFFFFFF
	cmp r0, r4
	beq _081380D2
	movs r2, #0xb5
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r2, [r0]
	str r4, [r3]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r2, r4
	adds r1, r2, #0
	adds r1, #0xd8
	adds r4, #0x14
	adds r3, r2, r4
	ldrb r4, [r0]
	ldrh r5, [r1]
	ldr r2, _081380A8 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081380AC
	asrs r1, r0, #0xc
	b _081380B2
	.align 2, 0
_081380A0: .4byte 0x00000B4C
_081380A4: .4byte 0x7FFFFFFF
_081380A8: .4byte gSineTable
_081380AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081380B2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081380CA
	asrs r0, r0, #0xc
	b _081380D0
_081380CA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081380D0:
	strh r0, [r3, #4]
_081380D2:
	pop {r4, r5}
	pop {r0}
	bx r0
