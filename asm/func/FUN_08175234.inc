	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08175254 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08175258
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817525A
	.align 2, 0
_08175254: .4byte 0x0000046C
_08175258:
	movs r0, #0
_0817525A:
	adds r1, r0, #0
	cmp r1, #0
	bne _08175262
	b _081753B8
_08175262:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08175328 @ =0x0000046D
	adds r0, r6, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
	movs r0, #0x90
	lsls r0, r0, #3
	strh r0, [r6, #8]
	movs r0, #0xfc
	lsls r0, r0, #8
	strh r0, [r6, #0xa]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r6, #0xc]
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r4, r6, #0
	adds r4, #8
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08177f7c
	movs r0, #0x20
	ldr r1, _0817532C @ =0x00000474
	adds r5, r6, r1
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	ldr r3, _08175330 @ =0x00001008
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08175334 @ =0x03002BE0
	add r2, sp, #4
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	strb r0, [r6, #5]
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r3, r6, r4
	ldrb r4, [r6, #5]
	movs r7, #0x18
	ldr r2, _08175338 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0817533C
	asrs r1, r0, #0xc
	b _08175342
	.align 2, 0
_08175328: .4byte 0x0000046D
_0817532C: .4byte 0x00000474
_08175330: .4byte 0x00001008
_08175334: .4byte 0x03002BE0
_08175338: .4byte gSineTable
_0817533C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08175342:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0817535C @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _08175360
	asrs r0, r0, #0xc
	b _08175366
	.align 2, 0
_0817535C: .4byte gSineTable
_08175360:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08175366:
	movs r1, #0
	strh r0, [r3, #4]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r0, #0x30
	strh r0, [r2]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	subs r3, #0x46
	adds r2, r6, r3
	ldr r1, _081753B0 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r6, #0
	bl FUN_08179ef0
	ldr r0, _081753B4 @ =0x000001A5
	bl PlaySound_082406e0
	movs r0, #0xf9
	lsls r0, r0, #2
	bl sound_08240740
	b _0817551E
	.align 2, 0
_081753B0: .4byte 0xFFEFFFFF
_081753B4: .4byte 0x000001A5
_081753B8:
	ldr r4, _081753E8 @ =0x00000484
	adds r0, r6, r4
	ldr r0, [r0]
	cmp r0, #9
	bgt _081753F0
	add r4, sp, #0xc
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081753EC @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r4, #2]
	movs r5, #0
_081753D6:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #3
	ble _081753D6
	b _08175490
	.align 2, 0
_081753E8: .4byte 0x00000484
_081753EC: .4byte 0x05000002
_081753F0:
	cmp r0, #0x13
	bgt _08175420
	add r4, sp, #0x14
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0817541C @ =0x05000002
	bl CpuSet
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r5, #0
_08175408:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #7
	ble _08175408
	b _08175490
	.align 2, 0
_0817541C: .4byte 0x05000002
_08175420:
	cmp r0, #0x3b
	bgt _08175450
	add r4, sp, #0x1c
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0817544C @ =0x05000002
	bl CpuSet
	movs r0, #0x40
	strh r0, [r4, #2]
	movs r5, #0
_08175438:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #7
	ble _08175438
	b _08175490
	.align 2, 0
_0817544C: .4byte 0x05000002
_08175450:
	cmp r0, #0x4f
	bgt _08175490
	add r4, sp, #0x24
	str r1, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08175478 @ =0x05000002
	bl CpuSet
	movs r5, #0
_08175464:
	cmp r5, #3
	bgt _0817547C
	movs r0, #0x54
	strh r0, [r4, #2]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	b _0817548A
	.align 2, 0
_08175478: .4byte 0x05000002
_0817547C:
	movs r0, #0x94
	strh r0, [r4, #2]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
_0817548A:
	adds r5, #1
	cmp r5, #7
	ble _08175464
_08175490:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r6, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	movs r0, #0xa
	ldrsh r1, [r6, r0]
	ldr r2, _08175504 @ =0x00000472
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _081754B8
	ldr r0, [r6, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081754B8:
	adds r0, r7, #0
	bl FUN_08176c60
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0xc
	bgt _08175514
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x15
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08175508 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, _0817550C @ =0x0000046A
	adds r0, r6, r4
	strb r2, [r0]
	ldr r2, _08175510 @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _0817551E
	.align 2, 0
_08175504: .4byte 0x00000472
_08175508: .4byte 0x00000469
_0817550C: .4byte 0x0000046A
_08175510: .4byte 0x00000484
_08175514:
	ldr r4, _08175528 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0817551E:
	add sp, #0x2c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08175528: .4byte 0x00000484
