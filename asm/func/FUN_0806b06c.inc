	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x20
	beq _0806B086
	adds r0, r5, #0
	movs r1, #0x20
	movs r2, #0
	bl FUN_08060b84
_0806B086:
	ldr r2, _0806B09C @ =0x0000037D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _0806B092
	b _0806B35E
_0806B092:
	lsls r0, r0, #2
	ldr r1, _0806B0A0 @ =_0806B0A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B09C: .4byte 0x0000037D
_0806B0A0: .4byte _0806B0A4
_0806B0A4: @ jump table
	.4byte _0806B0B8 @ case 0
	.4byte _0806B20A @ case 1
	.4byte _0806B2A8 @ case 2
	.4byte _0806B308 @ case 3
	.4byte _0806B31C @ case 4
_0806B0B8:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r2, #0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _0806B128 @ =0x000002E6
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	subs r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0806B12C @ =0x0000042E
	adds r0, r5, r1
	strh r2, [r0]
	movs r1, #0x1f
	ldr r2, _0806B130 @ =0x0000040C
	adds r6, r5, r2
	adds r4, r0, #0
_0806B0E0:
	subs r3, r1, #1
	adds r2, r6, r3
	ldrb r0, [r2]
	cmp r0, #0
	beq _0806B0F0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0806B0F0:
	adds r1, r6, r1
	ldrb r0, [r2]
	strb r0, [r1]
	adds r1, r3, #0
	cmp r1, #0
	bgt _0806B0E0
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r2, _0806B134 @ =0x0000042C
	adds r1, r5, r2
	ldrh r0, [r0, #2]
	ldrh r1, [r1]
	ands r1, r0
	cmp r1, #0
	beq _0806B138
	ldr r3, _0806B130 @ =0x0000040C
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0806B12C @ =0x0000042E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0806B13E
	.align 2, 0
_0806B128: .4byte 0x000002E6
_0806B12C: .4byte 0x0000042E
_0806B130: .4byte 0x0000040C
_0806B134: .4byte 0x0000042C
_0806B138:
	ldr r2, _0806B154 @ =0x0000040C
	adds r0, r5, r2
	strb r1, [r0]
_0806B13E:
	ldr r3, _0806B158 @ =0x0000042E
	adds r0, r5, r3
	ldrh r0, [r0]
	adds r1, r0, #0
	cmp r1, #0
	beq _0806B1E8
	cmp r1, #3
	bhi _0806B15C
	lsls r0, r0, #4
	movs r1, #0x80
	b _0806B17C
	.align 2, 0
_0806B154: .4byte 0x0000040C
_0806B158: .4byte 0x0000042E
_0806B15C:
	cmp r1, #5
	bhi _0806B172
	subs r0, #2
	lsls r0, r0, #3
	movs r1, #0x40
	subs r1, r1, r0
	movs r3, #0x86
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r1, [r0]
	b _0806B192
_0806B172:
	cmp r1, #7
	bhi _0806B188
	subs r0, #4
	lsls r0, r0, #2
	movs r1, #0x20
_0806B17C:
	subs r1, r1, r0
	movs r2, #0x86
	lsls r2, r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	b _0806B192
_0806B188:
	movs r3, #0x86
	lsls r3, r3, #3
	adds r1, r5, r3
	movs r0, #0x10
	strh r0, [r1]
_0806B192:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	movs r2, #0x86
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r2, [r0]
	adds r0, r5, #0
	bl FUN_08060a24
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	beq _0806B1BC
	b _0806B35E
_0806B1BC:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806B1D4
	ldr r0, _0806B1D0 @ =0x0000028E
	bl PlaySound_082406e0
	b _0806B35E
	.align 2, 0
_0806B1D0: .4byte 0x0000028E
_0806B1D4:
	cmp r0, #3
	beq _0806B1DA
	b _0806B35E
_0806B1DA:
	ldr r0, _0806B1E4 @ =0x0000028D
	bl PlaySound_082406e0
	b _0806B35E
	.align 2, 0
_0806B1E4: .4byte 0x0000028D
_0806B1E8:
	movs r3, #0x86
	lsls r3, r3, #3
	adds r4, r5, r3
	strh r1, [r4]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	ldrh r2, [r4]
	adds r0, r5, #0
	bl FUN_08060a24
	b _0806B35E
_0806B20A:
	ldr r2, _0806B284 @ =0x0000037E
	adds r6, r5, r2
	ldrh r4, [r6]
	cmp r4, #0
	bne _0806B24E
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #7
	strb r0, [r1]
	ldr r1, _0806B288 @ =0x000002E6
	adds r0, r5, r1
	strb r4, [r0]
	subs r2, #0x97
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	adds r3, #0x70
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806B28C @ =0x000001AD
	bl PlaySound_082406e0
	ldr r1, _0806B290 @ =0x000003F6
	adds r0, r5, r1
	strh r4, [r0]
_0806B24E:
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c40
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _0806B266
	b _0806B35E
_0806B266:
	movs r0, #0xd7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _0806B294
	movs r0, #0xbb
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0806B29C
	.align 2, 0
_0806B284: .4byte 0x0000037E
_0806B288: .4byte 0x000002E6
_0806B28C: .4byte 0x000001AD
_0806B290: .4byte 0x000003F6
_0806B294:
	movs r0, #0xc1
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0806B29C:
	adds r0, r5, #0
	movs r1, #0x20
	movs r2, #2
	bl FUN_08060b84
	b _0806B35E
_0806B2A8:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806B2FC @ =0x000003F6
	adds r4, r5, r0
	ldrh r0, [r4]
	subs r0, #0x3c
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r2, _0806B300 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _0806B35E
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c40
	ldr r0, _0806B304 @ =0x000005DC
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #0x20
	movs r2, #3
	bl FUN_08060b84
	b _0806B35E
	.align 2, 0
_0806B2FC: .4byte 0x000003F6
_0806B300: .4byte 0x0000037E
_0806B304: .4byte 0x000005DC
_0806B308:
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08060c40
	ldr r3, _0806B318 @ =0x0000037E
	adds r1, r5, r3
	b _0806B358
	.align 2, 0
_0806B318: .4byte 0x0000037E
_0806B31C:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r4, #0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _0806B364 @ =0x000002E6
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0806B368 @ =0x000002E7
	adds r0, r5, r2
	strb r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r1, _0806B36C @ =0x000003F6
	adds r0, r5, r1
	strh r4, [r0]
	ldr r2, _0806B370 @ =0x0000037E
	adds r1, r5, r2
_0806B358:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0806B35E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806B364: .4byte 0x000002E6
_0806B368: .4byte 0x000002E7
_0806B36C: .4byte 0x000003F6
_0806B370: .4byte 0x0000037E
