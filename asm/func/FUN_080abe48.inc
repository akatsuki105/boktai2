	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	mov ip, r1
	mov r5, sb
	adds r5, #0x9c
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080ABE68
	b _080ABF90
_080ABE68:
	ldrb r1, [r5]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #8
	adds r7, r5, r0
	adds r1, r7, #0
	adds r1, #0x28
	movs r0, #1
	strb r0, [r1]
	ldr r4, _080ABF20 @ =0x0203B400
	ldr r0, _080ABF24 @ =0x030046B8
	mov r8, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _080ABF28 @ =0x000003FF
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r3, #0xf
	ands r0, r3
	adds r0, #0x10
	adds r6, r7, #0
	adds r6, #0x2b
	strb r0, [r6]
	adds r1, #1
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r3
	adds r0, #0x40
	adds r6, #1
	strb r0, [r6]
	adds r1, #1
	ands r1, r2
	mov r2, r8
	str r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	movs r1, #0x2d
	adds r1, r1, r7
	mov r8, r1
	strb r0, [r1]
	adds r1, r7, #0
	adds r1, #0x2e
	movs r0, #8
	strb r0, [r1]
	subs r1, #4
	movs r0, #0
	strb r0, [r1]
	mov r2, ip
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x30]
	str r1, [r7, #0x34]
	ldr r0, _080ABF2C @ =FUN_080abd74
	str r0, [r7, #0x38]
	adds r4, r7, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r0, sb
	adds r0, #0xa0
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrb r3, [r6]
	ldr r2, _080ABF30 @ =0x085B0A08
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080ABF34
	asrs r3, r0, #0xc
	b _080ABF3A
	.align 2, 0
_080ABF20: .4byte 0x0203B400
_080ABF24: .4byte 0x030046B8
_080ABF28: .4byte 0x000003FF
_080ABF2C: .4byte FUN_080abd74
_080ABF30: .4byte 0x085B0A08
_080ABF34:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080ABF3A:
	ldrh r0, [r7, #0x30]
	adds r0, r0, r3
	strh r0, [r4, #0x18]
	ldrh r0, [r7, #0x32]
	strh r0, [r4, #0x1a]
	adds r0, r7, #0
	adds r0, #0x2c
	ldrb r2, [r0]
	ldr r1, _080ABF64 @ =0x085B0A08
	adds r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080ABF68
	asrs r1, r0, #0xc
	b _080ABF6E
	.align 2, 0
_080ABF64: .4byte 0x085B0A08
_080ABF68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080ABF6E:
	ldrh r0, [r7, #0x34]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r4, #0x1c]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080ABF86
	strb r1, [r5]
_080ABF86:
	strb r1, [r5, #1]
	mov r1, sb
	adds r1, #0x9e
	movs r0, #1
	strb r0, [r1]
_080ABF90:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
