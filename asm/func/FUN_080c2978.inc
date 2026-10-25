	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrh r0, [r6, #4]
	cmp r0, #0
	bne _080C29AA
	ldrb r0, [r6, #1]
	adds r1, r6, #0
	adds r1, #0x24
	strh r0, [r1, #0x10]
	movs r3, #2
	rsbs r3, r3, #0
	movs r0, #0xac
	lsls r0, r0, #1
	adds r2, r6, r0
_080C2994:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _080C2994
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, #0
	bl FUN_080c2694
_080C29AA:
	ldr r0, [r6, #0x18]
	ldr r4, [r0]
	ldr r5, [r0, #4]
	adds r0, r4, #0
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _080C2A00 @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	orrs r1, r0
	asrs r0, r1, #0x10
	ldrh r2, [r6, #0xa]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	ldr r2, _080C2A04 @ =0x0000FFFF
	ands r1, r2
	adds r4, r1, #0
	orrs r4, r0
	adds r0, r5, #0
	ldrh r1, [r6, #0xc]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r3, r5
	adds r5, r3, #0
	orrs r5, r0
	movs r0, #0x10
	ldrsh r2, [r6, r0]
	ldrh r1, [r6, #4]
	movs r0, #4
	subs r0, r0, r1
	muls r2, r0, r2
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r0, r2, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _080C2A08
	asrs r0, r0, #2
	b _080C2A0E
	.align 2, 0
_080C2A00: .4byte 0xFFFF0000
_080C2A04: .4byte 0x0000FFFF
_080C2A08:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C2A0E:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080C2A34 @ =0xFFFF0000
	ands r1, r4
	orrs r1, r0
	adds r4, r1, #0
	movs r0, #0x12
	ldrsh r2, [r6, r0]
	movs r0, #4
	subs r0, r0, r3
	muls r2, r0, r2
	asrs r1, r1, #0x10
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C2A38
	asrs r0, r0, #2
	b _080C2A3E
	.align 2, 0
_080C2A34: .4byte 0xFFFF0000
_080C2A38:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C2A3E:
	lsls r1, r0, #0x10
	ldr r0, _080C2A64 @ =0x0000FFFF
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	movs r2, #0x14
	ldrsh r1, [r6, r2]
	movs r0, #4
	subs r0, r0, r3
	muls r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2A68
	asrs r0, r0, #2
	b _080C2A6E
	.align 2, 0
_080C2A64: .4byte 0x0000FFFF
_080C2A68:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C2A6E:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C2AA8 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	movs r3, #0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	mov ip, r0
	adds r2, r6, #0
	adds r2, #0x40
	asrs r7, r4, #0x10
	lsls r0, r5, #0x10
	asrs r5, r0, #0x10
_080C2A8C:
	movs r0, #8
	subs r4, r0, r3
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	mov r0, ip
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2AAC
	asrs r0, r0, #3
	b _080C2AB2
	.align 2, 0
_080C2AA8: .4byte 0xFFFF0000
_080C2AAC:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C2AB2:
	strh r0, [r2]
	movs r1, #0x12
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	adds r0, r7, #0
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2ACA
	asrs r0, r0, #3
	b _080C2AD0
_080C2ACA:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C2AD0:
	strh r0, [r2, #2]
	movs r1, #0x14
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	adds r0, r5, #0
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2AE8
	asrs r0, r0, #3
	b _080C2AEE
_080C2AE8:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C2AEE:
	strh r0, [r2, #4]
	adds r2, #0x2c
	adds r3, #1
	cmp r3, #7
	ble _080C2A8C
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _080C2B14
	ldr r0, _080C2B1C @ =0x00000233
	bl PlaySound_082406e0
	ldr r1, _080C2B20 @ =FUN_080c26cc
	adds r0, r6, #0
	bl FUN_080c2680
_080C2B14:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2B1C: .4byte 0x00000233
_080C2B20: .4byte FUN_080c26cc
