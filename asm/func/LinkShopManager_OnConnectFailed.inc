	push {r4, lr}
	adds r4, r0, #0
	cmp r2, #0
	beq _081E1B58
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #3
	strb r0, [r1]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E1B60
_081E1B58:
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #4
	strb r0, [r1]
_081E1B60:
	ldr r2, _081E1B8C @ =LinkShopManager_StateClose
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
	movs r0, #6
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1B8C: .4byte LinkShopManager_StateClose
