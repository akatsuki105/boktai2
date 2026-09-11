	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _0800EB30
	movs r4, #0
	strb r4, [r5, #3]
	adds r0, r5, #0
	adds r0, #0x70
	ldr r1, _0800EB78 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r4, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	bl FUN_0800e530
	ldr r2, _0800EB7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800EB80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800EB84 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #6
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #8
	str r2, [sp]
	str r2, [sp, #4]
	str r4, [sp, #8]
	adds r2, #0xf8
	str r2, [sp, #0xc]
	movs r2, #0x18
	str r2, [sp, #0x10]
	movs r2, #0x10
	str r2, [sp, #0x14]
	movs r2, #9
	movs r3, #0x14
	bl FUN_080166ac
_0800EB30:
	ldrb r0, [r5, #2]
	cmp r0, #1
	bls _0800EB60
	ldrb r0, [r5, #0xe]
	adds r0, #1
	movs r1, #0
	strb r0, [r5, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _0800EB58
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0800EB56
	strb r1, [r5, #0xf]
_0800EB56:
	strb r1, [r5, #0xe]
_0800EB58:
	ldrb r1, [r5, #0xf]
	adds r0, r5, #0
	adds r0, #0x44
	strh r1, [r0, #0x10]
_0800EB60:
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bgt _0800EB88
	movs r0, #3
	movs r1, #0
	strb r0, [r5, #4]
	strh r1, [r5, #6]
	movs r0, #1
	strb r0, [r5, #3]
	b _0800EBFE
	.align 2, 0
_0800EB78: .4byte 0x03002B3C
_0800EB7C: .4byte 0x030046B8
_0800EB80: .4byte 0x000003FF
_0800EB84: .4byte 0x0203B400
_0800EB88:
	ldrh r0, [r5, #6]
	adds r1, r0, #1
	strh r1, [r5, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bls _0800EBA4
	movs r0, #2
	movs r1, #0
	strb r0, [r5, #4]
	strh r1, [r5, #6]
	movs r0, #1
	strb r0, [r5, #3]
	b _0800EBD8
_0800EBA4:
	ldrh r0, [r5, #6]
	movs r1, #0x1e
	subs r1, r1, r0
	asrs r2, r1, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800EBC6
	adds r1, r5, #0
	adds r1, #0x60
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r1]
	subs r0, r0, r2
	b _0800EBD6
_0800EBC6:
	adds r1, r5, #0
	adds r1, #0x60
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r1]
	adds r0, r0, r2
_0800EBD6:
	strh r0, [r1]
_0800EBD8:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0800EBE8
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800EBE8:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _0800EBFE
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r5, #0x24]
	bl FUN_08236400
_0800EBFE:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
