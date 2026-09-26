	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r7, #0
	ldr r0, _080AA174 @ =0x000003FF
	mov sl, r0
	ldr r1, _080AA178 @ =0x085B0A08
	mov sb, r1
	mov ip, r5
	movs r6, #0
	movs r2, #0xff
	mov r8, r2
_080AA102:
	adds r0, r5, #0
	adds r0, #0x7c
	ldrh r0, [r0]
	adds r0, #8
	movs r1, #0xbe
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x7e
	ldrh r0, [r0]
	adds r0, #8
	movs r1, #0xbf
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	ldr r0, _080AA17C @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	mov r2, sl
	ands r1, r2
	lsls r0, r1, #1
	ldr r2, _080AA180 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	lsls r3, r7, #5
	asrs r2, r2, #3
	movs r0, #0xf
	ands r2, r0
	adds r3, r3, r2
	adds r2, r3, #0
	subs r2, #8
	adds r1, #1
	mov r0, sl
	ands r1, r0
	ldr r0, _080AA17C @ =0x030046B8
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _080AA180 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r4, r0, #4
	adds r3, #0x38
	mov r1, r8
	ands r3, r1
	lsls r3, r3, #1
	add r3, sb
	movs r1, #0
	ldrsh r0, [r3, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AA184
	asrs r1, r0, #0xc
	b _080AA18A
	.align 2, 0
_080AA174: .4byte 0x000003FF
_080AA178: .4byte 0x085B0A08
_080AA17C: .4byte 0x030046B8
_080AA180: .4byte 0x0203B400
_080AA184:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AA18A:
	movs r0, #0xc8
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AA1A8
	asrs r0, r0, #0xc
	b _080AA1AE
_080AA1A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AA1AE:
	movs r1, #0xc9
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r2, r5, r0
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xc7
	lsls r1, r1, #1
	add r1, ip
	movs r0, #1
	strh r0, [r1]
	movs r0, #0xc6
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xce
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r0, r0, r6
	ldr r1, _080AA204 @ =FUN_080aa08c
	str r1, [r0]
	movs r2, #0x3c
	add ip, r2
	adds r6, #0x3c
	adds r7, #1
	cmp r7, #7
	ble _080AA102
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AA204: .4byte FUN_080aa08c
