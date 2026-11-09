	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _08182A0C @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182A10
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182A12
	.align 2, 0
_08182A0C: .4byte 0x0000046C
_08182A10:
	movs r0, #0
_08182A12:
	cmp r0, #0
	beq _08182A90
	ldr r3, _08182A68 @ =0x000005A4
	adds r0, r4, r3
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _08182A6C @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08182A70 @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	ldr r2, _08182A74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08182A78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08182A7C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _08182A84
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r3, _08182A80 @ =0x00000898
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08182A90
	.align 2, 0
_08182A68: .4byte 0x000005A4
_08182A6C: .4byte 0x0000046D
_08182A70: .4byte 0x0000046B
_08182A74: .4byte 0x030046B8
_08182A78: .4byte 0x000003FF
_08182A7C: .4byte 0x0203B400
_08182A80: .4byte 0x00000898
_08182A84:
	ldr r0, _08182AC8 @ =0x00000898
	adds r2, r5, r0
	ldr r1, _08182ACC @ =0xFFF7FFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08182A90:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08182AB2
	adds r0, r4, #0
	bl FUN_0817ba7c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08182AB2
	b _08182D10
_08182AB2:
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r3, _08182AC8 @ =0x00000898
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08182AD0
	movs r0, #1
	b _08182AD2
	.align 2, 0
_08182AC8: .4byte 0x00000898
_08182ACC: .4byte 0xFFF7FFFF
_08182AD0:
	movs r0, #0
_08182AD2:
	movs r2, #4
	cmp r0, #0
	beq _08182ADA
	movs r2, #8
_08182ADA:
	movs r1, #0x80
	lsls r1, r1, #8
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08182AEC
	movs r0, #1
	b _08182AEE
_08182AEC:
	movs r0, #0
_08182AEE:
	adds r1, r2, #0
	cmp r0, #0
	beq _08182AF6
	asrs r1, r1, #1
_08182AF6:
	ldr r0, _08182B14 @ =0x00000484
	adds r2, r4, r0
	ldr r0, [r2]
	cmp r0, r1
	bgt _08182B02
	b _08182D0C
_08182B02:
	movs r1, #1
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08182B18
	movs r0, #1
	b _08182B1A
	.align 2, 0
_08182B14: .4byte 0x00000484
_08182B18:
	movs r0, #0
_08182B1A:
	cmp r0, #0
	beq _08182B6C
	adds r0, r4, #0
	bl FUN_0817e02c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08182B2C
	b _08182D10
_08182B2C:
	ldr r1, _08182B54 @ =0x03002BE0
	ldr r3, _08182B58 @ =0x000004A4
	adds r0, r4, r3
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	ldr r0, [r1]
	adds r5, r0, #0
	adds r5, #0x2c
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08182B5C
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	b _08182BD8
	.align 2, 0
_08182B54: .4byte 0x03002BE0
_08182B58: .4byte 0x000004A4
_08182B5C:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	bne _08182BC2
	b _08182BD2
_08182B6C:
	movs r1, #0x80
	lsls r1, r1, #7
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08182B7E
	movs r0, #1
	b _08182B80
_08182B7E:
	movs r0, #0
_08182B80:
	adds r2, r0, #0
	cmp r2, #0
	beq _08182C10
	ldr r3, _08182BAC @ =0x000004A4
	adds r0, r4, r3
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	ldr r0, _08182BB0 @ =0x00000854
	adds r5, r5, r0
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08182BB4
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	b _08182BD8
	.align 2, 0
_08182BAC: .4byte 0x000004A4
_08182BB0: .4byte 0x00000854
_08182BB4:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08182BD2
_08182BC2:
	cmp r0, #2
	beq _08182BE0
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08182BE0
_08182BD2:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
_08182BD8:
	ldr r1, _08182C08 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08182BE0:
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _08182C0C @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _08182D10
	.align 2, 0
_08182C08: .4byte 0xFFFFFDFF
_08182C0C: .4byte 0x00000484
_08182C10:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xb
	cmp r1, r0
	bls _08182C5C
	movs r1, #0x14
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08182C50 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	ldr r2, _08182C54 @ =0x0000046C
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08182C58 @ =0xFFFFBFFF
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	b _08182D10
	.align 2, 0
_08182C50: .4byte 0x00000484
_08182C54: .4byte 0x0000046C
_08182C58: .4byte 0xFFFFBFFF
_08182C5C:
	ldr r0, _08182C94 @ =0x00000854
	adds r5, r5, r0
	ldr r0, _08182C98 @ =0x03002BE0
	ldr r2, [r0]
	adds r2, #0x2c
	movs r3, #0x90
	lsls r3, r3, #0xc
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0817e910
	ldr r1, _08182C9C @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08182CA0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	b _08182CC4
	.align 2, 0
_08182C94: .4byte 0x00000854
_08182C98: .4byte 0x03002BE0
_08182C9C: .4byte 0x000004A4
_08182CA0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08182CBE
	cmp r0, #2
	beq _08182CCC
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08182CCC
_08182CBE:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
_08182CC4:
	ldr r1, _08182D00 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08182CCC:
	movs r2, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08182D04 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _08182D08 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #7
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	b _08182D0E
	.align 2, 0
_08182D00: .4byte 0xFFFFFDFF
_08182D04: .4byte 0x00000469
_08182D08: .4byte 0x00000484
_08182D0C:
	adds r0, #1
_08182D0E:
	str r0, [r2]
_08182D10:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
