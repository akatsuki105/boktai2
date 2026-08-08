	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x1b
	beq _0806A922
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl FUN_08060b84
	movs r5, #0xba
	lsls r5, r5, #2
	adds r2, r4, r5
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806A8D4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806A8D0 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r5, #1
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _0806A8E4
	.align 2, 0
_0806A8D0: .4byte 0x000002E6
_0806A8D4:
	lsrs r1, r1, #0x19
	ldr r2, _0806A8F8 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _0806A8FC @ =0x000002E7
	adds r0, r4, r5
	strb r2, [r0]
_0806A8E4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0806A904
	ldr r0, _0806A900 @ =0x000002EB
	bl PlaySound_082406e0
	b _0806A90A
	.align 2, 0
_0806A8F8: .4byte 0x000002E6
_0806A8FC: .4byte 0x000002E7
_0806A900: .4byte 0x000002EB
_0806A904:
	movs r0, #0xe7
	bl PlaySound_082406e0
_0806A90A:
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldr r0, _0806A938 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0806A922
	bl FUN_08050d10
_0806A922:
	ldr r2, _0806A93C @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #6
	bls _0806A92E
	b _0806ABCC
_0806A92E:
	lsls r0, r0, #2
	ldr r1, _0806A940 @ =_0806A944
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806A938: .4byte 0x030047A4
_0806A93C: .4byte 0x0000037D
_0806A940: .4byte _0806A944
_0806A944: @ jump table
	.4byte _0806A960 @ case 0
	.4byte _0806A9AC @ case 1
	.4byte _0806AA88 @ case 2
	.4byte _0806AB34 @ case 3
	.4byte _0806AB68 @ case 4
	.4byte _0806AB88 @ case 5
	.4byte _0806ABC4 @ case 6
_0806A960:
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806A9A4 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _0806A98C
	b _0806ABCC
_0806A98C:
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #1
	bl FUN_08060b84
	ldr r2, _0806A9A8 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	b _0806ABCC
	.align 2, 0
_0806A9A4: .4byte 0x0000037E
_0806A9A8: .4byte 0x000003F6
_0806A9AC:
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	movs r1, #0x2b
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806A9F8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A9FC
	asrs r0, r0, #0xc
	b _0806AA02
	.align 2, 0
_0806A9F8: .4byte 0x085B0A08
_0806A9FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806AA02:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _0806AA24 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806AA28
	asrs r0, r0, #0xc
	b _0806AA2E
	.align 2, 0
_0806AA24: .4byte 0x085B0A08
_0806AA28:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806AA2E:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r2, _0806AA50 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0xe
	bls _0806AA54
	subs r0, #0xf
	b _0806AA56
	.align 2, 0
_0806AA50: .4byte 0x000003F6
_0806AA54:
	movs r0, #0
_0806AA56:
	strh r0, [r1]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _0806AA66
	b _0806ABCC
_0806AA66:
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #2
	bl FUN_08060b84
	ldr r1, _0806AA84 @ =0x000003F6
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	movs r0, #0xaa
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0806ABCC
	.align 2, 0
_0806AA84: .4byte 0x000003F6
_0806AA88:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806AABC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806AAC0
	asrs r0, r0, #0xc
	b _0806AAC6
	.align 2, 0
_0806AABC: .4byte 0x085B0A08
_0806AAC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806AAC6:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806AAE4
	asrs r0, r0, #0xc
	b _0806AAEA
_0806AAE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806AAEA:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806ABCC
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0806AB30 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0806AB52
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #3
	bl FUN_08060b84
	b _0806ABCC
	.align 2, 0
_0806AB30: .4byte 0x030047A4
_0806AB34:
	ldr r5, _0806AB60 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _0806ABCC
	ldr r0, _0806AB64 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	orrs r1, r2
	str r1, [r0]
_0806AB52:
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #4
	bl FUN_08060b84
	b _0806ABCC
	.align 2, 0
_0806AB60: .4byte 0x0000037E
_0806AB64: .4byte 0x030047A4
_0806AB68:
	ldr r0, _0806AB84 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806ABCC
	adds r1, r4, #0
	adds r1, #0xa2
	movs r0, #1
	strb r0, [r1]
	b _0806ABCC
	.align 2, 0
_0806AB84: .4byte 0x0000037E
_0806AB88:
	ldr r1, _0806ABC0 @ =0x0000037E
	adds r5, r4, r1
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _0806ABA4
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806ABA4:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _0806ABCC
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #6
	bl FUN_08060b84
	b _0806ABCC
	.align 2, 0
_0806ABC0: .4byte 0x0000037E
_0806ABC4:
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_0806ABCC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
