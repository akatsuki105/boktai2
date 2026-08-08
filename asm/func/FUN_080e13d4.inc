	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r3, r0, #0
	adds r3, #0x18
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080E14C2
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080E1438 @ =0x030047A4
	ldr r1, _080E143C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080E14C2
	movs r1, #4
	ldr r0, _080E1440 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080E14C2
	adds r4, r3, #0
	movs r6, #0xb
_080E140C:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080E14BA
	movs r3, #0x9b
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	bge _080E14BA
	movs r0, #0x12
	ldrsh r2, [r4, r0]
	ldr r0, _080E1438 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080E1444
	adds r5, r2, #0
	b _080E145E
	.align 2, 0
_080E1438: .4byte 0x030047A4
_080E143C: .4byte 0x030047A0
_080E1440: .4byte 0x03002BC0
_080E1444:
	ldr r0, _080E14CC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080E14D0 @ =0x00000942
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xa
	subs r0, r0, r1
	muls r0, r2, r0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
_080E145E:
	movs r7, #0x10
	ldrsh r2, [r4, r7]
	ldr r0, _080E14D4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080E148A
	ldr r0, _080E14CC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080E14D0 @ =0x00000942
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xa
	subs r0, r0, r1
	muls r0, r2, r0
	movs r1, #0xa
	bl Div
	adds r2, r0, #0
_080E148A:
	ldrh r1, [r4, #0x14]
	ldrb r3, [r4, #0x18]
	ldrb r0, [r4, #0x19]
	str r0, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	movs r7, #8
	ldrsh r0, [r4, r7]
	str r0, [sp, #8]
	movs r7, #0xa
	ldrsh r0, [r4, r7]
	str r0, [sp, #0xc]
	movs r7, #0xc
	ldrsh r0, [r4, r7]
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	ldrh r0, [r4, #0x16]
	str r0, [sp, #0x18]
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_081ead54
	str r0, [r4, #0x1c]
_080E14BA:
	adds r4, #0x20
	subs r6, #1
	cmp r6, #0
	bge _080E140C
_080E14C2:
	movs r0, #0
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080E14CC: .4byte 0x030046A0
_080E14D0: .4byte 0x00000942
_080E14D4: .4byte 0x030047A4
