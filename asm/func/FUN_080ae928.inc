	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r0, _080AE984 @ =0x00001348
	adds r3, r5, r0
	ldr r2, _080AE988 @ =0x0000134A
	adds r1, r5, r2
	ldrh r0, [r3]
	ldrh r2, [r1]
	cmp r0, r2
	bhs _080AE99C
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080AE94E
	b _080AEAD0
_080AE94E:
	ldr r0, _080AE98C @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r5, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r3, _080AE990 @ =0x00000504
	adds r2, r5, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r2, _080AE994 @ =0x00001352
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _080AE998 @ =0x0000134C
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	b _080AEAD0
	.align 2, 0
_080AE984: .4byte 0x00001348
_080AE988: .4byte 0x0000134A
_080AE98C: .4byte 0x03002BE0
_080AE990: .4byte 0x00000504
_080AE994: .4byte 0x00001352
_080AE998: .4byte 0x0000134C
_080AE99C:
	ldr r0, _080AE9F4 @ =0x0000134C
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bls _080AE9B0
	b _080AEACC
_080AE9B0:
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _080AE9BA
	b _080AEAD0
_080AE9BA:
	ldrh r0, [r2]
	lsls r6, r0, #4
	ldr r2, _080AE9F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AE9FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AEA00 @ =0x0203B400
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r3, _080AEA04 @ =0x085B0A08
	ldr r1, _080AEA08 @ =0x00001352
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r2, #0
	cmp r0, #0
	blt _080AEA0C
	asrs r2, r0, #0xc
	b _080AEA12
	.align 2, 0
_080AE9F4: .4byte 0x0000134C
_080AE9F8: .4byte 0x030046B8
_080AE9FC: .4byte 0x000003FF
_080AEA00: .4byte 0x0203B400
_080AEA04: .4byte 0x085B0A08
_080AEA08: .4byte 0x00001352
_080AEA0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AEA12:
	movs r0, #0xa0
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0x7f
	ands r4, r0
	ldrh r1, [r1]
	adds r0, r4, r1
	adds r1, r2, #0
	subs r1, #0x40
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r2, _080AEA60 @ =0x00000502
	adds r1, r5, r2
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AEA64 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080AEA68 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _080AEA6C @ =0x00001352
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _080AEA70
	asrs r3, r0, #0xc
	b _080AEA76
	.align 2, 0
_080AEA60: .4byte 0x00000502
_080AEA64: .4byte 0x000003FF
_080AEA68: .4byte 0x0203B400
_080AEA6C: .4byte 0x00001352
_080AEA70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AEA76:
	ldr r0, _080AEAC0 @ =0x00000504
	adds r1, r5, r0
	movs r0, #0x7f
	ands r2, r0
	ldrh r1, [r1]
	adds r1, r2, r1
	adds r0, r3, #0
	subs r0, #0x40
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080AEAC4 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	movs r2, #0x80
	lsls r2, r2, #1
	movs r0, #2
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	ldr r1, _080AEAC8 @ =0x0000134E
	adds r0, r5, r1
	ldrh r0, [r0]
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	add r3, sp, #0x14
	str r3, [sp, #0x10]
	movs r0, #1
	movs r1, #0
	movs r3, #2
	bl FUN_08056774
	b _080AEAD0
	.align 2, 0
_080AEAC0: .4byte 0x00000504
_080AEAC4: .4byte 0xFFFF0000
_080AEAC8: .4byte 0x0000134E
_080AEACC:
	movs r0, #0
	strh r0, [r3]
_080AEAD0:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
