	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r2, [r6, #0x44]
	ldr r0, _08163860 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163864
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08163866
	.align 2, 0
_08163860: .4byte 0x0000046D
_08163864:
	movs r0, #0
_08163866:
	cmp r0, #0
	beq _08163888
	movs r0, #0x40
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r0, _081638EC @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08163888:
	ldr r2, _081638F0 @ =0x0000046E
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081638E6
	ldr r3, _081638F4 @ =0x00000482
	adds r1, r6, r3
	movs r2, #0
	movs r4, #0
	movs r5, #1
	movs r0, #1
	strh r0, [r1]
	ldr r3, _081638F8 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r7, _081638FC @ =0x0000046D
	adds r0, r6, r7
	strb r5, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r1, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r2, [r0]
	ldr r3, _08163900 @ =0x00000469
	adds r0, r6, r3
	strb r2, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08163904 @ =0x00000484
	adds r0, r6, r1
	str r4, [r0]
	ldr r2, _08163908 @ =0x0000046C
	adds r0, r6, r2
	strb r5, [r0]
_081638E6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081638EC: .4byte 0xFFFFFEFF
_081638F0: .4byte 0x0000046E
_081638F4: .4byte 0x00000482
_081638F8: .4byte Enemy_ClearStateBegun
_081638FC: .4byte 0x0000046D
_08163900: .4byte 0x00000469
_08163904: .4byte 0x00000484
_08163908: .4byte 0x0000046C
