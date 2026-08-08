	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	mov r8, r7
	movs r4, #1
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r3, r7, r0
	ldr r0, [r3]
	adds r2, r0, #0
	ands r2, r4
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	cmp r2, #0
	beq _0821F138
	adds r0, r7, #0
	movs r1, #4
	bl FUN_0821c010
	ldr r2, _0821F160 @ =0x00000BF6
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r3, #0xfd
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0x1e
	str r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #0
	str r1, [r0]
	ldr r2, _0821F164 @ =0x000003DA
	adds r0, r7, r2
	strb r1, [r0]
_0821F138:
	movs r3, #0
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #3
	bne _0821F14E
	movs r2, #0xfe
	lsls r2, r2, #2
	adds r0, r7, r2
	str r4, [r0]
_0821F14E:
	movs r0, #0xfe
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, [r2]
	cmp r0, #0
	beq _0821F168
	cmp r0, #1
	beq _0821F17E
	b _0821F192
	.align 2, 0
_0821F160: .4byte 0x00000BF6
_0821F164: .4byte 0x000003DA
_0821F168:
	movs r0, #0xfd
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1]
	cmp r0, #0
	ble _0821F17A
	subs r0, #1
	str r0, [r1]
	b _0821F196
_0821F17A:
	str r4, [r2]
	b _0821F192
_0821F17E:
	movs r4, #0xfd
	lsls r4, r4, #2
	adds r1, r7, r4
	ldr r0, [r1]
	cmp r0, #0x1d
	bgt _0821F190
	adds r0, #1
	str r0, [r1]
	b _0821F196
_0821F190:
	str r3, [r2]
_0821F192:
	cmp r3, #0
	beq _0821F1B0
_0821F196:
	movs r1, #0xfd
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r2, [r0]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	bne _0821F1B0
	adds r0, r7, #0
	movs r1, #1
	movs r3, #0x1e
	bl FUN_0821c2a0
_0821F1B0:
	ldr r2, _0821F1DC @ =0x00080004
	mov r1, r8
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r6, [r0]
	cmp r6, #2
	bne _0821F1CA
	b _0821F5EA
_0821F1CA:
	cmp r6, #2
	bgt _0821F1E0
	cmp r6, #0
	beq _0821F1EE
	cmp r6, #1
	bne _0821F1D8
	b _0821F320
_0821F1D8:
	b _0821F806
	.align 2, 0
_0821F1DC: .4byte 0x00080004
_0821F1E0:
	cmp r6, #3
	bne _0821F1E6
	b _0821F700
_0821F1E6:
	cmp r6, #0x63
	bne _0821F1EC
	b _0821F7F6
_0821F1EC:
	b _0821F806
