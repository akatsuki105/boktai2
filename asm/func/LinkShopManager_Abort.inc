	push {lr}
	ldr r0, _081E24D0 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E2506
	adds r2, r0, #0
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E24D4
	movs r0, #1
	b _081E24D6
	.align 2, 0
_081E24D0: .4byte 0x03002C6C
_081E24D4:
	movs r0, #0
_081E24D6:
	cmp r0, #0
	bne _081E2506
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #2
	strb r0, [r1]
	ldr r3, _081E250C @ =LinkShopManager_StateError
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	ands r0, r1
	str r3, [r2, #0x4c]
	adds r1, r2, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #5
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	orrs r0, r1
	str r0, [r2, #0x64]
_081E2506:
	pop {r0}
	bx r0
	.align 2, 0
_081E250C: .4byte LinkShopManager_StateError
