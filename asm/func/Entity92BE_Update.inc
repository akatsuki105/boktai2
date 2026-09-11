	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r2, r4, #0
	adds r2, #0x9a
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	adds r2, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r2, [r2]
	cmp r1, r2
	blo _080A6FDA
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	beq _080A6FD4
	movs r1, #0
	bl Script_ExecById
_080A6FD4:
	adds r0, r4, #0
	bl KillEntity
_080A6FDA:
	pop {r4}
	pop {r1}
	bx r1
