	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b5ab0
FUN_080b5ab0: @ 0x080B5AB0
	ldr r3, _080B5AC0 @ =0x00001494
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080B5AC4 @ =0x0000140E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080B5AC0: .4byte 0x00001494
_080B5AC4: .4byte 0x0000140E

	thumb_func_start FUN_080b5ac8
FUN_080b5ac8: @ 0x080B5AC8
	ldr r2, _080B5AD0 @ =0x0000140C
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080B5AD0: .4byte 0x0000140C

	thumb_func_start FUN_080b5ad4
FUN_080b5ad4: @ 0x080B5AD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _080B5AF4 @ =0x00001498
	adds r0, r4, r3
	str r1, [r0]
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080b5ac8
	ldr r0, _080B5AF8 @ =0x0000140E
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B5AF4: .4byte 0x00001498
_080B5AF8: .4byte 0x0000140E

	thumb_func_start FUN_080b5afc
FUN_080b5afc: @ 0x080B5AFC
	push {r4, lr}
	adds r4, r1, #0
	movs r2, #0xf
	ldr r3, _080B5B28 @ =0x00001467
	adds r1, r0, r3
_080B5B06:
	strb r2, [r1]
	subs r1, #1
	subs r2, #1
	cmp r2, #0
	bge _080B5B06
	movs r2, #0x10
	ldr r1, _080B5B2C @ =0x00001458
	adds r3, r0, r1
_080B5B16:
	adds r1, r3, r2
	adds r0, r2, r4
	strb r0, [r1]
	adds r2, #1
	cmp r2, #0x1f
	ble _080B5B16
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B5B28: .4byte 0x00001467
_080B5B2C: .4byte 0x00001458

	thumb_func_start FUN_080b5b30
FUN_080b5b30: @ 0x080B5B30
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _080B5B4C @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	movs r3, #0x1f
	ands r1, r3
	lsls r1, r1, #1
	adds r0, r0, r1
	ands r2, r3
	lsls r2, r2, #6
	adds r0, r0, r2
	bx lr
	.align 2, 0
_080B5B4C: .4byte 0x03003ED0

	thumb_func_start FUN_080b5b50
FUN_080b5b50: @ 0x080B5B50
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08049e5c
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b5b94
FUN_080b5b94: @ 0x080B5B94
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _080B5BC4 @ =0x00001429
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080B5BCC
	ldr r2, _080B5BC8 @ =0x0000142B
	adds r5, r6, r2
	ldrb r0, [r5]
	adds r1, #0x2f
	adds r4, r6, r1
	adds r0, r4, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r7, r0, #0
	ldrb r0, [r5]
	adds r4, r4, r0
	ldrb r0, [r4]
	bl item_08092034
	adds r3, r0, #0
	b _080B5BD2
	.align 2, 0
_080B5BC4: .4byte 0x00001429
_080B5BC8: .4byte 0x0000142B
_080B5BCC:
	movs r7, #1
	rsbs r7, r7, #0
	movs r3, #0xcf
_080B5BD2:
	cmp r7, #0
	bge _080B5BEE
	movs r2, #0xf2
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080B5CA4
_080B5BEE:
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B5C5C @ =0x00000F18
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0x38
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B5C60 @ =0x000013F4
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r7, #0
	bl FUN_08047a28
	ldr r0, [r4]
	bl VM_ParseStringRef
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r1, r0, #0
	ldr r0, _080B5C64 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bne _080B5C7A
	cmp r7, #1
	bne _080B5C68
	adds r0, r1, #0
	adds r0, #0xea
	b _080B5C70
	.align 2, 0
_080B5C5C: .4byte 0x00000F18
_080B5C60: .4byte 0x000013F4
_080B5C64: .4byte 0x030046A0
_080B5C68:
	cmp r7, #0xd
	bne _080B5C7A
	adds r0, r1, #0
	adds r0, #0xa9
_080B5C70:
	bl Textbox_LookupString
	bl FUN_08049e30
	b _080B5CA4
_080B5C7A:
	ldr r0, _080B5C94 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080B5C90
	cmp r0, #5
	bne _080B5C98
_080B5C90:
	adds r1, #0x4e
	b _080B5C9A
	.align 2, 0
_080B5C94: .4byte 0x030046A0
_080B5C98:
	adds r1, #0x9c
_080B5C9A:
	adds r0, r1, r7
	bl Textbox_LookupString
	bl FUN_08049e30
