	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0800EA12
	movs r2, #0
	strb r2, [r4, #3]
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0800EA12
	adds r0, r4, #0
	adds r0, #0x70
	ldr r1, _0800EA40 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
_0800EA12:
	ldrh r0, [r4, #0x1a]
	ldrh r1, [r4, #0x12]
	subs r0, r0, r1
	strh r0, [r4, #0x1a]
	movs r1, #0x1a
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, #0x14]
	cmp r0, r1
	bgt _0800EA6C
	strh r1, [r4, #0x1a]
	ldrb r0, [r4, #2]
	cmp r0, #2
	bne _0800EA54
	ldrb r1, [r4, #5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800EA48
	ldr r0, _0800EA44 @ =0x0000029D
	bl PlaySound_082406e0
	b _0800EA5C
	.align 2, 0
_0800EA40: .4byte 0x03002B3C
_0800EA44: .4byte 0x0000029D
_0800EA48:
	ldr r0, _0800EA50 @ =0x000001FF
	bl PlaySound_082406e0
	b _0800EA5C
	.align 2, 0
_0800EA50: .4byte 0x000001FF
_0800EA54:
	movs r0, #0xa3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0800EA5C:
	movs r2, #1
	movs r1, #0
	strb r2, [r4, #4]
	movs r0, #0
	strh r1, [r4, #6]
	strb r2, [r4, #3]
	strb r0, [r4, #0xf]
	strb r0, [r4, #0xe]
_0800EA6C:
	ldrb r0, [r4, #2]
	cmp r0, #1
	bls _0800EA9C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bne _0800EA94
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0800EA92
	strb r1, [r4, #0xf]
_0800EA92:
	strb r1, [r4, #0xe]
_0800EA94:
	ldrb r1, [r4, #0xf]
	adds r0, r4, #0
	adds r0, #0x44
	strh r1, [r0, #0x10]
_0800EA9C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0800EAAC
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800EAAC:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0800EAC2
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r4, #0x24]
	bl FUN_08236400
_0800EAC2:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
