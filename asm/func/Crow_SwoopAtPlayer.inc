	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08144EEC @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08144EF0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08144EF2
	.align 2, 0
_08144EEC: .4byte 0x0000046C
_08144EF0:
	movs r0, #0
_08144EF2:
	cmp r0, #0
	bne _08144EF8
	b _08145084
_08144EF8:
	ldr r4, _08144F9C @ =FUN_081431e0
	movs r2, #0x24
	ldr r0, _08144FA0 @ =0x0000046D
	adds r1, r6, r0
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08144FA4 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r3, [r0]
	ldr r0, _08144FA8 @ =0x000004A4
	adds r5, r6, r0
	ldr r2, [r5]
	ldr r0, _08144FAC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r7, r2
	str r3, [sp]
	mov r0, sp
	ldr r2, _08144FB0 @ =0x05000002
	bl CpuSet
	add r4, sp, #4
	adds r3, r6, #0
	adds r3, #8
	ldr r0, [r5]
	adds r2, r0, #0
	adds r2, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	strb r0, [r6, #5]
	ldr r2, _08144FB4 @ =gSineTable
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _08144FB8 @ =0x0000065D
	adds r0, r7, r2
	ldrb r0, [r0]
	muls r0, r1, r0
	mov r8, r4
	cmp r0, #0
	blt _08144FBC
	asrs r1, r0, #0xc
	b _08144FC2
	.align 2, 0
_08144F9C: .4byte FUN_081431e0
_08144FA0: .4byte 0x0000046D
_08144FA4: .4byte 0x0000046B
_08144FA8: .4byte 0x000004A4
_08144FAC: .4byte 0x03002BE0
_08144FB0: .4byte 0x05000002
_08144FB4: .4byte gSineTable
_08144FB8: .4byte 0x0000065D
_08144FBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08144FC2:
	movs r4, #0xd6
	lsls r4, r4, #3
	adds r0, r7, r4
	strh r1, [r0]
	ldr r1, _08144FE8 @ =gSineTable
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	subs r4, #0x53
	adds r0, r7, r4
	ldrb r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08144FEC
	asrs r1, r0, #0xc
	b _08144FF2
	.align 2, 0
_08144FE8: .4byte gSineTable
_08144FEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08144FF2:
	ldr r0, _08145054 @ =0x000006B4
	adds r6, r7, r0
	movs r0, #0
	strh r1, [r6]
	ldr r1, _08145058 @ =0x000006B2
	adds r4, r7, r1
	strh r0, [r4]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq _0814501E
	mov r2, r8
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	bl Div
	strh r0, [r5]
_0814501E:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _08145036
	mov r2, r8
	movs r1, #4
	ldrsh r0, [r2, r1]
	movs r2, #0
	ldrsh r1, [r6, r2]
	bl Div
	strh r0, [r6]
_08145036:
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _0814505C
	cmp r1, #0
	beq _08145072
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	subs r0, #0x20
	movs r2, #0
	ldrsh r1, [r5, r2]
	b _0814506C
	.align 2, 0
_08145054: .4byte 0x000006B4
_08145058: .4byte 0x000006B2
_0814505C:
	cmp r0, #0
	beq _08145072
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	subs r0, #0x20
	movs r2, #0
	ldrsh r1, [r6, r2]
_0814506C:
	bl Div
	strh r0, [r4]
_08145072:
	movs r0, #0xf7
	bl PlaySound_082406e0
	movs r4, #0xce
	lsls r4, r4, #3
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _081452BA
_08145084:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldr r1, _081450B0 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081450B8
	ldr r4, _081450B4 @ =0x00000482
	adds r1, r6, r4
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081450C8
	.align 2, 0
_081450B0: .4byte 0x0000A02F
_081450B4: .4byte 0x00000482
_081450B8:
	ldr r1, _081450EC @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081450C8
	movs r0, #1
	strh r0, [r2]
_081450C8:
	ldr r4, _081450F0 @ =0x0000025D
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081450F4
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _0814510C
	.align 2, 0
_081450EC: .4byte 0x00000482
_081450F0: .4byte 0x0000025D
_081450F4:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_0814510C:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r2, _0814513C @ =0x000006B2
	adds r4, r7, r2
	ldrh r0, [r4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r1, _08145140 @ =0x00000484
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _08145150
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	blt _08145144
	asrs r1, r0, #1
	b _0814514A
	.align 2, 0
_0814513C: .4byte 0x000006B2
_08145140: .4byte 0x00000484
_08145144:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0814514A:
	ldr r4, _08145190 @ =0x000006B2
	adds r0, r7, r4
	strh r1, [r0]
_08145150:
	ldr r1, _08145194 @ =0x0000065D
	adds r0, r7, r1
	ldrb r4, [r0]
	ldr r2, _08145198 @ =0x000004A4
	adds r0, r6, r2
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r6, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r6, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _08145178
	rsbs r2, r2, #0
_08145178:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0814519C
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08145186
	rsbs r2, r2, #0
_08145186:
	cmp r2, #0x20
	bgt _0814519C
	movs r0, #1
	b _08145206
	.align 2, 0
_08145190: .4byte 0x000006B2
_08145194: .4byte 0x0000065D
_08145198: .4byte 0x000004A4
_0814519C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _081451A8
	cmp r1, #0
	beq _08145204
_081451A8:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r6, #5]
	ldr r2, _081451CC @ =gSineTable
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081451D0
	asrs r1, r0, #0xc
	b _081451D6
	.align 2, 0
_081451CC: .4byte gSineTable
_081451D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081451D6:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	ldr r1, _081451F4 @ =gSineTable
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081451F8
	asrs r1, r0, #0xc
	b _081451FE
	.align 2, 0
_081451F4: .4byte gSineTable
_081451F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081451FE:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
_08145204:
	movs r0, #0
_08145206:
	cmp r0, #0
	bne _08145224
	movs r1, #2
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814521E
	movs r0, #1
	b _08145220
_0814521E:
	movs r0, #0
_08145220:
	cmp r0, #0
	beq _081452B0
_08145224:
	ldr r1, _08145250 @ =0x0000065D
	adds r0, r7, r1
	ldrb r0, [r0]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrb r3, [r6, #5]
	lsls r5, r0, #1
	ldr r2, _08145254 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08145258
	asrs r1, r0, #0xc
	b _0814525E
	.align 2, 0
_08145250: .4byte 0x0000065D
_08145254: .4byte gSineTable
_08145258:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814525E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08145276
	asrs r0, r0, #0xc
	b _0814527C
_08145276:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814527C:
	movs r2, #0
	movs r3, #0
	strh r0, [r4, #4]
	movs r1, #2
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r2, [r0]
	ldr r2, _081452A8 @ =0x00000469
	adds r0, r6, r2
	strb r1, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _081452AC @ =0x00000484
	adds r0, r6, r1
	str r3, [r0]
	adds r2, #3
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	b _081452BA
	.align 2, 0
_081452A8: .4byte 0x00000469
_081452AC: .4byte 0x00000484
_081452B0:
	ldr r4, _081452C8 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081452BA:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081452C8: .4byte 0x00000484
