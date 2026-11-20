	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _081C1E98
	b _081C2360
_081C1E98:
	ldr r0, _081C1EFC @ =0x00000464
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _081C1EA4
	b _081C2360
_081C1EA4:
	ldr r1, _081C1F00 @ =0x00000553
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _081C1F0C
	ldr r2, _081C1F04 @ =0x00000494
	adds r1, r7, r2
	movs r0, #0x20
	strh r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	subs r0, #0x31
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081C1F08 @ =0x00000482
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	movs r1, #4
	bl Enemy_FadeParticles
	strh r5, [r4]
	b _081C2360
	.align 2, 0
_081C1EFC: .4byte 0x00000464
_081C1F00: .4byte 0x00000553
_081C1F04: .4byte 0x00000494
_081C1F08: .4byte 0x00000482
_081C1F0C:
	ldr r1, _081C1F2C @ =0x00000316
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _081C1F30
	ldrh r0, [r4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081C1F4A
	movs r0, #0x10
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	b _081C1F44
	.align 2, 0
_081C1F2C: .4byte 0x00000316
_081C1F30:
	ldrh r0, [r4]
	movs r1, #0x30
	bl Mod
	cmp r0, #0
	bne _081C1F4A
	movs r0, #0x20
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r7, r4
_081C1F44:
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081C1F4A:
	movs r5, #0x8c
	lsls r5, r5, #3
	adds r1, r7, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _081C1FA4
	movs r6, #0
	ldrh r1, [r1]
	cmp r6, r1
	bge _081C1FA4
	ldr r0, _081C1FE0 @ =0x00000462
	adds r3, r7, r0
	adds r2, r7, r5
_081C1F64:
	lsls r1, r6, #1
	movs r4, #0x8b
	lsls r4, r4, #3
	adds r0, r7, r4
	adds r5, r0, r1
	ldrh r4, [r5]
	cmp r4, #0
	bne _081C1F96
	adds r0, r7, #0
	movs r1, #1
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	bl Enemy_FadeParticles
	strh r4, [r5]
	movs r0, #1
	lsls r0, r6
	ldr r3, [sp, #0x18]
	ldrh r1, [r3]
	bics r1, r0
	strh r1, [r3]
	ldr r2, [sp, #0x14]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_081C1F96:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	adds r6, #1
	ldrh r5, [r2]
	cmp r6, r5
	blt _081C1F64
_081C1FA4:
	ldr r0, _081C1FE4 @ =0x00000464
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _081C1FEC
	adds r0, r7, #0
	movs r1, #4
	bl Enemy_FadeParticles
	ldr r1, _081C1FE0 @ =0x00000462
	adds r0, r7, r1
	strh r4, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r4, [r0]
	movs r1, #0
	movs r6, #3
	ldr r3, _081C1FE8 @ =0x0000045E
	adds r0, r7, r3
_081C1FD4:
	strh r1, [r0]
	subs r0, #2
	subs r6, #1
	cmp r6, #0
	bge _081C1FD4
	b _081C2176
	.align 2, 0
_081C1FE0: .4byte 0x00000462
_081C1FE4: .4byte 0x00000464
_081C1FE8: .4byte 0x0000045E
_081C1FEC:
	ldrh r0, [r1]
	movs r1, #0x28
	bl Mod
	cmp r0, #0
	beq _081C1FFA
	b _081C2176
_081C1FFA:
	ldr r4, _081C2050 @ =0x00000316
	adds r1, r7, r4
	movs r0, #2
	ldrb r1, [r1]
	lsls r0, r1
	movs r5, #0x8b
	lsls r5, r5, #1
	adds r3, r7, r5
	strh r0, [r3]
	ldr r2, _081C2054 @ =0x0000048A
	adds r1, r7, r2
	strh r0, [r1]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r2]
	movs r5, #0x93
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	beq _081C2036
	b _081C2176
_081C2036:
	ldr r1, _081C2058 @ =0x0000047C
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _081C205C @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C2060
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _081C206C
	.align 2, 0
_081C2050: .4byte 0x00000316
_081C2054: .4byte 0x0000048A
_081C2058: .4byte 0x0000047C
_081C205C: .4byte 0x0000025D
_081C2060:
	ldr r2, [r7, #0x44]
	ldr r0, _081C2098 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081C206C:
	ldr r3, _081C209C @ =0x00000492
	adds r1, r7, r3
	movs r0, #8
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #8
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081C20A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C20A4
	movs r0, #1
	b _081C20A6
	.align 2, 0
_081C2098: .4byte 0x03003584
_081C209C: .4byte 0x00000492
_081C20A0: .4byte 0x030047A4
_081C20A4:
	movs r0, #0
_081C20A6:
	cmp r0, #0
	beq _081C2114
	movs r5, #0x94
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _081C2114
	cmp r2, #0
	beq _081C2114
	ldr r0, _081C20CC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081C20D0
	movs r0, #1
	rsbs r0, r0, #0
	b _081C20D4
	.align 2, 0
_081C20CC: .4byte 0x03002C68
_081C20D0:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_081C20D4:
	cmp r0, #1
	beq _081C20F6
	cmp r0, #1
	bgt _081C20E2
	cmp r0, #0
	beq _081C20EC
	b _081C2114
_081C20E2:
	cmp r0, #2
	beq _081C2100
	cmp r0, #3
	beq _081C210A
	b _081C2114
_081C20EC:
	ldr r0, [r1]
	cmp r0, #1
	beq _081C2114
	movs r0, #0
	b _081C2116
_081C20F6:
	ldr r0, [r1]
	cmp r0, #2
	beq _081C2114
	movs r0, #0
	b _081C2116
_081C2100:
	ldr r0, [r1]
	cmp r0, #4
	beq _081C2114
	movs r0, #0
	b _081C2116
_081C210A:
	ldr r0, [r1]
	cmp r0, #8
	beq _081C2114
	movs r0, #0
	b _081C2116
_081C2114:
	movs r0, #1
_081C2116:
	cmp r0, #0
	beq _081C2176
	ldrh r0, [r7]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	movs r5, #0x95
	lsls r5, r5, #2
	adds r2, r7, r5
	ldrh r2, [r2]
	ldr r4, _081C21EC @ =0x0000025A
	adds r3, r7, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl HUD_ShowEnemyGauge
	add r5, sp, #0xc
	str r4, [sp, #8]
	add r0, sp, #8
	adds r1, r5, #0
	ldr r2, _081C21F0 @ =0x05000002
	bl CpuSet
	ldr r0, _081C21F4 @ =0x0000048A
	adds r2, r7, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _081C2160
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _081C2176
_081C2160:
	adds r0, r7, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r7, #0
	adds r3, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl CreateDamageNumber
_081C2176:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _081C2186
	b _081C2360
_081C2186:
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r2, #0
	strb r1, [r0]
	ldr r4, _081C21F8 @ =0x00000469
	adds r0, r7, r4
	strb r2, [r0]
	ldr r5, _081C21FC @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	ldr r1, _081C2200 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	adds r3, #4
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r4, [r0]
	movs r3, #0x11
	adds r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _081C2204 @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	ldr r0, _081C2208 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C220C
	movs r0, #1
	b _081C220E
	.align 2, 0
_081C21EC: .4byte 0x0000025A
_081C21F0: .4byte 0x05000002
_081C21F4: .4byte 0x0000048A
_081C21F8: .4byte 0x00000469
_081C21FC: .4byte 0x0000046A
_081C2200: .4byte 0x00000484
_081C2204: .4byte 0x0000046B
_081C2208: .4byte 0x030047A4
_081C220C:
	movs r0, #0
_081C220E:
	cmp r0, #0
	beq _081C2228
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r0, [r0]
	movs r5, #0x93
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r1, [r1]
	bl PlayerLink_UpdateBloodSwordOnKill
	b _081C2352
_081C2228:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r2, _081C224C @ =0x00000474
	adds r5, r7, r2
	cmp r0, #0
	beq _081C22F2
	movs r1, #0x80
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081C2250
	movs r0, #1
	b _081C2252
	.align 2, 0
_081C224C: .4byte 0x00000474
_081C2250:
	movs r0, #0
_081C2252:
	cmp r0, #0
	bne _081C22F2
	ldr r3, _081C2290 @ =0x000001DF
	adds r0, r7, r3
	ldrb r1, [r0]
	cmp r1, #0xe
	bne _081C226C
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r0, #1
	beq _081C22D4
_081C226C:
	cmp r1, #5
	beq _081C22D4
	cmp r1, #7
	beq _081C22D4
	cmp r1, #6
	beq _081C22D4
	ldr r2, _081C2294 @ =0x030046A0
	ldr r0, [r2]
	ldr r1, _081C2298 @ =0x00000948
	adds r3, r0, r1
	ldrh r4, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _081C229C @ =0x0000270E
	cmp r1, r0
	bgt _081C22A0
	adds r0, r4, #1
	b _081C22A4
	.align 2, 0
_081C2290: .4byte 0x000001DF
_081C2294: .4byte 0x030046A0
_081C2298: .4byte 0x00000948
_081C229C: .4byte 0x0000270E
_081C22A0:
	ldr r1, _081C22C0 @ =0x0000270F
	adds r0, r1, #0
_081C22A4:
	strh r0, [r3]
	ldr r0, [r2]
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r0, _081C22C4 @ =0x0000270E
	cmp r1, r0
	bgt _081C22C8
	adds r0, r3, #1
	b _081C22CC
	.align 2, 0
_081C22C0: .4byte 0x0000270F
_081C22C4: .4byte 0x0000270E
_081C22C8:
	ldr r1, _081C2300 @ =0x0000270F
	adds r0, r1, #0
_081C22CC:
	strh r0, [r2]
	adds r0, r7, #0
	bl Enemy_AddKillCount
_081C22D4:
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	bl AddPlayerExp
	movs r3, #0x93
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r4, _081C2304 @ =0x00000189
	adds r1, r7, r4
	ldrb r1, [r1]
	bl Player_AddWeaponExp
_081C22F2:
	movs r1, #0x80
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081C2308
	movs r0, #1
	b _081C230A
	.align 2, 0
_081C2300: .4byte 0x0000270F
_081C2304: .4byte 0x00000189
_081C2308:
	movs r0, #0
_081C230A:
	cmp r0, #0
	bne _081C2346
	ldr r0, _081C2320 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C2324
	movs r0, #1
	b _081C2326
	.align 2, 0
_081C2320: .4byte 0x030047A4
_081C2324:
	movs r0, #0
_081C2326:
	cmp r0, #0
	bne _081C2346
	movs r1, #0x80
	lsls r1, r1, #4
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081C2346
	ldr r0, _081C2368 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl EnemyRespawnInfo_Add
_081C2346:
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081C2352:
	ldr r1, _081C236C @ =0x00000464
	adds r0, r7, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _081C2370 @ =0x000004BE
	adds r0, r7, r2
	strh r1, [r0]
_081C2360:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C2368: .4byte 0x03002B28
_081C236C: .4byte 0x00000464
_081C2370: .4byte 0x000004BE
