	push {r4, r5, lr}
	adds r4, r2, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _081778B4 @ =0x00001010
	adds r0, r2, r3
	movs r5, #0
	ldrsh r3, [r0, r5]
	cmp r3, r1
	blt _081778BC
	strh r1, [r0]
	ldr r0, _081778B8 @ =0x0000100C
	adds r1, r2, r0
	movs r0, #0xff
	b _081778CA
	.align 2, 0
_081778B4: .4byte 0x00001010
_081778B8: .4byte 0x0000100C
_081778BC:
	rsbs r1, r1, #0
	cmp r3, r1
	bgt _081778CC
	strh r1, [r0]
	ldr r3, _081778E8 @ =0x0000100C
	adds r1, r2, r3
	movs r0, #1
_081778CA:
	strb r0, [r1]
_081778CC:
	ldr r5, _081778EC @ =0x00001010
	adds r1, r2, r5
	ldr r3, _081778E8 @ =0x0000100C
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r4, r0
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081778E8: .4byte 0x0000100C
_081778EC: .4byte 0x00001010
