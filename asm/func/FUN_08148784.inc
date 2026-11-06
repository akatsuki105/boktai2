	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r3, r4, r0
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0814879A
	b _081488AE
_0814879A:
	movs r1, #0xea
	lsls r1, r1, #1
	adds r5, r4, r1
	ldr r0, [r5]
	cmp r0, #0
	ble _081487CA
	movs r0, #0x80
	subs r1, #0x52
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldrh r0, [r5]
	bl EnemyTargetManager_FindOwnerByID
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r4, r2
	b _08148844
_081487CA:
	ldr r0, _081487DC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081487E0
	movs r0, #1
	b _081487E2
	.align 2, 0
_081487DC: .4byte 0x030047A4
_081487E0:
	movs r0, #0
_081487E2:
	cmp r0, #0
	beq _08148800
	adds r0, r4, #0
	bl Mimic_FindOpeningPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08148828
	adds r0, r4, #0
	bl Mimic_IsPlayerLost
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08148850
	b _081488AE
_08148800:
	movs r2, #0xa
	ldrsh r1, [r4, r2]
	ldr r0, _0814884C @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08148814
	rsbs r1, r1, #0
_08148814:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _081488AE
	adds r0, r4, #0
	bl Mimic_FindOpeningPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08148850
_08148828:
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
_08148844:
	str r0, [r1]
	movs r0, #1
	b _081488B0
	.align 2, 0
_0814884C: .4byte 0x03002BE0
_08148850:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _081488AE
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r2, #8
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081488AE
	ldr r1, _081488B8 @ =0x000004A4
	adds r0, r4, r1
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #8
	adds r2, r3, #0
	adds r2, #8
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _081488AE
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081488AE
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r3, r4, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081488AE:
	movs r0, #0
_081488B0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081488B8: .4byte 0x000004A4
