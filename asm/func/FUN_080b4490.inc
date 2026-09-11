	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	ldr r4, _080B4710 @ =0x0000CB05
	ldr r1, _080B4714 @ =0x000092F0
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, r8
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	mov r6, r8
	adds r6, #0x18
	adds r0, r6, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080B4718 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	mov r1, r8
	adds r1, #0x38
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r7, r8
	adds r7, #0x38
	adds r0, r7, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080B471C @ =0xFFFF0000
	movs r5, #0
	str r5, [sp, #0x10]
	mov r0, sp
	adds r0, #0x10
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	mov r0, r8
	adds r0, #0x58
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	mov sl, r1
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r4, _080B4720 @ =0x030046A0
	ldr r0, [r4]
	ldr r3, _080B4724 @ =0x0000023A
	mov sb, r3
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080B4550
	bl GetSecond
	adds r1, r0, #0
	ldr r0, [r4]
	movs r2, #0xad
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	eors r0, r1
	movs r1, #0xd
	bl Mod
	ldr r1, [r4]
	ldr r3, _080B4724 @ =0x0000023A
	adds r1, r1, r3
	adds r0, #0x41
	strh r0, [r1]
_080B4550:
	ldr r0, [r4]
	add r0, sb
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x64
	adds r4, r1, #0
	muls r4, r0, r4
	asrs r4, r4, #6
	subs r4, #0x64
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r2, r0, #0
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	subs r4, r4, r0
	movs r0, #0x8c
	lsls r0, r0, #1
	add r0, r8
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r5, [sp]
	str r5, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r1, r6, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	adds r4, #8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r5, [sp]
	str r5, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	adds r2, r4, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r5, [r0]
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, r8
	str r5, [sp]
	str r5, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x12
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, _080B4728 @ =0x0000FFF8
	ldr r6, [sp, #0x18]
	strh r0, [r6, #2]
	mov r0, r8
	adds r0, #0xb8
	str r5, [sp]
	str r5, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #0x94
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r1, #0x28
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r6, #2]
	mov sb, r7
	adds r5, r0, #0
	movs r4, #0x8e
	lsls r4, r4, #2
	add r4, r8
	movs r6, #0
	movs r7, #3
_080B4616:
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r5]
	adds r0, #8
	strh r0, [r5]
	adds r4, #0x60
	subs r7, #1
	cmp r7, #0
	bge _080B4616
	movs r1, #0x88
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x28
	strh r0, [r1, #2]
	adds r5, r1, #0
	movs r4, #0xee
	lsls r4, r4, #2
	add r4, r8
	movs r6, #0
	movs r7, #3
_080B4652:
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r5]
	adds r0, #8
	strh r0, [r5]
	adds r4, #0x60
	subs r7, #1
	cmp r7, #0
	bge _080B4652
	movs r7, #0
	movs r3, #0xa7
	lsls r3, r3, #3
	add r3, r8
	mov sb, r3
	movs r4, #0x38
	mov sl, r4
	movs r6, #0xb2
	lsls r6, r6, #3
	add r6, r8
_080B468A:
	adds r0, r6, #0
	ldr r1, _080B472C @ =0x0000A47C
	bl Video_GetActorSprite
	movs r0, #0x2c
	adds r4, r7, #0
	muls r4, r0, r4
	movs r5, #0xa7
	lsls r5, r5, #3
	adds r0, r4, r5
	add r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	mov r0, r8
	adds r5, r0, r4
	ldr r1, _080B4730 @ =0x0000053F
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	add r4, sb
	movs r0, #0x30
	str r0, [r4]
	cmp r7, #0
	bne _080B46C8
	mov r3, sb
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
_080B46C8:
	cmp r7, #1
	bne _080B46D8
	ldr r0, _080B4734 @ =0x000005AC
	add r0, r8
	movs r1, #0xa0
	lsls r1, r1, #1
	bl Video_SetActorSpritePltt
_080B46D8:
	ldr r4, _080B4738 @ =0x00000554
	adds r0, r5, r4
	mov r1, sl
	strh r1, [r0]
	ldr r2, _080B473C @ =0x00000556
	adds r1, r5, r2
	movs r0, #0x58
	strh r0, [r1]
	movs r3, #0xab
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r4, #0
	strh r4, [r0]
	movs r5, #0x60
	add sl, r5
	adds r6, #0x1c
	adds r7, #1
	cmp r7, #1
	ble _080B468A
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B4710: .4byte 0x0000CB05
_080B4714: .4byte 0x000092F0
_080B4718: .4byte 0x0000B343
_080B471C: .4byte 0xFFFF0000
_080B4720: .4byte 0x030046A0
_080B4724: .4byte 0x0000023A
_080B4728: .4byte 0x0000FFF8
_080B472C: .4byte 0x0000A47C
_080B4730: .4byte 0x0000053F
_080B4734: .4byte 0x000005AC
_080B4738: .4byte 0x00000554
_080B473C: .4byte 0x00000556
