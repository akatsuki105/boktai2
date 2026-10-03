	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_080b1078
	cmp r0, #0
	beq _080B1900
	ldr r0, _080B18F8 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	str r1, [sp]
	movs r3, #0
	bl FUN_0807bb3c
	ldr r0, _080B18FC @ =0x00000C16
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ad1ec
	b _080B19B2
	.align 2, 0
_080B18F8: .4byte 0x03002BE0
_080B18FC: .4byte 0x00000C16
_080B1900:
	adds r0, r5, #0
	bl FUN_080b1148
	cmp r0, #0
	beq _080B19B2
	ldr r0, _080B1960 @ =0x03002C00
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x48
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r6, _080B1964 @ =0x03002BE0
	ldr r4, [r6]
	movs r3, #0x2c
	ldrsh r0, [r4, r3]
	subs r2, r2, r0
	adds r1, #0x4c
	movs r0, #0
	ldrsh r1, [r1, r0]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #1
	bls _080B193C
	cmp r0, #5
	bne _080B1968
_080B193C:
	adds r0, r2, #0
	bl ArcTan2_8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r1, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0807b9dc
	b _080B1990
	.align 2, 0
_080B1960: .4byte 0x03002C00
_080B1964: .4byte 0x03002BE0
_080B1968:
	adds r0, r2, #0
	bl ArcTan2_8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0807b910
	ldr r0, [r6]
	movs r1, #0
	bl FUN_0807cc84
_080B1990:
	ldr r4, _080B19BC @ =0x03002C00
	ldr r0, [r4]
	bl FUN_0808613c
	ldr r1, [r4]
	adds r1, #0x48
	movs r0, #0x10
	bl FUN_0823bb7c
	adds r0, r5, #0
	movs r1, #0xd
	bl FUN_080ad1ec
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080ad204
_080B19B2:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B19BC: .4byte 0x03002C00
