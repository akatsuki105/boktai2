	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803117E
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031144
	ldr r1, _08031140 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x17
	cmp r0, #0
	bne _08031154
	movs r3, #0x13
	b _08031154
	.align 2, 0
_08031140: .4byte 0x00000824
_08031144:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x13
	cmp r0, #0
	beq _08031154
	movs r3, #0x17
_08031154:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl Boss_PlayAnim
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
_0803117E:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08031192
	b _0803140C
_08031192:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080311A8
	b _0803140C
_080311A8:
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #1
	bhi _08031250
	ldr r0, _08031228 @ =0x0000016F
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031250
	subs r0, #1
	mov r1, ip
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08031250
	ldr r6, _0803122C @ =0x030046B8
	ldr r0, [r6]
	adds r3, r0, #1
	ldr r7, _08031230 @ =0x000003FF
	ands r3, r7
	str r3, [r6]
	lsls r0, r3, #1
	ldr r2, _08031234 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	mov r8, r1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
	ldrb r0, [r2]
	cmp r0, #3
	bne _08031238
	adds r0, r3, #1
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _08031234 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, #8
	mov r1, ip
	strb r0, [r1]
	b _08031250
	.align 2, 0
_08031228: .4byte 0x0000016F
_0803122C: .4byte 0x030046B8
_08031230: .4byte 0x000003FF
_08031234: .4byte 0x0203B400
_08031238:
	adds r0, r3, #1
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08031268 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r1, r8
	ands r0, r1
	adds r0, #8
	mov r2, ip
	strb r0, [r2]
_08031250:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _0803125E
	b _08031360
_0803125E:
	cmp r0, #1
	bgt _0803126C
	cmp r0, #0
	beq _08031274
	b _0803140C
	.align 2, 0
_08031268: .4byte 0x0203B400
_0803126C:
	cmp r0, #2
	bne _08031272
	b _080313D8
_08031272:
	b _0803140C
_08031274:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bhi _0803128A
	b _0803140C
_0803128A:
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080312B0
	ldr r1, _080312AC @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x18
	movs r2, #0x82
	lsls r2, r2, #4
	adds r6, r4, r2
	cmp r0, #0
	bne _080312C2
	movs r3, #0x14
	b _080312C2
	.align 2, 0
_080312AC: .4byte 0x00000824
_080312B0:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r3, #0x14
	adds r6, r0, #0
	cmp r1, #0
	beq _080312C2
	movs r3, #0x18
_080312C2:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl Boss_PlayAnim
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, [r6]
	cmp r0, #0
	beq _08031304
	ldr r0, _08031300 @ =0x0000030B
	bl PlaySound_082406e0
	b _0803130C
	.align 2, 0
_08031300: .4byte 0x0000030B
_08031304:
	movs r0, #0xd7
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0803130C:
	adds r0, r4, #0
	bl FUN_0802835c
	cmp r0, #0
	bne _08031318
	b _0803140C
_08031318:
	movs r3, #0
	movs r2, #0xca
	ldr r5, _0803133C @ =0x0000087C
	adds r1, r4, r5
	strb r3, [r1]
	subs r5, #2
	adds r0, r4, r5
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _08031344
	ldr r0, _08031340 @ =0x00000878
	adds r1, r4, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _0803140C
	.align 2, 0
_0803133C: .4byte 0x0000087C
_08031340: .4byte 0x00000878
_08031344:
	cmp r0, #0
	bne _08031354
	ldr r1, _08031350 @ =0x00000878
	adds r0, r4, r1
	strh r3, [r0]
	b _0803140C
	.align 2, 0
_08031350: .4byte 0x00000878
_08031354:
	ldr r2, _0803135C @ =0x00000878
	adds r0, r4, r2
	strh r3, [r0]
	b _0803140C
	.align 2, 0
_0803135C: .4byte 0x00000878
_08031360:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _0803140C
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031394
	ldr r1, _08031390 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x19
	cmp r0, #0
	bne _080313A4
	movs r3, #0x15
	b _080313A4
	.align 2, 0
_08031390: .4byte 0x00000824
_08031394:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0x15
	cmp r0, #0
	beq _080313A4
	movs r3, #0x19
_080313A4:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl Boss_PlayAnim
	bl FUN_080846f8
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	b _0803140C
_080313D8:
	adds r0, r4, #0
	bl FUN_0802835c
	cmp r0, #0
	beq _080313F6
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _080313F6
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080313F6:
	ldr r2, _08031418 @ =0x00000311
	adds r0, r4, r2
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803140C
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803140C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031418: .4byte 0x00000311
