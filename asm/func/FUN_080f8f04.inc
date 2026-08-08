	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x8c
	str r0, [sp, #0x54]
	adds r7, r1, #0
	str r2, [sp, #0x58]
	ldrb r0, [r0, #5]
	cmp r0, #2
	bne _080F8F1E
	b _080F9490
_080F8F1E:
	cmp r0, #2
	bgt _080F8F2A
	cmp r0, #1
	beq _080F8F32
	bl _080F9A24
_080F8F2A:
	cmp r0, #4
	beq _080F8F32
	bl _080F9A24
_080F8F32:
	ldr r0, [sp, #0x54]
	ldr r1, [r0]
	mov r0, sp
	movs r2, #0x44
	bl memcpy
	movs r1, #0
	str r1, [sp, #0x5c]
	mov r2, sp
	adds r2, #0x44
	str r2, [sp, #0x88]
	adds r3, r7, #0
	adds r3, #8
	str r3, [sp, #0x80]
	mov r0, sp
	adds r0, #8
	str r0, [sp, #0x7c]
	mov r1, sp
	str r1, [sp, #0x60]
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sl, r2
_080F8F60:
	ldr r3, [sp, #0x54]
	ldrb r3, [r3, #5]
	str r3, [sp, #0x64]
	ldr r0, [sp, #0x7c]
	ldrh r1, [r0]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	add r2, sp, #0x44
	strh r1, [r2]
	ldr r1, [sp, #0x7c]
	ldrh r0, [r1, #2]
	ldr r3, [sp, #0x80]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	movs r1, #0x46
	add r1, sp
	strh r0, [r1]
	ldr r3, [sp, #0x7c]
	ldrh r0, [r3, #4]
	ldr r3, [sp, #0x80]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	add r1, sp, #0x48
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	add r3, sp, #0x48
	movs r2, #0
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	str r1, [sp, #0x68]
	adds r0, r7, #0
	ldr r1, [sp, #0x7c]
	bl FUN_080e4384
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F8FD0
	ldr r3, [sp, #0x68]
	ldr r0, [sp, #0x58]
	str r3, [r0]
	movs r0, #6
	ldr r1, [sp, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _080F8FCA
	movs r0, #1
	b _080F9450
_080F8FCA:
	mov r3, sl
	str r0, [r3]
	b _080F945A
_080F8FD0:
	ldrb r4, [r7, #5]
	ldr r1, [sp, #0x88]
	movs r2, #0
	ldrsh r0, [r1, r2]
	add r2, sp, #0x48
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	subs r1, r0, r4
	cmp r1, #0x80
	ble _080F8FF4
	ldr r3, _080F8FF0 @ =0xFFFFFF00
	adds r1, r1, r3
	b _080F9002
	.align 2, 0
_080F8FF0: .4byte 0xFFFFFF00
_080F8FF4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _080F9002
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_080F9002:
	cmp r1, #0
	bge _080F9008
	rsbs r1, r1, #0
_080F9008:
	ldr r2, _080F902C @ =0x000001FD
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r1, r0
	ble _080F9014
	b _080F945E
_080F9014:
	ldr r3, [sp, #0x64]
	cmp r3, #2
	bne _080F9106
	ldr r0, _080F9030 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F9034
	movs r0, #1
	b _080F9036
	.align 2, 0
_080F902C: .4byte 0x000001FD
_080F9030: .4byte 0x030047A4
_080F9034:
	movs r0, #0
_080F9036:
	cmp r0, #0
	beq _080F9090
	ldr r0, [sp, #0x60]
	movs r1, #1
	movs r2, #0x80
	lsls r2, r2, #9
	bl FUN_080f8e84
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F904E
	b _080F918E
_080F904E:
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	blt _080F905E
	asrs r0, r0, #1
	b _080F9064
_080F905E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080F9064:
	adds r4, r0, #0
	ldr r2, _080F9078 @ =0x00000474
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r3, #8
	ands r0, r3
	cmp r0, #0
	beq _080F907C
	movs r0, #1
	b _080F907E
	.align 2, 0
_080F9078: .4byte 0x00000474
_080F907C:
	movs r0, #0
_080F907E:
	cmp r0, #0
	beq _080F9084
	b _080F917E
_080F9084:
	lsls r0, r4, #3
	subs r0, r0, r4
	movs r1, #0xa
	bl Div
	b _080F919E
_080F9090:
	ldr r0, [sp, #0x60]
	movs r1, #1
	movs r2, #0x80
	lsls r2, r2, #9
	bl FUN_080f8e84
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F90C6
	movs r1, #0x20
	ldr r0, _080F90B8 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080F90BC @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F90C0
	movs r0, #1
	b _080F90C2
	.align 2, 0
_080F90B8: .4byte 0x030046A0
_080F90BC: .4byte 0x00000934
_080F90C0:
	movs r0, #0
_080F90C2:
	cmp r0, #0
	bne _080F918E
_080F90C6:
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	blt _080F90D6
	asrs r0, r0, #1
	b _080F90DC
_080F90D6:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080F90DC:
	adds r4, r0, #0
	ldr r2, _080F90F0 @ =0x00000474
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r3, #8
	ands r0, r3
	cmp r0, #0
	beq _080F90F4
	movs r0, #1
	b _080F90F6
	.align 2, 0
_080F90F0: .4byte 0x00000474
_080F90F4:
	movs r0, #0
_080F90F6:
	cmp r0, #0
	bne _080F917E
	lsls r0, r4, #3
	subs r0, r0, r4
	movs r1, #0xa
	bl Div
	b _080F919E
_080F9106:
	ldr r0, _080F9118 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F911C
	movs r0, #1
	b _080F911E
	.align 2, 0
_080F9118: .4byte 0x030047A4
_080F911C:
	movs r0, #0
_080F911E:
	cmp r0, #0
	beq _080F9124
	b _080F945E
_080F9124:
	movs r1, #0x20
	ldr r0, _080F913C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080F9140 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F9144
	movs r0, #1
	b _080F9146
	.align 2, 0
_080F913C: .4byte 0x030046A0
_080F9140: .4byte 0x00000934
_080F9144:
	movs r0, #0
_080F9146:
	cmp r0, #0
	bne _080F918E
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	blt _080F915A
	asrs r0, r0, #1
	b _080F9160
_080F915A:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080F9160:
	adds r4, r0, #0
	ldr r2, _080F9174 @ =0x00000474
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r3, #8
	ands r0, r3
	cmp r0, #0
	beq _080F9178
	movs r0, #1
	b _080F917A
	.align 2, 0
_080F9174: .4byte 0x00000474
_080F9178:
	movs r0, #0
_080F917A:
	cmp r0, #0
	beq _080F9182
_080F917E:
	mov sb, r4
	b _080F91A0
_080F9182:
	lsls r0, r4, #3
	subs r0, r0, r4
	movs r1, #0xa
	bl Div
	b _080F919E
_080F918E:
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
_080F919E:
	mov sb, r0
_080F91A0:
	ldr r3, [sp, #0x68]
	cmp r3, r4
	ble _080F91A8
	b _080F945E
_080F91A8:
	ldr r4, [sp, #0x60]
	adds r4, #8
	adds r0, r7, #0
	ldr r1, [sp, #0x80]
	adds r2, r4, #0
	bl FUN_080e3f50
	str r0, [sp, #0x6c]
	str r4, [sp, #0x84]
	cmp r0, #0
	bge _080F91C0
	b _080F945E
_080F91C0:
	ldr r1, [sp, #0x60]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x84]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080F91E8
	cmp r1, #0
	blt _080F91E8
	ldr r0, _080F91EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F91E8
	ldr r0, _080F91F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F91F4
_080F91E8:
	movs r5, #0
	b _080F9202
	.align 2, 0
_080F91EC: .4byte 0x030046A8
_080F91F0: .4byte 0x030046AC
_080F91F4:
	ldr r0, _080F9228 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080F9202:
	ldr r1, _080F922C @ =0x00000256
	adds r0, r7, r1
	ldrh r1, [r0]
	ldrh r0, [r7, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	mov r8, r0
	subs r0, r5, #1
	cmp r0, r1
	bne _080F928C
	adds r4, r5, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F9230
	adds r0, #4
	b _080F923C
	.align 2, 0
_080F9228: .4byte 0x030046A4
_080F922C: .4byte 0x00000256
_080F9230:
	ldr r0, _080F9258 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F923C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080F9272
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F925C
	adds r0, #4
	b _080F9268
	.align 2, 0
_080F9258: .4byte 0x030046A4
_080F925C:
	ldr r0, _080F9278 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F9268:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080F927C
_080F9272:
	movs r0, #0
	b _080F927E
	.align 2, 0
_080F9278: .4byte 0x030046A4
_080F927C:
	movs r0, #1
_080F927E:
	cmp r0, #0
	bne _080F9284
	b _080F9396
_080F9284:
	cmp r4, r5
	bne _080F928A
	b _080F9392
_080F928A:
	b _080F9396
_080F928C:
	ldr r6, _080F92B0 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r2, [r0, r3]
	adds r0, r1, r2
	cmp r5, r0
	bne _080F92F4
	adds r4, r5, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F92B4
	adds r0, #4
	b _080F92BE
	.align 2, 0
_080F92B0: .4byte 0x030046A4
_080F92B4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080F92BE:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080F9272
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F92D8
_080F92D4:
	adds r0, #4
	b _080F92E4
_080F92D8:
	ldr r0, _080F92F0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F92E4:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _080F9272
	b _080F927C
	.align 2, 0
_080F92F0: .4byte 0x030046A4
_080F92F4:
	adds r0, r5, #1
	cmp r0, r1
	bne _080F932E
	adds r4, r5, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F930C
	adds r0, #4
	b _080F9316
_080F930C:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080F9316:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080F9272
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _080F92D4
	b _080F92D8
_080F932E:
	subs r0, r1, r2
	cmp r5, r0
	bne _080F9396
	adds r4, r5, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F9346
	adds r0, #4
	b _080F9350
_080F9346:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080F9350:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080F9380
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F936A
	adds r0, #4
	b _080F9376
_080F936A:
	ldr r0, _080F9384 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F9376:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080F9388
_080F9380:
	movs r0, #0
	b _080F938A
	.align 2, 0
_080F9384: .4byte 0x030046A4
_080F9388:
	movs r0, #1
_080F938A:
	cmp r0, #0
	beq _080F9396
	cmp r4, r5
	bne _080F9396
_080F9392:
	movs r0, #1
	b _080F9398
_080F9396:
	movs r0, #0
_080F9398:
	cmp r0, #0
	beq _080F93E4
	ldr r1, _080F93B0 @ =0x00000474
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r2, #8
	ands r0, r2
	cmp r0, #0
	beq _080F93B4
	movs r0, #1
	b _080F93B6
	.align 2, 0
_080F93B0: .4byte 0x00000474
_080F93B4:
	movs r0, #0
_080F93B6:
	cmp r0, #0
	bne _080F93CC
	ldr r3, _080F93E0 @ =0x000004A4
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r1, [sp, #0x80]
	ldr r2, [sp, #0x84]
	bl FUN_0823599c
	cmp r0, #0
	beq _080F945E
_080F93CC:
	ldr r0, [sp, #0x68]
	ldr r1, [sp, #0x58]
	str r0, [r1]
	movs r0, #6
	ldr r2, [sp, #0x64]
	ands r0, r2
	cmp r0, #0
	beq _080F9456
_080F93DC:
	movs r0, #1
	b _080F8FCA
	.align 2, 0
_080F93E0: .4byte 0x000004A4
_080F93E4:
	ldr r2, [sp, #0x6c]
	cmp r2, #2
	beq _080F93FE
	ldr r0, [sp, #0x80]
	ldr r1, [sp, #0x84]
	movs r2, #0xa
	movs r3, #0x80
	lsls r3, r3, #1
	bl FUN_082340c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F945E
_080F93FE:
	ldr r3, [sp, #0x58]
	ldr r0, [r3]
	ldr r1, [sp, #0x68]
	cmp r1, r0
	bge _080F945E
	str r1, [r3]
	movs r0, #6
	ldr r2, [sp, #0x64]
	ands r0, r2
	cmp r0, #0
	beq _080F9456
	mov r3, sb
	cmp r3, #0
	bne _080F9424
	ldr r0, [sp, #0x6c]
	cmp r0, #0
	bne _080F9424
_080F9420:
	movs r0, #1
	b _080F9456
_080F9424:
	ldr r2, _080F9438 @ =0x00000474
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r3, #8
	ands r0, r3
	cmp r0, #0
	beq _080F943C
	movs r0, #1
	b _080F943E
	.align 2, 0
_080F9438: .4byte 0x00000474
_080F943C:
	movs r0, #0
_080F943E:
	cmp r0, #0
	bne _080F9420
	ldr r2, [sp, #0x6c]
	cmp r2, #2
	bne _080F944A
	b _080F8FCA
_080F944A:
	ldr r1, [sp, #0x68]
	cmp r1, sb
	bls _080F93DC
_080F9450:
	mov r2, sl
	str r0, [r2]
	b _080F945A
_080F9456:
	mov r1, sl
	str r0, [r1]
_080F945A:
	movs r0, #1
	b _080F9460
_080F945E:
	movs r0, #0
_080F9460:
	cmp r0, #0
	beq _080F9478
	ldr r2, _080F948C @ =0x000004A4
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [sp, #0x80]
	ldr r2, [sp, #0x7c]
	bl FUN_0823599c
	cmp r0, #0
	beq _080F9478
	b _080F9A1C
_080F9478:
	ldr r0, [sp, #0x7c]
	bl FUN_080865dc
	ldr r3, [sp, #0x5c]
	adds r3, #1
	str r3, [sp, #0x5c]
	cmp r3, #1
	bgt _080F948A
	b _080F8F60
_080F948A:
	b _080F9A24
	.align 2, 0
_080F948C: .4byte 0x000004A4
_080F9490:
	movs r1, #8
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080F94A2
	b _080F9A24
_080F94A2:
	ldr r0, _080F94B4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F94B8
	movs r0, #1
	b _080F94BA
	.align 2, 0
_080F94B4: .4byte 0x030047A4
_080F94B8:
	movs r0, #0
_080F94BA:
	ldr r3, [sp, #0x54]
	ldr r4, [r3]
	cmp r0, #0
	beq _080F94EC
	cmp r4, #0
	bne _080F94C8
	b _080F9A24
_080F94C8:
	ldrb r0, [r4, #4]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, #3
	bhi _080F94D4
	adds r3, r0, #0
_080F94D4:
	cmp r3, #0
	bge _080F94DA
	b _080F9A24
_080F94DA:
	movs r2, #8
	ldr r1, _080F9564 @ =0x03002BC0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080F94EC
	b _080F9A24
_080F94EC:
	movs r2, #0x84
	lsls r2, r2, #0xa
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080f8e84
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F9500
	b _080F9A24
_080F9500:
	ldr r0, [sp, #0x54]
	ldr r6, [r0]
	ldrb r1, [r0, #5]
	str r1, [sp, #0x70]
	add r5, sp, #0x4c
	adds r4, r7, #0
	adds r4, #8
	adds r1, r6, #0
	adds r1, #8
	ldrh r0, [r6, #8]
	ldrh r2, [r7, #8]
	subs r0, r0, r2
	strh r0, [r5]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	subs r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r4, #4]
	subs r0, r0, r2
	strh r0, [r5, #4]
	movs r2, #0
	ldrsh r0, [r5, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r2, r2, r0
	str r2, [sp, #0x74]
	adds r0, r7, #0
	bl FUN_080e4384
	lsls r0, r0, #0x18
	str r4, [sp, #0x80]
	cmp r0, #0
	beq _080F9568
_080F954E:
	ldr r0, [sp, #0x74]
	ldr r1, [sp, #0x58]
	str r0, [r1]
	movs r1, #6
	ldr r2, [sp, #0x70]
	ands r1, r2
	cmp r1, #0
	beq _080F9560
	b _080F99E8
_080F9560:
	b _080F99F4
	.align 2, 0
_080F9564: .4byte 0x03002BC0
_080F9568:
	ldrb r4, [r7, #5]
	movs r3, #0
	ldrsh r0, [r5, r3]
	movs r2, #4
	ldrsh r1, [r5, r2]
	bl FUN_0823785c
	subs r1, r0, r4
	cmp r1, #0x80
	ble _080F9588
	ldr r3, _080F9584 @ =0xFFFFFF00
	adds r1, r1, r3
	b _080F9596
	.align 2, 0
_080F9584: .4byte 0xFFFFFF00
_080F9588:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _080F9596
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_080F9596:
	cmp r1, #0
	bge _080F959C
	rsbs r1, r1, #0
_080F959C:
	ldr r2, _080F95C0 @ =0x000001FD
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r1, r0
	ble _080F95A8
	b _080F9A00
_080F95A8:
	ldr r3, [sp, #0x70]
	cmp r3, #2
	bne _080F969A
	ldr r0, _080F95C4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F95C8
	movs r0, #1
	b _080F95CA
	.align 2, 0
_080F95C0: .4byte 0x000001FD
_080F95C4: .4byte 0x030047A4
_080F95C8:
	movs r0, #0
_080F95CA:
	cmp r0, #0
	beq _080F9624
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x80
	lsls r2, r2, #9
	bl FUN_080f8e84
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F95E2
	b _080F9722
_080F95E2:
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	blt _080F95F2
	asrs r0, r0, #1
	b _080F95F8
_080F95F2:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080F95F8:
	adds r4, r0, #0
	movs r1, #8
	ldr r2, _080F960C @ =0x00000474
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F9610
	movs r0, #1
	b _080F9612
	.align 2, 0
_080F960C: .4byte 0x00000474
_080F9610:
	movs r0, #0
_080F9612:
	cmp r0, #0
	beq _080F9618
	b _080F9712
_080F9618:
	lsls r0, r4, #3
	subs r0, r0, r4
	movs r1, #0xa
	bl Div
	b _080F9732
_080F9624:
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x80
	lsls r2, r2, #9
	bl FUN_080f8e84
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F965A
	movs r1, #0x20
	ldr r0, _080F964C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080F9650 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F9654
	movs r0, #1
	b _080F9656
	.align 2, 0
_080F964C: .4byte 0x030046A0
_080F9650: .4byte 0x00000934
_080F9654:
	movs r0, #0
_080F9656:
	cmp r0, #0
	bne _080F9722
_080F965A:
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	cmp r0, #0
	blt _080F966A
	asrs r0, r0, #1
	b _080F9670
_080F966A:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080F9670:
	adds r4, r0, #0
	movs r1, #8
	ldr r2, _080F9684 @ =0x00000474
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F9688
	movs r0, #1
	b _080F968A
	.align 2, 0
_080F9684: .4byte 0x00000474
_080F9688:
	movs r0, #0
_080F968A:
	cmp r0, #0
	bne _080F9712
	lsls r0, r4, #3
	subs r0, r0, r4
	movs r1, #0xa
	bl Div
	b _080F9732
_080F969A:
	ldr r0, _080F96AC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F96B0
	movs r0, #1
	b _080F96B2
	.align 2, 0
_080F96AC: .4byte 0x030047A4
_080F96B0:
	movs r0, #0
_080F96B2:
	cmp r0, #0
	beq _080F96B8
	b _080F9A00
_080F96B8:
	movs r1, #0x20
	ldr r0, _080F96D0 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080F96D4 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F96D8
	movs r0, #1
	b _080F96DA
	.align 2, 0
_080F96D0: .4byte 0x030046A0
_080F96D4: .4byte 0x00000934
_080F96D8:
	movs r0, #0
_080F96DA:
	cmp r0, #0
	bne _080F9722
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	cmp r0, #0
	blt _080F96EE
	asrs r0, r0, #1
	b _080F96F4
_080F96EE:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080F96F4:
	adds r4, r0, #0
	movs r1, #8
	ldr r2, _080F9708 @ =0x00000474
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F970C
	movs r0, #1
	b _080F970E
	.align 2, 0
_080F9708: .4byte 0x00000474
_080F970C:
	movs r0, #0
_080F970E:
	cmp r0, #0
	beq _080F9716
_080F9712:
	mov sb, r4
	b _080F9734
_080F9716:
	lsls r0, r4, #3
	subs r0, r0, r4
	movs r1, #0xa
	bl Div
	b _080F9732
_080F9722:
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r4, [r0]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
_080F9732:
	mov sb, r0
_080F9734:
	ldr r2, [sp, #0x74]
	cmp r2, r4
	ble _080F973C
	b _080F9A00
_080F973C:
	adds r4, r6, #0
	adds r4, #8
	adds r0, r7, #0
	ldr r1, [sp, #0x80]
	adds r2, r4, #0
	bl FUN_080e3f50
	mov sl, r0
	str r4, [sp, #0x78]
	cmp r0, #0
	bge _080F9754
	b _080F9A00
_080F9754:
	ldrh r0, [r6, #8]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldr r3, [sp, #0x78]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080F977A
	cmp r1, #0
	blt _080F977A
	ldr r0, _080F9780 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080F977A
	ldr r0, _080F9784 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F9788
_080F977A:
	movs r4, #0
	b _080F9796
	.align 2, 0
_080F9780: .4byte 0x030046A8
_080F9784: .4byte 0x030046AC
_080F9788:
	ldr r0, _080F97BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080F9796:
	ldr r1, _080F97C0 @ =0x00000256
	adds r0, r7, r1
	ldrh r1, [r0]
	ldrh r0, [r7, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	mov r8, r0
	subs r0, r4, #1
	cmp r0, r1
	bne _080F9820
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F97C4
	adds r0, #4
	b _080F97D0
	.align 2, 0
_080F97BC: .4byte 0x030046A4
_080F97C0: .4byte 0x00000256
_080F97C4:
	ldr r0, _080F97EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F97D0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080F9806
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F97F0
	adds r0, #4
	b _080F97FC
	.align 2, 0
_080F97EC: .4byte 0x030046A4
_080F97F0:
	ldr r0, _080F980C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F97FC:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080F9810
_080F9806:
	movs r0, #0
	b _080F9812
	.align 2, 0
_080F980C: .4byte 0x030046A4
_080F9810:
	movs r0, #1
_080F9812:
	cmp r0, #0
	bne _080F9818
	b _080F992A
_080F9818:
	cmp r5, r4
	bne _080F981E
	b _080F9926
_080F981E:
	b _080F992A
_080F9820:
	ldr r6, _080F9844 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r2, [r0, r3]
	adds r0, r1, r2
	cmp r4, r0
	bne _080F9888
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F9848
	adds r0, #4
	b _080F9852
	.align 2, 0
_080F9844: .4byte 0x030046A4
_080F9848:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080F9852:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080F9806
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F986C
_080F9868:
	adds r0, #4
	b _080F9878
_080F986C:
	ldr r0, _080F9884 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F9878:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _080F9806
	b _080F9810
	.align 2, 0
_080F9884: .4byte 0x030046A4
_080F9888:
	adds r0, r4, #1
	cmp r0, r1
	bne _080F98C2
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F98A0
	adds r0, #4
	b _080F98AA
_080F98A0:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080F98AA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080F9806
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _080F9868
	b _080F986C
_080F98C2:
	subs r0, r1, r2
	cmp r4, r0
	bne _080F992A
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F98DA
	adds r0, #4
	b _080F98E4
_080F98DA:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080F98E4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bne _080F9914
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F98FE
	adds r0, #4
	b _080F990A
_080F98FE:
	ldr r0, _080F9918 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F990A:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080F991C
_080F9914:
	movs r0, #0
	b _080F991E
	.align 2, 0
_080F9918: .4byte 0x030046A4
_080F991C:
	movs r0, #1
_080F991E:
	cmp r0, #0
	beq _080F992A
	cmp r5, r4
	bne _080F992A
_080F9926:
	movs r0, #1
	b _080F992C
_080F992A:
	movs r0, #0
_080F992C:
	cmp r0, #0
	beq _080F9968
	movs r1, #8
	ldr r2, _080F9944 @ =0x00000474
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F9948
	movs r0, #1
	b _080F994A
	.align 2, 0
_080F9944: .4byte 0x00000474
_080F9948:
	movs r0, #0
_080F994A:
	cmp r0, #0
	beq _080F9950
	b _080F954E
_080F9950:
	ldr r3, _080F9964 @ =0x000004A4
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r1, [sp, #0x80]
	ldr r2, [sp, #0x78]
	bl FUN_0823599c
	cmp r0, #0
	beq _080F9A00
	b _080F954E
	.align 2, 0
_080F9964: .4byte 0x000004A4
_080F9968:
	mov r3, sl
	cmp r3, #2
	beq _080F9982
	ldr r0, [sp, #0x80]
	ldr r1, [sp, #0x78]
	movs r2, #0xa
	movs r3, #0x80
	lsls r3, r3, #1
	bl FUN_082340c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F9A00
_080F9982:
	ldr r1, [sp, #0x58]
	ldr r0, [r1]
	ldr r2, [sp, #0x74]
	cmp r2, r0
	bge _080F9A00
	str r2, [r1]
	movs r1, #6
	ldr r3, [sp, #0x70]
	ands r1, r3
	cmp r1, #0
	beq _080F99F4
	mov r0, sb
	cmp r0, #0
	bne _080F99AC
	mov r1, sl
	cmp r1, #0
	bne _080F99AC
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r1, r7, r2
	b _080F99EE
_080F99AC:
	movs r1, #8
	ldr r3, _080F99C0 @ =0x00000474
	adds r0, r7, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F99C4
	movs r0, #1
	b _080F99C6
	.align 2, 0
_080F99C0: .4byte 0x00000474
_080F99C4:
	movs r0, #0
_080F99C6:
	adds r1, r0, #0
	cmp r1, #0
	beq _080F99D4
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r1, r7, r0
	b _080F99EE
_080F99D4:
	mov r2, sl
	cmp r2, #2
	bne _080F99E2
	movs r3, #0xfc
	lsls r3, r3, #1
	adds r0, r7, r3
	b _080F99FA
_080F99E2:
	ldr r0, [sp, #0x74]
	cmp r0, sb
	bhi _080F99F4
_080F99E8:
	movs r3, #0xfc
	lsls r3, r3, #1
	adds r1, r7, r3
_080F99EE:
	movs r0, #1
	str r0, [r1]
	b _080F99FC
_080F99F4:
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r0, r7, r2
_080F99FA:
	str r1, [r0]
_080F99FC:
	movs r0, #1
	b _080F9A02
_080F9A00:
	movs r0, #0
_080F9A02:
	cmp r0, #0
	beq _080F9A24
	ldr r3, _080F9A20 @ =0x000004A4
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r1, [sp, #0x54]
	ldr r2, [r1]
	adds r2, #8
	ldr r1, [sp, #0x80]
	bl FUN_0823599c
	cmp r0, #0
	beq _080F9A24
_080F9A1C:
	movs r0, #1
	b _080F9A26
	.align 2, 0
_080F9A20: .4byte 0x000004A4
_080F9A24:
	movs r0, #0
_080F9A26:
	add sp, #0x8c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
