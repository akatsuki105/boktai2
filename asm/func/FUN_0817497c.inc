	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _0817499C @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081749A0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081749A2
	.align 2, 0
_0817499C: .4byte 0x0000046C
_081749A0:
	movs r0, #0
_081749A2:
	cmp r0, #0
	beq _08174A54
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r2, [r0]
	movs r1, #1
	ldr r4, _08174A9C @ =0x0000046D
	adds r0, r6, r4
	movs r3, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r3, [r0]
	subs r4, #0xe1
	adds r5, r6, r4
	ldrh r0, [r5]
	strh r0, [r6, #0xa]
	ldr r0, _08174AA0 @ =0x00000474
	adds r2, r6, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r6, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08174AA4 @ =0x00001008
	adds r2, r7, r1
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x2a
	strh r0, [r1]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r3, [r0]
	adds r4, r6, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08176698
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08176530
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _08174AA8 @ =0xFFFFF818
	adds r1, r0, #0
	ldrh r5, [r5]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	ldr r2, _08174AAC @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sp
	bl FUN_08177f7c
	ldr r0, _08174AB0 @ =0x000003E3
	bl PlaySound_082406e0
_08174A54:
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08174ABC
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x10
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08174AB4 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	ldr r2, _08174AB8 @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _08174AD8
	.align 2, 0
_08174A9C: .4byte 0x0000046D
_08174AA0: .4byte 0x00000474
_08174AA4: .4byte 0x00001008
_08174AA8: .4byte 0xFFFFF818
_08174AAC: .4byte 0x0000FFFF
_08174AB0: .4byte 0x000003E3
_08174AB4: .4byte 0x00000469
_08174AB8: .4byte 0x00000484
_08174ABC:
	ldr r3, _08174AE0 @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #4
	movs r2, #4
	bl FUN_08177d34
	adds r0, r7, #0
	bl FUN_08176c60
	ldr r4, _08174AE4 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08174AD8:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08174AE0: .4byte 0x0000FFFF
_08174AE4: .4byte 0x00000484
