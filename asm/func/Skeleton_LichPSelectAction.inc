	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08103CEC
	ldr r6, _08103CE8 @ =0xFFFFFF00
	adds r1, r1, r6
	b _08103CFA
	.align 2, 0
_08103CE8: .4byte 0xFFFFFF00
_08103CEC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08103CFA
	movs r7, #0x80
	lsls r7, r7, #1
	adds r1, r1, r7
_08103CFA:
	cmp r1, #0
	bge _08103D00
	rsbs r1, r1, #0
_08103D00:
	adds r7, r1, #0
	ldr r1, _08103D14 @ =0x000006FC
	adds r0, r4, r1
	movs r1, #0xc
	ldrh r0, [r0, #0x26]
	ands r0, r1
	cmp r0, #0
	beq _08103D18
	movs r0, #1
	b _08103D1A
	.align 2, 0
_08103D14: .4byte 0x000006FC
_08103D18:
	movs r0, #0
_08103D1A:
	adds r6, r0, #0
	cmp r6, #0
	beq _08103D22
	b _081041F6
_08103D22:
	adds r0, r5, #0
	bl Skeleton_CanAttack
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08103DFA
	ldr r2, _08103DB8 @ =0x00000716
	adds r2, r2, r4
	mov r8, r2
	ldrh r0, [r2]
	cmp r0, #0
	beq _08103D3C
	b _081041F6
_08103D3C:
	adds r1, r7, #0
	cmp r1, #0
	bge _08103D44
	rsbs r1, r1, #0
_08103D44:
	cmp r1, #0x1f
	bgt _08103DD4
	ldrb r1, [r5, #5]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r5, #5]
	adds r0, r5, #0
	bl Skeleton_PickWalkDestRandom
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08103D64
	b _081041F6
_08103D64:
	ldr r2, _08103DBC @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r4, _08103DC0 @ =0x0000046D
	adds r0, r5, r4
	movs r3, #1
	strb r3, [r0]
	ldr r7, _08103DC4 @ =0x0000046B
	adds r0, r5, r7
	strb r6, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r6, [r0]
	movs r2, #0x12
	subs r4, #0xeb
	adds r0, r5, r4
	strb r1, [r0]
	ldr r7, _08103DC8 @ =0x00000469
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08103DCC @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08103DD0 @ =0x00000484
	adds r0, r5, r2
	str r6, [r0]
	adds r4, #4
	adds r0, r5, r4
	strb r3, [r0]
	movs r0, #0x78
	mov r6, r8
	strh r0, [r6]
	b _081041F6
	.align 2, 0
_08103DB8: .4byte 0x00000716
_08103DBC: .4byte Enemy_ClearStateBegun
_08103DC0: .4byte 0x0000046D
_08103DC4: .4byte 0x0000046B
_08103DC8: .4byte 0x00000469
_08103DCC: .4byte 0x0000046A
_08103DD0: .4byte 0x00000484
_08103DD4:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r7, #0xe6
	lsls r7, r7, #3
	adds r0, r4, r7
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08103DEA
	movs r0, #1
	b _08103DEC
_08103DEA:
	movs r0, #0
_08103DEC:
	cmp r0, #0
	beq _08103DF2
	b _081041F6
_08103DF2:
	adds r0, r5, #0
	bl Skeleton_LichRelocate
	b _081041F6
_08103DFA:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _08103E24 @ =0x00000546
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r1, r0
	blt _08103E10
	b _08103FFA
_08103E10:
	ldr r7, _08103E28 @ =0x00000744
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08103E30
	ldr r2, _08103E2C @ =Enemy_ClearStateBegun
	movs r1, #0x10
	subs r3, #0xd9
	b _0810400C
	.align 2, 0
_08103E24: .4byte 0x00000546
_08103E28: .4byte 0x00000744
_08103E2C: .4byte Enemy_ClearStateBegun
_08103E30:
	bl Entity081f959c_IsAnyActive
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08103F08
	ldr r7, _08103E84 @ =0x00000746
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08103F08
	ldr r3, _08103E88 @ =0x000006FC
	adds r2, r4, r3
	movs r0, #4
	ldrh r1, [r2, #0x26]
	orrs r0, r1
	strh r0, [r2, #0x26]
	adds r4, r5, #0
	adds r4, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	str r6, [sp]
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Skeleton_PickFarPathNodeOnPath
	ldr r6, _08103E8C @ =0x000004A4
	adds r0, r5, r6
	ldr r6, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	add r2, sp, #4
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08103E90
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r0, r5, r7
	b _08103EB4
	.align 2, 0
_08103E84: .4byte 0x00000746
_08103E88: .4byte 0x000006FC
_08103E8C: .4byte 0x000004A4
_08103E90:
	adds r0, r6, #0
	adds r1, r4, #0
	add r2, sp, #4
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08103EAE
	cmp r0, #2
	beq _08103EBC
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08103EBC
_08103EAE:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
_08103EB4:
	ldr r1, _08103EF0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08103EBC:
	movs r1, #0x15
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08103EF4 @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	ldr r4, _08103EF8 @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	ldr r6, _08103EFC @ =0x00000484
	adds r0, r5, r6
	str r2, [r0]
	ldr r7, _08103F00 @ =0x0000046C
	adds r0, r5, r7
	movs r1, #1
	strb r1, [r0]
	ldr r4, _08103F04 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	subs r7, #1
	b _0810413A
	.align 2, 0
_08103EF0: .4byte 0xFFFFFDFF
_08103EF4: .4byte 0x00000469
_08103EF8: .4byte 0x0000046A
_08103EFC: .4byte 0x00000484
_08103F00: .4byte 0x0000046C
_08103F04: .4byte Enemy_ClearStateBegun
_08103F08:
	movs r6, #0xe9
	lsls r6, r6, #3
	adds r0, r4, r6
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	bgt _08103FE4
	adds r0, r5, #0
	bl Skeleton_CanSummonEnemy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08103FE4
	ldr r0, _08103F64 @ =0x000006FC
	adds r2, r4, r0
	movs r0, #8
	ldrh r1, [r2, #0x26]
	movs r4, #0
	orrs r0, r1
	strh r0, [r2, #0x26]
	add r7, sp, #0xc
	adds r6, r5, #0
	adds r6, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl Skeleton_PickFarPathNodeOnPath
	ldr r1, _08103F68 @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08103F6C
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _08103F90
	.align 2, 0
_08103F64: .4byte 0x000006FC
_08103F68: .4byte 0x000004A4
_08103F6C:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08103F8A
	cmp r0, #2
	beq _08103F98
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08103F98
_08103F8A:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_08103F90:
	ldr r1, _08103FCC @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08103F98:
	movs r1, #0x15
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r2, #0
	strb r2, [r0]
	ldr r6, _08103FD0 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	ldr r7, _08103FD4 @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08103FD8 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r3, _08103FDC @ =0x0000046C
	adds r0, r5, r3
	movs r1, #1
	strb r1, [r0]
	ldr r4, _08103FE0 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	adds r6, #4
	adds r0, r5, r6
	strb r1, [r0]
	adds r7, #1
	b _0810413A
	.align 2, 0
_08103FCC: .4byte 0xFFFFFDFF
_08103FD0: .4byte 0x00000469
_08103FD4: .4byte 0x0000046A
_08103FD8: .4byte 0x00000484
_08103FDC: .4byte 0x0000046C
_08103FE0: .4byte Enemy_ClearStateBegun
_08103FE4:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r6, #0xe6
	lsls r6, r6, #3
	adds r0, r4, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08103FF8
	b _08104186
_08103FF8:
	b _0810418A
_08103FFA:
	ldr r7, _08104058 @ =0x00000744
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08104078
	ldr r2, _0810405C @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r3, _08104060 @ =0x0000046D
_0810400C:
	adds r0, r5, r3
	movs r4, #1
	strb r4, [r0]
	ldr r7, _08104064 @ =0x0000046B
	adds r0, r5, r7
	strb r6, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r6, [r0]
	movs r2, #2
	movs r3, #7
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08104068 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0810406C @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	ldr r3, _08104070 @ =0x00000484
	adds r0, r5, r3
	str r6, [r0]
	ldr r6, _08104074 @ =0x0000046C
	adds r0, r5, r6
	strb r4, [r0]
	b _081041F6
	.align 2, 0
_08104058: .4byte 0x00000744
_0810405C: .4byte Enemy_ClearStateBegun
_08104060: .4byte 0x0000046D
_08104064: .4byte 0x0000046B
_08104068: .4byte 0x00000469
_0810406C: .4byte 0x0000046A
_08104070: .4byte 0x00000484
_08104074: .4byte 0x0000046C
_08104078:
	bl Entity081f959c_IsAnyActive
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _08104174
	ldr r1, _081040D0 @ =0x00000746
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08104174
	ldr r3, _081040D4 @ =0x000006FC
	adds r2, r4, r3
	movs r0, #4
	ldrh r1, [r2, #0x26]
	orrs r0, r1
	strh r0, [r2, #0x26]
	add r6, sp, #0x14
	adds r4, r5, #0
	adds r4, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	str r7, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Skeleton_PickFarPathNodeOnPath
	ldr r7, _081040D8 @ =0x000004A4
	adds r0, r5, r7
	ldr r7, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081040DC
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	b _08104100
	.align 2, 0
_081040D0: .4byte 0x00000746
_081040D4: .4byte 0x000006FC
_081040D8: .4byte 0x000004A4
_081040DC:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081040FA
	cmp r0, #2
	beq _08104108
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08104108
_081040FA:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
_08104100:
	ldr r1, _08104158 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08104108:
	movs r1, #0x15
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r4, _0810415C @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	ldr r6, _08104160 @ =0x0000046A
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _08104164 @ =0x00000484
	adds r0, r5, r7
	str r2, [r0]
	ldr r1, _08104168 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0810416C @ =Enemy_ClearStateBegun
	movs r3, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	subs r7, #0x19
_0810413A:
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _08104170 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	b _081041F6
	.align 2, 0
_08104158: .4byte 0xFFFFFDFF
_0810415C: .4byte 0x00000469
_08104160: .4byte 0x0000046A
_08104164: .4byte 0x00000484
_08104168: .4byte 0x0000046C
_0810416C: .4byte Enemy_ClearStateBegun
_08104170: .4byte 0x00000553
_08104174:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r6, #0xe6
	lsls r6, r6, #3
	adds r0, r4, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810418A
_08104186:
	movs r0, #1
	b _0810418C
_0810418A:
	movs r0, #0
_0810418C:
	adds r4, r0, #0
	cmp r4, #0
	bne _081041F6
	ldrb r1, [r5, #5]
	movs r7, #0xfe
	lsls r7, r7, #1
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r5, #5]
	adds r0, r5, #0
	bl Skeleton_PickWalkDestRandom
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081041F6
	ldr r2, _08104204 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r3, _08104208 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0810420C @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	ldr r7, _08104210 @ =0x00000553
	adds r0, r5, r7
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
	movs r2, #0x12
	subs r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08104214 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08104218 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	ldr r4, _0810421C @ =0x0000046C
	adds r0, r5, r4
	strb r3, [r0]
_081041F6:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08104204: .4byte Enemy_ClearStateBegun
_08104208: .4byte 0x0000046D
_0810420C: .4byte 0x0000046B
_08104210: .4byte 0x00000553
_08104214: .4byte 0x0000046A
_08104218: .4byte 0x00000484
_0810421C: .4byte 0x0000046C
