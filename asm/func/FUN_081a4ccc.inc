	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #1
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A4CF4
	movs r0, #1
	b _081A4CF6
_081A4CF4:
	movs r0, #0
_081A4CF6:
	cmp r0, #0
	beq _081A4CFC
	b _081A4E62
_081A4CFC:
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #2
	movs r6, #0xcc
	lsls r6, r6, #3
	adds r0, r0, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A4D18
	movs r0, #1
	b _081A4D1A
_081A4D18:
	movs r0, #0
_081A4D1A:
	cmp r0, #0
	beq _081A4DD4
	ldr r1, _081A4D64 @ =0x00000256
	adds r0, r5, r1
	ldrh r6, [r0]
	add r2, sp, #0x10
	mov sb, r2
	ldr r7, _081A4D68 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x10
	strh r4, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A4D6C
	adds r0, #4
	b _081A4D76
	.align 2, 0
_081A4D64: .4byte 0x00000256
_081A4D68: .4byte 0x030046A4
_081A4D6C:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A4D76:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r6, r8
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldrb r0, [r5, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081A4D9C
	asrs r0, r1, #6
	b _081A4DA2
_081A4D9C:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081A4DA2:
	lsls r3, r0, #6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldrb r0, [r1, #4]
	cmp r0, #3
	bhi _081A4DCE
	ldr r0, [r1, #0x38]
	movs r1, #0x3c
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	add r1, sp, #0x10
	movs r2, #0x40
	bl FUN_0807ac74
	movs r0, #0xe6
	bl PlaySound_082406e0
_081A4DCE:
	ldr r1, [r5, #0x44]
	movs r0, #2
	strb r0, [r1, #7]
_081A4DD4:
	ldr r2, _081A4E70 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _081A4E74 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081A4E78 @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #3
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081A4E7C @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081A4E80 @ =0x00000484
	adds r0, r5, r2
	str r3, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	adds r1, r5, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081A4E84 @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	movs r6, #0xcc
	lsls r6, r6, #3
	adds r1, r1, r6
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
_081A4E62:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A4E70: .4byte FUN_080e48d0
_081A4E74: .4byte 0x0000046D
_081A4E78: .4byte 0x0000046B
_081A4E7C: .4byte 0x0000046A
_081A4E80: .4byte 0x00000484
_081A4E84: .4byte 0x00000474
