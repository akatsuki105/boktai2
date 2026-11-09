	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r2, _08193DE8 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08193DEC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08193DEE
	.align 2, 0
_08193DE8: .4byte 0x0000046C
_08193DEC:
	movs r0, #0
_08193DEE:
	cmp r0, #0
	beq _08193E76
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	movs r3, #0
	strb r0, [r7, #5]
	ldr r4, _08193E44 @ =FUN_08189614
	movs r2, #0x25
	ldr r0, _08193E48 @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08193E4C @ =0x0000046B
	adds r0, r7, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r3, [r0]
	movs r6, #1
	ldr r0, _08193E50 @ =0x0000077A
	adds r3, r5, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r5, r1
	movs r5, #0x92
	lsls r5, r5, #1
	movs r4, #4
_08193E38:
	ldrh r0, [r3]
	ands r0, r6
	cmp r0, #0
	beq _08193E54
	movs r0, #1
	b _08193E56
	.align 2, 0
_08193E44: .4byte FUN_08189614
_08193E48: .4byte 0x0000046D
_08193E4C: .4byte 0x0000046B
_08193E50: .4byte 0x0000077A
_08193E54:
	movs r0, #0
_08193E56:
	cmp r0, #0
	bne _08193E64
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_08193E64:
	adds r3, r3, r5
	adds r2, r2, r5
	subs r4, #1
	cmp r4, #0
	bge _08193E38
	adds r0, r7, #0
	movs r1, #3
	bl FUN_08191ca0
_08193E76:
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r7, #0
	movs r1, #4
	movs r2, #0xc
	bl FUN_0818fdd8
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08193E9A
	movs r1, #5
	bl Mod
	cmp r0, #0
	bne _08193EA2
_08193E9A:
	adds r0, r7, #0
	movs r1, #3
	bl FUN_08191ca0
_08193EA2:
	ldr r3, _08193F6C @ =0x0000046B
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08193F8C
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _08193F70 @ =0x00000472
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_08191a14
	ldr r0, _08193F74 @ =0x000001DF
	bl PlaySound_082406e0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _08193F78 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0818e6fc
	mov r2, sp
	ldr r1, _08193F7C @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	movs r6, #0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #4
	ldrsh r1, [r2, r4]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	movs r1, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	ldr r4, _08193F80 @ =0x00000469
	adds r0, r7, r4
	strb r5, [r0]
	ldr r2, _08193F84 @ =0x0000046A
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r6, [r0]
	adds r4, #3
	adds r0, r7, r4
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08193F88 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r4, #1
	adds r0, r7, r4
	strb r1, [r0]
	ldr r1, _08193F6C @ =0x0000046B
	adds r0, r7, r1
	strb r5, [r0]
	adds r4, #0xe6
	adds r0, r7, r4
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r3, #0xaa
	lsls r3, r3, #2
	adds r0, r7, r3
	bl AuxShadow_Hide
	b _08193F96
	.align 2, 0
_08193F6C: .4byte 0x0000046B
_08193F70: .4byte 0x00000472
_08193F74: .4byte 0x000001DF
_08193F78: .4byte 0xFFEFFFFF
_08193F7C: .4byte 0x000004A4
_08193F80: .4byte 0x00000469
_08193F84: .4byte 0x0000046A
_08193F88: .4byte Enemy_ClearStateBegun
_08193F8C:
	ldr r4, _08193FA0 @ =0x00000484
	adds r1, r7, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08193F96:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08193FA0: .4byte 0x00000484
