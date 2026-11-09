	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	str r3, [sp]
	movs r0, #8
	adds r0, r0, r6
	mov sl, r0
	movs r1, #0x10
	adds r1, r1, r6
	mov r8, r1
	ldr r2, _08159FF8 @ =0x00000256
	adds r0, r6, r2
	ldrh r5, [r0]
	mov sb, sl
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08159FFC
	adds r0, #4
	b _0815A008
	.align 2, 0
_08159FF8: .4byte 0x00000256
_08159FFC:
	ldr r0, _0815A01C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815A008:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815A020
	cmp r2, #2
	beq _0815A026
	b _0815A02C
	.align 2, 0
_0815A01C: .4byte 0x030046A4
_0815A020:
	mov r3, sb
	ldrb r0, [r3, #4]
	b _0815A02A
_0815A026:
	mov r2, sb
	ldrb r0, [r2]
_0815A02A:
	subs r1, r1, r0
_0815A02C:
	adds r3, r1, #0
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldrh r0, [r7]
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r7, #4]
	strh r0, [r1, #4]
	ldrh r0, [r7, #2]
	ldr r1, [sp]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r1, [sp, #0x24]
	adds r0, r1, #0
	muls r0, r1, r0
	asrs r1, r0, #4
	cmp r4, #1
	beq _0815A06C
	cmp r4, #1
	bgt _0815A060
	cmp r4, #0
	beq _0815A066
	b _0815A07C
_0815A060:
	cmp r4, #2
	beq _0815A07A
	b _0815A07C
_0815A066:
	adds r0, r2, #1
	adds r2, r0, r1
	b _0815A07C
_0815A06C:
	movs r0, #0x40
	subs r0, r0, r1
	cmp r0, #0
	bge _0815A076
	rsbs r0, r0, #0
_0815A076:
	subs r2, r2, r0
	b _0815A07C
_0815A07A:
	adds r2, r2, r1
_0815A07C:
	adds r1, r2, r3
	cmp r4, #0
	beq _0815A088
	cmp r4, #1
	beq _0815A0B4
	b _0815A0CA
_0815A088:
	movs r3, #2
	ldrsh r0, [r7, r3]
	cmp r0, #0
	bgt _0815A0CA
	strh r4, [r7, #2]
	mov r0, r8
	strh r4, [r0]
	strh r4, [r0, #4]
	ldr r2, _0815A0B0 @ =0x00000472
	adds r1, r6, r2
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sl
	strh r0, [r1, #2]
	movs r0, #1
	b _0815A0D8
	.align 2, 0
_0815A0B0: .4byte 0x00000472
_0815A0B4:
	cmp r1, r3
	bgt _0815A0CA
	movs r0, #0
	mov r2, sl
	strh r3, [r2, #2]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #1
	b _0815A0D8
_0815A0CA:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
	mov r0, sl
	strh r1, [r0, #2]
	movs r0, #0
_0815A0D8:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
