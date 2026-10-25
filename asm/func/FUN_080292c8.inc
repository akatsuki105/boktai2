	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r7, r0, #0
	str r1, [sp, #0x28]
	str r7, [sp, #0x2c]
	adds r0, #0x48
	str r0, [sp, #0x30]
	add r2, sp, #0x10
	ldr r0, [r7, #0x50]
	ldr r1, [r7, #0x54]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	adds r0, r7, #0
	adds r0, #0xa0
	ldrb r0, [r0]
	add r6, sp, #0x18
	cmp r0, #1
	beq _08029324
	cmp r0, #1
	bgt _08029302
	cmp r0, #0
	beq _0802930C
	b _08029368
_08029302:
	cmp r0, #2
	beq _0802933A
	cmp r0, #3
	beq _0802934E
	b _08029368
_0802930C:
	ldrh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	subs r0, #0xa0
	strh r0, [r2, #4]
	ldrh r0, [r6, #4]
	subs r0, #0x60
	strh r0, [r6, #4]
	b _08029368
_08029324:
	ldrh r0, [r2, #2]
	adds r0, #0xf0
	strh r0, [r2, #2]
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #0x80
	add r1, sp, #0x10
	strh r0, [r1]
	ldrh r0, [r6]
	adds r0, #0x40
	b _08029366
_0802933A:
	ldrh r0, [r2, #2]
	adds r0, #0xf0
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	adds r0, #0x80
	strh r0, [r2, #4]
	ldrh r0, [r6, #4]
	adds r0, #0x40
	strh r0, [r6, #4]
	b _08029368
_0802934E:
	ldrh r0, [r2, #2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	strh r0, [r2, #2]
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0xa0
	add r1, sp, #0x10
	strh r0, [r1]
	ldrh r0, [r6]
	subs r0, #0x60
_08029366:
	strh r0, [r6]
_08029368:
	add r0, sp, #0x10
	ldrh r0, [r0, #2]
	subs r0, #0x20
	strh r0, [r6, #2]
	ldr r3, _08029480 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r3
	movs r2, #0x40
	orrs r0, r2
	ldr r1, _08029484 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x20]
	mov r0, sp
	adds r0, #0x20
	str r0, [sp, #0x34]
	ldr r0, [r0, #4]
	ands r0, r3
	orrs r0, r2
	ldr r1, [sp, #0x34]
	str r0, [r1, #4]
	ldr r2, [sp, #0x30]
	ldrb r2, [r2, #5]
	mov r8, r2
	movs r3, #0x80
	add r8, r3
	ldr r0, _08029488 @ =0x0203B400
	mov sl, r0
	ldr r1, _0802948C @ =0x030046B8
	ldr r2, [r1]
	adds r2, #1
	ldr r3, _08029490 @ =0x000003FF
	ands r2, r3
	lsls r0, r2, #1
	add r0, sl
	ldrh r1, [r0]
	movs r0, #1
	ands r1, r0
	adds r1, #2
	adds r2, #1
	ands r2, r3
	lsls r0, r2, #1
	add r0, sl
	ldrh r3, [r0]
	movs r0, #0x1f
	ands r3, r0
	add r3, r8
	subs r3, #0x10
	adds r2, #1
	ldr r0, _08029490 @ =0x000003FF
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	ldrh r4, [r0]
	movs r0, #3
	ands r4, r0
	adds r4, #4
	adds r2, #1
	ldr r0, _08029490 @ =0x000003FF
	ands r2, r0
	ldr r0, _0802948C @ =0x030046B8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sl
	ldrh r0, [r2]
	movs r2, #1
	mov sb, r2
	ands r0, r2
	adds r0, #1
	str r4, [sp]
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r6, #0
	ldr r2, [sp, #0x34]
	bl EmitSmoke
	ldr r3, _0802948C @ =0x030046B8
	ldr r2, [r3]
	adds r2, #1
	ldr r0, _08029490 @ =0x000003FF
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	ldrh r1, [r0]
	movs r3, #1
	ands r1, r3
	adds r1, #2
	adds r2, #1
	ldr r0, _08029490 @ =0x000003FF
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	movs r3, #0x1f
	ands r0, r3
	add r8, r0
	movs r0, #0x10
	rsbs r0, r0, #0
	add r8, r0
	adds r2, #1
	ldr r3, _08029490 @ =0x000003FF
	ands r2, r3
	lsls r0, r2, #1
	add r0, sl
	ldrh r3, [r0]
	movs r0, #3
	ands r3, r0
	adds r3, #4
	adds r2, #1
	ldr r0, _08029490 @ =0x000003FF
	ands r2, r0
	ldr r0, _0802948C @ =0x030046B8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sl
	ldrh r0, [r2]
	mov r2, sb
	ands r0, r2
	adds r0, #1
	str r3, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r6, #0
	ldr r2, [sp, #0x34]
	mov r3, r8
	bl EmitSmoke
	ldr r3, [sp, #0x28]
	cmp r3, #1
	beq _080294E8
	cmp r3, #1
	bgt _08029494
	cmp r3, #0
	beq _080294A2
	b _0802960C
	.align 2, 0
_08029480: .4byte 0xFFFF0000
_08029484: .4byte 0x0000FFFF
_08029488: .4byte 0x0203B400
_0802948C: .4byte 0x030046B8
_08029490: .4byte 0x000003FF
_08029494:
	ldr r0, [sp, #0x28]
	cmp r0, #2
	beq _0802952C
	cmp r0, #3
	bne _080294A0
	b _080295D8
_080294A0:
	b _0802960C
_080294A2:
	ldr r1, _080294DC @ =0x00000899
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r1, r1, #2
	ldr r2, [sp, #0x2c]
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r2, r3
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r1, _080294E0 @ =0x00001054
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _080294E4 @ =0x000008DA
	adds r1, r7, r3
	ldrb r1, [r1]
	str r1, [sp]
	movs r1, #0x20
	str r1, [sp, #4]
	subs r3, #0x26
	adds r1, r7, r3
	ldrh r1, [r1]
	str r1, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #0
	b _080295BA
	.align 2, 0
_080294DC: .4byte 0x00000899
_080294E0: .4byte 0x00001054
_080294E4: .4byte 0x000008DA
_080294E8:
	ldr r1, _08029520 @ =0x00000899
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r1, r1, #2
	ldr r2, [sp, #0x2c]
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r2, r3
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r1, _08029524 @ =0x00001054
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, [sp, #0x30]
	ldrb r1, [r3, #5]
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	ldr r3, _08029528 @ =0x000008B6
	adds r1, r7, r3
	ldrh r1, [r1]
	str r1, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #1
	b _080295BA
	.align 2, 0
_08029520: .4byte 0x00000899
_08029524: .4byte 0x00001054
_08029528: .4byte 0x000008B6
_0802952C:
	ldr r0, _080295C8 @ =0x00000899
	adds r5, r7, r0
	ldrb r0, [r5]
	lsls r0, r0, #2
	ldr r1, [sp, #0x2c]
	movs r2, #0x86
	lsls r2, r2, #1
	adds r4, r1, r2
	adds r0, r4, r0
	ldr r2, [r0]
	ldr r3, _080295CC @ =0x00001054
	adds r3, r7, r3
	str r3, [sp, #0x38]
	ldr r0, [r3]
	ldr r1, _080295D0 @ =0x000008DA
	adds r1, r1, r7
	mov sb, r1
	ldrb r1, [r1]
	subs r1, #0x20
	str r1, [sp]
	movs r3, #0x18
	mov r8, r3
	str r3, [sp, #4]
	ldr r1, _080295D4 @ =0x000008B8
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldrh r1, [r1]
	str r1, [sp, #8]
	movs r7, #0xa
	str r7, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #2
	bl FUN_0805b7d4
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r2, [r0]
	ldr r3, [sp, #0x38]
	ldr r0, [r3]
	mov r3, sb
	ldrb r1, [r3]
	str r1, [sp]
	mov r1, r8
	str r1, [sp, #4]
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3]
	str r1, [sp, #8]
	str r7, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #2
	bl FUN_0805b7d4
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, [r4]
	ldr r1, [sp, #0x38]
	ldr r0, [r1]
	mov r3, sb
	ldrb r1, [r3]
	adds r1, #0x20
	str r1, [sp]
	mov r1, r8
	str r1, [sp, #4]
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3]
	str r1, [sp, #8]
	str r7, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #2
_080295BA:
	bl FUN_0805b7d4
	movs r0, #0xcd
	bl PlaySound_0824078c
	b _0802960C
	.align 2, 0
_080295C8: .4byte 0x00000899
_080295CC: .4byte 0x00001054
_080295D0: .4byte 0x000008DA
_080295D4: .4byte 0x000008B8
_080295D8:
	ldr r1, _0802961C @ =0x000008DA
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r3, #0x10
	movs r0, #0xff
	ands r3, r0
	asrs r3, r3, #5
	adds r3, #3
	movs r0, #7
	ands r3, r0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r2, _08029620 @ =0x000008CC
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp, #8]
	add r0, sp, #0x10
	movs r1, #0x2c
	movs r2, #2
	bl Entity080c0fa0_Create
	ldr r0, _08029624 @ =0x00000345
	bl PlaySound_0824078c
_0802960C:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802961C: .4byte 0x000008DA
_08029620: .4byte 0x000008CC
_08029624: .4byte 0x00000345
