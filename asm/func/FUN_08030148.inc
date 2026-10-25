	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	mov r8, r6
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803020A
	movs r4, #0
	strb r4, [r1]
	ldr r0, _0803024C @ =0x00000899
	adds r5, r6, r0
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r1, [r5]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0x3a
	bl Boss_PlayAnimFacing
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	ldrb r1, [r5]
	lsls r1, r1, #2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r6, r3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, _08030250 @ =0x00000844
	adds r2, r6, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	bl FUN_08028604
	ldr r0, _08030254 @ =0x0000084C
	adds r1, r6, r0
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrh r2, [r4]
	adds r0, r6, #0
	bl FUN_0802853c
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_08029a1c
_0803020A:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803021E
	b _080304B0
_0803021E:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08030236
	b _080304B0
_08030236:
	movs r4, #0xb1
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #3
	ble _08030258
	subs r0, r2, #4
	strh r0, [r1]
	b _0803025A
	.align 2, 0
_0803024C: .4byte 0x00000899
_08030250: .4byte 0x00000844
_08030254: .4byte 0x0000084C
_08030258:
	strh r3, [r1]
_0803025A:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _0803026E
	subs r0, r2, #4
	b _08030270
_0803026E:
	movs r0, #0
_08030270:
	strh r0, [r1]
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r7, r6, r4
	ldrh r5, [r7]
	cmp r5, #1
	beq _08030342
	cmp r5, #1
	bgt _08030288
	cmp r5, #0
	beq _08030296
	b _08030484
_08030288:
	cmp r5, #2
	bne _0803028E
	b _080303F8
_0803028E:
	cmp r5, #3
	bne _08030294
	b _08030468
_08030294:
	b _08030484
_08030296:
	ldr r0, _0803032C @ =0x00000899
	adds r1, r6, r0
	mov r0, r8
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r3, r8
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	mov r0, r8
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, r8
	adds r0, #0xa1
	strb r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r2, _08030330 @ =0x00000842
	adds r1, r6, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08030338
	adds r0, r6, #0
	bl FUN_08028648
	adds r0, r6, #0
	bl FUN_080286d8
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	mov r0, r8
	movs r3, #0x3a
	bl Boss_PlayAnimFacing
	ldr r1, _08030334 @ =0x000008E4
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #3
	bhi _0803031E
	b _08030484
_0803031E:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
	b _08030484
	.align 2, 0
_0803032C: .4byte 0x00000899
_08030330: .4byte 0x00000842
_08030334: .4byte 0x000008E4
_08030338:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	b _0803047E
_08030342:
	ldr r3, _080303D0 @ =0x00000899
	adds r1, r6, r3
	mov r0, r8
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r3, r8
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	mov r0, r8
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, r8
	adds r0, #0xa1
	strb r1, [r0]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r4, r6, r0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080303D8
	adds r0, r6, #0
	adds r0, #0x48
	ldrb r0, [r0, #5]
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r0, #0x40
	ldr r2, _080303D4 @ =0x000008DA
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	movs r3, #0x3b
	bl Boss_PlayAnimFacing
	movs r0, #0
	strh r0, [r4]
	b _0803047E
	.align 2, 0
_080303D0: .4byte 0x00000899
_080303D4: .4byte 0x000008DA
_080303D8:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	str r5, [sp, #8]
	mov r0, r8
	movs r3, #0x3a
	bl Boss_PlayAnimFacing
	b _08030484
_080303F8:
	ldr r4, _08030440 @ =0x00000311
	adds r0, r6, r4
	ldrb r1, [r0]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08030484
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08030444 @ =0x0000017B
	adds r1, r6, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1]
	cmp r0, r1
	blo _08030448
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r6, r3
	subs r4, #0x3d
	adds r2, r6, r4
	str r5, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	movs r3, #0x3c
	bl Boss_PlayAnimFacing
	b _0803047E
	.align 2, 0
_08030440: .4byte 0x00000311
_08030444: .4byte 0x0000017B
_08030448:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r6, r3
	str r5, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	movs r3, #0x3b
	bl Boss_PlayAnimFacing
	b _08030484
_08030468:
	ldr r4, _080304BC @ =0x00000311
	adds r0, r6, r4
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08030484
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803047E:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
_08030484:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _080304B0
	movs r2, #0xc2
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _080304B0
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _080304B0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080292c8
_080304B0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080304BC: .4byte 0x00000311
