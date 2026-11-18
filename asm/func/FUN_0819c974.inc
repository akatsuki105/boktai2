	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov sb, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r7, [r5, #0x44]
	ldr r2, _0819C9A0 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C9A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C9A6
	.align 2, 0
_0819C9A0: .4byte 0x0000046D
_0819C9A4:
	movs r0, #0
_0819C9A6:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r5
	mov r8, r1
	cmp r0, #0
	beq _0819CAA8
	ldr r0, [r7]
	movs r1, #2
	orrs r0, r1
	str r0, [r7]
	ldr r2, _0819CA30 @ =0x00000EAA
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0819CA34 @ =0x03002BE0
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0819CA38 @ =0x00000546
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819CA3C
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x2c
	bl Div
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x2c
	strh r0, [r1]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0x2c
	bl Div
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	b _0819CA7E
	.align 2, 0
_0819CA30: .4byte 0x00000EAA
_0819CA34: .4byte 0x03002BE0
_0819CA38: .4byte 0x00000546
_0819CA3C:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0819CA4A
	asrs r1, r0, #6
	b _0819CA50
_0819CA4A:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0819CA50:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x40
	strh r0, [r1]
	mov r0, sp
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0819CA70
	asrs r1, r0, #6
	b _0819CA76
_0819CA70:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0819CA76:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0819CA7E:
	ldr r0, _0819CACC @ =0x00000EAF
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r4, r5, r1
	ldr r1, _0819CAD0 @ =0xFFEFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r2, _0819CAD4 @ =0x000008DC
	adds r1, r6, r2
	adds r0, r5, #0
	movs r2, #0xf8
	bl FUN_0819ee40
	ldr r0, _0819CAD8 @ =0x000001E5
	bl PlaySound_082406e0
	mov r8, r4
_0819CAA8:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0xa]
	adds r0, r0, r2
	strh r0, [r5, #0xa]
	ldr r1, _0819CADC @ =0x00000ECF
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #0x20
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819CAE4
	ldr r2, _0819CAE0 @ =0xFFFFFF00
	adds r1, r1, r2
	b _0819CAF2
	.align 2, 0
_0819CACC: .4byte 0x00000EAF
_0819CAD0: .4byte 0xFFEFFFFF
_0819CAD4: .4byte 0x000008DC
_0819CAD8: .4byte 0x000001E5
_0819CADC: .4byte 0x00000ECF
_0819CAE0: .4byte 0xFFFFFF00
_0819CAE4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819CAF2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0819CAF2:
	cmp r1, #0
	bge _0819CB08
	ldr r1, _0819CB04 @ =0x00000EAA
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r2, [r7, #6]
	adds r0, r0, r2
	strb r0, [r7, #6]
	b _0819CB14
	.align 2, 0
_0819CB04: .4byte 0x00000EAA
_0819CB08:
	ldr r1, _0819CB20 @ =0x00000EAA
	adds r0, r6, r1
	ldrb r1, [r7, #6]
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r7, #6]
_0819CB14:
	ldrb r4, [r7, #6]
	cmp r4, #0x80
	ble _0819CB28
	ldr r2, _0819CB24 @ =0xFFFFFF00
	adds r4, r4, r2
	b _0819CB36
	.align 2, 0
_0819CB20: .4byte 0x00000EAA
_0819CB24: .4byte 0xFFFFFF00
_0819CB28:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0819CB36
	movs r7, #0x80
	lsls r7, r7, #1
	adds r4, r4, r7
_0819CB36:
	adds r0, r5, #0
	bl FUN_0819ef24
	mov r0, sb
	cmp r0, #0x1b
	bgt _0819CB5C
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _0819CB7C
	ldr r2, _0819CB58 @ =0x00000EAA
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #4
	b _0819CB7A
	.align 2, 0
_0819CB58: .4byte 0x00000EAA
_0819CB5C:
	adds r0, r4, #0
	cmp r0, #0
	bge _0819CB64
	rsbs r0, r0, #0
_0819CB64:
	cmp r0, #0x5f
	bgt _0819CB74
	ldr r7, _0819CB70 @ =0x00000EAA
	adds r1, r6, r7
	movs r0, #8
	b _0819CB7A
	.align 2, 0
_0819CB70: .4byte 0x00000EAA
_0819CB74:
	ldr r0, _0819CBE4 @ =0x00000EAA
	adds r1, r6, r0
	movs r0, #0
_0819CB7A:
	strb r0, [r1]
_0819CB7C:
	movs r1, #0x10
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0819CBD4
	ldr r7, _0819CBE8 @ =0x00000ECD
	adds r0, r6, r7
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0819CBEC @ =FUN_0819c740
	movs r2, #0x32
	ldr r7, _0819CBF0 @ =0x0000046D
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _0819CBF4 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r7, _0819CBF8 @ =0x00000E48
	adds r2, r6, r7
	ldr r1, _0819CBFC @ =0xFFFFF7FF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0819CC00 @ =0x00000EAE
	adds r1, r6, r0
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0xe
	bl FUN_0819f530
_0819CBD4:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819CBE4: .4byte 0x00000EAA
_0819CBE8: .4byte 0x00000ECD
_0819CBEC: .4byte FUN_0819c740
_0819CBF0: .4byte 0x0000046D
_0819CBF4: .4byte 0x0000046B
_0819CBF8: .4byte 0x00000E48
_0819CBFC: .4byte 0xFFFFF7FF
_0819CC00: .4byte 0x00000EAE
