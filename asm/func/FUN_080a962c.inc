	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	movs r6, #0
	ldr r0, _080A96A8 @ =0x030046B8
	mov sl, r0
	ldr r1, _080A96AC @ =0x000003FF
	mov sb, r1
	ldr r2, _080A96B0 @ =0x085B0A08
	mov r8, r2
	movs r5, #0
	mov r4, ip
	adds r4, #0xa4
_080A964C:
	movs r0, #0x10
	strh r0, [r4]
	movs r0, #0x20
	strh r0, [r4, #2]
	mov r7, sl
	ldr r1, [r7]
	adds r1, #1
	mov r0, sb
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _080A96B4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	lsls r3, r6, #5
	asrs r2, r2, #3
	movs r0, #0xf
	ands r2, r0
	adds r3, r3, r2
	adds r2, r3, #0
	subs r2, #8
	adds r1, #1
	mov r7, sb
	ands r1, r7
	mov r0, sl
	str r1, [r0]
	lsls r1, r1, #1
	ldr r7, _080A96B4 @ =0x0203B400
	adds r1, r1, r7
	ldrh r0, [r1]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r1, r0, #4
	adds r3, #0x38
	movs r0, #0xff
	ands r3, r0
	lsls r3, r3, #1
	add r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A96B8
	asrs r0, r0, #0xc
	b _080A96BE
	.align 2, 0
_080A96A8: .4byte 0x030046B8
_080A96AC: .4byte 0x000003FF
_080A96B0: .4byte 0x085B0A08
_080A96B4: .4byte 0x0203B400
_080A96B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080A96BE:
	strh r0, [r4, #0x14]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A96D6
	asrs r0, r0, #0xc
	b _080A96DC
_080A96D6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080A96DC:
	strh r0, [r4, #0x16]
	mov r2, ip
	adds r2, #0x8c
	adds r2, r2, r5
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	strh r0, [r4, #0x12]
	movs r7, #0
	strh r7, [r4, #0x10]
	mov r0, ip
	adds r0, #0xc4
	adds r0, r0, r5
	ldr r1, _080A9718 @ =FUN_080a95d4
	str r1, [r0]
	adds r5, #0x3c
	adds r4, #0x3c
	adds r6, #1
	cmp r6, #7
	ble _080A964C
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9718: .4byte FUN_080a95d4
