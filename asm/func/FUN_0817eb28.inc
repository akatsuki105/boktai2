	push {lr}
	adds r3, r0, #0
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0817EB50
	cmp r1, #0
	blt _0817EB50
	ldr r0, _0817EB54 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0817EB50
	ldr r0, _0817EB58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0817EB5C
_0817EB50:
	movs r2, #0
	b _0817EB6A
	.align 2, 0
_0817EB54: .4byte 0x030046A8
_0817EB58: .4byte 0x030046AC
_0817EB5C:
	ldr r0, _0817EB84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r2
_0817EB6A:
	ldrb r0, [r3, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0817EBA0
	cmp r0, #1
	bgt _0817EB88
	cmp r0, #0
	beq _0817EB92
	b _0817EBE8
	.align 2, 0
_0817EB84: .4byte 0x030046A4
_0817EB88:
	cmp r0, #2
	beq _0817EBBC
	cmp r0, #3
	beq _0817EBCC
	b _0817EBE8
_0817EB92:
	ldr r1, _0817EB9C @ =0x00000256
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r0, #1
	b _0817EBEE
	.align 2, 0
_0817EB9C: .4byte 0x00000256
_0817EBA0:
	ldr r0, _0817EBB4 @ =0x00000256
	adds r1, r3, r0
	ldr r0, _0817EBB8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _0817EBEE
	.align 2, 0
_0817EBB4: .4byte 0x00000256
_0817EBB8: .4byte 0x030046A4
_0817EBBC:
	ldr r1, _0817EBC8 @ =0x00000256
	adds r0, r3, r1
	ldrh r0, [r0]
	subs r0, #1
	b _0817EBEE
	.align 2, 0
_0817EBC8: .4byte 0x00000256
_0817EBCC:
	ldr r1, _0817EBE0 @ =0x00000256
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r0, _0817EBE4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r0, r1, r0
	b _0817EBEE
	.align 2, 0
_0817EBE0: .4byte 0x00000256
_0817EBE4: .4byte 0x030046A4
_0817EBE8:
	ldr r1, _0817EBF8 @ =0x00000256
	adds r0, r3, r1
	ldrh r0, [r0]
_0817EBEE:
	cmp r2, r0
	beq _0817EBFC
	movs r0, #0
	b _0817EBFE
	.align 2, 0
_0817EBF8: .4byte 0x00000256
_0817EBFC:
	movs r0, #1
_0817EBFE:
	pop {r1}
	bx r1
	.align 2, 0
