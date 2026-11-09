	push {lr}
	adds r2, r0, #0
	ldr r0, _0817EAA8 @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r3, [r0, #6]
	ldrb r0, [r2, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0817EAC4
	cmp r0, #1
	bgt _0817EAAC
	cmp r0, #0
	beq _0817EAB6
	b _0817EB0C
	.align 2, 0
_0817EAA8: .4byte 0x03002BE0
_0817EAAC:
	cmp r0, #2
	beq _0817EAE0
	cmp r0, #3
	beq _0817EAF0
	b _0817EB0C
_0817EAB6:
	ldr r1, _0817EAC0 @ =0x00000256
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r0, #1
	b _0817EB12
	.align 2, 0
_0817EAC0: .4byte 0x00000256
_0817EAC4:
	ldr r0, _0817EAD8 @ =0x00000256
	adds r1, r2, r0
	ldr r0, _0817EADC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _0817EB12
	.align 2, 0
_0817EAD8: .4byte 0x00000256
_0817EADC: .4byte 0x030046A4
_0817EAE0:
	ldr r1, _0817EAEC @ =0x00000256
	adds r0, r2, r1
	ldrh r0, [r0]
	subs r0, #1
	b _0817EB12
	.align 2, 0
_0817EAEC: .4byte 0x00000256
_0817EAF0:
	ldr r1, _0817EB04 @ =0x00000256
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r0, _0817EB08 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r0, r1, r0
	b _0817EB12
	.align 2, 0
_0817EB04: .4byte 0x00000256
_0817EB08: .4byte 0x030046A4
_0817EB0C:
	ldr r1, _0817EB1C @ =0x00000256
	adds r0, r2, r1
	ldrh r0, [r0]
_0817EB12:
	cmp r3, r0
	beq _0817EB20
	movs r0, #0
	b _0817EB22
	.align 2, 0
_0817EB1C: .4byte 0x00000256
_0817EB20:
	movs r0, #1
_0817EB22:
	pop {r1}
	bx r1
	.align 2, 0
