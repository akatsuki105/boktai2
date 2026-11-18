	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r6, r0, #0
	adds r4, r1, #0
	ldrh r0, [r4, #0xa]
	cmp r0, #1
	beq _0813E6D0
	b _0813E928
_0813E6D0:
	adds r5, r2, #0
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813E6E0
	b _0813E928
_0813E6E0:
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0813E70E
	ldrh r1, [r4, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0813E70E
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r4, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _0813E760 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0813E70E:
	adds r0, r6, #0
	adds r1, r4, #0
	bl Hitbox_ApplyDamage
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #1
	beq _0813E72E
	subs r0, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0813E72E
	b _0813E87A
_0813E72E:
	ldrh r0, [r4, #0x3e]
	cmp r0, #0
	bne _0813E736
	b _0813E87A
_0813E736:
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r6, #0
	ldrsh r0, [r2, r6]
	ldrh r3, [r4, #0x3e]
	adds r0, r0, r3
	movs r1, #0x95
	lsls r1, r1, #2
	adds r6, r5, r1
	ldrh r1, [r6]
	cmp r0, r1
	ble _0813E764
	ldrh r0, [r2]
	subs r0, r1, r0
	movs r3, #0x8b
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	ldrh r0, [r6]
	b _0813E772
	.align 2, 0
_0813E760: .4byte 0xFEFFFFFF
_0813E764:
	movs r6, #0x8b
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r3, [r0]
	ldrh r0, [r4, #0x3e]
	ldrh r1, [r2]
	adds r0, r0, r1
_0813E772:
	strh r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ldr r3, _0813E79C @ =0x0000048A
	adds r1, r5, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0813E87A
	ldr r0, _0813E7A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0813E7A4
	movs r0, #1
	b _0813E7A6
	.align 2, 0
_0813E79C: .4byte 0x0000048A
_0813E7A0: .4byte 0x030047A4
_0813E7A4:
	movs r0, #0
_0813E7A6:
	cmp r0, #0
	beq _0813E814
	movs r4, #0x94
	lsls r4, r4, #3
	adds r1, r5, r4
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _0813E814
	cmp r2, #0
	beq _0813E814
	ldr r0, _0813E7CC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0813E7D0
	movs r0, #1
	rsbs r0, r0, #0
	b _0813E7D4
	.align 2, 0
_0813E7CC: .4byte 0x03002C68
_0813E7D0:
	movs r6, #0x18
	ldrsh r0, [r0, r6]
_0813E7D4:
	cmp r0, #1
	beq _0813E7F6
	cmp r0, #1
	bgt _0813E7E2
	cmp r0, #0
	beq _0813E7EC
	b _0813E814
_0813E7E2:
	cmp r0, #2
	beq _0813E800
	cmp r0, #3
	beq _0813E80A
	b _0813E814
_0813E7EC:
	ldr r0, [r1]
	cmp r0, #1
	beq _0813E814
	movs r0, #0
	b _0813E816
_0813E7F6:
	ldr r0, [r1]
	cmp r0, #2
	beq _0813E814
	movs r0, #0
	b _0813E816
_0813E800:
	ldr r0, [r1]
	cmp r0, #4
	beq _0813E814
	movs r0, #0
	b _0813E816
_0813E80A:
	ldr r0, [r1]
	cmp r0, #8
	beq _0813E814
	movs r0, #0
	b _0813E816
_0813E814:
	movs r0, #1
_0813E816:
	cmp r0, #0
	beq _0813E87A
	ldrh r0, [r5]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #0x95
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	ldr r6, _0813E8B4 @ =0x0000025A
	adds r3, r5, r6
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl HUD_ShowEnemyGauge
	add r6, sp, #0xc
	str r4, [sp, #8]
	add r0, sp, #8
	adds r1, r6, #0
	ldr r2, _0813E8B8 @ =0x05000002
	bl CpuSet
	ldr r0, _0813E8BC @ =0x0000048A
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _0813E866
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0813E87A
_0813E866:
	adds r0, r5, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r5, #0
	adds r3, #8
	str r6, [sp]
	movs r2, #1
	str r2, [sp, #4]
	bl CreateDamageNumber
_0813E87A:
	movs r3, #0x97
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r3, r5, r4
	ldr r1, [r3]
	movs r6, #0xcb
	lsls r6, r6, #3
	adds r1, r1, r6
	movs r2, #9
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, [r3]
	movs r1, #4
	adds r0, r0, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813E8C0
	movs r0, #1
	b _0813E8C2
	.align 2, 0
_0813E8B4: .4byte 0x0000025A
_0813E8B8: .4byte 0x05000002
_0813E8BC: .4byte 0x0000048A
_0813E8C0:
	movs r0, #0
_0813E8C2:
	adds r4, r0, #0
	cmp r4, #0
	bne _0813E928
	ldr r2, _0813E930 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r3, _0813E934 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0813E938 @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0813E93C @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0813E940 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r3, [r0]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #4
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r1, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0813E928:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813E930: .4byte Enemy_ClearStateBegun
_0813E934: .4byte 0x0000046D
_0813E938: .4byte 0x0000046B
_0813E93C: .4byte 0x00000469
_0813E940: .4byte 0x0000046A
