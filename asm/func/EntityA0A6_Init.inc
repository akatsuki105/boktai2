	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	bl sound_082402f8
	movs r5, #1
	rsbs r5, r5, #0
	str r5, [r4, #0x50]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081E2200
	bl VM_GetPC_Proxy
	str r0, [r4, #0x54]
	cmp r0, #0
	beq _081E221C
_081E2200:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r4, #0
	adds r1, #0x6e
	movs r5, #0
	strh r0, [r1]
	ldr r0, _081E2224 @ =0x00001770
	movs r1, #1
	bl LinkConnect_Create
	cmp r0, #0
	bne _081E2228
_081E221C:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E226A
	.align 2, 0
_081E2224: .4byte 0x00001770
_081E2228:
	ldr r1, _081E2270 @ =LinkShopManager_OnConnected
	ldr r2, _081E2274 @ =LinkShopManager_OnConnectFailed
	adds r0, r4, #0
	bl LinkConnect_SetCallbacks
	adds r0, r4, #0
	bl LinkShopManager_SetupBG
	adds r0, r4, #0
	bl LinkShopManager_OpenTextBox
	ldr r0, _081E2278 @ =0x03002C6C
	str r4, [r0]
	str r5, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x80
	str r5, [r0]
	str r5, [r4, #0x78]
	str r5, [r4, #0x74]
	ldr r2, _081E227C @ =LinkShopManager_StateConnecting
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #7
	strb r0, [r1]
	movs r0, #1
_081E226A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E2270: .4byte LinkShopManager_OnConnected
_081E2274: .4byte LinkShopManager_OnConnectFailed
_081E2278: .4byte 0x03002C6C
_081E227C: .4byte LinkShopManager_StateConnecting
