	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _080120EC
	movs r0, #0
	strb r0, [r4]
_080120EC:
	ldrh r0, [r4, #0xc]
	mov r5, sp
	movs r3, #6
	ldrsb r3, [r4, r3]
	lsls r6, r0, #1
	ldr r2, _08012114 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08012118
	asrs r1, r0, #0xc
	b _0801211E
	.align 2, 0
_08012114: .4byte 0x085B0A08
_08012118:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0801211E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0801213A
	asrs r0, r0, #0xc
	b _08012140
_0801213A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08012140:
	strh r0, [r5, #4]
	adds r1, r4, #0
	adds r1, #0x10
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x10]
	adds r0, r0, r3
	strh r0, [r4, #0x10]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl EntityE534Elem_SetAnim
	ldrh r1, [r4, #4]
	mov r0, r8
	adds r0, #2
	cmp r1, r0
	blt _08012180
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	movs r0, #0
	strh r0, [r4, #4]
_08012180:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