_0821F1EE:
	movs r3, #2
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r2, r7, r4
	ldr r0, [r2]
	ands r3, r0
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov sl, r2
	cmp r3, #0
	beq _0821F226
	movs r0, #0xed
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r7, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	str r6, [sp]
	str r6, [sp, #4]
	adds r0, r7, #0
	movs r1, #0x11
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_0821F226:
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	ble _0821F27A
	movs r2, #0x38
	cmp r1, #0x7f
	bgt _0821F254
	adds r0, r1, #0
	muls r0, r2, r0
	cmp r0, #0
	blt _0821F246
	asrs r1, r0, #6
	b _0821F24C
_0821F246:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0821F24C:
	movs r4, #0xef
	lsls r4, r4, #2
	adds r0, r7, r4
	b _0821F278
_0821F254:
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r2, r1
	movs r0, #8
	lsls r0, r0, #8
	subs r0, #8
	adds r0, r1, r0
	cmp r0, #0
	blt _0821F26C
	asrs r1, r0, #6
	b _0821F272
_0821F26C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0821F272:
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r7, r2
_0821F278:
	strh r1, [r0]
_0821F27A:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r4, r7, r3
	ldr r0, [r4]
	cmp r0, #0x19
	bne _0821F298
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0x13
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_0821F298:
	ldr r0, [r4]
	cmp r0, #0x2c
	bgt _0821F300
	movs r1, #0x2d
	subs r1, r1, r0
	adds r4, r7, #0
	adds r4, #0x58
	movs r2, #0xed
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x80
	asrs r5, r1, #2
	ldr r2, _0821F2D0 @ =0x085B0A08
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F2D4
	asrs r1, r0, #0xc
	b _0821F2DA
	.align 2, 0
_0821F2D0: .4byte 0x085B0A08
_0821F2D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821F2DA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F2F6
	asrs r0, r0, #0xc
	b _0821F2FC
_0821F2F6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821F2FC:
	strh r0, [r4, #4]
	b _0821F806
_0821F300:
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r2, #0
	strh r2, [r0]
	movs r1, #1
	movs r4, #0xe8
	lsls r4, r4, #2
	adds r0, r7, r4
	str r1, [r0]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r7, r1
	str r2, [r0]
	movs r1, #2
	b _0821F5CE
_0821F320:
	movs r3, #2
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r2, r7, r4
	ldr r0, [r2]
	ands r3, r0
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov sl, r2
	cmp r3, #0
	beq _0821F3FC
	movs r0, #0xed
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r7, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	str r6, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #9
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r4, #4
	ldrsh r3, [r0, r4]
	mov r0, r8
	adds r0, #0xcc
	movs r4, #0
	strh r1, [r0]
	mov r1, r8
	adds r1, #0xce
	strh r2, [r1]
	mov r2, r8
	adds r2, #0xd0
	strh r3, [r2]
	movs r1, #0xdc
	add r1, r8
	mov sb, r1
	strb r4, [r1]
	mov r1, r8
	adds r1, #0x48
	movs r3, #0
	ldrsh r5, [r0, r3]
	movs r4, #8
	ldrsh r0, [r1, r4]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	mov r1, r8
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	mov r2, r8
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	mov r3, sb
	strb r6, [r3]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r2, _0821F428 @ =0x000003CA
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #0xf3
	lsls r4, r4, #2
	adds r2, r7, r4
	movs r3, #0
	ldrsh r2, [r2, r3]
	movs r3, #0xc0
	lsls r3, r3, #0xb
	str r3, [sp]
	adds r4, #2
	adds r3, r7, r4
	movs r4, #0
	ldrsh r3, [r3, r4]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	ldr r0, _0821F42C @ =0x0000034A
	bl PlaySound_082406e0
_0821F3FC:
	adds r4, r7, #0
	adds r4, #0x58
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r3, [r0]
	movs r5, #0x32
	ldr r2, _0821F430 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F434
	asrs r1, r0, #0xc
	b _0821F43A
	.align 2, 0
_0821F428: .4byte 0x000003CA
_0821F42C: .4byte 0x0000034A
_0821F430: .4byte 0x085B0A08
_0821F434:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821F43A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F456
	asrs r0, r0, #0xc
	b _0821F45C
_0821F456:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821F45C:
	strh r0, [r4, #4]
	movs r5, #0xc8
	lsls r5, r5, #1
	add r4, sp, #8
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F486
	asrs r1, r0, #0xc
	b _0821F48C
_0821F486:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821F48C:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F4A8
	asrs r0, r0, #0xc
	b _0821F4AE
_0821F4A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821F4AE:
	strh r0, [r4, #4]
	adds r3, r7, #0
	adds r3, #0x50
	add r2, sp, #8
	adds r1, r2, #0
	ldrh r0, [r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r3, #4]
	ldrh r3, [r2, #4]
	adds r1, r1, r3
	strh r1, [r2, #4]
	adds r5, r2, #0
	adds r0, r2, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0821F4F8
	cmp r1, #0
	blt _0821F4F8
	ldr r0, _0821F4FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0821F4F8
	ldr r0, _0821F500 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0821F504
_0821F4F8:
	movs r4, #0
	b _0821F512
	.align 2, 0
_0821F4FC: .4byte 0x030046A8
_0821F500: .4byte 0x030046AC
_0821F504:
	ldr r0, _0821F524 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0821F512:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0821F528
	adds r0, #4
	b _0821F534
	.align 2, 0
_0821F524: .4byte 0x030046A4
_0821F528:
	ldr r0, _0821F548 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0821F534:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0821F54C
	cmp r2, #2
	beq _0821F550
	b _0821F554
	.align 2, 0
_0821F548: .4byte 0x030046A4
_0821F54C:
	ldrb r0, [r5, #4]
	b _0821F552
_0821F550:
	ldrb r0, [r5]
_0821F552:
	subs r1, r1, r0
_0821F554:
	movs r4, #0xec
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r0, [r0]
	subs r0, r1, r0
	ldr r1, _0821F5B0 @ =0x000001FF
	adds r0, r0, r1
	adds r1, #0xff
	movs r2, #0
	cmp r0, r1
	bls _0821F56C
	movs r2, #1
_0821F56C:
	cmp r2, #0
	bne _0821F584
	movs r2, #0xe9
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r3, _0821F5B4 @ =0x00000804
	adds r1, r7, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	ldr r0, [r0]
	cmp r0, r1
	blt _0821F5D8
_0821F584:
	ldr r0, _0821F5B8 @ =0x000003DA
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _0821F5BC
	movs r1, #3
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r7, r4
	str r2, [r0]
	movs r1, #2
	b _0821F5CE
	.align 2, 0
_0821F5B0: .4byte 0x000001FF
_0821F5B4: .4byte 0x00000804
_0821F5B8: .4byte 0x000003DA
_0821F5BC:
	movs r1, #2
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r7, r4
	str r2, [r0]
_0821F5CE:
	mov r2, sl
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _0821F806
_0821F5D8:
	movs r1, #6
	bl Mod
	cmp r0, #0
	beq _0821F5E4
	b _0821F806
_0821F5E4:
	adds r0, r7, #0
	movs r1, #1
	b _0821F7EE
_0821F5EA:
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r1, [r0]
	ands r6, r1
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	mov sl, r0
	cmp r6, #0
	beq _0821F678
	adds r1, r7, #0
	adds r1, #0x50
	add r2, sp, #0x10
	adds r0, r7, #0
	bl FUN_0821c044
	adds r3, r0, #0
	ldr r4, _0821F630 @ =0x000003DA
	adds r0, r7, r4
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0821F638
	subs r3, #2
	cmp r3, #0
	bge _0821F646
	ldr r1, _0821F634 @ =0x00000BF5
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r3, r3, r0
	b _0821F646
	.align 2, 0
_0821F630: .4byte 0x000003DA
_0821F634: .4byte 0x00000BF5
_0821F638:
	adds r3, #2
	ldr r2, _0821F6B8 @ =0x00000BF5
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r3, r0
	blt _0821F646
	subs r3, r3, r0
_0821F646:
	ldr r4, _0821F6BC @ =0x00000BF6
	adds r2, r7, r4
	strb r3, [r2]
	ldr r0, _0821F6C0 @ =0x00000BCC
	adds r4, r7, r0
	movs r1, #0xbf
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r1, [r0]
	ldrb r2, [r2]
	adds r0, r4, #0
	bl FUN_08234f80
	adds r0, r7, #0
	bl FUN_0821bef0
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0x1e
	bl FUN_0821be24
	movs r0, #0xd2
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0821F678:
	movs r2, #0xed
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, r7, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	movs r4, #1
	str r4, [sp]
	movs r5, #0
	str r5, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_0821c400
	ldr r3, _0821F6C4 @ =0x00000BEC
	adds r0, r7, r3
	ldr r2, _0821F6C8 @ =0x00000BEE
	adds r1, r7, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0821F6CC
	adds r0, r7, #0
	bl FUN_0821bf34
	adds r0, r7, #0
	bl FUN_0821bfc8
	b _0821F6E6
	.align 2, 0
_0821F6B8: .4byte 0x00000BF5
_0821F6BC: .4byte 0x00000BF6
_0821F6C0: .4byte 0x00000BCC
_0821F6C4: .4byte 0x00000BEC
_0821F6C8: .4byte 0x00000BEE
_0821F6CC:
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r7, r3
	str r4, [r0]
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r7, r4
	str r5, [r0]
	movs r1, #2
	mov r2, sl
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0821F6E6:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	movs r1, #6
	bl Mod
	cmp r0, #0
	beq _0821F6FA
	b _0821F806
_0821F6FA:
	adds r0, r7, #0
	movs r1, #1
	b _0821F7EE
_0821F700:
	movs r0, #2
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r5, r7, r4
	ldr r1, [r5]
	ands r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r5]
	cmp r0, #0
	beq _0821F754
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	adds r0, r7, #0
	movs r1, #0x15
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r2, _0821F790 @ =0x000003BE
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r4, [sp]
	ldr r4, _0821F794 @ =0x000003C2
	adds r3, r7, r4
	movs r4, #0
	ldrsh r3, [r3, r4]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
_0821F754:
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0x31
	bgt _0821F7C8
	movs r1, #0x32
	subs r1, r1, r0
	adds r4, r7, #0
	adds r4, #0x58
	movs r2, #0xed
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r3, [r0]
	asrs r5, r1, #2
	ldr r2, _0821F798 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F79C
	asrs r1, r0, #0xc
	b _0821F7A2
	.align 2, 0
_0821F790: .4byte 0x000003BE
_0821F794: .4byte 0x000003C2
_0821F798: .4byte 0x085B0A08
_0821F79C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821F7A2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F7BE
	asrs r0, r0, #0xc
	b _0821F7C4
_0821F7BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821F7C4:
	strh r0, [r4, #4]
	b _0821F7D4
_0821F7C8:
	cmp r0, #0x4f
	ble _0821F7D4
	movs r1, #0x10
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0821F7D4:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	cmp r0, #0x27
	bgt _0821F806
	movs r1, #0x14
	bl Mod
	cmp r0, #0
	bne _0821F806
	adds r0, r7, #0
	movs r1, #0
_0821F7EE:
	movs r2, #0x14
	bl FUN_0821ddc4
	b _0821F806
_0821F7F6:
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r1, [r0]
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0821F806:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
