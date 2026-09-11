	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0800EE60
	movs r2, #0
	strb r2, [r4, #3]
	adds r0, r4, #0
	adds r0, #0x70
	ldr r1, _0800EE88 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
_0800EE60:
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _0800EE78
	ldrh r0, [r4, #6]
	adds r1, r0, #1
	strh r1, [r4, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #8]
	cmp r0, r1
	bls _0800EE8C
_0800EE78:
	movs r0, #3
	movs r1, #0
	strb r0, [r4, #4]
	strh r1, [r4, #6]
	movs r0, #1
	strb r0, [r4, #3]
	b _0800EEB2
	.align 2, 0
_0800EE88: .4byte 0x03002B3C
_0800EE8C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0800EE9C
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800EE9C:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0800EEB2
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r4, #0x24]
	bl FUN_08236400
_0800EEB2:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
