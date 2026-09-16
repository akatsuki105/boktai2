	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	ldr r2, [r7, #0x1c]
	str r2, [r7, #0x28]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #6
	movs r1, #2
	movs r3, #0
	bl FUN_0822c0b8
	ldr r6, _0809152C @ =0x085ACE3C
	ldr r0, _08091530 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r4, r2, r1
	movs r3, #0
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldr r1, _08091534 @ =0x00004052
	adds r5, r7, r1
	strh r0, [r5]
	movs r3, #0
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	ldr r3, _08091538 @ =0x00004054
	adds r1, r7, r3
	strh r0, [r1]
	ldr r1, _0809153C @ =0x00000252
	adds r0, r2, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _08091318
	movs r0, #0x96
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldr r1, _08091540 @ =0x00004058
	adds r3, r7, r1
	strh r0, [r3]
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	ldr r6, _08091544 @ =0x0000405A
	adds r1, r7, r6
	strh r0, [r1]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08091318
	ldrh r0, [r5]
	subs r0, #4
	strh r0, [r5]
	ldrh r0, [r3]
	adds r0, #4
	strh r0, [r3]
_08091318:
	ldr r3, _08091548 @ =0x00004044
	adds r0, r7, r3
	movs r4, #0
	strh r4, [r0]
	ldr r5, _0809154C @ =0x00004046
	adds r0, r7, r5
	strh r4, [r0]
	ldr r6, _08091550 @ =0x00004048
	adds r1, r7, r6
	movs r0, #0x88
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r0, _08091554 @ =0x0000404A
	adds r1, r7, r0
	movs r0, #0xb0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _08091534 @ =0x00004052
	adds r6, r7, r1
	ldrh r0, [r6]
	subs r0, #0x78
	ldr r2, _08091558 @ =0x00004040
	adds r2, r2, r7
	mov sl, r2
	strh r0, [r2]
	adds r3, #0x10
	adds r3, r3, r7
	mov r8, r3
	ldrh r0, [r3]
	subs r0, #0x50
	ldr r4, _0809155C @ =0x00004042
	adds r4, r4, r7
	mov sb, r4
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_08090040
	mov r5, sl
	ldrh r1, [r5]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	ldrh r2, [r4]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x13
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	movs r4, #0
	ldrsh r3, [r5, r4]
	mov r5, sb
	movs r4, #0
	ldrsh r0, [r5, r4]
	str r0, [sp]
	movs r0, #1
	bl Video_GenerateBGMap
	ldr r5, _08091560 @ =0x00002BEC
	adds r1, r7, r5
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r3, _08091564 @ =0x00002BE4
	adds r4, r7, r3
	adds r5, r7, #0
	adds r5, #0x80
	adds r0, r7, #0
	bl FUN_08090b10
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldrh r0, [r6]
	mov r4, sl
	ldrh r1, [r4]
	subs r0, r0, r1
	ldr r5, _08091568 @ =0x00002C04
	adds r1, r7, r5
	strh r0, [r1]
	mov r6, r8
	ldrh r0, [r6]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	ldr r3, _0809156C @ =0x00002C06
	adds r1, r7, r3
	strh r0, [r1]
	ldr r4, _08091570 @ =0x00002C08
	adds r0, r7, r4
	movs r5, #0
	strh r5, [r0]
	ldr r0, _08091530 @ =0x030046A0
	ldr r0, [r0]
	ldr r6, _0809153C @ =0x00000252
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08091424
	ldr r2, _08091574 @ =0x00002C4C
	adds r1, r7, r2
	ldr r0, [r1]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r1]
	ldr r4, _08091540 @ =0x00004058
	adds r0, r7, r4
	ldrh r0, [r0]
	mov r5, sl
	ldrh r1, [r5]
	subs r0, r0, r1
	ldr r6, _08091578 @ =0x00002C64
	adds r1, r7, r6
	strh r0, [r1]
	ldr r1, _08091544 @ =0x0000405A
	adds r0, r7, r1
	ldrh r0, [r0]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	ldr r3, _0809157C @ =0x00002C66
	adds r1, r7, r3
	strh r0, [r1]
	ldr r4, _08091580 @ =0x00002C68
	adds r0, r7, r4
	movs r5, #0
	strh r5, [r0]
_08091424:
	mov r6, sl
	ldrh r1, [r6]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	mov r0, sb
	ldrh r2, [r0]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x13
	movs r3, #2
	rsbs r3, r3, #0
	ands r2, r3
	adds r0, r7, #0
	bl FUN_08090f24
	movs r5, #0
	mov r8, r5
	ldr r6, _08091584 @ =0x00002FC4
	adds r4, r7, r6
	movs r6, #0x81
	lsls r6, r6, #6
_0809144C:
	adds r0, r5, #0
	bl FUN_08090f0c
	cmp r0, #0
	beq _0809147E
	ldr r0, _08091588 @ =0x00000F6C
	adds r2, r7, r0
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08091558 @ =0x00004040
	adds r0, r7, r1
	ldrh r0, [r0]
	rsbs r0, r0, #0
	strh r0, [r4]
	ldr r2, _0809155C @ =0x00004042
	adds r0, r7, r2
	ldrh r0, [r0]
	rsbs r0, r0, #0
	strh r0, [r4, #2]
	mov r3, r8
	strh r3, [r4, #4]
_0809147E:
	adds r4, #0x60
	adds r6, #0x60
	adds r5, #1
	cmp r5, #5
	ble _0809144C
	movs r5, #0
	mov r8, r5
	ldr r6, _0809158C @ =0x00003204
	adds r4, r7, r6
	movs r3, #0x8a
	lsls r3, r3, #6
	ldr r0, _0809152C @ =0x085ACE3C
	adds r6, r0, #0
	adds r6, #0x1c
_0809149A:
	adds r0, r5, #6
	str r3, [sp, #0x10]
	bl FUN_08090f0c
	ldr r3, [sp, #0x10]
	cmp r0, #0
	beq _080914D8
	ldr r0, _08091588 @ =0x00000F6C
	adds r2, r7, r0
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrb r1, [r6]
	lsls r1, r1, #2
	ldr r2, _08091558 @ =0x00004040
	adds r0, r7, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	strh r1, [r4]
	ldrb r1, [r6, #1]
	lsls r1, r1, #2
	adds r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	strh r1, [r4, #2]
	mov r0, r8
	strh r0, [r4, #4]
_080914D8:
	adds r4, #0x60
	adds r3, #0x60
	adds r6, #4
	adds r5, #1
	cmp r5, #7
	ble _0809149A
	ldr r0, [r7, #0x50]
	bl FUN_080478f0
	ldr r0, _08091590 @ =0x0000EFDA
	bl FUN_08047dc0
	movs r0, #1
	bl FUN_080477e4
	ldr r1, _0809152C @ =0x085ACE3C
	ldr r0, _08091530 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #3]
	bl FUN_08047a28
	ldr r1, _08091594 @ =FUN_0809107c
	adds r0, r7, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809152C: .4byte 0x085ACE3C
_08091530: .4byte 0x030046A0
_08091534: .4byte 0x00004052
_08091538: .4byte 0x00004054
_0809153C: .4byte 0x00000252
_08091540: .4byte 0x00004058
_08091544: .4byte 0x0000405A
_08091548: .4byte 0x00004044
_0809154C: .4byte 0x00004046
_08091550: .4byte 0x00004048
_08091554: .4byte 0x0000404A
_08091558: .4byte 0x00004040
_0809155C: .4byte 0x00004042
_08091560: .4byte 0x00002BEC
_08091564: .4byte 0x00002BE4
_08091568: .4byte 0x00002C04
_0809156C: .4byte 0x00002C06
_08091570: .4byte 0x00002C08
_08091574: .4byte 0x00002C4C
_08091578: .4byte 0x00002C64
_0809157C: .4byte 0x00002C66
_08091580: .4byte 0x00002C68
_08091584: .4byte 0x00002FC4
_08091588: .4byte 0x00000F6C
_0809158C: .4byte 0x00003204
_08091590: .4byte 0x0000EFDA
_08091594: .4byte FUN_0809107c
