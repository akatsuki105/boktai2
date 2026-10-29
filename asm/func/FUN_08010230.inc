	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r6, r4, r0
	ldrh r5, [r6]
	cmp r5, #0
	bne _080102A0
	movs r0, #0xe1
	bl PlaySound_082406e0
	ldr r2, _0801032C @ =0x000002C2
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
	movs r7, #0xb1
	lsls r7, r7, #2
	adds r1, r4, r7
	movs r0, #5
	strh r0, [r1]
	ldr r0, _08010330 @ =0x000002C6
	adds r1, r4, r0
	ldr r0, _08010334 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #8
	adds r0, r4, r2
	movs r2, #4
	strh r2, [r0]
	adds r7, #0xc
	adds r1, r4, r7
	ldr r0, _08010338 @ =Entity329B_FadeToColor
	str r0, [r1]
	ldr r1, _0801033C @ =0x000002B2
	adds r0, r4, r1
	strh r5, [r0]
	subs r7, #0x1c
	adds r1, r4, r7
	movs r0, #0x74
	strh r0, [r1]
	ldr r1, _08010340 @ =0x000002AE
	adds r0, r4, r1
	strh r5, [r0]
	movs r5, #0xac
	lsls r5, r5, #2
	adds r0, r4, r5
	strh r2, [r0]
	adds r7, #0x20
	adds r1, r4, r7
	ldr r0, _08010344 @ =Entity329B_UpdateMosaic
	str r0, [r1]
_080102A0:
	ldrh r0, [r6]
	cmp r0, #0x30
	bne _080102E8
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl Entity329B_GetTilePtr
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _08010348 @ =0x03003ED0
	mov r8, r0
	mov ip, r8
_080102BA:
	movs r2, #0
	mov r5, ip
	movs r6, #0x18
	ldrsh r0, [r5, r6]
	lsls r0, r0, #1
	adds r5, r3, #1
	cmp r2, r0
	bge _080102E2
	movs r7, #0xd0
	lsls r7, r7, #8
	adds r6, r7, #0
	mov r3, r8
_080102D2:
	strh r6, [r1]
	adds r1, #2
	adds r2, #1
	movs r7, #0x18
	ldrsh r0, [r3, r7]
	lsls r0, r0, #1
	cmp r2, r0
	blt _080102D2
_080102E2:
	adds r3, r5, #0
	cmp r3, #0xe
	ble _080102BA
_080102E8:
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08010318
	ldr r1, _0801034C @ =FUN_0801019c
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r0, r4, r5
	str r1, [r0]
	movs r6, #0xb6
	lsls r6, r6, #2
	adds r1, r4, r6
	movs r0, #0
	strh r0, [r1]
_08010318:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801032C: .4byte 0x000002C2
_08010330: .4byte 0x000002C6
_08010334: .4byte 0x00001084
_08010338: .4byte Entity329B_FadeToColor
_0801033C: .4byte 0x000002B2
_08010340: .4byte 0x000002AE
_08010344: .4byte Entity329B_UpdateMosaic
_08010348: .4byte 0x03003ED0
_0801034C: .4byte FUN_0801019c
