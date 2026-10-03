	push {r4, lr}
	adds r3, r0, #0
	cmp r1, #0
	bne _08096DC2
	ldr r1, _08096DB0 @ =0x00003AEB
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08096DB4
	adds r0, r3, #0
	movs r1, #0
	movs r2, #4
	bl FUN_0808c658
	b _08096EBC
	.align 2, 0
_08096DB0: .4byte 0x00003AEB
_08096DB4:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0808c658
	b _08096EBC
_08096DC2:
	movs r1, #0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r3, r2
	ldr r0, [r0]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #5
	beq _08096E72
	ldr r1, _08096E20 @ =0x00003AEE
	adds r0, r3, r1
	ldrb r1, [r0]
	ldr r2, _08096E24 @ =0x00003FE0
	adds r0, r3, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08096E30
	ldr r4, _08096E28 @ =0x00003AEB
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0x10
	bne _08096E06
	ldr r0, _08096E2C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _08096E5E
_08096E06:
	ldr r2, _08096E28 @ =0x00003AEB
	adds r0, r3, r2
	ldr r4, _08096E24 @ =0x00003FE0
	adds r1, r3, r4
	ldrb r0, [r0]
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r1, #0
	cmp r0, #0
	blt _08096E72
	b _08096E70
	.align 2, 0
_08096E20: .4byte 0x00003AEE
_08096E24: .4byte 0x00003FE0
_08096E28: .4byte 0x00003AEB
_08096E2C: .4byte 0x030046A0
_08096E30:
	ldr r0, _08096E40 @ =0x00003AEB
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, #0x14
	bne _08096E44
	movs r1, #2
	b _08096E72
	.align 2, 0
_08096E40: .4byte 0x00003AEB
_08096E44:
	cmp r0, #0x10
	bne _08096E4C
	movs r1, #1
	b _08096E72
_08096E4C:
	cmp r0, r1
	bne _08096E70
	ldr r0, _08096E64 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bne _08096E68
_08096E5E:
	movs r1, #4
	b _08096E72
	.align 2, 0
_08096E64: .4byte 0x030046A0
_08096E68:
	movs r0, #0x10
	strb r0, [r2]
	movs r1, #1
	b _08096E72
_08096E70:
	movs r1, #3
_08096E72:
	cmp r1, #3
	beq _08096EA2
	cmp r1, #3
	bgt _08096E80
	cmp r1, #1
	beq _08096E86
	b _08096EB0
_08096E80:
	cmp r1, #4
	beq _08096E94
	b _08096EB0
_08096E86:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #5
	bl FUN_0808c658
	b _08096EBC
_08096E94:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #2
	bl FUN_0808c658
	b _08096EBC
_08096EA2:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #3
	bl FUN_0808c658
	b _08096EBC
_08096EB0:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0808c658
_08096EBC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
