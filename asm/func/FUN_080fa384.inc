	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _080FA3F8 @ =0xFEFFFFFF
	ldr r2, [r1]
	ands r2, r0
	str r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xe
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _080FA3F4
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	bne _080FA3F4
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r3
	cmp r0, #0
	bne _080FA3F4
	ldr r1, _080FA3FC @ =0x0000A13F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080FA3F4
	movs r0, #0x80
	lsls r0, r0, #0x14
	ands r3, r0
	cmp r3, #0
	bne _080FA3F4
	ldr r7, _080FA400 @ =0x000004BE
	adds r0, r5, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _080FA3F4
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080FA404
_080FA3F4:
	movs r0, #1
	b _080FA406
	.align 2, 0
_080FA3F8: .4byte 0xFEFFFFFF
_080FA3FC: .4byte 0x0000A13F
_080FA400: .4byte 0x000004BE
_080FA404:
	movs r0, #0
_080FA406:
	adds r1, r0, #0
	cmp r1, #0
	bne _080FA4E8
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r3, #0
	str r3, [sp, #0x18]
	ldr r4, _080FA4EC @ =0x7FFFFFFF
	mov sl, r4
	movs r7, #0
	str r7, [sp, #0x1c]
	movs r6, #0
	add r7, sp, #0x10
_080FA424:
	movs r1, #8
	ldrsh r0, [r5, r1]
	movs r2, #0xc
	ldrsh r1, [r5, r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r2, [r2]
	ldr r4, _080FA4F0 @ =0x0000021D
	adds r3, r5, r4
	ldrb r3, [r3]
	ldrh r4, [r5]
	str r4, [sp]
	lsls r4, r6, #0x18
	asrs r4, r4, #0x18
	str r4, [sp, #4]
	bl FUN_08240dec
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r0, #0
	blt _080FA4E2
	add r0, sp, #8
	mov r8, r0
	lsls r4, r6, #0x18
	asrs r2, r4, #0x18
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_080fa354
	adds r6, r0, #0
	adds r0, r5, #0
	add r1, sp, #8
	adds r2, r6, #0
	bl FUN_080fa2ac
	lsls r0, r0, #0x18
	mov sb, r4
	cmp r0, #0
	beq _080FA4D4
	ldr r1, _080FA4F4 @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, r5, #0
	adds r4, #8
	adds r1, r4, #0
	add r2, sp, #8
	bl FUN_0823599c
	cmp r0, #0
	beq _080FA4D4
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r7]
	mov r2, r8
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r3, #0
	ldrsh r0, [r7, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r7, r4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	cmp sl, r1
	ble _080FA4D4
	mov sl, r1
	movs r3, #0x81
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	str r6, [sp, #0x1c]
	movs r4, #1
	str r4, [sp, #0x18]
_080FA4D4:
	movs r0, #0x80
	lsls r0, r0, #0x11
	add r0, sb
	lsrs r6, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	ble _080FA424
_080FA4E2:
	ldr r7, [sp, #0x18]
	cmp r7, #0
	bne _080FA4F8
_080FA4E8:
	movs r0, #0
	b _080FA762
	.align 2, 0
_080FA4EC: .4byte 0x7FFFFFFF
_080FA4F0: .4byte 0x0000021D
_080FA4F4: .4byte 0x000004A4
_080FA4F8:
	ldr r0, _080FA60C @ =0x00000202
	adds r3, r5, r0
	ldrh r6, [r3]
	cmp r6, #0
	bne _080FA588
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _080FA610 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _080FA614 @ =0x0000021E
	adds r0, r5, r2
	movs r4, #0
	strh r6, [r0]
	movs r7, #0x88
	lsls r7, r7, #2
	adds r0, r5, r7
	strh r6, [r0]
	ldr r1, _080FA60C @ =0x00000202
	adds r0, r5, r1
	strh r6, [r0]
	movs r0, #0xb4
	strh r0, [r3]
	subs r2, #0x3f
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
	movs r3, #0xb9
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r2, [r0]
	movs r1, #9
	ldr r7, _080FA618 @ =0x0000046D
	adds r0, r5, r7
	movs r3, #1
	strb r3, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r4, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	movs r1, #0xb
	subs r7, #0xeb
	adds r0, r5, r7
	strb r4, [r0]
	ldr r2, _080FA61C @ =0x00000469
	adds r0, r5, r2
	strb r4, [r0]
	ldr r4, _080FA620 @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	adds r7, #0x1c
	adds r0, r5, r7
	str r6, [r0]
	ldr r1, _080FA624 @ =0x0000046C
	adds r0, r5, r1
	strb r3, [r0]
_080FA588:
	movs r2, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _080FA5BA
	ldr r4, _080FA628 @ =0x0000024E
	adds r2, r5, r4
	movs r7, #0x96
	lsls r7, r7, #1
	adds r0, r7, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r3, #0xcc
	adds r1, r5, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _080FA5BA
	strh r1, [r2]
_080FA5BA:
	ldr r4, _080FA614 @ =0x0000021E
	adds r0, r5, r4
	mov r7, sp
	ldrh r7, [r7, #0x1c]
	strh r7, [r0]
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0xb8
	strh r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080FA606
	cmp r1, #0
	blt _080FA606
	ldr r0, _080FA62C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FA606
	ldr r0, _080FA630 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FA634
_080FA606:
	movs r4, #0
	b _080FA642
	.align 2, 0
_080FA60C: .4byte 0x00000202
_080FA610: .4byte 0xFFFEBE3F
_080FA614: .4byte 0x0000021E
_080FA618: .4byte 0x0000046D
_080FA61C: .4byte 0x00000469
_080FA620: .4byte 0x0000046A
_080FA624: .4byte 0x0000046C
_080FA628: .4byte 0x0000024E
_080FA62C: .4byte 0x030046A8
_080FA630: .4byte 0x030046AC
_080FA634:
	ldr r0, _080FA654 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080FA642:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FA658
	adds r0, #4
	b _080FA664
	.align 2, 0
_080FA654: .4byte 0x030046A4
_080FA658:
	ldr r0, _080FA678 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FA664:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FA67C
	cmp r2, #2
	beq _080FA680
	b _080FA684
	.align 2, 0
_080FA678: .4byte 0x030046A4
_080FA67C:
	ldrb r0, [r6, #4]
	b _080FA682
_080FA680:
	ldrb r0, [r6]
_080FA682:
	subs r1, r1, r0
_080FA684:
	movs r3, #0
	strh r1, [r6, #2]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r1, [r2]
	ldrh r0, [r5, #0xa]
	strh r0, [r1, #2]
	ldr r0, [r2]
	strh r3, [r0, #6]
	ldr r7, _080FA6C4 @ =0x000004A4
	adds r0, r5, r7
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r0, #0x81
	lsls r0, r0, #2
	adds r4, r5, r0
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080FA6CC
	ldr r0, _080FA6C8 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080FA6F6
	.align 2, 0
_080FA6C4: .4byte 0x000004A4
_080FA6C8: .4byte 0xFFFFFDFF
_080FA6CC:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080FA6EC
	cmp r0, #2
	beq _080FA6E8
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FA6E8:
	movs r0, #1
	b _080FA6F8
_080FA6EC:
	ldr r0, _080FA70C @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_080FA6F6:
	movs r0, #0
_080FA6F8:
	cmp r0, #0
	bne _080FA714
	ldr r4, _080FA710 @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _080FA760
	.align 2, 0
_080FA70C: .4byte 0xFFFFFDFF
_080FA710: .4byte 0x000005C4
_080FA714:
	movs r2, #0x10
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r1, r5, r7
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _080FA774 @ =0x00000482
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x11
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r7, #0x8c
	adds r1, r5, r7
	adds r0, r5, #0
	bl FUN_080e7150
	ldr r1, _080FA778 @ =0x00000614
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080FA760
	adds r0, r5, #0
	bl _call_via_r1
_080FA760:
	movs r0, #1
_080FA762:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080FA774: .4byte 0x00000482
_080FA778: .4byte 0x00000614
