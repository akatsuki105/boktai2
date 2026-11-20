	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081A1188 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A118C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A118E
	.align 2, 0
_081A1188: .4byte 0x0000046C
_081A118C:
	movs r0, #0
_081A118E:
	adds r7, r5, #0
	adds r7, #8
	cmp r0, #0
	bne _081A1198
	b _081A1324
_081A1198:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _081A1214 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r0, #0xea
	lsls r0, r0, #4
	add r0, r8
	strb r1, [r0]
	ldr r0, _081A1218 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _081A121C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A1220 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081A1224 @ =0x0203B400
	adds r0, r0, r4
	movs r1, #0xff
	ldrb r6, [r0]
	mov r4, sp
	ldr r3, _081A1228 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	adds r7, r2, #0
	mov ip, r3
	cmp r0, #0
	blt _081A122C
	asrs r1, r0, #0xc
	b _081A1232
	.align 2, 0
_081A1214: .4byte 0x0000046D
_081A1218: .4byte 0x03002BE0
_081A121C: .4byte 0x030046B8
_081A1220: .4byte 0x000003FF
_081A1224: .4byte 0x0203B400
_081A1228: .4byte gSineTable
_081A122C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A1232:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _081A124E
	asrs r0, r0, #0xc
	b _081A1254
_081A124E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A1254:
	strh r0, [r4, #4]
	mov r0, sp
	add r2, sp, #8
	ldrh r1, [r2]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _081A12E4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	mov r3, sp
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r4, r5, #0
	adds r4, #8
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _081A12E8 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _081A12EC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	movs r1, #0xff
	ldr r3, _081A12F0 @ =0x00000F0C
	add r3, r8
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	adds r7, r4, #0
	cmp r0, #0
	blt _081A12F4
	asrs r1, r0, #0xc
	b _081A12FA
	.align 2, 0
_081A12E4: .4byte 0xFFFF0000
_081A12E8: .4byte 0x000003FF
_081A12EC: .4byte 0x0203B400
_081A12F0: .4byte 0x00000F0C
_081A12F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A12FA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _081A1314
	asrs r0, r0, #0xc
	b _081A131A
_081A1314:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A131A:
	strh r0, [r3, #4]
	ldr r1, _081A13C4 @ =0x00000E56
	add r1, r8
	movs r0, #1
	strh r0, [r1]
_081A1324:
	movs r6, #0xea
	lsls r6, r6, #4
	add r6, r8
	ldrb r1, [r6]
	mov r4, sp
	lsls r1, r1, #3
	add r1, r8
	ldr r3, _081A13C8 @ =0x00000E58
	adds r1, r1, r3
	ldrh r0, [r1]
	ldrh r2, [r5, #8]
	subs r0, r0, r2
	mov r2, sp
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl Ax_SpawnAfterimage
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _081A1424
	ldrb r1, [r6]
	lsls r1, r1, #3
	add r1, r8
	ldr r4, _081A13C8 @ =0x00000E58
	adds r0, r1, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #8
	ldrsh r2, [r5, r3]
	subs r0, r0, r2
	adds r4, #4
	adds r1, r1, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r0, _081A13C4 @ =0x00000E56
	add r0, r8
	mov r6, sp
	ldrb r3, [r5, #5]
	ldrh r4, [r0]
	ldr r2, _081A13CC @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A13D0
	asrs r1, r0, #0xc
	b _081A13D6
	.align 2, 0
_081A13C4: .4byte 0x00000E56
_081A13C8: .4byte 0x00000E58
_081A13CC: .4byte gSineTable
_081A13D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A13D6:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _081A13F0 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A13F4
	asrs r0, r0, #0xc
	b _081A13FA
	.align 2, 0
_081A13F0: .4byte gSineTable
_081A13F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A13FA:
	strh r0, [r6, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r4, [r5, #0x14]
	adds r0, r0, r4
	strh r0, [r5, #0x14]
	ldr r2, _081A1420 @ =0x00000F0C
	add r2, r8
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	b _081A153A
	.align 2, 0
_081A1420: .4byte 0x00000F0C
_081A1424:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _081A1434
	b _081A153A
_081A1434:
	ldr r3, _081A14BC @ =0x00000F0C
	add r3, r8
	ldr r2, _081A14C0 @ =0x00000E98
	add r2, r8
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _081A14C4 @ =0x00000F0E
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r5, #8]
	ldr r0, _081A14C8 @ =0x00000E9C
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	movs r0, #0
	strb r0, [r6]
	ldr r0, _081A14CC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _081A14D0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A14D4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081A14D8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r4, r0, r2
	movs r1, #0xff
	mov r3, sp
	ands r4, r1
	ldr r2, _081A14DC @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	mov ip, r2
	cmp r0, #0
	blt _081A14E0
	asrs r1, r0, #0xc
	b _081A14E6
	.align 2, 0
_081A14BC: .4byte 0x00000F0C
_081A14C0: .4byte 0x00000E98
_081A14C4: .4byte 0x00000F0E
_081A14C8: .4byte 0x00000E9C
_081A14CC: .4byte 0x03002BE0
_081A14D0: .4byte 0x030046B8
_081A14D4: .4byte 0x000003FF
_081A14D8: .4byte 0x0203B400
_081A14DC: .4byte gSineTable
_081A14E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A14E6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _081A1502
	asrs r0, r0, #0xc
	b _081A1508
_081A1502:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A1508:
	strh r0, [r3, #4]
	add r2, sp, #8
	mov r0, sp
	ldrh r1, [r0]
	ldrh r3, [r2]
	adds r1, r1, r3
	strh r1, [r2]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r2, #4]
	adds r0, r0, r4
	strh r0, [r2, #4]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	b _081A1562
_081A153A:
	ldr r1, _081A1570 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081A1558
	ldr r1, _081A1574 @ =0x00000E56
	add r1, r8
	ldrh r0, [r1]
	cmp r0, #0x11
	bhi _081A1558
	adds r0, #1
	strh r0, [r1]
_081A1558:
	ldr r2, _081A1570 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A1562:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A1570: .4byte 0x00000484
_081A1574: .4byte 0x00000E56
