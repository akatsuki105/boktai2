	push {r4, r5, lr}
	adds r4, r0, #0
	bl MessageWindow_Close
	movs r0, #0
	bl ClearBGTilemapBuffer
	bl Sio_Reset
	bl Sio_Start
	adds r3, r0, #0
	ldr r2, _081E1AF0 @ =LinkShopManager_StateIdle
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r2, r4, #0
	adds r2, #0x69
	movs r0, #1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x6a
	movs r0, #0
	strb r0, [r1]
	adds r5, r1, #0
	cmp r3, #0
	bge _081E1AF8
	subs r1, #2
	movs r0, #2
	strb r0, [r1]
	ldr r3, _081E1AF4 @ =LinkShopManager_StateError
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r3, [r4, #0x4c]
	movs r0, #1
	strb r0, [r2]
	movs r0, #5
	strb r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	b _081E1B3A
	.align 2, 0
_081E1AF0: .4byte LinkShopManager_StateIdle
_081E1AF4: .4byte LinkShopManager_StateError
_081E1AF8:
	cmp r3, #0
	bne _081E1B0A
	movs r0, #0x20
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	bl Sio_GetTimerIntrCount
	b _081E1B16
_081E1B0A:
	movs r0, #0x40
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	bl Sio_GetSerialIntrCount
_081E1B16:
	str r0, [r4, #0x70]
	bl Sio_CreatePacketCtx
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x6d
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x6c
	movs r1, #0
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
_081E1B3A:
	pop {r4, r5}
	pop {r0}
	bx r0
