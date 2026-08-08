	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _080F1F10 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F1F14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F1F16
	.align 2, 0
_080F1F10: .4byte 0x0000046C
_080F1F14:
	movs r0, #0
_080F1F16:
	cmp r0, #0
	beq _080F1F44
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _080F1F3C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _080F1F40 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	b _080F2034
	.align 2, 0
_080F1F3C: .4byte 0x0000046D
_080F1F40: .4byte 0x0000046B
_080F1F44:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ef86c
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _080F1F78 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F1F80
	ldr r3, _080F1F7C @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _080F1F90
	.align 2, 0
_080F1F78: .4byte 0x0000A02F
_080F1F7C: .4byte 0x00000482
_080F1F80:
	ldr r4, _080F1FB4 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _080F1F90
	movs r0, #1
	strh r0, [r2]
_080F1F90:
	ldr r1, _080F1FB8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F1FBC
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _080F1FD4
	.align 2, 0
_080F1FB4: .4byte 0x00000482
_080F1FB8: .4byte 0x0000025D
_080F1FBC:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_080F1FD4:
	ldr r2, _080F2048 @ =0x000004A4
	adds r0, r5, r2
	ldr r1, [r0]
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F205C
	adds r0, r5, #0
	adds r0, #0x48
	movs r1, #1
	bl FUN_08022488
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r1, [r0]
	ldr r4, _080F204C @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r2, [r0]
	ldr r1, _080F2050 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r3, _080F2054 @ =0x000005A4
	adds r0, r5, r3
	ldr r3, [r0]
	subs r4, #0x17
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _080F2058 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r2, [r0]
_080F2034:
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	b _080F2066
	.align 2, 0
_080F2048: .4byte 0x000004A4
_080F204C: .4byte 0x00000469
_080F2050: .4byte 0x0000046C
_080F2054: .4byte 0x000005A4
_080F2058: .4byte 0x0000046B
_080F205C:
	ldr r4, _080F2070 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F2066:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F2070: .4byte 0x00000484
