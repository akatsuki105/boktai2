	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F9F8E
	movs r0, #0xec
	lsls r0, r0, #1
	adds r5, r6, r0
	ldr r1, [r5]
	cmp r1, #0
	beq _080F9F8E
	ldrb r0, [r1, #4]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, #3
	bhi _080F9F4E
	adds r3, r0, #0
_080F9F4E:
	cmp r3, #0
	blt _080F9F8E
	movs r2, #8
	ldr r1, _080F9F94 @ =0x03002BC0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080F9F8E
	ldr r0, _080F9F98 @ =0x0000A027
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r2, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	bne _080F9F8E
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r0, #0
	bne _080F9F8E
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r3, #0
	ldrsh r7, [r0, r3]
	cmp r7, #0
	beq _080F9F9C
_080F9F8E:
	movs r0, #0
	b _080FA26C
	.align 2, 0
_080F9F94: .4byte 0x03002BC0
_080F9F98: .4byte 0x0000A027
_080F9F9C:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	movs r1, #0
	mov sb, r1
	mov r2, r8
	strh r0, [r2]
	ldr r3, _080FA0D8 @ =0x00000482
	adds r1, r6, r3
	movs r4, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	str r7, [r5]
	movs r1, #3
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _080FA0DC @ =0x00000469
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _080FA0E0 @ =0x0000046A
	adds r0, r6, r2
	mov r3, sb
	strb r3, [r0]
	adds r5, #0x1c
	adds r0, r6, r5
	str r7, [r0]
	adds r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _080FA0E4 @ =0x080E6795
	movs r1, #0xe
	ldr r3, _080FA0E8 @ =0x0000046D
	adds r0, r6, r3
	strb r4, [r0]
	subs r5, #0x19
	adds r0, r6, r5
	mov r3, sb
	strb r3, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r7, [r0]
	movs r1, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r3, r6, r5
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #7
	mov sl, r2
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r6, r5
	subs r5, #4
	adds r0, r6, r5
	str r1, [r0]
	str r4, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	subs r5, #3
	adds r0, r6, r5
	strb r2, [r0]
	adds r1, #2
	adds r0, r6, r1
	mov r2, sl
	strb r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r0, [r3]
	ands r0, r1
	mov sl, r3
	cmp r0, #0
	beq _080FA088
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _080FA0EC @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080FA0F0 @ =0xFFFFFDFF
	mov r5, r8
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	adds r3, #0xa2
	adds r0, r6, r3
	strh r7, [r0]
	ldr r5, _080FA0F4 @ =0x00000202
	adds r0, r6, r5
	strh r7, [r0]
_080FA088:
	ldr r1, _080FA0F8 @ =0x000004A4
	adds r0, r6, r1
	ldr r0, [r0]
	adds r4, r6, #0
	adds r4, #8
	adds r1, r4, #0
	bl FUN_082362fc
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r7, [r0]
	adds r2, r6, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r7]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r7, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sb, r4
	cmp r2, #0
	blt _080FA0D2
	cmp r1, #0
	blt _080FA0D2
	ldr r0, _080FA0FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FA0D2
	ldr r0, _080FA100 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FA104
_080FA0D2:
	movs r5, #0
	b _080FA112
	.align 2, 0
_080FA0D8: .4byte 0x00000482
_080FA0DC: .4byte 0x00000469
_080FA0E0: .4byte 0x0000046A
_080FA0E4: .4byte 0x080E6795
_080FA0E8: .4byte 0x0000046D
_080FA0EC: .4byte 0xFEFFFFFF
_080FA0F0: .4byte 0xFFFFFDFF
_080FA0F4: .4byte 0x00000202
_080FA0F8: .4byte 0x000004A4
_080FA0FC: .4byte 0x030046A8
_080FA100: .4byte 0x030046AC
_080FA104:
	ldr r0, _080FA124 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080FA112:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FA128
	adds r0, #4
	b _080FA134
	.align 2, 0
_080FA124: .4byte 0x030046A4
_080FA128:
	ldr r0, _080FA148 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FA134:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FA14C
	cmp r2, #2
	beq _080FA150
	b _080FA154
	.align 2, 0
_080FA148: .4byte 0x030046A4
_080FA14C:
	ldrb r0, [r7, #4]
	b _080FA152
_080FA150:
	ldrb r0, [r7]
_080FA152:
	subs r1, r1, r0
_080FA154:
	strh r1, [r7, #2]
	movs r3, #0x95
	lsls r3, r3, #3
	adds r2, r6, r3
	ldr r1, [r2]
	movs r0, #1
	strh r0, [r1, #6]
	ldr r5, _080FA184 @ =0x000004A4
	adds r0, r6, r5
	ldr r5, [r0]
	ldr r4, [r2]
	adds r0, r5, #0
	mov r1, sb
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080FA18C
	ldr r0, _080FA188 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080FA1B6
	.align 2, 0
_080FA184: .4byte 0x000004A4
_080FA188: .4byte 0xFFFFFDFF
_080FA18C:
	adds r0, r5, #0
	mov r1, sb
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080FA1AC
	cmp r0, #2
	beq _080FA1A8
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FA1A8:
	movs r0, #1
	b _080FA1B8
_080FA1AC:
	ldr r0, _080FA1CC @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_080FA1B6:
	movs r0, #0
_080FA1B8:
	cmp r0, #0
	bne _080FA1D4
	ldr r5, _080FA1D0 @ =0x000005C4
	adds r0, r6, r5
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	b _080FA26A
	.align 2, 0
_080FA1CC: .4byte 0xFFFFFDFF
_080FA1D0: .4byte 0x000005C4
_080FA1D4:
	ldr r1, _080FA27C @ =0x0000021E
	adds r0, r6, r1
	movs r4, #0
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r4, [r0]
	ldr r3, _080FA280 @ =0x00000482
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	ldr r5, _080FA284 @ =0x00000222
	adds r0, r6, r5
	strh r4, [r0]
	ldr r1, _080FA288 @ =0x0000024E
	adds r0, r6, r1
	strh r4, [r0]
	mov r3, r8
	ldr r0, _080FA28C @ =0xFFFFFC7F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r1, _080FA290 @ =0xF3FFFFFF
	mov r2, sl
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080FA240
	subs r5, #0xa6
	adds r2, r6, r5
	ldr r1, _080FA294 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080FA298 @ =0xFFFFFDFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #0x87
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080FA27C @ =0x0000021E
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, _080FA29C @ =0x00000202
	adds r0, r6, r2
	strh r4, [r0]
_080FA240:
	ldr r0, _080FA2A0 @ =0xFFFFFBFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r5, _080FA2A4 @ =0x00000542
	adds r1, r6, r5
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080FA2A8 @ =0x000001DF
	adds r0, r6, r1
	ldrb r3, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
_080FA26A:
	movs r0, #1
_080FA26C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080FA27C: .4byte 0x0000021E
_080FA280: .4byte 0x00000482
_080FA284: .4byte 0x00000222
_080FA288: .4byte 0x0000024E
_080FA28C: .4byte 0xFFFFFC7F
_080FA290: .4byte 0xF3FFFFFF
_080FA294: .4byte 0xFEFFFFFF
_080FA298: .4byte 0xFFFFFDFF
_080FA29C: .4byte 0x00000202
_080FA2A0: .4byte 0xFFFFFBFF
_080FA2A4: .4byte 0x00000542
_080FA2A8: .4byte 0x000001DF
