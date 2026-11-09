	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08132F20 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08132F24
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08132F26
	.align 2, 0
_08132F20: .4byte 0x0000046D
_08132F24:
	movs r0, #0
_08132F26:
	cmp r0, #0
	beq _08132F72
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl ParticleShadow_Show
	ldr r2, _08132F4C @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08132F50
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08132F5E
	.align 2, 0
_08132F4C: .4byte 0x0000025D
_08132F50:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_08132F5E:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x3c
	strh r0, [r1]
_08132F72:
	ldr r0, [r6, #0x44]
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1, #8]
	cmp r0, #3
	bne _08132F8A
	ldrh r0, [r1, #0xe]
	cmp r0, #4
	bne _08132F8A
	movs r0, #0xee
	bl PlaySound_082406e0
_08132F8A:
	ldr r1, _08133128 @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08132F96
	b _08133122
_08132F96:
	adds r0, r6, #0
	bl Centipede_OnReset
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _0813312C @ =0x0000055C
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	adds r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _08133130 @ =0x00000564
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r4, #0
	strb r0, [r6, #5]
	adds r2, #5
	adds r0, r6, r2
	ldrb r1, [r0]
	subs r2, #0xfd
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08133134 @ =0x00000566
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08133138 @ =0x00000567
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r1, r6, r0
	adds r2, #0xfe
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0813313C @ =0x0000056C
	adds r0, r6, r1
	ldrb r1, [r0]
	subs r2, #0x15
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08133140 @ =0x00000572
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r2, #0xdf
	adds r0, r6, r2
	movs r5, #0
	strh r1, [r0]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r2, #0x3a
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #0x9e
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, _08133144 @ =0x0000046B
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _08133148 @ =0x0000046C
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _0813314C @ =0x0000024E
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xbc
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _08133150 @ =0x00000544
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xde
	adds r0, r6, r2
	strh r4, [r0]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r6, r2
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r4, [r0]
	adds r2, #5
	adds r0, r6, r2
	strb r5, [r0]
	adds r2, #0x3f
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _08133154 @ =0x00000482
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #0x1a
	adds r0, r6, r2
	str r4, [r0]
	adds r1, #8
	adds r0, r6, r1
	str r4, [r0]
	subs r2, #0x10
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #0x1e
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	subs r1, #0x30
	adds r0, r6, r1
	strb r5, [r0]
	subs r2, #0x35
	adds r0, r6, r2
	movs r1, #8
	bl ClearMemory
	ldr r1, _08133158 @ =0x00000464
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r1, _0813315C @ =0x08252048
	adds r0, r6, #0
	ldr r2, _08133160 @ =0x00000982
	bl Enemy_ClearPendingState
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _08133164 @ =0x00000541
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r1, r6, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #0xa
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #5
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r5, [r0]
	adds r0, r6, #0
	bl EnemyManager_TryEndPaletteFade
_08133122:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08133128: .4byte 0x0000046E
_0813312C: .4byte 0x0000055C
_08133130: .4byte 0x00000564
_08133134: .4byte 0x00000566
_08133138: .4byte 0x00000567
_0813313C: .4byte 0x0000056C
_08133140: .4byte 0x00000572
_08133144: .4byte 0x0000046B
_08133148: .4byte 0x0000046C
_0813314C: .4byte 0x0000024E
_08133150: .4byte 0x00000544
_08133154: .4byte 0x00000482
_08133158: .4byte 0x00000464
_0813315C: .4byte 0x08252048
_08133160: .4byte 0x00000982
_08133164: .4byte 0x00000541
