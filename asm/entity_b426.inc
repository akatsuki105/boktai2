	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800f15c
FUN_0800f15c: @ 0x0800F15C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	movs r5, #0
	ldr r1, _0800F258 @ =0x000002DA
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r5, r2
	bge _0800F19E
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r7, r4, r3
	adds r6, r4, #0
	adds r6, #0x54
	mov ip, r5
	adds r3, r0, #0
_0800F184:
	lsls r2, r5, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r6, r2
	mov r0, ip
	strh r0, [r2]
	adds r5, #1
	ldrh r1, [r3]
	cmp r5, r1
	blt _0800F184
_0800F19E:
	ldr r2, _0800F258 @ =0x000002DA
	adds r0, r4, r2
	ldrh r5, [r0]
	movs r3, #0xb7
	lsls r3, r3, #2
	mov ip, r3
	adds r0, r4, r3
	ldr r1, _0800F25C @ =0x000002D6
	adds r1, r1, r4
	mov sl, r1
	subs r2, #2
	adds r2, r4, r2
	str r2, [sp]
	ldrh r0, [r0]
	cmp r5, r0
	bge _0800F210
	ldr r3, _0800F260 @ =0x0203B400
	mov sb, r3
	ldr r6, _0800F264 @ =0x030046B8
	ldr r0, _0800F25C @ =0x000002D6
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r7, r4, r1
_0800F1D0:
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _0800F268 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r2, r1, #0
	muls r2, r0, r2
	asrs r2, r2, #0x12
	lsls r3, r5, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r3, r3, r0
	adds r1, r4, #0
	adds r1, #0x54
	adds r1, r1, r3
	lsls r0, r2, #8
	orrs r2, r0
	strh r2, [r1]
	adds r5, #1
	mov r1, ip
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r5, r0
	blt _0800F1D0
_0800F210:
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r5, [r0]
	cmp r5, #0x9f
	bgt _0800F23E
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r6, r4, r3
	adds r3, r4, #0
	adds r3, #0x54
	movs r4, #0
_0800F228:
	lsls r2, r5, #1
	ldrh r1, [r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r3, r2
	strh r4, [r2]
	adds r5, #1
	cmp r5, #0x9f
	ble _0800F228
_0800F23E:
	mov r1, sl
	ldr r2, [sp]
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0800F26C
	movs r0, #0
	b _0800F274
	.align 2, 0
_0800F258: .4byte 0x000002DA
_0800F25C: .4byte 0x000002D6
_0800F260: .4byte 0x0203B400
_0800F264: .4byte 0x030046B8
_0800F268: .4byte 0x000003FF
_0800F26C:
	cmp r0, #0x80
	ble _0800F276
	movs r0, #0x80
	mov r1, sl
_0800F274:
	strh r0, [r1]
_0800F276:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800f288
FUN_0800f288: @ 0x0800F288
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0800F2B0
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	adds r1, r4, #0
	adds r1, #0x4e
	movs r5, #0
	ldrsh r1, [r1, r5]
	bl Div
	ldr r1, _0800F2E0 @ =0x03004040
	str r0, [r1]
_0800F2B0:
	adds r2, r4, #0
	adds r2, #0x48
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r1, r4, #0
	adds r1, #0x4e
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r1]
	movs r5, #0
	ldrsh r1, [r1, r5]
	cmp r0, r1
	ble _0800F2D8
	strh r3, [r2]
	movs r0, #0xb9
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
_0800F2D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800F2E0: .4byte 0x03004040

	thumb_func_start FUN_0800f2e4
FUN_0800f2e4: @ 0x0800F2E4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0800F30C
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	adds r1, r4, #0
	adds r1, #0x4e
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	ldr r1, _0800F340 @ =0x03004040
	str r0, [r1]
_0800F30C:
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	subs r0, #1
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0800F33A
	strh r2, [r1]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	str r2, [r0]
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0800F334
	movs r1, #0
	bl Script_ExecById
_0800F334:
	adds r0, r4, #0
	bl KillEntity
_0800F33A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F340: .4byte 0x03004040

	thumb_func_start EntityB426_Update
EntityB426_Update: @ 0x0800F344
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r3, r5, #0
	adds r3, #0x46
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _0800F35C
	ldr r0, _0800F3DC @ =0x0300445C
	ldr r1, _0800F3E0 @ =0x03004040
	ldr r1, [r1]
	str r1, [r0]
_0800F35C:
	adds r0, r5, #0
	adds r0, #0x44
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0800F3F4
	ldr r0, _0800F3E4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0800F3F4
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xeb
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3E8 @ =0x0000040C
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3EC @ =0x0000046C
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3F0 @ =0x000004CC
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	movs r1, #0
	ldrsh r2, [r3, r1]
	cmp r2, #0
	bne _0800F3C8
	ldr r1, _0800F3DC @ =0x0300445C
	ldr r0, _0800F3E0 @ =0x03004040
	str r2, [r0]
	str r2, [r1]
