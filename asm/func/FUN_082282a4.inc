	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _082282D4
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _082282D0 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _082282D6
	.align 2, 0
_082282D0: .4byte 0x00000F14
_082282D4:
	movs r0, #0
_082282D6:
	cmp r0, #0
	beq _0822830A
	ldr r3, _08228334 @ =0x00000F15
	adds r1, r6, r3
	movs r0, #6
	strb r0, [r1]
	ldr r1, _08228338 @ =0x00000DE4
	adds r0, r6, r1
	ldr r2, _0822833C @ =0x00000E34
	adds r1, r6, r2
	ldr r1, [r1]
	adds r3, #0x13
	adds r2, r6, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #6
	movs r3, #0
	bl FUN_08236fac
	adds r0, r6, #0
	bl FUN_08223998
	ldr r1, _08228340 @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_080136b4
_0822830A:
	ldr r2, _08228344 @ =0x00000F4C
	adds r0, r6, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _0822831A
	adds r0, r6, #0
	bl _call_via_r1
_0822831A:
	ldr r3, _08228348 @ =0x00000DEC
	adds r0, r6, r3
	ldrh r0, [r0]
	movs r1, #7
	ands r1, r0
	cmp r1, #7
	bhi _08228384
	lsls r0, r1, #2
	ldr r1, _0822834C @ =_08228350
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08228334: .4byte 0x00000F15
_08228338: .4byte 0x00000DE4
_0822833C: .4byte 0x00000E34
_08228340: .4byte 0x00000DF4
_08228344: .4byte 0x00000F4C
_08228348: .4byte 0x00000DEC
_0822834C: .4byte _08228350
_08228350: @ jump table
	.4byte _08228370 @ case 0
	.4byte _08228370 @ case 1
	.4byte _0822837C @ case 2
	.4byte _0822837C @ case 3
	.4byte _0822837C @ case 4
	.4byte _0822837C @ case 5
	.4byte _08228370 @ case 6
	.4byte _08228370 @ case 7
_08228370:
	ldr r0, _08228378 @ =0x00000E3A
	adds r1, r6, r0
	movs r0, #1
	b _08228382
	.align 2, 0
_08228378: .4byte 0x00000E3A
_0822837C:
	ldr r2, _082283DC @ =0x00000E3A
	adds r1, r6, r2
	movs r0, #0xff
_08228382:
	strb r0, [r1]
_08228384:
	ldr r3, _082283E0 @ =0x00000DF2
	adds r0, r6, r3
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	cmp r0, #0
	bne _082283A8
	ldr r0, _082283E4 @ =0x00000DBA
	adds r1, r6, r0
	ldr r2, _082283DC @ =0x00000E3A
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
_082283A8:
	ldr r0, _082283E8 @ =0x00000D9C
	adds r5, r6, r0
	ldr r1, _082283EC @ =0x00000DE4
	adds r4, r6, r1
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _082283F0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _082283F8
	.align 2, 0
_082283DC: .4byte 0x00000E3A
_082283E0: .4byte 0x00000DF2
_082283E4: .4byte 0x00000DBA
_082283E8: .4byte 0x00000D9C
_082283EC: .4byte 0x00000DE4
_082283F0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_082283F8:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0822841C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08228424
_0822841C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08228424:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0822845C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _082284A2
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08228466
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08228460
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0822847C
	.align 2, 0
_0822845C: .4byte 0x0000FFFF
_08228460:
	subs r0, #1
	strh r0, [r4, #8]
	b _0822847A
_08228466:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0822847A
	strh r1, [r4, #8]
	movs r2, #1
	b _0822847C
_0822847A:
	movs r2, #0
_0822847C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _082284A4
	movs r0, #1
	strb r0, [r4, #7]
	b _082284A4
_082284A2:
	movs r2, #0
_082284A4:
	ldr r3, _082284B4 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082284B4: .4byte 0x00000F14
