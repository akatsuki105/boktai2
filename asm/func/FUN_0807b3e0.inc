	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807B408 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807B404
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0807B404
	bl fetch_082316e4
	cmp r0, #2
	ble _0807B40C
_0807B404:
	movs r0, #0
	b _0807B41C
	.align 2, 0
_0807B408: .4byte 0x03002BE0
_0807B40C:
	lsls r0, r0, #1
	ldr r2, _0807B424 @ =0x0000043C
	adds r1, r4, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0807B404
	movs r0, #1
_0807B41C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0807B424: .4byte 0x0000043C