_0800F3C8:
	ldr r0, [r5, #0x40]
	cmp r0, #0
	beq _0800F3D4
	movs r1, #0
	bl Script_ExecById
_0800F3D4:
	adds r0, r5, #0
	bl KillEntity
	b _0800F506
	.align 2, 0
_0800F3DC: .4byte 0x0300445C
_0800F3E0: .4byte 0x03004040
_0800F3E4: .4byte 0x030044E0
_0800F3E8: .4byte 0x0000040C
_0800F3EC: .4byte 0x0000046C
_0800F3F0: .4byte 0x000004CC
_0800F3F4:
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r6, r5, r2
	ldr r1, [r6]
	cmp r1, #0
	beq _0800F406
	adds r0, r5, #0
	bl _call_via_r1
_0800F406:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r7, r5, r3
	ldr r1, [r7]
	cmp r1, #0
	beq _0800F43A
	adds r0, r5, #0
	bl _call_via_r1
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #6
	adds r2, #0x54
	adds r2, r5, r2
	movs r0, #0
	movs r1, #2
	bl Video_SetHBlankEffect
	ldrh r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r4]
_0800F43A:
	ldrh r2, [r5, #0x38]
	cmp r2, #1
	beq _0800F4A8
	cmp r2, #1
	bgt _0800F44A
	cmp r2, #0
	beq _0800F450
	b _0800F500
_0800F44A:
	cmp r2, #2
	beq _0800F4B4
	b _0800F500
_0800F450:
	ldrh r0, [r5, #0x3a]
	adds r0, #1
	strh r0, [r5, #0x3a]
	ldrh r1, [r5, #0x3a]
	adds r0, r5, #0
	adds r0, #0x4a
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	ble _0800F500
	movs r0, #1
	strh r0, [r5, #0x38]
	strh r2, [r5, #0x3a]
	ldr r0, _0800F498 @ =FUN_0800f288
	str r0, [r6]
	ldr r1, _0800F49C @ =0x000002DA
	adds r0, r5, r1
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0800F486
	movs r0, #0xe1
	bl PlaySound_082406e0
_0800F486:
	ldr r3, _0800F4A0 @ =0x000002D6
	adds r1, r5, r3
	movs r0, #0x80
	strh r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, _0800F4A4 @ =0x0000FFFE
	b _0800F4FA
	.align 2, 0
_0800F498: .4byte FUN_0800f288
_0800F49C: .4byte 0x000002DA
_0800F4A0: .4byte 0x000002D6
_0800F4A4: .4byte 0x0000FFFE
_0800F4A8:
	ldr r0, [r6]
	cmp r0, #0
	bne _0800F500
	movs r0, #2
	strh r0, [r5, #0x38]
	b _0800F500
_0800F4B4:
	ldrh r0, [r5, #0x3a]
	adds r0, #1
	movs r4, #0
	strh r0, [r5, #0x3a]
	ldrh r1, [r5, #0x3a]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble _0800F500
	movs r0, #3
	strh r0, [r5, #0x38]
	strh r4, [r5, #0x3a]
	ldr r0, _0800F510 @ =FUN_0800f2e4
	str r0, [r6]
	ldr r3, _0800F514 @ =0x000002DA
	adds r0, r5, r3
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0800F4EC
	movs r0, #0xe3
	bl PlaySound_082406e0
_0800F4EC:
	ldr r3, _0800F518 @ =0x000002D6
	adds r0, r5, r3
	strh r4, [r0]
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #4
_0800F4FA:
	strh r0, [r1]
	ldr r0, _0800F51C @ =FUN_0800f15c
	str r0, [r7]
_0800F500:
	ldr r0, [r5, #0x3c]
	adds r0, #1
	str r0, [r5, #0x3c]
_0800F506:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F510: .4byte FUN_0800f2e4
_0800F514: .4byte 0x000002DA
_0800F518: .4byte 0x000002D6
_0800F51C: .4byte FUN_0800f15c

	thumb_func_start EntityB426_Destroy
EntityB426_Destroy: @ 0x0800F520
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0822f0d8
	bl Video_ClearMosaic
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _0800F570 @ =0x0000040C
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r0, _0800F574 @ =0x0000046C
	adds r4, r4, r0
	movs r5, #1
_0800F558:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0800F558
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800F570: .4byte 0x0000040C
_0800F574: .4byte 0x0000046C

	thumb_func_start EntityB426_Init
EntityB426_Init: @ 0x0800F578
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r5, r0, #0
	ldr r1, _0800F5D4 @ =0x03004250
	movs r4, #0
	ldr r0, _0800F5D8 @ =0x00001084
	strh r0, [r1]
	ldr r1, _0800F5DC @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	str r4, [sp, #0x10]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	adds r0, r5, #0
	adds r0, #0x48
	strh r4, [r0]
	strh r4, [r5, #0x38]
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x44
	strh r0, [r1]
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x46
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800F5E0
	adds r1, #4
	movs r0, #0x40
	strh r0, [r1]
	b _0800F5E6
	.align 2, 0
_0800F5D4: .4byte 0x03004250
_0800F5D8: .4byte 0x00001084
_0800F5DC: .4byte 0xFFFF0000
_0800F5E0:
	adds r0, r5, #0
	adds r0, #0x4a
	strh r4, [r0]
_0800F5E6:
	adds r1, r5, #0
	adds r1, #0x4e
	movs r0, #0x40
	strh r0, [r1]
	movs r0, #0x64
	movs r1, #0x80
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x4c
	strh r0, [r1]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x20]
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x73
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r5, #0x40]
	movs r0, #0x6f
	adds r1, r4, #0
	bl VM_GetKeywordValue
	ldr r2, _0800F688 @ =0x000002DE
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x74
	adds r1, r4, #0
	bl VM_GetKeywordValue
	ldr r3, _0800F68C @ =0x000002DF
	adds r1, r5, r3
	strb r0, [r1]
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0xb8
	lsls r4, r4, #2
	adds r1, r5, r4
	strb r0, [r1]
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800F662
	bl FUN_0823d340
_0800F662:
	str r0, [r5, #0x50]
	movs r0, #0x79
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0800F694
	bl Script_GetValue
	ldr r7, _0800F690 @ =0x000002DA
	adds r1, r5, r7
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	b _0800F6A2
	.align 2, 0
_0800F688: .4byte 0x000002DE
_0800F68C: .4byte 0x000002DF
_0800F690: .4byte 0x000002DA
_0800F694:
	ldr r3, _0800F6B8 @ =0x000002DA
	adds r0, r5, r3
	strh r1, [r0]
	movs r4, #0xb7
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
_0800F6A2:
	ldr r0, _0800F6BC @ =0x0000CB05
	ldr r1, _0800F6C0 @ =0x0000E89F
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0800F6C4
	movs r0, #1
	rsbs r0, r0, #0
	b _0800F942
	.align 2, 0
_0800F6B8: .4byte 0x000002DA
_0800F6BC: .4byte 0x0000CB05
_0800F6C0: .4byte 0x0000E89F
_0800F6C4:
	adds r0, r5, #0
	adds r0, #0x18
	adds r1, r2, #0
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldm r1!, {r3, r7}
	stm r0!, {r3, r7}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	mov sl, r4
	cmp r6, #0
	blt _0800F710
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r5, r4
	adds r2, r6, #0
	adds r2, #0x17
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0x87
	lsls r3, r3, #4
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	bl FUN_0822f3fc
	b _0800F72E
_0800F710:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _0800F7D4 @ =0x00000871
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sl
	movs r2, #0x17
	bl FUN_0822f3fc
_0800F72E:
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r4, _0800F7D4 @ =0x00000871
	mov r8, r4
	movs r6, #0
	str r6, [sp]
	str r6, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	movs r2, #0x16
	mov r3, r8
	bl FUN_0822f3fc
	mov r0, sb
	cmp r0, #0
	beq _0800F766
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F766:
	ldr r2, _0800F7D8 @ =0x0000040C
	adds r1, r5, r2
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r7, r5, r3
	movs r0, #0
	ldrsb r0, [r7, r0]
	movs r2, #1
	cmp r0, #0
	beq _0800F77C
	movs r2, #0x26
_0800F77C:
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r0, r1, #0
	mov r1, sl
	mov r3, r8
	bl FUN_0822f3fc
	ldr r0, _0800F7DC @ =0x000002DE
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0800F7E4
	ldr r1, _0800F7E0 @ =0x00000414
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0xa
	bl Mod
	str r0, [sp, #0x18]
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0xa
	bl Div
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldr r0, [sp, #0x18]
	adds r0, #2
	str r0, [sp, #0x18]
	ldr r0, [r1, #4]
	adds r0, #0xc
	str r0, [r1, #4]
	adds r0, r1, #0
	b _0800F804
	.align 2, 0
_0800F7D4: .4byte 0x00000871
_0800F7D8: .4byte 0x0000040C
_0800F7DC: .4byte 0x000002DE
_0800F7E0: .4byte 0x00000414
_0800F7E4:
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	beq _0800F7FA
	ldr r2, _0800F8EC @ =0x00000414
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F7FA:
	movs r0, #2
	str r0, [sp, #0x18]
	movs r1, #0xc
	add r0, sp, #0x18
	str r1, [r0, #4]
_0800F804:
	adds r3, r5, #0
	adds r3, #0x46
	str r3, [sp, #0x24]
	adds r6, r0, #0
	ldr r7, _0800F8F0 @ =0x0000046C
	adds r4, r5, r7
	movs r0, #0
	mov sb, r0
	movs r1, #1
	mov r8, r1
_0800F818:
	ldrh r2, [r6]
	movs r7, #0
	str r7, [sp]
	str r7, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sl
	ldr r3, _0800F8F4 @ =0x00000871
	bl FUN_0822f3fc
	ldr r1, _0800F8F8 @ =0x000002DE
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0800F850
	ldr r2, _0800F8FC @ =0x00000474
	adds r0, r5, r2
	add r0, sb
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F850:
	adds r6, #4
	adds r4, #0x60
	movs r3, #0x60
	add sb, r3
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _0800F818
	ldr r2, _0800F900 @ =0x000002DF
	adds r6, r5, r2
	movs r0, #0
	ldrsb r0, [r6, r0]
	movs r2, #0
	cmp r0, #0
	blt _0800F874
	adds r2, r0, #0
_0800F874:
	movs r3, #0xeb
	lsls r3, r3, #2
	adds r0, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _0800F8F4 @ =0x00000871
	str r7, [sp]
	str r7, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	bl FUN_0822f3fc
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	blt _0800F8AA
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F8AA:
	ldr r0, [r5, #0x50]
	cmp r0, #0
	beq _0800F90C
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _0800F904 @ =0x0000539C
	bl FUN_08047dc0
	ldr r0, [r5, #0x50]
	bl FUN_080478f0
	ldr r0, [sp, #0x20]
	bl FUN_08047a28
	movs r0, #0
	movs r1, #7
	movs r2, #0x1a
	movs r3, #2
	bl FUN_08047b8c
	bl FUN_080488dc
	ldr r1, _0800F908 @ =0x03003ED0
	lsls r0, r0, #2
	subs r0, #0x78
	strh r0, [r1, #0x20]
	movs r0, #0
	movs r1, #0
	movs r2, #0x11
	bl Video_SetMosaic
	b _0800F916
	.align 2, 0
_0800F8EC: .4byte 0x00000414
_0800F8F0: .4byte 0x0000046C
_0800F8F4: .4byte 0x00000871
_0800F8F8: .4byte 0x000002DE
_0800F8FC: .4byte 0x00000474
_0800F900: .4byte 0x000002DF
_0800F904: .4byte 0x0000539C
_0800F908: .4byte 0x03003ED0
_0800F90C:
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Video_SetMosaic
_0800F916:
	ldr r2, [sp, #0x24]
	movs r4, #0
	ldrsh r3, [r2, r4]
	cmp r3, #0
	bne _0800F940
	ldr r0, _0800F954 @ =0x03004040
	str r3, [r0]
	ldr r0, _0800F958 @ =0x03004494
	ldr r7, _0800F95C @ =0x00001084
	adds r2, r7, #0
	strh r2, [r0]
	ldr r1, _0800F960 @ =0x03004454
	ldr r4, _0800F964 @ =0x0000FFFF
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _0800F968 @ =0x0300445C
	str r3, [r0]
	ldr r0, _0800F96C @ =0x03004464
	strh r2, [r0]
	ldr r0, _0800F970 @ =0x03004490
	strh r3, [r0]
_0800F940:
	movs r0, #0
_0800F942:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F954: .4byte 0x03004040
_0800F958: .4byte 0x03004494
_0800F95C: .4byte 0x00001084
_0800F960: .4byte 0x03004454
_0800F964: .4byte 0x0000FFFF
_0800F968: .4byte 0x0300445C
_0800F96C: .4byte 0x03004464
_0800F970: .4byte 0x03004490

	thumb_func_start EntityB426_Create
EntityB426_Create: @ 0x0800F974
	push {r4, lr}
	ldr r1, _0800F9A0 @ =0x0000052C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800F9AC
	ldr r1, _0800F9A4 @ =EntityB426_Update
	ldr r2, _0800F9A8 @ =EntityB426_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB426_Init
	cmp r0, #0
	bge _0800F9AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800F9AE
	.align 2, 0
_0800F9A0: .4byte 0x0000052C
_0800F9A4: .4byte EntityB426_Update
_0800F9A8: .4byte EntityB426_Destroy
_0800F9AC:
	adds r0, r4, #0
_0800F9AE:
	pop {r4}
	pop {r1}
	bx r1
