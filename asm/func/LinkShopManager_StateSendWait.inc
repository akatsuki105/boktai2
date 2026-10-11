	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E1D1A
	movs r0, #0
	strb r0, [r1]
_081E1D1A:
	movs r1, #1
	ldr r0, [r4, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1D28
	movs r0, #1
	b _081E1D2A
_081E1D28:
	movs r0, #0
_081E1D2A:
	cmp r0, #0
	beq _081E1D72
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x50
	bl LinkShopMsg_TrySend
	cmp r0, #1
	bne _081E1D72
	ldr r1, [r4, #0x78]
	cmp r1, #0
	beq _081E1D4A
	ldr r0, [r4, #0x74]
	bl _call_via_r1
_081E1D4A:
	movs r0, #0
	strh r0, [r4, #0x3c]
	subs r0, #2
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	adds r0, #1
	str r0, [r4, #0x50]
	ldr r2, _081E1D78 @ =LinkShopManager_StateIdle
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
_081E1D72:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1D78: .4byte LinkShopManager_StateIdle