_080B5CA4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b5cac
FUN_080b5cac: @ 0x080B5CAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080B5D30 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _080B5D34 @ =0x00001413
	adds r1, r7, r2
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r3, #0
	mov sb, r3
	adds r0, r7, #0
	adds r0, #0x80
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
_080B5CDA:
	movs r2, #0
	mov sl, r2
	mov r3, sb
	lsls r3, r3, #2
	mov r8, r3
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r2, [sp, #8]
	adds r6, r2, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, [sp, #4]
	adds r4, r0, r3
_080B5CFC:
	mov r5, r8
	add r5, sl
	ldr r1, _080B5D38 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r2, r0, #0
	cmp r2, #0
	blt _080B5D3C
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B5D52
	.align 2, 0
_080B5D30: .4byte 0x00001412
_080B5D34: .4byte 0x00001413
_080B5D38: .4byte 0x00001458
_080B5D3C:
	ldr r2, _080B5DE0 @ =0x00001412
	adds r1, r7, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B5D4A
	strb r5, [r1]
_080B5D4A:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B5D52:
	adds r0, r6, #0
	ldr r1, _080B5DE4 @ =0x000002DF
	bl FUN_080b95bc
	adds r6, #0x60
	adds r4, #0x60
	movs r3, #1
	add sl, r3
	mov r0, sl
	cmp r0, #3
	ble _080B5CFC
	ldr r1, [sp, #8]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r1, r2
	str r1, [sp, #8]
	add sb, r3
	mov r3, sb
	cmp r3, #3
	ble _080B5CDA
	movs r0, #0
	mov sb, r0
_080B5D7E:
	movs r1, #0
	mov sl, r1
	mov r2, sb
	lsls r2, r2, #2
	mov r8, r2
	mov r3, sb
	adds r3, #1
	str r3, [sp]
	adds r2, #0x13
	mov r1, sb
	lsls r0, r1, #3
	add r0, r8
	lsls r0, r0, #5
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r1, r7, r3
	adds r6, r0, r1
	mov r5, r8
	adds r5, #0x10
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp, #4]
	adds r4, r0, r1
_080B5DAE:
	ldr r2, _080B5DE8 @ =0x00001458
	adds r0, r7, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r2, r0, #0
	cmp r2, #0
	blt _080B5DEC
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B5E02
	.align 2, 0
_080B5DE0: .4byte 0x00001412
_080B5DE4: .4byte 0x000002DF
_080B5DE8: .4byte 0x00001458
_080B5DEC:
	ldr r3, _080B5E44 @ =0x00001413
	adds r1, r7, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B5DFA
	strb r5, [r1]
_080B5DFA:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B5E02:
	adds r4, #0x60
	adds r6, #0x60
	adds r5, #1
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080B5DAE
	ldr r2, [sp]
	mov sb, r2
	cmp r2, #3
	ble _080B5D7E
	movs r3, #1
	ldr r0, [sp, #4]
	movs r2, #0xf0
	lsls r2, r2, #4
	adds r1, r0, r2
	movs r2, #3
_080B5E26:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B5E26
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B5E44: .4byte 0x00001413

	thumb_func_start FUN_080b5e48
FUN_080b5e48: @ 0x080B5E48
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080B5E84
	ldr r1, _080B5E68 @ =0x00001429
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080B5E70
	ldr r1, _080B5E6C @ =0x0000130C
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080B5F0E
	.align 2, 0
_080B5E68: .4byte 0x00001429
_080B5E6C: .4byte 0x0000130C
_080B5E70:
	ldr r1, _080B5E80 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080B5F0E
	.align 2, 0
_080B5E80: .4byte 0x0000130C
_080B5E84:
	ldr r0, _080B5EAC @ =0x0000142E
	adds r6, r4, r0
	ldrb r0, [r6]
	ldr r1, _080B5EB0 @ =0x00001458
	adds r5, r4, r1
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	bge _080B5EB8
	ldr r1, _080B5EB4 @ =0x0000142B
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	b _080B5EDA
	.align 2, 0
_080B5EAC: .4byte 0x0000142E
_080B5EB0: .4byte 0x00001458
_080B5EB4: .4byte 0x0000142B
_080B5EB8:
	ldr r1, _080B5ECC @ =0x0000142B
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r6, [r6]
	cmp r0, r6
	bne _080B5EE4
	cmp r0, #0xf
	bhi _080B5ED0
	subs r1, #0x18
	b _080B5ED2
	.align 2, 0
_080B5ECC: .4byte 0x0000142B
_080B5ED0:
	ldr r1, _080B5EE0 @ =0x00001412
_080B5ED2:
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
_080B5EDA:
	mvns r0, r0
	lsrs r0, r0, #0x1f
	b _080B5EE6
	.align 2, 0
_080B5EE0: .4byte 0x00001412
_080B5EE4:
	movs r0, #1
_080B5EE6:
	cmp r0, #1
	bne _080B5F00
	ldr r1, _080B5EFC @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080B5F0E
	.align 2, 0
_080B5EFC: .4byte 0x0000130C
_080B5F00:
	ldr r1, _080B5F14 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080B5F0E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B5F14: .4byte 0x0000130C

	thumb_func_start FUN_080b5f18
FUN_080b5f18: @ 0x080B5F18
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B5F48 @ =0x0000142E
	adds r6, r4, r0
	ldrb r0, [r6]
	ldr r1, _080B5F4C @ =0x00001458
	adds r5, r4, r1
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	bge _080B5F54
	ldr r1, _080B5F50 @ =0x0000142B
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	blt _080B5F8E
	b _080B5FBA
	.align 2, 0
_080B5F48: .4byte 0x0000142E
_080B5F4C: .4byte 0x00001458
_080B5F50: .4byte 0x0000142B
_080B5F54:
	ldr r5, _080B5F78 @ =0x0000142B
	adds r3, r4, r5
	ldrb r0, [r3]
	ldrb r6, [r6]
	cmp r0, r6
	bne _080B5FC4
	cmp r0, #0xf
	bhi _080B5F80
	ldr r0, _080B5F7C @ =0x00001413
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B5F8E
	movs r0, #3
	ands r0, r1
	b _080B5FA2
	.align 2, 0
_080B5F78: .4byte 0x0000142B
_080B5F7C: .4byte 0x00001413
_080B5F80:
	ldr r0, _080B5F94 @ =0x00001412
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bge _080B5F98
_080B5F8E:
	movs r0, #0
	b _080B5FCA
	.align 2, 0
_080B5F94: .4byte 0x00001412
_080B5F98:
	adds r0, r1, #0
	subs r0, #0x10
	movs r1, #3
	ands r0, r1
	adds r0, #4
_080B5FA2:
	ldr r5, _080B5FC0 @ =0x00001429
	adds r1, r4, r5
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	subs r0, #0x10
	asrs r0, r0, #2
	adds r5, #1
	adds r1, r4, r5
	strb r0, [r1]
	ldrb r0, [r2]
	strb r0, [r3]
_080B5FBA:
	movs r0, #1
	b _080B5FCA
	.align 2, 0
_080B5FC0: .4byte 0x00001429
_080B5FC4:
	cmp r0, #0x20
	bne _080B5FBA
	movs r0, #2
_080B5FCA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b5fd0
FUN_080b5fd0: @ 0x080B5FD0
	push {lr}
	ldr r2, _080B5FF4 @ =0x0000142B
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _080B5FF8 @ =0x00001458
	adds r2, r0, r3
	adds r1, r2, r1
	ldrb r3, [r1]
	ldr r1, _080B5FFC @ =0x0000142E
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r2, r2, r0
	ldrb r1, [r2]
	adds r0, r3, #0
	bl SwapNormalItem
	pop {r0}
	bx r0
	.align 2, 0
_080B5FF4: .4byte 0x0000142B
_080B5FF8: .4byte 0x00001458
_080B5FFC: .4byte 0x0000142E

	thumb_func_start FUN_080b6000
FUN_080b6000: @ 0x080B6000
	push {lr}
	ldr r2, _080B6018 @ =0x0000142E
	adds r1, r0, r2
	adds r2, #0x2a
	adds r0, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl RemoveItem
	pop {r0}
	bx r0
	.align 2, 0
_080B6018: .4byte 0x0000142E

	thumb_func_start FUN_080b601c
FUN_080b601c: @ 0x080B601C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	adds r7, r0, #0
	movs r5, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x44]
	add r1, sp, #0x34
	mov r8, r1
	add r0, sp, #0x3c
	mov sb, r0
	add r1, sp, #0x1c
	mov sl, r1
	str r0, [sp, #0x48]
	mov r1, r8
	str r1, [sp, #0x4c]
	ldr r2, [sp, #0x44]
_080B6046:
	cmp r5, #0
	bne _080B6054
	ldr r1, _080B6050 @ =0x0000142E
	b _080B6056
	.align 2, 0
_080B6050: .4byte 0x0000142E
_080B6054:
	ldr r1, _080B608C @ =0x0000142B
_080B6056:
	adds r0, r7, r1
	ldrb r4, [r0]
	adds r1, r4, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r7, #0
	adds r1, #0x80
	adds r1, r1, r0
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	ldr r1, _080B6090 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	str r2, [sp, #0x50]
	bl GetNormalItemID
	adds r1, r0, #0
	ldr r2, [sp, #0x50]
	cmp r1, #0
	blt _080B6094
	str r6, [r2]
	b _080B6098
	.align 2, 0
_080B608C: .4byte 0x0000142B
_080B6090: .4byte 0x00001458
_080B6094:
	movs r0, #0
	str r0, [r2]
_080B6098:
	adds r0, r1, #0
	adds r0, #0x68
	ldr r1, [sp, #0x4c]
	stm r1!, {r0}
	str r1, [sp, #0x4c]
	ldr r0, _080B6108 @ =0x000002DF
	ldr r1, [sp, #0x48]
	stm r1!, {r0}
	str r1, [sp, #0x48]
	lsls r0, r5, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r4, #0
	str r2, [sp, #0x50]
	bl FUN_080b9938
	ldr r2, [sp, #0x50]
	adds r2, #4
	adds r5, #1
	cmp r5, #1
	ble _080B6046
	add r2, sp, #0x14
	mov r3, sl
	movs r5, #1
_080B60C8:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r5, #1
	cmp r5, #0
	bge _080B60C8
	ldr r1, _080B610C @ =0x00001218
	adds r0, r7, r1
	mov r1, r8
	str r1, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x44]
	add r2, sp, #0xc
	mov r3, sl
	bl FUN_080b9a28
	ldr r0, _080B6110 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B6108: .4byte 0x000002DF
_080B610C: .4byte 0x00001218
_080B6110: .4byte 0x0000038A

	thumb_func_start FUN_080b6114
FUN_080b6114: @ 0x080B6114
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r3, #1
	str r3, [sp, #0x2c]
	ldr r0, _080B61B0 @ =0x0000142E
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r1, _080B61B4 @ =0x00001458
	adds r0, r5, r1
	ldrb r1, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r0, #0x68
	str r0, [sp, #0x34]
	ldr r0, _080B61B8 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r4]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x68
	add r6, sp, #0x34
	str r0, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r0, _080B61BC @ =0x00001218
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080B61C0 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B61B0: .4byte 0x0000142E
_080B61B4: .4byte 0x00001458
_080B61B8: .4byte 0x000002DF
_080B61BC: .4byte 0x00001218
_080B61C0: .4byte 0x0000038A

	thumb_func_start FUN_080b61c4
FUN_080b61c4: @ 0x080B61C4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x88
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080b5cac
	ldr r0, _080B6224 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080B6228 @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080b5b94
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5e48
	ldr r1, _080B622C @ =FUN_080b6230
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080b5ad4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B6224: .4byte 0x00001428
_080B6228: .4byte 0x000010F8
_080B622C: .4byte FUN_080b6230

	thumb_func_start FUN_080b6230
FUN_080b6230: @ 0x080B6230
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B6264 @ =0x00001428
	adds r4, r5, r0
	ldr r2, _080B6268 @ =0x00000D98
	adds r1, r5, r2
	ldr r0, _080B626C @ =0x00000E58
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B6270
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080B627E
	.align 2, 0
_080B6264: .4byte 0x00001428
_080B6268: .4byte 0x00000D98
_080B626C: .4byte 0x00000E58
_080B6270:
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080B627E:
	str r1, [r0]
	ldr r4, _080B62E0 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080B62F0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5ac8
	ldr r1, _080B62E4 @ =0x000010F8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B62E8 @ =0x0000130C
	adds r0, r5, r2
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B62BE
	b _080B6490
_080B62BE:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080B62EC @ =0x00001478
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080B62D8
	b _080B6490
_080B62D8:
	movs r0, #0
	strb r0, [r1]
	b _080B6490
	.align 2, 0
_080B62E0: .4byte 0x030044E0
_080B62E4: .4byte 0x000010F8
_080B62E8: .4byte 0x0000130C
_080B62EC: .4byte 0x00001478
_080B62F0:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5ac8
	ldr r1, _080B6360 @ =0x000010F8
	adds r6, r5, r1
	adds r7, r5, #0
	adds r7, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082372cc
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B6314
	b _080B646C
_080B6314:
	ldr r2, _080B6364 @ =0x0000142B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _080B6380
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B6368 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r2, _080B636C @ =0x000013F4
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B6370 @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B6374 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080B6378 @ =0x0000130C
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B637C @ =FUN_080b6754
	b _080B63C4
	.align 2, 0
_080B6360: .4byte 0x000010F8
_080B6364: .4byte 0x0000142B
_080B6368: .4byte 0x00001428
_080B636C: .4byte 0x000013F4
_080B6370: .4byte 0x000011B8
_080B6374: .4byte 0x0000140D
_080B6378: .4byte 0x0000130C
_080B637C: .4byte FUN_080b6754
_080B6380:
	cmp r0, #0x22
	bne _080B63E8
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B63D0 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r2, _080B63D4 @ =0x000013F4
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #4
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B63D8 @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B63DC @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080B63E0 @ =0x0000130C
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B63E4 @ =FUN_080b67c0
_080B63C4:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B6490
	.align 2, 0
_080B63D0: .4byte 0x00001428
_080B63D4: .4byte 0x000013F4
_080B63D8: .4byte 0x000011B8
_080B63DC: .4byte 0x0000140D
_080B63E0: .4byte 0x0000130C
_080B63E4: .4byte FUN_080b67c0
_080B63E8:
	ldr r0, _080B6434 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fd8
	movs r1, #0x8b
	lsls r1, r1, #5
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080B6438 @ =0x00001178
	adds r2, r5, r0
	ldr r1, _080B643C @ =0x00001118
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080B6440 @ =0x0000142E
	adds r1, r5, r2
	adds r2, #0x2a
	adds r0, r5, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	blt _080B6444
	adds r0, r4, #0
	movs r1, #0x18
	bl FUN_080b9d94
	b _080B644C
	.align 2, 0
_080B6434: .4byte 0x00001428
_080B6438: .4byte 0x00001178
_080B643C: .4byte 0x00001118
_080B6440: .4byte 0x0000142E
_080B6444:
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_080b9d94
_080B644C:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B6468 @ =FUN_080b649c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5e48
	b _080B6490
	.align 2, 0
_080B6468: .4byte FUN_080b649c
_080B646C:
	ldr r0, _080B6498 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B6490
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b5b94
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5e48
_080B6490:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B6498: .4byte 0x00001428

	thumb_func_start FUN_080b649c
FUN_080b649c: @ 0x080B649C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B64D4 @ =0x00001428
	adds r4, r5, r0
	ldr r0, _080B64D8 @ =0x00000D98
	adds r1, r5, r0
	adds r0, #0xc0
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B64DC
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080B6520
	.align 2, 0
_080B64D4: .4byte 0x00001428
_080B64D8: .4byte 0x00000D98
_080B64DC:
	ldr r1, _080B64F8 @ =0x0000140E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _080B64FC
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080B6508
	.align 2, 0
_080B64F8: .4byte 0x0000140E
_080B64FC:
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080B6508:
	str r1, [r0]
	ldr r0, _080B658C @ =0x0000140E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080B6520
	movs r0, #0
	strh r0, [r1]
_080B6520:
	ldr r1, _080B6590 @ =0x000010F8
	adds r6, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r0, _080B6594 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #4
	ands r0, r1
	adds r7, r4, #0
	cmp r0, #0
	beq _080B65A8
	ldr r1, _080B6598 @ =0x00001428
	adds r0, r5, r1
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B65A8
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B659C @ =0x00001118
	adds r0, r5, r1
	movs r1, #0x20
	bl FUN_080b9938
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B65A0 @ =0x0000130C
	adds r0, r5, r1
	movs r4, #1
	rsbs r4, r4, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r0, _080B65A4 @ =0x00000107
	bl PlaySound_082406e0
	b _080B65F8
	.align 2, 0
_080B658C: .4byte 0x0000140E
_080B6590: .4byte 0x000010F8
_080B6594: .4byte 0x030044E0
_080B6598: .4byte 0x00001428
_080B659C: .4byte 0x00001118
_080B65A0: .4byte 0x0000130C
_080B65A4: .4byte 0x00000107
_080B65A8:
	ldr r0, _080B65E0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B6638
	adds r0, r5, #0
	bl FUN_080b5f18
	adds r4, r0, #0
	ldr r1, _080B65E4 @ =0x0000130C
	adds r0, r5, r1
	movs r6, #1
	rsbs r6, r6, #0
	adds r1, r6, #0
	adds r2, r6, #0
	bl FUN_080b98c0
	cmp r4, #1
	beq _080B65E8
	cmp r4, #2
	beq _080B65F8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080B6674
	.align 2, 0
_080B65E0: .4byte 0x030044E0
_080B65E4: .4byte 0x0000130C
_080B65E8:
	adds r0, r5, #0
	bl FUN_080b601c
	ldr r1, _080B65F4 @ =0x080B6835
	b _080B661C
	.align 2, 0
_080B65F4: .4byte 0x080B6835
_080B65F8:
	ldr r1, _080B6628 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r3, #1
	rsbs r3, r3, #0
	bl FUN_080b5b50
	ldr r1, _080B662C @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B6630 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B6634 @ =FUN_080b685c
_080B661C:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B6674
	.align 2, 0
_080B6628: .4byte 0x000013F4
_080B662C: .4byte 0x000011B8
_080B6630: .4byte 0x0000140D
_080B6634: .4byte FUN_080b685c
_080B6638:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B664E
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b61c4
	b _080B6674
_080B664E:
	ldr r0, _080B667C @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B6674
	ldr r0, _080B6680 @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b5b94
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5e48
_080B6674:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B667C: .4byte 0x00001428
_080B6680: .4byte 0x000010F8

	thumb_func_start FUN_080b6684
FUN_080b6684: @ 0x080B6684
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B66D8 @ =0x000010F8
	adds r5, r4, r0
	adds r6, r4, #0
	adds r6, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_082372cc
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B66DC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B66E8
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080B66E0 @ =0x00001428
	adds r0, r4, r1
	adds r1, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b5b94
	ldr r1, _080B66E4 @ =FUN_080b649c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B673A
	.align 2, 0
_080B66D8: .4byte 0x000010F8
_080B66DC: .4byte 0x030044E0
_080B66E0: .4byte 0x00001428
_080B66E4: .4byte FUN_080b649c
_080B66E8:
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080B673A
	movs r0, #0x88
	lsls r0, r0, #5
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B6740 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080B6744 @ =0x000013F4
	adds r0, r4, r1
	ldr r2, [r0]
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080b5b50
	ldr r1, _080B6748 @ =0x000011B8
	adds r0, r4, r1
	ldr r1, _080B674C @ =0x0000140D
	adds r2, r4, r1
	adds r1, r6, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B6750 @ =FUN_080b685c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
_080B673A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B6740: .4byte 0x00000107
_080B6744: .4byte 0x000013F4
_080B6748: .4byte 0x000011B8
_080B674C: .4byte 0x0000140D
_080B6750: .4byte FUN_080b685c

	thumb_func_start FUN_080b6754
FUN_080b6754: @ 0x080B6754
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B6794 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B6798 @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080B67A8
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortInventory
	ldr r1, _080B679C @ =0x0000142C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080B67A0 @ =0x0000142D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080B67A4 @ =0x0000142E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b61c4
	b _080B67B8
	.align 2, 0
_080B6794: .4byte 0x000011B8
_080B6798: .4byte 0x0000140D
_080B679C: .4byte 0x0000142C
_080B67A0: .4byte 0x0000142D
_080B67A4: .4byte 0x0000142E
_080B67A8:
	cmp r0, #0
	bne _080B67B8
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b61c4
_080B67B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b67c0
FUN_080b67c0: @ 0x080B67C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B6808 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B680C @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080B681C
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B6810 @ =0x00001468
	adds r0, r4, r1
	ldrb r0, [r0]
	bl SortInventory
	ldr r3, _080B6814 @ =0x0000142C
	adds r1, r4, r3
	movs r2, #0
	movs r0, #4
	strb r0, [r1]
	ldr r1, _080B6818 @ =0x0000142D
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080b61c4
	b _080B682C
	.align 2, 0
_080B6808: .4byte 0x000011B8
_080B680C: .4byte 0x0000140D
_080B6810: .4byte 0x00001468
_080B6814: .4byte 0x0000142C
_080B6818: .4byte 0x0000142D
_080B681C:
	cmp r0, #0
	bne _080B682C
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b61c4
_080B682C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B6834:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x07, 0x49, 0x60, 0x18, 0x03, 0xF0, 0x4E, 0xF9
	.byte 0x00, 0x28, 0x05, 0xD0, 0x20, 0x1C, 0xFF, 0xF7, 0xC3, 0xFB, 0x20, 0x1C, 0xFF, 0xF7, 0xBA, 0xFC
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x18, 0x12, 0x00, 0x00

	thumb_func_start FUN_080b685c
FUN_080b685c: @ 0x080B685C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B6898 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B689C @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	adds r2, r0, #0
	cmp r2, #1
	bne _080B68A4
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r4, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080b6114
	ldr r1, _080B68A0 @ =FUN_080b68bc
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B68B4
	.align 2, 0
_080B6898: .4byte 0x000011B8
_080B689C: .4byte 0x0000140D
_080B68A0: .4byte FUN_080b68bc
_080B68A4:
	cmp r2, #0
	bne _080B68B4
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b61c4
_080B68B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b68bc
FUN_080b68bc: @ 0x080B68BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B68EC @ =0x00001218
	adds r0, r4, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _080B68E4
	adds r0, r4, #0
	bl FUN_080b6000
	movs r0, #0x87
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080B68F0 @ =FUN_080b68f4
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
_080B68E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B68EC: .4byte 0x00001218
_080B68F0: .4byte FUN_080b68f4

	thumb_func_start FUN_080b68f4
FUN_080b68f4: @ 0x080B68F4
	push {lr}
	adds r3, r0, #0
	ldr r0, _080B691C @ =0x0000140E
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080B693C
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B6924
	ldr r2, _080B6920 @ =0x00000DBA
	adds r1, r3, r2
	b _080B6944
	.align 2, 0
_080B691C: .4byte 0x0000140E
_080B6920: .4byte 0x00000DBA
_080B6924:
	ldrh r1, [r2]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x40
	subs r1, r1, r0
	ldr r2, _080B6938 @ =0x00000DBA
	adds r0, r3, r2
	strh r1, [r0]
	b _080B6956
	.align 2, 0
_080B6938: .4byte 0x00000DBA
_080B693C:
	cmp r1, #0xf
	bhi _080B6950
	ldr r0, _080B694C @ =0x00000DBA
	adds r1, r3, r0
_080B6944:
	movs r0, #0x40
	strh r0, [r1]
	b _080B6956
	.align 2, 0
_080B694C: .4byte 0x00000DBA
_080B6950:
	adds r0, r3, #0
	bl FUN_080b61c4
_080B6956:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b695c
FUN_080b695c: @ 0x080B695C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_080b5afc
	adds r0, r4, #0
	bl FUN_080b5cac
	ldr r0, _080B69AC @ =0x00001428
	adds r5, r4, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080b9ff8
	ldr r0, _080B69B0 @ =0x000010F8
	adds r1, r4, r0
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b5b94
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b5e48
	ldr r1, _080B69B4 @ =FUN_080b6230
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080b5ad4
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B69AC: .4byte 0x00001428
_080B69B0: .4byte 0x000010F8
_080B69B4: .4byte FUN_080b6230

	thumb_func_start FUN_080b69b8
FUN_080b69b8: @ 0x080B69B8
	push {r4, r5, lr}
	sub sp, #0x24
	adds r5, r0, #0
	ldr r1, _080B69E0 @ =0x00001429
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080B69E8
	ldr r2, _080B69E4 @ =0x0000142B
	adds r0, r5, r2
	adds r2, #0x2d
	adds r1, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl FUN_08242b14
	b _080B69EE
	.align 2, 0
_080B69E0: .4byte 0x00001429
_080B69E4: .4byte 0x0000142B
_080B69E8:
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
_080B69EE:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B6A0E
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080B6A60
_080B6A0E:
	mov r0, sp
	bl FUN_08094e70
	adds r2, r0, #0
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r3, r5, r0
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	ldr r1, _080B6A68 @ =0x00000F18
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x38
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B6A6C @ =0x000013F8
	adds r4, r5, r2
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _080B6A70 @ =0x00001404
	adds r1, r5, r0
	mov r0, sp
	bl FUN_08094d1c
	ldr r1, [r4]
	mov r0, sp
	bl FUN_08094d48
_080B6A60:
	add sp, #0x24
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B6A68: .4byte 0x00000F18
_080B6A6C: .4byte 0x000013F8
_080B6A70: .4byte 0x00001404

	thumb_func_start FUN_080b6a74
FUN_080b6a74: @ 0x080B6A74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080B6AF8 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _080B6AFC @ =0x00001413
	adds r1, r7, r3
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r0, #0
	mov sb, r0
	adds r1, r7, #0
	adds r1, #0x80
	str r1, [sp, #4]
	movs r3, #0
	str r3, [sp, #8]
_080B6AA2:
	movs r0, #0
	mov sl, r0
	mov r1, sb
	lsls r1, r1, #2
	mov r8, r1
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [sp, #8]
	adds r5, r1, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, [sp, #4]
	adds r4, r0, r3
_080B6AC4:
	mov r6, r8
	add r6, sl
	ldr r1, _080B6B00 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	bl GetWeaponID
	adds r2, r0, #0
	cmp r2, #0
	ble _080B6B04
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B6B1A
	.align 2, 0
_080B6AF8: .4byte 0x00001412
_080B6AFC: .4byte 0x00001413
_080B6B00: .4byte 0x00001458
_080B6B04:
	ldr r3, _080B6B30 @ =0x00001412
	adds r1, r7, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B6B12
	strb r6, [r1]
_080B6B12:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B6B1A:
	adds r0, r6, #0
	bl FUN_082430d4
	cmp r0, #0
	beq _080B6B34
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080B6B3C
	.align 2, 0
_080B6B30: .4byte 0x00001412
_080B6B34:
	adds r0, r5, #0
	ldr r1, _080B6BC4 @ =0x000002DF
	bl FUN_080b95bc
_080B6B3C:
	adds r5, #0x60
	adds r4, #0x60
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080B6AC4
	ldr r3, [sp, #8]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r3, r3, r0
	str r3, [sp, #8]
	movs r1, #1
	add sb, r1
	mov r3, sb
	cmp r3, #3
	ble _080B6AA2
	movs r0, #0
	mov sb, r0
_080B6B62:
	movs r1, #0
	mov sl, r1
	mov r3, sb
	lsls r3, r3, #2
	mov r8, r3
	mov r0, sb
	adds r0, #1
	str r0, [sp]
	mov r2, r8
	adds r2, #0x13
	mov r1, sb
	lsls r0, r1, #3
	add r0, r8
	lsls r0, r0, #5
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r1, r7, r3
	adds r6, r0, r1
	mov r5, r8
	adds r5, #0x10
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp, #4]
	adds r4, r0, r1
_080B6B94:
	ldr r3, _080B6BC8 @ =0x00001458
	adds r0, r7, r3
	adds r0, r0, r5
	ldrb r0, [r0]
	bl GetWeaponID
	adds r2, r0, #0
	cmp r2, #0
	ble _080B6BCC
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B6BE2
	.align 2, 0
_080B6BC4: .4byte 0x000002DF
_080B6BC8: .4byte 0x00001458
_080B6BCC:
	ldr r0, _080B6C44 @ =0x00001413
	adds r1, r7, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B6BDA
	strb r5, [r1]
_080B6BDA:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B6BE2:
	adds r4, #0x60
	adds r6, #0x60
	adds r5, #1
	movs r1, #1
	add sl, r1
	mov r3, sl
	cmp r3, #3
	ble _080B6B94
	ldr r0, [sp]
	mov sb, r0
	cmp r0, #3
	ble _080B6B62
	ldr r0, _080B6C48 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, [sp, #4]
	movs r3, #0xf0
	lsls r3, r3, #4
	adds r2, r1, r3
	adds r3, r0, #0
	adds r3, #0x60
	ldr r0, _080B6C4C @ =0x00000F98
	adds r5, r7, r0
	movs r6, #3
_080B6C10:
	ldrh r4, [r3]
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _080B6C50
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r5]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r5, #2]
	b _080B6C58
	.align 2, 0
_080B6C44: .4byte 0x00001413
_080B6C48: .4byte 0x030046A0
_080B6C4C: .4byte 0x00000F98
_080B6C50:
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080B6C58:
	adds r2, #0x60
	adds r3, #2
	adds r5, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B6C10
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b6c74
FUN_080b6c74: @ 0x080B6C74
	push {r4, lr}
	cmp r1, #0xf
	ble _080B6C80
	b _080B6C9A
_080B6C7C:
	adds r0, r3, #0
	b _080B6C9E
_080B6C80:
	movs r3, #0
	ldr r0, _080B6CA4 @ =0x030046A0
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x60
_080B6C8A:
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, r1
	beq _080B6C7C
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	ble _080B6C8A
_080B6C9A:
	movs r0, #1
	rsbs r0, r0, #0
_080B6C9E:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B6CA4: .4byte 0x030046A0

	thumb_func_start FUN_080b6ca8
FUN_080b6ca8: @ 0x080B6CA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	adds r7, r0, #0
	movs r6, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x48]
	mov r1, sp
	adds r1, #0x34
	str r1, [sp, #0x4c]
	add r2, sp, #0x3c
	mov sl, r2
	subs r0, #0x10
	str r0, [sp, #0x44]
	mov r1, sl
	str r1, [sp, #0x50]
	ldr r2, [sp, #0x4c]
	str r2, [sp, #0x54]
	ldr r0, [sp, #0x48]
	mov sb, r0
_080B6CD8:
	cmp r6, #0
	bne _080B6CE8
	ldr r1, _080B6CE4 @ =0x0000142E
	adds r0, r7, r1
	b _080B6CEC
	.align 2, 0
_080B6CE4: .4byte 0x0000142E
_080B6CE8:
	ldr r2, _080B6D40 @ =0x0000142B
	adds r0, r7, r2
_080B6CEC:
	ldrb r4, [r0]
	adds r0, r4, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r5, r7, #0
	adds r5, #0x80
	adds r1, r5, r1
	ldr r0, [r1]
	movs r2, #1
	mov r8, r2
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B6D24
	adds r0, #0x28
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r1, r5, r1
	ldr r0, [r1]
	mov r2, r8
	orrs r0, r2
	str r0, [r1]
_080B6D24:
	ldr r1, _080B6D44 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	bl GetWeaponID
	adds r1, r0, #0
	cmp r1, #0
	ble _080B6D48
	mov r2, r8
	mov r0, sb
	str r2, [r0]
	b _080B6D4E
	.align 2, 0
_080B6D40: .4byte 0x0000142B
_080B6D44: .4byte 0x00001458
_080B6D48:
	movs r0, #0
	mov r2, sb
	str r0, [r2]
_080B6D4E:
	ldr r0, [sp, #0x54]
	stm r0!, {r1}
	str r0, [sp, #0x54]
	ldr r0, _080B6DB8 @ =0x000002DF
	ldr r1, [sp, #0x50]
	stm r1!, {r0}
	str r1, [sp, #0x50]
	lsls r0, r6, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r4, #0
	bl FUN_080b9938
	movs r2, #4
	add sb, r2
	adds r6, #1
	cmp r6, #1
	ble _080B6CD8
	add r2, sp, #0x14
	ldr r3, [sp, #0x44]
	movs r6, #1
_080B6D78:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r6, #1
	cmp r6, #0
	bge _080B6D78
	ldr r1, _080B6DBC @ =0x00001218
	adds r0, r7, r1
	ldr r2, [sp, #0x4c]
	str r2, [sp]
	mov r1, sl
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x48]
	add r2, sp, #0xc
	ldr r3, [sp, #0x44]
	bl FUN_080b9a28
	ldr r0, _080B6DC0 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B6DB8: .4byte 0x000002DF
_080B6DBC: .4byte 0x00001218
_080B6DC0: .4byte 0x0000038A

	thumb_func_start FUN_080b6dc4
FUN_080b6dc4: @ 0x080B6DC4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r3, #1
	str r3, [sp, #0x2c]
	ldr r0, _080B6E5C @ =0x0000142E
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r1, _080B6E60 @ =0x00001458
	adds r0, r5, r1
	ldrb r1, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetWeaponID
	str r0, [sp, #0x34]
	ldr r0, _080B6E64 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r4]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	add r6, sp, #0x34
	str r2, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r0, _080B6E68 @ =0x00001218
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080B6E6C @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B6E5C: .4byte 0x0000142E
_080B6E60: .4byte 0x00001458
_080B6E64: .4byte 0x000002DF
_080B6E68: .4byte 0x00001218
_080B6E6C: .4byte 0x0000038A

	thumb_func_start FUN_080b6e70
FUN_080b6e70: @ 0x080B6E70
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080B6EAC
	ldr r1, _080B6E90 @ =0x00001429
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080B6E98
	ldr r1, _080B6E94 @ =0x0000130C
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080B6F9A
	.align 2, 0
_080B6E90: .4byte 0x00001429
_080B6E94: .4byte 0x0000130C
_080B6E98:
	ldr r1, _080B6EA8 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080B6F9A
	.align 2, 0
_080B6EA8: .4byte 0x0000130C
_080B6EAC:
	ldr r0, _080B6EE8 @ =0x0000142E
	adds r6, r4, r0
	ldrb r0, [r6]
	ldr r1, _080B6EEC @ =0x00001458
	adds r7, r4, r1
	adds r0, r7, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	bne _080B6EF8
	ldr r0, _080B6EF0 @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	adds r0, r7, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	beq _080B6F9A
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B6F9A
	ldr r1, _080B6EF4 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	b _080B6F9A
	.align 2, 0
_080B6EE8: .4byte 0x0000142E
_080B6EEC: .4byte 0x00001458
_080B6EF0: .4byte 0x0000142B
_080B6EF4: .4byte 0x0000142C
_080B6EF8:
	ldr r0, _080B6F1C @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	ldrb r1, [r6]
	cmp r0, r1
	bne _080B6F3C
	ldr r1, _080B6F20 @ =0x00001428
	adds r0, r4, r1
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B6F68
	ldrb r0, [r5]
	cmp r0, #0xf
	bhi _080B6F28
	ldr r1, _080B6F24 @ =0x00001413
	b _080B6F2A
	.align 2, 0
_080B6F1C: .4byte 0x0000142B
_080B6F20: .4byte 0x00001428
_080B6F24: .4byte 0x00001413
_080B6F28:
	ldr r1, _080B6F38 @ =0x00001412
_080B6F2A:
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mvns r0, r0
	lsrs r1, r0, #0x1f
	b _080B6F72
	.align 2, 0
_080B6F38: .4byte 0x00001412
_080B6F3C:
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B6F50
	ldr r1, _080B6F4C @ =0x0000142C
	b _080B6F5E
	.align 2, 0
_080B6F4C: .4byte 0x0000142C
_080B6F50:
	ldrb r1, [r6]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B6F70
	ldr r1, _080B6F6C @ =0x00001429
_080B6F5E:
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #3
	bls _080B6F72
_080B6F68:
	movs r1, #0
	b _080B6F72
	.align 2, 0
_080B6F6C: .4byte 0x00001429
_080B6F70:
	movs r1, #1
_080B6F72:
	cmp r1, #1
	bne _080B6F8C
	ldr r1, _080B6F88 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080B6F9A
	.align 2, 0
_080B6F88: .4byte 0x0000130C
_080B6F8C:
	ldr r1, _080B6FA0 @ =0x0000130C
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080B6F9A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B6FA0: .4byte 0x0000130C

	thumb_func_start FUN_080b6fa4
FUN_080b6fa4: @ 0x080B6FA4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B6FE8 @ =0x0000142E
	adds r5, r4, r0
	ldrb r0, [r5]
	ldr r1, _080B6FEC @ =0x00001458
	adds r6, r4, r1
	adds r0, r6, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	bne _080B6FF8
	ldr r3, _080B6FF0 @ =0x0000142B
	adds r5, r4, r3
	ldrb r0, [r5]
	adds r0, r6, r0
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	beq _080B709A
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B70A4
_080B6FDC:
	ldr r1, _080B6FF4 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080B709A
	b _080B70A4
	.align 2, 0
_080B6FE8: .4byte 0x0000142E
_080B6FEC: .4byte 0x00001458
_080B6FF0: .4byte 0x0000142B
_080B6FF4: .4byte 0x0000142C
_080B6FF8:
	ldr r3, _080B7044 @ =0x0000142B
	adds r6, r4, r3
	ldrb r0, [r6]
	ldrb r1, [r5]
	cmp r0, r1
	bne _080B7070
	subs r3, #3
	adds r0, r4, r3
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B709A
	ldrb r0, [r6]
	cmp r0, #0xf
	bhi _080B7050
	ldr r0, _080B7048 @ =0x00001413
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B709A
	movs r0, #3
	ands r0, r1
_080B702A:
	ldr r3, _080B704C @ =0x00001429
	adds r1, r4, r3
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	subs r0, #0x10
	asrs r0, r0, #2
	adds r3, #1
	adds r1, r4, r3
	strb r0, [r1]
	ldrb r0, [r2]
	strb r0, [r6]
	b _080B70A4
	.align 2, 0
_080B7044: .4byte 0x0000142B
_080B7048: .4byte 0x00001413
_080B704C: .4byte 0x00001429
_080B7050:
	ldr r0, _080B706C @ =0x00001412
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B709A
	adds r0, r1, #0
	subs r0, #0x10
	movs r1, #3
	ands r0, r1
	adds r0, #4
	b _080B702A
	.align 2, 0
_080B706C: .4byte 0x00001412
_080B7070:
	cmp r0, #0x20
	bne _080B7078
	movs r0, #2
	b _080B70A6
_080B7078:
	ldrb r1, [r6]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	bge _080B6FDC
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B70A4
	ldr r3, _080B70A0 @ =0x00001429
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bls _080B70A4
_080B709A:
	movs r0, #0
	b _080B70A6
	.align 2, 0
_080B70A0: .4byte 0x00001429
_080B70A4:
	movs r0, #1
_080B70A6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b70ac
FUN_080b70ac: @ 0x080B70AC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x88
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080b6a74
	ldr r0, _080B710C @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080B7110 @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080b69b8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b6e70
	ldr r1, _080B7114 @ =FUN_080b7118
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080b5ad4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B710C: .4byte 0x00001428
_080B7110: .4byte 0x000010F8
_080B7114: .4byte FUN_080b7118

	thumb_func_start FUN_080b7118
FUN_080b7118: @ 0x080B7118
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B714C @ =0x00001428
	adds r4, r5, r0
	ldr r0, _080B7150 @ =0x00000D98
	adds r1, r5, r0
	adds r0, #0xc0
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B7154
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080B7162
	.align 2, 0
_080B714C: .4byte 0x00001428
_080B7150: .4byte 0x00000D98
_080B7154:
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080B7162:
	str r1, [r0]
	ldr r0, _080B71D0 @ =0x000010F8
	adds r6, r5, r0
	adds r7, r5, #0
	adds r7, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082372cc
	ldr r4, _080B71D4 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080B71E0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5ac8
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B71D8 @ =0x0000130C
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B71AE
	b _080B73AC
_080B71AE:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080B71DC @ =0x00001478
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080B71C8
	b _080B73AC
_080B71C8:
	movs r0, #0
	strb r0, [r1]
	b _080B73AC
	.align 2, 0
_080B71D0: .4byte 0x000010F8
_080B71D4: .4byte 0x030044E0
_080B71D8: .4byte 0x0000130C
_080B71DC: .4byte 0x00001478
_080B71E0:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5ac8
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082372cc
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B71FC
	b _080B7388
_080B71FC:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B7250 @ =0x0000142B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _080B726C
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B7254 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r1, _080B7258 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B725C @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B7260 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B7264 @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B7268 @ =FUN_080b7670
	b _080B7378
	.align 2, 0
_080B7250: .4byte 0x0000142B
_080B7254: .4byte 0x00001428
_080B7258: .4byte 0x000013F4
_080B725C: .4byte 0x000011B8
_080B7260: .4byte 0x0000140D
_080B7264: .4byte 0x0000130C
_080B7268: .4byte FUN_080b7670
_080B726C:
	cmp r0, #0x22
	bne _080B72CC
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _080B72B4 @ =0x00001428
	adds r0, r5, r1
	bl FUN_080b9fd8
	ldr r1, _080B72B8 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #4
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B72BC @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B72C0 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B72C4 @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B72C8 @ =0x080B76DD
	b _080B7378
	.align 2, 0
_080B72B4: .4byte 0x00001428
_080B72B8: .4byte 0x000013F4
_080B72BC: .4byte 0x000011B8
_080B72C0: .4byte 0x0000140D
_080B72C4: .4byte 0x0000130C
_080B72C8: .4byte 0x080B76DD
_080B72CC:
	ldr r0, _080B7324 @ =0x00001428
	adds r7, r5, r0
	adds r0, r7, #0
	bl FUN_080b9fd8
	movs r1, #0x8b
	lsls r1, r1, #5
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080B7328 @ =0x00001178
	adds r2, r5, r0
	ldr r1, _080B732C @ =0x00001118
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _080B7330 @ =0x0000142E
	adds r6, r5, r0
	ldr r1, _080B7334 @ =0x00001458
	adds r0, r5, r1
	ldrb r1, [r6]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetWeaponID
	adds r4, r0, #0
	cmp r4, #0
	ble _080B7366
	ldrb r1, [r6]
	adds r0, r5, #0
	bl FUN_080b6c74
	cmp r0, #0
	blt _080B7338
	adds r0, r7, #0
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080B736E
	.align 2, 0
_080B7324: .4byte 0x00001428
_080B7328: .4byte 0x00001178
_080B732C: .4byte 0x00001118
_080B7330: .4byte 0x0000142E
_080B7334: .4byte 0x00001458
_080B7338:
	adds r0, r4, #0
	subs r0, #0x3a
	cmp r0, #3
	bls _080B734C
	cmp r4, #0x3f
	beq _080B734C
	cmp r4, #0x40
	beq _080B734C
	cmp r4, #0x41
	bne _080B735C
_080B734C:
	ldr r1, _080B7358 @ =0x00001428
	adds r0, r5, r1
	movs r1, #0x1c
	bl FUN_080b9d94
	b _080B736E
	.align 2, 0
_080B7358: .4byte 0x00001428
_080B735C:
	adds r0, r7, #0
	movs r1, #0x18
	bl FUN_080b9d94
	b _080B736E
_080B7366:
	adds r0, r7, #0
	movs r1, #0x1c
	bl FUN_080b9d94
_080B736E:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b6e70
	ldr r1, _080B7384 @ =FUN_080b73b8
_080B7378:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B73AC
	.align 2, 0
_080B7384: .4byte FUN_080b73b8
_080B7388:
	ldr r0, _080B73B4 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B73AC
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b69b8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b6e70
_080B73AC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B73B4: .4byte 0x00001428

	thumb_func_start FUN_080b73b8
FUN_080b73b8: @ 0x080B73B8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B73F0 @ =0x00001428
	adds r4, r5, r0
	ldr r0, _080B73F4 @ =0x00000D98
	adds r1, r5, r0
	adds r0, #0xc0
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B73F8
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080B743C
	.align 2, 0
_080B73F0: .4byte 0x00001428
_080B73F4: .4byte 0x00000D98
_080B73F8:
	ldr r1, _080B7414 @ =0x0000140E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _080B7418
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080B7424
	.align 2, 0
_080B7414: .4byte 0x0000140E
_080B7418:
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080B7424:
	str r1, [r0]
	ldr r0, _080B74A8 @ =0x0000140E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080B743C
	movs r0, #0
	strh r0, [r1]
_080B743C:
	ldr r1, _080B74AC @ =0x000010F8
	adds r6, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r0, _080B74B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #4
	ands r0, r1
	adds r7, r4, #0
	cmp r0, #0
	beq _080B74C4
	ldr r1, _080B74B4 @ =0x00001428
	adds r0, r5, r1
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B74C4
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B74B8 @ =0x00001118
	adds r0, r5, r1
	movs r1, #0x20
	bl FUN_080b9938
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B74BC @ =0x0000130C
	adds r0, r5, r1
	movs r4, #1
	rsbs r4, r4, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r0, _080B74C0 @ =0x00000107
	bl PlaySound_082406e0
	b _080B7514
	.align 2, 0
_080B74A8: .4byte 0x0000140E
_080B74AC: .4byte 0x000010F8
_080B74B0: .4byte 0x030044E0
_080B74B4: .4byte 0x00001428
_080B74B8: .4byte 0x00001118
_080B74BC: .4byte 0x0000130C
_080B74C0: .4byte 0x00000107
_080B74C4:
	ldr r0, _080B74FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B7554
	adds r0, r5, #0
	bl FUN_080b6fa4
	adds r4, r0, #0
	ldr r1, _080B7500 @ =0x0000130C
	adds r0, r5, r1
	movs r6, #1
	rsbs r6, r6, #0
	adds r1, r6, #0
	adds r2, r6, #0
	bl FUN_080b98c0
	cmp r4, #1
	beq _080B7504
	cmp r4, #2
	beq _080B7514
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080B7590
	.align 2, 0
_080B74FC: .4byte 0x030044E0
_080B7500: .4byte 0x0000130C
_080B7504:
	adds r0, r5, #0
	bl FUN_080b6ca8
	ldr r1, _080B7510 @ =0x080B7751
	b _080B7538
	.align 2, 0
_080B7510: .4byte 0x080B7751
_080B7514:
	ldr r1, _080B7544 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r3, #1
	rsbs r3, r3, #0
	bl FUN_080b5b50
	ldr r1, _080B7548 @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B754C @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B7550 @ =FUN_080b7794
_080B7538:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B7590
	.align 2, 0
_080B7544: .4byte 0x000013F4
_080B7548: .4byte 0x000011B8
_080B754C: .4byte 0x0000140D
_080B7550: .4byte FUN_080b7794
_080B7554:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B756A
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b70ac
	b _080B7590
_080B756A:
	ldr r0, _080B7598 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B7590
	ldr r0, _080B759C @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b69b8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b6e70
_080B7590:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B7598: .4byte 0x00001428
_080B759C: .4byte 0x000010F8

	thumb_func_start FUN_080b75a0
FUN_080b75a0: @ 0x080B75A0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B75F4 @ =0x000010F8
	adds r5, r4, r0
	adds r6, r4, #0
	adds r6, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_082372cc
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B75F8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B7604
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080B75FC @ =0x00001428
	adds r0, r4, r1
	adds r1, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b69b8
	ldr r1, _080B7600 @ =FUN_080b73b8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B7656
	.align 2, 0
_080B75F4: .4byte 0x000010F8
_080B75F8: .4byte 0x030044E0
_080B75FC: .4byte 0x00001428
_080B7600: .4byte FUN_080b73b8
_080B7604:
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080B7656
	movs r0, #0x88
	lsls r0, r0, #5
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B765C @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080B7660 @ =0x000013F4
	adds r0, r4, r1
	ldr r2, [r0]
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080b5b50
	ldr r1, _080B7664 @ =0x000011B8
	adds r0, r4, r1
	ldr r1, _080B7668 @ =0x0000140D
	adds r2, r4, r1
	adds r1, r6, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B766C @ =FUN_080b7794
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
_080B7656:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B765C: .4byte 0x00000107
_080B7660: .4byte 0x000013F4
_080B7664: .4byte 0x000011B8
_080B7668: .4byte 0x0000140D
_080B766C: .4byte FUN_080b7794

	thumb_func_start FUN_080b7670
FUN_080b7670: @ 0x080B7670
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B76B0 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B76B4 @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080B76C4
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortWeapons
	ldr r1, _080B76B8 @ =0x0000142C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080B76BC @ =0x0000142D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080B76C0 @ =0x0000142E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b70ac
	b _080B76D4
	.align 2, 0
_080B76B0: .4byte 0x000011B8
_080B76B4: .4byte 0x0000140D
_080B76B8: .4byte 0x0000142C
_080B76BC: .4byte 0x0000142D
_080B76C0: .4byte 0x0000142E
_080B76C4:
	cmp r0, #0
	bne _080B76D4
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b70ac
_080B76D4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B76DC:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0x10, 0x49, 0x60, 0x18, 0x21, 0x1C, 0x18, 0x31, 0x0F, 0x4B, 0xE2, 0x18, 0x02, 0xF0, 0x46, 0xF8
	.byte 0x01, 0x28, 0x21, 0xD1, 0xDD, 0x20, 0x88, 0xF1, 0xF3, 0xFF, 0x0C, 0x49, 0x60, 0x18, 0x00, 0x78
	.byte 0x8B, 0xF1, 0xF0, 0xFA, 0x0A, 0x4B, 0xE1, 0x18, 0x00, 0x22, 0x04, 0x20, 0x08, 0x70, 0x09, 0x49
	.byte 0x60, 0x18, 0x02, 0x70, 0x02, 0x33, 0xE1, 0x18, 0x10, 0x20, 0x08, 0x70, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0xC5, 0xFC, 0x11, 0xE0, 0xB8, 0x11, 0x00, 0x00, 0x0D, 0x14, 0x00, 0x00, 0x68, 0x14, 0x00, 0x00
	.byte 0x2C, 0x14, 0x00, 0x00, 0x2D, 0x14, 0x00, 0x00, 0x00, 0x28, 0x05, 0xD1, 0xDE, 0x20, 0x88, 0xF1
	.byte 0xCF, 0xFF, 0x20, 0x1C, 0xFF, 0xF7, 0xB2, 0xFC, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x0C, 0x49, 0x60, 0x18, 0x02, 0xF0, 0xC0, 0xF9, 0x00, 0x28, 0x10, 0xD0
	.byte 0x0A, 0x4B, 0xE0, 0x18, 0x00, 0x78, 0x0A, 0x49, 0x62, 0x18, 0x10, 0x18, 0x00, 0x78, 0x03, 0x33
	.byte 0xE1, 0x18, 0x09, 0x78, 0x52, 0x18, 0x11, 0x78, 0x8B, 0xF1, 0x64, 0xFA, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x95, 0xFC, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x18, 0x12, 0x00, 0x00, 0x2B, 0x14, 0x00, 0x00
	.byte 0x58, 0x14, 0x00, 0x00

	thumb_func_start FUN_080b7794
FUN_080b7794: @ 0x080B7794
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B77D0 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B77D4 @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	adds r2, r0, #0
	cmp r2, #1
	bne _080B77DC
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r4, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080b6dc4
	ldr r1, _080B77D8 @ =0x080B77F5
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B77EC
	.align 2, 0
_080B77D0: .4byte 0x000011B8
_080B77D4: .4byte 0x0000140D
_080B77D8: .4byte 0x080B77F5
_080B77DC:
	cmp r2, #0
	bne _080B77EC
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b70ac
_080B77EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B77F4:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x0D, 0x49, 0x60, 0x18, 0x02, 0xF0, 0x6E, 0xF9
	.byte 0x00, 0x28, 0x11, 0xD0, 0x0B, 0x4A, 0xA1, 0x18, 0x2A, 0x32, 0xA0, 0x18, 0x09, 0x78, 0x40, 0x18
	.byte 0x00, 0x78, 0x8B, 0xF1, 0xF9, 0xF9, 0x87, 0x20, 0x40, 0x00, 0x88, 0xF1, 0x61, 0xFF, 0x06, 0x49
	.byte 0x20, 0x1C, 0x00, 0x22, 0xFE, 0xF7, 0x56, 0xF9, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x18, 0x12, 0x00, 0x00, 0x2E, 0x14, 0x00, 0x00, 0x3D, 0x78, 0x0B, 0x08

	thumb_func_start FUN_080b783c
FUN_080b783c: @ 0x080B783C
	push {lr}
	adds r3, r0, #0
	ldr r0, _080B7864 @ =0x0000140E
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080B7884
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B786C
	ldr r2, _080B7868 @ =0x00000DBA
	adds r1, r3, r2
	b _080B788C
	.align 2, 0
_080B7864: .4byte 0x0000140E
_080B7868: .4byte 0x00000DBA
_080B786C:
	ldrh r1, [r2]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x40
	subs r1, r1, r0
	ldr r2, _080B7880 @ =0x00000DBA
	adds r0, r3, r2
	strh r1, [r0]
	b _080B789E
	.align 2, 0
_080B7880: .4byte 0x00000DBA
_080B7884:
	cmp r1, #0xf
	bhi _080B7898
	ldr r0, _080B7894 @ =0x00000DBA
	adds r1, r3, r0
_080B788C:
	movs r0, #0x40
	strh r0, [r1]
	b _080B789E
	.align 2, 0
_080B7894: .4byte 0x00000DBA
_080B7898:
	adds r0, r3, #0
	bl FUN_080b70ac
_080B789E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b78a4
FUN_080b78a4: @ 0x080B78A4
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_080b5afc
	adds r0, r4, #0
	bl FUN_080b6a74
	ldr r0, _080B78F4 @ =0x00001428
	adds r5, r4, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080b9ff8
	ldr r0, _080B78F8 @ =0x000010F8
	adds r1, r4, r0
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b69b8
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b6e70
	ldr r1, _080B78FC @ =FUN_080b7118
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080b5ad4
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B78F4: .4byte 0x00001428
_080B78F8: .4byte 0x000010F8
_080B78FC: .4byte FUN_080b7118

	thumb_func_start FUN_080b7900
FUN_080b7900: @ 0x080B7900
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _080B7930 @ =0x00001429
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080B793C
	ldr r2, _080B7934 @ =0x0000142B
	adds r1, r5, r2
	adds r2, #0x2d
	adds r0, r5, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _080B7938 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r6, [r0, r2]
	b _080B7940
	.align 2, 0
_080B7930: .4byte 0x00001429
_080B7934: .4byte 0x0000142B
_080B7938: .4byte 0x030046A0
_080B793C:
	movs r6, #1
	rsbs r6, r6, #0
_080B7940:
	cmp r6, #0
	bge _080B795C
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080B79C6
_080B795C:
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B79CC @ =0x00000F18
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x38
	movs r2, #0xcf
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080B79D0 @ =0x000013FC
	adds r5, r5, r2
	ldr r0, [r5]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _080B79D4 @ =0x08DAA7B0
	lsls r4, r6, #3
	adds r4, r4, r0
	ldrb r1, [r4, #1]
	movs r0, #0
	bl FUN_08049e6c
	ldrb r1, [r4, #2]
	movs r0, #1
	bl FUN_08049e6c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r6, #0
	bl FUN_08047a28
	ldr r0, [r5]
	bl VM_ParseStringRef
	adds r0, #0x25
	adds r0, r0, r6
	bl Textbox_LookupString
	bl FUN_08049e30
_080B79C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B79CC: .4byte 0x00000F18
_080B79D0: .4byte 0x000013FC
_080B79D4: .4byte 0x08DAA7B0

	thumb_func_start FUN_080b79d8
FUN_080b79d8: @ 0x080B79D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080B7A68 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _080B7A6C @ =0x00001413
	adds r1, r7, r2
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r3, #0
	mov sb, r3
	adds r0, r7, #0
	adds r0, #0x80
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
_080B7A06:
	movs r2, #0
	mov sl, r2
	mov r3, sb
	lsls r3, r3, #2
	mov r8, r3
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r2, [sp, #8]
	adds r5, r2, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, [sp, #4]
	adds r4, r0, r3
_080B7A28:
	mov r6, r8
	add r6, sl
	ldr r1, _080B7A70 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	ldr r1, _080B7A74 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r2, #0
	blt _080B7A78
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B7A8E
	.align 2, 0
_080B7A68: .4byte 0x00001412
_080B7A6C: .4byte 0x00001413
_080B7A70: .4byte 0x00001458
_080B7A74: .4byte 0x030046A0
_080B7A78:
	ldr r0, _080B7AA8 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B7A86
	strb r6, [r1]
_080B7A86:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B7A8E:
	ldr r0, _080B7AAC @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bne _080B7AB0
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080B7AB8
	.align 2, 0
_080B7AA8: .4byte 0x00001412
_080B7AAC: .4byte 0x030046A0
_080B7AB0:
	adds r0, r5, #0
	ldr r1, _080B7B4C @ =0x000002DF
	bl FUN_080b95bc
_080B7AB8:
	adds r5, #0x60
	adds r4, #0x60
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	ble _080B7A28
	ldr r0, [sp, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #8]
	add sb, r2
	mov r2, sb
	cmp r2, #3
	ble _080B7A06
	movs r3, #0
	mov sb, r3
_080B7ADC:
	movs r0, #0
	mov sl, r0
	mov r1, sb
	lsls r1, r1, #2
	mov r8, r1
	mov r2, sb
	adds r2, #1
	str r2, [sp]
	mov r2, r8
	adds r2, #0x13
	mov r3, sb
	lsls r0, r3, #3
	add r0, r8
	lsls r0, r0, #5
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r1, r7, r3
	adds r6, r0, r1
	mov r5, r8
	adds r5, #0x10
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp, #4]
	adds r4, r0, r1
_080B7B0E:
	ldr r2, _080B7B50 @ =0x00001458
	adds r0, r7, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	ldr r1, _080B7B54 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r2, [r0, r1]
	cmp r2, #0
	blt _080B7B58
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080B7B6E
	.align 2, 0
_080B7B4C: .4byte 0x000002DF
_080B7B50: .4byte 0x00001458
_080B7B54: .4byte 0x030046A0
_080B7B58:
	ldr r2, _080B7BD0 @ =0x00001413
	adds r1, r7, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B7B66
	strb r5, [r1]
_080B7B66:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B7B6E:
	adds r4, #0x60
	adds r6, #0x60
	adds r5, #1
	movs r3, #1
	add sl, r3
	mov r0, sl
	cmp r0, #3
	ble _080B7B0E
	ldr r1, [sp]
	mov sb, r1
	cmp r1, #3
	ble _080B7ADC
	ldr r0, _080B7BD4 @ =0x030046A0
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x5c
	ldrh r4, [r3]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	blt _080B7BE0
	movs r0, #0xf8
	lsls r0, r0, #4
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r2, _080B7BD8 @ =0x00000F98
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r3, _080B7BDC @ =0x00000F9A
	adds r1, r7, r3
	strh r0, [r1]
	b _080B7BEE
	.align 2, 0
_080B7BD0: .4byte 0x00001413
_080B7BD4: .4byte 0x030046A0
_080B7BD8: .4byte 0x00000F98
_080B7BDC: .4byte 0x00000F9A
_080B7BE0:
	movs r1, #0xf8
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_080B7BEE:
	movs r3, #1
	ldr r2, [sp, #4]
	movs r0, #0xf6
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r2, #2
_080B7BFA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B7BFA
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b7c18
FUN_080b7c18: @ 0x080B7C18
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080B7C54
	ldr r1, _080B7C38 @ =0x00001429
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080B7C40
	ldr r2, _080B7C3C @ =0x0000130C
	adds r0, r4, r2
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080B7D5E
	.align 2, 0
_080B7C38: .4byte 0x00001429
_080B7C3C: .4byte 0x0000130C
_080B7C40:
	ldr r3, _080B7C50 @ =0x0000130C
	adds r0, r4, r3
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080B7D5E
	.align 2, 0
_080B7C50: .4byte 0x0000130C
_080B7C54:
	ldr r5, _080B7CA8 @ =0x0000142E
	adds r0, r4, r5
	ldrb r3, [r0]
	ldr r0, _080B7CAC @ =0x00001458
	adds r1, r4, r0
	adds r0, r1, r3
	ldrb r6, [r0]
	ldr r0, _080B7CB0 @ =0x030046A0
	ldr r2, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	bge _080B7CBC
	ldr r3, _080B7CB4 @ =0x0000142B
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, r1, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r2
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _080B7D5E
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bne _080B7D5E
	ldr r1, _080B7CB8 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	b _080B7D5E
	.align 2, 0
_080B7CA8: .4byte 0x0000142E
_080B7CAC: .4byte 0x00001458
_080B7CB0: .4byte 0x030046A0
_080B7CB4: .4byte 0x0000142B
_080B7CB8: .4byte 0x0000142C
_080B7CBC:
	ldr r0, _080B7CE0 @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, r3
	bne _080B7D00
	ldr r1, _080B7CE4 @ =0x00001428
	adds r0, r4, r1
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B7D2C
	ldrb r0, [r5]
	cmp r0, #0xf
	bhi _080B7CEC
	ldr r2, _080B7CE8 @ =0x00001413
	adds r0, r4, r2
	b _080B7CF0
	.align 2, 0
_080B7CE0: .4byte 0x0000142B
_080B7CE4: .4byte 0x00001428
_080B7CE8: .4byte 0x00001413
_080B7CEC:
	ldr r3, _080B7CFC @ =0x00001412
	adds r0, r4, r3
_080B7CF0:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mvns r0, r0
	lsrs r1, r0, #0x1f
	b _080B7D36
	.align 2, 0
_080B7CFC: .4byte 0x00001412
_080B7D00:
	ldrb r0, [r5]
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bne _080B7D1C
	ldr r1, _080B7D18 @ =0x0000142C
	adds r0, r4, r1
	b _080B7D24
	.align 2, 0
_080B7D18: .4byte 0x0000142C
_080B7D1C:
	cmp r6, r0
	bne _080B7D34
	ldr r2, _080B7D30 @ =0x00001429
	adds r0, r4, r2
_080B7D24:
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #3
	bls _080B7D36
_080B7D2C:
	movs r1, #0
	b _080B7D36
	.align 2, 0
_080B7D30: .4byte 0x00001429
_080B7D34:
	movs r1, #1
_080B7D36:
	cmp r1, #1
	bne _080B7D50
	ldr r3, _080B7D4C @ =0x0000130C
	adds r0, r4, r3
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080B7D5E
	.align 2, 0
_080B7D4C: .4byte 0x0000130C
_080B7D50:
	ldr r5, _080B7D64 @ =0x0000130C
	adds r0, r4, r5
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080B7D5E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B7D64: .4byte 0x0000130C

	thumb_func_start FUN_080b7d68
FUN_080b7d68: @ 0x080B7D68
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080B7DC4 @ =0x0000142E
	adds r0, r4, r1
	ldrb r3, [r0]
	ldr r2, _080B7DC8 @ =0x00001458
	adds r1, r4, r2
	adds r0, r1, r3
	ldrb r6, [r0]
	ldr r0, _080B7DCC @ =0x030046A0
	ldr r2, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	bge _080B7DD8
	ldr r3, _080B7DD0 @ =0x0000142B
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, r1, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r2
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _080B7E7C
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bne _080B7E84
_080B7DB8:
	ldr r1, _080B7DD4 @ =0x0000142C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080B7E7C
	b _080B7E84
	.align 2, 0
_080B7DC4: .4byte 0x0000142E
_080B7DC8: .4byte 0x00001458
_080B7DCC: .4byte 0x030046A0
_080B7DD0: .4byte 0x0000142B
_080B7DD4: .4byte 0x0000142C
_080B7DD8:
	ldr r0, _080B7E24 @ =0x0000142B
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, r3
	bne _080B7E54
	ldr r1, _080B7E28 @ =0x00001428
	adds r0, r4, r1
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B7E7C
	ldrb r0, [r5]
	cmp r0, #0xf
	bhi _080B7E34
	ldr r3, _080B7E2C @ =0x00001413
	adds r2, r4, r3
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B7E7C
	movs r0, #3
	ands r0, r1
_080B7E08:
	ldr r3, _080B7E30 @ =0x00001429
	adds r1, r4, r3
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	subs r0, #0x10
	asrs r0, r0, #2
	adds r3, #1
	adds r1, r4, r3
	strb r0, [r1]
	ldrb r0, [r2]
	strb r0, [r5]
	b _080B7E84
	.align 2, 0
_080B7E24: .4byte 0x0000142B
_080B7E28: .4byte 0x00001428
_080B7E2C: .4byte 0x00001413
_080B7E30: .4byte 0x00001429
_080B7E34:
	ldr r0, _080B7E50 @ =0x00001412
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080B7E7C
	adds r0, r1, #0
	subs r0, #0x10
	movs r1, #3
	ands r0, r1
	adds r0, #4
	b _080B7E08
	.align 2, 0
_080B7E50: .4byte 0x00001412
_080B7E54:
	cmp r0, #0x20
	bne _080B7E5C
	movs r0, #2
	b _080B7E86
_080B7E5C:
	ldrb r0, [r5]
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	beq _080B7DB8
	cmp r6, r0
	bne _080B7E84
	ldr r2, _080B7E80 @ =0x00001429
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #3
	bls _080B7E84
_080B7E7C:
	movs r0, #0
	b _080B7E86
	.align 2, 0
_080B7E80: .4byte 0x00001429
_080B7E84:
	movs r0, #1
_080B7E86:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b7e8c
FUN_080b7e8c: @ 0x080B7E8C
	push {r4, r5, r6, lr}
	ldr r2, _080B7ED4 @ =0x0000142B
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _080B7ED8 @ =0x00001458
	adds r2, r0, r3
	adds r1, r2, r1
	ldrb r6, [r1]
	ldr r1, _080B7EDC @ =0x0000142E
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r2, r2, r0
	ldrb r5, [r2]
	ldr r0, _080B7EE0 @ =0x030046A0
	ldr r3, [r0]
	lsls r2, r6, #1
	adds r2, r2, r3
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r2, r2, r1
	movs r0, #0
	ldrsh r4, [r2, r0]
	lsls r0, r5, #1
	adds r0, r0, r3
	adds r0, r0, r1
	ldrh r1, [r0]
	strh r1, [r2]
	strh r4, [r0]
	adds r3, #0x5c
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, r6
	bne _080B7EE4
	strh r5, [r3]
	b _080B7EEA
	.align 2, 0
_080B7ED4: .4byte 0x0000142B
_080B7ED8: .4byte 0x00001458
_080B7EDC: .4byte 0x0000142E
_080B7EE0: .4byte 0x030046A0
_080B7EE4:
	cmp r0, r5
	bne _080B7EEA
	strh r6, [r3]
_080B7EEA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b7ef0
FUN_080b7ef0: @ 0x080B7EF0
	ldr r2, _080B7F18 @ =0x0000142E
	adds r1, r0, r2
	adds r2, #0x2a
	adds r0, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _080B7F1C @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080B7F18: .4byte 0x0000142E
_080B7F1C: .4byte 0x030046A0

	thumb_func_start FUN_080b7f20
FUN_080b7f20: @ 0x080B7F20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	adds r6, r0, #0
	movs r4, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x48]
	add r1, sp, #0x34
	mov sl, r1
	add r2, sp, #0x3c
	mov sb, r2
	subs r0, #0x10
	str r0, [sp, #0x44]
	mov r1, sb
	str r1, [sp, #0x4c]
	mov r2, sl
	str r2, [sp, #0x50]
	ldr r0, [sp, #0x48]
	mov r8, r0
_080B7F4E:
	cmp r4, #0
	bne _080B7F5C
	ldr r1, _080B7F58 @ =0x0000142E
	adds r0, r6, r1
	b _080B7F60
	.align 2, 0
_080B7F58: .4byte 0x0000142E
_080B7F5C:
	ldr r2, _080B7FB8 @ =0x0000142B
	adds r0, r6, r2
_080B7F60:
	ldrb r3, [r0]
	adds r1, r3, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r6, #0
	adds r1, #0x80
	adds r1, r1, r0
	ldr r0, [r1]
	movs r5, #1
	orrs r0, r5
	str r0, [r1]
	ldr r7, _080B7FBC @ =0x030046A0
	ldr r0, [r7]
	adds r0, #0x5c
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _080B7FC0 @ =0x00001458
	adds r0, r6, r2
	adds r2, r0, r3
	ldrb r0, [r2]
	cmp r1, r0
	bne _080B7F9A
	movs r0, #0xf8
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_080B7F9A:
	ldrb r0, [r2]
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	blt _080B7FC4
	mov r0, r8
	str r5, [r0]
	b _080B7FCA
	.align 2, 0
_080B7FB8: .4byte 0x0000142B
_080B7FBC: .4byte 0x030046A0
_080B7FC0: .4byte 0x00001458
_080B7FC4:
	movs r0, #0
	mov r2, r8
	str r0, [r2]
_080B7FCA:
	adds r0, r1, #0
	adds r0, #0x43
	ldr r1, [sp, #0x50]
	stm r1!, {r0}
	str r1, [sp, #0x50]
	ldr r0, _080B8038 @ =0x000002DF
	ldr r2, [sp, #0x4c]
	stm r2!, {r0}
	str r2, [sp, #0x4c]
	lsls r0, r4, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r3, #0
	bl FUN_080b9938
	movs r0, #4
	add r8, r0
	adds r4, #1
	cmp r4, #1
	ble _080B7F4E
	add r2, sp, #0x14
	ldr r3, [sp, #0x44]
	movs r4, #1
_080B7FF8:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r4, #1
	cmp r4, #0
	bge _080B7FF8
	ldr r1, _080B803C @ =0x00001218
	adds r0, r6, r1
	mov r2, sl
	str r2, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x48]
	add r2, sp, #0xc
	ldr r3, [sp, #0x44]
	bl FUN_080b9a28
	ldr r0, _080B8040 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8038: .4byte 0x000002DF
_080B803C: .4byte 0x00001218
_080B8040: .4byte 0x0000038A

	thumb_func_start FUN_080b8044
FUN_080b8044: @ 0x080B8044
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r4, #1
	str r4, [sp, #0x2c]
	ldr r0, _080B80EC @ =0x0000142E
	adds r3, r5, r0
	ldrb r0, [r3]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	ldr r1, _080B80F0 @ =0x00001458
	adds r0, r5, r1
	ldrb r1, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _080B80F4 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0x43
	str r0, [sp, #0x34]
	ldr r0, _080B80F8 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r3]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x43
	add r6, sp, #0x34
	str r0, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r0, _080B80FC @ =0x00001218
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080B8100 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B80EC: .4byte 0x0000142E
_080B80F0: .4byte 0x00001458
_080B80F4: .4byte 0x030046A0
_080B80F8: .4byte 0x000002DF
_080B80FC: .4byte 0x00001218
_080B8100: .4byte 0x0000038A

	thumb_func_start FUN_080b8104
FUN_080b8104: @ 0x080B8104
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x88
	lsls r0, r0, #5
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080b79d8
	ldr r0, _080B8164 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080B8168 @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080b7900
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b7c18
	ldr r1, _080B816C @ =FUN_080b8170
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080b5ad4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B8164: .4byte 0x00001428
_080B8168: .4byte 0x000010F8
_080B816C: .4byte FUN_080b8170

	thumb_func_start FUN_080b8170
FUN_080b8170: @ 0x080B8170
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B81A4 @ =0x00001428
	adds r4, r5, r0
	ldr r2, _080B81A8 @ =0x00000D98
	adds r1, r5, r2
	ldr r3, _080B81AC @ =0x00000E58
	adds r2, r5, r3
	ldr r0, _080B81B0 @ =0x00000EB8
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B81B4
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080B81C2
	.align 2, 0
_080B81A4: .4byte 0x00001428
_080B81A8: .4byte 0x00000D98
_080B81AC: .4byte 0x00000E58
_080B81B0: .4byte 0x00000EB8
_080B81B4:
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080B81C2:
	str r1, [r0]
	ldr r4, _080B8224 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080B8234
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b5ac8
	ldr r3, _080B8228 @ =0x000010F8
	adds r0, r5, r3
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B822C @ =0x0000130C
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B8202
	b _080B83F8
_080B8202:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080B8230 @ =0x00001478
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080B821C
	b _080B83F8
_080B821C:
	movs r0, #0
	strb r0, [r1]
	b _080B83F8
	.align 2, 0
_080B8224: .4byte 0x030044E0
_080B8228: .4byte 0x000010F8
_080B822C: .4byte 0x0000130C
_080B8230: .4byte 0x00001478
_080B8234:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b5ac8
	ldr r3, _080B82A4 @ =0x000010F8
	adds r6, r5, r3
	adds r7, r5, #0
	adds r7, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082372cc
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B8258
	b _080B83D4
_080B8258:
	ldr r1, _080B82A8 @ =0x0000142B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _080B82C4
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _080B82AC @ =0x00001428
	adds r0, r5, r2
	bl FUN_080b9fd8
	ldr r3, _080B82B0 @ =0x000013F4
	adds r0, r5, r3
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B82B4 @ =0x000011B8
	adds r0, r5, r1
	ldr r3, _080B82B8 @ =0x0000140D
	adds r2, r5, r3
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B82BC @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B82C0 @ =FUN_080b86bc
	b _080B83C4
	.align 2, 0
_080B82A4: .4byte 0x000010F8
_080B82A8: .4byte 0x0000142B
_080B82AC: .4byte 0x00001428
_080B82B0: .4byte 0x000013F4
_080B82B4: .4byte 0x000011B8
_080B82B8: .4byte 0x0000140D
_080B82BC: .4byte 0x0000130C
_080B82C0: .4byte FUN_080b86bc
_080B82C4:
	cmp r0, #0x22
	bne _080B8324
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _080B830C @ =0x00001428
	adds r0, r5, r2
	bl FUN_080b9fd8
	ldr r3, _080B8310 @ =0x000013F4
	adds r0, r5, r3
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #4
	adds r3, r4, #0
	bl FUN_080b5b50
	ldr r1, _080B8314 @ =0x000011B8
	adds r0, r5, r1
	ldr r3, _080B8318 @ =0x0000140D
	adds r2, r5, r3
	adds r1, r7, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080B831C @ =0x0000130C
	adds r0, r5, r1
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080B8320 @ =0x080B8729
	b _080B83C4
	.align 2, 0
_080B830C: .4byte 0x00001428
_080B8310: .4byte 0x000013F4
_080B8314: .4byte 0x000011B8
_080B8318: .4byte 0x0000140D
_080B831C: .4byte 0x0000130C
_080B8320: .4byte 0x080B8729
_080B8324:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _080B8390 @ =0x00001428
	adds r4, r5, r2
	adds r0, r4, #0
	bl FUN_080b9fd8
	movs r3, #0x8b
	lsls r3, r3, #5
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080B8394 @ =0x00001178
	adds r2, r5, r0
	ldr r1, _080B8398 @ =0x00001118
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080B839C @ =0x0000142E
	adds r1, r5, r2
	ldr r3, _080B83A0 @ =0x00001458
	adds r0, r5, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r0, _080B83A4 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _080B83B2
	adds r0, r1, #0
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bne _080B83A8
	adds r0, r4, #0
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080B83BA
	.align 2, 0
_080B8390: .4byte 0x00001428
_080B8394: .4byte 0x00001178
_080B8398: .4byte 0x00001118
_080B839C: .4byte 0x0000142E
_080B83A0: .4byte 0x00001458
_080B83A4: .4byte 0x030046A0
_080B83A8:
	adds r0, r4, #0
	movs r1, #0x18
	bl FUN_080b9d94
	b _080B83BA
_080B83B2:
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_080b9d94
_080B83BA:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b7c18
	ldr r1, _080B83D0 @ =FUN_080b8404
_080B83C4:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B83F8
	.align 2, 0
_080B83D0: .4byte FUN_080b8404
_080B83D4:
	ldr r2, _080B8400 @ =0x00001428
	adds r4, r5, r2
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B83F8
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b7900
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080b7c18
_080B83F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8400: .4byte 0x00001428

	thumb_func_start FUN_080b8404
FUN_080b8404: @ 0x080B8404
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080B843C @ =0x00001428
	adds r4, r5, r0
	ldr r0, _080B8440 @ =0x00000D98
	adds r1, r5, r0
	adds r0, #0xc0
	adds r2, r5, r0
	adds r0, #0x60
	adds r3, r5, r0
	adds r0, r4, #0
	bl FUN_080b95d0
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B8444
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080B8488
	.align 2, 0
_080B843C: .4byte 0x00001428
_080B8440: .4byte 0x00000D98
_080B8444:
	ldr r1, _080B8460 @ =0x0000140E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _080B8464
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080B8470
	.align 2, 0
_080B8460: .4byte 0x0000140E
_080B8464:
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080B8470:
	str r1, [r0]
	ldr r0, _080B84F4 @ =0x0000140E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080B8488
	movs r0, #0
	strh r0, [r1]
_080B8488:
	ldr r1, _080B84F8 @ =0x000010F8
	adds r6, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r0, _080B84FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #4
	ands r0, r1
	adds r7, r4, #0
	cmp r0, #0
	beq _080B8510
	ldr r1, _080B8500 @ =0x00001428
	adds r0, r5, r1
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	bne _080B8510
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B8504 @ =0x00001118
	adds r0, r5, r1
	movs r1, #0x20
	bl FUN_080b9938
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080B8508 @ =0x0000130C
	adds r0, r5, r1
	movs r4, #1
	rsbs r4, r4, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r0, _080B850C @ =0x00000107
	bl PlaySound_082406e0
	b _080B8560
	.align 2, 0
_080B84F4: .4byte 0x0000140E
_080B84F8: .4byte 0x000010F8
_080B84FC: .4byte 0x030044E0
_080B8500: .4byte 0x00001428
_080B8504: .4byte 0x00001118
_080B8508: .4byte 0x0000130C
_080B850C: .4byte 0x00000107
_080B8510:
	ldr r0, _080B8548 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B85A0
	adds r0, r5, #0
	bl FUN_080b7d68
	adds r4, r0, #0
	ldr r1, _080B854C @ =0x0000130C
	adds r0, r5, r1
	movs r6, #1
	rsbs r6, r6, #0
	adds r1, r6, #0
	adds r2, r6, #0
	bl FUN_080b98c0
	cmp r4, #1
	beq _080B8550
	cmp r4, #2
	beq _080B8560
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080B85DC
	.align 2, 0
_080B8548: .4byte 0x030044E0
_080B854C: .4byte 0x0000130C
_080B8550:
	adds r0, r5, #0
	bl FUN_080b7f20
	ldr r1, _080B855C @ =0x080B879D
	b _080B8584
	.align 2, 0
_080B855C: .4byte 0x080B879D
_080B8560:
	ldr r1, _080B8590 @ =0x000013F4
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r3, #1
	rsbs r3, r3, #0
	bl FUN_080b5b50
	ldr r1, _080B8594 @ =0x000011B8
	adds r0, r5, r1
	ldr r1, _080B8598 @ =0x0000140D
	adds r2, r5, r1
	adds r1, r7, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B859C @ =FUN_080b87c4
_080B8584:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B85DC
	.align 2, 0
_080B8590: .4byte 0x000013F4
_080B8594: .4byte 0x000011B8
_080B8598: .4byte 0x0000140D
_080B859C: .4byte FUN_080b87c4
_080B85A0:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B85B6
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b8104
	b _080B85DC
_080B85B6:
	ldr r0, _080B85E4 @ =0x00001428
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080B85DC
	ldr r0, _080B85E8 @ =0x000010F8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080b7900
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080b7c18
_080B85DC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B85E4: .4byte 0x00001428
_080B85E8: .4byte 0x000010F8

	thumb_func_start FUN_080b85ec
FUN_080b85ec: @ 0x080B85EC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B8640 @ =0x000010F8
	adds r5, r4, r0
	adds r6, r4, #0
	adds r6, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_082372cc
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B8644 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B8650
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080B8648 @ =0x00001428
	adds r0, r4, r1
	adds r1, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b7900
	ldr r1, _080B864C @ =FUN_080b8404
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B86A2
	.align 2, 0
_080B8640: .4byte 0x000010F8
_080B8644: .4byte 0x030044E0
_080B8648: .4byte 0x00001428
_080B864C: .4byte FUN_080b8404
_080B8650:
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080B86A2
	movs r0, #0x88
	lsls r0, r0, #5
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080B86A8 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080B86AC @ =0x000013F4
	adds r0, r4, r1
	ldr r2, [r0]
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080b5b50
	ldr r1, _080B86B0 @ =0x000011B8
	adds r0, r4, r1
	ldr r1, _080B86B4 @ =0x0000140D
	adds r2, r4, r1
	adds r1, r6, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080B86B8 @ =FUN_080b87c4
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
_080B86A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B86A8: .4byte 0x00000107
_080B86AC: .4byte 0x000013F4
_080B86B0: .4byte 0x000011B8
_080B86B4: .4byte 0x0000140D
_080B86B8: .4byte FUN_080b87c4

	thumb_func_start FUN_080b86bc
FUN_080b86bc: @ 0x080B86BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B86FC @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B8700 @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080B8710
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortArmors
	ldr r1, _080B8704 @ =0x0000142C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080B8708 @ =0x0000142D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080B870C @ =0x0000142E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b8104
	b _080B8720
	.align 2, 0
_080B86FC: .4byte 0x000011B8
_080B8700: .4byte 0x0000140D
_080B8704: .4byte 0x0000142C
_080B8708: .4byte 0x0000142D
_080B870C: .4byte 0x0000142E
_080B8710:
	cmp r0, #0
	bne _080B8720
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b8104
_080B8720:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8728:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x10, 0x49, 0x60, 0x18
	.byte 0x21, 0x1C, 0x18, 0x31, 0x0F, 0x4B, 0xE2, 0x18, 0x01, 0xF0, 0x20, 0xF8, 0x01, 0x28, 0x21, 0xD1
	.byte 0xDD, 0x20, 0x87, 0xF1, 0xCD, 0xFF, 0x0C, 0x49, 0x60, 0x18, 0x00, 0x78, 0x8A, 0xF1, 0xBC, 0xFD
	.byte 0x0A, 0x4B, 0xE1, 0x18, 0x00, 0x22, 0x04, 0x20, 0x08, 0x70, 0x09, 0x49, 0x60, 0x18, 0x02, 0x70
	.byte 0x02, 0x33, 0xE1, 0x18, 0x10, 0x20, 0x08, 0x70, 0x20, 0x1C, 0xFF, 0xF7, 0xCB, 0xFC, 0x11, 0xE0
	.byte 0xB8, 0x11, 0x00, 0x00, 0x0D, 0x14, 0x00, 0x00, 0x68, 0x14, 0x00, 0x00, 0x2C, 0x14, 0x00, 0x00
	.byte 0x2D, 0x14, 0x00, 0x00, 0x00, 0x28, 0x05, 0xD1, 0xDE, 0x20, 0x87, 0xF1, 0xA9, 0xFF, 0x20, 0x1C
	.byte 0xFF, 0xF7, 0xB8, 0xFC, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x10, 0xB5, 0x04, 0x1C
	.byte 0x07, 0x49, 0x60, 0x18, 0x01, 0xF0, 0x9A, 0xF9, 0x00, 0x28, 0x05, 0xD0, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x6D, 0xFB, 0x20, 0x1C, 0xFF, 0xF7, 0xA6, 0xFC, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x18, 0x12, 0x00, 0x00

	thumb_func_start FUN_080b87c4
FUN_080b87c4: @ 0x080B87C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B8800 @ =0x000011B8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080B8804 @ =0x0000140D
	adds r2, r4, r3
	bl FUN_080b977c
	adds r2, r0, #0
	cmp r2, #1
	bne _080B880C
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r4, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080b8044
	ldr r1, _080B8808 @ =0x080B8825
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080b5ad4
	b _080B881C
	.align 2, 0
_080B8800: .4byte 0x000011B8
_080B8804: .4byte 0x0000140D
_080B8808: .4byte 0x080B8825
_080B880C:
	cmp r2, #0
	bne _080B881C
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b8104
_080B881C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8824:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x0A, 0x49, 0x60, 0x18, 0x01, 0xF0, 0x56, 0xF9
	.byte 0x00, 0x28, 0x0B, 0xD0, 0x20, 0x1C, 0xFF, 0xF7, 0x5B, 0xFB, 0x87, 0x20, 0x40, 0x00, 0x87, 0xF1
	.byte 0x4F, 0xFF, 0x05, 0x49, 0x20, 0x1C, 0x00, 0x22, 0xFD, 0xF7, 0x44, 0xF9, 0x10, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0x18, 0x12, 0x00, 0x00, 0x5D, 0x88, 0x0B, 0x08

	thumb_func_start FUN_080b885c
FUN_080b885c: @ 0x080B885C
	push {lr}
	adds r3, r0, #0
	ldr r0, _080B8884 @ =0x0000140E
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080B88A4
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B888C
	ldr r2, _080B8888 @ =0x00000DBA
	adds r1, r3, r2
	b _080B88AC
	.align 2, 0
_080B8884: .4byte 0x0000140E
_080B8888: .4byte 0x00000DBA
_080B888C:
	ldrh r1, [r2]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x40
	subs r1, r1, r0
	ldr r2, _080B88A0 @ =0x00000DBA
	adds r0, r3, r2
	strh r1, [r0]
	b _080B88BE
	.align 2, 0
_080B88A0: .4byte 0x00000DBA
_080B88A4:
	cmp r1, #0xf
	bhi _080B88B8
	ldr r0, _080B88B4 @ =0x00000DBA
	adds r1, r3, r0
_080B88AC:
	movs r0, #0x40
	strh r0, [r1]
	b _080B88BE
	.align 2, 0
_080B88B4: .4byte 0x00000DBA
_080B88B8:
	adds r0, r3, #0
	bl FUN_080b8104
_080B88BE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b88c4
FUN_080b88c4: @ 0x080B88C4
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_080b5afc
	adds r0, r4, #0
	bl FUN_080b79d8
	ldr r0, _080B8914 @ =0x00001428
	adds r5, r4, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080b9ff8
	ldr r0, _080B8918 @ =0x000010F8
	adds r1, r4, r0
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080b7900
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b7c18
	ldr r1, _080B891C @ =FUN_080b8170
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080b5ad4
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B8914: .4byte 0x00001428
_080B8918: .4byte 0x000010F8
_080B891C: .4byte FUN_080b8170

	thumb_func_start FUN_080b8920
FUN_080b8920: @ 0x080B8920
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _080B8978 @ =0x00001410
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _080B8938
	b _080B8ABE
_080B8938:
	bl Script_GetValue
	ldr r2, _080B897C @ =0x00001411
	adds r6, r4, r2
	strb r0, [r6]
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _080B894E
	b _080B8ABE
_080B894E:
	movs r5, #0
	ldrb r6, [r6]
	cmp r5, r6
	bge _080B896E
	ldr r0, _080B8980 @ =0x00001414
	adds r7, r4, r0
	ldr r1, _080B897C @ =0x00001411
	adds r6, r4, r1
_080B895E:
	bl Script_GetValue
	adds r1, r7, r5
	strb r0, [r1]
	adds r5, #1
	ldrb r2, [r6]
	cmp r5, r2
	blt _080B895E
_080B896E:
	movs r5, #0
	ldr r1, _080B897C @ =0x00001411
	adds r0, r4, r1
	b _080B8A84
	.align 2, 0
_080B8978: .4byte 0x00001410
_080B897C: .4byte 0x00001411
_080B8980: .4byte 0x00001414
_080B8984:
	ldr r2, _080B899C @ =0x00001414
	adds r0, r4, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #4
	bls _080B8992
	b _080B8ABE
_080B8992:
	lsls r0, r0, #2
	ldr r1, _080B89A0 @ =_080B89A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B899C: .4byte 0x00001414
_080B89A0: .4byte _080B89A4
_080B89A4: @ jump table
	.4byte _080B89B8 @ case 0
	.4byte _080B89E4 @ case 1
	.4byte _080B8A0C @ case 2
	.4byte _080B8A38 @ case 3
	.4byte _080B8A60 @ case 4
_080B89B8:
	ldr r1, _080B89D8 @ =0x00001419
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x50
	strb r1, [r0]
	ldr r2, _080B89DC @ =0x0000141E
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #3
	strb r1, [r0]
	ldr r1, _080B89E0 @ =0x00001423
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x2c
	b _080B8A7C
	.align 2, 0
_080B89D8: .4byte 0x00001419
_080B89DC: .4byte 0x0000141E
_080B89E0: .4byte 0x00001423
_080B89E4:
	ldr r2, _080B8A04 @ =0x00001419
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x50
	strb r1, [r0]
	ldr r1, _080B8A08 @ =0x0000141E
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #3
	strb r1, [r0]
	adds r2, #0xa
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x2d
	b _080B8A7C
	.align 2, 0
_080B8A04: .4byte 0x00001419
_080B8A08: .4byte 0x0000141E
_080B8A0C:
	ldr r1, _080B8A2C @ =0x00001419
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x5a
	strb r1, [r0]
	ldr r2, _080B8A30 @ =0x0000141E
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #5
	strb r1, [r0]
	ldr r1, _080B8A34 @ =0x00001423
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x2c
	b _080B8A7C
	.align 2, 0
_080B8A2C: .4byte 0x00001419
_080B8A30: .4byte 0x0000141E
_080B8A34: .4byte 0x00001423
_080B8A38:
	ldr r2, _080B8A58 @ =0x00001419
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x5a
	strb r1, [r0]
	ldr r1, _080B8A5C @ =0x0000141E
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #5
	strb r1, [r0]
	adds r2, #0xa
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #0x2d
	b _080B8A7C
	.align 2, 0
_080B8A58: .4byte 0x00001419
_080B8A5C: .4byte 0x0000141E
_080B8A60:
	ldr r1, _080B8AA4 @ =0x00001419
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x53
	strb r1, [r0]
	ldr r2, _080B8AA8 @ =0x0000141E
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #7
	strb r1, [r0]
	ldr r1, _080B8AAC @ =0x00001423
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0x10
_080B8A7C:
	strb r1, [r0]
	adds r5, #1
	ldr r2, _080B8AB0 @ =0x00001411
	adds r0, r4, r2
_080B8A84:
	ldrb r0, [r0]
	cmp r5, r0
	bge _080B8A8C
	b _080B8984
_080B8A8C:
	movs r0, #0x65
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080B8AB8
	bl Script_GetValue
	ldr r2, _080B8AB4 @ =0x00001490
	adds r1, r4, r2
	str r0, [r1]
	b _080B8ABE
	.align 2, 0
_080B8AA4: .4byte 0x00001419
_080B8AA8: .4byte 0x0000141E
_080B8AAC: .4byte 0x00001423
_080B8AB0: .4byte 0x00001411
_080B8AB4: .4byte 0x00001490
_080B8AB8:
	ldr r2, _080B8AC4 @ =0x00001490
	adds r0, r4, r2
	str r1, [r0]
_080B8ABE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8AC4: .4byte 0x00001490

	thumb_func_start FUN_080b8ac8
FUN_080b8ac8: @ 0x080B8AC8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080B8B18 @ =0x0000C091
	ldr r1, _080B8B1C @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080B8B20 @ =0x000013EC
	adds r4, r4, r0
	str r2, [r4]
	movs r5, #0
	str r5, [sp, #0xc]
	str r5, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, [r4]
	movs r0, #0
	movs r2, #5
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B8B18: .4byte 0x0000C091
_080B8B1C: .4byte 0x00009F57
_080B8B20: .4byte 0x000013EC

	thumb_func_start FUN_080b8b24
FUN_080b8b24: @ 0x080B8B24
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B8B4C @ =0x000092B3
	ldr r1, _080B8B50 @ =0x0000A41A
	bl GetFile
	ldr r1, _080B8B54 @ =0x000013F0
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080B8B58 @ =0x030043F0
	ldr r2, _080B8B5C @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8B4C: .4byte 0x000092B3
_080B8B50: .4byte 0x0000A41A
_080B8B54: .4byte 0x000013F0
_080B8B58: .4byte 0x030043F0
_080B8B5C: .4byte 0x04000018

	thumb_func_start FUN_080b8b60
FUN_080b8b60: @ 0x080B8B60
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	ldr r4, _080B8E40 @ =0x0000CB05
	ldr r1, _080B8E44 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, sb
	adds r1, #0x38
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	movs r6, #0x38
	add r6, sb
	mov r8, r6
	mov r0, r8
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080B8E48 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, sb
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	mov r0, sb
	adds r0, #0x18
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080B8E4C @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, sb
	adds r1, #0x58
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r4, r5}
	stm r1!, {r4, r5}
	mov r6, sb
	adds r6, #0x58
	adds r0, r6, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080B8E50 @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	mov r0, sb
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x28
	movs r3, #0x30
	bl FUN_0822f3fc
	mov r0, sb
	adds r0, #0xd8
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x23
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r6, #0
	add r5, sp, #0x10
	mov sl, r6
	mov r4, r8
	str r4, [sp, #0x18]
	movs r0, #0xf3
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
	movs r7, #0xcc
	lsls r7, r7, #1
	add r7, sb
	str r4, [sp, #0x1c]
_080B8C56:
	asrs r1, r6, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r5, #2]
	movs r0, #3
	ands r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #3
	adds r0, r4, #0
	adds r0, #0x90
	strh r0, [r5]
	mov r1, sl
	str r1, [sp]
	str r1, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r4, #8
	strh r4, [r5]
	mov r3, sl
	str r3, [sp]
	str r3, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	mov r0, r8
	ldr r1, [sp, #0x18]
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r0, #0x60
	add r8, r0
	adds r7, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _080B8C56
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	add r1, sp, #0x10
	mov r8, r1
	movs r0, #0x80
	strh r0, [r1, #2]
	ldr r0, _080B8E54 @ =0x00000F18
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0xcf
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0x70
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x40
	mov r3, r8
	strh r0, [r3, #2]
	ldr r5, _080B8E58 @ =0x00000D98
	add r5, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0xca
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	add r0, sp, #0x10
	strh r4, [r0]
	mov r1, r8
	strh r4, [r1, #2]
	ldr r0, _080B8E5C @ =0x00000DF8
	add r0, sb
	mov r1, sb
	adds r1, #0x58
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0x2a
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r1, #0x78
	add r0, sp, #0x10
	strh r1, [r0]
	movs r5, #0x68
	mov r3, r8
	strh r5, [r3, #2]
	ldr r0, _080B8E60 @ =0x00000E58
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0xcb
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r5, [r0]
	movs r0, #0x20
	mov r2, r8
	strh r0, [r2, #2]
	ldr r0, _080B8E64 @ =0x00000EB8
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0xcb
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	mov r5, r8
	strh r4, [r5, #2]
	movs r6, #0x18
	add r6, sb
	mov sl, r6
	adds r5, r0, #0
	mov r8, r4
	ldr r4, _080B8E68 @ =0x00000F78
	add r4, sb
	movs r7, #0x20
	movs r6, #3
_080B8D8E:
	strh r7, [r5, #2]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0x41
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r4, #0x60
	adds r7, #0x18
	subs r6, #1
	cmp r6, #0
	bge _080B8D8E
	movs r4, #0
	ldr r0, _080B8E6C @ =0x00001158
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	mov r1, sl
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x20
	strh r0, [r6, #2]
	ldr r5, _080B8E70 @ =0x000010F8
	add r5, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x39
	movs r3, #0x30
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r6, #2]
	ldr r0, _080B8E74 @ =0x000011B8
	add r0, sb
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sl
	movs r2, #0x94
	movs r3, #0x11
	bl FUN_0822f3fc
	ldr r0, _080B8E78 @ =0x00001218
	add r0, sb
	bl FUN_080b99a0
	ldr r0, _080B8E7C @ =0x0000130C
	add r0, sb
	bl FUN_080b9814
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8E40: .4byte 0x0000CB05
_080B8E44: .4byte 0x00005D04
_080B8E48: .4byte 0x0000B343
_080B8E4C: .4byte 0x0000414C
_080B8E50: .4byte 0xFFFF0000
_080B8E54: .4byte 0x00000F18
_080B8E58: .4byte 0x00000D98
_080B8E5C: .4byte 0x00000DF8
_080B8E60: .4byte 0x00000E58
_080B8E64: .4byte 0x00000EB8
_080B8E68: .4byte 0x00000F78
_080B8E6C: .4byte 0x00001158
_080B8E70: .4byte 0x000010F8
_080B8E74: .4byte 0x000011B8
_080B8E78: .4byte 0x00001218
_080B8E7C: .4byte 0x0000130C

	thumb_func_start FUN_080b8e80
FUN_080b8e80: @ 0x080B8E80
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080B8E98
	bl FUN_0823d340
	ldr r2, _080B8EF8 @ =0x000013F4
	adds r1, r4, r2
	str r0, [r1]
_080B8E98:
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080B8EAC
	bl FUN_0823d340
	ldr r2, _080B8EFC @ =0x000013F8
	adds r1, r4, r2
	str r0, [r1]
_080B8EAC:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080B8EC0
	bl FUN_0823d340
	ldr r2, _080B8F00 @ =0x000013FC
	adds r1, r4, r2
	str r0, [r1]
_080B8EC0:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080B8ED6
	bl FUN_0823d340
	movs r2, #0xa0
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
_080B8ED6:
	bl FUN_08049f5c
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _080B8F04 @ =0x0000A41A
	bl FUN_08047dc0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8EF8: .4byte 0x000013F4
_080B8EFC: .4byte 0x000013F8
_080B8F00: .4byte 0x000013FC
_080B8F04: .4byte 0x0000A41A

	thumb_func_start FUN_080b8f08
FUN_080b8f08: @ 0x080B8F08
	push {lr}
	adds r2, r0, #0
	ldr r0, _080B8F2C @ =0x0000140E
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080B8F26
	ldr r1, _080B8F30 @ =FUN_080b90dc
	adds r0, r2, #0
	bl FUN_080b5ab0
_080B8F26:
	pop {r0}
	bx r0
	.align 2, 0
_080B8F2C: .4byte 0x0000140E
_080B8F30: .4byte FUN_080b90dc

	thumb_func_start FUN_080b8f34
FUN_080b8f34: @ 0x080B8F34
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _080B8F64 @ =0x030044E0
	ldrh r2, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _080B8F70
	ldr r0, _080B8F68 @ =0x00001410
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _080B8F5A
	ldr r3, _080B8F6C @ =0x00001411
	adds r0, r1, r3
	ldrb r0, [r0]
_080B8F5A:
	subs r0, #1
	strb r0, [r2]
_080B8F5E:
	movs r0, #1
	b _080B8F9E
	.align 2, 0
_080B8F64: .4byte 0x030044E0
_080B8F68: .4byte 0x00001410
_080B8F6C: .4byte 0x00001411
_080B8F70:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080B8F9C
	ldr r4, _080B8F98 @ =0x00001410
	adds r2, r1, r4
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r4, #1
	adds r1, r1, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _080B8F5E
	strb r3, [r2]
	b _080B8F5E
	.align 2, 0
_080B8F98: .4byte 0x00001410
_080B8F9C:
	movs r0, #0
_080B8F9E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b8fa4
FUN_080b8fa4: @ 0x080B8FA4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #3
	bl FUN_080b5b30
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _080B901C @ =0x00001410
	adds r2, r4, r0
	ldrb r0, [r2]
	ldr r6, _080B9020 @ =0x0000141E
	adds r5, r4, r6
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r3, r0
	bge _080B8FEC
	ldr r0, _080B9024 @ =0x00001419
	adds r6, r4, r0
	ldr r0, _080B9028 @ =0xFFFFF000
	adds r7, r0, #0
	adds r4, r5, #0
_080B8FD2:
	ldrb r0, [r2]
	adds r0, r6, r0
	ldrb r0, [r0]
	adds r0, r0, r3
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	ldrb r0, [r2]
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r3, r0
	blt _080B8FD2
_080B8FEC:
	movs r2, #0
	ldr r6, _080B9028 @ =0xFFFFF000
	adds r4, r6, #0
_080B8FF2:
	adds r0, r2, #0
	adds r0, #0x60
	orrs r0, r4
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	adds r2, #1
	cmp r2, #2
	ble _080B8FF2
	cmp r3, #9
	bgt _080B9016
	ldr r2, _080B902C @ =0x0000F010
	adds r0, r2, #0
_080B900C:
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	cmp r3, #9
	ble _080B900C
_080B9016:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B901C: .4byte 0x00001410
_080B9020: .4byte 0x0000141E
_080B9024: .4byte 0x00001419
_080B9028: .4byte 0xFFFFF000
_080B902C: .4byte 0x0000F010

	thumb_func_start FUN_080b9030
FUN_080b9030: @ 0x080B9030
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0
	movs r1, #1
	movs r2, #3
	bl FUN_080b5b30
	adds r2, r0, #0
	movs r3, #0
	ldr r0, _080B90C4 @ =0x00001410
	adds r1, r5, r0
	ldrb r0, [r1]
	ldr r6, _080B90C8 @ =0x0000141E
	adds r4, r5, r6
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r3, r0
	bge _080B9076
	ldr r0, _080B90CC @ =0x00001419
	adds r6, r5, r0
	ldr r0, _080B90D0 @ =0xFFFFF000
	adds r7, r0, #0
_080B905C:
	ldrb r0, [r1]
	adds r0, r6, r0
	ldrb r0, [r0]
	adds r0, r0, r3
	orrs r0, r7
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	ldrb r0, [r1]
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r3, r0
	blt _080B905C
_080B9076:
	movs r1, #0
	ldr r6, _080B90D0 @ =0xFFFFF000
	adds r4, r6, #0
_080B907C:
	adds r0, r1, #0
	adds r0, #0x1d
	orrs r0, r4
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	adds r1, #1
	cmp r1, #2
	ble _080B907C
	ldr r0, _080B90C4 @ =0x00001410
	adds r1, r5, r0
	ldr r4, _080B90D4 @ =0x00001423
	adds r0, r5, r4
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0xf0
	lsls r6, r6, #8
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #0xa
	bgt _080B90BC
	ldr r1, _080B90D8 @ =0x0000F010
	adds r0, r1, #0
_080B90B2:
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #0xa
	ble _080B90B2
_080B90BC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B90C4: .4byte 0x00001410
_080B90C8: .4byte 0x0000141E
_080B90CC: .4byte 0x00001419
_080B90D0: .4byte 0xFFFFF000
_080B90D4: .4byte 0x00001423
_080B90D8: .4byte 0x0000F010

	thumb_func_start FUN_080b90dc
FUN_080b90dc: @ 0x080B90DC
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080B911C @ =0x0000140C
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080B90EE
	b _080B920C
_080B90EE:
	ldr r2, _080B9120 @ =0x00001479
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1d
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080B9124
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	b _080B913C
	.align 2, 0
_080B911C: .4byte 0x0000140C
_080B9120: .4byte 0x00001479
_080B9124:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
_080B913C:
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080b8f34
	adds r5, r0, #0
	cmp r5, #0
	beq _080B91CA
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _080B9170 @ =0x00001410
	adds r1, r4, r2
	adds r2, #4
	adds r0, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #4
	bhi _080B91BC
	lsls r0, r0, #2
	ldr r1, _080B9174 @ =_080B9178
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B9170: .4byte 0x00001410
_080B9174: .4byte _080B9178
_080B9178: @ jump table
	.4byte _080B918C @ case 0
	.4byte _080B9196 @ case 1
	.4byte _080B91A0 @ case 2
	.4byte _080B91AA @ case 3
	.4byte _080B91B4 @ case 4
_080B918C:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b695c
	b _080B91BC
_080B9196:
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080b695c
	b _080B91BC
_080B91A0:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b78a4
	b _080B91BC
_080B91AA:
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080b78a4
	b _080B91BC
_080B91B4:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b88c4
_080B91BC:
	adds r0, r4, #0
	bl FUN_080b8fa4
	adds r0, r4, #0
	bl FUN_080b9030
	b _080B922A
_080B91CA:
	ldr r0, _080B91FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B922A
	ldr r0, _080B9200 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B9204 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B9208 @ =FUN_080b9248
	adds r0, r4, #0
	bl FUN_080b5ab0
	b _080B9236
	.align 2, 0
_080B91FC: .4byte 0x030044E0
_080B9200: .4byte 0x00000119
_080B9204: .4byte 0x0000FFFF
_080B9208: .4byte FUN_080b9248
_080B920C:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080B9240 @ =0x00001479
	adds r0, r4, r1
	strb r3, [r0]
_080B922A:
	ldr r2, _080B9244 @ =0x00001498
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080B9236:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B9240: .4byte 0x00001479
_080B9244: .4byte 0x00001498

	thumb_func_start FUN_080b9248
FUN_080b9248: @ 0x080B9248
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B927C @ =0x0000140E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080B9274
	ldr r1, _080B9280 @ =0x00001490
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B926E
	movs r1, #0
	bl Script_ExecById
_080B926E:
	adds r0, r4, #0
	bl KillEntity
_080B9274:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B927C: .4byte 0x0000140E
_080B9280: .4byte 0x00001490

	thumb_func_start EntityE02E_Update
EntityE02E_Update: @ 0x080B9284
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080B92AC @ =0x00001478
	adds r5, r4, r0
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r1, _080B92B0 @ =0x00001494
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080B92AC: .4byte 0x00001478
_080B92B0: .4byte 0x00001494

	thumb_func_start EntityE02E_Destroy
EntityE02E_Destroy: @ 0x080B92B4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x78
	movs r5, #0x2e
_080B92BE:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B92BE
	ldr r1, _080B92E4 @ =0x00001218
	adds r0, r6, r1
	bl FUN_080b9a0c
	ldr r1, _080B92E8 @ =0x0000130C
	adds r0, r6, r1
	bl FUN_080b9894
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B92E4: .4byte 0x00001218
_080B92E8: .4byte 0x0000130C

	thumb_func_start EntityE02E_Init
EntityE02E_Init: @ 0x080B92EC
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_080b8920
	adds r0, r4, #0
	bl FUN_080b8ac8
	adds r0, r4, #0
	bl FUN_080b8b24
	adds r0, r4, #0
	bl FUN_080b8b60
	adds r0, r4, #0
	bl FUN_080b8e80
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B9348 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080b695c
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080B934C @ =FUN_080b8f08
	adds r0, r4, #0
	bl FUN_080b5ab0
	movs r0, #0
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B9348: .4byte 0x0000FFFF
_080B934C: .4byte FUN_080b8f08

	thumb_func_start EntityE02E_Create
EntityE02E_Create: @ 0x080B9350
	push {r4, lr}
	ldr r1, _080B937C @ =0x0000149C
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080B9388
	ldr r1, _080B9380 @ =EntityE02E_Update
	ldr r2, _080B9384 @ =EntityE02E_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityE02E_Init
	cmp r0, #0
	bge _080B9388
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080B938A
	.align 2, 0
_080B937C: .4byte 0x0000149C
_080B9380: .4byte EntityE02E_Update
_080B9384: .4byte EntityE02E_Destroy
_080B9388:
	adds r0, r4, #0
_080B938A:
	pop {r4}
	pop {r1}
	bx r1
