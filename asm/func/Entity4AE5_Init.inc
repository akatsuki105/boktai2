	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08002440 @ =gEntity4AE5
	str r6, [r0]
	movs r5, #0
	movs r4, #0
	strh r1, [r6, #0x18]
	ldr r0, _08002444 @ =0x03004250
	str r0, [r6, #0x2c]
	ldr r0, _08002448 @ =0x03004040
	movs r1, #0x40
	str r1, [r0]
	ldr r0, _0800244C @ =0x03004048
	str r1, [r0]
	ldr r1, _08002450 @ =0x03004494
	ldr r2, _08002454 @ =0x00001084
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _08002458 @ =0x03004454
	strh r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r6, #0x1a]
	strb r5, [r6, #0x1d]
	movs r3, #0xc9
	lsls r3, r3, #3
	adds r0, r6, r3
	strh r4, [r0]
	strb r5, [r6, #0x1b]
	movs r0, #7
	strb r0, [r6, #0x1e]
	movs r0, #4
	strb r0, [r6, #0x1f]
	movs r0, #0x70
	bl prepare_08231510
	mov r5, sp
	adds r5, #2
	cmp r0, #0
	beq _08002478
	b _0800246C
	.align 2, 0
_08002440: .4byte gEntity4AE5
_08002444: .4byte 0x03004250
_08002448: .4byte 0x03004040
_0800244C: .4byte 0x03004048
_08002450: .4byte 0x03004494
_08002454: .4byte 0x00001084
_08002458: .4byte 0x03004454
_0800245C:
	bl Script_GetValue
	lsls r2, r4, #1
	ldr r3, _080024F4 @ =0x00000634
	adds r1, r6, r3
	adds r1, r1, r2
	strh r0, [r1]
	adds r4, #1
_0800246C:
	bl VM_GetPC
	cmp r0, #0
	beq _08002478
	cmp r4, #3
	ble _0800245C
_08002478:
	ldr r1, _080024F8 @ =0x0000063C
	adds r0, r6, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	ldr r3, _080024FC @ =0x0000063E
	adds r0, r6, r3
	strh r1, [r0]
	strb r2, [r6, #0x1c]
	ldr r0, _08002500 @ =0x0000064E
	adds r7, r6, r0
	strh r1, [r7]
	movs r1, #0xc8
	lsls r1, r1, #3
	adds r4, r6, r1
	strb r2, [r4]
	ldrb r1, [r6, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08002510
	mov r0, sp
	adds r1, r5, #0
	bl FUN_0823ce10
	movs r0, #0x40
	strb r0, [r4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldr r2, _080024F4 @ =0x00000634
	adds r4, r6, r2
	adds r0, r4, r0
	ldrh r1, [r0]
	ldr r0, _08002504 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x24]
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	ldr r0, _08002504 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x28]
	adds r0, r6, #0
	bl FUN_08001b58
	ldr r1, _08002508 @ =gClock
	ldrb r0, [r1, #0xf]
	strh r0, [r7]
	ldrb r1, [r1, #0xe]
	ldr r3, _0800250C @ =0x0000064C
	adds r0, r6, r3
	strh r1, [r0]
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r6, r1
	b _08002612
	.align 2, 0
_080024F4: .4byte 0x00000634
_080024F8: .4byte 0x0000063C
_080024FC: .4byte 0x0000063E
_08002500: .4byte 0x0000064E
_08002504: .4byte 0x000092B3
_08002508: .4byte gClock
_0800250C: .4byte 0x0000064C
_08002510:
	movs r7, #2
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _0800251C
	b _08002638
_0800251C:
	mov r4, sp
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r4]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldr r2, _080025A8 @ =0x00000634
	adds r4, r6, r2
	adds r0, r4, r0
	ldrh r1, [r0]
	ldr r0, _080025AC @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x24]
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	ldr r0, _080025AC @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x28]
	movs r0, #0x61
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080025C4
	bl Script_GetValue
	ldr r3, _080025B0 @ =0x00000652
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080025B4 @ =0x00000656
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _080025B8 @ =0x00000659
	adds r1, r6, r3
	strb r0, [r1]
	bl Script_GetValue
	ldr r2, _080025BC @ =0x0000065C
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xcc
	lsls r3, r3, #3
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080025C0 @ =0x00000662
	adds r1, r6, r2
	strh r0, [r1]
	b _080025F0
	.align 2, 0
_080025A8: .4byte 0x00000634
_080025AC: .4byte 0x000092B3
_080025B0: .4byte 0x00000652
_080025B4: .4byte 0x00000656
_080025B8: .4byte 0x00000659
_080025BC: .4byte 0x0000065C
_080025C0: .4byte 0x00000662
_080025C4:
	ldr r3, _0800261C @ =0x00000652
	adds r1, r6, r3
	movs r0, #4
	strh r0, [r1]
	ldr r1, _08002620 @ =0x00000656
	adds r0, r6, r1
	strh r7, [r0]
	adds r3, #7
	adds r1, r6, r3
	movs r0, #8
	strb r0, [r1]
	ldr r0, _08002624 @ =0x0000065C
	adds r1, r6, r0
	ldr r0, _08002628 @ =0x0000FFFF
	strh r0, [r1]
	adds r3, #7
	adds r1, r6, r3
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0800262C @ =0x00000662
	adds r0, r6, r1
	strh r2, [r0]
_080025F0:
	movs r2, #0xca
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	ldr r3, _08002630 @ =0x00000654
	adds r0, r6, r3
	strh r1, [r0]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r2, [r0]
	adds r3, #6
	adds r0, r6, r3
	strb r2, [r0]
	ldr r0, [r6, #0x24]
_08002612:
	ldr r1, [r6, #0x2c]
	ldr r2, _08002634 @ =0x04000068
	bl CpuSet
	b _08002682
	.align 2, 0
_0800261C: .4byte 0x00000652
_08002620: .4byte 0x00000656
_08002624: .4byte 0x0000065C
_08002628: .4byte 0x0000FFFF
_0800262C: .4byte 0x00000662
_08002630: .4byte 0x00000654
_08002634: .4byte 0x04000068
_08002638:
	mov r4, sp
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r4]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldr r1, _0800269C @ =0x00000634
	adds r4, r6, r1
	adds r0, r4, r0
	ldrh r1, [r0]
	ldr r0, _080026A0 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x24]
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	ldr r0, _080026A0 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x28]
	ldr r0, [r6, #0x24]
	ldr r1, [r6, #0x2c]
	ldr r2, _080026A4 @ =0x04000068
	bl CpuSet
_08002682:
	ldr r2, _080026A8 @ =0x00000644
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	adds r1, r6, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800269C: .4byte 0x00000634
_080026A0: .4byte 0x000092B3
_080026A4: .4byte 0x04000068
_080026A8: .4byte 0x00000644
