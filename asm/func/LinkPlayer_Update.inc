	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080845D4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080845CA
	adds r0, r4, #0
	bl FUN_08080e34
	adds r0, r4, #0
	bl FUN_08084540
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08081628
_080845CA:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080845D4: .4byte 0x03002BE0
