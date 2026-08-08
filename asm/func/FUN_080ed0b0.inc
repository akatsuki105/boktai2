	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r0, [sp, #0x14]
	bl FUN_080ef840
	ldr r0, _080ED0C8 @ =0x03002C60
	b _080ED532
	.align 2, 0
_080ED0C8: .4byte 0x03002C60
_080ED0CC:
	adds r0, r7, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _080ED0DC
	b _080ED530
_080ED0DC:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r6, r7, r0
	ldr r1, _080ED180 @ =0xFFFEBE3F
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r1, _080ED184 @ =0x0000021E
	adds r0, r7, r1
	strh r2, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r7, r3
	strh r2, [r0]
	ldr r4, _080ED188 @ =0x00000202
	adds r0, r7, r4
	strh r2, [r0]
	ldr r5, _080ED18C @ =0x0203B400
	ldr r4, _080ED190 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r2, _080ED194 @ =0x000003FF
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r3, #0x3f
	ands r0, r3
	subs r0, #0x10
	str r0, [sp, #0x1c]
	adds r1, #1
	ands r1, r2
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	ands r0, r3
	subs r0, #0x10
	mov sl, r0
	movs r0, #0x8b
	lsls r0, r0, #1
	adds r1, r7, r0
	mov r2, sp
	ldrh r2, [r2, #0x14]
	strh r2, [r1]
	ldr r3, _080ED198 @ =0x0000048A
	adds r0, r7, r3
	mov r4, sp
	ldrh r4, [r4, #0x14]
	strh r4, [r0]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r2, r7, r1
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r1, r0
	mov sb, r6
	mov r8, r2
	cmp r1, #0
	beq _080ED166
	b _080ED2B8
_080ED166:
	ldr r2, _080ED19C @ =0x0000047C
	adds r0, r7, r2
	ldrh r1, [r0]
	ldr r3, _080ED1A0 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080ED1A4
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080ED1B0
	.align 2, 0
_080ED180: .4byte 0xFFFEBE3F
_080ED184: .4byte 0x0000021E
_080ED188: .4byte 0x00000202
_080ED18C: .4byte 0x0203B400
_080ED190: .4byte 0x030046B8
_080ED194: .4byte 0x000003FF
_080ED198: .4byte 0x0000048A
_080ED19C: .4byte 0x0000047C
_080ED1A0: .4byte 0x0000025D
_080ED1A4:
	ldr r2, [r7, #0x44]
	ldr r0, _080ED1D8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080ED1B0:
	ldr r4, _080ED1DC @ =0x00000492
	adds r1, r7, r4
	movs r0, #8
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #8
	mov r2, sb
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, _080ED1E0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080ED1E4
	movs r0, #1
	b _080ED1E6
	.align 2, 0
_080ED1D8: .4byte 0x03003584
_080ED1DC: .4byte 0x00000492
_080ED1E0: .4byte 0x030047A4
_080ED1E4:
	movs r0, #0
_080ED1E6:
	cmp r0, #0
	beq _080ED254
	movs r3, #0x94
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _080ED254
	cmp r2, #0
	beq _080ED254
	ldr r0, _080ED20C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080ED210
	movs r0, #1
	rsbs r0, r0, #0
	b _080ED214
	.align 2, 0
_080ED20C: .4byte 0x03002C68
_080ED210:
	movs r4, #0x18
	ldrsh r0, [r0, r4]
_080ED214:
	cmp r0, #1
	beq _080ED236
	cmp r0, #1
	bgt _080ED222
	cmp r0, #0
	beq _080ED22C
	b _080ED254
_080ED222:
	cmp r0, #2
	beq _080ED240
	cmp r0, #3
	beq _080ED24A
	b _080ED254
_080ED22C:
	ldr r0, [r1]
	cmp r0, #1
	beq _080ED254
	movs r0, #0
	b _080ED256
_080ED236:
	ldr r0, [r1]
	cmp r0, #2
	beq _080ED254
	movs r0, #0
	b _080ED256
_080ED240:
	ldr r0, [r1]
	cmp r0, #4
	beq _080ED254
	movs r0, #0
	b _080ED256
_080ED24A:
	ldr r0, [r1]
	cmp r0, #8
	beq _080ED254
	movs r0, #0
	b _080ED256
_080ED254:
	movs r0, #1
_080ED256:
	cmp r0, #0
	beq _080ED2B8
	ldrh r0, [r7]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #0x95
	lsls r4, r4, #2
	adds r2, r7, r4
	ldrh r2, [r2]
	adds r4, #6
	adds r3, r7, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl FUN_0809c344
	add r5, sp, #0xc
	str r4, [sp, #8]
	add r0, sp, #8
	adds r1, r5, #0
	ldr r2, _080ED368 @ =0x05000002
	bl CpuSet
	ldr r0, _080ED36C @ =0x0000048A
	adds r2, r7, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _080ED2A2
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080ED2B8
_080ED2A2:
	adds r0, r7, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r7, #0
	adds r3, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
_080ED2B8:
	adds r0, r7, #0
	ldr r1, [sp, #0x1c]
	mov r2, sl
	bl FUN_080e5098
	movs r0, #8
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r4, r7, r3
	ldrh r1, [r4]
	movs r5, #0
	movs r6, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r0, [sp, #0x1c]
	mov r1, sl
	bl FUN_0823785c
	strb r0, [r7, #5]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x26
	strh r0, [r1]
	ldr r1, _080ED370 @ =0x000004BE
	adds r0, r7, r1
	strh r6, [r0]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	ble _080ED2FE
	b _080ED4CC
_080ED2FE:
	movs r4, #0xba
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r2, [r0]
	movs r1, #0x11
	ldr r3, _080ED374 @ =0x0000046D
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r5, [r0]
	ldr r4, _080ED378 @ =0x00000553
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r1, #3
	subs r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	subs r4, #0xea
	adds r0, r7, r4
	strb r5, [r0]
	ldr r1, _080ED37C @ =0x0000046A
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _080ED380 @ =0x00000484
	adds r0, r7, r2
	str r6, [r0]
	adds r3, #4
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	adds r1, #0x36
	adds r0, r7, r1
	movs r2, #1
	str r2, [r0]
	ldr r0, _080ED384 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080ED388
	movs r0, #1
	b _080ED38A
	.align 2, 0
_080ED368: .4byte 0x05000002
_080ED36C: .4byte 0x0000048A
_080ED370: .4byte 0x000004BE
_080ED374: .4byte 0x0000046D
_080ED378: .4byte 0x00000553
_080ED37C: .4byte 0x0000046A
_080ED380: .4byte 0x00000484
_080ED384: .4byte 0x030047A4
_080ED388:
	movs r0, #0
_080ED38A:
	cmp r0, #0
	beq _080ED3A0
	movs r3, #0x94
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	mov r4, r8
	ldr r1, [r4]
	bl FUN_080ce544
	b _080ED524
_080ED3A0:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	movs r2, #1
	ands r0, r2
	ldr r3, _080ED3C4 @ =0x00000474
	adds r5, r7, r3
	cmp r0, #0
	beq _080ED466
	movs r1, #0x80
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _080ED3C8
	movs r0, #1
	b _080ED3CA
	.align 2, 0
_080ED3C4: .4byte 0x00000474
_080ED3C8:
	movs r0, #0
_080ED3CA:
	cmp r0, #0
	bne _080ED466
	ldr r4, _080ED408 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	cmp r1, #0xe
	bne _080ED3E4
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #1
	beq _080ED44C
_080ED3E4:
	cmp r1, #5
	beq _080ED44C
	cmp r1, #7
	beq _080ED44C
	cmp r1, #6
	beq _080ED44C
	ldr r2, _080ED40C @ =0x030046A0
	ldr r0, [r2]
	ldr r4, _080ED410 @ =0x00000948
	adds r3, r0, r4
	ldrh r4, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080ED414 @ =0x0000270E
	cmp r1, r0
	bgt _080ED418
	adds r0, r4, #1
	b _080ED41C
	.align 2, 0
_080ED408: .4byte 0x000001DF
_080ED40C: .4byte 0x030046A0
_080ED410: .4byte 0x00000948
_080ED414: .4byte 0x0000270E
_080ED418:
	ldr r1, _080ED438 @ =0x0000270F
	adds r0, r1, #0
_080ED41C:
	strh r0, [r3]
	ldr r0, [r2]
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r0, _080ED43C @ =0x0000270E
	cmp r1, r0
	bgt _080ED440
	adds r0, r3, #1
	b _080ED444
	.align 2, 0
_080ED438: .4byte 0x0000270F
_080ED43C: .4byte 0x0000270E
_080ED440:
	ldr r1, _080ED474 @ =0x0000270F
	adds r0, r1, #0
_080ED444:
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_080e9178
_080ED44C:
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_0807a798
	mov r3, r8
	ldr r0, [r3]
	ldr r4, _080ED478 @ =0x00000189
	adds r1, r7, r4
	ldrb r1, [r1]
	bl FUN_0807a840
_080ED466:
	movs r1, #0x80
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _080ED47C
	movs r0, #1
	b _080ED47E
	.align 2, 0
_080ED474: .4byte 0x0000270F
_080ED478: .4byte 0x00000189
_080ED47C:
	movs r0, #0
_080ED47E:
	cmp r0, #0
	bne _080ED4BA
	ldr r0, _080ED494 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080ED498
	movs r0, #1
	b _080ED49A
	.align 2, 0
_080ED494: .4byte 0x030047A4
_080ED498:
	movs r0, #0
_080ED49A:
	cmp r0, #0
	bne _080ED4BA
	movs r1, #0x80
	lsls r1, r1, #4
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080ED4BA
	ldr r0, _080ED4C8 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl FUN_080ec5b4
_080ED4BA:
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _080ED524
	.align 2, 0
_080ED4C8: .4byte 0x03002B28
_080ED4CC:
	movs r0, #0x20
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r3, _080ED550 @ =0x000005CC
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #0x12
	ldr r4, _080ED554 @ =0x0000046D
	adds r0, r7, r4
	movs r3, #1
	strb r3, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r5, [r0]
	ldr r3, _080ED558 @ =0x00000553
	adds r0, r7, r3
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r6, [r0]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	subs r3, #0xea
	adds r0, r7, r3
	strb r5, [r0]
	ldr r4, _080ED55C @ =0x0000046A
	adds r0, r7, r4
	strb r5, [r0]
	ldr r1, _080ED560 @ =0x00000484
	adds r0, r7, r1
	str r6, [r0]
	adds r2, #4
	adds r0, r7, r2
	movs r3, #1
	strb r3, [r0]
_080ED524:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r4, sb
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_080ED530:
	ldr r0, [sp, #0x18]
_080ED532:
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldr r7, [r0, #4]
	cmp r7, #0
	beq _080ED53E
	b _080ED0CC
_080ED53E:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ED550: .4byte 0x000005CC
_080ED554: .4byte 0x0000046D
_080ED558: .4byte 0x00000553
_080ED55C: .4byte 0x0000046A
_080ED560: .4byte 0x00000484
