	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	adds r6, r0, #0
	mov sb, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, [r6, #0x44]
	mov r8, r2
	ldr r3, _0819D2B0 @ =0x0000046D
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819D2B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819D2B6
	.align 2, 0
_0819D2B0: .4byte 0x0000046D
_0819D2B4:
	movs r0, #0
_0819D2B6:
	cmp r0, #0
	beq _0819D320
	adds r0, r6, #0
	movs r1, #0xa
	bl Enemy_PlayAnimNoFacing
	adds r0, r6, #0
	bl PlayEnemyDeathCry
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r6, r4
	ldr r1, _0819D380 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0819D384 @ =0x0000021E
	adds r0, r6, r1
	movs r3, #0
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	adds r4, #0x8a
	adds r0, r6, r4
	strh r1, [r0]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r6, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _0819D388 @ =0x00000474
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0819D38C @ =0x00000ECE
	adds r0, r7, r2
	strb r3, [r0]
	adds r0, r6, #0
	bl Ax_RemoveClone
_0819D320:
	mov r0, sb
	movs r1, #2
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	beq _0819D330
	b _0819D518
_0819D330:
	ldr r2, _0819D390 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _0819D394 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x34]
	add r4, sp, #0x34
	ldr r0, [r4, #4]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [r4, #4]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp, #0x44]
	str r1, [sp, #0x48]
	add r5, sp, #0x3c
	str r3, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0819D398 @ =0x05000002
	bl CpuSet
	ldr r3, _0819D38C @ =0x00000ECE
	adds r0, r7, r3
	ldrb r0, [r0]
	mov sl, r4
	cmp r0, #4
	bhi _0819D430
	lsls r0, r0, #2
	ldr r1, _0819D39C @ =_0819D3A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0819D380: .4byte 0xFFFEBE3F
_0819D384: .4byte 0x0000021E
_0819D388: .4byte 0x00000474
_0819D38C: .4byte 0x00000ECE
_0819D390: .4byte 0xFFFF0000
_0819D394: .4byte 0x0000FFFF
_0819D398: .4byte 0x05000002
_0819D39C: .4byte _0819D3A0
_0819D3A0: @ jump table
	.4byte _0819D3B4 @ case 0
	.4byte _0819D3D8 @ case 1
	.4byte _0819D3F0 @ case 2
	.4byte _0819D408 @ case 3
	.4byte _0819D420 @ case 4
_0819D3B4:
	ldr r1, _0819D3D0 @ =0x0000FF88
	strh r1, [r5]
	add r0, sp, #0x3c
	strh r1, [r0, #4]
	ldr r4, _0819D3D4 @ =0x00000ECE
	adds r1, r7, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xb7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0819D430
	.align 2, 0
_0819D3D0: .4byte 0x0000FF88
_0819D3D4: .4byte 0x00000ECE
_0819D3D8:
	ldr r1, _0819D3E8 @ =0x0000FFB5
	strh r1, [r5]
	add r0, sp, #0x3c
	strh r1, [r0, #4]
	ldr r0, _0819D3EC @ =0x00000ECE
	adds r1, r7, r0
	b _0819D414
	.align 2, 0
_0819D3E8: .4byte 0x0000FFB5
_0819D3EC: .4byte 0x00000ECE
_0819D3F0:
	ldr r1, _0819D400 @ =0x0000FFE2
	strh r1, [r5]
	add r0, sp, #0x3c
	strh r1, [r0, #4]
	ldr r2, _0819D404 @ =0x00000ECE
	adds r1, r7, r2
	b _0819D414
	.align 2, 0
_0819D400: .4byte 0x0000FFE2
_0819D404: .4byte 0x00000ECE
_0819D408:
	movs r1, #0xf
	strh r1, [r5]
	add r0, sp, #0x3c
	strh r1, [r0, #4]
	ldr r3, _0819D41C @ =0x00000ECE
	adds r1, r7, r3
_0819D414:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0819D430
	.align 2, 0
_0819D41C: .4byte 0x00000ECE
_0819D420:
	movs r2, #0
	movs r1, #0x3c
	strh r1, [r5]
	add r0, sp, #0x3c
	strh r1, [r0, #4]
	ldr r4, _0819D454 @ =0x00000ECE
	adds r0, r7, r4
	strb r2, [r0]
_0819D430:
	movs r7, #0
	ldrsh r3, [r5, r7]
	ldr r2, _0819D458 @ =gSineTable
	mov r1, r8
	ldrb r0, [r1, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r3, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _0819D45C
	asrs r0, r0, #0xc
	b _0819D462
	.align 2, 0
_0819D454: .4byte 0x00000ECE
_0819D458: .4byte gSineTable
_0819D45C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819D462:
	adds r2, r0, #0
	movs r7, #4
	ldrsh r0, [r5, r7]
	mov r3, r8
	ldrb r1, [r3, #6]
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r7, #0
	ldrsh r1, [r1, r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819D47E
	asrs r0, r0, #0xc
	b _0819D484
_0819D47E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819D484:
	add r3, sp, #0x44
	adds r1, r2, r0
	ldrh r0, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819D4B8 @ =0xFFFF0000
	ldr r0, [sp, #0x44]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x44]
	movs r2, #0
	ldrsh r1, [r5, r2]
	mov r7, r8
	ldrb r0, [r7, #6]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _0819D4BC
	asrs r0, r0, #0xc
	b _0819D4C0
	.align 2, 0
_0819D4B8: .4byte 0xFFFF0000
_0819D4BC:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_0819D4C0:
	adds r7, r0, #0
	movs r0, #4
	ldrsh r2, [r5, r0]
	mov r1, r8
	ldrb r0, [r1, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	cmp r0, #0
	blt _0819D4E2
	asrs r0, r0, #0xc
	b _0819D4E8
_0819D4E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819D4E8:
	adds r1, r7, r0
	ldrh r7, [r3, #4]
	adds r1, r1, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819D5C4 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #2
	mov r2, sl
	movs r3, #0
	bl EmitSmoke
_0819D518:
	ldr r0, [r6, #0x44]
	mov r1, sb
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0819D52C
	b _0819D640
_0819D52C:
	ldr r1, _0819D5C8 @ =0x0000046B
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_080e6658
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0819D59C
	movs r7, #8
	ldrsh r0, [r6, r7]
	str r0, [sp, #0x14]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	str r0, [sp, #0x18]
	movs r3, #0xc
	ldrsh r0, [r6, r3]
	str r0, [sp, #0x1c]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x28]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	ldrh r0, [r6]
	str r0, [sp, #0x30]
	ldr r1, _0819D5C4 @ =0xFFFF0000
	ldr r0, [sp, #0x4c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x4c]
	add r0, sp, #0x14
	add r1, sp, #0x4c
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_0819D59C:
	ldr r1, _0819D5CC @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0819D5D4
	ldr r0, _0819D5D0 @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _0819D5E6
	.align 2, 0
_0819D5C4: .4byte 0xFFFF0000
_0819D5C8: .4byte 0x0000046B
_0819D5CC: .4byte 0x000001DF
_0819D5D0: .4byte 0x030046A0
_0819D5D4:
	ldr r0, _0819D650 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0819D5E6:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _0819D654 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	ldr r7, _0819D658 @ =0x0000046D
	adds r0, r6, r7
	movs r1, #1
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r3, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _0819D65C @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _0819D660 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
_0819D640:
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819D650: .4byte 0x030046A0
_0819D654: .4byte Enemy_ClearStateBegun
_0819D658: .4byte 0x0000046D
_0819D65C: .4byte 0x00000469
_0819D660: .4byte 0x00000484
