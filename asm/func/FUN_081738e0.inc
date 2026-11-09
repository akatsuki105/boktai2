	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08173900 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173904
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08173906
	.align 2, 0
_08173900: .4byte 0x0000046C
_08173904:
	movs r0, #0
_08173906:
	cmp r0, #0
	beq _08173938
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08173968 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	ldr r7, _0817396C @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08173938:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	ldr r2, _08173970 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0x63
	bgt _08173974
	movs r1, #0x14
	bl Mod
	cmp r0, #0
	bne _0817398A
	adds r0, r5, #0
	movs r1, #0x28
	movs r2, #0x18
	movs r3, #0
	bl FUN_08177a4c
	b _0817398A
	.align 2, 0
_08173968: .4byte 0x0000046D
_0817396C: .4byte 0x0000046B
_08173970: .4byte 0x00000484
_08173974:
	movs r1, #0x28
	bl Mod
	cmp r0, #0
	bne _0817398A
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0x2c
	movs r3, #1
	bl FUN_08177a4c
_0817398A:
	ldr r3, _08173A04 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	cmp r0, #0xc8
	ble _08173A1C
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	movs r2, #1
	ldr r7, _08173A08 @ =0x0000046D
	adds r0, r5, r7
	movs r1, #0
	strb r2, [r0]
	ldr r4, _08173A0C @ =0x0000046B
	adds r0, r5, r4
	strb r1, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r3, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r3, #0
	strh r1, [r0]
	movs r4, #0x11
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r4, [r0]
	ldr r4, _08173A04 @ =0x00000484
	adds r0, r5, r4
	str r1, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r1, _08173A10 @ =0x00001008
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08173A14 @ =0x00000F97
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _08173A18 @ =0x00000F96
	adds r1, r6, r3
	movs r0, #3
	strb r0, [r1]
	b _08173A20
	.align 2, 0
_08173A04: .4byte 0x00000484
_08173A08: .4byte 0x0000046D
_08173A0C: .4byte 0x0000046B
_08173A10: .4byte 0x00001008
_08173A14: .4byte 0x00000F97
_08173A18: .4byte 0x00000F96
_08173A1C:
	adds r0, #1
	str r0, [r1]
_08173A20:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
