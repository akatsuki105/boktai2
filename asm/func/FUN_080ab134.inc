	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov ip, r1
	movs r7, #0x9c
	lsls r7, r7, #1
	add r7, r8
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080AB154
	b _080AB26E
_080AB154:
	ldrb r1, [r7]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #8
	adds r6, r7, r0
	adds r1, r6, #0
	adds r1, #0x28
	movs r0, #1
	strb r0, [r1]
	ldr r4, _080AB1FC @ =0x0203B400
	ldr r5, _080AB200 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r2, _080AB204 @ =0x000003FF
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r3, #0xf
	ands r0, r3
	adds r0, #0x10
	strh r0, [r6, #0x2e]
	adds r1, #1
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r3
	adds r0, #0x40
	strh r0, [r6, #0x30]
	adds r1, #1
	ands r1, r2
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r5, r6, #0
	adds r5, #0x2a
	strb r0, [r5]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #8
	strb r0, [r1]
	movs r0, #0
	strh r0, [r6, #0x2c]
	mov r2, ip
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	ldr r0, _080AB208 @ =FUN_080ab074
	str r0, [r6, #0x40]
	adds r4, r6, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r0, #0x9e
	lsls r0, r0, #1
	add r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrh r3, [r4, #0x30]
	ldr r2, _080AB20C @ =0x085B0A08
	ldrb r0, [r5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080AB210
	asrs r3, r0, #0xc
	b _080AB216
	.align 2, 0
_080AB1FC: .4byte 0x0203B400
_080AB200: .4byte 0x030046B8
_080AB204: .4byte 0x000003FF
_080AB208: .4byte FUN_080ab074
_080AB20C: .4byte 0x085B0A08
_080AB210:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AB216:
	ldrh r0, [r6, #0x38]
	adds r0, r0, r3
	strh r0, [r4, #0x18]
	ldrh r0, [r6, #0x3a]
	strh r0, [r4, #0x1a]
	ldrh r2, [r6, #0x30]
	ldr r1, _080AB23C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080AB240
	asrs r1, r0, #0xc
	b _080AB246
	.align 2, 0
_080AB23C: .4byte 0x085B0A08
_080AB240:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AB246:
	ldrh r0, [r6, #0x3c]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r4, #0x1c]
	movs r0, #2
	strb r0, [r4, #0xf]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _080AB262
	strb r1, [r7]
_080AB262:
	strb r1, [r7, #1]
	movs r1, #0x9d
	lsls r1, r1, #1
	add r1, r8
	movs r0, #1
	strb r0, [r1]
_080AB26E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
