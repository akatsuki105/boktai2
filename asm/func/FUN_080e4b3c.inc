	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r3, #2
	ldrsh r0, [r1, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r2, r2, r0
	movs r3, #4
	ldrsh r0, [r1, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	cmn r2, r0
	bne _080E4B90
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _080E4B90
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	b _080E4DF8
_080E4B90:
	ldr r1, _080E4C0C @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xa
	beq _080E4BAA
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080E4BAA:
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	bne _080E4C14
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	subs r1, #2
	strh r1, [r0]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x10]
	adds r0, r0, r2
	strh r0, [r5, #0x10]
	adds r3, #6
	adds r0, r5, r3
	ldrh r0, [r0]
	ldrh r1, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	ldr r2, _080E4C10 @ =0x00000256
	adds r0, r5, r2
	ldrh r4, [r0]
	adds r6, r5, #0
	adds r6, #8
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	mov r8, r6
	cmp r0, #0
	beq _080E4C84
	adds r0, #4
	b _080E4C90
	.align 2, 0
_080E4C0C: .4byte 0x000001DF
_080E4C10: .4byte 0x00000256
_080E4C14:
	movs r3, #0xe5
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _080E4C66
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _080E4C38
	asrs r1, r0, #1
	b _080E4C3E
_080E4C38:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_080E4C3E:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _080E4C58
	asrs r1, r0, #1
	b _080E4C5E
_080E4C58:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_080E4C5E:
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
_080E4C66:
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x10]
	adds r0, r0, r2
	strh r0, [r5, #0x10]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ldrh r1, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	b _080E4E0C
_080E4C84:
	ldr r0, _080E4CA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E4C90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E4CA8
	cmp r2, #2
	beq _080E4CAC
	b _080E4CB0
	.align 2, 0
_080E4CA4: .4byte 0x030046A4
_080E4CA8:
	ldrb r0, [r6, #4]
	b _080E4CAE
_080E4CAC:
	ldrb r0, [r6]
_080E4CAE:
	subs r1, r1, r0
_080E4CB0:
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r7, r5, r2
	movs r3, #0
	ldrsh r0, [r7, r3]
	adds r0, r0, r1
	cmp r0, r1
	bgt _080E4DAC
	ldr r3, _080E4CFC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x52
	orrs r0, r2
	ldr r1, _080E4D00 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r4, [r6]
	mov sl, r1
	cmp r4, #0
	bne _080E4D08
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	str r4, [sp, #8]
	add r0, sp, #8
	ldr r2, _080E4D04 @ =0x05000002
	bl CpuSet
	strh r4, [r7]
	b _080E4D50
	.align 2, 0
_080E4CFC: .4byte 0xFFFF0000
_080E4D00: .4byte 0x0000FFFF
_080E4D04: .4byte 0x05000002
_080E4D08:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r4, r5, r3
	movs r0, #0
	ldrsh r1, [r4, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r4]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	cmp r1, #0
	bge _080E4D2E
	rsbs r1, r1, #0
_080E4D2E:
	ldrh r0, [r6]
	muls r0, r1, r0
	movs r1, #0xa
	bl Div
	strh r0, [r4]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r4, r5, r3
	movs r0, #0
	ldrsh r1, [r4, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r4]
_080E4D50:
	ldr r1, _080E4E00 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _080E4D92
	cmp r0, #0x17
	beq _080E4D92
	cmp r0, #0x13
	beq _080E4D92
	cmp r0, #0x12
	beq _080E4D92
	cmp r0, #0x19
	beq _080E4D92
	cmp r0, #0xe
	beq _080E4D92
	cmp r0, #0x1a
	beq _080E4D92
	cmp r0, #0xd
	beq _080E4D92
	cmp r0, #0x1f
	beq _080E4D92
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, r8
	mov r2, sl
	movs r3, #6
	bl FUN_080dbcec
_080E4D92:
	ldr r3, _080E4E04 @ =0x000005B4
	adds r0, r5, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _080E4DA2
	adds r0, r5, #0
	bl _call_via_r1
_080E4DA2:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
_080E4DAC:
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #2
	ldrsh r0, [r2, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	cmn r1, r0
	bne _080E4E0C
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _080E4E0C
	strh r0, [r1]
	str r0, [sp, #8]
	add r0, sp, #8
	adds r1, r2, #0
	ldr r2, _080E4E08 @ =0x05000002
	bl CpuSet
	movs r1, #0x10
	mov r2, sb
	ldr r0, [r2]
	orrs r0, r1
_080E4DF8:
	str r0, [r2]
	movs r0, #1
	b _080E4E0E
	.align 2, 0
_080E4E00: .4byte 0x000001DF
_080E4E04: .4byte 0x000005B4
_080E4E08: .4byte 0x05000002
_080E4E0C:
	movs r0, #0
_080E4E0E:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
